using System.IO;

namespace PSXDiscompile
{
    public sealed class BREAKInstruction : Instruction
    {
        private int func;

        public BREAKInstruction(int func)
        {
            this.func = func;
        }

        public override string ToString()
        {
            return string.Format("BREAK {0}",func);
        }

        public override void Discompile(Program p,int address,bool direct)
        {
            p.WriteLine("EMU_Break({0});",func);
        }
    }
}
