using System.IO;

namespace PSXDiscompile
{
    public sealed class MTLOInstruction : Instruction
    {
        private Register rs;

        public MTLOInstruction(Register rs)
        {
            this.rs = rs;
        }

        public override string ToString()
        {
            return string.Format("MTLO ${0}",rs);
        }

        public override void Discompile(Program p,int address,bool direct)
        {
            //p.WriteLine("ZZ_ONCE(0x{0:X});",address);return;
            p.WriteLine("LO = {0};",rs);
        }
    }
}
