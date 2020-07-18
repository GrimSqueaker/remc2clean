#pragma once

#include <cstddef>
#include <string>
#include <vector>
#include <filesystem>
#include <unordered_map>

#include "../dosbox_files/config.h"

namespace remc2 {

int constexpr BUFFER_SIZE = 1024*1024*4; // 4 MB buffer size for reading file data

using std::string;
using std::filesystem::path;

typedef std::vector<unsigned char> data_t;

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
    data_block16_dat,
    data_block32_dat,
    data_block128_dat,
    data_build00_dat,
    data_build00_tab,
    data_clrd0_dat,
    data_font0_dat,
    data_font0_tab,
    data_font1_dat,
    data_font1_tab,
    data_gtd2_dat,
    data_hfont3_dat,
    data_hfont3_tab,
    data_pald0_dat,
    data_pointers_dat,
    data_pointers_tab,
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

    data_hsprd00_dat,
    data_hsprd00_tab,
    data_msprd00_dat,
    data_msprd00_tab,
    data_hsprn00_dat,
    data_hsprn00_tab,
    data_msprn00_dat,
    data_msprn00_tab,
    data_hsprc00_dat,
    data_hsprc00_tab,
    data_msprc00_dat,
    data_msprc00_tab,

    data_etext_dat,
    data_ftext_dat,
    data_gtext_dat,
    data_itext_dat,

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

typedef struct {
    path file_path;
    data_t file_data;
    std::unordered_map<int, data_t> data_decompressed;
} MC2FileInfo;

enum class MC2CurrentTMapsFile {
    TMaps00,
    TMaps10,
    TMaps20,
};

typedef struct {
    int    uncompressed_size;
    int    pos_in_tmaps_dat;
    int    id;
    data_t data;
} MC2TMapsEntry;

//enum class MC2Asset {
//    sprite0,
//};

// NOTE: fix all pstr[..] by using file_handling instead

/*    
Pathstruct xasearchd_2bac30 = { "*SearchD\0",&SEARCH_BEGIN_BUFFER,&SEARCH_END_BUFFER,0x1000,NULL };
Pathstruct xapaldata = { "*PalData\0",&PALDATA_BEGIN_BUFFER,NULL,0x400,NULL };
Pathstruct xapalmem = { "*PalMem\0",&PALMEM_BEGIN_BUFFER,NULL,NULL,NULL };
Pathstruct xabscreen = { "*BScreen\0",&BSCREEN_BEGIN_BUFFER,&BSCREEN_END_BUFFER,0x011508,NULL };
Pathstruct xawscreen_351628 = { "*WScreen\0",&WSCREEN_BEGIN_BUFFER,&WSCREEN_END_BUFFER,0x04b100,NULL };
Pathstruct xabscreen2 = { "*BScreen\0",&x_DWORD_E9C38_smalltit,&BSCREEN2_END_BUFFER,0x11170,NULL }; //0x011508
Pathstruct xadatalang = { "",(Bit8u**)&x_DWORD_D41BC_langbuffer,&LANG_BEGIN_BUFFER,NULL,NULL };
Pathstruct xadatatables = { "",(Bit8u**)&x_DWORD_D41BC_langbuffer,&LANG_BEGIN_BUFFER,NULL,NULL };
*/

// Class to handle all file accesses to orinial game data
class FileHandling {
public:
    FileHandling();

    void init();
    void initDirsAndFiles();

    void createDefaultSoundIni(path inifile);

	path getExePath() const {return m_exe_path; }

    path getGamePath() const { return m_game_path; }
    void setGamePath(const path& gamepath);

    void setCurrentTMapsFile(MC2CurrentTMapsFile file) { m_current_tmaps_file = file; };
    MC2CurrentTMapsFile getCurrentTMapsFile() const { return m_current_tmaps_file; };
    MC2File getTMapsDatFile(MC2CurrentTMapsFile tmap) const;
    MC2FileInfo& getCurrentTMapsFileDatInfo() const;
    MC2File getTMapsTabFile(MC2CurrentTMapsFile tmap) const;
    MC2FileInfo& getCurrentTMapsFileTabInfo() const;
    MC2TMapsEntry& getCurrentTMaps(int index) const { return m_tmaps[getCurrentTMapsFile()][index]; };

    const data_t& getFileData(MC2File file) {
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
    void prepareTMapsFile(MC2CurrentTMapsFile map);

    std::unordered_map<MC2File, MC2FileInfo> m_mc2files;

    // tmaps
    MC2CurrentTMapsFile m_current_tmaps_file;
    std::unordered_map<MC2CurrentTMapsFile, std::vector<MC2TMapsEntry>> m_tmaps;
};


int sub_9894C_decompress(const Bit8u* a1, Bit8u* a2);
signed int sub_5C3D0_file_decompress(const Bit8u* input, Bit8u* output);

}