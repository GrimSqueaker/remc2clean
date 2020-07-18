#include "menus_and_intros.h"

#include <cstring>

#include "defs.h"


///////////////////////////////////////////////
// file-global variables

char x_BYTE_E29DF_skip_screen = 0;

int16_t x_WORD_E29DC = 0;
int16_t x_WORD_E29D8 = 0;
int16_t x_WORD_17DE26;
int16_t x_WORD_E29DA_type_resolution = 0;
int16_t x_WORD_17DB58;
char x_BYTE_E29DE = 1;

bool x_BYTE_E29E1 = true;

Bit8u unk_17DB40[12];

Bit16s x_WORD_17DB46;

Bit8u unk_E17CC_0x160[0x34] = {
0x00,0x00,0x41,0x03,0x00,0x00,0x00,
0x00,0x00,0x59,0x00,0x00,0x00,0x00,
0x00,0x00,0x45,0x04,0x00,0x00,0x00,
0x01,0x00,0x53,0x12,0x00,0x00,0x00,
0x01,0x00,0x58,0x05,0x00,0x00,0x00,
0x0A,0x00,0x53,0x13,0x00,0x00,0x00,
0x60,0x00,0x41,0x64,0x00,0x00,0x00,
0x00,0x00,0x22 };

Bit8s byte_E16E0[49] = {//2b26e0
0x28,0x23,0x2B,0x00,0x05,0x00,0x01,
0xEC,0x23,0x2B,0x00,0x09,0x00,0x02,
0xAC,0x24,0x2B,0x00,0x0D,0x00,0x03,
0x70,0x25,0x2B,0x00,0x11,0x00,0x04,
0x34,0x26,0x2B,0x00,0x18,0x00,0x05,
0xB4,0x26,0x2B,0x00,0x19,0x00,0x06,
0x00,0x00,0x00,0x00,0x00,0x00,0x00};

char array_E1328[0x3b8] = {
0x00,0x00,0x45,0x05,0x00,0x00,0x00,//2b2328
0x00,0x00,0x56,0x00,0x00,0x00,0x00,
0x00,0x00,0x57,0x00,0x00,0x00,0x00,
0x00,0x00,0x41,0x05,0x00,0x00,0x00,
0x01,0x00,0x4D,0x06,0x00,0x00,0x00,
0x18,0x00,0x53,0x02,0x00,0x00,0x00,
0x42,0x00,0x53,0x02,0x00,0x00,0x00,
0x46,0x00,0x53,0x02,0x00,0x00,0x00,
0x48,0x00,0x53,0x02,0x00,0x00,0x00,
0x5C,0x00,0x53,0x02,0x00,0x00,0x00,
0x5E,0x00,0x53,0x02,0x00,0x00,0x00,
0x7C,0x00,0x57,0x00,0x00,0x00,0x00,
0x7C,0x00,0x55,0x0A,0x01,0x00,0x00,
0x7C,0x00,0x41,0x0A,0x00,0x00,0x00,
0x7C,0x00,0x53,0x01,0x00,0x00,0x00,
0xD2,0x00,0x57,0x00,0x00,0x00,0x00,
0xD2,0x00,0x55,0x0B,0x01,0x00,0x00,
0x18,0x01,0x57,0x00,0x00,0x00,0x00,
0x18,0x01,0x55,0x0C,0x01,0x00,0x00,
0x54,0x01,0x57,0x00,0x00,0x00,0x00,
0x54,0x01,0x55,0x0D,0x01,0x00,0x00,
0xC2,0x01,0x57,0x00,0x00,0x00,0x00,
0xC2,0x01,0x59,0x00,0x00,0x00,0x00,
0xCC,0x01,0x53,0x03,0x00,0x00,0x00,
0xD6,0x01,0x53,0x03,0x00,0x00,0x00,
0xDA,0x01,0x53,0x03,0x00,0x00,0x00,
0xDE,0x01,0x53,0x03,0x00,0x00,0x00,
0xFF,0xFF,0xFF,0x01,0x00,0x00,0x00,
0x00,0x00,0x45,0x06,0x00,0x00,0x00,//2b23ec
0x00,0x00,0x56,0x00,0x00,0x00,0x00,
0x00,0x00,0x57,0x00,0x00,0x00,0x00,
0x00,0x00,0x41,0x05,0x00,0x00,0x00,
0x01,0x00,0x4D,0x06,0x00,0x00,0x00,
0x18,0x00,0x53,0x02,0x00,0x00,0x00,
0x42,0x00,0x53,0x02,0x00,0x00,0x00,
0x46,0x00,0x53,0x02,0x00,0x00,0x00,
0x48,0x00,0x53,0x02,0x00,0x00,0x00,
0x5C,0x00,0x53,0x02,0x00,0x00,0x00,
0x5E,0x00,0x53,0x02,0x00,0x00,0x00,
0x7C,0x00,0x57,0x00,0x00,0x00,0x00,
0x7C,0x00,0x55,0x0E,0x01,0x00,0x00,
0x7C,0x00,0x41,0x0A,0x00,0x00,0x00,
0x7C,0x00,0x53,0x01,0x00,0x00,0x00,
0xC8,0x00,0x57,0x00,0x00,0x00,0x00,
0xC8,0x00,0x55,0x0F,0x01,0x00,0x00,
0x18,0x01,0x57,0x00,0x00,0x00,0x00,
0x18,0x01,0x55,0x10,0x01,0x00,0x00,
0x54,0x01,0x57,0x00,0x00,0x00,0x00,
0x54,0x01,0x55,0x11,0x01,0x00,0x00,
0xB8,0x01,0x53,0x03,0x00,0x00,0x00,
0xC2,0x01,0x59,0x00,0x00,0x00,0x00,
0xD0,0x01,0x53,0x03,0x00,0x00,0x00,
0xDE,0x01,0x53,0x03,0x00,0x00,0x00,
0x03,0x02,0x53,0x03,0x00,0x00,0x00,
0xFF,0xFF,0xFF,0x01,0x00,0x00,0x00,
0x57,0x00,0x00,
0x00,0x00,0x45,0x07,0x00,0x00,0x00,//0x2B24ac
0x00,0x00,0x56,0x00,0x00,0x00,0x00,
0x00,0x00,0x57,0x00,0x00,0x00,0x00,
0x00,0x00,0x41,0x05,0x00,0x00,0x00,
0x01,0x00,0x4D,0x06,0x00,0x00,0x00,
0x18,0x00,0x53,0x02,0x00,0x00,0x00,
0x42,0x00,0x53,0x02,0x00,0x00,0x00,
0x46,0x00,0x53,0x02,0x00,0x00,0x00,
0x48,0x00,0x53,0x02,0x00,0x00,0x00,
0x5C,0x00,0x53,0x02,0x00,0x00,0x00,
0x5E,0x00,0x53,0x02,0x00,0x00,0x00,
0x7C,0x00,0x57,0x00,0x00,0x00,0x00,
0x7C,0x00,0x55,0x12,0x01,0x00,0x00,
0x7C,0x00,0x41,0x0A,0x00,0x00,0x00,
0x7C,0x00,0x53,0x01,0x00,0x00,0x00,
0xDE,0x00,0x57,0x00,0x00,0x00,0x00,
0xDE,0x00,0x55,0x13,0x01,0x00,0x00,
0x5E,0x01,0x59,0x00,0x00,0x00,0x00,
0x62,0x01,0x53,0x03,0x00,0x00,0x00,
0x6C,0x01,0x53,0x03,0x00,0x00,0x00,
0x76,0x01,0x53,0x03,0x00,0x00,0x00,
0x80,0x01,0x53,0x03,0x00,0x00,0x00,
0x8A,0x01,0x53,0x03,0x00,0x00,0x00,
0x94,0x01,0x53,0x03,0x00,0x00,0x00,
0x9E,0x01,0x53,0x03,0x00,0x00,0x00,
0xA8,0x01,0x53,0x03,0x00,0x00,0x00,
0xB2,0x01,0x53,0x03,0x00,0x00,0x00,
0xFF,0xFF,0xFF,0x01,0x00,0x00,0x00,
0x00,0x00,0x45,0x08,0x00,0x00,0x00,//0x2B2570
0x00,0x00,0x56,0x00,0x00,0x00,0x00,
0x00,0x00,0x57,0x00,0x00,0x00,0x00,
0x00,0x00,0x41,0x05,0x00,0x00,0x00,
0x01,0x00,0x4D,0x06,0x00,0x00,0x00,
0x18,0x00,0x53,0x02,0x00,0x00,0x00,
0x42,0x00,0x53,0x02,0x00,0x00,0x00,
0x46,0x00,0x53,0x02,0x00,0x00,0x00,
0x48,0x00,0x53,0x02,0x00,0x00,0x00,
0x5C,0x00,0x53,0x02,0x00,0x00,0x00,
0x5E,0x00,0x53,0x02,0x00,0x00,0x00,
0x7C,0x00,0x57,0x00,0x00,0x00,0x00,
0x7C,0x00,0x55,0x14,0x01,0x00,0x00,
0x7C,0x00,0x41,0x0A,0x00,0x00,0x00,
0x7C,0x00,0x53,0x01,0x00,0x00,0x00,
0xC8,0x00,0x57,0x00,0x00,0x00,0x00,
0xC8,0x00,0x55,0x15,0x01,0x00,0x00,
0x18,0x01,0x57,0x00,0x00,0x00,0x00,
0x18,0x01,0x55,0x16,0x01,0x00,0x00,
0x5E,0x01,0x59,0x00,0x00,0x00,0x00,
0x68,0x01,0x53,0x03,0x00,0x00,0x00,
0x6D,0x01,0x53,0x03,0x00,0x00,0x00,
0x72,0x01,0x53,0x03,0x00,0x00,0x00,
0x7C,0x01,0x53,0x03,0x00,0x00,0x00,
0x81,0x01,0x53,0x03,0x00,0x00,0x00,
0x86,0x01,0x53,0x03,0x00,0x00,0x00,
0x90,0x01,0x53,0x03,0x00,0x00,0x00,
0xFF,0xFF,0xFF,0x01,0x00,0x00,0x00,
0x00,0x00,0x45,0x09,0x00,0x00,0x00,//0x2B2634
0x00,0x00,0x56,0x00,0x00,0x00,0x00,
0x00,0x00,0x57,0x00,0x00,0x00,0x00,
0x00,0x00,0x41,0x05,0x00,0x00,0x00,
0x01,0x00,0x4D,0x06,0x00,0x00,0x00,
0x18,0x00,0x53,0x02,0x00,0x00,0x00,
0x42,0x00,0x53,0x02,0x00,0x00,0x00,
0x46,0x00,0x53,0x02,0x00,0x00,0x00,
0x48,0x00,0x53,0x02,0x00,0x00,0x00,
0x5C,0x00,0x53,0x02,0x00,0x00,0x00,
0x5E,0x00,0x53,0x02,0x00,0x00,0x00,
0x7C,0x00,0x57,0x00,0x00,0x00,0x00,
0x7C,0x00,0x55,0x17,0x01,0x00,0x00,
0x7C,0x00,0x41,0x0A,0x00,0x00,0x00,
0x7C,0x00,0x53,0x01,0x00,0x00,0x00,
0xC8,0x00,0x57,0x00,0x00,0x00,0x00,
0xC8,0x00,0x55,0x18,0x01,0x00,0x00,
0xFF,0xFF,0xFF,0x01,0x00,0x00,0x00,
0x6D,0x01,
0x00,0x00,0x45,0x04,0x00,0x00,0x00,//0x2B26b4
0x00,0x00,0x41,0x0A,0x00,0x00,0x00,
0x00,0x00,0x41,0x05,0x00,0x00,0x00,
0x01,0x00,0x4D,0x02,0x00,0x00,0x00,
0x1E,0x00,0x53,0x09,0x00,0x00,0x00,
0x38,0x00,0x53,0x0A,0x00,0x00,0x00,
0xFF,0x01
};// 2b2328



