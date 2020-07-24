#include "engine_support.h"

#ifdef __linux__
  #include <ctype.h>
#endif

#ifdef USE_DOSBOX
extern DOS_Device *DOS_CON;
#endif //USE_DOSBOX


//delete after finalization
Bit8u* readbuffer;

char* printbuffer;//char* buffer; // [esp+0h] [ebp-2h]
char* printbuffer2;//char v11; // [esp+40h] [ebp+3Eh]

type_x_D41A0_BYTEARRAY_4_struct x_D41A0_BYTEARRAY_4_struct;

Bit16s x_D41A0_WORDARRAY[10000];

Bit8u x_BYTE_10B4E0_terraintype[0x10000]; // idb// x_BYTE_10B1E0[0x300]//2DC4E0 //map array1
Bit8u x_BYTE_11B4E0_height[0x10000]; // idb		//2EC4E0    	//map array2 // heightmap
Bit8u x_BYTE_12B4E0_shading[0x10000]; // fix it -  weak	//2FC4E0    //map array3
Bit8u x_BYTE_13B4E0_angle[0x10000]; // idb//30C4E0	//map array4 // water
int16_t x_WORD_15B4E0_source[0x10000]; // idb//32C4E0	//map array5


type_str_E2A74 str_E2A74[0x69] = {//2b3a74
{0x0000,{0x0000,0x0000,0x0000,0x0000,0x0000},0x00000000,0x00000000,0x00000000,0x00000000,0x00,0x00},
{0x0001,{0x0004,0x011E,0x0032,0x0140,0x0050},0x00000000,0x00000000,0x00000000,0x00000258,0x02,0x00},
{0x0001,{0x0200,0x011F,0x0032,0x0000,0x0000},0x00000000,0x00000000,0x00000000,0x00000258,0x02,0x00},
{0x0001,{0x0004,0x0120,0x0032,0x0140,0x0050},0x00000000,0x00000000,0x00000000,0x00000258,0x06,0x00},
{0x0001,{0x0024,0x0121,0x0032,0x0140,0x0050},0x00000000,0x00000000,0x00000000,0x0000012C,0x04,0x00},
{0x0001,{0x0220,0x0122,0x0032,0x01D6,0x0010},0x00000000,0x00000000,0x00000000,0x00000258,0x02,0x00},
{0x0001,{0x0404,0x0123,0x0032,0x0140,0x0050},0x00000000,0x00000000,0x00000000,0x00000258,0x02,0x00},
{0x0001,{0x0004,0x0124,0x0032,0x0140,0x0050},0x00000000,0x00000000,0x00000000,0x00000258,0x02,0x00},
{0x0001,{0x0004,0x0125,0x0032,0x0140,0x0050},0x00000000,0x00000000,0x00000000,0x00000258,0x02,0x00},
{0x0001,{0x0004,0x0126,0x0032,0x0140,0x0050},0x00000000,0x00000000,0x00000000,0x00000258,0x02,0x00},
{0x0001,{0x0624,0x0127,0x0032,0x0140,0x0050},0x00000000,0x00000000,0x00000000,0x00000258,0x05,0x00},
{0x0001,{0x0624,0x0128,0x0032,0x0140,0x0050},0x00000000,0x00000000,0x00000000,0x00000258,0x05,0x00},
{0x0001,{0x0624,0x0129,0x0032,0x0140,0x0050},0x00000000,0x00000000,0x00000000,0x00000258,0x05,0x00},
{0x0001,{0x0404,0x012A,0x0032,0x0140,0x0050},0x00000000,0x00000000,0x00000000,0x00000078,0x04,0x00},
{0x0001,{0x0404,0x012B,0x0032,0x0140,0x0050},0x00000000,0x00000000,0x00000000,0x00000258,0x05,0x00},
{0x0001,{0x0004,0x012C,0x0032,0x0140,0x0050},0x00000000,0x00000000,0x00000000,0x00000258,0x04,0x00},
{0x0001,{0x0004,0x012D,0x0032,0x0140,0x0050},0x00000000,0x00000000,0x00000000,0x00000258,0x04,0x00},
{0x0001,{0x0624,0x012E,0x0032,0x00D6,0x0010},0x00000000,0x00000000,0x00000000,0x00000190,0x05,0x00},
{0x0002,{0x0400,0x0132,0x0032,0x0000,0x0000},0x00000000,0x00000000,0x00000000,0x000000A0,0x05,0x00},
{0x0002,{0x0400,0x0133,0x0032,0x0000,0x0000},0x00000000,0x00000000,0x00000000,0x000000A0,0x05,0x00},
{0x0002,{0x0000,0x0134,0x0032,0x0000,0x0000},0x00000000,0x00000000,0x00000000,0x000000A0,0x05,0x00},
{0x0002,{0x0400,0x0135,0x0032,0x0000,0x0000},0x00000000,0x00000000,0x00000000,0x00000258,0x04,0x00},
{0x0002,{0x0000,0x0136,0x0032,0x0000,0x0000},0x00000000,0x00000000,0x00000000,0x00000140,0x04,0x00},
{0x0002,{0x0000,0x0137,0x0032,0x0000,0x0000},0x00000000,0x00000000,0x00000000,0x000000A0,0x05,0x00},
{0x0002,{0x0000,0x0138,0x0032,0x0000,0x0000},0x00000000,0x00000000,0x00000000,0x000000A0,0x05,0x00},
{0x0002,{0x0000,0x0139,0x0032,0x0000,0x0000},0x00000000,0x00000000,0x00000000,0x000000A0,0x05,0x00},
{0x0002,{0x0000,0x013A,0x0032,0x0000,0x0000},0x00000000,0x00000000,0x00000000,0x000000A0,0x05,0x00},
{0x0002,{0x0000,0x013B,0x0032,0x0000,0x0000},0x00000000,0x00000000,0x00000000,0x00000140,0x03,0x00},
{0x0002,{0x0000,0x013C,0x0032,0x0000,0x0000},0x00000000,0x00000000,0x00000000,0x000000A0,0x05,0x00},
{0x0003,{0x0220,0x013D,0x0032,0x00D6,0x0020},0x00000000,0x00000000,0x00000000,0x00000320,0x02,0x00},
{0x0003,{0x0220,0x013E,0x0032,0x00D6,0x0010},0x00000000,0x00000000,0x00000000,0x00000320,0x02,0x00},
{0x0003,{0x0220,0x013F,0x0032,0x0082,0x0010},0x00000000,0x00000000,0x00000000,0x00000320,0x02,0x00},
{0x0003,{0x0220,0x0140,0x0032,0x0140,0x0020},0x00000000,0x00000000,0x00000000,0x00000320,0x02,0x00},
{0x0003,{0x0220,0x0141,0x0032,0x0104,0x0010},0x00000000,0x00000000,0x00000000,0x00000320,0x02,0x00},
{0x0003,{0x0220,0x0142,0x0032,0x0140,0x0010},0x00000000,0x00000000,0x00000000,0x00000320,0x02,0x00},
{0x0003,{0x0620,0x0143,0x0032,0x0000,0x0000},0x00000000,0x00000000,0x00000000,0x00000320,0x02,0x00},
{0x0004,{0x0220,0x0144,0x0032,0x01D6,0x0010},0x00000000,0x00000000,0x00000000,0x00000320,0x02,0x03},
{0x0004,{0x0220,0x0145,0x0032,0x01D6,0x0020},0x00000000,0x00000000,0x00000000,0x00000320,0x02,0x03},
{0x0005,{0x0620,0x0146,0x0032,0x021C,0x0020},0x00000000,0x00000000,0x00000000,0x00000320,0x02,0x00},
{0x0005,{0x0620,0x0147,0x0032,0x0258,0x0020},0x00000000,0x00000000,0x00000000,0x00000320,0x02,0x00},
{0x0005,{0x0620,0x0148,0x0032,0x021C,0x0028},0x00000000,0x00000000,0x00000000,0x00000320,0x02,0x00},
{0x0005,{0x0620,0x0149,0x0032,0x0000,0x0000},0x00000000,0x00000000,0x00000000,0x00000320,0x02,0x00},
{0x0005,{0x0220,0x014A,0x0032,0x0230,0x0010},0x00000000,0x00000000,0x00000000,0x00000320,0x02,0x00},
{0x0006,{0x0000,0x00A0,0x0032,0x0000,0x0000},0x00000000,0x00000000,0x00000000,0x00000050,0x00,0x00},
{0x0006,{0x0000,0x00A1,0x0032,0x0000,0x0000},0x00000000,0x00000000,0x00000000,0x00000050,0x00,0x00},
{0x0006,{0x0000,0x00A2,0x0032,0x0000,0x0000},0x00000000,0x00000000,0x00000000,0x00000050,0x00,0x00},
{0x0006,{0x0000,0x00A3,0x0032,0x0000,0x0000},0x00000000,0x00000000,0x00000000,0x00000050,0x00,0x00},
{0x0006,{0x0000,0x00A4,0x0032,0x0000,0x0000},0x00000000,0x00000000,0x00000000,0x00000050,0x00,0x00},
{0x0006,{0x0000,0x00A5,0x0032,0x0000,0x0000},0x00000000,0x00000000,0x00000000,0x00000050,0x00,0x00},
{0x0006,{0x0000,0x00A6,0x0032,0x0000,0x0000},0x00000000,0x00000000,0x00000000,0x00000050,0x00,0x00},
{0x0006,{0x0000,0x00A7,0x0032,0x0000,0x0000},0x00000000,0x00000000,0x00000000,0x00000050,0x00,0x00},
{0x0006,{0x0000,0x00A8,0x0032,0x0000,0x0000},0x00000000,0x00000000,0x00000000,0x00000050,0x00,0x00},
{0x0006,{0x0000,0x00A9,0x0032,0x0000,0x0000},0x00000000,0x00000000,0x00000000,0x00000050,0x00,0x00},
{0x0006,{0x0000,0x00AA,0x0032,0x0000,0x0000},0x00000000,0x00000000,0x00000000,0x00000050,0x00,0x00},
{0x0006,{0x0000,0x00AB,0x0032,0x0000,0x0000},0x00000000,0x00000000,0x00000000,0x00000050,0x00,0x00},
{0x0006,{0x0000,0x00AC,0x0032,0x0000,0x0000},0x00000000,0x00000000,0x00000000,0x00000050,0x00,0x00},
{0x0006,{0x0000,0x00AD,0x0032,0x0000,0x0000},0x00000000,0x00000000,0x00000000,0x00000050,0x00,0x00},
{0x0006,{0x0000,0x00AE,0x0032,0x0000,0x0000},0x00000000,0x00000000,0x00000000,0x00000050,0x00,0x00},
{0x0006,{0x0000,0x00AF,0x0032,0x0000,0x0000},0x00000000,0x00000000,0x00000000,0x00000050,0x00,0x00},
{0x0006,{0x0000,0x00B0,0x0032,0x0000,0x0000},0x00000000,0x00000000,0x00000000,0x00000050,0x00,0x00},
{0x0006,{0x0000,0x00B1,0x0032,0x0000,0x0000},0x00000000,0x00000000,0x00000000,0x00000050,0x00,0x00},
{0x0006,{0x0000,0x00B2,0x0032,0x0000,0x0000},0x00000000,0x00000000,0x00000000,0x00000050,0x00,0x00},
{0x0006,{0x0000,0x00B3,0x0032,0x0000,0x0000},0x00000000,0x00000000,0x00000000,0x00000050,0x00,0x00},
{0x0006,{0x0000,0x00B4,0x0032,0x0000,0x0000},0x00000000,0x00000000,0x00000000,0x00000050,0x00,0x00},
{0x0006,{0x0000,0x00B5,0x0032,0x0000,0x0000},0x00000000,0x00000000,0x00000000,0x00000050,0x00,0x00},
{0x0006,{0x0000,0x00B6,0x0032,0x0000,0x0000},0x00000000,0x00000000,0x00000000,0x00000050,0x00,0x00},
{0x0006,{0x0000,0x00B7,0x0032,0x0000,0x0000},0x00000000,0x00000000,0x00000000,0x00000050,0x00,0x00},
{0x0006,{0x0000,0x00B8,0x0032,0x0000,0x0000},0x00000000,0x00000000,0x00000000,0x00000050,0x00,0x00},
{0x0006,{0x0000,0x00B9,0x0032,0x0000,0x0000},0x00000000,0x00000000,0x00000000,0x00000050,0x00,0x00},
{0x0006,{0x0000,0x014B,0x0032,0x0000,0x0000},0x00000000,0x00000000,0x00000000,0x00000050,0x00,0x00},
{0x0006,{0x0000,0x014C,0x0032,0x0000,0x0000},0x00000000,0x00000000,0x00000000,0x00000050,0x00,0x00},
{0x0006,{0x0000,0x014D,0x0032,0x0000,0x0000},0x00000000,0x00000000,0x00000000,0x00000050,0x00,0x00},
{0x0007,{0x0004,0x014E,0x0032,0x0140,0x0050},0x00000000,0x00000000,0x00000000,0x00000258,0x03,0x00},
{0x0007,{0x0004,0x014F,0x0032,0x0140,0x0050},0x00000000,0x00000000,0x00000000,0x00000258,0x03,0x00},
{0x0007,{0x0004,0x0150,0x0032,0x0140,0x0050},0x00000000,0x00000000,0x00000000,0x00000258,0x03,0x00},
{0x0007,{0x0004,0x0151,0x0032,0x0140,0x0050},0x00000000,0x00000000,0x00000000,0x00000258,0x03,0x00},
{0x0007,{0x0004,0x0152,0x0032,0x0140,0x0050},0x00000000,0x00000000,0x00000000,0x00000258,0x03,0x00},
{0x0007,{0x0004,0x0153,0x0032,0x0140,0x0050},0x00000000,0x00000000,0x00000000,0x00000258,0x03,0x00},
{0x0007,{0x0004,0x0154,0x0032,0x0140,0x0050},0x00000000,0x00000000,0x00000000,0x00000258,0x03,0x00},
{0x0007,{0x0004,0x0155,0x0032,0x0140,0x0050},0x00000000,0x00000000,0x00000000,0x00000258,0x03,0x00},
{0x0007,{0x0004,0x0156,0x0032,0x0140,0x0050},0x00000000,0x00000000,0x00000000,0x0000008C,0x04,0x00},
{0x0008,{0x0280,0x0157,0x0032,0x0000,0x0000},0x00000000,0x00000000,0x00000000,0x000000A0,0x05,0x00},
{0x0008,{0x0400,0x0158,0x0032,0x0000,0x0000},0x00000000,0x00000000,0x00000000,0x000000A0,0x05,0x00},
{0x0008,{0x0280,0x0159,0x0032,0x0000,0x0000},0x00000000,0x00000000,0x00000000,0x00000064,0x05,0x00},
{0x0009,{0x0004,0x011E,0x0032,0x0000,0x0000},0x00000000,0x00000000,0x00000000,0x00000000,0x00,0x00},
{0x000A,{0x0000,0x00BA,0x0046,0x0000,0x0000},0x00000000,0x00000000,0x00000000,0x00000000,0x00,0x00},
{0x000B,{0x0000,0x01A8,0x0000,0x0168,0x0072},0x00000000,0x00000000,0x00000000,0x00000000,0x00,0x00},
{0x000B,{0x0000,0x01A7,0x0000,0x0168,0x0092},0x00000000,0x00000000,0x00000000,0x00000000,0x00,0x00},
{0x000B,{0x0000,0x01AB,0x0000,0x0136,0x00B0},0x00000000,0x00000000,0x00000000,0x00000000,0x00,0x00},
{0x000B,{0x0000,0x01AA,0x0000,0x0168,0x00B0},0x00000000,0x00000000,0x00000000,0x00000000,0x00,0x00},
{0x000B,{0x0000,0x01AC,0x0000,0x0168,0x00D2},0x00000000,0x00000000,0x00000000,0x00000000,0x00,0x00},
{0x0001,{0x0004,0x017C,0x0032,0x0140,0x0050},0x00000000,0x00000000,0x00000000,0x00000064,0x04,0x00},
{0x0001,{0x0104,0x0000,0x0032,0x0140,0x0050},0x00000000,0x00000000,0x00000000,0x00000190,0x03,0x00},
{0x0001,{0x0004,0x012F,0x0032,0x0140,0x0050},0x00000000,0x00000000,0x00000000,0x00000000,0x01,0x00},
{0x0001,{0x0004,0x0130,0x0032,0x0140,0x0050},0x00000000,0x00000000,0x00000000,0x00000000,0x01,0x00},
{0x000C,{0x0000,0x0160,0x0032,0x0000,0x0000},0x00000000,0x00000000,0x00000000,0x00000000,0x01,0x00},
{0x000C,{0x0100,0x0161,0x0032,0x0000,0x0000},0x00000000,0x00000000,0x00000000,0x00000000,0x01,0x00},
{0x000D,{0x0000,0x015A,0x0032,0x003C,0x0168},0x00000000,0x00000000,0x00000000,0x00000000,0x01,0x00},
{0x000D,{0x0000,0x015B,0x0032,0x008C,0x0170},0x00000000,0x00000000,0x00000000,0x00000000,0x01,0x00},
{0x000D,{0x0000,0x015C,0x0032,0x00D4,0x0170},0x00000000,0x00000000,0x00000000,0x00000000,0x01,0x00},
{0x000D,{0x0000,0x015D,0x0032,0x0116,0x0170},0x00000000,0x00000000,0x00000000,0x00000000,0x01,0x00},
{0x000D,{0x0000,0x015E,0x0032,0x0174,0x0170},0x00000000,0x00000000,0x00000000,0x00000000,0x01,0x00},
{0x000D,{0x0000,0x015F,0x0032,0x0198,0x0168},0x00000000,0x00000000,0x00000000,0x00000000,0x01,0x00},
{0x0000,{0x0000,0x0000,0x0000,0x0000,0x0000},0x00000000,0x00000000,0x00000000,0x00000000,0x00,0x00},
{0x0000,{0x0000,0x0000,0x0000,0x0000,0x0000},0x00000000,0x00000000,0x00000000,0x00000000,0x00,0x00},
};


