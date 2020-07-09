#pragma once

#include <cstddef>
#include <string>
#include <vector>
#include <filesystem>
#include <unordered_map>

#include "../dosbox_files/config.h"

namespace remc2 {

using std::string;
using std::filesystem::path;

typedef std::vector<std::byte> filedata_t;

enum class MC2File {
    data_bl16c00_dat,
    data_bl16f00_dat,
    data_bl16n00_dat,
    data_bl32c00_dat,
    data_bl32f00_dat,
    data_bl32n00_dat,
    data_bl128c00_dat,
    data_bl128f00_dat,
    data_bl128n00_dat,
    data_bldgprm_dat,
    data_block128_dat,
    data_block16_dat,
    data_block32_dat,
    data_clrd0_dat,
    data_gtd2_dat,
    data_hscreen0_dat,
    data_pald0_dat,
    data_screens_hscreen0_dat,
    data_search_dat,
    data_skyd00_dat,
    data_skyn00_dat,
    data_smatitl2_dat,
    data_smatitl2_pal,
    data_smatitle_dat,
    data_smatitle_pal,
    data_spells_dat,
    data_tablesc_dat,
    data_tablesd_dat,
    data_tablesn_dat,
    data_tmaps00_dat,
    data_tmaps10_dat,
    data_tmaps20_dat,
    data_tmaps00_tab,
    data_tmaps10_tab,
    data_tmaps20_tab,

    cdata_tmaps00_dat,
    cdata_tmaps10_dat,
    cdata_tmaps20_dat,
    cdata_tmaps00_tab,
    cdata_tmaps10_tab,
    cdata_tmaps20_tab,
    cdata_version_dat,

    levels_levels_dat,
    levels_levels_tab,

    clevels_levels_dat,
    clevels_levels_tab,

    config_dat,