///////////////////////////////////////////////
// forward declarations

void sub_76FA0_main_menu(int a2, Bit16u a3);




///////////////////////////////////////////////
// menu and intro functions


//----- (0002EB40) --------------------------------------------------------
void sub_2EB40()//20fb40
{
	//int result; // eax

	//BYTE1(result) = 0;
	x_BYTE_D41CE = 0;
	x_BYTE_D41C1 = 0;
	x_DWORD_D41D0 = 0;
	//return result;
}

//----- (0007AC00) --------------------------------------------------------
int sub_7AC00_load_and_set_graphics_and_pallette()//25BC00
{
	//char v0; // al
	//uint8_t v1; // al
	//uint8_t v2; // al

	if (!(x_WORD_180660_VGA_type_resolution & 8))
	{
		/*if (x_DWORD_E9C3C)
		{
			sub_83E80_freemem4(x_DWORD_E9C3C);
			x_DWORD_E9C3C = 0;
		}*/
		//fix
		if (pre_x_DWORD_E9C3C)
		{
			sub_83E80_freemem4(pre_x_DWORD_E9C3C);
			pre_x_DWORD_E9C3C = 0;
			x_DWORD_E9C3C = 0;
		}
		//fix
		sub_54600_mouse_reset();//235600 //mouse reset
		sub_6EBF0(&filearray_2aa18c[filearrayindex_POINTERSDATTAB]);//24FBF0 - 2AA18C//?tab
		if (x_WORD_180660_VGA_type_resolution == 1)
		{
			x_WORD_E29DA_type_resolution = x_WORD_180660_VGA_type_resolution;
			x_WORD_180660_VGA_type_resolution = 8;
			/*
			x_DWORD_E9C3C = (Bit8u*)malloc(307200);
			*/
			//fix
			pre_x_DWORD_E9C3C = (Bit8u*)malloc(3000000);
			x_DWORD_E9C3C = &pre_x_DWORD_E9C3C[200000];
			//fix
			sub_6EB90(&filearray_2aa18c[filearrayindex_POINTERSDATTAB]);
			memset((void*)*xadatapald0dat2.var28_begin_buffer, 0, 768);
			if (x_WORD_180660_VGA_type_resolution & 1)
			{
				//v0 = sub_5BE80_test_pallette(*xadatapald0dat2.var28_begin_buffer, 0, 0, 0);
				//sub_72883_clear_graphics_320(/*(void*)x_DWORD_180628b_screen_buffer, */(void *)x_DWORD_180628b_screen_buffer, 0xC8u, sub_5BE80_test_pallette(*xadatapald0dat2.var28_begin_buffer, 0, 0, 0));
			}
			else
			{
				//v1 = sub_5BE80_test_pallette(*xadatapald0dat2.var28_begin_buffer, 0, 0, 0);
				//sub_728A9_clear_graphics_640(&x_DWORD_180628b_screen_buffer, 0x1E0u, sub_5BE80_test_pallette(*xadatapald0dat2.var28_begin_buffer, 0, 0, 0));//[351628d]3aa0a4,1E0,0
			}
			memset((void*)*xadatapald0dat2.var28_begin_buffer, 0, 768);
			sub_41A90_VGA_pallette_install(*xadatapald0dat2.var28_begin_buffer);
			if (x_WORD_180660_VGA_type_resolution & 1)
				sub_90D6E_VGA_set_video_mode_320x200_and_pallette(*xadatapald0dat2.var28_begin_buffer);
			else
				sub_90E07_VGA_set_video_mode_640x480_and_pallette(*xadatapald0dat2.var28_begin_buffer);
			sub_41A90_VGA_pallette_install(*xadatapald0dat2.var28_begin_buffer);
			x_BYTE_EB3A8 = sub_5BE80_test_pallette(*xadatapald0dat2.var28_begin_buffer, 0, 0, 0);
			//x_BYTE_EB3A8 = v2;
			if (x_WORD_180660_VGA_type_resolution & 1)
				sub_72883_clear_graphics_320(/*x_BYTE_EB3A8, */(void *)x_DWORD_180628b_screen_buffer, 0xC8u, x_BYTE_EB3A8);
			else
				sub_728A9_clear_graphics_640(x_DWORD_180628b_screen_buffer, 0x1E0u, x_BYTE_EB3A8);
			sub_8CEDF_install_mouse();
			sub_8CD27_set_cursor((*filearray_2aa18c[filearrayindex_POINTERSDATTAB].posistruct)[0]);
		}
	}
	sub_8CD27_set_cursor((*filearray_2aa18c[filearrayindex_POINTERSDATTAB].posistruct)[0]);
	return 0;//fix it sub_8CD27_set_cursor((Bit8u**)**filearray_2aa18c[0]);
}

