using System.IO;

namespace PSXDiscompile
{
    public sealed class SRAVInstruction : Instruction
    {
        private Register rs;
        private Register rt;
        private Register rd;

        public SRAVInstruction(Register rs,Register rt,Register rd)
        {
            this.rs = rs;
            this.rt = rt;
            this.rd = rd;
        }

        public override string ToString()
        {
            return string.Format("SRAV ${0},${1},${2}",rd,rt,rs);
        }

        public override void Discompile(Program p,int address,bool direct)
        {
            //p.WriteLine("ZZ_ONCE(0x{0:X});",address);return;
            p.WriteLine("{0} = (int32_t){1} >> {2};",rd,rt,rs);
        }
    }
}
