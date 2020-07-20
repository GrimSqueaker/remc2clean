#include <stdio.h>
#include <assert.h>
#include <sstream>
#include <stddef.h>
#include <stdarg.h>     /* va_list, va_start, va_arg, va_end */

#include "png.h"
#pragma comment(lib, "zlib.lib") // must be before libpng!
#ifndef _WIN64
#pragma comment(lib, "libpng15.lib") // must be after zlib!
#else
#endif

#include"../portability/port_time.h"

#include "../portability/port_sdl_vga_mouse.h"
#include "../portability/mctypes.h"
//#define USE_DOSBOX


#include "file_handling.h"
using namespace remc2;

#ifndef ENGINE_SUPPORT_ACTIVE
#define ENGINE_SUPPORT_ACTIVE

void allert_error();

extern Bit8u* readbuffer;
extern char* printbuffer;//char* buffer; // [esp+0h] [ebp-2h]
extern char* printbuffer2;//char v11; // [esp+40h] [ebp+3Eh]


extern Bit8u* off_D41A8_sky;
extern Bit8u* x_BYTE_14B4E0;

#pragma pack (1)
typedef struct {
	Bit8u byte1;
	Bit8u byte2;
}doublebyte;

typedef struct {
	doublebyte dbyte1_2;
	doublebyte dbyte3_4;
}tetrabytebyte;

typedef struct {
	Bit16u x;
	Bit16u y;	
}axis_2du;

typedef struct {
	Bit16s x;
	Bit16s y;
}axis_2d;

typedef struct {
	Bit32s x;
	Bit32s y;
}axis_2d_32;

typedef struct {
	Bit16u x;
	Bit16u y;
	Bit16u z;
}axis_3d;

typedef struct {
	Bit16s aa;
	Bit16s xshift;
	Bit16s yshift;
	Bit16s dd;
}axis_4d;

typedef struct {
	Bit8u x;
	Bit8u y;
} baxis_2d;

typedef union {
	baxis_2d _axis_2d;
	Bit16u word;
}
uaxis_2d;

typedef struct {
	Bit8s str_0x6E3E_byte0;//0x6E3E-28222//D41A0_BYTESTR_0.array_0x6E3E[xx].str_0x6E3E_byte0
	Bit8s str_0x6E3E_byte1;//0x6E3F-28223
	Bit8s str_0x6E3E_byte2;//0x6E40-28224
	Bit8s str_0x6E3E_byte3;//0x6E41-28225
	Bit8s str_0x6E3E_byte4;//0x6E42-28226
	Bit8s str_0x6E3E_byte5;//0x6E43-28227
	Bit16u str_0x6E3E_word6;//0x6E44-28228
	Bit16u str_0x6E3E_word8;//0x6E46-28230
}type_str_0x6E3E;
/*
3-bit-28225
4-bit-28226
5-bit-28227
6-2bit-28228
8-2bit-28230
*/

typedef struct {
	Bit8u byte[0x1a];
}
type_8_1a;

typedef struct {
	Bit16s word[0x1a];
}
type_16_1a;

typedef struct {
	Bit32s dword[0x1a];
}
type_32_1a;


typedef union {
	Bit8u byte[4];
	Bit16u word[2];
	Bit32u dword;
}
dw_w_b;
typedef struct {//begin 611//str_611
	type_32_1a array_0x263_611x;//size??//dword_0x649_2BDE
	type_32_1a array_0x2CB_715x;//104//size??
	type_16_1a array_0x333_819x;//208//size?? spells//word_0x719_2BDE
	type_16_1a array_0x367_871x;//260//ok
	type_8_1a array_0x39B_923x;//312//size??//byte_0x781_2BDE
	type_8_1a array_0x3B5_949x;//338//size??//array_0x79B_2BDE_13177
	type_8_1a array_0x3CF_975x;//364//byte_0x7B5_2BDE
	type_8_1a array_0x3E9_1001x;//390//size??//array_0x7CF_2BDE_13229
	type_8_1a array_0x403_1027x;//416//size??//byte_0x7E9_2BDE
	type_8_1a array_0x41D_1053z;//442//size??//byte_0x803_2BDE
	type_8_1a array_0x437_1079x;//468//size?? //table of spell indexes//byte_0x81D_2BDE
	Bit16s word_0x451_1105;//494 act left spell index//word_0x837_2BDE
	Bit16s word_0x453_1107;//496 act right spell index//word_0x839_2BDE
	Bit8s byte_0x455_1109;//498
	Bit8s byte_0x456_1110;//499
	Bit8s byte_0x457_1111;//500//byte_0x83D_2BDE //select spell/type spell
	Bit8s byte_0x458_1112;//501//byte_0x83E_2BDE
	Bit8s byte_0x459_1113;//502
	Bit8s byte_0x45A_1114;
	Bit8s byte_0x45B_1115;	
}
type_str_611;

typedef struct {//lenght 18
	Bit16s word_0;
	Bit16s word_2BDE_12658[8];
}type_str_0x1AC_428;

typedef struct {//size 1136
	Bit32s dword_0x0_0;
	Bit16s word_0x4_4;
	Bit16s word_0x6_6;
	Bit8u stuba[4];
	Bit16s word_0xc_12;//final speed
	Bit16s word_0xe_14;
	Bit16s word_0x10_16;
	Bit8u stubb[2];
	axis_2d position_backup_20;//position //mouse backup
	Bit16s word_0x18_24_next_entity;
	Bit16s word_0x1A_26;
	Bit8u stubc[2];
	Bit16s word_0x1E_30;
	Bit16s word_0x20_32;
	Bit16s word_0x22_34;
	Bit16s word_0x24_36;
	Bit16s word_0x26_38[8];
	Bit16s word_0x36_54;
	Bit16s word_0x38_56;
	Bit16s word_0x3A_58;
	Bit16u array_0x3C_60[16];//size??
	Bit16u array_0x5C_92[16];
	Bit8u stubd[174];
	Bit32s dword_0x12A_298;
	Bit32s dword_0x12E_302;
	Bit8u stube[10];
	Bit32s dword_0x13C_316;
	Bit8u stubf[2];
	Bit32s dword_0x142_322;
	Bit16s word_0x146_326;
	Bit16s word_0x148_328;
	Bit16s word_0x14A_330;
	Bit8u byte_0x14C_332;
	Bit8s byte_0x14D_333;
	Bit8s byte_0x14E_334;
	Bit8s byte_0x14F_335;
	Bit32s byte_0x150_336;
	Bit8u byte_0x154_340;
	Bit16s word_0x155_341;
	Bit16s word_0x157_343;
	Bit16s word_0x159_345;
	Bit8s array_0x15B_347[8];
	Bit16s word_0x163_355;
	Bit32s dword_0x165_357;
	Bit32s dword_0x169_361;
	Bit32s dword_0x16D_365;
	Bit8u stubg[4];
	Bit32s dword_0x175_373;
	Bit32s dword_0x179_377;
	Bit32s dword_0x17D_381;
	Bit32s dword_0x181_385;
	Bit32s dword_0x185_389;
	Bit32s dword_0x189_393;//clock
	Bit32s dword_0x18D_397;
	Bit8u stubi[4];
	Bit8s byte_0x195_405;
	Bit8s byte_0x196_406;
	Bit8s byte_0x197_407;
	Bit8u stubj[2];
	Bit32s dword_0x19A_410;
	Bit32s dword_0x19E_414;
	Bit16s word_0x1A2_418;
	Bit16s word_0x1A4_420;
	Bit16s word_0x1A6_422;//211 x add
	Bit16s word_0x1A8_424;//212 y add
	Bit16s word_0x1AA_426;//213 z add
	type_str_0x1AC_428 str_0x1AC_428;
	Bit8s byte_0x1BE_446;
	Bit8s byte_0x1BF_447;
	Bit8s byte_0x1C0_448;
	Bit8s byte_0x1C1_449;//switch - event? type?
	Bit16s word_0x1C2_450;
	Bit8u stubl[56];
	Bit16u array_0x1FC_508[32];//1ca
	Bit8u stubm[6];
	Bit16s word_0x242_578=-1;
	Bit16s word_0x244_580;
	Bit16s word_0x246_582;
	Bit16s word_0x248_584;
	Bit16s word_0x24A_586;
	Bit16s word_0x24C_588;
	Bit8s array_0x24E_590[10];//size??
	Bit8u stubn[9];
	Bit8s byte_0x261_609;
	Bit8s byte_0x262_610;
	type_str_611 str_611;

	Bit8s str_611_byte_0x45C_1116;
	Bit8s str_611_byte_0x45D_1117;
	Bit8s str_611_byte_0x45E_1118;
	Bit8s str_611_byte_0x45E_1119;
}
type_str_164;

