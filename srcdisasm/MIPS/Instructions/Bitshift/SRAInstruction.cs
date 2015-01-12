using System.IO;

namespace PSXDiscompile
{
    public sealed class SRAInstruction : Instruction
    {
        private Register rt;
        private Register rd;
        private int shamt;

        public SRAInstruction(Register rt,Register rd,int shamt)
        {
            this.rt = rt;
            this.rd = rd;
            this.shamt = shamt;
        }

        public override string ToString()
        {
            return string.Format("SRA ${0},${1},{2}",rd,rt,shamt);
        }

        public override void Discompile(Program p,int address,bool direct)
        {
            //p.WriteLine("ZZ_ONCE(0x{0:X});",address);return;
            p.WriteLine("{0} = (int32_t){1} >> {2};",rd,rt,shamt);
        }
    }
}
