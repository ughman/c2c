using System.IO;

namespace PSXDiscompile
{
    public sealed class CTCInstruction : Instruction
    {
        private int copid;
        private Register rs;
        private int coprd;

        public CTCInstruction(int copid,Register rs,int coprd)
        {
            this.copid = copid;
            this.rs = rs;
            this.coprd = coprd;
        }

        public override string ToString()
        {
            return string.Format("CTC{0} ${1},${2}",copid,rs,coprd);
        }

        public override void Discompile(Program p,int address,bool direct)
        {
            //p.WriteLine("ZZ_ONCE(0x{0:X});",address);return;
            if (copid == 0)
            {
                throw new PSXException();
            }
            else if (copid == 2)
            {
                p.WriteLine("GTE_SetControlRegister({0},{1});",coprd,rs);
            }
            else
            {
                throw new PSXException();
            }
        }
    }
}