typedef struct {//lenght 34
	Bit8u stub[2];
	Bit16s word_160_0x2_2;
	Bit16s word_160_0x4_4;
	Bit16s word_160_0x6_6;
	Bit16s word_160_0x8_8;
	Bit16s word_160_0xa_10;
	Bit16s word_160_0xc_12;
	Bit16s word_160_0xe_14;
	Bit16s word_160_0x10_16;//->dword_0xA0_160x->word_160_0x10_16
	Bit16s word_160_0x12_18;
	Bit32s dword_160_0x14_20;
	Bit8u stuba[2];
	Bit16s word_160_0x1a_26;
	Bit16s word_160_0x1c_28;
	Bit16s word_160_0x1e_30;
	Bit8s byte_160_0x20_32;
	Bit8u stubb[1];
}
type_str_160;

//viz. unk_D7BD6

typedef struct
{
	Bit32s dword_0x5E_94;//94 //36 lenght
	Bit16s word_0x62_98;//98 //4 // index subentity
	Bit32s dword_0x64_100;//100 //6
	Bit16s word_0x68_104;//104 //10
	Bit8u stub5b[6];
	Bit32s dword_0x70_112;//112
	Bit16s word_0x74_116;//116
	Bit16s word_0x76_118;//118
	Bit16s word_0x78_120;//120
	Bit16s word_0x7A_122;//122
	Bit16s word_0x7C_124;//124
	Bit8u stub5d[2];
	Bit16u word_0x80_128;//128
} type_str_0x5E_94;

typedef struct _str_0x6E8E {//lenght a8//THING
	struct _str_0x6E8E* next_0;
	Bit32s dword_0x4;//4 //?bitmap//LIVE
	Bit32s dword_0x8;//8 // this is Bit32s ?bitmap//MAX LIVE
	dw_w_b struct_byte_0xc_12_15;//12
	//12//struct_byte_0xc_12_15.dbyte1_2.byte1
	//0xfe - all spell
	Bit32s dword_0x10_16;//16 // index of array
	Bit16u word_0x14_20;//20 //random seed adress
	Bit16u word_0x16_22;//22
	Bit16u word_0x18_24_next_entity;//24 //next entity index
	Bit16u word_0x1A_26;//26 // index - owner //ID last index
	Bit16s word_0x1C_28;//28//rotate1
	Bit16s word_0x1E_30;//30//rotate2
	Bit16s word_0x20_32;//32//rotate3
	//Bit8s byte_0x21_33;//33
	Bit16s word_0x22_34;//34//rotate4
	Bit16s word_0x24_36;//36 // index subentity
	Bit16s word_0x26_38;//38 // index subentity
	Bit16u word_0x28_40;//40//WHO OWNS ME
	Bit16u word_0x2A_42;//42 //maybe Bit16s
	Bit16s word_0x2C_44;//44 //add to z
	Bit16s word_0x2E_46;//46
	Bit16u word_0x30_48;//48
	Bit16u word_0x32_50;//50
	Bit16u word_0x34_52;//52 // index subentity
	Bit16u word_0x36_54;//54
	Bit8s byte_0x38_56;//56
	Bit8s byte_0x39_57;//57
	Bit8s byte_0x3A_58;//58
	Bit8s byte_0x3B_59;//59
	Bit8s byte_0x3C_60;//60
	Bit8s byte_0x3D_61;//61
	Bit8u byte_0x3E_62;//62 //index
	Bit8s byte_0x3F_63;//63 //type//MODEL
	//11 - spell
	Bit8s byte_0x40_64;//64 //subtype//CLASS
	//0 or 1 - player, 2 - castle,3-ballon
	Bit8s byte_0x41_65;//65 //type subentity
	Bit8s byte_0x42_66;//66 //subtype subentity
	Bit8s byte_0x43_67;//67
	Bit8s byte_0x44_68;//68	
	Bit8u byte_0x45_69;//69 // index of structure with lenght 14//STATE-
	Bit8s byte_0x46_70;//70 // index of bitmap // index of ending sequence
	Bit8s byte_0x47_71_xx;//71
	Bit8s byte_0x48_72;//72
	Bit8s byte_0x49_73;//70
	Bit16s word_0x4A_74;
	axis_3d array_0x4C_76;//position//ACTUAL X Y Z
	axis_4d array_0x52_82;
	Bit16s word_0x5A_90;
	Bit8s byte_0x5C_92;
	Bit8s byte_0x5D_93;
	type_str_0x5E_94 str_0x5E_94;
	

	Bit16s word_0x82_130;//130 //add to z//ACTUAL SPEED
	Bit16s word_0x84_132;//132//MIN SPEED
	Bit16s word_0x86_134;//134//MAX SPEED
	Bit32s dword_0x88_136;//136
	Bit32s dword_0x8C_140;//140 //wiz name?//ACTUAL MANA
	Bit32s dword_0x90_144;//144 0-1000//MAX MANA
	Bit16u word_0x94_148;//148
	Bit16s word_0x96_150;//150 // index subentity
	Bit16u word_0x98_152;//152
	axis_3d word_0x9A_154x;//154
	type_str_160* dword_0xA0_160x;//160 //special settings
	type_str_164* dword_0xA4_164x;//100 // adress of xx
}
type_str_0x6E8E;
/*
	entite
	8-dead
	26-index
	64-type
		1-player
		2-castle
		3-ballon
	144-mana
*/



typedef struct {
	Bit32s dword[0x1a];
}
type_dword_0x649_2BDE;


typedef struct { // 479 // size 14 tj 0xe
	axis_3d axis_2BDE_11695;//11709 0 2 4
	axis_4d rotation__2BDE_11701;//_2BDE_11715 6 8 10 12 //aa
} type_struct_0x1d1_2BDE_11695;

typedef struct {//lenght 2124=0x84C
	dw_w_b dw_w_b_0_2BDE_11230;
	Bit8u byte_0x004_2BE0_11234;//2	//11234 - byte //4
	Bit8u byte_0x005_2BE0_11235;//5
	Bit8u byte_0x006_2BE4_11236;//6	//11236 - byte //6
	Bit16s word_0x007_2BE4_11237;//index of player
	Bit8s byte_0x009_2BE4_11239;
	Bit16u word_0x00a_2BE4_11240;//10 //11240 - word - index z EA3E4 //0xa
	Bit8u byte_0x00c_2BE0_11242_xx;
	Bit8u byte_0x00d_2BE0_11243_xx;
	Bit16s word_0x00e_2BDE_11244; //14
	Bit16s word_0x010_2BDE_11246; //16	
	Bit32s dword_0x012_2BE0_11248;//18 ??

	Bit8u byte_0x016_2BE0_11252_xx;//22
	Bit8u byte_0x017_2BE0_11253_xx;//23	
	Bit32s dword_0x018_2BDE_11254; //24 //pointer
	char array_0x01c_2BFA_11258[49];//28//11258 - byte* jmeno2?
	Bit16s word_0x04d_2C2B_11307;//77 //11307 - word
	Bit16u word_0x04f_2C2D_11309;//79 //11309 - word
	char names_81[8][48];//81 ?8

	type_struct_0x1d1_2BDE_11695 struct_0x1d1_2BDE_11695[0x21];//465

	char array_0x39f_2BFA_12157[0x40];//927//12157 - byte(11230+927) 100% name
	Bit8u byte_0x3DF_2BE4_12221;//991//12221 - byte
	Bit8u byte_0x3E0_2BE4_12222;//992//12222 - byte
	Bit8u byte_0x3E1_2BE4_12223;//993//12223 - byte - ok
	Bit8u byte_0x3E2_2BE4_12224;//994//12224 - byte
	Bit8u byte_0x3E3_2BE4_12225;//995
	Bit8u byte_0x3E4_2BE4_12226;//996
	Bit8u stub3[1];
	type_str_164 dword_0x3E6_2BE4_12228;//998//pointer or other	

	Bit8s byte_0x846_2BDE;//2118
	Bit8s byte_0x847_2BDE;//2119
	Bit16s word_0x848_2BDE;//2120
	Bit16s word_0x84A_2BDE;//2122
} type_str_0x2BDE;//11230 // 84c lenght


