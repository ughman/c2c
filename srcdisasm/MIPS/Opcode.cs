namespace PSXDiscompile
{
    public enum Opcode
    {
        Special = 0,
        REGIMM = 1,
        J = 2,
        JAL = 3,
        BEQ = 4,
        BNE = 5,
        BLEZ = 6,
        BGTZ = 7,
        ADDI = 8,
        ADDIU = 9,
        // The R3000 documentation I was looking at describes
        // two opcodes "SUBI" and "SUBUI" in the place of
        // SLTI and SLTIU, but also describes SLTI and SLTUI,
        // so I don't know what the hell is going on.
        // Apparently SUBI and SUBIU don't actually exist.
        SLTI = 10,
        SLTIU = 11,
        ANDI = 12,
        ORI = 13,
        XORI = 14,
        LUI = 15,
        COP0 = 16,
        COP1 = 17,
        COP2 = 18,
        COP3 = 19,
        LB = 32,
        LH = 33,
        LWL = 34,
        LW = 35,
        LBU = 36,
        LHU = 37,
        LWR = 38,
        SB = 40,
        SH = 41,
        SWL = 42,
        SW = 43,
        SWR = 46,
        LWC0 = 48,
        LWC1 = 49,
        LWC2 = 50,
        LWC3 = 51,
        SWC0 = 56,
        SWC1 = 57,
        SWC2 = 58,
        SWC3 = 59
    }
}