Bit8u* x_DWORD_180628b_screen_buffer; //351628

Bit8u* off_D41A8_sky;//graphics buffer// = (Bit8u*)&x_BYTE_14B4E0; // weak
Bit8u* x_BYTE_14B4E0;//31C4E0

posistruct* xy_DWORD_17DED4_spritestr;
posistruct* xy_DWORD_17DEC0_spritestr;
posistruct* xy_DWORD_17DEC8_spritestr;

posistruct* x_DWORD_D4188t_spritestr;

posistruct* xy_DWORD_17DEC0_spritestr_orig;

doublebyte doublebyte_conv(Bit16u a2) {
	doublebyte result;
	result.byte1 = a2 && 0xff;
	result.byte2 = a2 && 0xff00;
	return result;
};

Bit8u* pre_x_DWORD_180628b_screen_buffer;

void allert_error() {
	int a = 10;
	int b = 0;
	int c = a / b;//this is generate error
}

void support_begin() {
    readbuffer = (Bit8u*)malloc(1000000);//fix it max 64000
    printbuffer = (char*)malloc(4096);
    //printbuffer[0] = '\0';
    printbuffer2 = (char*)malloc(4096);
	pre_x_DWORD_180628b_screen_buffer = (Bit8u*)malloc(0x220000);
	x_DWORD_180628b_screen_buffer = &pre_x_DWORD_180628b_screen_buffer[0x110000];

	x_BYTE_14B4E0 = new Bit8u[65536];
	off_D41A8_sky = new Bit8u[65536];
	memcpy(off_D41A8_sky, &x_BYTE_14B4E0,4);

	xy_DWORD_17DED4_spritestr = new posistruct[1000];
	xy_DWORD_17DEC0_spritestr_orig = new posistruct[1000];
	xy_DWORD_17DEC0_spritestr=xy_DWORD_17DEC0_spritestr_orig;
	xy_DWORD_17DEC8_spritestr = new posistruct[1000];

	x_DWORD_D4188t_spritestr = new posistruct[1000];

	x_D41A0_BYTEARRAY_4_struct.harddiskchar_byte4_182 = 0x43;
}