//----- (00076160) --------------------------------------------------------
void sub_76160_play_intro(int16_t a1, int16_t a2, Bit8u* a3)//257160
{
	//fix
	//memset(&x_DWORD_180628b_screen_buffer[320 * 200], 0, 320*200);
	//fix
	FILE* tempfile; // eax
	//int16_t v4; // ax

	x_WORD_E12FC = a2;
	x_WORD_D4004 = 0;
	x_WORD_17DB58 = 0;
	x_WORD_17DB60 = 0;
	x_DWORD_E12F4 = x_DWORD_180628b_screen_buffer;
	tempfile = sub_98817_open(printbuffer, 512);
	x_DWORD_17DB38_intro_file_handle = tempfile;
	if (tempfile)
	{
		sub_988A7_read(tempfile, unk_17DB40, 12);//ecx=12
		x_WORD_17DB46 = *(Bit16s*)&unk_17DB40[6];
		x_WORD_17DB48 = *(Bit16s*)&unk_17DB40[8];
		x_WORD_17DB4A = *(Bit16s*)&unk_17DB40[0xa];

		x_WORD_180744_mouse_right_button = 0;
		x_WORD_180746_mouse_left_button = 0;
		x_DWORD_E1300 += 12;
		x_BYTE_1806E4 = 0;
		x_WORD_17DB5A = 0;
		sub_473B0();//2283b0
		x_WORD_17DB5C = a1;
		do
		{
			if (x_WORD_17DB5A)
				break;
			if (x_WORD_17DB60 >= x_WORD_17DB46 - 1)//34eb60 a 34eb46
				break;
			sub_1B280_run_intro_events(a3);//1fc280 - asi vykresleni textu
			/*v4 = */sub_75DB0();//256db0 - read header

			sub_75E70(/*v4*/);//256e70 - draw intro frame

			/*
			//debug
			int compsize;
			if (testcount > 0)
			{
				Bit8u origbyte = 0;
				Bit8u remakebyte = 0;
				compsize = compare_with_snapshot((char*)"0160-00256E70", x_DWORD_180628b_screen_buffer, 0x3aa0a4, 320 * 231, &origbyte, &remakebyte);
			}
			testcount++;
			//debug
			*/
			x_WORD_17DB60++;
		} while (x_BYTE_1806E4 != 1);
		sub_98882_close(x_DWORD_17DB38_intro_file_handle);
	}
}

//----- (00083850) --------------------------------------------------------
int sub_83850_show_welcome_screen()//264850
{
	signed int v0; // eax
	signed int v1; // ebx
	int v2; // edx
	int v3; // edx
	int v4; // esi
	int v5; // eax
	//int v6; // eax
	signed int v7; // eax

	//fix it
	v2 = 0;
	v3 = 0;
	//v7 = 0;
	
	//fix it

	sub_7AA70_load_and_decompres_dat_file(file_handling->getFilePath(MC2File::data_screens_hscreen0_dat).c_str(), x_DWORD_E9C38_smalltit, 0x178E5F, 0x32B9);
	sub_7AA70_load_and_decompres_dat_file(file_handling->getFilePath(MC2File::data_screens_hscreen0_dat).c_str(), *xadatapald0dat2.var28_begin_buffer, 0x17C118, 0x300);
	sub_7AA70_load_and_decompres_dat_file((char*)"\0", 0, 0, 0);
	//v0 = (int)sub_7AA70_load_and_decompres_dat_file(0, 0, 0, 0); //fix it
	v0 = 0;//fix it
	v1 = 0;
	v5 = j___clock();
	v4 = v5;
	//BYTE1(v5) = 0;
	x_BYTE_1806E4 = 0;
	while (!x_BYTE_1806E4 && !x_WORD_180746_mouse_left_button && !x_WORD_180744_mouse_right_button && (j___clock() - v4) / 0x64u <= 0x14)
	{
		if (x_WORD_180660_VGA_type_resolution & 1)
			sub_9A128_copy_screen_320(x_DWORD_E9C38_smalltit, x_DWORD_180628b_screen_buffer, 0xC8u);
		else
			sub_9A144_copy_screen_640(x_DWORD_E9C38_smalltit, x_DWORD_180628b_screen_buffer, 0x1E0u);
		if (v1)
		{
			if (x_WORD_180660_VGA_type_resolution & 1)
				sub_90478_VGA_Blit320();
			else
				sub_75200_VGA_Blit640(480);
		}
		else
		{
			v1 = 1;
			sub_728A9_clear_graphics_640((void*)x_DWORD_180628b_screen_buffer, 0x1E0u, 0);//fix
			sub_75200_VGA_Blit640(480);//fix
			/*LOWORD(v5) = */sub_90B27_VGA_pal_fadein_fadeout(*xadatapald0dat2.var28_begin_buffer, 0x20u, 0);
		}
	}
	/*LOWORD(v6) = */sub_90B27_VGA_pal_fadein_fadeout(0, 0x10u, 0);
	if (x_WORD_180660_VGA_type_resolution & 1)
		sub_72883_clear_graphics_320(/*x_DWORD_180628b_screen_buffer,*/ x_DWORD_180628b_screen_buffer, 0xC8u, 0);
	else
		sub_728A9_clear_graphics_640(x_DWORD_180628b_screen_buffer, 0x1E0u, 0);
	if (x_WORD_180660_VGA_type_resolution & 1)
		sub_90478_VGA_Blit320();
	else
		sub_75200_VGA_Blit640(480);
	while (sub_9A10A_check_keyboard(/*v7*/))
	{
		x_BYTE_1806E4 = 0;
		/*v7 = */sub_7A060_get_mouse_and_keyboard_events();
	}
	return j___delay(50);
}

