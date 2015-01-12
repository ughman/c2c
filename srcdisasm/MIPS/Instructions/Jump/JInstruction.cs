using System.IO;

namespace PSXDiscompile
{
    public sealed class JInstruction : Instruction
    {
        private int target;

        public JInstruction(int target)
        {
            this.target = target;
        }

        public override string ToString()
        {
            return string.Format("J {0:X}",target);
        }

        public override string ToString(Program p,int address)
        {
            return string.Format("J {0:X}",(address & ~0xFFFFFFF) | target << 2);
        }

        public override void Mark(Program p,int address)
        {
            p.MarkDelaySlot(address + 4);
            p.MarkBranch((address & ~0xFFFFFFF) | target << 2);
        }

        public override void Discompile(Program p,int address,bool direct)
        {
            //p.WriteLine("ZZ_ONCEBRANCH(0x{0:X},{1});",address,p.Clocks);return;
            if (!direct)
                throw new PSXException();
            Word nextword = p[address + 4];
            Word branchword = p[(address & ~0xFFFFFFF) | target << 2];
            nextword.Discompile(false);
            p.WriteClocks(1,branchword.Address);
            p.WriteLine("goto {0};",branchword.Label);
        }
    }
}
