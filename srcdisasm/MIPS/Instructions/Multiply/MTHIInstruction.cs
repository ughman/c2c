using System.IO;

namespace PSXDiscompile
{
    public sealed class MTHIInstruction : Instruction
    {
        private Register rs;

        public MTHIInstruction(Register rs)
        {
            this.rs = rs;
        }

        public override string ToString()
        {
            return string.Format("MTHI ${0}",rs);
        }

        public override void Discompile(Program p,int address,bool direct)
        {
            //p.WriteLine("ZZ_ONCE(0x{0:X});",address);return;
            p.WriteLine("HI = {0};",rs);
        }
    }
}