void support_end() {
	if(readbuffer)free(readbuffer);
	if(printbuffer)free(printbuffer);//char* buffer; // [esp+0h] [ebp-2h]
    if(printbuffer2)free(printbuffer2);//char v11; // [esp+40h] [ebp+3Eh]
	if(pre_x_DWORD_180628b_screen_buffer)free(pre_x_DWORD_180628b_screen_buffer);

	if(x_BYTE_14B4E0)delete(x_BYTE_14B4E0);
	if(off_D41A8_sky)delete(off_D41A8_sky);

	if(xy_DWORD_17DED4_spritestr)delete(xy_DWORD_17DED4_spritestr);
	if(xy_DWORD_17DEC0_spritestr_orig)delete(xy_DWORD_17DEC0_spritestr_orig);//fixed
	if(xy_DWORD_17DEC8_spritestr)delete(xy_DWORD_17DEC8_spritestr);

	if(x_DWORD_D4188t_spritestr)delete(x_DWORD_D4188t_spritestr);
}

void loadfromsnapshot(char* filename, Bit8u* adress, Bit32u adressdos, Bit32u size) {
	char findnamec[500];
	FILE* fptestepc;
	sprintf(findnamec, "../remc2/memimages/engine-memory-%s", filename);
	fptestepc=fopen(findnamec, "rb");
	fseek(fptestepc, adressdos, SEEK_SET);
	fread(adress, size, 1, fptestepc);
	fclose(fptestepc);
};

void loadfromsnapshot2(char* filename, Bit8u* adress, Bit32u adressdos, Bit32u size) {
	char findnamec[500];
	FILE* fptestepc;
	Bit32u subadress;
	sprintf(findnamec, "../remc2/memimages/engine-memory-%s", filename);
	fptestepc=fopen(findnamec, "rb");
	fseek(fptestepc, adressdos, SEEK_SET);
	fread(&subadress, 4, 1, fptestepc);
	fseek(fptestepc, subadress, SEEK_SET);
	fread(adress, size, 1, fptestepc);

	fclose(fptestepc);
};


