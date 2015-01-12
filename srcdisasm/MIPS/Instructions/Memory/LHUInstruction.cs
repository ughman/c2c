using System.IO;

namespace PSXDiscompile
{
    public sealed class LHUInstruction : Instruction
    {
        private Register rs;
        private Register rd;
        private int imm;

        public LHUInstruction(Register rs,Register rd,int imm)
        {
            this.rs = rs;
            this.rd = rd;
            this.imm = imm;
        }

        public override string ToString()
        {
            return string.Format("LHU ${0},{2}(${1})",rd,rs,imm);
        }

        public override void Discompile(Program p,int address,bool direct)
        {
            //p.WriteLine("ZZ_ONCE(0x{0:X});",address);return;
            if (imm == 0)
                p.WriteLine("{0} = EMU_ReadU16({1});",rd,rs);
            else if (imm < 0)
                p.WriteLine("{0} = EMU_ReadU16({1} - {2}); //+ 0x{3:X}",rd,rs,-imm,imm);
            else
                p.WriteLine("{0} = EMU_ReadU16({1} + {2}); //+ 0x{2:X}",rd,rs,imm);
        }
    }
}
