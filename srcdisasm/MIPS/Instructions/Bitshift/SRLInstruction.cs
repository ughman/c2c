using System.IO;

namespace PSXDiscompile
{
    public sealed class SRLInstruction : Instruction
    {
        private Register rt;
        private Register rd;
        private int shamt;

        public SRLInstruction(Register rt,Register rd,int shamt)
        {
            this.rt = rt;
            this.rd = rd;
            this.shamt = shamt;
        }

        public override string ToString()
        {
            return string.Format("SRL ${0},${1},{2}",rd,rt,shamt);
        }

        public override void Discompile(Program p,int address,bool direct)
        {
            //p.WriteLine("ZZ_ONCE(0x{0:X});",address);return;
            if (rt == rd)
                p.WriteLine("{0} >>= {1};",rd,shamt);
            else
                p.WriteLine("{0} = {1} >> {2};",rd,rt,shamt);
        }
    }
}