typedef struct {
	Bit8u* data_0;
	uint32_t data_4;
	uint16_t data_8;
	int16_t data_10;
	int16_t data_12;
} type_x_DWORD_E9C28_data;

typedef struct {//size 26
	Bit32s dword_0;
	Bit32s dword_4;
	//Bit8u* dword_8_data;  // points to data[], data is indexed in 14-byte steps
	Bit32u* dword_12x;
	Bit32u* dword_16x;
	Bit16s word_20;
	Bit16s word_22;       // stores number of entries in dword_8_data
	Bit16s word_24;
	//Bit8u data[];
	std::vector<type_x_DWORD_E9C28_data> data;
} type_x_DWORD_E9C28_str;


typedef struct {
	Bit32u dwordindex_0;//x_D41A0_BYTEARRAY_4_struct.dwordindex_0
	Bit16u wordindex_4;//x_D41A0_BYTEARRAY_4_struct.byteindex_4
	Bit16u wordindex_6;//x_D41A0_BYTEARRAY_4_struct.wordindex_6
	Bit16u wordindex_8;//x_D41A0_BYTEARRAY_4_struct.wordindex_8
	Bit8u byteindex_10;//0xa//x_D41A0_BYTEARRAY_4_struct.byteindex_10//show help
	Bit8s byte_brightness_11;//0xb//x_D41A0_BYTEARRAY_4_struct.byteindex_11
	Bit8s byte_brightness_12;//0xc//x_D41A0_BYTEARRAY_4_struct.byteindex_12
	Bit8s byte_brightness_13;//0xd//x_D41A0_BYTEARRAY_4_struct.byteindex_13
	Bit16u wordindex_14;
	Bit32u dwordindex_16;//0x10//x_D41A0_BYTEARRAY_4_struct.dwordindex_16	
	Bit8u stubb[2];
	Bit8u setting_byte1_22;//x_D41A0_BYTEARRAY_4_struct.setting_byte1_22
	Bit8s setting_byte2_23;//0x17//x_D41A0_BYTEARRAY_4_struct.setting_byte2_23
	Bit8u setting_byte3_24;//cheats? 0x20==free spell//x_D41A0_BYTEARRAY_4_struct.setting_byte3_24
	//spell on - 0x20
	Bit8u setting_byte4_25;//cheats? 0x1==Invincability
	//invincability - 1;
	Bit8u byteindex_26=0;//x_D41A0_BYTEARRAY_4_struct.byteindex_26
	Bit8u stubc[3];
	Bit8u setting_30;//x_D41A0_BYTEARRAY_4_struct.setting_30
	Bit8u stubd[3];
	//FILE* moviemvidatfile_byte4_33;
	Bit8u byteindex_34;//0x22//x_D41A0_BYTEARRAY_4_struct.byteindex_34
	FILE* moviemvidatfile_byte4_35;
	Bit16u moviemvinumber_byte4_39;//x_D41A0_BYTEARRAY_4_struct.moviemvinumber_byte4_39
	Bit8u stube[2];
	Bit16u levelnumber_43w;//x_D41A0_BYTEARRAY_4_struct.levelnumber_43
	//Bit8u stubf[1];
	Bit16u setting_45w;
	Bit8u stubg[3];
	Bit8s byteindex_50;//0x32//x_D41A0_BYTEARRAY_4_struct.byteindex_50
	Bit8u byteindex_51;//0x33//x_D41A0_BYTEARRAY_4_struct.byteindex_51
	Bit8u byteindex_52;//0x34//x_D41A0_BYTEARRAY_4_struct.byteindex_52
	Bit8u byteindex_53;//0x35//x_D41A0_BYTEARRAY_4_struct.byteindex_53
	Bit8u stubh[3];
	char player_name_57ar[32];
	char savestring_89[32];
	Bit8u byteindex_121[16];//0x79//x_D41A0_BYTEARRAY_4_struct.byteindex_121
	Bit8u stubi[8];
	char byteindex_145ar[32];//x_D41A0_BYTEARRAY_4_struct.byteindex_145ar

	Bit8u byteindex_177;//0xb1//x_D41A0_BYTEARRAY_4_struct.byteindex_177
	Bit8u byteindex_178;//0xb2//x_D41A0_BYTEARRAY_4_struct.byteindex_178
	Bit8u byteindex_179;
	Bit8u byteindex_180;//0xb4//x_D41A0_BYTEARRAY_4_struct.byteindex_180
	Bit8u byteindex_181;//0xb5//x_D41A0_BYTEARRAY_4_struct.byteindex_181
	Bit8u harddiskchar_byte4_182;
	Bit8u byteindex_183;//0xb7//x_D41A0_BYTEARRAY_4_struct.byteindex_183
	Bit16u byteindex_184w;//0xb8//x_D41A0_BYTEARRAY_4_struct.byteindex_184
	//Bit8u stubj[1];
	Bit8u byteindex_186;//0xba//x_D41A0_BYTEARRAY_4_struct.byteindex_186
	Bit8u stubk[1];
	Bit32u dwordindex_188;//x_D41A0_BYTEARRAY_4_struct.byteindex_188
						  
	Bit32u dwordindex_192;//0xc0//x_D41A0_BYTEARRAY_4_struct.byteindex_192

	Bit8u byteindex_196;//0xc4//x_D41A0_BYTEARRAY_4_struct.byteindex_196
	Bit8u stubl[3];
	Bit8u transfer_rate_dwordindex_200;//0xc8//x_D41A0_BYTEARRAY_4_struct.transfer_rate_dwordindex_200
	Bit8u stubm[3];
	Bit8u byteindex_204;//0xCC//x_D41A0_BYTEARRAY_4_struct.byteindex_204
	Bit8u byteindex_205;//0xCD//x_D41A0_BYTEARRAY_4_struct.byteindex_205
	Bit8u byteindex_206;//0xce//x_D41A0_BYTEARRAY_4_struct.byteindex_206
	Bit8u byteindex_207;//0xcf//x_D41A0_BYTEARRAY_4_struct.byteindex_207
	Bit8u byteindex_208;//0xd0//x_D41A0_BYTEARRAY_4_struct.byteindex_208
	Bit8u stubmm[1];
	Bit32u byteindex_210d;//0xd2//x_D41A0_BYTEARRAY_4_struct.byteindex_210
	Bit16u byteindex_214w;//0xd6//x_D41A0_BYTEARRAY_4_struct.byteindex_214
	Bit16u setting_216w;
	Bit16u byteindex_218w;//0xda//x_D41A0_BYTEARRAY_4_struct.byteindex_218
	
	Bit8u byteindex_220;//0xdc//x_D41A0_BYTEARRAY_4_struct.byteindex_220
	Bit8u byteindex_221ar[3];//0xe0//x_D41A0_BYTEARRAY_4_struct.byteindex_221ar
	Bit8u byteindex_224;//0xe0//x_D41A0_BYTEARRAY_4_struct.byteindex_224
	Bit8u byteindex_225;//0xe1//x_D41A0_BYTEARRAY_4_struct.byteindex_225
	std::vector<Bit8u> heapbuffer;
	Bit32u dword_0xE6_heapsize_230;//x_D41A0_BYTEARRAY_4_struct.dword_0xE6_heapsize_230
	Bit8u stubr[8];
	Bit8u byteindex_242ar[14];//0xf2//x_D41A0_BYTEARRAY_4_struct.byteindex_242ar
	
	type_str_0x2BDE byteindex_256ar;//0x100//x_D41A0_BYTEARRAY_4_struct.byteindex_256ar	

	Bit32u dwordindex_2380;//0x94c//x_D41A0_BYTEARRAY_4_struct.dwordindex_2380
	Bit8u stubt[4];
	Bit32u dwordindex_2388;//0x954//x_D41A0_BYTEARRAY_4_struct.dwordindex_2388
	Bit32u dwordindex_2392;//0x958//x_D41A0_BYTEARRAY_4_struct.dwordindex_2392

	Bit8u stubu[36000];
	type_str_0x6E8E* dwordindex_38396;//0x95FC//x_D41A0_BYTEARRAY_4_struct.dwordindex_38396
	Bit8u byteindex_38400;//0x9600//x_D41A0_BYTEARRAY_4_struct.byteindex_38400
	Bit8u byteindex_38401;//0x9601//x_D41A0_BYTEARRAY_4_struct.byteindex_38401

	Bit8u setting_38402;//0x9602//x_D41A0_BYTEARRAY_4_struct.setting_38402

	type_str_0x6E8E* bytearray_38403x[30];//array 116//0x9603//x_D41A0_BYTEARRAY_4_struct.bytearray_38403	
	/*
	creatures
		8-dead
		69-dead
	*/
	type_str_0x6E8E* dword_38519;//0x9677//x_D41A0_BYTEARRAY_4_struct.dword_38519
	/*
	entite
	8-dead
	26-index
	64-type
		1-player
		2-castle
		3-ballon
	144-mana
	*/
	type_str_0x6E8E* dword_38523;//0x967b//x_D41A0_BYTEARRAY_4_struct.dword_38523
	type_str_0x6E8E* dword_38527;//0x967F//x_D41A0_BYTEARRAY_4_struct.dword_38527	
	type_str_0x6E8E* dword_38531;//0x9683//x_D41A0_BYTEARRAY_4_struct.dword_38531
	type_str_0x6E8E* dword_38535;//x_D41A0_BYTEARRAY_4_struct.dword_38535
	Bit8u stubv[5];
	Bit8u byte_38544;//x_D41A0_BYTEARRAY_4_struct.byte_38544
	Bit8u setting_38545;//0x9691//x_D41A0_BYTEARRAY_4_struct.setting_38545
	Bit8u byte_38546;//0x9692//x_D41A0_BYTEARRAY_4_struct.byte_38546
	Bit8u stubw[44];
	Bit8u byte_38591;//0x96BF//x_D41A0_BYTEARRAY_4_struct.byte_38591
}type_x_D41A0_BYTEARRAY_4_struct;



