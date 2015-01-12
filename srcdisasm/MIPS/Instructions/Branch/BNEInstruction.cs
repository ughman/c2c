using System.IO;

namespace PSXDiscompile
{
    public sealed class BNEInstruction : Instruction
    {
        private Register rs;
        private Register rt;
        private int offset;

        public BNEInstruction(Register rs,Register rt,int offset)
        {
            this.rs = rs;
            this.rt = rt;
            this.offset = offset;
        }

        public override string ToString()
        {
            return string.Format("BNE ${0},${1},{2:X}",rs,rt,offset * 4 + 4);
        }

        public override string ToString(Program p,int address)
        {
            return string.Format("BNE ${0},${1},{2:X}",rs,rt,address + offset * 4 + 4);
        }

        public override void Mark(Program p,int address)
        {
            base.Mark(p,address);
            p.MarkBranch(address + offset * 4 + 4);
        }

        public override void Discompile(Program p,int address,bool direct)
        {
            //p.WriteLine("ZZ_ONCEBRANCH(0x{0:X},{1});",address,p.Clocks);return;
            if (!direct)
                throw new PSXException();
            Word nextword = p[address + 4];
            Word branchword = p[address + offset * 4 + 4];
            if (rs == Register.R0)
                p.WriteLine("if ({0})",rt);
            else if (rt == Register.R0)
                p.WriteLine("if ({0})",rs);
            else
                p.WriteLine("if ({0} != {1})",rs,rt);
            p.WriteLine("{{");
            p.Indent();
            nextword.Discompile(false);
            p.WriteClocks(1,branchword.Address);
            p.WriteLine("goto {0};",branchword.Label);
            p.Unindent();
            p.WriteLine("}}");
        }
    }
}
