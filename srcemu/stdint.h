#ifndef __STDINT_H__
#define __STDINT_H__

// MSVC doesn't have this header
// So, I have to write it myself

typedef   signed  char       int8_t;
typedef unsigned  char      uint8_t;
typedef   signed short      int16_t;
typedef unsigned short     uint16_t;
typedef   signed   int      int32_t;
typedef unsigned   int     uint32_t;
typedef   signed long long  int64_t;
typedef unsigned long long uint64_t;

#endif
