using System.IO;

namespace PSXDiscompile
{
    public sealed class MFHIInstruction : Instruction
    {
        private Register rd;

        public MFHIInstruction(Register rd)
        {
            this.rd = rd;
        }

        public override string ToString()
        {
            return string.Format("MFHI ${0}",rd);
        }

        public override void Discompile(Program p,int address,bool direct)
        {
            //p.WriteLine("ZZ_ONCE(0x{0:X});",address);return;
            p.WriteLine("{0} = HI;",rd);
        }
    }
}