//----- (00076D10) --------------------------------------------------------
void sub_76D10_intros(char a1)//257d10
{
	x_DWORD_17DE38str.x_DWORD_17DE54 = &x_D41A0_BYTEARRAY_4_struct.heapbuffer[0x49ADB];// 301787;
	x_DWORD_17DE38str.x_DWORD_17DEC0 = &x_D41A0_BYTEARRAY_4_struct.heapbuffer[0x4B52F];//308527;
	x_DWORD_17DE38str.x_DWORD_17DEC4 = &x_D41A0_BYTEARRAY_4_struct.heapbuffer[0x4BB8F];
	sub_7AA70_load_and_decompres_dat_file(file_handling->getFilePath(MC2File::data_screens_hscreen0_dat).c_str(), &x_D41A0_BYTEARRAY_4_struct.heapbuffer[0x49ADB], 0x164FCD, 0x35C);
	sub_7AA70_load_and_decompres_dat_file(file_handling->getFilePath(MC2File::data_screens_hscreen0_dat).c_str(), x_DWORD_17DE38str.x_DWORD_17DEC0, 0x165329, 0x224);
	sub_7AA70_load_and_decompres_dat_file(0, 0, 0, 0);
	if (x_WORD_180660_VGA_type_resolution & 1)
		sub_98709_create_index_dattab_power(x_DWORD_17DE38str.x_DWORD_17DEC0, x_DWORD_17DE38str.x_DWORD_17DEC4, x_DWORD_17DE38str.x_DWORD_17DE54, xy_DWORD_17DEC0_spritestr);
	else
		sub_9874D_create_index_dattab(x_DWORD_17DE38str.x_DWORD_17DEC0, x_DWORD_17DE38str.x_DWORD_17DEC4, x_DWORD_17DE38str.x_DWORD_17DE54, xy_DWORD_17DEC0_spritestr);

	sub_2EB40();
	if (x_BYTE_E3798_sound_active2 && x_D41A0_BYTEARRAY_4_struct.byteindex_179 == 2)
	{
		x_BYTE_D41C1 = 0;
		x_BYTE_D41C0 = 0;
	}
	else
	{
		x_BYTE_D41C0 = 1;
		x_BYTE_D41C1 = 1;
	}
	sub_8CD27_set_cursor((*filearray_2aa18c[filearrayindex_POINTERSDATTAB].posistruct)[0]);
	// TODO/FIXME: get rid of this global printbuffer
	std::strcpy(printbuffer, file_handling->getFilePath(MC2File::intro_intro_dat).c_str());
	switch (a1)
	{
	case 0:
#ifndef debug_hide_graphics
		sub_83850_show_welcome_screen();//frog logo and wait
#endif
		sub_76160_play_intro(1, 1, unk_E17CC_0);//257160 intro .. 2b27cc
		/*v1 = */sub_2EB40();
		x_BYTE_D41C1 = 0;
		x_BYTE_D41C0 = 0;
		while (sub_9A10A_check_keyboard(/*v1*/))
		{
			x_BYTE_1806E4 = 0;
			/*v1 = */sub_7A060_get_mouse_and_keyboard_events();
		}
		j___delay(50);
    std::strcpy(printbuffer, file_handling->getFilePath(MC2File::intro_intro2_dat).c_str());
		goto LABEL_17;
	case 1:
		sub_76160_play_intro(1, 1, unk_E17CC_0);
		break;
	case 2:
		x_BYTE_1806E4 = 0;
		x_BYTE_D41C1 = 0;
		x_BYTE_D41C0 = 0;
    std::strcpy(printbuffer, file_handling->getFilePath(MC2File::intro_intro2_dat).c_str());
	LABEL_17:
		sub_76160_play_intro(1, 1, unk_E17CC_0x160);//E192C
		break;
	}
	sub_90B27_VGA_pal_fadein_fadeout(0, 0x10u, 0);
	sub_8D8F0_sound_proc3_endsample();
	sub_8E020_sound_proc14_stopsequence();//?ac_sound_stop_music
	sub_7B5D0();
	//v2 = 0;
	x_WORD_E29D8 = 4;
	x_BYTE_D41C0 = 0;
	x_BYTE_D41C1 = 0;
	//v3 = sub_9A10A_check_keyboard(/*v2*/);
	if (sub_9A10A_check_keyboard(/*v2*/))
		/*v3 = */sub_7A060_get_mouse_and_keyboard_events();
	x_DWORD_17DE38str.x_BYTE_17DF11_last_key_status = 0;
	x_DWORD_17DE38str.x_BYTE_17DF10_get_key_scancode = 0;
	if (!a1)
		/*v3 = */sub_7AC00_load_and_set_graphics_and_pallette();
	//return v3;
}


