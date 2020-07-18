#pragma once
/*

   This file contains definitions used by the Hex-Rays decompiler output.
   It has type definitions and convenience macros to make the
   output more readable.

   Copyright (c) 2007 Hex-Rays

*/

#if defined(__GNUC__)
  typedef          long long ll;
  typedef unsigned long long ull;
  #define MAKELL(num) num ## LL
  #define FMT_64 "ll"
#elif defined(_MSC_VER)
  typedef          int64_t ll;
  typedef uint64_t ull;
  #define MAKELL(num) num ## i64
  #define FMT_64 "I64"
#elif defined (__BORLANDC__)
  typedef          int64_t ll;
  typedef uint64_t ull;
  #define MAKELL(num) num ## i64
  #define FMT_64 "L"
#else
  #error "unknown compiler"
#endif
typedef unsigned int uint;
typedef unsigned char uchar;
typedef unsigned short ushort;
//typedef unsigned long ulong;

// Partially defined types:
#define _BYTE  uint8_t
#define _WORD  uint16_t
#define _DWORD uint32_t
#define _QWORD uint64_t

#ifndef _WINDOWS_
#endif
typedef int64_t x_QWORD;
#ifndef __cplusplus
typedef int bool;       // we want to use bool in our C programs
#endif

// Some convenience macros to make partial accesses nicer
// first unsigned macros:
#define LOBYTE(x)   (*((_BYTE*)&(x)))   // low byte
#define LOWORD(x)   (*((_WORD*)&(x)))   // low word
#define LODWORD(x)  (*((_DWORD*)&(x)))  // low dword
#define HIBYTE(x)   (*((_BYTE*)&(x)+1))
#define HIWORD(x)   (*((_WORD*)&(x)+1))
#define HIDWORD(x)  (*((_DWORD*)&(x)+1))
#define BYTEn(x, n)   (*((_BYTE*)&(x)+n))
#define WORDn(x, n)   (*((_WORD*)&(x)+n))
#define BYTE1(x)   BYTEn(x,  1)         // byte 1 (counting from 0)
#define BYTE2(x)   BYTEn(x,  2)
#define BYTE3(x)   BYTEn(x,  3)
#define BYTE4(x)   BYTEn(x,  4)
#define BYTE5(x)   BYTEn(x,  5)
#define BYTE6(x)   BYTEn(x,  6)
#define BYTE7(x)   BYTEn(x,  7)
#define BYTE8(x)   BYTEn(x,  8)
#define BYTE9(x)   BYTEn(x,  9)
#define BYTE10(x)  BYTEn(x, 10)
#define BYTE11(x)  BYTEn(x, 11)
#define BYTE12(x)  BYTEn(x, 12)
#define BYTE13(x)  BYTEn(x, 13)
#define BYTE14(x)  BYTEn(x, 14)
#define BYTE15(x)  BYTEn(x, 15)
#define WORD1(x)   WORDn(x,  1)
#define WORD2(x)   WORDn(x,  2)         // third word of the object, unsigned
#define WORD3(x)   WORDn(x,  3)
#define WORD4(x)   WORDn(x,  4)
#define WORD5(x)   WORDn(x,  5)
#define WORD6(x)   WORDn(x,  6)
#define WORD7(x)   WORDn(x,  7)