Bit32u compare_with_snapshot(char* filename, Bit8u* adress, Bit32u adressdos, Bit32u size, Bit8u* origbyte, Bit8u* copybyte) {

	char findnamec[500];
	Bit8u* buffer = (Bit8u*)malloc(size);
	FILE* fptestepc;
	sprintf(findnamec, "c:/prenos/remc2/remc2/memimages/engine-memory-%s", filename);
	fptestepc=fopen(findnamec, "rb");
	if (fptestepc == NULL)
	{
		mydelay(100);
		fptestepc=fopen(findnamec, "rb");
	}
	fseek(fptestepc, adressdos, SEEK_SET);
	
	fread(buffer, size, 1, fptestepc);
	Bit32u i;
	for (i = 0;i < size;i++)
	{
		if (buffer[i] != adress[i])
		{
			*origbyte = buffer[i];
			*copybyte = adress[i];
			break;
		}
	}

	free(buffer);
	fclose(fptestepc);
	return(i);
};
int test_E7EE0_id_pointer(Bit32u adress) {
	if ((adress >= 0x28) && (adress < 0x29))return 1;
	return 0;
}

int test_D41A0_4_id_pointer(Bit32u adress) {
	if ((adress >= 0xe2) && (adress < 0xe3))return 1;	
	if ((adress >= 0x954) && (adress < 0x95a))return 2;
	return 0;
}
int test_EA3E4_id_pointer(Bit32u adress) {
	if ((adress >= 0x0) && (adress < 0x1))return 1;
	if ((adress >= 0xa0) && (adress < 0xa1))return 1;
	if ((adress >= 0xa4) && (adress < 0xa5))return 1;
	return 0;
}


int test_0x6E8E_id_pointer(Bit32u adress) {
	if ((adress >= 0x0) && (adress < 0x1))return 1;
	if ((adress >= 0xa0) && (adress < 0xa1))return 1;
	if ((adress >= 0xa4) && (adress < 0xa5))return 1;
	return 0;
}
int test_D41A0_id_pointer(Bit32u adress) {
	if ((adress >= 0x2fc4) && (adress < 0x2fc5))return 2;//event

	if ((adress >= 0x314d) && (adress < 0x3151))return 2;//clock
	if ((adress >= 0x3999) && (adress < 0x399c))return 2;//clock2
	if ((adress >= 0x41e5) && (adress < 0x41e8))return 2;//clock3
	if ((adress >= 0x4a31) && (adress < 0x4a34))return 2;//clock4
	if ((adress >= 0x527d) && (adress < 0x5280))return 2;//clock5
	if ((adress >= 0x5ac9) && (adress < 0x5acc))return 2;//clock6
	if ((adress >= 0x6315) && (adress < 0x6318))return 2;//clock7
	if ((adress >= 0x6b61) && (adress < 0x6b64))return 2;//clock8

	if ((adress >= 0x235) && (adress < 0x236))return 2;//music

	if ((adress >= 0x246)&& (adress < 0x2186))return 1;

	if ((adress >= 0x36552) && (adress < 0x36553))return 1;
	if ((adress >= 0x3655c) && (adress < 0x3655d))return 1;	
	if ((adress >= 0x3655f) && (adress < 0x36560))return 1;
	if ((adress >= 0x36566) && (adress < 0x36567))return 1;
	if ((adress >= 0x36570) && (adress < 0x36571))return 1;
	if ((adress >= 0x36608) && (adress < 0x36609))return 1;
	//if ((adress >= 0x36625) && (adress < 0x36626))return 1;
	if ((adress >= 0x36628) && (adress < 0x36630))return 1;

	/*if ((adress >= 0x36b36) && (adress < 0x36b37))return 1;
	if ((adress >= 0x36b5d) && (adress < 0x36b5e))return 1;
	if ((adress >= 0x36b84) && (adress < 0x36b85))return 1;
	if ((adress >= 0x36bab) && (adress < 0x36bac))return 1;
	if ((adress >= 0x36bd2) && (adress < 0x36bd3))return 1;
	*/
	for (int j = 1; j < 50; j++)
	{
		if ((adress >= 0x3664C+0xa +39*j) && (adress < 0x3664C + 0xa +1 + 39 * j))return 1;
	}


	/*if ((adress >= 0x36656) && (adress < 0x36657))return 1;
	if ((adress >= 0x3667d) && (adress < 0x3667e))return 1;
	if ((adress >= 0x366a4) && (adress < 0x366a5))return 1;
	if ((adress >= 0x366cb) && (adress < 0x366cc))return 1;
	if ((adress >= 0x366f2) && (adress < 0x366f3))return 1;
	if ((adress >= 0x36719) && (adress < 0x3671a))return 1;
	if ((adress >= 0x36740) && (adress < 0x36741))return 1;
	if ((adress >= 0x36767) && (adress < 0x36768))return 1;
	if ((adress >= 0x3678e) && (adress < 0x3678f))return 1;*/
	if ((adress >= 0x36620) && (adress < 0x36621))return 1;
	for (Bit32u i = 0; i < 32; i++) {
		if ((adress >= 0x36656 + i * 39) && (adress < 0x36657 + i * 39))return 1;
	}
	/*if ((adress >= 0x6f32) && (adress < 0x6f37))return 1;
	if ((adress >= 0x6fd6) && (adress < 0x6fdb))return 1;
	if ((adress >= 0x707e) && (adress < 0x707f))return 1;
	if ((adress >= 0x7082) && (adress < 0x7083))return 1;
	if ((adress >= 0x7126) && (adress < 0x712b))return 1;
	if ((adress >= 0x71ce) && (adress < 0x71cf))return 1;
	if ((adress >= 0x71d2) && (adress < 0x71d3))return 1;
	if ((adress >= 0x7276) && (adress < 0x7277))return 1;
	if ((adress >= 0x727a) && (adress < 0x727b))return 1;
	if ((adress >= 0x731e) && (adress < 0x731f))return 1;
	if ((adress >= 0x7322) && (adress < 0x7323))return 1;
	if ((adress >= 0x73c6) && (adress < 0x73c7))return 1;
	if ((adress >= 0x73ca) && (adress < 0x73cb))return 1;
	if ((adress >= 0x746e) && (adress < 0x746f))return 1;
	if ((adress >= 0x7472) && (adress < 0x7473))return 1;
	if ((adress >= 0x7516) && (adress < 0x7517))return 1;
	if ((adress >= 0x751a) && (adress < 0x751b))return 1;
	if ((adress >= 0x75be) && (adress < 0x75bf))return 1;
	if ((adress >= 0x75c2) && (adress < 0x75c3))return 1;
	if ((adress >= 0x7666) && (adress < 0x7667))return 1;
	if ((adress >= 0x766a) && (adress < 0x766b))return 1;
	if ((adress >= 0x770e) && (adress < 0x770f))return 1;
	if ((adress >= 0x7712) && (adress < 0x7713))return 1;
	if ((adress >= 0x77b6) && (adress < 0x77b7))return 1;
	if ((adress >= 0x77ba) && (adress < 0x77bb))return 1;
	if ((adress >= 0x785e) && (adress < 0x7863))return 1;
	if ((adress >= 0x7906) && (adress < 0x790b))return 1;
	if ((adress >= 0x79ae) && (adress < 0x79b3))return 1;
	if ((adress >= 0x7a56) && (adress < 0x7a5b))return 1;
	if ((adress >= 0x7afe) && (adress < 0x7b03))return 1;*/
	for (Bit32u i = 0; i < 0x3e8; i++) {
		if ((adress >= 0x6f2e +i*168) && (adress < 0x6f37 + i * 168))return 1;
	}
	if ((adress >= 0x36df6) && (adress < 0x36df7))return 1;
	return 0;
}

int test_E2A74_id_pointer(Bit32u adress) {
	if ((adress >= 0x246) && (adress < 0x247))return 1;
	if ((adress >= 0x282) && (adress < 0x283))return 1;
	if ((adress >= 0x2a0) && (adress < 0x2a1))return 1;

	return 0;
}

