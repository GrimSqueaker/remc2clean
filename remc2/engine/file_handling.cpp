#include "file_handling.h"

#include <algorithm>
#include <cstring>
#include <fstream>
#include <iostream>
#include <libgen.h>
#include <limits.h>
#include <list>
#include <string.h>
#include <unistd.h>

#define MAX_PATH PATH_MAX

#ifndef _countof
#define _countof(arr) sizeof(arr) / sizeof(arr[0])
//dirty
#endif



namespace remc2 {

using std::string;
using std::filesystem::path;

FileHandling::FileHandling() 
{
    // obtain exe path
    std::string pathexe;
    char result[ PATH_MAX ];
    ssize_t count = readlink("/proc/self/exe", result, PATH_MAX);
    if (count != -1) {
        pathexe = dirname(result);
    }
    this->m_exe_path = pathexe;
}

void FileHandling::init() {
	m_mc2files.clear();

	// define and load all files into memory
    m_mc2files.insert( {MC2File::data_bl16c00_dat, {m_game_path / "DATA" / "BL16C0-0.DAT"} } );
    m_mc2files.insert( {MC2File::data_bl16f00_dat, {m_game_path / "DATA" / "BL16F0-0.DAT"} } );
    m_mc2files.insert( {MC2File::data_bl16n00_dat, {m_game_path / "DATA" / "BL16N0-0.DAT"} } );
    m_mc2files.insert( {MC2File::data_bl32c00_dat, {m_game_path / "DATA" / "BL32C0-0.DAT"} } );
    m_mc2files.insert( {MC2File::data_bl32f00_dat, {m_game_path / "DATA" / "BL32F0-0.DAT"} } );
    m_mc2files.insert( {MC2File::data_bl32n00_dat, {m_game_path / "DATA" / "BL32N0-0.DAT"} } );
    m_mc2files.insert( {MC2File::data_bl128c00_dat, {m_game_path / "DATA" / "BL128C0-0.DAT"} } );
    m_mc2files.insert( {MC2File::data_bl128f00_dat, {m_game_path / "DATA" / "BL128F0-0.DAT"} } );
    m_mc2files.insert( {MC2File::data_bl128n00_dat, {m_game_path / "DATA" / "BL128N0-0.DAT"} } );
    m_mc2files.insert( {MC2File::data_bldgprm_dat, {m_game_path / "DATA" / "BLDGPRM.DAT"} } );
    m_mc2files.insert( {MC2File::data_block16_dat, {m_game_path / "DATA" / "BLOCK16.DAT"} } );
    m_mc2files.insert( {MC2File::data_block32_dat, {m_game_path / "DATA" / "BLOCK32.DAT"} } );
    m_mc2files.insert( {MC2File::data_block128_dat, {m_game_path / "DATA" / "BLOCK128.DAT"} } );
    m_mc2files.insert( {MC2File::data_build00_dat, {m_game_path / "DATA" / "BUILD0-0.DAT"} } );
    m_mc2files.insert( {MC2File::data_build00_tab, {m_game_path / "DATA" / "BUILD0-0.TAB"} } );
    m_mc2files.insert( {MC2File::data_clrd0_dat, {m_game_path / "DATA" / "CLRD-0.DAT"} } );
    m_mc2files.insert( {MC2File::data_font0_dat, {m_game_path / "DATA" / "FONT0.DAT"} } );
    m_mc2files.insert( {MC2File::data_font0_tab, {m_game_path / "DATA" / "FONT0.TAB"} } );
    m_mc2files.insert( {MC2File::data_font1_dat, {m_game_path / "DATA" / "FONT1.DAT"} } );
    m_mc2files.insert( {MC2File::data_font1_tab, {m_game_path / "DATA" / "FONT1.TAB"} } );
    m_mc2files.insert( {MC2File::data_gtd2_dat, {m_game_path / "DATA" / "GTD2.DAT"} } );
    m_mc2files.insert( {MC2File::data_hfont3_dat, {m_game_path / "DATA" / "HFONT3.DAT"} } );
    m_mc2files.insert( {MC2File::data_hfont3_tab, {m_game_path / "DATA" / "HFONT3.TAB"} } );
    m_mc2files.insert( {MC2File::data_pald0_dat, {m_game_path / "DATA" / "PALD-0.DAT"} } );
    m_mc2files.insert( {MC2File::data_pointers_dat, {m_game_path / "DATA" / "POINTERS.DAT"} } );
    m_mc2files.insert( {MC2File::data_pointers_tab, {m_game_path / "DATA" / "POINTERS.TAB"} } );
    m_mc2files.insert( {MC2File::data_screens_hscreen0_dat, {m_game_path / "DATA" / "SCREENS" / "HSCREEN0.DAT"} } );
    m_mc2files.insert( {MC2File::data_search_dat, {m_game_path / "DATA" / "SEARCH.DAT"} } );
    m_mc2files.insert( {MC2File::data_skyd00_dat, {m_game_path / "DATA" / "SKYD0-0.DAT"} } );
    m_mc2files.insert( {MC2File::data_skyn00_dat, {m_game_path / "DATA" / "SKYN0-0.DAT"} } );
    m_mc2files.insert( {MC2File::data_smatitl2_dat, {m_game_path / "DATA" / "SMATITL2.DAT"} } );
    m_mc2files.insert( {MC2File::data_smatitl2_pal, {m_game_path / "DATA" / "SMATITL2.PAL"} } );
    m_mc2files.insert( {MC2File::data_smatitle_dat, {m_game_path / "DATA" / "SMATITLE.DAT"} } );
    m_mc2files.insert( {MC2File::data_smatitle_pal, {m_game_path / "DATA" / "SMATITLE.PAL"} } );
    m_mc2files.insert( {MC2File::data_spells_dat, {m_game_path / "DATA" / "SPELLS.DAT"} } );
    m_mc2files.insert( {MC2File::data_tablesc_dat, {m_game_path / "DATA" / "TABLESC.DAT"} } );
    m_mc2files.insert( {MC2File::data_tablesd_dat, {m_game_path / "DATA" / "TABLESD.DAT"} } );
    m_mc2files.insert( {MC2File::data_tablesn_dat, {m_game_path / "DATA" / "TABLESN.DAT"} } );
    m_mc2files.insert( {MC2File::data_tmaps00_dat, {m_game_path / "DATA" / "TMAPS0-0.DAT"} } );
    m_mc2files.insert( {MC2File::data_tmaps10_dat, {m_game_path / "DATA" / "TMAPS1-0.DAT"} } );
    m_mc2files.insert( {MC2File::data_tmaps20_dat, {m_game_path / "DATA" / "TMAPS2-0.DAT"} } );
    m_mc2files.insert( {MC2File::data_tmaps00_tab, {m_game_path / "DATA" / "TMAPS0-0.TAB"} } );
    m_mc2files.insert( {MC2File::data_tmaps10_tab, {m_game_path / "DATA" / "TMAPS1-0.TAB"} } );
    m_mc2files.insert( {MC2File::data_tmaps20_tab, {m_game_path / "DATA" / "TMAPS2-0.TAB"} } );

    m_mc2files.insert( {MC2File::data_hsprd00_dat, {m_game_path / "DATA" / "HSPRD0-0.DAT"} } );
    m_mc2files.insert( {MC2File::data_hsprd00_tab, {m_game_path / "DATA" / "HSPRD0-0.TAB"} } );
    m_mc2files.insert( {MC2File::data_msprd00_dat, {m_game_path / "DATA" / "MSPRD0-0.DAT"} } );
    m_mc2files.insert( {MC2File::data_msprd00_tab, {m_game_path / "DATA" / "MSPRD0-0.TAB"} } );
    m_mc2files.insert( {MC2File::data_hsprn00_dat, {m_game_path / "DATA" / "HSPRN0-0.DAT"} } );
    m_mc2files.insert( {MC2File::data_hsprn00_tab, {m_game_path / "DATA" / "HSPRN0-0.TAB"} } );
    m_mc2files.insert( {MC2File::data_msprn00_dat, {m_game_path / "DATA" / "MSPRN0-0.DAT"} } );
    m_mc2files.insert( {MC2File::data_msprn00_tab, {m_game_path / "DATA" / "MSPRN0-0.TAB"} } );
    m_mc2files.insert( {MC2File::data_hsprc00_dat, {m_game_path / "DATA" / "HSPRC0-0.DAT"} } );
    m_mc2files.insert( {MC2File::data_hsprc00_tab, {m_game_path / "DATA" / "HSPRC0-0.TAB"} } );
    m_mc2files.insert( {MC2File::data_msprc00_dat, {m_game_path / "DATA" / "MSPRC0-0.DAT"} } );
    m_mc2files.insert( {MC2File::data_msprc00_tab, {m_game_path / "DATA" / "MSPRC0-0.TAB"} } );

    m_mc2files.insert( {MC2File::data_etext_dat, {m_game_path / "DATA" / "ETEXT.DAT"} } );
    m_mc2files.insert( {MC2File::data_ftext_dat, {m_game_path / "DATA" / "FTEXT.DAT"} } );
    m_mc2files.insert( {MC2File::data_gtext_dat, {m_game_path / "DATA" / "GTEXT.DAT"} } );
    m_mc2files.insert( {MC2File::data_itext_dat, {m_game_path / "DATA" / "ITEXT.DAT"} } );

    m_mc2files.insert( {MC2File::cdata_tmaps00_dat, {m_game_path / "CDATA" / "TMAPS0-0.DAT"} } );
    m_mc2files.insert( {MC2File::cdata_tmaps10_dat, {m_game_path / "CDATA" / "TMAPS1-0.DAT"} } );
    m_mc2files.insert( {MC2File::cdata_tmaps20_dat, {m_game_path / "CDATA" / "TMAPS2-0.DAT"} } );
    m_mc2files.insert( {MC2File::cdata_tmaps00_tab, {m_game_path / "CDATA" / "TMAPS0-0.TAB"} } );
    m_mc2files.insert( {MC2File::cdata_tmaps10_tab, {m_game_path / "CDATA" / "TMAPS1-0.TAB"} } );
    m_mc2files.insert( {MC2File::cdata_tmaps20_tab, {m_game_path / "CDATA" / "TMAPS2-0.TAB"} } );
    m_mc2files.insert( {MC2File::cdata_version_dat, {m_game_path / "CDATA" / "VERSION.DAT"} } );

    m_mc2files.insert( {MC2File::levels_levels_dat, {m_game_path / "LEVELS" / "LEVELS.DAT"} } );
    m_mc2files.insert( {MC2File::levels_levels_tab, {m_game_path / "LEVELS" / "LEVELS.TAB"} } );

    m_mc2files.insert( {MC2File::clevels_levels_dat, {m_game_path / "CLEVELS" / "LEVELS.DAT"} } );
    m_mc2files.insert( {MC2File::clevels_levels_tab, {m_game_path / "CLEVELS" / "LEVELS.TAB"} } );

    m_mc2files.insert( {MC2File::config_dat, {m_game_path / "CONFIG.DAT"} } );

    m_mc2files.insert( {MC2File::intro_intro_dat, {m_game_path / "INTRO" / "INTRO.DAT"} } );
    m_mc2files.insert( {MC2File::intro_intro2_dat, {m_game_path / "INTRO" / "INTRO2.DAT"} } );

	// load everything into buffers
	for( auto const& [key, val] : m_mc2files ) {
		loadFileIntoBuffer(key);
	}

	// decompress all needed data
	for( auto const& [key, val] : m_mc2files ) {
		decompressFile(key);
	}

	// set up texture maps
	

}

void FileHandling::initDirsAndFiles()
{
    // create game directories
    std::filesystem::create_directories(m_game_path / "SAVE");
    std::filesystem::create_directories(m_game_path / "CDATA");
    std::filesystem::create_directories(m_game_path / "CLEVELS");
    std::filesystem::create_directories(m_game_path / "SOUND");
    std::filesystem::create_directories(m_game_path / "LANGUAGE");
    std::filesystem::create_directories(m_game_path / "SHOTS");

    // create default sound inis
    createDefaultSoundIni("DIG.INI");
    createDefaultSoundIni("MID.INI");
}

void FileHandling::createDefaultSoundIni(path inifile)
{
    std::string default_sound_ini = "DEVICE\t\tNone\r\nDRIVER\t\tNone\r\nIO_ADDR\t\t-1\r\nIRQ\t\t-1\r\nDMA_8_BIT\t\t-1\r\nDMA_16_BIT\t\t-1\r\n";
    std::filesystem::path sound_dir = m_game_path / "SOUND";
    std::filesystem::create_directories(sound_dir);

    std::filesystem::path dig_ini_file = sound_dir / inifile;
    if (!std::filesystem::exists(dig_ini_file))
    {
        std::ofstream dig_ini_file_stream;
        dig_ini_file_stream.open(dig_ini_file);
        dig_ini_file_stream << default_sound_ini;
        dig_ini_file_stream.close();
    }
}

void FileHandling::setGamePath(const path& gamepath)
{ 
    path data_dir("DATA");
    path tmaps0file("TMAPS0-0.DAT");
    path mainfile = gamepath / data_dir / tmaps0file;
	if (!std::filesystem::exists(mainfile)) {
        std::string err = std::string("Original game not found in ") + gamepath.string();
        throw std::runtime_error(err);
    }
    this->m_game_path = gamepath;

	init();
}


void FileHandling::loadFileIntoBuffer(MC2File file)
{
	auto file_path = m_mc2files.at(file).file_path;
	auto &file_data = m_mc2files.at(file).file_data;

	if (std::filesystem::exists(file_path)) {
		auto size = std::filesystem::file_size(file_path);
		file_data.resize(size);

		std::ifstream ifs(file_path, std::ios::binary);

		if(!ifs.read((char*)file_data.data(), size))
			throw std::runtime_error(file_path.string() + ": " + std::strerror(errno));
	}
	else
		std::cerr << "File missing: " << file_path.string() << std::endl;
}

void FileHandling::decompressFile(MC2File file)
{
	MC2FileInfo& fileinfo = m_mc2files.at(file);
	const data_t& data = fileinfo.file_data;
	bool has_rnc = false;
	data_t temp_buffer;
	temp_buffer.resize(BUFFER_SIZE);
	fileinfo.data_decompressed.clear();

	// find all RNC headers in the files and try to decompress the data
	int RNC_header_length = 18;
	for (int i = 0; i+RNC_header_length < data.size(); i++) {
		if (data[i+2] == 'C' && data[i+1] == 'N' && data[i] == 'R') {
			int compression_method = fileinfo.file_data[i+3];
			int uncompressed_size = (data[i+4]<<24) + (data[i+5]<<16) + (data[i+6]<<8) + data[i+7];
			int compressed_size = (data[i+8]<<24) + (data[i+9]<<16) + (data[i+10]<<8) + data[i+11];
			std::cout << "File: " << fileinfo.file_path << " - "
			          << "RNC header @ " << i
					  << ", compression method " << compression_method
					  << ", uncompressed size " << uncompressed_size
					  << ", compressed size " << compressed_size
					  << std::endl;
			has_rnc = true;

			// uncompress and store in hashmap
			std::memcpy(temp_buffer.data(), &data[i+RNC_header_length], std::min(compressed_size, (int)(data.size()-(i+RNC_header_length)) ));
			sub_9894C_decompress(temp_buffer.data(), temp_buffer.data());
			data_t decomp_data;
			decomp_data.resize(uncompressed_size);
			std::memcpy(decomp_data.data(), temp_buffer.data(), uncompressed_size);
    		fileinfo.data_decompressed.insert({i, decomp_data});
		}
	}
	if (!has_rnc) {
		std::cout << "No RNC in file: " << fileinfo.file_path << std::endl;
	}
}

MC2FileInfo& FileHandling::getCurrentTMapsFileDatInfo()
{
	MC2File current_dat = MC2File::data_tmaps00_dat;
	switch (m_current_tmaps_file) {
		case MC2CurrentTMapsFile::TMaps00:
			current_dat = MC2File::data_tmaps00_dat;
			break;
		case MC2CurrentTMapsFile::TMaps10:
			current_dat = MC2File::data_tmaps10_dat;
			break;
		case MC2CurrentTMapsFile::TMaps20:
			current_dat = MC2File::data_tmaps20_dat;
			break;
	}

    return m_mc2files[current_dat];
}

MC2FileInfo& FileHandling::getCurrentTMapsFileTabInfo()
{
	MC2File current_tab = MC2File::data_tmaps00_tab;
	switch (m_current_tmaps_file) {
		case MC2CurrentTMapsFile::TMaps00:
			current_tab = MC2File::data_tmaps00_tab;
			break;
		case MC2CurrentTMapsFile::TMaps10:
			current_tab = MC2File::data_tmaps10_tab;
			break;
		case MC2CurrentTMapsFile::TMaps20:
			current_tab = MC2File::data_tmaps20_tab;
			break;
	}

    return m_mc2files[current_tab];
}

// original load and decompress functions

typedef struct huftable_s {
	uint32_t l1; // +0
	uint16_t l2; // +4
	uint32_t l3; // +6
	uint16_t bit_depth; // +A
} huftable_t;

typedef struct vars_s {
	uint16_t max_matches;
	uint16_t enc_key;
	uint32_t pack_block_size;
	uint16_t dict_size;
	uint32_t method;
	uint32_t pus_mode;
	uint32_t input_size;
	uint32_t file_size;

	// inner
	uint32_t bytes_left;
	uint32_t packed_size;
	uint32_t processed_size;
	uint32_t v7;
	uint32_t pack_block_pos;
	uint16_t pack_token, bit_count, v11;
	uint16_t last_min_offset;
	uint32_t v17;
	uint32_t pack_block_left_size;
	uint16_t match_count;
	uint16_t match_offset;
	uint32_t v20, v21;
	uint32_t bit_buffer;

	uint32_t unpacked_size;
	uint32_t rnc_data_size;
	uint16_t unpacked_crc, unpacked_crc_real;
	uint16_t packed_crc;
	uint32_t leeway;
	uint32_t chunks_count;

	uint8_t *mem1;
	uint8_t *pack_block_start;
	uint8_t *pack_block_max;
	uint8_t *pack_block_end;
	uint16_t *mem2;
	uint16_t *mem3;
	uint16_t *mem4;
	uint16_t *mem5;

	uint8_t *decoded;
	uint8_t *window;

	size_t read_start_offset, write_start_offset;
	uint8_t *input, *output, *temp;
	size_t input_offset, output_offset, temp_offset;

	uint8_t tmp_crc_data[2048];
	huftable_t raw_table[16];
	huftable_t pos_table[16];
	huftable_t len_table[16];
} vars_t;

#define RNC_SIGN 0x524E43 // RNC
#define RNC_HEADER_SIZE 0x12
#define MAX_BUF_SIZE 0x90000

uint8_t read_byte(uint8_t *buf, size_t *offset)
{
	return buf[(*offset)++];
}

uint16_t read_word_be(uint8_t *buf, size_t *offset)
{
	uint8_t b1 = read_byte(buf, offset);
	uint8_t b2 = read_byte(buf, offset);

	return (b1 << 8) | b2;
}

uint32_t read_dword_be(uint8_t *buf, size_t *offset)
{
	uint16_t w1 = read_word_be(buf, offset);
	uint16_t w2 = read_word_be(buf, offset);

	return (w1 << 16) | w2;
}

static const uint16_t crc_table[] = {
	0x0000, 0xC0C1, 0xC181, 0x0140, 0xC301, 0x03C0, 0x0280, 0xC241,
	0xC601, 0x06C0, 0x0780, 0xC741, 0x0500, 0xC5C1, 0xC481, 0x0440,
	0xCC01, 0x0CC0, 0x0D80, 0xCD41, 0x0F00, 0xCFC1, 0xCE81, 0x0E40,
	0x0A00, 0xCAC1, 0xCB81, 0x0B40, 0xC901, 0x09C0, 0x0880, 0xC841,
	0xD801, 0x18C0, 0x1980, 0xD941, 0x1B00, 0xDBC1, 0xDA81, 0x1A40,
	0x1E00, 0xDEC1, 0xDF81, 0x1F40, 0xDD01, 0x1DC0, 0x1C80, 0xDC41,
	0x1400, 0xD4C1, 0xD581, 0x1540, 0xD701, 0x17C0, 0x1680, 0xD641,
	0xD201, 0x12C0, 0x1380, 0xD341, 0x1100, 0xD1C1, 0xD081, 0x1040,
	0xF001, 0x30C0, 0x3180, 0xF141, 0x3300, 0xF3C1, 0xF281, 0x3240,
	0x3600, 0xF6C1, 0xF781, 0x3740, 0xF501, 0x35C0, 0x3480, 0xF441,
	0x3C00, 0xFCC1, 0xFD81, 0x3D40, 0xFF01, 0x3FC0, 0x3E80, 0xFE41,
	0xFA01, 0x3AC0, 0x3B80, 0xFB41, 0x3900, 0xF9C1, 0xF881, 0x3840,
	0x2800, 0xE8C1, 0xE981, 0x2940, 0xEB01, 0x2BC0, 0x2A80, 0xEA41,
	0xEE01, 0x2EC0, 0x2F80, 0xEF41, 0x2D00, 0xEDC1, 0xEC81, 0x2C40,
	0xE401, 0x24C0, 0x2580, 0xE541, 0x2700, 0xE7C1, 0xE681, 0x2640,
	0x2200, 0xE2C1, 0xE381, 0x2340, 0xE101, 0x21C0, 0x2080, 0xE041,
	0xA001, 0x60C0, 0x6180, 0xA141, 0x6300, 0xA3C1, 0xA281, 0x6240,
	0x6600, 0xA6C1, 0xA781, 0x6740, 0xA501, 0x65C0, 0x6480, 0xA441,
	0x6C00, 0xACC1, 0xAD81, 0x6D40, 0xAF01, 0x6FC0, 0x6E80, 0xAE41,
	0xAA01, 0x6AC0, 0x6B80, 0xAB41, 0x6900, 0xA9C1, 0xA881, 0x6840,
	0x7800, 0xB8C1, 0xB981, 0x7940, 0xBB01, 0x7BC0, 0x7A80, 0xBA41,
	0xBE01, 0x7EC0, 0x7F80, 0xBF41, 0x7D00, 0xBDC1, 0xBC81, 0x7C40,
	0xB401, 0x74C0, 0x7580, 0xB541, 0x7700, 0xB7C1, 0xB681, 0x7640,
	0x7200, 0xB2C1, 0xB381, 0x7340, 0xB101, 0x71C0, 0x7080, 0xB041,
	0x5000, 0x90C1, 0x9181, 0x5140, 0x9301, 0x53C0, 0x5280, 0x9241,
	0x9601, 0x56C0, 0x5780, 0x9741, 0x5500, 0x95C1, 0x9481, 0x5440,
	0x9C01, 0x5CC0, 0x5D80, 0x9D41, 0x5F00, 0x9FC1, 0x9E81, 0x5E40,
	0x5A00, 0x9AC1, 0x9B81, 0x5B40, 0x9901, 0x59C0, 0x5880, 0x9841,
	0x8801, 0x48C0, 0x4980, 0x8941, 0x4B00, 0x8BC1, 0x8A81, 0x4A40,
	0x4E00, 0x8EC1, 0x8F81, 0x4F40, 0x8D01, 0x4DC0, 0x4C80, 0x8C41,
	0x4400, 0x84C1, 0x8581, 0x4540, 0x8701, 0x47C0, 0x4680, 0x8641,
	0x8201, 0x42C0, 0x4380, 0x8341, 0x4100, 0x81C1, 0x8081, 0x4040
};

uint16_t crc_block(uint8_t *buf, size_t offset, int size)
{
	uint16_t crc = 0;

	while (size--)
	{
		crc ^= read_byte(buf, &offset);
		crc = (crc >> 8) ^ crc_table[crc & 0xFF];
	}

	return crc;
}

void read_buf(uint8_t *dest, uint8_t *source, size_t *offset, int size)
{
	memmove(dest, &source[*offset], size);
	*offset += size;
}

uint8_t read_source_byte(vars_t *v)
{
	if (v->pack_block_start == &v->mem1[0xFFFD])
	{
		int left_size = v->file_size - v->input_offset;

		int size_to_read;
		if (left_size <= 0xFFFD)
			size_to_read = left_size;
		else
			size_to_read = 0xFFFD;

		v->pack_block_start = v->mem1;

		read_buf(v->pack_block_start, v->input, &v->input_offset, size_to_read);

		if (left_size - size_to_read > 2)
			left_size = 2;

		read_buf(&v->mem1[size_to_read], v->input, &v->input_offset, left_size);
		v->input_offset -= left_size;
	}

	return *v->pack_block_start++;
}

uint32_t input_bits_m2(vars_t *v, short count)
{
	uint32_t bits = 0;

	while (count--)
	{
		if (!v->bit_count)
		{
			v->bit_buffer = read_source_byte(v);
			v->bit_count = 8;
		}

		bits <<= 1;

		if (v->bit_buffer & 0x80)
			bits |= 1;

		v->bit_buffer <<= 1;
		v->bit_count--;
	}

	return bits;
}



uint32_t input_bits_m1(vars_t *v, short count)
{
	uint32_t bits = 0;
	uint32_t prev_bits = 1;

	while (count--)
	{
		if (!v->bit_count)
		{
			uint8_t b1 = read_source_byte(v);
			uint8_t b2 = read_source_byte(v);
			v->bit_buffer = (v->pack_block_start[1] << 24) | (v->pack_block_start[0] << 16) | (b2 << 8) | b1;

			v->bit_count = 16;
		}

		if (v->bit_buffer & 1)
			bits |= prev_bits;

		v->bit_buffer >>= 1;
		prev_bits <<= 1;
		v->bit_count--;
	}

	return bits;
}

int input_bits(vars_t *v, short count)
{
	if (v->method != 2)
		return input_bits_m1(v, count);
	else
		return input_bits_m2(v, count);
}

void clear_table(huftable_t *data, int count)
{
	for (int i = 0; i < count; ++i)
	{
		data[i].l1 = 0;
		data[i].l2 = 0xFFFF;
		data[i].l3 = 0;
		data[i].bit_depth = 0;
	}
}

uint32_t inverse_bits(uint32_t value, int count)
{
	int i = 0;
	while (count--)
	{
		i <<= 1;

		if (value & 1)
			i |= 1;

		value >>= 1;
	}

	return i;
}

void proc_20(huftable_t *data, int count)
{
	int val = 0;
	uint32_t div = 0x80000000;
	int bits_count = 1;

	while (bits_count <= 16)
	{
		int i = 0;

		while (1)
		{
			if (i >= count)
			{
				bits_count++;
				div >>= 1;
				break;
			}

			if (data[i].bit_depth == bits_count)
			{
				data[i].l3 = inverse_bits(val / div, bits_count);
				val += div;
			}

			i++;
		}
	}
}

void make_huftable(vars_t *v, huftable_t *data, int count)
{
	clear_table(data, count);

	int leaf_nodes = input_bits_m1(v, 5);

	if (leaf_nodes)
	{
		if (leaf_nodes > 16)
			leaf_nodes = 16;

		for (int i = 0; i < leaf_nodes; ++i)
			data[i].bit_depth = input_bits_m1(v, 4);

		proc_20(data, leaf_nodes);
	}
}

uint32_t decode_table_data(vars_t *v, huftable_t *data)
{
	uint32_t i = 0;

	while (1)
	{
		if (data[i].bit_depth && (data[i].l3 == (v->bit_buffer & ((1 << data[i].bit_depth) - 1))))
		{
			input_bits_m1(v, data[i].bit_depth);

			if (i < 2)
				return i;

			return input_bits_m1(v, i - 1) | (1 << (i - 1));
		}

		i++;
	}
}

void write_buf(uint8_t *dest, size_t *offset, uint8_t *source, int size)
{
	memmove(&dest[*offset], source, size);
	*offset += size;
}

void write_decoded_byte(vars_t *v, uint8_t b)
{
	if (&v->decoded[0xFFFF] == v->window)
	{
		write_buf(v->output, &v->output_offset, &v->decoded[v->dict_size], 0xFFFF - v->dict_size);
		memmove(v->decoded, &v->window[-v->dict_size], v->dict_size);
		v->window = &v->decoded[v->dict_size];
	}

	*v->window++ = b;
	v->unpacked_crc_real = crc_table[(v->unpacked_crc_real ^ b) & 0xFF] ^ (v->unpacked_crc_real >> 8);
}

void ror_w(uint16_t *x)
{
	if (*x & 1)
		*x = 0x8000 | (*x >> 1);
	else
		*x >>= 1;
}

int unpack_data_m1(vars_t *v)
{
	while (v->processed_size < v->input_size)
	{
		make_huftable(v, v->raw_table, _countof(v->raw_table));
		make_huftable(v, v->len_table, _countof(v->len_table));
		make_huftable(v, v->pos_table, _countof(v->pos_table));

		int subchunks = input_bits_m1(v, 16);

		while (subchunks--)
		{
			uint32_t data_length = decode_table_data(v, v->raw_table);
			v->processed_size += data_length;

			if (data_length)
			{
				while (data_length--)
					write_decoded_byte(v, (v->enc_key ^ read_source_byte(v)) & 0xFF);

				ror_w(&v->enc_key);

				v->bit_buffer = (((v->pack_block_start[2] << 16) | (v->pack_block_start[1] << 8) | v->pack_block_start[0]) << v->bit_count) | (v->bit_buffer & ((1 << v->bit_count) - 1));
			}

			if (subchunks)
			{
				v->match_offset = decode_table_data(v, v->len_table) + 1;
				v->match_count = decode_table_data(v, v->pos_table) + 2;
				v->processed_size += v->match_count;

				while (v->match_count--)
					write_decoded_byte(v, v->window[-v->match_offset]);
			}
		}
	}

	write_buf(v->output, &v->output_offset, &v->decoded[v->dict_size], v->window - &v->decoded[v->dict_size]);
	return 0;
}

void decode_match_count(vars_t *v)
{
	v->match_count = input_bits_m2(v, 1) + 4;

	if (input_bits_m2(v, 1))
		v->match_count = ((v->match_count - 1) << 1) + input_bits_m2(v, 1);
}

void decode_match_offset(vars_t *v)
{
	v->match_offset = 0;
	if (input_bits_m2(v, 1))
	{
		v->match_offset = input_bits_m2(v, 1);

		if (input_bits_m2(v, 1))
		{
			v->match_offset = ((v->match_offset << 1) | input_bits_m2(v, 1)) | 4;

			if (!input_bits_m2(v, 1))
				v->match_offset = (v->match_offset << 1) | input_bits_m2(v, 1);
		}
		else if (!v->match_offset)
			v->match_offset = input_bits_m2(v, 1) + 2;
	}

	v->match_offset = ((v->match_offset << 8) | read_source_byte(v)) + 1;
}

int unpack_data_m2(vars_t *v)
{
	while (v->processed_size < v->input_size)
	{
		while (1)
		{
			if (!input_bits_m2(v, 1))
			{
				write_decoded_byte(v, (v->enc_key ^ read_source_byte(v)) & 0xFF);

				ror_w(&v->enc_key);

				v->processed_size++;
			}
			else
			{
				if (input_bits_m2(v, 1))
				{
					if (input_bits_m2(v, 1))
					{
						if (input_bits_m2(v, 1))
						{
							v->match_count = read_source_byte(v) + 8;

							if (v->match_count == 8)
							{
								input_bits_m2(v, 1);
								break;
							}
						}
						else
							v->match_count = 3;

						decode_match_offset(v);
					}
					else
					{
						v->match_count = 2;
						v->match_offset = read_source_byte(v) + 1;
					}

					v->processed_size += v->match_count;

					while (v->match_count--)
						write_decoded_byte(v, v->window[-v->match_offset]);
				}
				else
				{
					decode_match_count(v);

					if (v->match_count != 9)
					{
						decode_match_offset(v);
						v->processed_size += v->match_count;

						while (v->match_count--)
							write_decoded_byte(v, v->window[-v->match_offset]);
					}
					else
					{
						uint32_t data_length = (input_bits_m2(v, 4) << 2) + 12;
						v->processed_size += data_length;

						while (data_length--)
							write_decoded_byte(v, (v->enc_key ^ read_source_byte(v)) & 0xFF);

						ror_w(&v->enc_key);
					}
				}
			}
		}
	}

	write_buf(v->output, &v->output_offset, &v->decoded[v->dict_size], v->window - &v->decoded[v->dict_size]);
	return 0;
}

int do_unpack_data(vars_t *v)
{
	int start_pos = v->input_offset;

	uint32_t sign = read_dword_be(v->input, &v->input_offset);
	if ((sign >> 8) != RNC_SIGN)
		return 6;

	v->method = sign & 3;
	v->input_size = read_dword_be(v->input, &v->input_offset);
	v->packed_size = read_dword_be(v->input, &v->input_offset);
	if (v->file_size < v->packed_size)
		return 7;
	v->unpacked_crc = read_word_be(v->input, &v->input_offset);
	v->packed_crc = read_word_be(v->input, &v->input_offset);

	/*v->leeway = */read_byte(v->input, &v->input_offset);
	/*v->chunks_count = */read_byte(v->input, &v->input_offset);

	if (crc_block(v->input, v->input_offset, v->packed_size) != v->packed_crc)
		return 4;

	v->mem1 = (uint8_t*)malloc(0xFFFF);
	v->decoded = (uint8_t*)malloc(0xFFFF);
	v->pack_block_start = &v->mem1[0xFFFD];
	v->window = &v->decoded[v->dict_size];

	v->unpacked_crc_real = 0;
	v->bit_count = 0;
	v->bit_buffer = 0;
	v->processed_size = 0;

	uint16_t specified_key = v->enc_key;

	int error_code = 0;
	if (input_bits(v, 1) && !v->pus_mode)
		error_code = 9;

	if (!error_code)
	{
		if (input_bits(v, 1) && !v->enc_key) // key is needed, but not specified as argument
			error_code = 10;
	}

	if (!error_code)
	{
		switch (v->method)
		{
		case 1: error_code = unpack_data_m1(v); break;
		case 2: error_code = unpack_data_m2(v); break;
		}
	}

	v->enc_key = specified_key;

	free(v->mem1);
	free(v->decoded);

	v->input_offset = start_pos + v->packed_size + RNC_HEADER_SIZE;

	if (error_code)
		return error_code;

	if (v->unpacked_crc != v->unpacked_crc_real)
		return 5;

	return 0;
}

int do_unpack(vars_t *v)
{
	v->packed_size = v->file_size;

	if (v->file_size < RNC_HEADER_SIZE)
		return 6;

	int result = do_unpack_data(v); // data
	if (result == 0)return v->input_size;
	return -result;
}

vars_t *init_vars()
{
	vars_t *v = (vars_t*)malloc(sizeof(vars_t));
	v->enc_key = 0;
	v->max_matches = 0x1000;
	v->unpacked_crc_real = 0;
	v->pack_block_size = 0x3000;
	v->dict_size = 0xFFFF;
	v->method = 1;
	v->pus_mode = 0;

	v->read_start_offset = 0;
	v->write_start_offset = 0;
	v->input_offset = 0;
	v->output_offset = 0;
	v->temp_offset = 0;

	memset(v->tmp_crc_data, 0, sizeof(v->tmp_crc_data));
	memset(v->raw_table, 0, sizeof(v->raw_table));
	memset(v->pos_table, 0, sizeof(v->pos_table));
	memset(v->len_table, 0, sizeof(v->len_table));

	return v;
}

int sub_9894C_decompress(const Bit8u* a1, Bit8u* a2) {
	vars_t *v = init_vars();
	if (v->method == 1)
	{
		if (v->dict_size > 0x8000)
			v->dict_size = 0x8000;
		v->max_matches = 0x1000;
	}
	else if (v->method == 2)
	{
		if (v->dict_size > 0x1000)
			v->dict_size = 0x1000;
		v->max_matches = 0xFF;
	}

	v->file_size = MAX_BUF_SIZE;
	v->input = (uint8_t*)malloc(MAX_BUF_SIZE);

	Bit32u signature = a1[0] + (a1[1] << 8) + (a1[2] << 16);
	if (signature == 0x434e52)
	{
		Bit32u inputsize = a1[11] + (a1[10] << 8) + (a1[9] << 16) + (a1[8] << 24);
 		memmove(v->input, a1, inputsize + 0x12);
	}
	else
	{
		v->input[0] = 0;
	}
	//v->input = a1;

	v->output = a2;
	v->temp = (uint8_t*)malloc(MAX_BUF_SIZE);

	int error_code = 0;
	/*switch (v->pus_mode)
	{
	case 0: error_code = do_pack(v); break;
	case 1: error_code = do_unpack(v); break;
	case 2: error_code = do_search(v); break;
	}*/
	error_code = do_unpack(v);

	if (v->pus_mode == 2)
	{
		free(v->input);
		free(v->output);
		free(v->temp);
		free(v->input);
		free(v);

		return error_code;
	}

	/*if (error_code)
	 {
		switch (error_code) {
		case 4: printf("Corrupted input data.\n"); break;
		case 5: printf("CRC check failed.\n"); break;
		case 6:
		case 7:
			printf("Wrong RNC header.\n"); break;
		case 10: printf("No RNC archives were found.\n"); break;
		default: printf("Cannot process file. Error code: %x\n", error_code); break;
		}
	}*/

	free(v->input);
	//free(v->output);
	free(v->temp);
	free(v);
	if (error_code == -6)return 0;
	//if (error_code == 0)return 0;
	return error_code;
}

//----- (0005C3D0) --------------------------------------------------------
signed int sub_5C3D0_file_decompress(const Bit8u* input, Bit8u* output)//23d3d0
{
	char RNSSING[5] = "RNC\x1";
	if (strncmp((const char*)input, RNSSING, 4))
		return 0;
	sub_9894C_decompress(input, output);
	return 1;
}
}
