#ifndef ENGINE_TYPES
#define ENGINE_TYPES

#ifdef USE_DOSBOX
#include "dosbox.h"
#include "logging.h"
#include "dos_system.h"
#else
#include "../dosbox_files/config.h"
#endif //USE_DOSBOX

#include <cstdint>

#ifdef __linux__
typedef int8_t    int8;
typedef int8_t    sint8;
typedef uint8_t   uint8;
typedef int16_t   int16;
typedef int16_t   sint16;
typedef uint16_t  uint16;
typedef int32_t   int32;
typedef int32_t   sint32;
typedef uint32_t  uint32;
#else
typedef          char   int8;
typedef   signed char   sint8;
typedef unsigned char   uint8;
typedef          short  int16;
typedef   signed short  sint16;
typedef unsigned short  uint16;
typedef          int    int32;
typedef   signed int    sint32;
typedef unsigned int    uint32;
#endif

#define x_BYTE int8
#define x_WORD int16
#define x_DWORD int32
#define x_LONG int32

typedef struct {
	Bit8u* data;
	Bit8u width;
	Bit8u height;
} posistruct;
#endif //ENGINE_TYPES