// now signed macros (the same but with sign extension)
#define SLOBYTE(x)   (*((int8_t*)&(x)))
#define SLOWORD(x)   (*((int16_t*)&(x)))
#define SLODWORD(x)  (*((int32_t*)&(x)))
#define SHIBYTE(x)   (*((int8_t*)&(x)+1))
#define SHIWORD(x)   (*((int16_t*)&(x)+1))
#define SHIDWORD(x)  (*((int32_t*)&(x)+1))
#define SBYTEn(x, n)   (*((int8_t*)&(x)+n))
#define SWORDn(x, n)   (*((int16_t*)&(x)+n))
#define SBYTE1(x)   SBYTEn(x,  1)
#define SBYTE2(x)   SBYTEn(x,  2)
#define SBYTE3(x)   SBYTEn(x,  3)
#define SBYTE4(x)   SBYTEn(x,  4)
#define SBYTE5(x)   SBYTEn(x,  5)
#define SBYTE6(x)   SBYTEn(x,  6)
#define SBYTE7(x)   SBYTEn(x,  7)
#define SBYTE8(x)   SBYTEn(x,  8)
#define SBYTE9(x)   SBYTEn(x,  9)
#define SBYTE10(x)  SBYTEn(x, 10)
#define SBYTE11(x)  SBYTEn(x, 11)
#define SBYTE12(x)  SBYTEn(x, 12)
#define SBYTE13(x)  SBYTEn(x, 13)
#define SBYTE14(x)  SBYTEn(x, 14)
#define SBYTE15(x)  SBYTEn(x, 15)
#define SWORD1(x)   SWORDn(x,  1)
#define SWORD2(x)   SWORDn(x,  2)
#define SWORD3(x)   SWORDn(x,  3)
#define SWORD4(x)   SWORDn(x,  4)
#define SWORD5(x)   SWORDn(x,  5)
#define SWORD6(x)   SWORDn(x,  6)
#define SWORD7(x)   SWORDn(x,  7)


// Helper functions to represent some assembly instructions.

#ifdef __cplusplus

// Fill memory block with an integer value
inline void memset32(void *ptr, uint32_t value, int count)
{
	memset(ptr,value,count);
}

// Generate a reference to pair of operands
template<class T>  int16_t __PAIR__( int8_t  high, T low) { return ((( int16_t)high) << sizeof(high)*8) | uint8_t(low); }
template<class T>  int32_t __PAIR__( int16_t high, T low) { return ((( int32_t)high) << sizeof(high)*8) | uint16_t(low); }
template<class T>  int64_t __PAIR__( int32_t high, T low) { return ((( int64_t)high) << sizeof(high)*8) | uint32_t(low); }
template<class T> uint16_t __PAIR__(uint8_t  high, T low) { return (((uint16_t)high) << sizeof(high)*8) | uint8_t(low); }
template<class T> uint32_t __PAIR__(uint16_t high, T low) { return (((uint32_t)high) << sizeof(high)*8) | uint16_t(low); }
template<class T> uint64_t __PAIR__(uint32_t high, T low) { return (((uint64_t)high) << sizeof(high)*8) | uint32_t(low); }

// rotate left
template<class T> T __ROL__(T value, int count)
{
	const uint nbits = sizeof(T) * 8;

	if (count > 0)
	{
		count %= nbits;
		T high = value >> (nbits - count);
		if (T(-1) < 0) // signed value
			high &= ~((T(-1) << count));
		value <<= count;
		value |= high;
	}
	else
	{
		count = -count % nbits;
		T low = value << (nbits - count);
		value >>= count;
		value |= low;
	}
	return value;
}

// rotate right
template<class T> T __ROR__(T value, int count)
{
	return __ROL__(value, -count);
}
/*
template<class T> T __ROR__(T value, uint count)
{
  const uint nbits = sizeof(T) * 8;
  count %= nbits;

  T low = value << (nbits - count);
  value >>= count;
  value |= low;
  return value;
}*/

inline uint8_t  __ROL1__(uint8_t  value, int count) { return __ROL__((uint8_t)value, count); }
inline uint16_t __ROL2__(uint16_t value, int count) { return __ROL__((uint16_t)value, count); }
inline uint32_t __ROL4__(uint32_t value, int count) { return __ROL__((uint32_t)value, count); }
inline uint64_t __ROL8__(uint64_t value, int count) { return __ROL__((uint64_t)value, count); }
inline uint8_t __ROR1__(uint8_t  value, int count) { return __ROL__((uint8_t)value, -count); }
inline uint16_t __ROR2__(uint16_t value, int count) { return __ROL__((uint16_t)value, -count); }
inline uint32_t __ROR4__(uint32_t value, int count) { return __ROL__((uint32_t)value, -count); }
inline uint64_t __ROR8__(uint64_t value, int count) { return __ROL__((uint64_t)value, -count); }

// carry flag of left shift
template<class T> int8_t __MKCSHL__(T value, uint count)
{
  const uint nbits = sizeof(T) * 8;
  count %= nbits;

  return (value >> (nbits-count)) & 1;
}

