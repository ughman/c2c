#include "system.h"
#include "r3000a.h"
#include "gte.h"
#include <stdio.h>
#include <stdarg.h>
#include <windows.h>

static HWND hwnd = NULL;

static LRESULT CALLBACK MainWndProc(HWND hwnd,UINT uMsg,WPARAM wParam,LPARAM lParam)
{
	PAINTSTRUCT ps;
	switch (uMsg)
	{
	case WM_PAINT:
		BeginPaint(hwnd,&ps);
		EndPaint(hwnd,&ps);
		return TRUE;
	default:
		return DefWindowProcA(hwnd,uMsg,wParam,lParam);
	}
}

static void CreateMainWindow() {
	WNDCLASS wc;

	wc.lpszClassName = "PCSXR Main";
	wc.lpfnWndProc = MainWndProc;
	wc.style = 0;
	wc.hInstance = GetModuleHandle(NULL);
	wc.hIcon = NULL;
	wc.hCursor = NULL;
	wc.hbrBackground = (HBRUSH)(COLOR_MENUTEXT);
	wc.lpszMenuName = 0;
	wc.cbClsExtra = 0;
	wc.cbWndExtra = 0;

	RegisterClass(&wc);

	hwnd = CreateWindow("PCSXR Main",
						"PCSXR",
						WS_OVERLAPPEDWINDOW | WS_CLIPSIBLINGS | WS_CLIPCHILDREN,
						CW_USEDEFAULT,
						0,
						356,
						252,
						NULL,
						NULL,
						GetModuleHandle(NULL),
						NULL);

	/*if(Config.SaveWindowPos)
		SetWindowPos(hwnd, 0, Config.WindowPos[0], Config.WindowPos[1], 0, 0, SWP_NOSIZE | SWP_NOZORDER);*/

	ShowWindow(hwnd, SW_SHOW);
}

static int OpenPlugins() {
	int ret;

	if (!hwnd)
		CreateMainWindow();

	CDR_configure();
	GPU_configure();
	SPU_configure();
	PAD1_configure();
	PAD2_configure();

	ret = CDR_open();
	if (ret < 0) { SysMessage (_("Error Opening CDR Plugin")); return -1; }
	ret = GPU_open(hwnd);
	if (ret < 0) { SysMessage (_("Error Opening GPU Plugin (%d)"), ret); return -1; }
	ret = SPU_open(hwnd);
	if (ret < 0) { SysMessage (_("Error Opening SPU Plugin (%d)"), ret); return -1; }
	SPU_registerCallback(SPUirq);
	ret = PAD1_open(hwnd);
	if (ret < 0) { SysMessage (_("Error Opening PAD1 Plugin (%d)"), ret); return -1; }
	ret = PAD2_open(hwnd);
	if (ret < 0) { SysMessage (_("Error Opening PAD2 Plugin (%d)"), ret); return -1; }
	return 0;
}

void SysReset()
{
}

void SysClose()
{
}

void SysRunGui()
{
}

void ClosePlugins()
{
}

void SysPrintf(const char *fmt, ...)
{
	va_list args;
	va_start(args,fmt);
	vprintf(fmt,args);
	va_end(args);
	fflush(stdout);
}

void SysMessage(const char *fmt, ...)
{
	char message[2048];
	va_list args;
	va_start(args,fmt);
	vsnprintf(message,sizeof(message),fmt,args);
	va_end(args);
	MessageBoxA(NULL,message,"CBCLR Error",MB_ICONERROR | MB_OK);
}

void *SysLoadLibrary(const char *lib)
{
	return LoadLibraryA(lib);
}

static FARPROC lastproc;

void *SysLoadSym(void *lib, const char *sym)
{
	return lastproc = GetProcAddress((HMODULE)lib,sym);
}

const char *SysLibError()
{
	return lastproc ? NULL : "Error";
}

void SysCloseLibrary(void *lib)
{
	FreeLibrary((HMODULE)lib);
}

void SysUpdate()
{
	MSG msg;
	while (PeekMessageA(&msg,NULL,0,0,TRUE))
	{
		TranslateMessage(&msg);
		DispatchMessageA(&msg);
	}
}

#define DLLEXPORT(returntype) returntype __declspec(dllexport)

struct nativeinfo native;

