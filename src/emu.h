#ifndef H_EMU_H
#define H_EMU_H

#include <stdlib.h>
#include <stdint.h>

typedef uint8_t unk8_t;
typedef uint16_t unk16_t;
typedef uint32_t unk32_t;

#ifdef __cplusplus
extern "C" {
#endif

#define EMU_REG_R0 0
#define EMU_REG_AT 1
#define EMU_REG_V0 2
#define EMU_REG_V1 3
#define EMU_REG_A0 4
#define EMU_REG_A1 5
#define EMU_REG_A2 6
#define EMU_REG_A3 7
#define EMU_REG_T0 8
#define EMU_REG_T1 9
#define EMU_REG_T2 10
#define EMU_REG_T3 11
#define EMU_REG_T4 12
#define EMU_REG_T5 13
#define EMU_REG_T6 14
#define EMU_REG_T7 15
#define EMU_REG_S0 16
#define EMU_REG_S1 17
#define EMU_REG_S2 18
#define EMU_REG_S3 19
#define EMU_REG_S4 20
#define EMU_REG_S5 21
#define EMU_REG_S6 22
#define EMU_REG_S7 23
#define EMU_REG_T8 24
#define EMU_REG_T9 25
#define EMU_REG_K0 26
#define EMU_REG_K1 27
#define EMU_REG_GP 28
#define EMU_REG_SP 29
#define EMU_REG_FP 30
#define EMU_REG_RA 31
#define EMU_REG_LO 32
#define EMU_REG_HI 33

#define R0 ((uint32_t)0)
#define AT (EMU_reg[EMU_REG_AT])
#define V0 (EMU_reg[EMU_REG_V0])
#define V1 (EMU_reg[EMU_REG_V1])
#define A0 (EMU_reg[EMU_REG_A0])
#define A1 (EMU_reg[EMU_REG_A1])
#define A2 (EMU_reg[EMU_REG_A2])
#define A3 (EMU_reg[EMU_REG_A3])
#define T0 (EMU_reg[EMU_REG_T0])
#define T1 (EMU_reg[EMU_REG_T1])
#define T2 (EMU_reg[EMU_REG_T2])
#define T3 (EMU_reg[EMU_REG_T3])
#define T4 (EMU_reg[EMU_REG_T4])
#define T5 (EMU_reg[EMU_REG_T5])
#define T6 (EMU_reg[EMU_REG_T6])
#define T7 (EMU_reg[EMU_REG_T7])
#define S0 (EMU_reg[EMU_REG_S0])
#define S1 (EMU_reg[EMU_REG_S1])
#define S2 (EMU_reg[EMU_REG_S2])
#define S3 (EMU_reg[EMU_REG_S3])
#define S4 (EMU_reg[EMU_REG_S4])
#define S5 (EMU_reg[EMU_REG_S5])
#define S6 (EMU_reg[EMU_REG_S6])
#define S7 (EMU_reg[EMU_REG_S7])
#define T8 (EMU_reg[EMU_REG_T8])
#define T9 (EMU_reg[EMU_REG_T9])
#define K0 (EMU_reg[EMU_REG_K0])
#define K1 (EMU_reg[EMU_REG_K1])
#define GP (EMU_reg[EMU_REG_GP])
#define SP (EMU_reg[EMU_REG_SP])
#define FP (EMU_reg[EMU_REG_FP])
#define RA (EMU_reg[EMU_REG_RA])
#define LO (EMU_reg[EMU_REG_LO])
#define HI (EMU_reg[EMU_REG_HI])

#define EMU_RAMWORDS 524288
#define EMU_SCRATCHWORDS 256

extern uint32_t *EMU_reg;
extern uint32_t *EMU_ram;
extern uint32_t *EMU_scratch;

extern uint32_t (*EMU_codemap[EMU_RAMWORDS])(uint32_t address);

extern void EMU_Init(void);

extern uint32_t EMU_ExecuteUnrecognizedCode(uint32_t address);
extern uint32_t EMU_ExecuteBadEntryPointCode(uint32_t address);

extern int8_t EMU_ReadS8(uint32_t address);
extern int16_t EMU_ReadS16(uint32_t address);

extern uint8_t EMU_ReadU8(uint32_t address);
extern uint16_t EMU_ReadU16(uint32_t address);
extern uint32_t EMU_ReadU32(uint32_t address);

extern void EMU_Write8(uint32_t address,uint8_t value);
extern void EMU_Write16(uint32_t address,uint16_t value);
extern void EMU_Write32(uint32_t address,uint32_t value);

extern void EMU_ReadLeft(uint32_t address,uint32_t *valueref);
extern void EMU_ReadRight(uint32_t address,uint32_t *valueref);
extern void EMU_WriteLeft(uint32_t address,uint32_t value);
extern void EMU_WriteRight(uint32_t address,uint32_t value);

extern void *EMU_Pointer(uint32_t address);

extern void EMU_SMultiply(int32_t a,int32_t b);
extern void EMU_UMultiply(uint32_t a,uint32_t b);
extern void EMU_SDivide(int32_t a,int32_t b);
extern void EMU_UDivide(uint32_t a,uint32_t b);

#define EMU_CheckedAdd(a,b) ((a) + (b))
#define EMU_CheckedSubtract(a,b) ((a) - (b))

extern uint32_t EMU_Invoke(uint32_t address,int argc,...);
extern void EMU_Syscall(uint32_t pc);
extern void EMU_Break(uint32_t id);

extern void EMU_NativeCall(void *method);

extern void EMU_Cycle(int cycles);
extern void EMU_RunInterrupts(void);

#ifdef __cplusplus
}

