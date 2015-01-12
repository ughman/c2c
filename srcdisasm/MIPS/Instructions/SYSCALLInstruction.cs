using System.IO;

namespace PSXDiscompile
{
    public sealed class SYSCALLInstruction : Instruction
    {
        private int func;

        public SYSCALLInstruction(int func)
        {
            this.func = func;
        }

        public override string ToString()
        {
            return string.Format("SYSCALL {0}",func);
        }

        public override void Discompile(Program p,int address,bool direct)
        {
            //p.WriteLine("ZZ_ONCE(0x{0:X});",address);return;
            p.WriteLine("EMU_Syscall(0x{0:X});",address);
        }
    }
}
