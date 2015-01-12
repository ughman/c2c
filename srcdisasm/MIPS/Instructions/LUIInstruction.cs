using System.IO;

namespace PSXDiscompile
{
    public sealed class LUIInstruction : Instruction
    {
        private Register rd;
        private int imm;

        public LUIInstruction(Register rd,int imm)
        {
            this.rd = rd;
            this.imm = imm;
        }

        public override string ToString()
        {
            return string.Format("LUI ${0},{1}",rd,imm);
        }

        public override void Discompile(Program p,int address,bool direct)
        {
            //p.WriteLine("ZZ_ONCE(0x{0:X});",address);return;
            p.WriteLine("{0} = 0x{1:X}0000;",rd,imm);
        }
    }
}