doublebyte doublebyte_conv(Bit16u a2);

extern type_x_D41A0_BYTEARRAY_4_struct x_D41A0_BYTEARRAY_4_struct;
extern Bit16s x_D41A0_WORDARRAY[];

extern posistruct* xy_DWORD_17DED4_spritestr;
extern posistruct* xy_DWORD_17DEC0_spritestr;
extern posistruct* xy_DWORD_17DEC8_spritestr;

extern posistruct* x_DWORD_D4188t_spritestr;

extern Bit8u* x_DWORD_180628b_screen_buffer;

typedef struct {//lenght 30
	Bit16s word_0;//str_E2A74[].word_0
	Bit16s axis_2[5]; //str_E2A74[].axis_2[0]
	type_str_0x6E8E* dword_12;//str_E2A74[].dword_12
	Bit32s dword_16;
	Bit32s dword_20;//str_E2A74[].dword_20
	Bit32s dword_24;//str_E2A74[].dword_24
	Bit8s byte_28;
	Bit8s byte_29;
}
type_str_E2A74;

extern type_str_E2A74 str_E2A74[0x69];

void support_begin();
void support_end();

void loadfromsnapshot(char* filename, Bit8u* adress, Bit32u adressdos, Bit32u size);
void loadfromsnapshot2(char* filename, Bit8u* adress, Bit32u adressdos, Bit32u size);
Bit32u compare_with_snapshot(char* filename, Bit8u* adress, Bit32u adressdos, Bit32u size, Bit8u* origbyte, Bit8u* copybyte);
Bit32u compare_with_sequence(char* filename, Bit8u* adress, Bit32u adressdos, long count, long size1, Bit32u size2, Bit8u* origbyte, Bit8u* copybyte, long offset = 0);
Bit32u compare_with_sequence_E7EE0(char* filename, Bit8u* adress, Bit32u adressdos, Bit32u count, Bit32u size1, Bit32u size2, Bit8u* origbyte, Bit8u* copybyte, long offset = 0);
Bit32u compare_with_snapshot_D41A0(char* filename, Bit8u* adress, Bit32u adressdos, Bit32u size, Bit8u* origbyte, Bit8u* copybyte);
Bit32u compare_with_sequence_D41A0(char* filename, Bit8u* adress, Bit32u adressdos, Bit32u count, Bit32u size, Bit8u* origbyte, Bit8u* copybyte, long offset=0);
Bit32u compare_with_sequence_array_E2A74(char* filename, Bit8u* adress, Bit32u adressdos, Bit32u count, Bit32u size1, Bit32u size2, Bit8u* origbyte, Bit8u* copybyte, long offset=0);
Bit32u compare_with_sequence_x_DWORD_F2C20ar(char* filename, Bit8u* adress, Bit32u adressdos, Bit32u count, Bit32u size, Bit8u* origbyte, Bit8u* copybyte, int* posdiff);
Bit32u compare_with_sequence_array_222BD3(char* filename, Bit8u* adress, Bit32u adressdos, Bit32u count, Bit32u size, Bit8u* origbyte, Bit8u* copybyte, int* posdiff);
Bit32u compare_with_sequence_D41A0_4(char* filename, Bit8u* adress, Bit32u adressdos, Bit32u count, Bit32u size, Bit8u* origbyte, Bit8u* copybyte, long offset = 0);
Bit32u compare_with_sequence_EA3E4(char* filename, type_str_0x6E8E** adress, Bit32u count, Bit32u size, Bit8u* origbyte, Bit8u* copybyte);
Bit32u compare_0x6E8E(char* filename, Bit8u* adress, Bit32u count, Bit32u size, Bit8u* origbyte, Bit8u* copybyte, long offset=0);
void add_compare(Bit32u adress, bool debugafterload,int stopstep=-1,bool skip=false);

void writehex(Bit8u* buffer,Bit32u count);

void mine_texts(char* filename, Bit32u adressdos, Bit32u count, char* outfilename);

typedef union {
	axis_2du axis;
	type_str_0x6E8E* pointer_0x6E8E;
}
un1;

typedef struct {//lenght 8
	Bit8s str_0x3647A_byte_0;//array_0x3647a
	Bit8s str_0x3647A_byte_1;//array_0x3647b
	uaxis_2d str_0x3647A_2;//array_0x3647c//str_0x3647A_2.word
	un1 str_0x3647C_4;//array_0x3647e	
} type_str_0x3647Ac;