//----- (00082670) --------------------------------------------------------
void sub_82670()//263670
{
	int16_t v0; // si
	//x_WORD *v1; // eax
	Bit16s v1x;
	Bit8s* v3; // ebx
	int16_t v4; // cx
	type_x_WORD_E2970* v5x; // edi
	int v6; // eax
	int v7; // eax
	int v8; // eax
	//char v10; // [esp+0h] [ebp-54h]
	uint8_t v11; // [esp+50h] [ebp-4h]

	//fix it
	v7 = 0;
	//fix it

	v0 = 0;
	v11 = x_WORD_180660_VGA_type_resolution;
	//LOWORD(v1) = (uint8_t)x_WORD_180660_VGA_type_resolution;
	x_BYTE_1806E4 = 0;
	if (!x_BYTE_E29E1)
	{
		//LOWORD(v1) = (uint16)x_D41A0_BYTEARRAY_4;
		if (!(x_D41A0_BYTEARRAY_4_struct.setting_byte1_22 & 0x10))
		{
			x_BYTE_D41C1 = 0;
			x_DWORD_17DE38str.x_DWORD_17DE48c = x_D41A0_BYTEARRAY_4_struct.heapbuffer.data();
			x_DWORD_17DE38str.x_DWORD_17DE54 = &x_D41A0_BYTEARRAY_4_struct.heapbuffer[301787];
			x_DWORD_17DE38str.x_DWORD_17DEC0 = &x_D41A0_BYTEARRAY_4_struct.heapbuffer[308527];
			x_DWORD_17DE38str.x_DWORD_17DEC4 = &x_D41A0_BYTEARRAY_4_struct.heapbuffer[310159];
			sub_7AA70_load_and_decompres_dat_file(file_handling->getFilePath(MC2File::data_screens_hscreen0_dat).c_str(), (Bit8u*)x_DWORD_17DE38str.x_DWORD_17DE54, 0x164FCD, 860);
			sub_7AA70_load_and_decompres_dat_file(file_handling->getFilePath(MC2File::data_screens_hscreen0_dat).c_str(), (Bit8u*)x_DWORD_17DE38str.x_DWORD_17DEC0, 0x165329, 548);
			sub_7AA70_load_and_decompres_dat_file(0, 0, 0, 0);
			//if (*(x_BYTE *)(2124 * D41A0_BYTESTR_0.word_0xc + x_D41A0_BYTEARRAY_0 + 11232) & 2 || x_D41A0_BYTEARRAY_4_struct.levelnumber_43 > 0x18u)
			if (D41A0_BYTESTR_0.array_0x2BDE[D41A0_BYTESTR_0.word_0xc].dw_w_b_0_2BDE_11230.byte[2] & 2 || x_D41A0_BYTEARRAY_4_struct.levelnumber_43w > 0x18u)
			{
				v3 = byte_E16E0;
				//LOWORD(v1) = 1;
				v1x = 1;
				while (*((x_BYTE *)v3 + 4))
				{
					if (x_D41A0_BYTEARRAY_4_struct.levelnumber_43w + 1 == *((uint8_t *)v3 + 4))
					{
						if (!*((x_BYTE *)v3 + 5))
						{
							v0 = v1x;
							*((x_BYTE *)v3 + 5) = 1;
						}
						break;
					}
					v3 += 7;
					v1x++;
				}
				if (!v0)
				{
					//LOWORD(v1) = (uint16)x_D41A0_BYTEARRAY_4;
					v4 = x_D41A0_BYTEARRAY_4_struct.levelnumber_43w;
					if ((uint16_t)v4 > 0x18u)
					{
						//v1 = sub_824E0(v4);
						v5x = sub_824E0(v4);
						if (v5x)
						{
							v3 = byte_E16E0;
							//LOWORD(v1) = 1;
							v1x = 1;
							while (*((x_BYTE *)v3 + 4))
							{
								if (v5x->word_4 + 1 == *((uint8_t *)v3 + 4))
								{
									if (!*((x_BYTE *)v3 + 5))
									{
										v0 = v1x;
										*((x_BYTE *)v3 + 5) = 1;
									}
									break;
								}
								//v3 = (void **)((char *)v3 + 7);
								v3 += 7;
								v1x++;
							}
						}
					}
				}
				if (v0)
				{
					if (x_D41A0_BYTEARRAY_4_struct.byteindex_179 == 2 && x_BYTE_E3798_sound_active2 || v0 >= 6)
					{
						x_BYTE_D41C1 = 0;
						x_BYTE_D41C0 = 0;
					}
					else
					{
						sub_2EB40();
						x_BYTE_D41C1 = 1;
						x_BYTE_D41C0 = 1;
					}
					sub_8CD27_set_cursor((*filearray_2aa18c[filearrayindex_POINTERSDATTAB].posistruct)[0]);
					memset((void*)x_DWORD_180628b_screen_buffer, 0, 640*480);
					if (x_WORD_180660_VGA_type_resolution != 1)
					{
						sub_54600_mouse_reset();
						v6 = (int)memset((void*)*xadatapald0dat2.var28_begin_buffer, 0, 768);
						if (x_WORD_180660_VGA_type_resolution & 1)
							sub_72883_clear_graphics_320((void *)x_DWORD_180628b_screen_buffer, 200, 0);
						else
							sub_728A9_clear_graphics_640((void *)x_DWORD_180628b_screen_buffer, 480, 0);
						sub_41A90_VGA_pallette_install(*xadatapald0dat2.var28_begin_buffer);
						x_WORD_180660_VGA_type_resolution = 1;
						sub_90D6E_VGA_set_video_mode_320x200_and_pallette(*xadatapald0dat2.var28_begin_buffer);
						sub_8CEDF_install_mouse();
						sub_8CD27_set_cursor((*filearray_2aa18c[filearrayindex_POINTERSDATTAB].posistruct)[0]);
					}

					if (x_WORD_180660_VGA_type_resolution & 1)
					{
						sub_98709_create_index_dattab_power(x_DWORD_17DE38str.x_DWORD_17DEC0, x_DWORD_17DE38str.x_DWORD_17DEC4, x_DWORD_17DE38str.x_DWORD_17DE54, xy_DWORD_17DEC0_spritestr);
					}
					else
					{
						sub_9874D_create_index_dattab(x_DWORD_17DE38str.x_DWORD_17DEC0, x_DWORD_17DE38str.x_DWORD_17DEC4, x_DWORD_17DE38str.x_DWORD_17DE54, xy_DWORD_17DEC0_spritestr);
					}

					sprintf(printbuffer2, "intro\\cut%d.dat", *((uint8_t *)v3 + 6));
					sprintf(printbuffer, printbuffer2);
					sub_76160_play_intro(0, 1, *((Bit32s*)v3) - 0x2b2328 + (Bit8u*)array_E1328);
					/*sprintf(printbuffer, "intro\\cut4.dat");
					sub_76160_play_intro(0, 1, 0 + (Bit8u*)array_E1328);*/

					sub_90B27_VGA_pal_fadein_fadeout(0, 0x10u, 0);
					sub_8D8F0_sound_proc3_endsample();
					sub_8E020_sound_proc14_stopsequence();
					sub_7B5D0();
					if (x_WORD_180660_VGA_type_resolution & 1)
						sub_72883_clear_graphics_320(/*v7, */(void *)x_DWORD_180628b_screen_buffer, 0xC8u, 0);
					else
						sub_728A9_clear_graphics_640((void *)x_DWORD_180628b_screen_buffer, 0x1E0u, 0);
					if (x_WORD_180660_VGA_type_resolution & 1)
						sub_90478_VGA_Blit320();
					else
						sub_75200_VGA_Blit640(480);
					//LOWORD(v1) = v11;
					if (v11 != x_WORD_180660_VGA_type_resolution)
					{
						sub_54600_mouse_reset();
						v8 = (int)memset((void*)*xadatapald0dat2.var28_begin_buffer, 0, 768);
						if (x_WORD_180660_VGA_type_resolution & 1)
							sub_72883_clear_graphics_320(/*v8, */(void *)x_DWORD_180628b_screen_buffer, 0xC8u, 0);
						else
							sub_728A9_clear_graphics_640((void *)x_DWORD_180628b_screen_buffer, 0x1E0u, 0);
						sub_41A90_VGA_pallette_install(*xadatapald0dat2.var28_begin_buffer);
						x_WORD_180660_VGA_type_resolution = v11;
						if (v11 & 1)
							sub_90D6E_VGA_set_video_mode_320x200_and_pallette(*xadatapald0dat2.var28_begin_buffer);
						else
							sub_90E07_VGA_set_video_mode_640x480_and_pallette(*xadatapald0dat2.var28_begin_buffer);
						sub_8CEDF_install_mouse();
						// fix it//LOWORD(v1) = sub_8CD27_set_cursor((Bit8u**)*filearray_2aa18c[0]);
						sub_8CD27_set_cursor((*filearray_2aa18c[filearrayindex_POINTERSDATTAB].posistruct)[0]);
					}
				}
			}
		}
	}
	x_BYTE_D41C1 = 0;
	//return (int16_t)v1;
}

