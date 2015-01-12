using System;
using System.Collections.Generic;

namespace PSXDiscompile
{
    internal static class MainClass
    {
        private static Program p;

        private static void Main()
        {
            p = Program.LoadEXE(@"..\SCES_009.67");
            DefineSwitchTables();
            DefineFunctionPointers();
            DefineWeirdReturns();
            DefineBIOSStubs();
            DefineOther();
            DefineHacks();
            p.FlushMarks();
            DefineUnknown();
            p.Discompile();
            p.Disassemble(@"..\zz_dis.txt");
            p.DumpCodemap(@"..\zz_map.txt");
        }

        private static void DefineSwitchTables()
        {
            // Compiler-generated switch-case tables
            p[0x12048].DefineSwitchTable(0x10068,26);
            p[0x13354].DefineSwitchTable(0x10138,30);
            p[0x15298].DefineSwitchTable(0x101B0,59);
            p[0x16050].DefineSwitchTable(0x1029C,8);
            p[0x23F38].DefineSwitchTable(0x10438,11);
            p[0x26754].DefineSwitchTable(0x10468,6);
            p[0x270B0].DefineSwitchTable(0x10480,11);
            p[0x32114].DefineSwitchTable(0x10544,19);
            p[0x333A4].DefineSwitchTable(0x10590,15);
            p[0x34810].DefineSwitchTable(0x10668,5);
            p[0x34974].DefineSwitchTable(0x106DC,9);
            p[0x4761C].DefineSwitchTable(0x10B20,5);
            p[0x497AC].DefineSwitchTable(0x10C2C,45);
            p[0x516C0].DefineSwitchTable(0x110DC,8);
            p[0x51780].DefineSwitchTable(0x110FC,8);
            p[0x51C84].DefineSwitchTable(0x1111C,7);
            p[0x51D64].DefineSwitchTable(0x1113C,7);
            p[0x12740].DefineSwitchTable(0x10120,6);
            p[0x379D8].DefineSwitchTable(0x10838,15);
            p[0x369E8].DefineSwitchTable(0x10704,19);
            p[0x37C80].DefineSwitchTable(0x10878,10);
            p[0x37F08].DefineSwitchTable(0x108A0,22);
            p[0x1C154].DefineSwitchTable(0x102BC,7);
            p[0x1D05C].DefineSwitchTable(0x102D8,5);
            p[0x1FD24].DefineSwitchTable(0x102EC,37);
            p[0x2A510].DefineSwitchTable(0x104AC,38);
            p[0x340B0].DefineSwitchTable(0x105D0,38);
            p[0x384C8].DefineSwitchTable(0x108F8,8);
            p[0x38A00].DefineSwitchTable(0x10918,7);
            p[0x391F8].DefineSwitchTable(0x10938,6);
            p[0x56820].DefineSwitchTable(0x11198,6);

            // GOOL Opcode Jump Table
            p[0x3A328].DefineSwitchTable(0x5C7AC,79);
        }

