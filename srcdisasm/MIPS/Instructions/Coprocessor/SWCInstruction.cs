using System.IO;

namespace PSXDiscompile
{
    public sealed class SWCInstruction : Instruction
    {
        private int copid;
        private Register rs;
        private int coprt;
        private int imm;

        public SWCInstruction(int copid,Register rs,int coprt,int imm)
        {
            this.copid = copid;
            this.rs = rs;
            this.coprt = coprt;
            this.imm = imm;
        }

        public override string ToString()
        {
            return string.Format("SWC{0} ${1},{3}(${2})",copid,coprt,rs,imm);
        }

        public override void Discompile(Program p,int address,bool direct)
        {
            //p.WriteLine("ZZ_ONCE(0x{0:X});",address);return;
            if (copid == 0)
            {
                if (imm == 0)
                    p.WriteLine("EMU_Write32({0},COP0_GetRegister({1}));",rs,coprt);
                else
                    p.WriteLine("EMU_Write32({0} + {1},COP0_GetRegister({2})); //+ 0x{1:X}",rs,imm,coprt);
            }
            else if (copid == 2)
            {
                if (imm == 0)
                    p.WriteLine("EMU_Write32({0},GTE_GetDataRegister({1}));",rs,coprt);
                else
                    p.WriteLine("EMU_Write32({0} + {1},GTE_GetDataRegister({2})); //+ 0x{1:X}",rs,imm,coprt);
            }
            else
            {
                throw new PSXException();
            }
        }
    }
}
