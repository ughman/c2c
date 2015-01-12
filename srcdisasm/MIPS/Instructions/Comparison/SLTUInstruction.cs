using System.IO;

namespace PSXDiscompile
{
    public sealed class SLTUInstruction : Instruction
    {
        private Register rs;
        private Register rt;
        private Register rd;

        public SLTUInstruction(Register rs,Register rt,Register rd)
        {
            this.rs = rs;
            this.rt = rt;
            this.rd = rd;
        }

        public override string ToString()
        {
            return string.Format("SLTU ${0},${1},${2}",rd,rs,rt);
        }

        public override void Discompile(Program p,int address,bool direct)
        {
            //p.WriteLine("ZZ_ONCE(0x{0:X});",address);return;
            p.WriteLine("{0} = {1} < {2};",rd,rs,rt);
        }
    }
}