        private static void DefineFunctionPointers()
        {
            List<Word> fs;

            // Subsystems Function 2
            fs = new List<Word>();
            fs.Add(p[0x16328]);
            fs.Add(p[0x299DC]);
            fs.Add(p[0x243FC]);
            fs.Add(p[0x2CDCC]);
            fs.Add(p[0x1F0AC]);
            fs.Add(p[0x327B4]);
            fs.Add(p[0x34034]);
            fs.Add(p[0x2FFDC]);
            fs.Add(p[0x27CAC]);
            p[0x14FC0].AddCalleeList(fs);

            // Subsystems Function 3
            fs = new List<Word>();
            fs.Add(p[0x1FC0C]);
            fs.Add(p[0x1F260]);
            p[0x152FC].AddCalleeList(fs);

            // Subsystems Function 4
            fs = new List<Word>();
            fs.Add(p[0x1747C]);
            fs.Add(p[0x172BC]);
            fs.Add(p[0x20024]);
            fs.Add(p[0x18AE8]);
            p[0x127F8].AddCalleeList(fs);
            p[0x12A50].AddCalleeList(fs);

            // Subsystems Function 5
            fs = new List<Word>();
            fs.Add(p[0x20178]);
            p[0x12C30].AddCalleeList(fs);

            // Subsystems Function 6
            fs = new List<Word>();
            fs.Add(p[0x1642C]);
            fs.Add(p[0x29A3C]);
            fs.Add(p[0x2CE28]);
            fs.Add(p[0x1F220]);
            fs.Add(p[0x32894]);
            fs.Add(p[0x346B8]);
            fs.Add(p[0x2FFF4]);
            fs.Add(p[0x27E10]);
            p[0x153D8].AddCalleeList(fs);

            // Argument
            fs = new List<Word>();
            fs.Add(p[0x376D8]);
            fs.Add(p[0x376E0]);
            fs.Add(p[0x37804]);
            fs.Add(p[0x38414]);
            fs.Add(p[0x38998]);
            fs.Add(p[0x38D94]);
            fs.Add(p[0x38EAC]);
            fs.Add(p[0x38FA0]);
            fs.Add(p[0x390AC]);
            fs.Add(p[0x39198]);
            fs.Add(p[0x39CAC]);
            fs.Add(p[0x39D3C]);
            fs.Add(p[0x39DAC]);
            fs.Add(p[0x39EA0]);
            p[0x3A264].AddCalleeList(fs);

            // Argument
            fs = new List<Word>();
            fs.Add(p[0x392A4]);
            fs.Add(p[0x3939C]);
            fs.Add(p[0x39470]);
            fs.Add(p[0x395A8]);
            fs.Add(p[0x3975C]);
            fs.Add(p[0x3991C]);
            p[0x3A28C].AddCalleeList(fs);

            // 8005CA64
            fs = new List<Word>();
            p[0x47B0C].AddCalleeList(fs);
            p[0x47D94].AddCalleeList(fs);
            p[0x48204].AddCalleeList(fs);

            // 8005CA68
            fs = new List<Word>();
            p[0x47AD8].AddCalleeList(fs);
            p[0x47D60].AddCalleeList(fs);
            p[0x481D0].AddCalleeList(fs);

            // 8005DFB0
            fs = new List<Word>();
            p[0x4B7C4].AddCalleeList(fs);
            p[0x4BF64].AddCalleeList(fs);
            p[0x4BFE8].AddCalleeList(fs);
            p[0x4C0F8].AddCalleeList(fs);
            p[0x4C160].AddCalleeList(fs);
            p[0x4C214].AddCalleeList(fs);
            p[0x4C280].AddCalleeList(fs);
            p[0x4C310].AddCalleeList(fs);
            p[0x4C42C].AddCalleeList(fs);
            p[0x4C454].AddCalleeList(fs);
            p[0x4C768].AddCalleeList(fs);
            p[0x4C824].AddCalleeList(fs);
            p[0x4C910].AddCalleeList(fs);
            p[0x4C994].AddCalleeList(fs);
            p[0x4CAA4].AddCalleeList(fs);
            p[0x4CBEC].AddCalleeList(fs);

            // 8005EAA0
            fs = new List<Word>();
            p[0x4FA60].AddCalleeList(fs);

            // 8005F278
            fs = new List<Word>();
            p[0x55134].AddCalleeList(fs);
            p[0x55184].AddCalleeList(fs);

            // 8005F27C
            fs = new List<Word>();
            p[0x55120].AddCalleeList(fs);

            // 8005F5D0
            fs = new List<Word>();
            p[0x4A60C].AddCalleeList(fs);

            // 800697F8
            fs = new List<Word>();
            p[0x574B4].AddCalleeList(fs);

            // 800699AC
            fs = new List<Word>();
            p[0x574E0].AddCalleeList(fs);
        }

