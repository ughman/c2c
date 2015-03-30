#ifndef HH_EMU_HH
#define HH_EMU_HH

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

#undef EMUPTR
#define EMUPTR(x) emuptr<x>

#endif