//----- (0007ADE0) --------------------------------------------------------
int sub_7ADE0(char a1)//25bde0
{
	char v1; // al
	uint8_t v2; // al
	uint8_t v3; // al

	if (a1 == 1)
	{
		/*if (x_DWORD_E9C3C)
		{
			sub_83E80_freemem4(x_DWORD_E9C3C);
			x_DWORD_E9C3C = 0;
		}
		*/
		//fix
		if (pre_x_DWORD_E9C3C)
		{
			sub_83E80_freemem4(pre_x_DWORD_E9C3C);
			pre_x_DWORD_E9C3C = 0;
			x_DWORD_E9C3C = 0;
		}
		//fix
		sub_54600_mouse_reset();//mouse reset
		sub_6EBF0(&filearray_2aa18c[filearrayindex_POINTERSDATTAB]);
		x_WORD_180660_VGA_type_resolution = 1;
		x_WORD_E29DA_type_resolution = 1;
		/*
		x_DWORD_E9C3C = (Bit8u*)malloc(64000);
		*/
		//fix
		pre_x_DWORD_E9C3C = (Bit8u*)malloc(3000000);
		x_DWORD_E9C3C = &pre_x_DWORD_E9C3C[2000000];
		//fix
		//sub_6EB90(&*filearray_2aa18c[0]);
		sub_6EB90(&(filearray_2aa18c[filearrayindex_POINTERSDATTAB]));
		memset((void*)*xadatapald0dat2.var28_begin_buffer, 0, 768);
		if (x_WORD_180660_VGA_type_resolution & 1)
		{
			v1 = sub_5BE80_test_pallette(*xadatapald0dat2.var28_begin_buffer, 0, 0, 0);
			sub_72883_clear_graphics_320(/*(int)x_DWORD_180628b_screen_buffer, */(void *)x_DWORD_180628b_screen_buffer, 0xC8u, v1);
		}
		else
		{
			v2 = sub_5BE80_test_pallette(*xadatapald0dat2.var28_begin_buffer, 0, 0, 0);
			sub_728A9_clear_graphics_640((void *)x_DWORD_180628b_screen_buffer, 0x1E0u, v2);
		}
		memset((void*)*xadatapald0dat2.var28_begin_buffer, 0, 768);
		sub_41A90_VGA_pallette_install(*xadatapald0dat2.var28_begin_buffer);
		if (x_WORD_180660_VGA_type_resolution & 1)
			sub_90D6E_VGA_set_video_mode_320x200_and_pallette(*xadatapald0dat2.var28_begin_buffer);
		else
			sub_90E07_VGA_set_video_mode_640x480_and_pallette(*xadatapald0dat2.var28_begin_buffer);
		sub_41A90_VGA_pallette_install(*xadatapald0dat2.var28_begin_buffer);
		v3 = sub_5BE80_test_pallette(*xadatapald0dat2.var28_begin_buffer, 0, 0, 0);
		x_BYTE_EB3A8 = v3;
		if (x_WORD_180660_VGA_type_resolution & 1)
			sub_72883_clear_graphics_320(/*v3, */(void *)x_DWORD_180628b_screen_buffer, 0xC8u, v3);
		else
			sub_728A9_clear_graphics_640((void *)x_DWORD_180628b_screen_buffer, 0x1E0u, v3);
		sub_8CEDF_install_mouse();
	}
	sub_8CD27_set_cursor((*filearray_2aa18c[filearrayindex_POINTERSDATTAB].posistruct)[0]);
	return 0;//fix it sub_8CD27_set_cursor((Bit8u**)**filearray_2aa18c[0]);
}

//----- (00076A40) --------------------------------------------------------
void sub_76A40_lang_setting()//257A40
{
	FILE* configdatfile; // ebx
	//int v1; // edi
	//Bit16s index; // si
	FILE* langfile; // eax
	//FILE* v4; // ebx
	//FILE* v5; // edi
	Bit32u filelenght; // esi
	//int result; // eax
	//char v8; // [esp+0h] [ebp-42h]
	//char v9; // [esp+50h] [ebp+Eh]
	Bit8u v10[32]; // [esp+A0h] [ebp+5Eh]
	//Bit8u v11[100]; // [esp+A4h] [ebp+62h]
	//int v12; // [esp+B4h] [ebp+72h]
	//int16_t v13; // [esp+BEh] [ebp+7Ch]
	Bit32s configdword1; // [esp+C0h] [ebp+7Eh]

	//fix
	//v10 = 0;
	//fix

	configdword1 = 0;
	memset(&x_DWORD_17DE38str, 0, 613);//fix it
	x_DWORD_17DE38str.x_DWORD_17DEE0_filedesc = NULL;
	memset(v10, 0, 32);
	configdatfile = sub_98817_open(file_handling->getFilePath(MC2File::config_dat).c_str(), 512);
	if (configdatfile == NULL)//config is not found
	{
		sub_7AC00_load_and_set_graphics_and_pallette();//25BC00 //zmena pomeru obrazovky
		sub_779E0_lang_setting_dialog(0);//2589E0 //nastaveni jazyka
		sub_7ADE0(1);//25BDE0x_D41A0_BYTEARRAY_4_struct.setting_216
	}
	else
	{
		sub_988A7_read(configdatfile, (Bit8u*)&configdword1, 4);//prvni dword
		if (configdword1 == 0xfffffff7)
		{
			sub_988A7_read(configdatfile, (Bit8u*)&v10[4], 28);

			x_D41A0_BYTEARRAY_4_struct.dwordindex_0 = *(Bit32u*)&v10[0];
			x_D41A0_BYTEARRAY_4_struct.wordindex_4 = *(Bit16u*)&v10[4];
			x_D41A0_BYTEARRAY_4_struct.wordindex_6 = *(Bit16u*)&v10[6];
			x_D41A0_BYTEARRAY_4_struct.wordindex_8 = *(Bit16u*)&v10[8];
			x_D41A0_BYTEARRAY_4_struct.byteindex_10 = *(Bit8u*)&v10[10];
			x_D41A0_BYTEARRAY_4_struct.byte_brightness_11 = *(Bit8u*)&v10[11];
			x_D41A0_BYTEARRAY_4_struct.byte_brightness_12 = *(Bit8u*)&v10[12];
			x_D41A0_BYTEARRAY_4_struct.byte_brightness_13 = *(Bit8u*)&v10[13];
			x_D41A0_BYTEARRAY_4_struct.wordindex_14 = *(Bit16u*)&v10[14];
			x_D41A0_BYTEARRAY_4_struct.dwordindex_16 = *(Bit32u*)&v10[16];
			*x_D41A0_BYTEARRAY_4_struct.stubb = *(Bit16u*)&v10[20];

			x_BYTE_EB39E_keys[0] = *(Bit8u*)&v10[22];
			x_BYTE_EB39E_keys[1] = *(Bit8u*)&v10[23];
			x_BYTE_EB39E_keys[2] = *(Bit8u*)&v10[24];
			x_BYTE_EB39E_keys[3] = *(Bit8u*)&v10[25];
			x_BYTE_EB39E_keys[4] = *(Bit8u*)&v10[26];
			x_BYTE_EB39E_keys[5] = *(Bit8u*)&v10[27];
			x_BYTE_EB39E_keys[6] = *(Bit8u*)&v10[28];
			x_BYTE_EB39E_keys[7] = *(Bit8u*)&v10[29];
			x_BYTE_EB39E_keys[8] = *(Bit8u*)&v10[30];
			x_BYTE_EB39E_keys[9] = *(Bit8u*)&v10[31];

			sub_98882_close(configdatfile);
			sub_8E470_sound_proc17_volume(x_D41A0_BYTEARRAY_4_struct.wordindex_6);
			sub_8E410_sound_proc16_xmidivolume(x_D41A0_BYTEARRAY_4_struct.wordindex_8);

    		std::filesystem::path path_language = gamepath / "LANGUAGE" / (std::string("L") + std::to_string(x_D41A0_BYTEARRAY_4_struct.wordindex_4) + ".TXT");
			for (Bit16s i = 0;i < 2;i++)
				//i = 0;
				//while (i < 2 )
			{
				x_D41A0_BYTEARRAY_4_struct.byteindex_179 = x_D41A0_BYTEARRAY_4_struct.wordindex_4 & 0xff;
				if (x_BYTE_E29E0 || x_DWORD_D41BC_langbuffer)
					sub_83E80_freemem4((Bit8u*)x_DWORD_D41BC_langbuffer);
				langfile = sub_98817_open(path_language.c_str(), 512);
				//v4 = v3;
				//v5 = v3;
				if (langfile != NULL)
				{
					filelenght = x_filelength(langfile) - 4785;
					x_DWORD_D41BC_langbuffer = (char*)malloc(filelenght);
					if (x_DWORD_D41BC_langbuffer)
					{
						sub_9891E_seek(langfile, 4785, 0);
						sub_988A7_read(langfile, (Bit8u*)x_DWORD_D41BC_langbuffer, filelenght);
					}
					sub_98882_close(langfile);
					sub_5B870_copy_sentence(x_DWORD_D41BC_langbuffer, x_DWORD_E9C4C_langindexbuffer, 471);//Exit Game
					break;
				}
				//i++;
        path_language = gamepath / "LANGUAGE" / (std::string("L") + std::to_string(x_D41A0_BYTEARRAY_4_struct.byteindex_179) + ".TXT");
			}
		}
		else
		{
			sub_98882_close(configdatfile);
			sub_7AC00_load_and_set_graphics_and_pallette();
			sub_779E0_lang_setting_dialog(0);
			sub_7ADE0(1);
		}
	}
	//result = (uint8)x_D41A0_BYTEARRAY_4;
	if (x_D41A0_BYTEARRAY_4_struct.byteindex_179 != 2 || !x_BYTE_E3798_sound_active2)
		x_BYTE_D41C0 = 1;
	x_WORD_E29D8 = 1;
	//return result;
}