        private static void DefineWeirdReturns()
        {
            p[0x3A978].IsWeirdReturn = true;
            p[0x3A98C].IsWeirdReturn = true;
            p[0x3A994].IsWeirdReturn = true;
            p[0x3AA34].IsWeirdReturn = true;
            p[0x3AA40].IsWeirdReturn = true;
            p[0x3AA48].IsWeirdReturn = true;
            p[0x3AAD4].IsWeirdReturn = true;
            p[0x3AB00].IsWeirdReturn = true;
        }

        private static void DefineBIOSStubs()
        {
            // Stubs for BIOS calls
            // BIOS addresses are too far away to use a direct call/jump
            p[0x49410].DirectBranch = 0xB0;
            p[0x49428].DirectBranch = 0xB0;
            p[0x49470].DirectBranch = 0xA0;
            p[0x49480].DirectBranch = 0xA0;
            p[0x49490].DirectBranch = 0xA0;
            p[0x494A0].DirectBranch = 0xA0;
            p[0x494C0].DirectBranch = 0xA0;
            p[0x494D0].DirectBranch = 0xA0;
            p[0x494E0].DirectBranch = 0xA0;
            p[0x49F48].DirectBranch = 0xA0;
            p[0x49F68].DirectBranch = 0xB0;
            p[0x49F78].DirectBranch = 0xB0;
            p[0x49F88].DirectBranch = 0xB0;
            p[0x49F98].DirectBranch = 0xB0;
            p[0x49FA8].DirectBranch = 0xB0;
            p[0x4A058].DirectBranch = 0xB0;
            p[0x4A500].DirectBranch = 0xB0;
            p[0x4A510].DirectBranch = 0xB0;
            p[0x4A520].DirectBranch = 0xB0;
            p[0x4A540].DirectBranch = 0xC0;
            p[0x4A550].DirectBranch = 0xC0;
            p[0x4A5F0].DirectBranch = 0xA0;
            p[0x4A904].DirectBranch = 0xC0;
            p[0x4EEB4].DirectBranch = 0xA0;
            p[0x51304].DirectBranch = 0xB0;
            p[0x5B384].DirectBranch = 0xB0;
            p[0x5B394].DirectBranch = 0xB0;
            p[0x5B3A4].DirectBranch = 0xB0;
            p[0x49450].DirectBranch = 0xA0;
            p[0x49460].DirectBranch = 0xA0;
            p[0x494B0].DirectBranch = 0xA0;
            p[0x49D4C].DirectBranch = 0xA0;
            p[0x49FD8].DirectBranch = 0xB0;
            p[0x49FE8].DirectBranch = 0xB0;
            p[0x49FF8].DirectBranch = 0xB0;
            p[0x4A008].DirectBranch = 0xB0;
            p[0x4A018].DirectBranch = 0xB0;
            p[0x4A028].DirectBranch = 0xB0;
            p[0x4A038].DirectBranch = 0xB0;
            p[0x4A048].DirectBranch = 0xB0;
            p[0x5B244].DirectBranch = 0xA0;
            p[0x5B254].DirectBranch = 0xA0;
            p[0x5B264].DirectBranch = 0xB0;
            p[0x5B274].DirectBranch = 0xB0;
            p[0x5B284].DirectBranch = 0xB0;
            p[0x49440].DirectBranch = 0xA0;
            p[0x49F58].DirectBranch = 0xB0;
            p[0x4A530].DirectBranch = 0xB0;
            p[0x4B024].DirectBranch = 0xA0;
            p[0x4B03C].DirectBranch = 0xA0;
            p[0x4B054].DirectBranch = 0xB0;
            p[0x4B064].DirectBranch = 0xB0;
            p[0x4B074].DirectBranch = 0xB0;
            p[0x5B3C4].DirectBranch = 0xB0;
            p[0x4F4A4].DirectBranch = 0xB0;
            p[0x4A6D0].DirectBranch = 0xB0;
            p[0x4A638].DirectBranch = 0xB0;
            p[0x4A598].DirectBranch = 0xB0;
        }

