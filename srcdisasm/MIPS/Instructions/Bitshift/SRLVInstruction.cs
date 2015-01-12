using System.IO;

namespace PSXDiscompile
{
    public sealed class SRLVInstruction : Instruction
    {
        private Register rs;
        private Register rt;
        private Register rd;

        public SRLVInstruction(Register rs,Register rt,Register rd)
        {
            this.rs = rs;
            this.rt = rt;
            this.rd = rd;
        }

        public override string ToString()
        {
            return string.Format("SRLV ${0},${1},${2}",rd,rt,rs);
        }

        public override void Discompile(Program p,int address,bool direct)
        {
            //p.WriteLine("ZZ_ONCE(0x{0:X});",address);return;
            if (rt == rd)
                p.WriteLine("{0} >>= {1};",rd,rs);
            else
                p.WriteLine("{0} = {1} >> {2};",rd,rt,rs);
        }
    }
}
