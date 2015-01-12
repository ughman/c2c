using System.IO;

namespace PSXDiscompile
{
    public sealed class SLTIUInstruction : Instruction
    {
        private Register rs;
        private Register rd;
        private int imm;

        public SLTIUInstruction(Register rs,Register rd,int imm)
        {
            this.rs = rs;
            this.rd = rd;
            this.imm = imm;
        }

        public override string ToString()
        {
            return string.Format("SLTIU ${0},${1},{2}",rd,rs,imm);
        }

        public override void Discompile(Program p,int address,bool direct)
        {
            //p.WriteLine("ZZ_ONCE(0x{0:X});",address);return;
            p.WriteLine("{0} = {1} < {2};",rd,rs,imm);
        }
    }
}
