using System.IO;

namespace PSXDiscompile
{
    public abstract class Instruction
    {
        public static Instruction Disassemble(int value)
        {
            if (value == 0)
                return new NOPInstruction();
            int opcode = Cutter.Cut(value,0,6,true);
            int rs = Cutter.Cut(value,6,5,true);
            int rt = Cutter.Cut(value,11,5,true);
            int rd = Cutter.Cut(value,16,5,true);
            int shamt = Cutter.Cut(value,21,5,true);
            int func = Cutter.Cut(value,26,6,true);
            int imm = Cutter.Cut(value,16,16,false);
            int uimm = Cutter.Cut(value,16,16,true);
            int jumptarget = Cutter.Cut(value,6,26,true);
            int copid = Cutter.Cut(value,4,2,true);
            int copargs = Cutter.Cut(value,7,25,true);
            int sysfunc = Cutter.Cut(value,6,20,true);
            Register rrs = (Register)rs;
            Register rrt = (Register)rt;
            Register rrd = (Register)rd;
            switch ((Opcode)opcode)
            {
                case Opcode.Special:
                    switch ((Function)func)
                    {
                        case Function.SLL:
                            return new SLLInstruction(rrt,rrd,shamt);
                        case Function.SRL:
                            return new SRLInstruction(rrt,rrd,shamt);
                        case Function.SRA:
                            return new SRAInstruction(rrt,rrd,shamt);
                        case Function.SLLV:
                            return new SLLVInstruction(rrs,rrt,rrd);
                        case Function.SRLV:
                            return new SRLVInstruction(rrs,rrt,rrd);
                        case Function.SRAV:
                            return new SRAVInstruction(rrs,rrt,rrd);
                        case Function.JR:
                            return new JRInstruction(rrs);
                        case Function.JALR:
                            return new JALRInstruction(rrs,rrd);
                        case Function.SYSCALL:
                            return new SYSCALLInstruction(sysfunc);
                        case Function.BREAK:
                            return new BREAKInstruction(sysfunc);
                        case Function.MFHI:
                            return new MFHIInstruction(rrd);
                        case Function.MTHI:
                            return new MTHIInstruction(rrs);
                        case Function.MFLO:
                            return new MFLOInstruction(rrd);
                        case Function.MTLO:
                            return new MTLOInstruction(rrs);
                        case Function.MULT:
                            return new MULTInstruction(rrs,rrt);
                        case Function.MULTU:
                            return new MULTUInstruction(rrs,rrt);
                        case Function.DIV:
                            return new DIVInstruction(rrs,rrt);
                        case Function.DIVU:
                            return new DIVUInstruction(rrs,rrt);
                        case Function.ADD:
                            return new ADDInstruction(rrs,rrt,rrd);
                        case Function.ADDU:
                            return new ADDUInstruction(rrs,rrt,rrd);
                        case Function.SUB:
                            return new SUBInstruction(rrs,rrt,rrd);
                        case Function.SUBU:
                            return new SUBUInstruction(rrs,rrt,rrd);
                        case Function.AND:
                            return new ANDInstruction(rrs,rrt,rrd);
                        case Function.OR:
                            return new ORInstruction(rrs,rrt,rrd);
                        case Function.XOR:
                            return new XORInstruction(rrs,rrt,rrd);
                        case Function.NOR:
                            return new NORInstruction(rrs,rrt,rrd);
                        case Function.SLT:
                            return new SLTInstruction(rrs,rrt,rrd);
                        case Function.SLTU:
                            return new SLTUInstruction(rrs,rrt,rrd);
                    }
                    break;
                case Opcode.REGIMM:
                    switch ((REGIMM)rt)
                    {
                        case REGIMM.BLTZ:
                            return new BLTZInstruction(rrs,imm);
                        case REGIMM.BGEZ:
                            return new BGEZInstruction(rrs,imm);
                        case REGIMM.BLTZAL:
                            return new BLTZALInstruction(rrs,imm);
                        case REGIMM.BGEZAL:
                            return new BGEZALInstruction(rrs,imm);
                    }
                    break;
                case Opcode.J:
                    return new JInstruction(jumptarget);
                case Opcode.JAL:
                    return new JALInstruction(jumptarget);
                case Opcode.BEQ:
                    return new BEQInstruction(rrs,rrt,imm);
                case Opcode.BNE:
                    return new BNEInstruction(rrs,rrt,imm);
                case Opcode.BLEZ:
                    return new BLEZInstruction(rrs,imm);
                case Opcode.BGTZ:
                    return new BGTZInstruction(rrs,imm);
                case Opcode.ADDI:
                    return new ADDIInstruction(rrs,rrt,imm);
                case Opcode.ADDIU:
                    return new ADDIUInstruction(rrs,rrt,imm);
                case Opcode.SLTI:
                    return new SLTIInstruction(rrs,rrt,imm);
                case Opcode.SLTIU:
                    return new SLTIUInstruction(rrs,rrt,uimm);
                case Opcode.ANDI:
                    return new ANDIInstruction(rrs,rrt,uimm);
                case Opcode.ORI:
                    return new ORIInstruction(rrs,rrt,uimm);
                case Opcode.XORI:
                    return new XORIInstruction(rrs,rrt,uimm);
                case Opcode.LUI:
                    return new LUIInstruction(rrt,uimm);
                case Opcode.COP0:
                case Opcode.COP1:
                case Opcode.COP2:
                case Opcode.COP3:
                    if ((rs & 0x10) == 0)
                    {
                        switch ((COPFunction)rs)
                        {
                            case COPFunction.MFC:
                                return new MFCInstruction(copid,rrt,rd);
                            case COPFunction.CFC:
                                return new CFCInstruction(copid,rrt,rd);
                            case COPFunction.MTC:
                                return new MTCInstruction(copid,rrt,rd);
                            case COPFunction.CTC:
                                return new CTCInstruction(copid,rrt,rd);
                        }
                    }
                    else
                    {
                        return new COPInstruction(copid,copargs);
                    }
                    break;
                case Opcode.LB:
                    return new LBInstruction(rrs,rrt,imm);
                case Opcode.LH:
                    return new LHInstruction(rrs,rrt,imm);
                case Opcode.LWL:
                    return new LWLInstruction(rrs,rrt,imm);
                case Opcode.LW:
                    return new LWInstruction(rrs,rrt,imm);
                case Opcode.LBU:
                    return new LBUInstruction(rrs,rrt,imm);
                case Opcode.LHU:
                    return new LHUInstruction(rrs,rrt,imm);
                case Opcode.LWR:
                    return new LWRInstruction(rrs,rrt,imm);
                case Opcode.SB:
                    return new SBInstruction(rrs,rrt,imm);
                case Opcode.SH:
                    return new SHInstruction(rrs,rrt,imm);
                case Opcode.SW:
                    return new SWInstruction(rrs,rrt,imm);
                case Opcode.SWL:
                    return new SWLInstruction(rrs,rrt,imm);
                case Opcode.SWR:
                    return new SWRInstruction(rrs,rrt,imm);
                case Opcode.LWC0:
                case Opcode.LWC1:
                case Opcode.LWC2:
                case Opcode.LWC3:
                    return new LWCInstruction(copid,rrs,rt,imm);
                case Opcode.SWC0:
                case Opcode.SWC1:
                case Opcode.SWC2:
                case Opcode.SWC3:
                    return new SWCInstruction(copid,rrs,rt,imm);
            }
            return new InvalidInstruction(value);
        }

        public abstract override string ToString();

        public virtual string ToString(Program p,int address)
        {
            return ToString();
        }

        public virtual void Mark(Program p,int address)
        {
            p.MarkDirect(address + 4);
        }

        public abstract void Discompile(Program p,int address,bool direct);
    }
}