//----- (0007BEC0) --------------------------------------------------------
void sub_7BEC0()//25cec0
{
	Bit8u* result; // eax
	uint8_t v1; // dl

	for (result = off_E1BAC; *((Bit16u*)result + 5); result += 44)
	{
		*((Bit16u*)result + 4) = 0;
		v1 = result[22];
		result[24] = 0;
		if (v1 >= 7u)
		{
			if (v1 <= 7u)
			{
				result[23] = x_D41A0_BYTEARRAY_4_struct.setting_216w != 0;
			}
			else if (v1 == 13)
			{
				result[23] = 1;
			}
		}
	}
	//return result;
	/*
	for (Bit32u i=0; *(Bit32u*)(off_E1BAC+i+10); i += 0x2c)//2b2bac
	{
		*(Bit32u*)(off_E1BAC + i + 8) = 0;
		*(off_E1BAC + i + 18) = 0;
		if (*(off_E1BAC + i + 16) >= 7u)
		{
			if (*(off_E1BAC + i + 16) <= 7u)
			{
				*(off_E1BAC + i + 17) = (x_D41A0_BYTEARRAY_4_struct.setting_216 != 0);
			}
			else if (*(off_E1BAC + i + 16) == 13)
			{
				*(off_E1BAC + i + 17) = 1;
			}
		}
	}*/
}

void /*__fastcall*/ _wcpp_1_unwind_leave__131() {//257d00
	stub_fix_it();
};// weak

//----- (00076930) --------------------------------------------------------
void sub_76930_menus_and_intros(int a2, Bit16u a3)//257930
{
	//int v3; // eax
	int v4; // edx

	//fix it
	v4 = 0;
	//fix it

	//x_BYTE_E29DE = x_WORD_180660_VGA_type_resolution;//1 -351660
	x_BYTE_E29DF_skip_screen = x_BYTE_D41AD_skip_screen;
	x_WORD_E29DC = 0;
	if (x_BYTE_D41AD_skip_screen == 1 || x_WORD_E29D8)
	{
		sub_82670();
		sub_7AC00_load_and_set_graphics_and_pallette();
	}
	if (x_BYTE_D41AD_skip_screen == 1)
	{
		sub_76A40_lang_setting();
		x_WORD_E29D8 = 4;
	}
	memset(&x_DWORD_17DE38str, 0, 613);
	x_DWORD_17DE38str.x_DWORD_17DEE0_filedesc = NULL;
	sub_7BEC0();//25CEC0 // fix this structure
	sub_6EDB0_set_mouse_position_by_res();//24FDB0
	/*v3 = */sub_81DB0_read_config();//262DB0

	//test_x_D41A0_BYTEARRAY_0();

	do
	{
		//x_WORD_E29D8 - prvni pruchod -0
		//v3 = x_WORD_E29D8;//2b39d8
		switch (x_WORD_E29D8)
		{
		case 0:
			/*v3 = */sub_76A40_lang_setting();//257A40 //asi inicializace + rovnou i nastaveni jazyka
			break;
		case 1:
	    x_WORD_E29D8 = 3;
			break;
		case 2:
			/*v3 = */_wcpp_1_unwind_leave__131(/*v3*/);//257d00 asi konec
			break;
		case 3:
			sub_76D10_intros(0);//257d10 intro		  
			x_WORD_E29D8 = 4;
			break;
		case 4:
			#ifdef EDITOR
			if(config_EDITOR)
						editor_run();//test editor
			#endif EDITOR
			//v3 = sub_76FA0_main_menu(v3, v4, a3);//257fa0 main menu loop
			sub_76FA0_main_menu(v4, a3);//257fa0 main menu loop
			break;
		case 5:
			x_WORD_E29DC = 1;
			break;
		case 12:
			sub_779E0_lang_setting_dialog(0);//2589e0 asi herni smycka
			break;
		default:
			break;
		}
	} while (!x_WORD_E29DC);
	sub_7ADE0(x_BYTE_E29DE);//zase nejaka inicializace
	if (x_BYTE_E29E1)
		x_BYTE_E29E1 = false;
	sub_81DB0_read_config();//neco
}


//----- (00083250) --------------------------------------------------------
void sub_83250_play_intros(char a1)//264250
{
	int v1; // eax

	sub_8CD27_set_cursor((*filearray_2aa18c[filearrayindex_POINTERSDATTAB].posistruct)[0]);
	memset((void*)x_DWORD_180628b_screen_buffer, 0, 307200);
	if (x_WORD_180660_VGA_type_resolution != 1)
	{
		sub_54600_mouse_reset();
		memset((void*)*xadatapald0dat2.var28_begin_buffer, 0, 768);
		x_WORD_180660_VGA_type_resolution = 1;
		sub_90D6E_VGA_set_video_mode_320x200_and_pallette(*xadatapald0dat2.var28_begin_buffer);
		sub_8CEDF_install_mouse();
		sub_8CD27_set_cursor((*filearray_2aa18c[filearrayindex_POINTERSDATTAB].posistruct)[0]);
	}
	sub_76D10_intros(a1);
	sub_54600_mouse_reset();
	v1 = (int)memset((void*)*xadatapald0dat2.var28_begin_buffer, 0, 768);
	BYTE1(v1) = x_WORD_180660_VGA_type_resolution;
	if (x_WORD_180660_VGA_type_resolution & 1)
		sub_72883_clear_graphics_320(/*v1, */(void *)x_DWORD_180628b_screen_buffer, 0xC8u, 0);
	else
		sub_728A9_clear_graphics_640((void *)x_DWORD_180628b_screen_buffer, 0x1E0u, 0);
	sub_41A90_VGA_pallette_install(*xadatapald0dat2.var28_begin_buffer);
	x_WORD_180660_VGA_type_resolution = 8;
	sub_90E07_VGA_set_video_mode_640x480_and_pallette(*xadatapald0dat2.var28_begin_buffer);
	sub_8CEDF_install_mouse();
	sub_8CD27_set_cursor((*filearray_2aa18c[filearrayindex_POINTERSDATTAB].posistruct)[0]);
	sub_6EDB0_set_mouse_position_by_res();
	sub_7A110_load_hscreen(x_WORD_180660_VGA_type_resolution, 4);
	sub_7B5A0_disable_enable();
	sub_8CD27_set_cursor(xy_DWORD_17DED4_spritestr[39]);
	x_DWORD_17DE38str.x_WORD_17DEEE_mouse_buttons = 0;
	x_DWORD_17DE38str.x_BYTE_17DF10_get_key_scancode = 0;
	sub_84300_load_sound(0);
}



