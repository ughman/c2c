using System.IO;

namespace PSXDiscompile
{
    public sealed class MFCInstruction : Instruction
    {
        private int copid;
        private Register rd;
        private int coprs;

        public MFCInstruction(int copid,Register rd,int coprs)
        {
            this.copid = copid;
            this.rd = rd;
            this.coprs = coprs;
        }

        public override string ToString()
        {
            return string.Format("MFC{0} ${1},${2}",copid,rd,coprs);
        }

        public override void Discompile(Program p,int address,bool direct)
        {
            //p.WriteLine("ZZ_ONCE(0x{0:X});",address);return;
            if (copid == 0)
            {
                p.WriteLine("{0} = COP0_GetRegister({1});",rd,coprs);
            }
            else if (copid == 2)
            {
                p.WriteLine("{0} = GTE_GetDataRegister({1});",rd,coprs);
            }
            else
            {
                throw new PSXException();
            }
        }
    }
}