int test_222BD3_id_pointer(Bit32u adress) {
	if ((adress >= 0x8) && (adress < 0x9))return 1;
	if ((adress >= 0x50) && (adress < 0x51))return 1;
	if ((adress >= 0x68) && (adress < 0x69))return 1;


	return 0;
}

Bit32u compare_with_snapshot_D41A0(char* filename, Bit8u* adress, Bit32u adressdos, Bit32u size, Bit8u* origbyte, Bit8u* copybyte) {

	char findnamec[500];
	Bit8u* buffer = (Bit8u*)malloc(size);
	FILE* fptestepc;
	sprintf(findnamec, "c:/prenos/dosbox-x-remc2/vs2015/engine-memory-%s", filename);
	fptestepc=fopen(findnamec, "rb");
	if (fptestepc == NULL)
	{
		mydelay(100);
		fptestepc=fopen(findnamec, "rb");
	}
	fseek(fptestepc, adressdos, SEEK_SET);

	fread(buffer, size, 1, fptestepc);
	Bit32u i;
	bool testa, testb;
	for (i = 0; i < size; i++)
	{
		int testx = test_D41A0_id_pointer(i);
		if (testx==1)
		{
			if (*(Bit32u*)&buffer[i])testa = true;
			else testa = false;
			if (*(Bit32u*)&adress[i])testb = true;
			else testb = false;
			if (testa != testb)
			{
				*origbyte = buffer[i];
				*copybyte = adress[i];
				break;
			}
			i += 3;
		}
		else if (testx == 0) {
			if (buffer[i] != adress[i])
			{
				*origbyte = buffer[i];
				*copybyte = adress[i];
				break;
			}
		}
	}

	free(buffer);
	fclose(fptestepc);
	return(i);
};

Bit32u compare_with_sequence_E7EE0(char* filename, Bit8u* adress, Bit32u adressdos, Bit32u count, Bit32u size1, Bit32u size2, Bit8u* origbyte, Bit8u* copybyte, long offset){
	char findnamec[500];
	Bit8u* buffer = (Bit8u*)malloc(size2);
	FILE* fptestepc;
	sprintf(findnamec, "c:/prenos/dosbox-x-remc2/vs2015/sequence-%s.bin", filename);
	fptestepc=fopen(findnamec, "rb");
	if (fptestepc == NULL)
	{
		mydelay(100);
		fptestepc=fopen(findnamec, "rb");
	}
	fseek(fptestepc, count * size1 + offset, SEEK_SET);

	fread(buffer, size2, 1, fptestepc);
	Bit32u i;
	bool testa, testb;
	int diffindex = 0;
	for (i = 0; i < size2; i++)
	{
		int testx = test_E7EE0_id_pointer(i);
		if (testx == 1)
		{
			if (*(Bit32u*)& buffer[i])testa = true;
			else testa = false;
			if (*(Bit32u*)& adress[i])testb = true;
			else testb = false;
			if (testa != testb)
			{
				*origbyte = buffer[i];
				*copybyte = adress[i];
				break;
			}
			i += 3;
		}
		else if (testx == 0) {
			if (buffer[i] != adress[i])
			{
				*origbyte = buffer[i];
				*copybyte = adress[i];
				break;
			}
		}
	}

	free(buffer);
	fclose(fptestepc);
	return(i);
};

Bit32u compare_with_sequence_D41A0(char* filename, Bit8u* adress, Bit32u adressdos, Bit32u count, Bit32u size, Bit8u* origbyte, Bit8u* copybyte, long offset) {

	char findnamec[500];
	Bit8u* buffer = (Bit8u*)malloc(size);
	FILE* fptestepc;
	sprintf(findnamec, "c:/prenos/dosbox-x-remc2/vs2015/sequence-%s.bin", filename);
	fptestepc=fopen(findnamec, "rb");
	if (fptestepc == NULL)
	{
		mydelay(100);
		fptestepc=fopen(findnamec, "rb");
	}
	fseek(fptestepc, count*size+ offset, SEEK_SET);

	fread(buffer, size, 1, fptestepc);
	Bit32u i;
	bool testa, testb;
	for (i = 0; i < size; i++)
	{
		int testx = test_D41A0_id_pointer(i);
		if (testx == 1)
		{
			if (*(Bit32u*)&buffer[i])testa = true;
			else testa = false;
			if (*(Bit32u*)&adress[i])testb = true;
			else testb = false;
			if (testa != testb)
			{
				*origbyte = buffer[i];
				*copybyte = adress[i];
				break;
			}
			i += 3;
		}
		else if (testx == 0) {
			if (buffer[i] != adress[i])
			{
				*origbyte = buffer[i];
				*copybyte = adress[i];
				break;
			}
		}
	}

	free(buffer);
	fclose(fptestepc);
	if (i < size)
		allert_error();
	return(i);
};

Bit32u compare_0x6E8E(char* filename, Bit8u* adress, Bit32u count, Bit32u size, Bit8u* origbyte, Bit8u* copybyte, long offset) {

	char findnamec[500];
	Bit8u* buffer = (Bit8u*)malloc(size);
	FILE* fptestepc;
	sprintf(findnamec, "c:/prenos/dosbox-x-remc2/vs2015/sequence-%s.bin", filename);
	fptestepc=fopen(findnamec, "rb");
	if (fptestepc == NULL)
	{
		mydelay(100);
		fptestepc=fopen(findnamec, "rb");
	}
	fseek(fptestepc, count * size + offset, SEEK_SET);

	fread(buffer, size, 1, fptestepc);
	Bit32u i;
	bool testa, testb;
	for (i = 0; i < size; i++)
	{
		int testx = test_0x6E8E_id_pointer(i);
		if (testx == 1)
		{
			if (*(Bit32u*)& buffer[i])testa = true;
			else testa = false;
			if (*(Bit32u*)& adress[i])testb = true;
			else testb = false;
			if (testa != testb)
			{
				*origbyte = buffer[i];
				*copybyte = adress[i];
				break;
			}
			i += 3;
		}
		else if (testx == 0) {
			if (buffer[i] != adress[i])
			{
				*origbyte = buffer[i];
				*copybyte = adress[i];
				break;
			}
		}
	}

	free(buffer);
	fclose(fptestepc);
	if (i < size)
		allert_error();
	return(i);
};

Bit32u compare_with_sequence_EA3E4(char* filename, type_str_0x6E8E** adress, Bit32u count, Bit32u size, Bit8u* origbyte, Bit8u* copybyte) {

	char findnamec[500];
	Bit8u* buffer = (Bit8u*)malloc(size * 0x3E9);
	FILE* fptestepc;
	sprintf(findnamec, "c:/prenos/dosbox-x-remc2/vs2015/seq_D41A0-%s.bin", filename);
	fptestepc=fopen(findnamec, "rb");
	if (fptestepc == NULL)
	{
		mydelay(100);
		fptestepc=fopen(findnamec, "rb");
	}
	fseek(fptestepc, count * size * 0x3E9/* + offset*/, SEEK_SET);

	fread(buffer, size * 0x3E9, 1, fptestepc);

	for (int ea = 0; ea < 0x3E9; ea++)
	{
		Bit32u i;
		bool testa, testb;
		for (i = 0; i < size; i++)
		{
			int testx = test_EA3E4_id_pointer(i);
			if (testx == 1)
			{
				if (*(Bit32u*)& buffer[i+ ea * size])testa = true;
				else testa = false;
				if (*(Bit32u*)((Bit8u*)adress[ea] + i))testb = true;
				else testb = false;
				if (testa != testb)
				{
					*origbyte = buffer[i + ea * size];
					*copybyte = *((Bit8u*)adress[ea] + i);
					break;
				}
				i += 3;
			}
			else if (testx == 0) {
				if (buffer[i + ea * size] != *((Bit8u*)adress[ea]+i) )
				{
					*origbyte = buffer[i + ea * size];
					*copybyte = *((Bit8u*)adress[ea] + i);
					break;
				}
			}
		}
		if (i < size)
			allert_error();
	}


	free(buffer);


	fclose(fptestepc);
	
	return(1);
};

