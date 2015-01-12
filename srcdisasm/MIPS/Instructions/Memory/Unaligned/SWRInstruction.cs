using System.IO;

namespace PSXDiscompile
{
    public sealed class SWRInstruction : Instruction
    {
        private Register rs;
        private Register rt;
        private int imm;

        public SWRInstruction(Register rs,Register rt,int imm)
        {
            this.rs = rs;
            this.rt = rt;
            this.imm = imm;
        }

        public override string ToString()
        {
            return string.Format("SWR ${0},{2}(${1})",rt,rs,imm);
        }

        public override void Discompile(Program p,int address,bool direct)
        {
            //p.WriteLine("ZZ_ONCE(0x{0:X});",address);return;
            if (imm == 0)
                p.WriteLine("EMU_WriteRight({0},{1});",rs,rt);
            else
                p.WriteLine("EMU_WriteRight({0} + {1},{2}); //+ 0x{1:X}",rs,imm,rt);
        }
    }
}
