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

#define x_BYTE int8_t
#define x_WORD int16_t
#define x_DWORD int32_t
#define x_LONG int32_t

typedef struct {
	Bit8u* data;
	Bit8u width;
	Bit8u height;
} posistruct;
#endif //ENGINE_TYPES