Bit32u compare_with_sequence_D41A0_4(char* filename, Bit8u* adress, Bit32u adressdos, Bit32u count, Bit32u size, Bit8u* origbyte, Bit8u* copybyte, long offset) {

	char findnamec[500];
	Bit8u* buffer = (Bit8u*)malloc(size);
	FILE* fptestepc;
	sprintf(findnamec, "c:/prenos/dosbox-x-remc2/vs2015/sequence-%s.bin", filename);
	fptestepc=fopen(findnamec, "rb");
	if (fptestepc == NULL)
	{
		mydelay(100);
		fptestepc=fopen(findnamec, "rb");
	}
	fseek(fptestepc, count * size + offset, SEEK_SET);

	fread(buffer, size, 1,fptestepc);
	Bit32u i;
	bool testa, testb;
	for (i = 0; i < size; i++)
	{
		int testx = test_D41A0_4_id_pointer(i);
		if (testx == 1)
		{
			if (*(Bit32u*)& buffer[i])testa = true;
			else testa = false;
			if (*(Bit32u*)& adress[i])testb = true;
			else testb = false;
			if (testa != testb)
			{
				*origbyte = buffer[i];
				*copybyte = adress[i];
				break;
			}
			i += 3;
		}
		else if (testx == 0) {
			if (buffer[i] != adress[i])
			{
				*origbyte = buffer[i];
				*copybyte = adress[i];
				break;
			}
		}
	}

	free(buffer);
	fclose(fptestepc);
	if (i < size)
		allert_error();
	return(i);
};

int test_F2C20ar_id_pointer(Bit32u adress) {
	if ((adress >= 0x8) && (adress < 0x9))return 1;
	return 0;
}

Bit32u compare_with_sequence_x_DWORD_F2C20ar(char* filename, Bit8u* adress, Bit32u adressdos, Bit32u count, Bit32u size, Bit8u* origbyte, Bit8u* copybyte, int* posdiff) {

	char findnamec[500];
	Bit8u* buffer = (Bit8u*)malloc(size);
	FILE* fptestepc;
	sprintf(findnamec, "c:/prenos/dosbox-x-remc2/vs2015/sequence-%s.bin", filename);
	fptestepc=fopen(findnamec, "rb");
	if (fptestepc == NULL)
	{
		mydelay(100);
		fptestepc=fopen(findnamec, "rb");
	}
	fseek(fptestepc, count*size, SEEK_SET);

	fread(buffer, size, 1, fptestepc);
	Bit32u i;
	bool testa, testb;
	int diffindex = 0;
	for (i = 0; i < size; i++)
	{
		int testx = test_F2C20ar_id_pointer(i);
		if (testx == 1)
		{
			if (*(Bit32u*)&buffer[i])testa = true;
			else testa = false;
			if (*(Bit32u*)&adress[i])testb = true;
			else testb = false;
			if (testa != testb)
			{
				posdiff[diffindex] = i;
				origbyte[diffindex] = buffer[i];
				copybyte[diffindex++] = adress[i];
				if (diffindex >= 100)break;
			}
			i += 3;
		}
		else if (testx == 0) {
			if (buffer[i] != adress[i])
			{
				posdiff[diffindex] = i;
				origbyte[diffindex] = buffer[i];
				copybyte[diffindex++] = adress[i];
				if (diffindex >= 100)break;
			}
		}
	}

	free(buffer);
	fclose(fptestepc);
	return(diffindex);
};

Bit32u compare_with_sequence_array_E2A74(char* filename, Bit8u* adress, Bit32u adressdos, Bit32u count, Bit32u size1,Bit32u size2, Bit8u* origbyte, Bit8u* copybyte, long offset) {

	char findnamec[500];
	Bit8u* buffer = (Bit8u*)malloc(size2);
	FILE* fptestepc;
	sprintf(findnamec, "c:/prenos/dosbox-x-remc2/vs2015/sequence-%s.bin", filename);
	fptestepc=fopen(findnamec, "rb");
	if (fptestepc == NULL)
	{
		mydelay(100);
		fptestepc=fopen(findnamec, "rb");
	}
	fseek(fptestepc, count * size1 + offset, SEEK_SET);

	fread(buffer, size2, 1,fptestepc);
	Bit32u i;
	bool testa, testb;
	int diffindex=0;
	for (i = 0; i < size2; i++)
	{
		int testx = test_E2A74_id_pointer(i);
		if (testx == 1)
		{
			if (*(Bit32u*)&buffer[i])testa = true;
			else testa = false;
			if (*(Bit32u*)&adress[i])testb = true;
			else testb = false;
			if (testa != testb)
			{
				*origbyte = buffer[i];
				*copybyte = adress[i];
				break;
			}
			i += 3;
		}
		else if (testx == 0) {
			if (buffer[i] != adress[i])
			{
				*origbyte = buffer[i];
				*copybyte = adress[i];
				break;
			}
		}
	}

	free(buffer);
	fclose(fptestepc);
	return(i);
};

Bit32u compare_with_sequence_array_222BD3(char* filename, Bit8u* adress, Bit32u adressdos, Bit32u count, Bit32u size, Bit8u* origbyte, Bit8u* copybyte, int* posdiff) {

	char findnamec[500];
	Bit8u* buffer = (Bit8u*)malloc(size);
	FILE* fptestepc;
	sprintf(findnamec, "c:/prenos/dosbox-x-remc2/vs2015/sequence-%s.bin", filename);
	fptestepc=fopen(findnamec, "rb");
	if (fptestepc == NULL)
	{
		mydelay(100);
		fptestepc=fopen(findnamec, "rb");
	}
	fseek(fptestepc, count*size, SEEK_SET);

	fread(buffer, size, 1, fptestepc);
	Bit32u i;
	bool testa, testb;
	int diffindex = 0;
	for (i = 0; i < size; i++)
	{
		int testx = test_222BD3_id_pointer(i);
		if (testx == 1)
		{
			if (*(Bit32u*)&buffer[i])testa = true;
			else testa = false;
			if (*(Bit32u*)&adress[i])testb = true;
			else testb = false;
			if (testa != testb)
			{
				posdiff[diffindex] = i;
				origbyte[diffindex] = buffer[i];
				copybyte[diffindex++] = adress[i];
				if (diffindex >= 100)break;
			}
			i += 3;
		}
		else if (testx == 0) {
			if (buffer[i] != adress[i])
			{
				posdiff[diffindex] = i;
				origbyte[diffindex] = buffer[i];
				copybyte[diffindex++] = adress[i];
				if (diffindex >= 100)break;
			}
		}
	}

	free(buffer);
	fclose(fptestepc);
	return(i);
};