//----- (00076FA0) --------------------------------------------------------
void sub_76FA0_main_menu(int a2, Bit16u a3x)
{
	int16_t v4; // dx
	int v6; // eax
	int v7; // edx
	int v8; // edx
	int v9; // edx
	uint16_t v10; // di
	uint16_t v12; // si
	int v13; // eax
	Bit8u* v15; // esi
	int v16; // edx
	char v18; // dh
	int v20; // edx
	int v22; // edx
	int v23; // edx
	int v26; // [esp+1Ch] [ebp-8h]
	int v27; // [esp+20h] [ebp-4h]

	v4 = 0;
	v7 = 0;
	v8 = 0;
	v9 = 0;
	v16 = 0;
	v20 = 0;
	v22 = 0;
	v23 = 0;

	help_VGA_type_resolution = 0;

	sub_86860_speak_Sound(x_WORD_1803EC);//267860
	sub_84300_load_sound(0);//265300
	memset(&x_DWORD_17DBB8, 0, 16);
	x_BYTE_17DBC6 = 2;
	x_DWORD_17DE38str.x_WORD_17DF04 = -1;
	x_DWORD_17DE38str.x_DWORD_17DE44 = x_DWORD_E9C38_smalltit;
	sub_6EDB0_set_mouse_position_by_res();
	sub_8E020_sound_proc14_stopsequence();//26f020
	sub_8E160_sound_proc15_startsequence(4, 0x7Fu);//26f160
	a3x = 256;
	x_WORD_17DE26 = v4;
	VGA_cleanKeyBuffer();
	if (x_BYTE_E29E1 || x_D41A0_BYTEARRAY_4_struct.setting_byte1_22 & 0x10 || (sub_77350_new_game_dialog(0), !x_WORD_E29DC))
	{
		x_D41A0_BYTEARRAY_4_struct.setting_byte1_22 &= 0xEFu;
		sub_7A110_load_hscreen(x_WORD_180660_VGA_type_resolution, 4);
		sub_7B5A0_disable_enable();
		
		sub_8CD27_set_cursor(xy_DWORD_17DED4_spritestr[39]);
		x_DWORD_17DE38str.x_BYTE_17DF13 = x_D41A0_BYTEARRAY_4_struct.byteindex_10;
		v6 = x_DWORD_17DE38str.x_BYTE_17DF13;
		x_DWORD_17DBB8[0] = j___clock();
		v26 = j___clock();
		v10 = x_DWORD_17DE38str.x_DWORD_17DEE4_mouse_positionx;
		v12 = x_DWORD_17DE38str.x_DWORD_17DEE8_mouse_positiony;
		v27 = x_DWORD_17DE38str.x_BYTE_17DF10_get_key_scancode;
		while (!x_WORD_E29DC)
		{
			v13 = j___clock();
			if ((v10 == x_DWORD_17DE38str.x_DWORD_17DEE4_mouse_positionx) && (v12 == x_DWORD_17DE38str.x_DWORD_17DEE8_mouse_positiony) && (x_DWORD_17DE38str.x_BYTE_17DF10_get_key_scancode == v27))
			{
				if ((v13 - v26) / 0x64u > 0x3C)//after any time run intro
				{
					v15 = x_DWORD_E9C38_smalltit;
					x_DWORD_E9C38_smalltit = x_DWORD_17DE38str.x_DWORD_17DE44;
					sub_83250_play_intros(SBYTE1(a3x));
					x_DWORD_E9C38_smalltit = v15;
					BYTE1(a3x) = (BYTE1(a3x) == 1) + 1;
					v12 = x_DWORD_17DE38str.x_DWORD_17DEE8_mouse_positiony;
					v10 = x_DWORD_17DE38str.x_DWORD_17DEE4_mouse_positionx;
					x_DWORD_17DE38str.x_BYTE_17DF10_get_key_scancode = 0;
					v27 = 0;
					v26 = j___clock();
					sub_8E020_sound_proc14_stopsequence();
					LOBYTE(a3x) = 0;
					sub_8E160_sound_proc15_startsequence(4, 0x7Fu);
				}
			}
			else
			{
				v12 = x_DWORD_17DE38str.x_DWORD_17DEE8_mouse_positiony;
				v10 = x_DWORD_17DE38str.x_DWORD_17DEE4_mouse_positionx;
				v27 = x_DWORD_17DE38str.x_BYTE_17DF10_get_key_scancode;
				v26 = j___clock();
			}
			if (x_DWORD_17DE38str.x_BYTE_17DF10_get_key_scancode == 59)
			{
				//v17 = x_D41A0_BYTEARRAY_4;
				v18 = x_D41A0_BYTEARRAY_4_struct.byteindex_10;
				x_D41A0_BYTEARRAY_4_struct.byteindex_10 = v18 != 1;
				x_DWORD_17DE38str.x_BYTE_17DF13 = v18 != 1;
				//*(x_BYTE *)(v17 + 38402) = 1;
				x_D41A0_BYTEARRAY_4_struct.setting_38402 = 1;
			}
			if (x_WORD_180660_VGA_type_resolution & 1)
				sub_9A128_copy_screen_320(x_DWORD_E9C38_smalltit, x_DWORD_180628b_screen_buffer, 0xC8u);
			else
				sub_9A144_copy_screen_640(x_DWORD_E9C38_smalltit, x_DWORD_180628b_screen_buffer, 0x1E0u);

			/*v19 = */sub_7C120_draw_bitmap_640(185, 232, xy_DWORD_17DED4_spritestr[66]);//adress 25827a
			//ax,ebx,a3
			//6038,100,4?
			/*v21 = */sub_7AB00_draw_menu_animations(/*v19,*/ /*v20,*/ /*(Bit16s*)a3x,*/ 4u);//25bb00
			if (sub_7B250_draw_and_serve(/*(int)v21, v22*/))//25c250
			{
				v12 = x_DWORD_17DE38str.x_DWORD_17DEE8_mouse_positiony;
				v10 = x_DWORD_17DE38str.x_DWORD_17DEE4_mouse_positionx;
				LOBYTE(a3x) = 0;
				v27 = x_DWORD_17DE38str.x_BYTE_17DF10_get_key_scancode;
				v26 = j___clock();
			}
			if (LOBYTE(a3x))
			{
				if (x_WORD_180660_VGA_type_resolution & 1)
					sub_90478_VGA_Blit320();
				else
					sub_75200_VGA_Blit640(480);
			}
			else
			{
				LOBYTE(a3x) = 1;
				//34ee38 20 0
				sub_90B27_VGA_pal_fadein_fadeout(x_DWORD_17DE38str.x_DWORD_17DE38, 0x20u, 0);//tady
			}
			/*v11 = */sub_7A060_get_mouse_and_keyboard_events();

			//test_x_D41A0_BYTEARRAY_0();
		}
		sub_41BC0();

		//x_D41A0_BYTEARRAY_0[8592] = 0;
		D41A0_BYTESTR_0.str_0x218A_settings.str_0x218E.scr_size_0x2190 = 0;
		
		//dos_setvect(9, x_DWORD_17DE22, x_WORD_17DE26);
		sub_753D0();
		//result = (int)x_DWORD_17DE44;
		x_DWORD_E9C38_smalltit = x_DWORD_17DE38str.x_DWORD_17DE44;
	}
	else
	{
		sub_41BC0();
		
		//x_D41A0_BYTEARRAY_0[8592] = 0;
		D41A0_BYTESTR_0.str_0x218A_settings.str_0x218E.scr_size_0x2190 = 0;

		//dos_setvect(9, x_DWORD_17DE22, x_WORD_17DE26);
		/*result = */sub_753D0();
	}
	//  return result;
}
