#pragma once

#include <string>
#include <filesystem>

namespace remc2 {

using std::string;
using std::filesystem::path;

// Class to handle all file accesses to orinial game data
class FileHandling {
public:
    FileHandling();

	path getExePath() {return m_exe_path; }
    void initDirsAndFiles();

    void createDefaultSoundIni(path inifile);

    path getGamePath() { return m_game_path; }
    void setGamePath(const path& gamepath);
    
    path m_exe_path {};
    path m_game_path {};
};


}