typedef struct {//lenght 8
	Bit8u str_0x3647A_byte_0;//array_0x3647a
	Bit8u str_0x3647A_byte_1;//array_0x3647b
	Bit16s str_0x3647A_word_2;//array_0x3647c
	Bit32u str_0x3647A_dword_4;//array_0x3647e
} type_str_0x3647Ab;

typedef struct {//lenght 20
	Bit16u str_0x30311_type;//type_str_0x30311//type_str_0x30325//1091
	Bit16s str_0x30311_subtype;//type_str_0x30313//type_str_0x30327//1091
	axis_2du axis2d_4;
	Bit16u DisId;
	Bit16u word_10;//type_str_0x3031b//type_str_0x3032f
	Bit16u word_12;//type_str_0x3031d//type_str_0x30331
	Bit16u word_14;//type_str_0x3031f//type_str_0x30333//1105
	Bit16u word_16;//type_str_0x30321//type_str_0x30335
	Bit16u word_18;//type_str_0x30323//type_str_0x30337
}
type_str_0x30311;


typedef struct {//lenght 9377
	Bit8u stub[9377];
} type_str_0x24DF;

typedef struct {//lenght 110 //word_0x360D2
		Bit8u stuba[3];
		Bit16s word_0x360D5;
		Bit8u stubb[2];
		Bit16s word_0x360D9;
		Bit8u stubc[2];
		Bit16s word_0x360DD;
		Bit8u stubd[2];
		Bit8u byte_0x360E1x[26];
		Bit8u byte_0x360FBx[26];
		//Bit8u byte_0x36112;
		//Bit8u stubb[0x2];
		Bit8u byte_0x36115x[26];
		//Bit8u stube[25];
		Bit16s word_0x3612F;
		//Bit8u byte_0x0x36140;
		Bit8u stubf[15];
}
type_str_0x360D2;

//objective type
//0 - collect mana
//1 - kill creature2 - must fix entites
//2 -
//3 - kill enemy player
//4 -
//5 - release point
//6 -
//7 - kill creature - must fix entites
//8 - kill all players
//9 - destroy building - must fix entites

typedef struct {
	Bit8s byte_0;
	Bit16s word_1;//25973//word_0
	axis_2d _axis_2d;
}
type_str_0x36442;

typedef enum : Bit8u
{
  Day = 0,
  Night = 1,
  Cave = 2,
} MC2LevelType;

typedef struct {//lenght 0x6604u
	Bit16u word_2FECE;
	Bit16u word_2FED0;
	Bit8u byte_0x2FED2;//x_D41A0_BYTEARRAY_0[196306] // type of level graphics
	Bit8u byte_0x2FED3;
	MC2LevelType byte_level_type;//x_D41A0_BYTEARRAY_0[196308]//GraphicsType
	Bit16s word_0x2FED5;
	Bit16s word_0x2FED7;
	Bit8s array_0x2FED9[8];
	Bit8u stubb[4];
	Bit16u word_0x2FEE5;//2FEE5//23
	Bit8u stubb2[2];
	Bit16u word_0x2FEE9;//2FEE9//27 //first seed position
	Bit8u stubc[2];
	Bit16u word_0x2FEED;//2FEED//31 //first seed height
	Bit8u stubc2[2];
	Bit16u word_0x2FEF1;//2FEF1//35 //random seed
	Bit8u stubc3[2];
	Bit32u word_0x2FEF5;//2FEF5//39
	Bit16u word_0x2FEF9;//2FEF9//43
	Bit8u stube[2];
	Bit16u word_0x2FEFD;//2FEFD//47
	Bit8u stubf[2];
	Bit16u word_0x2FF01;//2FF01//51
	Bit8u stubg[2];
	Bit16u word_0x2FF05;//2FF05//55
	Bit8u stubh[2];
	Bit16u word_0x2FF09;//2FF09//59
	Bit8u stubi[2];
	Bit16u word_0x2FF0D;//2FF0D//63
	Bit8u stubj[2];
	Bit16u word_0x2FF11;//2FF11//67
	Bit8u stubk[1022];
	type_str_0x30311 array_0x30311[0x4b0];//end(next entity) - 0x360d1
	Bit8u next_0x360D1;

	type_str_0x360D2 next_0x360D2[8];//lenght 110  /spells?

	type_str_0x36442 str_0x36442[8];//stages(checkpoints)
	type_str_0x3647Ac array_0x3647A[0xb];//8x11	
} type_str_2FECE;//compress level 

typedef union{
	Bit32s dword;
	Bit16u* ptr16u;
	type_str_0x30311* ptr0x30311;
	type_str_0x6E8E* ptr0x6E8E;
}
un_str_36552;
typedef struct {//size 10 count 8
	Bit8s str_3654C_byte0;//222540
	Bit8s str_3654D_byte1;
	axis_2d str_3654E_axis;
	un_str_36552 str_36552_un; //pointer sometimes
} type_str_3654C;

typedef struct {//size 11 count 6
	Bit8u array_0x3659C_byte[11];//objectives 1-active 2-done
} type_str_3659C;

typedef struct {
	Bit8u reflections_0x218A;//8586 reflections	
	Bit8u shadows_0x218B;//8587 shadows
	Bit8u sky_0x218C;//8588 sky
	Bit8u alter_0x218D;//8589 alter screen size
}
type_str_0x218A;

typedef struct {
	Bit8u minimap_0x218E;//8590 icons//str_0x218E.str.icons_0x218E
	Bit8u topbar_0x218F;//8591 ??//str_0x218E.str.xxxx_0x218F
	Bit8u scr_size_0x2190;//8592 screen size?//str_0x218E.str.scr_size_0x2190
	Bit8u xxxx_0x2191;//8593//str_0x218E.str.xxxx_0x2191
}
type_str_0x218E;

typedef struct {
	Bit8u xxxx_0x2192;//8594 ??//str_0x2192.str.xxxx_0x2192
	Bit8u xxxx_0x2193;//8595 ??//str_0x2192.str.xxxx_0x2193
	Bit8u resolution_0x2194;//8596 resolution//str_0x2192.str.resolution_0x2194
	Bit8u shadows_0x2195;//8593 shadows//str_0x2192.str.shadows_0x2195
}
type_str_0x2192;

typedef struct {
	Bit8u lights_0x2196;//8598 lights//str_0x2196.str.lights_0x2196
	Bit8u setting_0x2197;//8599 setting//str_0x2196.str.setting_0x2197
	Bit8u transparency_0x2198;//8600 transparency//str_0x2196.str.transparency_0x2198
	Bit8u flat_0x2199;//8601 flat//str_0x2196.str.flat_0x2199
}
type_str_0x2196;

typedef struct {
	Bit8u creflections_0x21AA;//Bit8u byte_0x21AA;//8618 can reflections//str_0x21AA.str.creflections_0x21AA
	Bit8u cshadows_0x21AB;//Bit8u byte_0x21AB;//8619 can shadows//str_0x21AA.str.cshadows_0x21AB
	Bit8u csky_0x21AC;//Bit8u byte_0x21AC;//8620 can sky//str_0x21AA.str.csky_0x21AC
	Bit8u calter_0x21AD;//Bit8u byte_0x21AD;//8621//str_0x21AA.str.calter_0x21AD
}
type_str_0x21AA;

typedef struct {
	Bit8u xxxx_0x21AE;//Bit8u byte_0x21AE;//str_0x21AE.str.xxxx_0x21AE
	Bit8u xxxx_0x21AF;//Bit8u byte_0x21AF;//str_0x21AE.str.xxxx_0x21AF
	Bit8u xxxx_0x21B0;//Bit8u byte_0x21B0;//str_0x21AE.str.xxxx_0x21B0
	Bit8u xxxx_0x21B1;//Bit8u byte_0x21B1;//str_0x21AE.str.xxxx_0x21B1
}
type_str_0x21AE;