#include <type_traits>

template <typename T> static inline T *EMU_TPointer(uint32_t address)
{
	return (T *)EMU_Pointer(address);
}

template <typename T>
class emuptr
{
	// This type represents an emulated pointer to an arbitrary type.
	// Imagine `emuptr<foo_t>' as `foo_t *' but as a pointer in the
	// emulated system, rather than the host system. This also works
	// with const, i.e. `emuptr<const bar_t>' is like `const bar_t *'.
	//
	// This type is also interchangable with uint32_t at the ABI level
	// and so can be used with EMU_Invoke() and EMU_NativeCall(). To
	// facilitate this ABI compatibility, it is crucial that this type
	// is a "trivial" type according to C++11 standards.
	//
	// A macro EMUPTR(x) exists, defined as emuptr<x> for C++ source
	// files and as uint32_t for C source files.

	friend class emuptr<typename std::add_const<T>::type>;
private:
	uint32_t address;
public:
	emuptr() = default;

	explicit emuptr(uint32_t address)
	{
		this->address = address;
	}

	template <typename TT = T> // SFINAE
	emuptr(const emuptr<typename std::remove_const<T>::type> &other)
	{
		// This allows emuptr<const T> to be assigned from emuptr<T>
		this->address = other.address;
	}

	explicit operator uint32_t()
	{
		return address;
	}

	operator T *() const
	{
		return EMU_TPointer<T>(address);
	}

	T &operator *() const
	{
		return *(T *)*this;
	}

	T *operator ->() const
	{
		return (T *)*this;
	}

	T &operator [](ptrdiff_t i) const
	{
		return *(*this + i);
	}

	emuptr operator +(ptrdiff_t i) const
	{
		return emuptr(address + i * sizeof(T));
	}

	emuptr operator -(ptrdiff_t i) const
	{
		return emuptr(address - i * sizeof(T));
	}

	emuptr &operator +=(ptrdiff_t i)
	{
		address += i * sizeof(T);
		return *this;
	}

	emuptr &operator -=(ptrdiff_t i)
	{
		address -= i * sizeof(T);
		return *this;
	}

	emuptr &operator++()
	{
		address += sizeof(T);
		return *this;
	}

	emuptr &operator--()
	{
		address -= sizeof(T);
		return *this;
	}

	emuptr operator++(int)
	{
		emuptr result = *this;
		address += sizeof(T);
		return result;
	}

	emuptr operator--(int)
	{
		emuptr result = *this;
		address -= sizeof(T);
		return result;
	}
};

static_assert(std::is_trivial<emuptr<int>>::value,"emuptr<T> must be a trivial type for ABI compatibility with uint32_t!");
static_assert(std::is_trivial<emuptr<const int>>::value,"emuptr<const T> must be a trivial type for ABI compatibility with uint32_t!");

#define EMUPTR(x) emuptr<x>
#else
#define EMUPTR(x) uint32_t
#endif

#endif
