using System.IO;

namespace PSXDiscompile
{
    public sealed class JALInstruction : Instruction
    {
        private int target;

        public JALInstruction(int target)
        {
            this.target = target;
        }

        public override string ToString()
        {
            return string.Format("JAL {0:X}",target);
        }

        public override string ToString(Program p,int address)
        {
            return string.Format("JAL {0:X}",(address & ~0xFFFFFFF) | target << 2);
        }

        public override void Mark(Program p,int address)
        {
            p.MarkDelaySlot(address + 4);
            p.MarkBranch(address + 8);
            p.MarkCall((address & ~0xFFFFFFF) | target << 2,address + 8);
        }

        public override void Discompile(Program p,int address,bool direct)
        {
            //p.WriteLine("ZZ_ONCEBRANCH(0x{0:X},{1});",address,p.Clocks);return;
            if (!direct)
                throw new PSXException();
            Word nextword = p[address + 4];
            Word linkword = p[address + 8];
            Word branchword = p[(address & ~0xFFFFFFF) | target << 2];
            p.WriteLine("RA = 0x{0:X}; //{1}",linkword.Address,linkword.Label);
            nextword.Discompile(false);
            p.WriteClocks(1,branchword.Address);
            p.WriteLine("goto {0};",branchword.Label);
        }
    }
}
