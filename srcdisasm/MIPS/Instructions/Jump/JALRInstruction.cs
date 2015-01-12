using System;
using System.IO;

namespace PSXDiscompile
{
    public sealed class JALRInstruction : Instruction
    {
        private Register rs;
        private Register rd;

        public JALRInstruction(Register rs,Register rd)
        {
            this.rs = rs;
            this.rd = rd;
        }

        public override string ToString()
        {
            if (rd == Register.RA)
                return string.Format("JALR ${0}",rs);
            return string.Format("JALR ${0},${1}",rd,rs);
        }

        public override void Mark(Program p,int address)
        {
            p.MarkDelaySlot(address + 4);
            p.MarkBranch(address + 8);
        }

        public override void Discompile(Program p,int address,bool direct)
        {
            //p.WriteLine("ZZ_ONCEBRANCH(0x{0:X},{1});",address,p.Clocks);return;
            if (!direct)
                throw new PSXException();
            Word nextword = p[address + 4];
            Word linkword = p[address + 8];
            p.WriteLine("ZZ_JUMPREGISTER_BEGIN({0});",rs);
            p.WriteLine("{0} = 0x{1:X}; //{2}",rd,linkword.Address,linkword.Label);
            nextword.Discompile(false);
            p.WriteClocksJR(1);
            if (p[address].Destinations.Count > 0)
            {
                foreach (Word destination in p[address].Destinations)
                {
                    p.WriteLine("ZZ_JUMPREGISTER(0x{0:X},{1});",destination.Address,destination.Label);
                }
            }
            else
            {
                p.WriteLine("// UNIMPLEMENTED JUMP-TO-REGISTER-AND-LINK ({0},{1:X})",rs,address);
            }
            p.WriteLine("ZZ_JUMPREGISTER_END();");
        }
    }
}
