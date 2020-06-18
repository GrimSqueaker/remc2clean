#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include <direct.h>  
#include <io.h>  

#include <windows.h>
#ifdef _MSC_VER
#include "../portability/dirent-x.h"
#else
#include "dirent.h"
#endif
#include "../portability/port_time.h"
#include "../portability/port_filesystem.h"
#include "../portability/port_sdl_sound.h"
#include "defs.h"

#include "INIReader.h"
#include "ini.h"



#ifndef READ_CONFIG
#define READ_CONFIG

void readini(char* filename);
extern int config_skip_screen;
extern int texturepixels;
extern int speedGame;
extern int speedAnim;
extern bool res640x480;

#endif //READ_CONFIG