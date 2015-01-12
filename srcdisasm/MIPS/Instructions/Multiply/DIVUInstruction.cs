using System.IO;

namespace PSXDiscompile
{
    public sealed class DIVUInstruction : Instruction
    {
        private Register rs;
        private Register rt;

        public DIVUInstruction(Register rs,Register rt)
        {
            this.rs = rs;
            this.rt = rt;
        }

        public override string ToString()
        {
            return string.Format("DIVU ${0},${1}",rs,rt);
        }

        public override void Discompile(Program p,int address,bool direct)
        {
            //p.WriteLine("ZZ_ONCE(0x{0:X});",address);return;
            p.WriteLine("EMU_UDivide({0},{1});",rs,rt);
        }
    }
}
