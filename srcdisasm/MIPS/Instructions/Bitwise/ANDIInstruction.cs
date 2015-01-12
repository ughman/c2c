using System.IO;

namespace PSXDiscompile
{
    public sealed class ANDIInstruction : Instruction
    {
        private Register rs;
        private Register rd;
        private int imm;

        public ANDIInstruction(Register rs,Register rd,int imm)
        {
            this.rs = rs;
            this.rd = rd;
            this.imm = imm;
        }

        public override string ToString()
        {
            return string.Format("ANDI ${0},${1},{2}",rd,rs,imm);
        }

        public override void Discompile(Program p,int address,bool direct)
        {
            //p.WriteLine("ZZ_ONCE(0x{0:X});",address);return;
            if (rs == rd)
                p.WriteLine("{0} &= 0x{1:X};",rd,imm);
            else
                p.WriteLine("{0} = {1} & 0x{2:X};",rd,rs,imm);
        }
    }
}
