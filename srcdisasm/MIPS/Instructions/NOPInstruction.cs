using System.IO;

namespace PSXDiscompile
{
    public sealed class NOPInstruction : Instruction
    {
        public override string ToString()
        {
            return "NOP";
        }

        public override void Discompile(Program p,int address,bool direct)
        {
        }
    }
}
