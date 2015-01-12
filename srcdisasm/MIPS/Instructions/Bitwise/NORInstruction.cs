using System.IO;

namespace PSXDiscompile
{
    public sealed class NORInstruction : Instruction
    {
        private Register rs;
        private Register rt;
        private Register rd;

        public NORInstruction(Register rs,Register rt,Register rd)
        {
            this.rs = rs;
            this.rt = rt;
            this.rd = rd;
        }

        public override string ToString()
        {
            return string.Format("NOR ${0},${1},${2}",rd,rs,rt);
        }

        public override void Discompile(Program p,int address,bool direct)
        {
            //p.WriteLine("ZZ_ONCE(0x{0:X});",address);return;
            if (rs == Register.R0)
                p.WriteLine("{0} = ~{1};",rd,rt);
            else if (rt == Register.R0)
                p.WriteLine("{0} = ~{1};",rd,rs);
            else
                p.WriteLine("{0} = ~({1} | {2});",rd,rs,rt);
        }
    }
}