        private static void DefineOther()
        {
            // Strange -0 -n construct
            p[0x3B984].AddDestination(0x3B9A4); //  -0 words
            p[0x3B984].AddDestination(0x3B994); //  -4 words
            p[0x3B9F8].AddDestination(0x3BA3C); //  -0 words
            p[0x3B9F8].AddDestination(0x3BA14); // -10 words
            p[0x3BA94].AddDestination(0x3BAD8); //  -0 words
            p[0x3BA94].AddDestination(0x3BAB0); // -10 words
            p[0x3BC44].AddDestination(0x3BC74); //  -0 words
            p[0x3BC44].AddDestination(0x3BC64); //  -4 words
            p[0x3BC44].AddDestination(0x3BC54); //  -8 words
            p[0x3BCC8].AddDestination(0x3BD34); //  -0 words
            p[0x3BCC8].AddDestination(0x3BD0C); // -10 words
            p[0x3BCC8].AddDestination(0x3BCE4); // -20 words
            p[0x3BD8C].AddDestination(0x3BDF8); //  -0 words
            p[0x3BD8C].AddDestination(0x3BDD0); // -10 words
            p[0x3BD8C].AddDestination(0x3BDA8); // -20 words

            // *n skip construct
            p[0x3BB0C].AddDestination(0x3BB14); // 0*8 words
            p[0x3BB0C].AddDestination(0x3BB34); // 1*8 words
            p[0x3BB0C].AddDestination(0x3BB54); // 2*8 words
            p[0x3BB0C].AddDestination(0x3BB74); // 3*8 words
            p[0x3BB0C].AddDestination(0x3BB94); // 4*8 words
            p[0x3BB0C].AddDestination(0x3BBB4); // 5*8 words
            p[0x3BE24].AddDestination(0x3BE2C); // 0*8 words
            p[0x3BE24].AddDestination(0x3BE4C); // 1*8 words
            p[0x3BE24].AddDestination(0x3BE6C); // 2*8 words
            p[0x3BE24].AddDestination(0x3BE8C); // 3*8 words
            p[0x3BE24].AddDestination(0x3BEAC); // 4*8 words
            p[0x3BE24].AddDestination(0x3BECC); // 5*8 words
            // potential for -1*2 here for infinite loop or what
            p[0x3C3A4].AddDestination(0x3C3AC); // 0*2 words
            p[0x3C3A4].AddDestination(0x3C3B4); // 1*2 words
            p[0x3C3A4].AddDestination(0x3C3BC); // 2*2 words
            p[0x3C3A4].AddDestination(0x3C3C4); // 3*2 words
            p[0x3C3A4].AddDestination(0x3C3CC); // 4*2 words
            p[0x3C3A4].AddDestination(0x3C3D4); // 5*2 words
            p[0x3C3A4].AddDestination(0x3C3DC); // 6*2 words
            p[0x3C3F8].AddDestination(0x3C400); // 0*2 words
            p[0x3C3F8].AddDestination(0x3C408); // 1*2 words
            p[0x3C3F8].AddDestination(0x3C410); // 2*2 words
            p[0x3C3F8].AddDestination(0x3C418); // 3*2 words
            p[0x3C3F8].AddDestination(0x3C420); // 4*2 words
            p[0x3C3F8].AddDestination(0x3C428); // 5*2 words
            p[0x3C3F8].AddDestination(0x3C430); // 6*2 words
            p[0x3C3F8].AddDestination(0x3C438); // 7*2 words
            p[0x3C448].AddDestination(0x3C450); //  0*2 words
            p[0x3C448].AddDestination(0x3C458); //  1*2 words
            p[0x3C448].AddDestination(0x3C460); //  2*2 words
            p[0x3C448].AddDestination(0x3C468); //  3*2 words
            p[0x3C448].AddDestination(0x3C470); //  4*2 words
            p[0x3C448].AddDestination(0x3C478); //  5*2 words
            p[0x3C448].AddDestination(0x3C480); //  6*2 words
            p[0x3C448].AddDestination(0x3C488); //  7*2 words
            p[0x3C448].AddDestination(0x3C490); //  8*2 words
            p[0x3C448].AddDestination(0x3C498); //  9*2 words
            p[0x3C448].AddDestination(0x3C4A0); // 10*2 words
            p[0x3C448].AddDestination(0x3C4A8); // 11*2 words
            p[0x3C448].AddDestination(0x3C4B0); // 12*2 words
            p[0x3C448].AddDestination(0x3C4B8); // 13*2 words
            p[0x3C448].AddDestination(0x3C4C0); // 14*2 words
            p[0x3C448].AddDestination(0x3C4C8); // 15*2 words
            p[0x3C448].AddDestination(0x3C4D0); // 16*2 words
            p[0x3C448].AddDestination(0x3C4D8); // 17*2 words
            p[0x3C448].AddDestination(0x3C4E0); // 18*2 words
            p[0x3C448].AddDestination(0x3C4E8); // 19*2 words
            p[0x3C448].AddDestination(0x3C4F0); // 20*2 words
            p[0x3C448].AddDestination(0x3C4F8); // 21*2 words
            p[0x3C448].AddDestination(0x3C500); // 22*2 words
            p[0x3C448].AddDestination(0x3C508); // 23*2 words
            p[0x3C448].AddDestination(0x3C510); // 24*2 words
            p[0x3C448].AddDestination(0x3C518); // 25*2 words
            p[0x3C530].AddDestination(0x3C538); // 0*2 words
            p[0x3C530].AddDestination(0x3C540); // 1*2 words
            p[0x3C530].AddDestination(0x3C548); // 2*2 words
            p[0x3C530].AddDestination(0x3C550); // 3*2 words
            p[0x3C530].AddDestination(0x3C558); // 4*2 words
            p[0x3C530].AddDestination(0x3C560); // 5*2 words
            p[0x3C530].AddDestination(0x3C568); // 6*2 words
        }