Bit32u compare_with_sequence(char* filename, Bit8u* adress, Bit32u adressdos, long count, long size1, Bit32u size2, Bit8u* origbyte, Bit8u* copybyte,long offset) {

	char findnamec[500];
	Bit8u* buffer = (Bit8u*)malloc(size2);
	FILE* fptestepc;
	sprintf(findnamec, "c:/prenos/dosbox-x-remc2/vs2015/sequence-%s.bin", filename);
	fptestepc=fopen(findnamec, "rb");
	if (fptestepc == NULL)
	{
		mydelay(100);
		fptestepc=fopen(findnamec, "rb");
	}

#ifdef __linux__
	fseek(fptestepc, (long long)count* (long long)size1+ offset, SEEK_SET);
#else
	_fseeki64(fptestepc, (long long)count* (long long)size1+ offset, SEEK_SET);
#endif
	
	Bit32u i;
	/*for (i = 0; i < count; i++)
	{
		fread_s(buffer,size,1,size, fptestepc);
	}*/

	fread(buffer, size2, 1, fptestepc);
	//for (i = size-1; i >0; i--)
	for (i = 0; i < size2; i++)
	{
		if (buffer[i] != adress[i])
		{
			*origbyte = buffer[i];
			*copybyte = adress[i];
			break;
		}
	}	

	free(buffer);
	fclose(fptestepc);
	if (i < size2)
		allert_error();
	return(i);
};

int countcompindexes = 0;
typedef struct {
	int index;
	int adress;
} type_compstr;

type_compstr compstr[100];
int getcompindex(Bit32u adress) {
	bool finded = false;
	int findindex=0;
	for (int i = 0; i < countcompindexes; i++)
	{
		if (compstr[i].adress == adress)
		{
			finded = true;
			findindex = i;
			break;
		}
	}
	if (finded)
	{
		compstr[findindex].index++;
		return compstr[findindex].index;
	}
	else
	{
		compstr[countcompindexes].adress = adress;
		countcompindexes++;
		return 0;
	}
};

type_compstr lastcompstr;
void add_compare(Bit32u adress,bool debugafterload,int stopstep,bool skip) {


	Bit8u origbyte20 = 0;
	Bit8u remakebyte20 = 0;
	int comp20;

	char buffer1[500];
	sprintf(buffer1,"%08X-002DC4E0", adress);
	char buffer2[500];
	sprintf(buffer2, "%08X-00356038", adress);
	char buffer3[500];
	sprintf(buffer3, "%08X-002B3A74", adress);
	char buffer4[500];
	sprintf(buffer4, "%08X-003AA0A4", adress);


	if (debugafterload)
	{
		int index = getcompindex(adress);
		if (index >= stopstep)
		{
			if (!skip)
			{
				comp20 = compare_with_sequence(buffer1, (Bit8u*)x_BYTE_10B4E0_terraintype, 0x2dc4e0, index, 0x70000, 0x10000, &origbyte20, &remakebyte20);
				comp20 = compare_with_sequence(buffer1, (Bit8u*)x_BYTE_11B4E0_height, 0x2dc4e0, index, 0x70000, 0x10000, &origbyte20, &remakebyte20, 0x10000);
				comp20 = compare_with_sequence(buffer1, (Bit8u*)x_BYTE_12B4E0_shading, 0x2dc4e0, index, 0x70000, 0x10000, &origbyte20, &remakebyte20, 0x20000);
				comp20 = compare_with_sequence(buffer1, (Bit8u*)x_BYTE_13B4E0_angle, 0x2dc4e0, index, 0x70000, 0x10000, &origbyte20, &remakebyte20, 0x30000);
				comp20 = compare_with_sequence(buffer1, (Bit8u*)x_WORD_15B4E0_source, 0x2dc4e0, index, 0x70000, 0x20000, &origbyte20, &remakebyte20, 0x50000);

				comp20 = compare_with_sequence_D41A0(buffer2, (Bit8u*)& D41A0_BYTESTR_0, 0x356038, index, 0x36e16, &origbyte20, &remakebyte20);

				comp20 = compare_with_sequence_array_E2A74(buffer3, (Bit8u*)& str_E2A74, 0x2b3a74, index, 0xc4e, 0xc4e, &origbyte20, &remakebyte20);
			}
		if (stopstep > -1)
		{
			comp20 = index;
		}

		lastcompstr.index = index;
		lastcompstr.adress = adress;

	}

	}
};

void mine_texts(char* filename, Bit32u adressdos, Bit32u count, char* outfilename) {

	char findnamec[500];
	FILE* fptestepc;
	FILE* fileout;
	char actchar;
	char outtext[2048];
	char outtext2[2048];
	sprintf(findnamec, "c:/prenos/dosbox-x-remc2/vs2015/engine-memory-%s", filename);
	fptestepc=fopen(findnamec, "rb");
	fileout=fopen(outfilename, "wb");
	if (fptestepc == NULL)
	{
		mydelay(100);
		fptestepc=fopen(findnamec, "rb");
	}
	fseek(fptestepc, adressdos, SEEK_SET);
	long adressadd;
	long adressaddall=0;
	fread(&actchar, 1,1, fptestepc);
	for (Bit32u i = 0; i < count; i++)
	{
		adressadd = 0;
		while ((adressaddall % 4)||(actchar==0))
		{
			fread(&actchar, 1,1, fptestepc);
			adressaddall++;
		}
		while(actchar!=0){
			outtext[adressadd] = actchar;
			fread(&actchar, 1,1, fptestepc);
			adressadd++;
			adressaddall++;
		}
		
		outtext[adressadd]=0;
		sprintf(outtext2,"char* off_%05X[1]={%s};\n", 0xDB06C- 0x1131 + adressaddall,outtext);
		if(strlen(outtext2)>1)
			fwrite(outtext2, strlen(outtext2),1, fileout);
	}

	fclose(fptestepc);
	fclose(fileout);
};

void writehex(Bit8u* buffer, Bit32u count) {
	for (Bit32u i=0;i < count;i++)
	{
		if (i % 32 == 0)printf("\n");
		printf("%02X", buffer[i]);		
	}
	printf("\n");
};

type_D41A0_BYTESTR_0 D41A0_BYTESTR_0;

inline void setRGBA(png_byte *ptr, Bit8u* val)
{	
		ptr[0] = val[0];
		ptr[1] = val[1];
		ptr[2] = val[2];
		ptr[3] = val[3];	
}

int writeImage(char* filename, int width, int height, Bit8u *buffer, char* title)
{
	int code = 0;
	FILE *fp = NULL;
	png_structp png_ptr = NULL;
	png_infop info_ptr = NULL;
	png_bytep row = NULL;

	// Open file for writing (binary mode)
	fp = fopen(filename, "wb");
	if (fp == NULL) {
		fprintf(stderr, "Could not open file %s for writing\n", filename);
		code = 1;
		goto finalise;
	}

	// Initialize write structure
	png_ptr = png_create_write_struct(PNG_LIBPNG_VER_STRING, NULL, NULL, NULL);
	if (png_ptr == NULL) {
		fprintf(stderr, "Could not allocate write struct\n");
		code = 1;
		goto finalise;
	}

	// Initialize info structure
	info_ptr = png_create_info_struct(png_ptr);
	if (info_ptr == NULL) {
		fprintf(stderr, "Could not allocate info struct\n");
		code = 1;
		goto finalise;
	}

	// Setup Exception handling
	if (setjmp(png_jmpbuf(png_ptr))) {
		fprintf(stderr, "Error during png creation\n");
		code = 1;
		goto finalise;
	}

	png_init_io(png_ptr, fp);

	// Write header (8 bit colour depth)
	png_set_IHDR(png_ptr, info_ptr, width, height,
		8, PNG_COLOR_TYPE_RGBA, PNG_INTERLACE_NONE,
		PNG_COMPRESSION_TYPE_BASE, PNG_FILTER_TYPE_BASE);

	// Set title
	if (title != NULL) {
		png_text title_text;
		title_text.compression = PNG_TEXT_COMPRESSION_NONE;
		title_text.key = (png_charp)"Title";
		title_text.text = title;
		png_set_text(png_ptr, info_ptr, &title_text, 1);
	}

	png_write_info(png_ptr, info_ptr);

	// Allocate memory for one row (3 bytes per pixel - RGB)
	row = (png_bytep)malloc(4 * width * sizeof(png_byte));

	// Write image data
	int x, y;
	for (y = 0; y < height; y++) {
		for (x = 0; x < width; x++) {
			setRGBA(&(row[x * 4]), buffer+(y*width + x)*4);
		}
		png_write_row(png_ptr, row);
	}

	// End write
	png_write_end(png_ptr, NULL);

finalise:
	if (fp != NULL) fclose(fp);
	if (info_ptr != NULL) png_free_data(png_ptr, info_ptr, PNG_FREE_ALL, -1);
	if (png_ptr != NULL) png_destroy_write_struct(&png_ptr, (png_infopp)NULL);
	if (row != NULL) free(row);

	return code;
}


