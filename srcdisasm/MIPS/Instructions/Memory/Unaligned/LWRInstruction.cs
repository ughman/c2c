using System.IO;

namespace PSXDiscompile
{
    public sealed class LWRInstruction : Instruction
    {
        private Register rs;
        private Register rd;
        private int imm;

        public LWRInstruction(Register rs,Register rd,int imm)
        {
            this.rs = rs;
            this.rd = rd;
            this.imm = imm;
        }

        public override string ToString()
        {
            return string.Format("LWR ${0},{2}(${1})",rd,rs,imm);
        }

        public override void Discompile(Program p,int address,bool direct)
        {
            //p.WriteLine("ZZ_ONCE(0x{0:X});",address);return;
            if (imm == 0)
                p.WriteLine("EMU_ReadRight({0},&{1});",rs,rd);
            else
                p.WriteLine("EMU_ReadRight({0} + {1},&{2}); //+ 0x{1:X}",rs,imm,rd);
        }
    }
}