typedef struct {
	Bit8u xxxx_0x21B2;//Bit8u byte_0x21B2;//str_0x21B2.str.xxxx_0x21B2
	Bit8u xxxx_0x21B3;//Bit8u byte_0x21B3;//str_0x21B2.str.xxxx_0x21B3
	Bit8u cresolution_0x21B4;//Bit8u byte_0x21B4;//str_0x21B2.str.cresolution_0x21B4
	Bit8u xxxx_0x21B5;//Bit8u byte_0x21B5;//str_0x21B2.str.xxxx_0x21B5
}
type_str_0x21B2;

typedef struct {
	Bit8u clights_0x21B6;//Bit8u byte_0x21B6;//str_0x21B6.str.clights_0x21B6
	Bit8u csetting_0x21B7;//Bit8u byte_0x21B7;//str_0x21B6.str.csetting_0x21B7
	Bit8u ctransparency_0x21B8;//Bit8u byte_0x21B8;//str_0x21B6.str.ctransparency_0x21B8
	Bit8u cflat_0x21B9;//Bit8u byte_0x21B9;//str_0x21B6.str.cflat_0x21B9
}
type_str_0x21B6;

typedef struct{//lenght 39
	Bit8s byte_0;
	Bit8s byte_1;
	Bit8u byte_2;
	Bit8s byte_3;
	axis_3d axis3d_4;
	type_str_0x6E8E* dword_A;
	Bit8u array_E[25];
}
type_str_0x3664C;

typedef struct {//lenght 108
	Bit32u dword_0x364D2;//lenght 108
	Bit32u dword_0x364D6[0x1a];// lenght 0x68=104 end 0x3653e
}
type_str_0x364D2;

typedef struct {//lenght 7
	Bit8s byte_0;//25972
	Bit8s byte_1;//25973
	Bit8u stub[5];
}
type_str_0x6574;

typedef struct {
	type_str_0x218A str_0x218A;
	type_str_0x218E str_0x218E;
	type_str_0x2192 str_0x2192;
	type_str_0x2196 str_0x2196;
}
type_str_0x218A_settings;

typedef struct {//lenght 0x36e16	
	Bit8u stub0[4];
	Bit32u dword_0x4;
	Bit32u dword_0x8;

	Bit16s word_0xc;//player_index?
	Bit16s word_0xe;
	Bit8u array_0x10[0x1d]; //0x10, next 0x2d(45)
	Bit32s dword_0x2d;//45
	Bit16u word_0x31;//49
	Bit16u word_0x33;//51
	Bit32s dword_0x35;//53//entity counter(max 1000 entity changes per step)
	Bit8u array_0x39[508];//57
	Bit32s dword_0x235;//act music
	Bit8u byte_0x239;//569
	Bit32s dword_0x23a;
	Bit32s dword_0x23e;
	Bit32s dword_0x242;
	type_str_0x6E8E* pointers_0x246[0x3e8];//pointers
	Bit32s dword_0x11e6;//second entity counter
	type_str_0x6E8E* dword_0x11EA[0x3e8];//??4586

	type_str_0x218A_settings str_0x218A_settings;	

	Bit32u dword_0x219A;//8602
	Bit32u dword_0x219E;//8606
	Bit32u dword_0x21A2;//8610
	Bit32u dword_0x21A6;//8614

	type_str_0x21AA str_0x21AA;
	type_str_0x21AE str_0x21AE;
	type_str_0x21B2 str_0x21B2;
	type_str_0x21B6 str_0x21B6;

	Bit8u stub3b[0x1a8];

	axis_3d array_0x2362[8];//0x30
	Bit8u stub3c[0x14d];
	Bit8u stub3d[0x6ff];

	type_str_0x2BDE array_0x2BDE[0x8]; //0x84c*0x8 ??

	type_str_0x6E3E array_0x6E3E[8];//28222	lenght 0xa size 0x8// game events
	type_str_0x6E8E struct_0x6E8E[0x3e8];//28302 a8*3e8 

	type_str_2FECE str_2FECE;// a1 = &x_D41A0_BYTEARRAY_0[0x2FECE/*196302*/];//fix - size 0x6604u//compress level 

	type_str_0x364D2 str_0x364D2;//lenght 108

	Bit16s word_0x3653E;//
	Bit16s word_0x36540;//
	Bit16s word_0x36542;//
	Bit16s word_0x36544;//
	Bit16s word_0x36546;//
	Bit16s word_0x36548;//
	Bit16s word_0x3654A;//
	type_str_3654C struct_0x3654C[0x8];//size 10 count 8
	type_str_3659C struct_0x3659C[0x8];//size 11 count 8 C-0 D-1 E-2 F-3

	type_str_0x3647Ac array_0x365F4[0xb];//8x11	//set 0x58 // end 0x3664c

	type_str_0x3664C str_0x3664C[0x32];// lenght 0x79e//39x50 (end-0x36dea)
	Bit8s byte_0x36DEA_fly_asistant;
	Bit8s byte_0x36DEB_xx;
	Bit16s word_0x36DEC_mousex;
	Bit16s word_0x36DEE_mousey;
	Bit16s word_0x36DF0_mousexx;
	Bit32u dword_0x36DF2;//index
	Bit32u dword_0x36DF6;//pointer
	Bit16s word_0x36DFA;
	Bit16s word_0x36DFC;
	Bit16s word_0x36DFE;	
	Bit8u byte_0x36E00;
	Bit8u byte_0x36E01;//count objectives
	Bit8s byte_0x36E02;//temp objective
	Bit8s byte_0x36E03;
	Bit8s byte_0x36E04;
	Bit8u stub3k[0x6];
	Bit8s byte_0x36E0B;

	Bit8u stubend[0xa];

} type_D41A0_BYTESTR_0;

struct {//lenght 0x33
	Bit16s word_0x0;//0 //0
	Bit16s word_0x2;//2 //1
	Bit16s word_0x4;//4 //2
	Bit16s word_0x6;//6 //3
	Bit16s word_0x8;//8 //4
	Bit16s word_0xa;//a //5
	Bit16s word_0xc;//c-3f //6
	Bit16s word_0xe;//e //7
	Bit16s word_0x10;//10 //8
	Bit16s word_0x12;//12 //9
	Bit16s word_0x14;//14 //10
	Bit16s word_0x16;//16 //11
	Bit16s word_0x18;//18 //12	
	Bit16s word_0x1a;//1a //13
	Bit16s word_0x1c;//1c-4f //14 
	Bit16s word_0x1e;//1e-51 //15
	Bit16s word_0x20;//20 //16
	Bit16s word_0x22;//22 //17
	Bit16s word_0x24;//24-57 //width 18
	Bit16s word_0x26;//26-59 //19
	Bit16s word_0x28;//28-5b //20
	Bit16s word_0x2a;//2a-5d//21
	Bit8s stub[4];
	Bit8s byte_0x30;//30-63 - color1 //24
	Bit8s byte_0x31;//31-64 - color2
	Bit8s byte_0x32;//32-65 - color2
}
typedef type_sub_str_unk_1804B0ar;

typedef union {//lenght 12
	Bit32s dword[3];
	Bit16s word[6];
}
type_uni_0x8a;

struct {//0xb0 nebo spis 171(0xab)
	type_sub_str_unk_1804B0ar type_sub_0[2];

	Bit32s dword_0x66;//66
	Bit32s dword_0x6a;//6a
	Bit32s dword_0x6e;//6e
	Bit32s dword_0x72;//72
	Bit32s dword_0x76;//76
	Bit32s dword_0x7a;//7a
	Bit8s stub[4];
	Bit32s dword_0x82;//82	
	Bit16s word_0x86;//86
	Bit16s word_0x88;//88
	type_uni_0x8a uni_0x8a;
	Bit16s word_0x96;//96
	Bit16s word_0x98;//98
	Bit16s word_0x9a;//9A
	Bit16s word_0x9c;//9C
	Bit8s byte_0x9e;//9e
	Bit8s byte_0x9f;//9f
	Bit8s byte_0xa0;//a0
	Bit8s byte_0xa1;//a1
	Bit8s byte_0xa2;//a2
	Bit8s byte_0xa3;//a3
	Bit8s byte_0xa4;//a4
	Bit8s byte_0xa5;//a5
	Bit8s byte_0xa6;//a6
	Bit8s byte_0xa7;//a7
	Bit8s byte_0xa8;//a8
	Bit8s byte_0xa9;//a9
	Bit8s byte_0xaa;//aa
}
typedef type_str_unk_1804B0ar;
#pragma pack (16)