// sign flag
template<class T> int8_t __SETS__(T x)
{
  if ( sizeof(T) == 1 )
    return int8_t(x) < 0;
  if ( sizeof(T) == 2 )
    return int16_t(x) < 0;
  if ( sizeof(T) == 4 )
    return int32_t(x) < 0;
  return int64_t(x) < 0;
}

// overflow flag of subtraction (x-y)
template<class T, class U> int8_t __OFSUB__(T x, U y)
{
  if ( sizeof(T) < sizeof(U) )
  {
    U x2 = x;
    int8_t sx = __SETS__(x2);
    return (sx ^ __SETS__(y)) & (sx ^ __SETS__(x2-y));
  }
  else
  {
    T y2 = y;
    int8_t sx = __SETS__(x);
    return (sx ^ __SETS__(y2)) & (sx ^ __SETS__(x-y2));
  }
}

// overflow flag of addition (x+y)
template<class T, class U> int8_t __OFADD__(T x, U y)
{
  if ( sizeof(T) < sizeof(U) )
  {
    U x2 = x;
    int8_t sx = __SETS__(x2);
    return ((1 ^ sx) ^ __SETS__(y)) & (sx ^ __SETS__(x2+y));
  }
  else
  {
    T y2 = y;
    int8_t sx = __SETS__(x);
    return ((1 ^ sx) ^ __SETS__(y2)) & (sx ^ __SETS__(x+y2));
  }
}

// carry flag of subtraction (x-y)
template<class T, class U> int8_t __CFSUB__(T x, U y)
{
  int size = sizeof(T) > sizeof(U) ? sizeof(T) : sizeof(U);
  if ( size == 1 )
    return uint8_t(x) < uint8_t(y);
  if ( size == 2 )
    return uint16_t(x) < uint16_t(y);
  if ( size == 4 )
    return uint32_t(x) < uint32_t(y);
  return uint64_t(x) < uint64_t(y);
}

// carry flag of addition (x+y)
template<class T, class U> int8_t __CFADD__(T x, U y)
{
  int size = sizeof(T) > sizeof(U) ? sizeof(T) : sizeof(U);
  if ( size == 1 )
    return uint8_t(x) > uint8_t(x+y);
  if ( size == 2 )
    return uint16_t(x) > uint16_t(x+y);
  if ( size == 4 )
    return uint32_t(x) > uint32_t(x+y);
  return uint64_t(x) > uint64_t(x+y);
}

#else
// The following definition is not quite correct because it always returns
// uint64_t. The above C++ functions are good, though.
#define __PAIR__(high, low) (((uint64)(high)<<sizeof(high)*8) | low)
// For C, we just provide macros, they are not quite correct.
#define __ROL__(x, y) __rotl__(x, y)      // Rotate left
#define __ROR__(x, y) __rotr__(x, y)      // Rotate right
#define __CFSHL__(x, y) printf("invalid_operation:__CFSHL__(x, y)") // Generate carry flag for (x<<y)
#define __CFSHR__(x, y) invalid_operation // Generate carry flag for (x>>y)
#define __CFADD__(x, y) invalid_operation // Generate carry flag for (x+y)
#define __CFSUB__(x, y) invalid_operation // Generate carry flag for (x-y)
#define __OFADD__(x, y) invalid_operation // Generate overflow flag for (x+y)
#define __OFSUB__(x, y) invalid_operation // Generate overflow flag for (x-y)
#endif

// No definition for rcl/rcr because the carry flag is unknown
//#define __RCL__(x, y)    invalid_operation // Rotate left thru carry
//#define __RCR__(x, y)    invalid_operation // Rotate right thru carry
#define __MKCRCL__(x, y) invalid_operation // Generate carry flag for a RCL
#define __MKCRCR__(x, y) invalid_operation // Generate carry flag for a RCR
#define __SETP__(x, y)   invalid_operation // Generate parity flag for (x-y)

// In the decompilation listing there are some objects declarared as _UNKNOWN
// because we could not determine their types. Since the C compiler does not
// accept void item declarations, we replace them by anything of our choice,
// for example a char:

#define _UNKNOWN char

#ifdef _MSC_VER
#define snprintf _snprintf
#define vsnprintf _vsnprintf
#endif
