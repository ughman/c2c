using System.IO;

namespace PSXDiscompile
{
    public sealed class COPInstruction : Instruction
    {
        private int copid;
        private int copargs;

        public COPInstruction(int copid,int copargs)
        {
            this.copid = copid;
            this.copargs = copargs;
        }

        public override string ToString()
        {
            return string.Format("COP{0} 0x{1:X7}",copid,copargs);
        }

        public override void Discompile(Program p,int address,bool direct)
        {
            //p.WriteLine("ZZ_ONCE(0x{0:X});",address);return;
            if (copid == 0)
            {
                p.WriteLine("COP0_Execute({0});",copargs);
            }
            else if (copid == 2)
            {
                p.WriteLine("GTE_Execute({0});",copargs);
            }
            else
            {
                throw new PSXException();
            }
        }
    }
}