void clean_x_D41A0_BYTEARRAY_0_0x2BDE(int number);

extern type_D41A0_BYTESTR_0 D41A0_BYTESTR_0;

void write_posistruct_to_png(Bit8u* buffer, int width, int height, char* filename);

int my_sign32(Bit32s var);
int my_sign16(Bit16s var);

///////////////////////////////////////////////
// shared between sub_main and menus_and_intros

#pragma pack (1)
typedef struct {
	Bit32s dword_0;
	Bit16u word_4;
	Bit16u word_6;//level number
	Bit16u word_8;
	Bit16u word_10;
	Bit16u word_12;
	Bit16u word_14;
	Bit8u byte_16;
}
type_x_WORD_E2970;
#pragma pack (16)

#pragma pack (1)
typedef struct//lenght 613 // end 17E09D
{
	Bit8u* x_DWORD_17DE38; // weak
	Bit8u* x_DWORD_17DE3C; // weak//1
	Bit8u* x_DWORD_17DE40; // weak//2
	Bit8u* x_DWORD_17DE44; // weak//3
	Bit8u* x_DWORD_17DE48c; // weak//4
	Bit8u* x_DWORD_17DE4C; // weak
	char* x_DWORD_17DE50; // weak
	Bit8u* x_DWORD_17DE54; // weak
	Bit8u* x_DWORD_17DE58; // weak
	Bit8u* x_DWORD_17DE5C_border_bitmap; // weak
	Bit8u* x_DWORD_17DE60; // weak
	Bit8u* x_DWORD_17DE64_game_world_map; // weak
	Bit8u x_BYTE_17DE68x[88]; // fix it -  weak
	//char x_BYTE_17DE69[1]; //x_BYTE_17DE68x[0x1] fix it -  weak
	//char x_BYTE_17DE71[1]; //x_BYTE_17DE68x[0x9] fix it -  weak
	//char x_BYTE_17DE72[78]; //x_BYTE_17DE68x[0xa] idb
	Bit8u* x_DWORD_17DEC0; // weak
	Bit8u* x_DWORD_17DEC4; // weak
	Bit8u* x_DWORD_17DEC8; // weak
	Bit8u* x_DWORD_17DECC; // weak
	int x_DWORD_17DED0; // weak
	Bit8u* x_DWORD_17DED4; // weak
	Bit8u* x_DWORD_17DED8; // weak
	int x_DWORD_17DEDC; // weak
	FILE* x_DWORD_17DEE0_filedesc; // weak
	Bit16s x_DWORD_17DEE4_mouse_positionx; // weak
	char stub0[2];
	Bit16s x_DWORD_17DEE8_mouse_positiony; // weak
	char stub1[2];
	int16_t x_WORD_17DEEC; // weak
	int16_t x_WORD_17DEEE_mouse_buttons; // weak
	int16_t x_WORD_17DEF0; // weak
	int16_t x_WORD_17DEF2; // weak
	int16_t x_WORD_17DEF4; // weak
	int16_t x_WORD_17DEF6; // weak
	int16_t x_WORD_17DEF8; // weak
	int16_t x_WORD_17DEFA; // weak
	int16_t x_WORD_17DEFC; // weak
	int16_t x_WORD_17DEFE; // weak
	int16_t x_WORD_17DF00; // weak
	int16_t x_WORD_17DF02; // weak
	int16_t x_WORD_17DF04; // weak
	int16_t x_WORD_17DF06; // weak
	int16_t x_WORD_17DF08; // weak
	int16_t x_WORD_17DF0A; // weak
	int16_t x_WORD_17DF0C; // weak
	int16_t x_WORD_17DF0E; // weak
	char x_BYTE_17DF10_get_key_scancode; // weak
	char x_BYTE_17DF11_last_key_status; // weak
	char stuba[1];
	char x_BYTE_17DF13; // weak
	char x_BYTE_17DF14[344]; // idb// 34*8
	//char x_BYTE_17DF3C[400]; // fix it -  weak//&x_BYTE_17DF14[40]
	//char x_BYTE_17DF3D[400]; // fix it -  weak//&x_BYTE_17DF14[41]
	//char x_BYTE_17DF3E[400]; // idb//&x_BYTE_17DF14[42]
	int16_t x_WORD_17E06C; // weak
	int16_t x_WORD_17E06E; // weak
	int16_t x_WORD_17E070; // weak
	int16_t x_WORD_17E072; // weak
	int16_t x_WORD_17E074; // weak
	int16_t x_WORD_17E076; // weak
	Bit8s unk_17E078x[0xc]; // weak [11]
	//int16_t x_WORD_17E07C; // weak unk_17E078x[4]
	//int16_t x_WORD_17E07E; // weak unk_17E078x[6]
	//int16_t x_WORD_17E080; // weak unk_17E078x[8]
	//char x_BYTE_17E082; // weak unk_17E078x[0xa]
	//char x_BYTE_17E083; // weak unk_17E078x[0xb]
	Bit16s unk_17E084x[0xc]; // weak [11]
	char x_BYTE_17E09C; // weak
} type_x_DWORD_17DE38str;
#pragma pack (16)

#pragma pack (1)
typedef struct {
	Bit8u** begin_buffer;
	Bit8u** end_buffer;
	Bit8u** dat_buffer;
	posistruct** _posistruct;
} filearray_struct;
#pragma pack (16)

#pragma pack (1)
typedef struct {
	char path[512];
	Bit8u** var28_begin_buffer;//1C // asi buffer
	Bit8u** var32_end_buffer;//20 // asi buffer
	Bit32u var36_size_buffer;//24 //asi file size
	Bit32u var40_alloc_type;//28
} Pathstruct;
#pragma pack (16)

extern std::unique_ptr<FileHandling> file_handling;

extern int16_t x_WORD_180660_VGA_type_resolution;
extern char x_BYTE_D41C1;
extern Bit8u* x_DWORD_E9C38_smalltit;
extern type_x_DWORD_17DE38str x_DWORD_17DE38str;
extern char x_BYTE_17DBC6;
extern Bit32s x_DWORD_17DBB8[4];
extern int16_t x_WORD_1803EC;
extern int help_VGA_type_resolution;
extern char* x_DWORD_E9C4C_langindexbuffer[1000];
extern char* x_DWORD_D41BC_langbuffer;
extern char x_BYTE_E29E0;
extern char x_BYTE_D41C0;
extern Bit8u off_E1BAC[0x3c4/*4096*/];
extern int filearrayindex_POINTERSDATTAB;
extern filearray_struct filearray_2aa18c[];
extern Bit8u x_BYTE_EB3A8;
extern int16_t x_WORD_E29DA_type_resolution;
extern char x_BYTE_D41AD_skip_screen;
extern Bit8u* pre_x_DWORD_E9C3C;
extern Bit8u* x_DWORD_E9C3C;
extern char x_BYTE_E3798_sound_active2;
extern char x_BYTE_D41CE;
extern char* x_DWORD_D41D0;
extern int16_t x_WORD_E12FC;
extern int16_t x_WORD_D4004;
extern Bit16u x_WORD_17DB60;
extern Bit8u* x_DWORD_E12F4;
extern FILE* x_DWORD_17DB38_intro_file_handle;
extern Bit16s x_WORD_17DB48;
extern Bit16s x_WORD_17DB4A;
extern int16_t x_WORD_180744_mouse_right_button;
extern int16_t x_WORD_180746_mouse_left_button;
extern int16_t x_WORD_18074A_mouse_right2_button;
extern int16_t x_WORD_18074C_mouse_left2_button;
extern int x_DWORD_E1300;
extern int16_t x_WORD_17DB5A;
extern int16_t x_WORD_17DB5C;
extern Bit8u unk_E17CC_0[0x160];
extern Bit8u x_BYTE_EB39E_keys[10];