    intro_intro_dat,
    intro_intro2_dat,
};
//file_handling->getFilePath(MC2File::data_search_dat).c_str()

typedef struct {
    path file_path;
    filedata_t file_data;
    filedata_t file_data_decompressed;
} MC2FileInfo;

enum class MC2Asset {
    sprite0,
};

typedef struct {
    MC2File mc2file;
    int position;
    int lengh;
} MC2AssetInfo;

/*    
Bit8u* x_DWORD_E9C38_smalltit;

Pathstruct xasearchd_2bac30 = { "*SearchD\0",&SEARCH_BEGIN_BUFFER,&SEARCH_END_BUFFER,0x1000,NULL };
#define psxasearchd_2bac30 0
Pathstruct xafonts0dat = { "DATA/FONT0.DAT\0",&FONTS0DAT_BEGIN_BUFFER,NULL,NULL,NULL };
#define psxafonts0dat 1
Pathstruct xafonts0tab = { "DATA/FONT0.TAB\0",&FONTS0TAB_BEGIN_BUFFER,&FONTS0TAB_END_BUFFER,NULL,NULL };
#define psxafonts0tab 2
Pathstruct xafonts1dat = { "DATA/FONT1.DAT\0",&FONTS1DAT_BEGIN_BUFFER,NULL,NULL,NULL };
#define psxafonts1dat 3
Pathstruct xafonts1tab = { "DATA/FONT1.TAB\0",&FONTS1TAB_BEGIN_BUFFER,&FONTS1TAB_END_BUFFER,NULL,NULL };
#define psxafonts1tab 4
Pathstruct xadatatmaps00tab = { "DATA/TMAPS0-0.TAB",&TMAPS00TAB_BEGIN_BUFFER,NULL,NULL,NULL };
#define psxadatatmaps00tab 5
Pathstruct xapaldata = { "*PalData\0",&PALDATA_BEGIN_BUFFER,NULL,0x400,NULL };
#define psxapaldata 6
Pathstruct xapalmem = { "*PalMem\0",&PALMEM_BEGIN_BUFFER,NULL,NULL,NULL };
#define psxapalmem 7
Pathstruct xadatapointersdat = { "DATA/POINTERS.DAT\0",&POINTERSDAT_BEGIN_BUFFER,NULL,NULL,NULL };
#define psxadatapointersdat 8
Pathstruct xadatapointerstab = { "DATA/POINTERS.TAB\0",&POINTERSTAB_BEGIN_BUFFER,&POINTERSTAB_END_BUFFER,NULL,NULL };
#define psxadatapointerstab 9
Pathstruct xazero = { "\0",NULL,NULL,NULL,NULL };
#define psxazero0 10
Pathstruct xadatabuild00dat = { "DATA/BUILD0-0.DAT\0",&BUILD00DAT_BEGIN_BUFFER,NULL,NULL,NULL };
#define psxadatabuild00dat 11
Pathstruct xadatabuild00tab = { "DATA/BUILD0-0.TAB\0",&BUILD00TAB_BEGIN_BUFFER,&BUILD00TAB_END_BUFFER,NULL,NULL };
#define psxadatabuild00tab 12
//zero
#define psxazero1 13
Pathstruct xadataetextdat = { "DATA/ETEXT.DAT\0",&ETEXT_BEGIN_BUFFER,NULL,NULL,NULL };
#define psxadataetextdat 14
//zero
#define psxazero2 15
Pathstruct xadataftextdat = { "DATA/FTEXT.DAT\0",&FTEXT_BEGIN_BUFFER,NULL,NULL,NULL };
#define psxadataftextdat 16
//zero
#define psxazero3 17
Pathstruct xadatagtextdat = { "DATA/GTEXT.DAT\0",&GTEXT_BEGIN_BUFFER,NULL,NULL,NULL };
#define psxadatagtextdat 18
//zero
#define psxazero4 19
Pathstruct xadataitextdat = { "DATA/ITEXT.DAT\0",&ITEXT_BEGIN_BUFFER,NULL,NULL,NULL };
#define psxadataitextdat 20
//zero
#define psxazero5 21
Pathstruct xadatablock16dat = { "DATA/BLOCK16.DAT\0",&BLOCK16DAT_BEGIN_BUFFER,NULL,NULL,NULL };
#define psxadatablock16dat 22
Pathstruct xadatablock32dat = { "DATA/BLOCK32.DAT\0",&BLOCK32DAT_BEGIN_BUFFER,NULL,NULL,NULL };
#define psxadatablock32dat 23
//zero
#define psxazero6 24
Pathstruct xabscreen = { "*BScreen\0",&BSCREEN_BEGIN_BUFFER,&BSCREEN_END_BUFFER,0x011508,NULL };
#define psxabscreen 25
Pathstruct xadatapald0dat = { "DATA/PALD-0.DAT\0",&PALD0DAT_BEGIN_BUFFER,NULL,NULL,NULL };
#define psxadatapald0dat 26
//zero
#define psxazero7 27
Pathstruct xawscreen_351628 = { "*WScreen\0",&WSCREEN_BEGIN_BUFFER,&WSCREEN_END_BUFFER,0x04b100,NULL };
#define psxawscreen_351628 28
Pathstruct xabscreen2 = { "*BScreen\0",&x_DWORD_E9C38_smalltit,&BSCREEN2_END_BUFFER,0x11170,NULL }; //0x011508
#define psxabscreen2 29

Pathstruct xadatapald0dat2 = { "DATA/PALD-0.DAT\0",&PALD0DAT2_BEGIN_BUFFER,NULL,NULL,NULL };
#define psxadatapald0dat2 30
//zero
#define psxazero8 31
Pathstruct xadatamsprd00dat = { "DATA/MSPRD0-0.DAT\0",&MSPRD00DAT_BEGIN_BUFFER,NULL,NULL,NULL };
#define psxadatamsprd00dat 32
Pathstruct xadatamsprd00tab = { "DATA/MSPRD0-0.TAB\0",&MSPRD00TAB_BEGIN_BUFFER,&MSPRD00TAB_END_BUFFER,NULL,NULL };
#define psxadatamsprd00tab 33
//zero
#define psxazero9 34
Pathstruct xadatahsprd00dat = { "DATA/HSPRD0-0.DAT\0",&HSPRD00DAT_BEGIN_BUFFER,NULL,NULL,NULL };
#define psxadatahsprd00dat 35
Pathstruct xadatahsprd00tab = { "DATA/HSPRD0-0.TAB\0",&HSPRD00TAB_BEGIN_BUFFER,&HSPRD00TAB_END_BUFFER,NULL,NULL };
#define psxadatahsprd00tab 36
Pathstruct xadatahfont3dat = { "DATA/HFONT3.DAT\0",&HFONT3DAT_BEGIN_BUFFER,NULL,NULL,NULL };
#define psxadatahfont3dat 37
Pathstruct xadatahfont3tab = { "DATA/HFONT3.TAB\0",&HFONT3TAB_BEGIN_BUFFER,&HFONT3TAB_END_BUFFER,NULL,NULL };
#define psxadatahfont3tab 38
//zero
#define psxazero10 39
Pathstruct xadataclrd0dat = { "DATA/CLRD-0.DAT\0",&CLRD0DAT_BEGIN_BUFFER,NULL,NULL,NULL };
#define psxadataclrd0dat 40
//zero
#define psxazero11 41
Pathstruct xadataspellsdatx = { "DATA/SPELLS.DAT\0",&SPELLS_BEGIN_BUFFER_ptr,NULL,NULL,NULL };
#define psxadataspellsdat 42
//zero
#define psxazero12 43
Pathstruct xadatalang = { "",(Bit8u**)&x_DWORD_D41BC_langbuffer,&LANG_BEGIN_BUFFER,NULL,NULL };
#define psxadatalangbuffer 44
//zero
#define psxazero13 45
Pathstruct xadatatables = { "",(Bit8u**)&x_DWORD_D41BC_langbuffer,&LANG_BEGIN_BUFFER,NULL,NULL };
#define psxadatalangbuffer2 46
//zero
#define psxazero14 47

Pathstruct pstr[100] = { xasearchd_2bac30 ,//00
xafonts0dat,//01
xafonts0tab,//02
xafonts1dat,//03
xafonts1tab,//04
xadatatmaps00tab,//05
xapaldata,//06
xapalmem,//07
xadatapointersdat,//08
xadatapointerstab,//09
xazero,//10-a
xadatabuild00dat,//11-b
xadatabuild00tab,//12-c
xazero,//13
xadataetextdat,//14
xazero,//15
xadataftextdat,//16
xazero,//17
xadatagtextdat,//18
xazero,//19
xadataitextdat,//20
xazero,//21
xadatablock16dat,//22
xadatablock32dat,//23
xazero,//24
xabscreen,//25
xadatapald0dat,//26
xazero,//27
xawscreen_351628,//28
xabscreen2,//29
xadatapald0dat2,//30
xazero,//31
xadatamsprd00dat,//32
xadatamsprd00tab,//33
xazero,//34
xadatahsprd00dat,//35
xadatahsprd00tab,//36
xadatahfont3dat,//37
xadatahfont3tab,//38
xazero,//39
xadataclrd0dat,//40
xazero,//41
xadataspellsdatx,//42
xazero };//43

}
*/

// Class to handle all file accesses to orinial game data
class FileHandling {
public:
    FileHandling();

    void init();
    void initDirsAndFiles();

    void createDefaultSoundIni(path inifile);

	path getExePath() {return m_exe_path; }

    path getGamePath() { return m_game_path; }
    void setGamePath(const path& gamepath);

    const filedata_t& getFileData(MC2File file) {
        return m_mc2files.at(file).file_data;
    };
    const path& getFilePath(MC2File file) {
        return m_mc2files.at(file).file_path;
    };
    
    path m_exe_path {};
    path m_game_path {};


private:
    void loadFileIntoBuffer(MC2File);
    void decompressFile(MC2File);

    std::unordered_map<MC2File, MC2FileInfo> m_mc2files;
};


int sub_9894C_decompress(const Bit8u* a1, Bit8u* a2);
signed int sub_5C3D0_file_decompress(const Bit8u* input, Bit8u* output);

}