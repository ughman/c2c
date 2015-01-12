using System;
using System.IO;

namespace PSXDiscompile
{
    public sealed class JRInstruction : Instruction
    {
        private Register rs;

        public JRInstruction(Register rs)
        {
            this.rs = rs;
        }

        public override string ToString()
        {
            return string.Format("JR ${0}",rs);
        }

        public override void Mark(Program p,int address)
        {
            p.MarkDelaySlot(address + 4);
            foreach (Word destination in p[address].Destinations)
            {
                p.MarkBranch(destination.Address);
            }
        }

        public override void Discompile(Program p,int address,bool direct)
        {
            //p.WriteLine("ZZ_ONCEBRANCH(0x{0:X},{1});",address,p.Clocks);return;
            if (!direct)
                throw new PSXException();
            Word nextword = p[address + 4];
            p.WriteLine("ZZ_JUMPREGISTER_BEGIN({0});",rs);
            nextword.Discompile(false);
            p.WriteClocksJR(1);
            if (p[address].DirectBranch.HasValue)
            {
                p.WriteLine("ZZ_JUMPREGISTER(0x{0:X},ZZ_FORCEEXIT);",p[address].DirectBranch.Value);
            }
            else if (p[address].Destinations.Count > 0)
            {
                foreach (Word destination in p[address].Destinations)
                {
                    p.WriteLine("ZZ_JUMPREGISTER(0x{0:X},{1});",destination.Address,destination.Label);
                }
            }
            else if (rs == Register.RA || p[address].IsWeirdReturn)
            {
                foreach (Word caller in p[address].MethodEntryPoint.Callers)
                {
                    p.WriteLine("ZZ_JUMPREGISTER(0x{0:X},{1});",caller.Address,caller.Label);
                }
            }
            else
            {
                p.WriteLine("// UNIMPLEMENTED INDIRECT JUMP ({0},{1:X})",rs,address);
                p.WriteLine("// PC IS {0:X}",address);
            }
            p.WriteLine("ZZ_JUMPREGISTER_END();");
        }
    }
}
