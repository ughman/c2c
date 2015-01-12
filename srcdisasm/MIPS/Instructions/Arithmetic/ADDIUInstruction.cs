using System.IO;

namespace PSXDiscompile
{
    public sealed class ADDIUInstruction : Instruction
    {
        private Register rs;
        private Register rd;
        private int imm;

        public ADDIUInstruction(Register rs,Register rd,int imm)
        {
            this.rs = rs;
            this.rd = rd;
            this.imm = imm;
        }

        public override string ToString()
        {
            return string.Format("ADDIU ${0},${1},{2}",rd,rs,imm);
        }

        public override void Discompile(Program p,int address,bool direct)
        {
            //p.WriteLine("ZZ_ONCE(0x{0:X});",address);return;
            if (rs == Register.R0)
                p.WriteLine("{0} = {1};",rd,imm);
            else if (imm < 0)
            {
                if (rs == rd)
                    p.WriteLine("{0} -= {1};",rd,-imm);
                else
                    p.WriteLine("{0} = {1} - {2};",rd,rs,-imm);
            }
            else
            {
                if (rs == rd)
                    p.WriteLine("{0} += {1};",rd,imm);
                else
                    p.WriteLine("{0} = {1} + {2};",rd,rs,imm);
            }
        }
    }
}
