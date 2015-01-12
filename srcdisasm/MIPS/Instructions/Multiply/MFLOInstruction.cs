using System.IO;

namespace PSXDiscompile
{
    public sealed class MFLOInstruction : Instruction
    {
        private Register rd;

        public MFLOInstruction(Register rd)
        {
            this.rd = rd;
        }

        public override string ToString()
        {
            return string.Format("MFLO ${0}",rd);
        }

        public override void Discompile(Program p,int address,bool direct)
        {
            //p.WriteLine("ZZ_ONCE(0x{0:X});",address);return;
            p.WriteLine("{0} = LO;",rd);
        }
    }
}