const int bytesPerPixel = 4; /// red, green, blue
const int fileHeaderSize = 14;
const int infoHeaderSize = 40;


unsigned char* createBitmapFileHeader(int height, int width, int pitch, int paddingSize) {	
	int fileSize = fileHeaderSize + infoHeaderSize + (/*bytesPerPixel*width*/pitch + paddingSize) * height;

	static unsigned char fileHeader[] = {
		0,0, /// signature
		0,0,0,0, /// image file size in bytes
		0,0,0,0, /// reserved
		0,0,0,0, /// start of pixel array
	};

	fileHeader[0] = (unsigned char)('B');
	fileHeader[1] = (unsigned char)('M');
	fileHeader[2] = (unsigned char)(fileSize);
	fileHeader[3] = (unsigned char)(fileSize >> 8);
	fileHeader[4] = (unsigned char)(fileSize >> 16);
	fileHeader[5] = (unsigned char)(fileSize >> 24);
	fileHeader[10] = (unsigned char)(fileHeaderSize + infoHeaderSize);

	return fileHeader;
}

unsigned char* createBitmapInfoHeader(int height, int width) {
	static unsigned char infoHeader[] = {
		0,0,0,0, /// header size
		0,0,0,0, /// image width
		0,0,0,0, /// image height
		0,0, /// number of color planes
		0,0, /// bits per pixel
		0,0,0,0, /// compression
		0,0,0,0, /// image size
		0,0,0,0, /// horizontal resolution
		0,0,0,0, /// vertical resolution
		0,0,0,0, /// colors in color table
		0,0,0,0, /// important color count
	};

	infoHeader[0] = (unsigned char)(infoHeaderSize);
	infoHeader[4] = (unsigned char)(width);
	infoHeader[5] = (unsigned char)(width >> 8);
	infoHeader[6] = (unsigned char)(width >> 16);
	infoHeader[7] = (unsigned char)(width >> 24);
	infoHeader[8] = (unsigned char)(height);
	infoHeader[9] = (unsigned char)(height >> 8);
	infoHeader[10] = (unsigned char)(height >> 16);
	infoHeader[11] = (unsigned char)(height >> 24);
	infoHeader[12] = (unsigned char)(1);
	infoHeader[14] = (unsigned char)(bytesPerPixel * 8);

	return infoHeader;
}

void writeImageBMP(char* imageFileName, int width, int height, Bit8u* image)
{
	int pitch = bytesPerPixel * width;
		unsigned char padding[3] = { 0, 0, 0 };
		int paddingSize = (4 - (/*width*bytesPerPixel*/ pitch) % 4) % 4;

		unsigned char* fileHeader = createBitmapFileHeader(height, width, pitch, paddingSize);
		unsigned char* infoHeader = createBitmapInfoHeader(height, width);

		FILE* imageFile = fopen(imageFileName, "wb");

		fwrite(fileHeader, 1, fileHeaderSize, imageFile);
		fwrite(infoHeader, 1, infoHeaderSize, imageFile);

		int i;
		for (i = 0; i < height; i++) {
			fwrite(image + (i * pitch /*width*bytesPerPixel*/), bytesPerPixel, width, imageFile);
			fwrite(padding, 1, paddingSize, imageFile);
		}

		fclose(imageFile);
		//free(fileHeader);
		//free(infoHeader);
}


void write_posistruct_to_png(Bit8u* buffer,int width, int height, char* filename) {
	png_bytep row = NULL;

	Bit8u pallettebuffer[768];
	FILE* palfile;
	palfile=fopen("c:\\prenos\\remc2\\tools\\palletelight\\Debug\\out-n.pal", "rb");
	fread(pallettebuffer, 768, 1, palfile);
	fclose(palfile);

	Bit8u buffer2[10000*4];
	for (int i = 0; i < width* height; i++)
	{
		buffer2[i * 4 + 0] = pallettebuffer[buffer[(width * height) - 1 - i] * 3+2];
		buffer2[i * 4 + 1] = pallettebuffer[buffer[(width * height) - 1 - i] * 3+1];
		buffer2[i * 4 + 2] = pallettebuffer[buffer[(width * height) - 1 - i] * 3];

		if (buffer[(width * height) - 1 - i] != 0xff)buffer2[i * 4 + 3]=255;
	}
	writeImageBMP(filename, width, height, buffer2);
}

void buff_posistruct_to_png(Bit8u* buffer, int width, int height, char* filename) {
	png_bytep row = NULL;
	Bit8u pallettebuffer[768];
	FILE* palfile;
	palfile=fopen("c:\\prenos\\remc2\\testpal.pal", "rb");
	fread(pallettebuffer, 768, 1, palfile);
	fclose(palfile);

	Bit8u buffer2[10000 * 4];
	for (int i = 0; i < 10000; i++)
	{
		buffer2[i * 4 + 0] = pallettebuffer[buffer[i] * 3];
		buffer2[i * 4 + 1] = pallettebuffer[buffer[i] * 3 + 1];
		buffer2[i * 4 + 2] = pallettebuffer[buffer[i] * 3 + 2];


		if (buffer[i] != 0xff)buffer2[i * 4 + 3] = 255;
	}
	writeImage(filename, width, height, buffer2, (char*)"test");
}


void testdword(Bit32s* val1, Bit32s* val2) {
	if (*val1 != *val2)
	{
		printf("x_D41A0_BYTEARRAY_0_error");
		//allert_error();
		//exit(0);
	}
}

void testcbyte(int count,Bit8u* val1, Bit8u* val2) {
	for(int i=0;i<count;count++)
	if (val1[i] != val2[i])
	{
		printf("x_D41A0_BYTEARRAY_0_error");
		//allert_error();
		//exit(0);
	}
}

void testword(Bit16s* val1, Bit16s* val2) {
	if (*val1 != *val2)
	{
		printf("x_D41A0_BYTEARRAY_0_error");
	}
}

void testbyte(Bit8u* val1, Bit8u* val2) {
	if (*val1 != *val2)
	{
		printf("x_D41A0_BYTEARRAY_0_error");
	}
}

void clean_x_D41A0_BYTEARRAY_0_0x2362() {
	for (int i=0; i < 8; i++)
	{
		D41A0_BYTESTR_0.array_0x2362[i].x = 0;
		D41A0_BYTESTR_0.array_0x2362[i].y = 0;
		D41A0_BYTESTR_0.array_0x2362[i].z = 0;
	}

};

void clean_x_D41A0_BYTEARRAY_0_0x2BDE(int number) {
	memset((void*)(&D41A0_BYTESTR_0.array_0x2BDE[number]), 0, 2124);
};

void errorsize(int type,int size)
{
	printf("Test x_D41A0_BYTEARRAY_0 %d %X ERROR\n",type,size);
}

int my_sign32(Bit32s var)
{
	if (var < 0)return -1;
	return 0;
}

int my_sign16(Bit16s var)
{
	return my_sign32(var);
}
