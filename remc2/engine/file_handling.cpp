#include "file_handling.h"

#include <fstream>
#include <libgen.h>
#include <unistd.h>
#include <limits.h>

#define MAX_PATH PATH_MAX

namespace remc2 {

using std::string;
using std::filesystem::path;

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
}

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

}