DLLEXPORT(void) pcsxInit(const char *filename,void **regbase,struct nativeinfo *newnative)
{
	native = *newnative;
	*regbase = &psxRegs.GPR;
	SetIsoFile(filename);
	if (EmuInit() == -1)
		abort();
	if (LoadPlugins() == -1)
		abort();
	if (OpenPlugins() == -1)
		abort();
	if (CheckCdrom() == -1)
		abort();
	EmuReset();
	if (LoadCdrom() == -1)
		abort();
	LoadMcd(1,"memcard1");
	*native.ram = psxM;
	*native.scratchpad = psxH;
}

DLLEXPORT(int) pcsxReadGPR(int reg)
{
	return psxRegs.GPR.r[reg];
}

DLLEXPORT(void) pcsxWriteGPR(int reg,int value)
{
	psxRegs.GPR.r[reg] = value;
}

DLLEXPORT(int) pcsxReadHI()
{
	return psxRegs.GPR.n.hi;
}

DLLEXPORT(void) pcsxWriteHI(int value)
{
	psxRegs.GPR.n.hi = value;
}

DLLEXPORT(int) pcsxReadLO()
{
	return psxRegs.GPR.n.lo;
}

DLLEXPORT(void) pcsxWriteLO(int value)
{
	psxRegs.GPR.n.lo = value;
}

DLLEXPORT(int) pcsxReadPC()
{
	return psxRegs.pc;
}

DLLEXPORT(void) pcsxWritePC(int value)
{
	psxRegs.pc = value;
}

DLLEXPORT(char) pcsxReadMemory8(int address)
{
	return psxMemRead8(address);
}

DLLEXPORT(void) pcsxWriteMemory8(int address,char value)
{
	psxMemWrite8(address,value);
}

DLLEXPORT(short) pcsxReadMemory16(int address)
{
	return psxMemRead16(address);
}

DLLEXPORT(void) pcsxWriteMemory16(int address,short value)
{
	psxMemWrite16(address,value);
}

DLLEXPORT(int) pcsxReadMemory32(int address)
{
	return psxMemRead32(address);
}

DLLEXPORT(void) pcsxWriteMemory32(int address,int value)
{
	psxMemWrite32(address,value);
}

////
// from psxinterpreter.c
static void psxTestSWInts() {
	// the next code is untested, if u know please
	// tell me if it works ok or not (linuzappz)
	if (psxRegs.CP0.n.Cause & psxRegs.CP0.n.Status & 0x0300 &&
		psxRegs.CP0.n.Status & 0x1) {
		psxException(psxRegs.CP0.n.Cause, 0);
	}
}

static void MTC0(int reg, u32 val) {
//	SysPrintf("MTC0 %d: %x\n", reg, val);
	switch (reg) {
		case 12: // Status
			psxRegs.CP0.r[12] = val;
			psxTestSWInts();
			break;

		case 13: // Cause
			psxRegs.CP0.n.Cause = val & ~(0xfc00);
			psxTestSWInts();
			break;

		default:
			psxRegs.CP0.r[reg] = val;
			break;
	}
}

static void (*psxCP2[64])() = {
	   NULL , gteRTPS ,    NULL ,    NULL,    NULL,    NULL , gteNCLIP,    NULL, // 00
	   NULL ,    NULL ,    NULL ,    NULL, gteOP  ,    NULL ,    NULL ,    NULL, // 08
	gteDPCS , gteINTPL, gteMVMVA, gteNCDS, gteCDP ,    NULL , gteNCDT ,    NULL, // 10
	   NULL ,    NULL ,    NULL , gteNCCS, gteCC  ,    NULL , gteNCS  ,    NULL, // 18
	gteNCT  ,    NULL ,    NULL ,    NULL,    NULL,    NULL ,    NULL ,    NULL, // 20
	gteSQR  , gteDCPL , gteDPCT ,    NULL,    NULL, gteAVSZ3, gteAVSZ4,    NULL, // 28
	gteRTPT ,    NULL ,    NULL ,    NULL,    NULL,    NULL ,    NULL ,    NULL, // 30
	   NULL ,    NULL ,    NULL ,    NULL,    NULL, gteGPF  , gteGPL  , gteNCCT  // 38
};
////

DLLEXPORT(int) pcsxReadCOPData(int copid,int copregister)
{
	if (copid == 0)
		return psxRegs.CP0.r[copregister];
	else if (copid == 2)
		return MFC2(copregister);
	else
		abort();
	return 0;
}

DLLEXPORT(void) pcsxWriteCOPData(int copid,int copregister,int value)
{
	if (copid == 0)
		MTC0(copregister,value);
	else if (copid == 2)
		MTC2(value,copregister);
	else
		abort();
}

