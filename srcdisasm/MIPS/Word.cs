using System;
using System.Collections.Generic;

namespace PSXDiscompile
{
    public sealed class Word
    {
        private Program program;
        private int address;
        private int value;
        private Instruction instruction;
        private bool iscode;
        private bool istarget;
        private bool ismethod;
        private bool isdelayslot;
        private bool isunknown;
        private List<Word> callers;
        private List<Word> destinations;
        private int? directbranch;
        private string label;
        private bool isweirdreturn;
        private string hackstring;
        private bool hackmustinvalidateicache;

        internal Word(Program program,int address,int value)
        {
            if (program == null)
                throw new ArgumentNullException("program");
            if ((address & 3) != 0)
                throw new ArgumentException("Address is unaligned.");
            this.program = program;
            this.address = address;
            this.value = value;
            this.instruction = Instruction.Disassemble(value);
            this.iscode = false;
            this.istarget = false;
            this.ismethod = false;
            this.isdelayslot = false;
            this.isunknown = false;
            this.callers = new List<Word>();
            this.destinations = new List<Word>();
            this.directbranch = null;
            this.label = null;
            this.isweirdreturn = false;
            this.hackstring = null;
            this.hackmustinvalidateicache = false;
        }

        public Program Program
        {
            get { return program; }
        }

        public int Address
        {
            get { return address; }
        }

        public int Value
        {
            get { return value; }
        }

        public Instruction Instruction
        {
            get { return instruction; }
        }

        public bool IsCode
        {
            get { return iscode; }
            set { iscode = value; }
        }

        public bool IsTarget
        {
            get { return istarget; }
            set { istarget = value; }
        }

        public bool IsMethod
        {
            get { return ismethod; }
            set { ismethod = value; }
        }

        public bool IsDelaySlot
        {
            get { return isdelayslot; }
            set { isdelayslot = value; }
        }

        public bool IsUnknown
        {
            get { return isunknown; }
            set { isunknown = value; }
        }

        public IList<Word> Callers
        {
            get { return callers; }
        }

        public IList<Word> Destinations
        {
            get { return destinations; }
        }

        public int? DirectBranch
        {
            get { return directbranch; }
            set { directbranch = value; }
        }

        public string Label
        {
            get
            {
                if (label != null)
                    return label;
                else if (ismethod)
                    return string.Format("ZZ_{0:X}",address & 0x1FFFFF);
                else
                    return string.Format("{0}_{1:X}",MethodEntryPoint.Label,address - MethodEntryPoint.address);
            }
            set { label = value; }
        }

        public Word MethodEntryPoint
        {
            get
            {
                int a;
                for (a = address;!program[a].ismethod;a -= 4)
                {
                }
                return program[a];
            }
        }

        public bool IsWeirdReturn
        {
            get { return isweirdreturn; }
            set { isweirdreturn = value; }
        }

        public string Text
        {
            get
            {
                char[] result = new char [4];
                for (int i = 0;i < 4;i++)
                {
                    result[i] = (char)((value >> (i * 8)) & 0xFF);
                    if (char.IsControl(result[i]))
                        result[i] = '.';
                }
                return new string(result);
            }
        }

        public string HackString
        {
            get { return hackstring; }
            set { hackstring = value; }
        }

        public bool HackMustInvalidateICache
        {
            get { return hackmustinvalidateicache; }
            set { hackmustinvalidateicache = value; }
        }

        public void Discompile(bool direct)
        {
            instruction.Discompile(program,address,direct);
        }

        public void AddDestination(int address)
        {
            if (!(instruction is JRInstruction))
                throw new PSXException();
            if (!destinations.Contains(program[address]))
                destinations.Add(program[address]);
        }

        public void AddCalleeList(IEnumerable<Word> callees)
        {
            if (!(instruction is JALRInstruction))
                throw new PSXException();
            foreach (Word callee in callees)
            {
                if (!destinations.Contains(callee))
                {
                    destinations.Add(callee);
                    program.MarkCall(callee.address,address + 8);
                }
            }
        }

        public void DefineSwitchTable(int address,int count)
        {
            if (destinations.Count > 0)
                throw new PSXException();
            for (int i = 0;i < count;i++)
            {
                Word destination = program[address + i * 4];
                if (destination.IsCode)
                    throw new PSXException();
                AddDestination(destination.Value);
            }
        }
    }
}
