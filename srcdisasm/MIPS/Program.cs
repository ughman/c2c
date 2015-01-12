using System;
using System.Collections.Generic;
using System.IO;

namespace PSXDiscompile
{
    public class Program
    {
        public static Program LoadEXE(string filename)
        {
            Program program = new Program();
            using (FileStream exe = new FileStream(filename,FileMode.Open,FileAccess.Read))
            {
                byte[] buffer = new byte [4];
                exe.Position = 0x10;
                exe.Read(buffer,0,4);
                int entrypoint = BitConv.FromInt32(buffer,0);
                exe.Position = 0x18;
                exe.Read(buffer,0,4);
                int address = BitConv.FromInt32(buffer,0);
                exe.Position = 0x800;
                while (exe.Read(buffer,0,4) == 4)
                {
                    program.SetWord(address,BitConv.FromInt32(buffer,0));
                    address += 4;
                }
                program[entrypoint].IsMethod = true;
                program[entrypoint].Label = "Main";
                program.MarkBranch(entrypoint);
            }
            return program;
        }

        private List<Word> marks;
        private Dictionary<int,Word> words;
        private int indentcount;
        private TextWriter o;
        private int clocks;
        private int lastword;

        public Program()
        {
            this.marks = new List<Word>();
            this.words = new Dictionary<int,Word>();
            this.indentcount = 0;
            this.o = null;
            this.lastword = int.MinValue;
        }

        public int Clocks
        {
            get { return clocks; }
        }

        public Word this[int address]
        {
            get { return words[address | ~0x7FFFFFFF]; }
        }

        public void SetWord(int address,int value)
        {
            words.Add(address,new Word(this,address,value));
            if (address > lastword)
                lastword = address;
        }

        public void Indent()
        {
            indentcount++;
        }

        public void Unindent()
        {
            indentcount--;
        }

        public void WriteLine(string format,params object[] arg)
        {
            for (int i = 0;i < indentcount;i++)
                o.Write("\t");
            o.WriteLine(format,arg);
        }

        public void WriteClocks(int offset,int address)
        {
            WriteLine("ZZ_CLOCKCYCLES({0},0x{1:X});",clocks + offset,address);
        }

        public void WriteClocksJR(int offset)
        {
            WriteLine("ZZ_CLOCKCYCLES_JR({0});",clocks + offset);
        }

        public void MarkDirect(int address)
        {
            Word word = this[address];
            if (word.IsUnknown)
                throw new PSXException();
            if (!word.IsCode)
            {
                marks.Add(word);
                word.IsCode = true;
            }
        }

        public void MarkBranch(int address)
        {
            Word word = this[address];
            word.IsTarget = true;
            MarkDirect(address);
        }

        public void MarkCall(int address,int returnaddress)
        {
            Word word = this[address];
            Word callerword = this[returnaddress];
            word.IsTarget = true;
            word.IsMethod = true;
            if (!word.Callers.Contains(callerword))
            {
                word.Callers.Add(callerword);
            }
            MarkDirect(address);
        }

        public void MarkDelaySlot(int address)
        {
            Word word = this[address];
            word.IsDelaySlot = true;
            /*while ((word = this[word.Address + 4]).Value == 0)
            {
                word.IsDelaySlot = true;
            }*/
        }

        public void MarkUnknown(int address)
        {
            Word word = this[address];
            if (word.IsCode)
                throw new PSXException();
            MarkBranch(address);
            word.IsMethod = true;
            word.IsUnknown = true;
        }

        public void FlushMarks()
        {
            while (marks.Count > 0)
            {
                marks[0].Instruction.Mark(this,marks[0].Address);
                marks.RemoveAt(0);
            }
        }

        public void Disassemble(string filename)
        {
            FlushMarks();
            using (o = new StreamWriter(filename))
            {
                o.NewLine = "\n";
                foreach (Word word in words.Values)
                {
                    if (word.IsMethod || word.IsTarget)
                        o.WriteLine("{0}:",word.Label);
                    o.WriteLine("\t{0:X8}: {1:X8} {2} {3}",word.Address,word.Value,word.Text,word.Instruction.ToString(this,word.Address));
                }
            }
        }

        public void Discompile()
        {
            FlushMarks();
            string zzsrc = Path.Combine("..","srczz");
            using (StreamWriter zzi = new StreamWriter(Path.Combine(zzsrc,"zz_include.h")))
            {
                zzi.NewLine = "\n";
                foreach (Word wx in words.Values)
                {
                    if (wx.IsMethod)
                    {
                        string ofn = string.Format("zz_{0:x}.h",wx.Address & 0x1FFFFF);
                        zzi.WriteLine("#include \"{0}\"",ofn);
                        using (o = new StreamWriter(Path.Combine(zzsrc,ofn)))
                        {
                            o.NewLine = "\n";
                            o.WriteLine("#ifdef ZZ_INCLUDE_CODE");
                            Indent();
                            {
                                Word ww = wx;
                                do
                                {
                                    if (ww.IsMethod || ww.IsTarget)
                                    {
                                        if (clocks != 0)
                                        {
                                            WriteClocks(0,ww.Address);
                                            clocks = 0;
                                        }
                                        o.WriteLine("{0}:",ww.Label);
                                    }
                                    if (ww.IsCode)
                                    {
                                        clocks++;
                                        if (ww.HackMustInvalidateICache)
                                            WriteLine("EMU_InvalidateICache();");
                                        if (ww.HackString != null)
                                            WriteLine(ww.HackString);
                                        else
                                            ww.Discompile(true);
                                    }
                                    else
                                    {
                                        clocks = 0;
                                    }
                                    if (ww.Address == lastword)
                                        break;
                                    ww = this[ww.Address + 4];
                                } while (!ww.IsMethod);
                            }
                            Unindent();
                            o.WriteLine("#endif");
                            {
                                Word ww = wx;
                                do
                                {
                                    if (ww.IsMethod || ww.IsTarget)
                                    {
                                        o.WriteLine("ZZ_MARK_TARGET(0x{0:X},{1});",ww.Address,ww.Label);
                                    }
                                    else if (ww.IsCode || ww.IsDelaySlot)
                                    {
                                        o.WriteLine("ZZ_MARK(0x{0:X});",ww.Address);
                                    }
                                    if (ww.Address == lastword)
                                        break;
                                    ww = this[ww.Address + 4];
                                } while (!ww.IsMethod);
                            }
                        }
                    }
                }
            }
        }

        public void DumpCodemap(string filename)
        {
            using (o = new StreamWriter(filename))
            {
                o.NewLine = "\n";
                int startaddr = 0;
                string type = null;
                foreach (Word word in words.Values)
                {
                    string oldtype = type;
                    type = (word.IsCode || word.IsDelaySlot) ? "Code" : "Data";
                    if (oldtype != type)
                    {
                        if (oldtype != null)
                            o.WriteLine("{0:X8} +{2,6:X}: {1}",startaddr,oldtype,word.Address - startaddr);
                        startaddr = word.Address;
                    }
                }
            }
        }

        public void MarkAnonymousJumpTable(int firstaddr,int lastaddr)
        {
            for (int i = firstaddr;i <= lastaddr;i += 4)
            {
                MarkBranch(this[i].Value);
            }
        }

        public void MarkAnonymousCallTable(int firstaddr,int lastaddr)
        {
            for (int i = firstaddr;i <= lastaddr;i += 4)
            {
                MarkBranch(this[i].Value);
                this[this[i].Value].IsMethod = true;
            }
        }
    }
}