DLLEXPORT(int) pcsxReadCOPControl(int copid,int copregister)
{
	if (copid == 0)
		return psxRegs.CP0.r[copregister];
	else if (copid == 2)
		return psxRegs.CP2C.p[copregister].d;
	else
		abort();
	return 0;
}

DLLEXPORT(void) pcsxWriteCOPControl(int copid,int copregister,int value)
{
	if (copid == 0)
		MTC0(copregister,value);
	else if (copid == 2)
		CTC2(value,copregister);
	else
		abort();
}

DLLEXPORT(void) pcsxExecuteCOP(int copid,int copargs)
{
	psxRegs.code = 16 << 26 | copid << 24 | copargs;
	if (copid == 0)
	{
		if (_Rs_ == 16)
		{
			psxRegs.CP0.n.Status = (psxRegs.CP0.n.Status & 0xfffffff0) |
				((psxRegs.CP0.n.Status & 0x3c) >> 2);
		}
	}
	else if (copid == 2)
		psxCP2[_Funct_]();
	else
		abort();
}

typedef const char *pcsxdisstring_t;
DLLEXPORT(pcsxdisstring_t) pcsxDisassemble(int pc)
{
	return disR3000AF(psxMemRead32(pc),pc);
}

DLLEXPORT(void) pcsxSyscall(int pc)
{
	psxRegs.CP0.n.EPC = pc;
	psxRegs.CP0.n.Status = (psxRegs.CP0.n.Status &~0x3f) |
		((psxRegs.CP0.n.Status & 0xf) << 2);
	if (psxRegs.GPR.n.a0 == 1)
		psxRegs.CP0.n.Status &= ~0x404;
	else if (psxRegs.GPR.n.a0 == 2)
		psxRegs.CP0.n.Status |= 0x404;
	else
		abort();
	psxRegs.CP0.n.Status = (psxRegs.CP0.n.Status & 0xfffffff0) |
		((psxRegs.CP0.n.Status & 0x3c) >> 2);
}

DLLEXPORT(void) pcsxCycle(int clocks)
{
	psxRegs.cycle += clocks * BIAS;
}

DLLEXPORT(int) pcsxRunInterrupts(int pc)
{
	psxRegs.pc = pc;
	psxBranchTest();
	return psxRegs.pc;
}

typedef const char *biosname_t;

DLLEXPORT(biosname_t) pcsxA0Name(unsigned int id)
{
	const char *name;
	char *result;
	if (id >= sizeof(biosA0n) / sizeof(*biosA0n))
		abort();
	name = biosA0n[id];
	result = (char *)CoTaskMemAlloc(strlen(name) + 1);
	strcpy(result,name);
	return result;
}

DLLEXPORT(biosname_t) pcsxB0Name(unsigned int id)
{
	const char *name;
	char *result;
	if (id >= sizeof(biosB0n) / sizeof(*biosB0n))
		abort();
	name = biosB0n[id];
	result = (char *)CoTaskMemAlloc(strlen(name) + 1);
	strcpy(result,name);
	return result;
}

DLLEXPORT(biosname_t) pcsxC0Name(unsigned int id)
{
	const char *name;
	char *result;
	if (id >= sizeof(biosC0n) / sizeof(*biosC0n))
		abort();
	name = biosC0n[id];
	result = (char *)CoTaskMemAlloc(strlen(name) + 1);
	strcpy(result,name);
	return result;
}

extern void hleA0();
extern void hleB0();
extern void hleC0();

DLLEXPORT(int) pcsxHLEA0(void)
{
	hleA0();
	return psxRegs.pc;
}

DLLEXPORT(int) pcsxHLEB0(void)
{
	hleB0();
	return psxRegs.pc;
}

DLLEXPORT(int) pcsxHLEC0(void)
{
	hleC0();
	return psxRegs.pc;
}

DLLEXPORT(int) pcsxGetBaseMemoryAddress()
{
	return (int)psxM;
}

int zz_readbp = 0;
int zz_writebp = 0;
int zz_execbp = 0;

DLLEXPORT(void) pcsxSetReadBP(int address)
{
	zz_readbp = address;
}

DLLEXPORT(void) pcsxSetWriteBP(int address)
{
	zz_writebp = address;
}

DLLEXPORT(void) pcsxSetExecBP(int address)
{
	zz_execbp = address;
}