extern void sub_753D0();
extern void sub_41BC0();
extern void sub_7A060_get_mouse_and_keyboard_events();
extern Bit16s sub_90B27_VGA_pal_fadein_fadeout(Bit8u* a1, Bit8u shadow_levels, bool a3);
extern void sub_90478_VGA_Blit320();
extern void sub_75200_VGA_Blit640(Bit16u height);
extern char sub_7B250_draw_and_serve();
extern void sub_7AB00_draw_menu_animations(uint8_t a4);
extern void sub_7C120_draw_bitmap_640(Bit16s posx, Bit16s posy, posistruct tempstr);
extern void sub_9A144_copy_screen_640(void* source, void* desc, Bit16u countlines);
extern void sub_9A128_copy_screen_320(void* source, void* desc, Bit16u countlines);
extern long j___clock();
extern void sub_8CD27_set_cursor(posistruct a2);
extern void sub_7B5A0_disable_enable();
extern void sub_7A110_load_hscreen(char a1, char a2);
extern char sub_77350_new_game_dialog(Bit8u* a1);
extern void sub_8E160_sound_proc15_startsequence(int16_t a1, uint16_t a2);
extern void sub_8E020_sound_proc14_stopsequence();
extern void sub_6EDB0_set_mouse_position_by_res();
extern Bit32s sub_84300_load_sound(Bit8u a1);
extern char sub_86860_speak_Sound(uint16_t a1);
extern signed int sub_8CEDF_install_mouse();
extern void sub_90D6E_VGA_set_video_mode_320x200_and_pallette(Bit8u* pallette);
extern void sub_90E07_VGA_set_video_mode_640x480_and_pallette(Bit8u* pallette);
extern void sub_41A90_VGA_pallette_install(Bit8u* a1);
extern void sub_72883_clear_graphics_320(void *a2, uint16_t a3, char a4);
extern void sub_728A9_clear_graphics_640(void *a2, uint16_t a3, char a4);
extern void sub_54600_mouse_reset();
extern void sub_81DB0_read_config();
extern void sub_7B5D0();
extern void sub_8D8F0_sound_proc3_endsample();
extern void sub_7AA70_load_and_decompres_dat_file(const char* a1, Bit8u* a2, int a3, int a4);
extern char sub_779E0_lang_setting_dialog(Bit8u* a1);
extern int sub_98882_close(FILE* a1);
extern int sub_9891E_seek(FILE* filedesc, int position, char type);
extern void sub_5B870_copy_sentence(char* langbuffer, char** langindexbuffer, Bit32u count);
extern void sub_83E80_freemem4(Bit8u* a1);
extern Bit8u sub_5BE80_test_pallette(Bit8u *a1, Bit8u a2, Bit8u a3, Bit8u a4);
extern size_t sub_988A7_read(FILE* a1, Bit8u* a2, int a3);
extern void sub_8E410_sound_proc16_xmidivolume(Bit32s master_volume);
extern int sub_8E470_sound_proc17_volume(int a1);
extern x_DWORD fix_filelength(x_DWORD);
extern long x_filelength(FILE* decriptor);
extern void stub_fix_it();
extern void sub_6EBF0(filearray_struct* a1);
extern FILE* sub_98817_open(const char* path, int __pmode);
extern void sub_9874D_create_index_dattab(Bit8u* a1, Bit8u* a2, Bit8u* a3, posistruct* a4);
extern void sub_9874D_create_index_dattab_add(Bit8u* a1, Bit8u* a2, Bit8u* a3, posistruct* a4,int add);
extern void sub_98709_create_index_dattab_power(Bit8u* a1, Bit8u* a2, Bit8u* a3, posistruct* a4);
extern void sub_98709_create_index_dattab_power_add(Bit8u* a1, Bit8u* a2, Bit8u* a3, posistruct* a4,int add);
extern signed int sub_9A10A_check_keyboard();
extern type_x_WORD_E2970* sub_824E0(int16_t a1);
extern void sub_6EB90(filearray_struct* a1);
extern void sub_473B0();
extern void sub_1B280_run_intro_events(Bit8u* a1);
extern void sub_75DB0();
extern void sub_75E70();
extern x_DWORD j___delay(x_DWORD);


extern Pathstruct xasearchd_2bac30;
#define psxasearchd_2bac30 0
extern Pathstruct xafonts0dat;
#define psxafonts0dat 1
extern Pathstruct xafonts0tab;
#define psxafonts0tab 2
extern Pathstruct xafonts1dat;
#define psxafonts1dat 3
extern Pathstruct xafonts1tab;
#define psxafonts1tab 4
extern Pathstruct xadatatmaps00tab;
#define psxadatatmaps00tab 5
extern Pathstruct xapaldata;
#define psxapaldata 6
extern Pathstruct xapalmem;
#define psxapalmem 7
extern Pathstruct xadatapointersdat;
#define psxadatapointersdat 8
extern Pathstruct xadatapointerstab;
#define psxadatapointerstab 9
extern Pathstruct xazero;
#define psxazero0 10
extern Pathstruct xadatabuild00dat;
#define psxadatabuild00dat 11
extern Pathstruct xadatabuild00tab;
#define psxadatabuild00tab 12
//zero
#define psxazero1 13
extern Pathstruct xadataetextdat;
#define psxadataetextdat 14
//zero
#define psxazero2 15
extern Pathstruct xadataftextdat;
#define psxadataftextdat 16
//zero
#define psxazero3 17
extern Pathstruct xadatagtextdat;
#define psxadatagtextdat 18
//zero
#define psxazero4 19
extern Pathstruct xadataitextdat;
#define psxadataitextdat 20
//zero
#define psxazero5 21
extern Pathstruct xadatablock16dat;
#define psxadatablock16dat 22
extern Pathstruct xadatablock32dat;
#define psxadatablock32dat 23
//zero
#define psxazero6 24
extern Pathstruct xabscreen;
#define psxabscreen 25
extern Pathstruct xadatapald0dat;
#define psxadatapald0dat 26
//zero
#define psxazero7 27
extern Pathstruct xawscreen_351628;
#define psxawscreen_351628 28
extern Pathstruct xabscreen2;
#define psxabscreen2 29

extern Pathstruct xadatapald0dat2;
#define psxadatapald0dat2 30
//zero
#define psxazero8 31
extern Pathstruct xadatamsprd00dat;
#define psxadatamsprd00dat 32
extern Pathstruct xadatamsprd00tab;
#define psxadatamsprd00tab 33
//zero
#define psxazero9 34
extern Pathstruct xadatahsprd00dat;
#define psxadatahsprd00dat 35
extern Pathstruct xadatahsprd00tab;
#define psxadatahsprd00tab 36
extern Pathstruct xadatahfont3dat;
#define psxadatahfont3dat 37
extern Pathstruct xadatahfont3tab;
#define psxadatahfont3tab 38
//zero
#define psxazero10 39
extern Pathstruct xadataclrd0dat;
#define psxadataclrd0dat 40
//zero
#define psxazero11 41
extern Pathstruct xadataspellsdatx;
#define psxadataspellsdat 42
//zero
#define psxazero12 43
extern Pathstruct xadatalang;
#define psxadatalangbuffer 44
//zero
#define psxazero13 45
extern Pathstruct xadatatables;
#define psxadatalangbuffer2 46
//zero
#define psxazero14 47

extern Pathstruct pstr[100];


#endif //ENGINE_SUPPORT_ACTIVE
