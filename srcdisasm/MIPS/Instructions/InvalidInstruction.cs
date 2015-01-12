using System.IO;

namespace PSXDiscompile
{
    public sealed class InvalidInstruction : Instruction
    {
        private int value;

        public InvalidInstruction(int value)
        {
            this.value = value;
        }

        public override string ToString()
        {
            return string.Format("INVALID 0x{0:X8}",value);
        }

        public override void Discompile(Program p,int address,bool direct)
        {
            throw new PSXException("Unrecognized opcode.");
        }
    }
}