        static void DefineUnknown()
        {
            p.MarkUnknown(0x18DD0);
            p.MarkUnknown(0x1C850);
            p.MarkUnknown(0x18F84);
            p.MarkUnknown(0x18FA4);
            p.MarkUnknown(0x1D014);
            p.MarkUnknown(0x2A4CC);
            p.MarkBranch(0x3E170);
            p.MarkUnknown(0x5519C);
            p.MarkUnknown(0x191B0);
            p.MarkUnknown(0x19E68);
            p.MarkUnknown(0x54498);
            p.MarkBranch(0x42D50);
            p.MarkUnknown(0x53408);
            p.MarkUnknown(0x53D10);
            p.MarkUnknown(0x5510C);
            p.MarkUnknown(0x53FE0);
            p.MarkBranch(0x4573C);
            p.MarkAnonymousJumpTable(0x5B8F0,0x5B924);
            p.MarkAnonymousJumpTable(0x5B930,0x5B99C);
            p.MarkAnonymousJumpTable(0x5B9A4,0x5B9AC);
            p.MarkAnonymousJumpTable(0x5B9B4,0x5BA00);
            p.MarkAnonymousJumpTable(0x5BA08,0x5BA44);
            p.MarkBranch(0x41FAC);
            p.MarkUnknown(0x54090);
            p.MarkUnknown(0x5456C);
            p.MarkUnknown(0x542C8);
            p.MarkUnknown(0x46BB4);
            p.MarkUnknown(0x48B90);
            p.MarkUnknown(0x4AAA8);
            p.MarkUnknown(0x4AD6C);
            p.MarkBranch(0x420E8);
            p.MarkBranch(0x42DDC);
            p.MarkBranch(0x42C34);
            p.MarkBranch(0x42EC4);
            p.MarkBranch(0x44138);
            p.MarkBranch(0x44C9C);
            p.MarkUnknown(0x4B1F8);
            p.MarkBranch(0x43FEC);
            p.MarkBranch(0x4401C);
            p.MarkBranch(0x44D08);
            p.MarkBranch(0x45158);
            p.MarkUnknown(0x48AAC);
            p.MarkUnknown(0x4B0D8);
            p.MarkBranch(0x42F08);
            p.MarkBranch(0x3E794);
            p.MarkBranch(0x44C18);
            p.MarkUnknown(0x4B37C);
            p.MarkBranch(0x42E14);
            p.MarkBranch(0x43C34);
            p.MarkUnknown(0x53830);
            p.MarkUnknown(0x4F9D0);
            p.MarkBranch(0x44C48);
            p.MarkUnknown(0x46C04);
            p.MarkBranch(0x43DF4);
            p.MarkBranch(0x43EE0);
            p.MarkBranch(0x43FCC);
            p.MarkBranch(0x43E0C);
            p.MarkBranch(0x43EC4);
            p.MarkBranch(0x4311C);
            p.MarkBranch(0x42930);
            p.MarkBranch(0x431A0);
            p.MarkUnknown(0x4A454);
            p.MarkUnknown(0x3C120);

            // JAN 05 2015 - Night Fight
            p.MarkBranch(0x44D38);
            p.MarkBranch(0x450E0);
            p.MarkBranch(0x44D40);
            p.MarkBranch(0x44D98);

            // JAN 07 2015 - Road To Ruin
            p.MarkBranch(0x43D1C);
            p.MarkUnknown(0x43C6C);

            // JAN 07 2015 - Ruination
            p.MarkBranch(0x45C34);
            p.MarkBranch(0x45C40);
            p.MarkBranch(0x45D4C);

            // JAN 07 2015 - Diggin' It
            p.MarkBranch(0x45EB0);
            p.MarkUnknown(0x46020);
            p.MarkBranch(0x461D8);

            // JAN 10 2015 - Table Discovered From Save Game Screen
            p.MarkAnonymousCallTable(0x5DF70,0x5DFA8);

            //p.MarkBranch(0x3BC64);
            /*p.MarkAnonymousJumpTable(0x5B8F0,0x5B924);
            p.MarkAnonymousJumpTable(0x5B930,0x5B99C);
            p.MarkAnonymousJumpTable(0x5B9A4,0x5B9AC);
            p.MarkAnonymousJumpTable(0x5B9B4,0x5BA00);
            p.MarkAnonymousJumpTable(0x5BA08,0x5BA44);
            p.MarkAnonymousJumpTable(0x5DEE4,0x5DEEC);

            p.FlushMarks();
            p.MarkUnknown(0x11E98);
            p.MarkUnknown(0x12100);
            p.MarkUnknown(0x1232C);
            p.MarkUnknown(0x14324);
            p.MarkUnknown(0x14D0C);
            p.MarkUnknown(0x14D4C);
            p.MarkUnknown(0x16328);
            p.MarkUnknown(0x1642C);
            p.MarkUnknown(0x16518);
            p.MarkUnknown(0x16538);
            p.MarkUnknown(0x16548);
            p.MarkUnknown(0x17020);
            p.MarkUnknown(0x172BC);
            p.MarkUnknown(0x172E4);
            p.MarkUnknown(0x1747C);
            p.MarkUnknown(0x18558);
            p.MarkUnknown(0x18AE8);
            p.MarkUnknown(0x18DD0);
            p.MarkUnknown(0x18F84);
            p.MarkUnknown(0x18FA4);
            p.MarkUnknown(0x191B0);
            p.MarkUnknown(0x19E68);
            p.MarkUnknown(0x1C850);
            p.MarkUnknown(0x1D014);
            p.MarkUnknown(0x1F0AC);
            p.MarkUnknown(0x1F220);
            p.MarkUnknown(0x1FC0C);
            p.MarkUnknown(0x20024);
            p.MarkUnknown(0x20178);
            p.MarkUnknown(0x243FC);
            p.MarkUnknown(0x27CAC);
            p.MarkUnknown(0x27E10);
            p.MarkUnknown(0x299B0);
            p.MarkUnknown(0x299DC);
            p.MarkUnknown(0x29A3C);
            p.MarkUnknown(0x2A4CC);
            p.MarkUnknown(0x2CE28);
            p.MarkUnknown(0x2E93C);
            p.MarkUnknown(0x2E9F4);
            p.MarkUnknown(0x2EB68);
            p.MarkUnknown(0x2FFDC);
            p.MarkUnknown(0x2FFF4);
            p.MarkUnknown(0x2FFFC);
            p.MarkUnknown(0x31780);
            p.MarkUnknown(0x31788);
            p.MarkUnknown(0x31964);
            p.MarkUnknown(0x32618);
            p.MarkUnknown(0x32620);
            p.MarkUnknown(0x32628);
            p.MarkUnknown(0x32630);
            p.MarkUnknown(0x32638);
            p.MarkUnknown(0x32640);
            p.MarkUnknown(0x32648);
            p.MarkUnknown(0x32650);
            p.MarkUnknown(0x32658);
            p.MarkUnknown(0x32660);
            p.MarkUnknown(0x32668);
            p.MarkUnknown(0x32670);
            p.MarkUnknown(0x32678);
            p.MarkUnknown(0x32680);
            p.MarkUnknown(0x32688);
            p.MarkUnknown(0x32690);
            p.MarkUnknown(0x32698);
            p.MarkUnknown(0x326A0);
            p.MarkUnknown(0x326A8);
            p.MarkUnknown(0x326B0);
            p.MarkUnknown(0x327A4);
            p.MarkUnknown(0x327B4);
            p.MarkUnknown(0x328E8);
            p.MarkUnknown(0x34034);
            p.MarkUnknown(0x34E0C);
            p.MarkUnknown(0x35DA8);
            p.MarkUnknown(0x35E80);
            p.MarkUnknown(0x362B4);
            p.MarkUnknown(0x36F90);
            p.MarkUnknown(0x376D8);
            p.MarkUnknown(0x376E0);
            p.MarkUnknown(0x37804);
            p.MarkUnknown(0x38414);
            p.MarkUnknown(0x38998);
            p.MarkUnknown(0x38D94);
            p.MarkUnknown(0x38EAC);
            p.MarkUnknown(0x38FA0);
            p.MarkUnknown(0x39198);
            p.MarkUnknown(0x392A4);
            p.MarkUnknown(0x3939C);
            p.MarkUnknown(0x39470);
            p.MarkUnknown(0x395A8);
            p.MarkUnknown(0x3975C);
            p.MarkUnknown(0x3991C);
            p.MarkUnknown(0x39CAC);
            p.MarkUnknown(0x39D3C);
            p.MarkUnknown(0x39DAC);
            p.MarkUnknown(0x39EA0);
            p.MarkUnknown(0x3C120);
            p.MarkUnknown(0x3C198);
            p.MarkUnknown(0x3E170);
            p.MarkUnknown(0x3E794);
            p.MarkUnknown(0x426B8);
            p.MarkUnknown(0x4573C);
            p.MarkUnknown(0x46BB4);
            p.MarkUnknown(0x46BDC);
            p.MarkUnknown(0x46C4C);
            p.MarkUnknown(0x46D10);
            p.MarkUnknown(0x46D44);
            p.MarkUnknown(0x47190);
            p.MarkUnknown(0x48B90);
            p.MarkUnknown(0x49170);
            p.MarkUnknown(0x49EDC);
            //p.MarkUnknown(0x49F54);
            p.MarkUnknown(0x4A100);
            p.MarkUnknown(0x4A1DC);
            p.MarkUnknown(0x4A1FC);
            p.MarkUnknown(0x4A454);
            p.MarkUnknown(0x4A4BC);
            //p.MarkUnknown(0x4A52C);
            p.MarkUnknown(0x4A5FC);
            p.MarkUnknown(0x4A9D4);
            p.MarkUnknown(0x4AA34);
            p.MarkUnknown(0x4AA74);
            p.MarkUnknown(0x4B0D8);
            p.MarkUnknown(0x4B478);
            p.MarkUnknown(0x4B564);
            p.MarkUnknown(0x4B5CC);
            p.MarkUnknown(0x4B77C);
            p.MarkUnknown(0x4B890);
            p.MarkUnknown(0x4B8CC);
            p.MarkUnknown(0x4B930);
            p.MarkUnknown(0x4B958);
            p.MarkUnknown(0x4B96C);
            p.MarkUnknown(0x4B9BC);
            p.MarkUnknown(0x4B9D0);
            p.MarkUnknown(0x4B9E4);
            p.MarkUnknown(0x4B9F8);
            p.MarkUnknown(0x4BA0C);
            p.MarkUnknown(0x4BA20);
            p.MarkUnknown(0x4BA34);
            p.MarkUnknown(0x4BA48);
            p.MarkUnknown(0x4BA5C);
            p.MarkUnknown(0x4BA70);
            p.MarkUnknown(0x4BA84);
            p.MarkUnknown(0x4BA98);
            p.MarkUnknown(0x4BFA0);
            p.MarkUnknown(0x4C118);
            p.MarkUnknown(0x4C1D4);
            p.MarkUnknown(0x4C1E4);
            p.MarkUnknown(0x4C470);
            p.MarkUnknown(0x4C504);
            p.MarkUnknown(0x4C72C);
            p.MarkUnknown(0x4C7E4);
            p.MarkUnknown(0x4CA54);
            p.MarkUnknown(0x4CB70);
            p.MarkUnknown(0x4D050);
            p.MarkUnknown(0x4D088);
            p.MarkUnknown(0x4D0B8);
            p.MarkUnknown(0x4D240);
            p.MarkUnknown(0x4F500);
            p.MarkUnknown(0x4F9D0);
            p.MarkUnknown(0x4FA8C);
            p.MarkUnknown(0x4FE38);
            p.MarkUnknown(0x4FF84);
            p.MarkUnknown(0x4FFC0);
            p.MarkUnknown(0x50330);
            p.MarkUnknown(0x519F0);
            p.MarkUnknown(0x52150);
            p.MarkUnknown(0x529AC);
            p.MarkUnknown(0x52B28);
            p.MarkUnknown(0x52DB0);
            p.MarkUnknown(0x53390);
            p.MarkUnknown(0x53408);
            p.MarkUnknown(0x53830);
            p.MarkUnknown(0x54B44);
            p.MarkUnknown(0x54B98);
            p.MarkUnknown(0x54CA4);
            p.MarkUnknown(0x550EC);
            p.MarkUnknown(0x5510C);
            p.MarkUnknown(0x5514C);
            p.MarkUnknown(0x56574);
            p.MarkUnknown(0x5690C);
            p.MarkUnknown(0x56A84);
            p.MarkUnknown(0x5817C);
            p.MarkUnknown(0x59E40);
            p.MarkUnknown(0x59E88);
            p.MarkUnknown(0x5AB04);
            p.MarkUnknown(0x5AB34);
            p.MarkUnknown(0x1F260);
            p.MarkUnknown(0x390AC);
            p.MarkUnknown(0x41FAC);
            p.MarkUnknown(0x42D50);
            /*p.MarkUnknown(0x80043C34);
            p.MarkUnknown(0x800444D0);
            p.MarkUnknown(0x80044C18);
            p.MarkUnknown(0x80046C04);
            p.MarkUnknown(0x80048A9C);
            p.MarkUnknown(0x80048E60);
            p.MarkUnknown(0x);
            p.MarkUnknown(0x);
            p.MarkUnknown(0x);
            p.MarkUnknown(0x);
            p.MarkUnknown(0x);
            p.MarkUnknown(0x);
            p.MarkUnknown(0x);
            p.MarkUnknown(0x);
            p.MarkUnknown(0x);
            p.MarkUnknown(0x);
            p.MarkUnknown(0x);
            p.MarkUnknown(0x);
            p.MarkUnknown(0x);
            p.MarkUnknown(0x);
            p.MarkUnknown(0x);*/
        }

        public static void DefineHacks()
        {
            p[0x430A0].HackString = "GTE_GetDataRegister(9);";
            p[0x3AD6C].HackMustInvalidateICache = true;
        }
    }
}
