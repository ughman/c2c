using System.IO;

namespace PSXDiscompile
{
    public sealed class SWLInstruction : Instruction
    {
        private Register rs;
        private Register rt;
        private int imm;

        public SWLInstruction(Register rs,Register rt,int imm)
        {
            this.rs = rs;
            this.rt = rt;
            this.imm = imm;
        }

        public override string ToString()
        {
            return string.Format("SWL ${0},{2}(${1})",rt,rs,imm);
        }

        public override void Discompile(Program p,int address,bool direct)
        {
            //p.WriteLine("ZZ_ONCE(0x{0:X});",address);return;
            if (imm == 0)
                p.WriteLine("EMU_WriteLeft({0},{1});",rs,rt);
            else
                p.WriteLine("EMU_WriteLeft({0} + {1},{2}); //+ 0x{1:X}",rs,imm,rt);
        }
    }
}
