using System.IO;

namespace PSXDiscompile
{
    public sealed class LWCInstruction : Instruction
    {
        private int copid;
        private Register rs;
        private int coprd;
        private int imm;

        public LWCInstruction(int copid,Register rs,int coprd,int imm)
        {
            this.copid = copid;
            this.rs = rs;
            this.coprd = coprd;
            this.imm = imm;
        }

        public override string ToString()
        {
            return string.Format("LWC{0} ${1},{3}(${2})",copid,coprd,rs,imm);
        }

        public override void Discompile(Program p,int address,bool direct)
        {
            //p.WriteLine("ZZ_ONCE(0x{0:X});",address);return;
            if (copid == 0)
            {
                if (imm == 0)
                    p.WriteLine("COP0_SetRegister({0},EMU_ReadU32({1}));",coprd,rs);
                else
                    p.WriteLine("COP0_SetRegister({0},EMU_ReadU32({1} + {2})); //+ 0x{2:X}",coprd,rs,imm);
            }
            else if (copid == 2)
            {
                if (imm == 0)
                    p.WriteLine("GTE_SetDataRegister({0},EMU_ReadU32({1}));",coprd,rs);
                else
                    p.WriteLine("GTE_SetDataRegister({0},EMU_ReadU32({1} + {2})); //+ 0x{2:X}",coprd,rs,imm);
            }
            else
            {
                throw new PSXException();
            }
        }
    }
}
