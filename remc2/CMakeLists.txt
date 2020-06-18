project(remc2 C CXX)

################################################################################
# Source groups
################################################################################
if (WIN32)
    set(HEADER_FILES
        "stdafx.h"
        "targetver.h"
    )
else ()
    set(HEADER_FILES
    )
endif ()
source_group("Header Files" FILES ${HEADER_FILES})

if (WIN32)
    set(SOURCE_FILES
        "remc2.cpp"
        "stdafx.cpp"
    )
else()
    set(SOURCE_FILES
        "remc2.cpp"
    )
endif()
source_group("Source Files" FILES ${SOURCE_FILES})

set(SOURCE_FILES__dosbox_files
    "dosbox_files/config.h"
)
source_group("Source Files\\dosbox_files" FILES ${SOURCE_FILES__dosbox_files})

set(SOURCE_FILES_ENGINE
#    "engine/ail_sound.h"
#    "engine/bytearrays.x"
#    "engine/cd_utils.cpp"
#    "engine/cd_utils.h"
#    "engine/defs.h"
##    "engine/editor.cpp"
##    "engine/editor.h"
#    "engine/engine_support.cpp"
#    "engine/engine_support.h"
#    "engine/engine_support_converts.cpp"
#    "engine/engine_support_converts.h"
#    "engine/info.x"
#    "engine/read_config.cpp"
#    "engine/read_config.h"
#    "engine/structures.x"
    "engine/sub_main.cpp"
    "engine/sub_main.h"
    "engine/sub_main_mouse.h"
)
source_group("Source Files\\engine" FILES ${SOURCE_FILES_ENGINE})

set(SOURCE_FILES__libs__inih
    "../inih/ini.c"
    "../inih/ini.h"
    "../inih/INIReader.cpp"
    "../inih/INIReader.h"
)
source_group("Source Files\\libs\\inih" FILES ${SOURCE_FILES__libs__inih})

set(SOURCE_FILES__libs__kiss-sdl
#    "../kiss_sdl-master/kiss_draw.cpp"
#    "../kiss_sdl-master/kiss_general.cpp"
#    "../kiss_sdl-master/kiss_posix.cpp"
#    "../kiss_sdl-master/kiss_sdl.h"
#    "../kiss_sdl-master/kiss_widgets.cpp"
)
source_group("Source Files\\libs\\kiss-sdl" FILES ${SOURCE_FILES__libs__kiss-sdl})

set(SOURCE_FILES__libs__libADL
#    "../libADLMIDI-master/src/adldata.cpp"
#    "../libADLMIDI-master/src/adldata.hh"
#    "../libADLMIDI-master/src/adlmidi.cpp"
#    "../libADLMIDI-master/src/adlmidi_bankmap.h"
#    "../libADLMIDI-master/src/adlmidi_bankmap.tcc"
#    "../libADLMIDI-master/src/adlmidi_cvt.hpp"
#    "../libADLMIDI-master/src/adlmidi_load.cpp"
#    "../libADLMIDI-master/src/adlmidi_midiplay.cpp"
#    "../libADLMIDI-master/src/adlmidi_midiplay.hpp"
#    "../libADLMIDI-master/src/adlmidi_opl3.cpp"
#    "../libADLMIDI-master/src/adlmidi_opl3.hpp"
#    "../libADLMIDI-master/src/adlmidi_private.cpp"
#    "../libADLMIDI-master/src/adlmidi_private.hpp"
#    "../libADLMIDI-master/src/adlmidi_ptr.hpp"
#    "../libADLMIDI-master/src/adlmidi_sequencer.cpp"
#    "../libADLMIDI-master/src/chips/dosbox/dbopl.cpp"
#    "../libADLMIDI-master/src/chips/dosbox/dbopl.h"
#    "../libADLMIDI-master/src/chips/dosbox_opl3.cpp"
#    "../libADLMIDI-master/src/chips/dosbox_opl3.h"
#    "../libADLMIDI-master/src/chips/nuked/nukedopl3.c"
#    "../libADLMIDI-master/src/chips/nuked/nukedopl3.h"
#    "../libADLMIDI-master/src/chips/nuked/nukedopl3_174.c"
#    "../libADLMIDI-master/src/chips/nuked/nukedopl3_174.h"
#    "../libADLMIDI-master/src/chips/nuked_opl3.cpp"
#    "../libADLMIDI-master/src/chips/nuked_opl3.h"
#    "../libADLMIDI-master/src/chips/nuked_opl3_v174.cpp"
#    "../libADLMIDI-master/src/chips/nuked_opl3_v174.h"
#    "../libADLMIDI-master/src/chips/opl_chip_base.h"
#    "../libADLMIDI-master/src/chips/opl_chip_base.tcc"
#    "../libADLMIDI-master/src/cvt_mus2mid.hpp"
#    "../libADLMIDI-master/src/cvt_xmi2mid.hpp"
#    "../libADLMIDI-master/src/file_reader.hpp"
#    "../libADLMIDI-master/src/fraction.hpp"
#    "../libADLMIDI-master/src/midi_sequencer.h"
#    "../libADLMIDI-master/src/midi_sequencer.hpp"
#    "../libADLMIDI-master/src/midi_sequencer_impl.hpp"
#    "../libADLMIDI-master/src/wopl/wopl_file.c"
#    "../libADLMIDI-master/src/wopl/wopl_file.h"
)
source_group("Source Files\\libs\\libADL" FILES ${SOURCE_FILES__libs__libADL})

set(SOURCE_FILES__libs__libOPL
#    "../libOPNMIDI-master/src/chips/gens/Ym2612_Emu.cpp"
#    "../libOPNMIDI-master/src/chips/gens/Ym2612_Emu.h"
#    "../libOPNMIDI-master/src/chips/gens_opn2.cpp"
#    "../libOPNMIDI-master/src/chips/gens_opn2.h"
#    "../libOPNMIDI-master/src/chips/gx/gx_ym2612.c"
#    "../libOPNMIDI-master/src/chips/gx/gx_ym2612.h"
#    "../libOPNMIDI-master/src/chips/gx_opn2.cpp"
#    "../libOPNMIDI-master/src/chips/gx_opn2.h"
#    "../libOPNMIDI-master/src/chips/mame/mame_ym2612fm.c"
#    "../libOPNMIDI-master/src/chips/mame/mame_ym2612fm.h"
#    "../libOPNMIDI-master/src/chips/mame/mamedef.h"
#    "../libOPNMIDI-master/src/chips/mame_opn2.cpp"
#    "../libOPNMIDI-master/src/chips/mame_opn2.h"
#    "../libOPNMIDI-master/src/chips/nuked/ym3438.c"
#    "../libOPNMIDI-master/src/chips/nuked/ym3438.h"
#    "../libOPNMIDI-master/src/chips/nuked_opn2.cpp"
#    "../libOPNMIDI-master/src/chips/nuked_opn2.h"
#    "../libOPNMIDI-master/src/chips/opn_chip_base.h"
#    "../libOPNMIDI-master/src/chips/opn_chip_base.tcc"
#    "../libOPNMIDI-master/src/cvt_mus2mid.hpp"
#    "../libOPNMIDI-master/src/cvt_xmi2mid.hpp"
#    "../libOPNMIDI-master/src/file_reader.hpp"
#    "../libOPNMIDI-master/src/fraction.hpp"
#    "../libOPNMIDI-master/src/midi_sequencer.h"
#    "../libOPNMIDI-master/src/midi_sequencer.hpp"
#    "../libOPNMIDI-master/src/midi_sequencer_impl.hpp"
#    "../libOPNMIDI-master/src/opnbank.h"
#    "../libOPNMIDI-master/src/opnmidi.cpp"
#    "../libOPNMIDI-master/src/opnmidi_bankmap.h"
#    "../libOPNMIDI-master/src/opnmidi_bankmap.tcc"
#    "../libOPNMIDI-master/src/opnmidi_cvt.hpp"
#    "../libOPNMIDI-master/src/opnmidi_load.cpp"
#    "../libOPNMIDI-master/src/opnmidi_midiplay.cpp"
#    "../libOPNMIDI-master/src/opnmidi_midiplay.hpp"
#    "../libOPNMIDI-master/src/opnmidi_opn2.cpp"
#    "../libOPNMIDI-master/src/opnmidi_opn2.hpp"
#    "../libOPNMIDI-master/src/opnmidi_private.cpp"
#    "../libOPNMIDI-master/src/opnmidi_private.hpp"
#    "../libOPNMIDI-master/src/opnmidi_ptr.hpp"
#    "../libOPNMIDI-master/src/opnmidi_sequencer.cpp"
#    "../libOPNMIDI-master/src/wopn/wopn_file.c"
#    "../libOPNMIDI-master/src/wopn/wopn_file.h"
)
source_group("Source Files\\libs\\libOPL" FILES ${SOURCE_FILES__libs__libOPL})

set(SOURCE_FILES__libs__sdl-mixer-x
#    "../SDL-Mixer-X-master/include/SDL_mixer_ext/SDL_mixer_ext.h"
#    "../SDL-Mixer-X-master/src/codecs/load_aiff.c"
#    "../SDL-Mixer-X-master/src/codecs/load_aiff.h"
#    "../SDL-Mixer-X-master/src/codecs/load_voc.c"
#    "../SDL-Mixer-X-master/src/codecs/load_voc.h"
#    "../SDL-Mixer-X-master/src/codecs/music_cmd.c"
#    "../SDL-Mixer-X-master/src/codecs/music_cmd.h"
#    "../SDL-Mixer-X-master/src/codecs/music_flac.c"
#    "../SDL-Mixer-X-master/src/codecs/music_flac.h"
#    "../SDL-Mixer-X-master/src/codecs/music_fluidsynth.c"
#    "../SDL-Mixer-X-master/src/codecs/music_fluidsynth.h"
#    "../SDL-Mixer-X-master/src/codecs/music_gme.c"
#    "../SDL-Mixer-X-master/src/codecs/music_gme.h"
#    "../SDL-Mixer-X-master/src/codecs/music_id3tag.c"
#    "../SDL-Mixer-X-master/src/codecs/music_id3tag.h"
#    "../SDL-Mixer-X-master/src/codecs/music_mad.c"
#    "../SDL-Mixer-X-master/src/codecs/music_mad.h"
#    "../SDL-Mixer-X-master/src/codecs/music_mikmod.c"
#    "../SDL-Mixer-X-master/src/codecs/music_mikmod.h"
#    "../SDL-Mixer-X-master/src/codecs/music_modplug.c"
#    "../SDL-Mixer-X-master/src/codecs/music_modplug.h"
#    "../SDL-Mixer-X-master/src/codecs/music_mpg123.c"
#    "../SDL-Mixer-X-master/src/codecs/music_mpg123.h"
#    "../SDL-Mixer-X-master/src/codecs/music_nativemidi.c"
#    "../SDL-Mixer-X-master/src/codecs/music_nativemidi.h"
#    "../SDL-Mixer-X-master/src/codecs/music_ogg.c"
#    "../SDL-Mixer-X-master/src/codecs/music_ogg.h"
#    "../SDL-Mixer-X-master/src/codecs/music_opus.c"
#    "../SDL-Mixer-X-master/src/codecs/music_opus.h"
#    "../SDL-Mixer-X-master/src/codecs/music_smpeg.c"
#    "../SDL-Mixer-X-master/src/codecs/music_smpeg.h"
#    "../SDL-Mixer-X-master/src/codecs/music_timidity.c"
#    "../SDL-Mixer-X-master/src/codecs/music_timidity.h"
#    "../SDL-Mixer-X-master/src/codecs/music_wav.c"
#    "../SDL-Mixer-X-master/src/codecs/music_wav.h"
#    "../SDL-Mixer-X-master/src/codecs/native_midi/native_midi.h"
#    "../SDL-Mixer-X-master/src/codecs/native_midi/native_midi_common.c"
#    "../SDL-Mixer-X-master/src/codecs/native_midi/native_midi_common.h"
#    "../SDL-Mixer-X-master/src/codecs/native_midi/native_midi_haiku.cpp"
#    "../SDL-Mixer-X-master/src/codecs/native_midi/native_midi_mac.c"
#    "../SDL-Mixer-X-master/src/codecs/native_midi/native_midi_macosx.c"
#    "../SDL-Mixer-X-master/src/codecs/native_midi/native_midi_win32.c"
#    "../SDL-Mixer-X-master/src/codecs/play_cmdmusic.pri"
#    "../SDL-Mixer-X-master/src/codecs/play_flac.pri"
#    "../SDL-Mixer-X-master/src/codecs/play_gme.pri"
#    "../SDL-Mixer-X-master/src/codecs/play_id3tag.pri"
#    "../SDL-Mixer-X-master/src/codecs/play_mad.pri"
#    "../SDL-Mixer-X-master/src/codecs/play_midi_adl.pri"
#    "../SDL-Mixer-X-master/src/codecs/play_midi_fluid.pri"
#    "../SDL-Mixer-X-master/src/codecs/play_midi_native.pri"
#    "../SDL-Mixer-X-master/src/codecs/play_midi_opn.pri"
#    "../SDL-Mixer-X-master/src/codecs/play_midi_timidity.pri"
#    "../SDL-Mixer-X-master/src/codecs/play_mikmod.pri"
#    "../SDL-Mixer-X-master/src/codecs/play_modplug.pri"
#    "../SDL-Mixer-X-master/src/codecs/play_mpg123.pri"
#    "../SDL-Mixer-X-master/src/codecs/play_ogg.pri"
#    "../SDL-Mixer-X-master/src/codecs/play_smpeg.pri"
#    "../SDL-Mixer-X-master/src/codecs/play_wave.pri"
#    "../SDL-Mixer-X-master/src/effect_position.c"
#    "../SDL-Mixer-X-master/src/effect_stereoreverse.c"
#    "../SDL-Mixer-X-master/src/effects_internal.c"
#    "../SDL-Mixer-X-master/src/effects_internal.h"
#    "../SDL-Mixer-X-master/src/mixer.c"
#    "../SDL-Mixer-X-master/src/mixer.h"
#    "../SDL-Mixer-X-master/src/mixer_x_deprecated.c"
#    "../SDL-Mixer-X-master/src/music.c"
#    "../SDL-Mixer-X-master/src/music.h"
)
source_group("Source Files\\libs\\sdl-mixer-x" FILES ${SOURCE_FILES__libs__sdl-mixer-x})

set(SOURCE_FILES__portability
#    "../temp/dirent.c"
#    "portability/dirent-x.h"
#    "portability/mctypes.h"
#    "portability/port_filesystem.cpp"
#    "portability/port_filesystem.h"
#    "portability/port_inputs.cpp"
#    "portability/port_inputs.h"
#    "portability/port_outputs.cpp"
#    "portability/port_outputs.h"
#    "portability/port_sdl_sound.cpp"
#    "portability/port_sdl_sound.h"
#    "portability/port_sdl_vga_mouse.cpp"
#    "portability/port_sdl_vga_mouse.h"
#    "portability/port_time.cpp"
#    "portability/port_time.h"
#    "portability/xmi2mid.cpp"
#    "portability/xmi2mid.h"
)
source_group("Source Files\\portability" FILES ${SOURCE_FILES__portability})

set(ALL_FILES
    ${HEADER_FILES}
    ${SOURCE_FILES}
    ${SOURCE_FILES__dosbox_files}
    ${SOURCE_FILES_ENGINE}
    ${SOURCE_FILES__libs__inih}
    ${SOURCE_FILES__libs__kiss-sdl}
    ${SOURCE_FILES__libs__libADL}
    ${SOURCE_FILES__libs__libOPL}
    ${SOURCE_FILES__libs__sdl-mixer-x}
    ${SOURCE_FILES__portability}
)

################################################################################
# Target
################################################################################
add_executable(${PROJECT_NAME} ${ALL_FILES})

if (WIN32)
    add_precompiled_header(${PROJECT_NAME} "stdafx.h" "stdafx.cpp")
endif (WIN32)

use_props(${PROJECT_NAME} "${CMAKE_CONFIGURATION_TYPES}" "${DEFAULT_CXX_PROPS}")
set(ROOT_NAMESPACE remc2)

set_target_properties(${PROJECT_NAME} PROPERTIES
    VS_GLOBAL_KEYWORD "Win32Proj"
)
################################################################################
# Target name
################################################################################
if("${CMAKE_VS_PLATFORM_NAME}" STREQUAL "x64")
    set_target_properties(${PROJECT_NAME} PROPERTIES
        TARGET_NAME_DEBUG        "${OUTPUT_DIRECTORY}${TARGET_NAME}$ENV{TargetExt}"
        TARGET_NAME_XBOX_DEBUG   "${OUTPUT_DIRECTORY}${TARGET_NAME}$ENV{TargetExt}"
    )
endif()
################################################################################
# Output directory
################################################################################
if("${CMAKE_VS_PLATFORM_NAME}" STREQUAL "x64")
    set_target_properties(${PROJECT_NAME} PROPERTIES
        OUTPUT_DIRECTORY_DEBUG        "${CMAKE_CURRENT_SOURCE_DIR}/"
        OUTPUT_DIRECTORY_XBOX_DEBUG   "${CMAKE_CURRENT_SOURCE_DIR}/"
    )
endif()
if("${CMAKE_VS_PLATFORM_NAME}" STREQUAL "x64")
    set_target_properties(${PROJECT_NAME} PROPERTIES
        INTERPROCEDURAL_OPTIMIZATION_RELEASE      "TRUE"
        INTERPROCEDURAL_OPTIMIZATION_XBOX_RELEASE "TRUE"
    )
elseif("${CMAKE_VS_PLATFORM_NAME}" STREQUAL "x86")
    set_target_properties(${PROJECT_NAME} PROPERTIES
        INTERPROCEDURAL_OPTIMIZATION_RELEASE      "TRUE"
        INTERPROCEDURAL_OPTIMIZATION_XBOX_RELEASE "TRUE"
    )
endif()
################################################################################
# Include directories
################################################################################
if("${CMAKE_VS_PLATFORM_NAME}" STREQUAL "x64")
    target_include_directories(${PROJECT_NAME} PUBLIC
        "$<$<CONFIG:Debug>:"
            "C:/prenos/remc2/sdl2/include;"
            "C:/prenos/remc2/fluidsynth/include;"
            "C:/prenos/remc2/libADLMIDI-master/include;"
            "C:/prenos/remc2/libOPNMIDI-master/include;"
            "C:/prenos/remc2/SDL-Mixer-X-master/include/SDL_mixer_ext;"
            "C:/prenos/remc2/SDL-Mixer-X-master/src;"
            "C:/prenos/remc2/inih;"
            "C:/prenos/remc2/libvorbis/include;"
            "C:/prenos/remc2/libogg/include;"
            "C:/Program Files %28x86%29/Visual Leak Detector/include;"
            "C:/prenos/remc2/zlib/include;"
            "C:/prenos/remc2/libpng3/include/libpng16"
        ">"
        "$<$<CONFIG:XBOX_Debug>:"
            "C:/prenos/remc2/sdl2/include;"
            "C:/prenos/remc2/fluidsynth/include;"
            "C:/prenos/remc2/libADLMIDI-master/include;"
            "C:/prenos/remc2/libOPNMIDI-master/include;"
            "C:/prenos/remc2/SDL-Mixer-X-master/include/SDL_mixer_ext;"
            "C:/prenos/remc2/SDL-Mixer-X-master/src;"
            "C:/prenos/remc2/inih;"
            "C:/prenos/remc2/libvorbis/include;"
            "C:/prenos/remc2/libogg/include;"
            "C:/Program Files %28x86%29/Visual Leak Detector/include;"
            "C:/prenos/remc2/zlib/include;"
            "C:/prenos/remc2/libpng3/include/libpng16"
        ">"
    )
elseif("${CMAKE_VS_PLATFORM_NAME}" STREQUAL "x86")
    target_include_directories(${PROJECT_NAME} PUBLIC
        "$<$<CONFIG:Debug>:"
            "C:/Program Files %28x86%29/Visual Leak Detector/include;"
            "C:/prenos/remc2/OpenAL 1.1 SDK/include"
        ">"
        "$<$<CONFIG:XBOX_Debug>:"
            "C:/Program Files %28x86%29/Visual Leak Detector/include;"
            "C:/prenos/remc2/OpenAL 1.1 SDK/include"
        ">"
        "C:/prenos/remc2/sdl2/include;"
        "C:/prenos/remc2/fluidsynth/include;"
        "C:/prenos/remc2/libADLMIDI-master/include;"
        "C:/prenos/remc2/libOPNMIDI-master/include;"
        "C:/prenos/remc2/SDL-Mixer-X-master/include/SDL_mixer_ext;"
        "C:/prenos/remc2/SDL-Mixer-X-master/src;"
        "C:/prenos/remc2/inih;"
        "C:/prenos/remc2/libvorbis/include;"
        "C:/prenos/remc2/libogg/include;"
        "C:/prenos/remc2/libpng2/libpng-master;"
        "C:/prenos/remc2/zlib/include;"
        "C:/prenos/remc2/kiss_sdl-master;"
        "C:/prenos/remc2/SDL2_image-2.0.5/include;"
        "C:/prenos/remc2/SDL2_ttf-2.0.15/include;"
        "c:/prenos/remc2/SDL-Mixer-X-master/include;"
        "c:/prenos/remc2/SDL-Mixer-X-master/src/codecs"
    )
endif()

################################################################################
# Compile definitions
################################################################################
if("${CMAKE_VS_PLATFORM_NAME}" STREQUAL "x64")
    target_compile_definitions(${PROJECT_NAME} PRIVATE
        "$<$<CONFIG:Debug>:"
            "_DEBUG"
        ">"
        "$<$<CONFIG:Release>:"
            "NDEBUG"
        ">"
        "$<$<CONFIG:XBOX_Debug>:"
            "_DEBUG"
        ">"
        "$<$<CONFIG:XBOX_Release>:"
            "NDEBUG"
        ">"
        "_CONSOLE;"
        "UNICODE;"
        "_UNICODE"
    )
elseif("${CMAKE_VS_PLATFORM_NAME}" STREQUAL "x86")
    target_compile_definitions(${PROJECT_NAME} PRIVATE
        "$<$<CONFIG:Debug>:"
            "_DEBUG"
        ">"
        "$<$<CONFIG:Release>:"
            "NDEBUG"
        ">"
        "$<$<CONFIG:XBOX_Debug>:"
            "_DEBUG"
        ">"
        "$<$<CONFIG:XBOX_Release>:"
            "NDEBUG"
        ">"
        "WIN32;"
        "_CONSOLE;"
        "UNICODE;"
        "_UNICODE"
    )
endif()

################################################################################
# Compile and link options
################################################################################
if(MSVC)
    if("${CMAKE_VS_PLATFORM_NAME}" STREQUAL "x64")
        target_compile_options(${PROJECT_NAME} PRIVATE
            $<$<CONFIG:Debug>:
                /Od;
                /arch:SSE2;
                /Oy-;
                ${DEFAULT_CXX_DEBUG_RUNTIME_LIBRARY};
                /Y-
            >
            $<$<CONFIG:Release>:
                /O2;
                /Oi;
                ${DEFAULT_CXX_RUNTIME_LIBRARY};
                /Gy
            >
            $<$<CONFIG:XBOX_Debug>:
                /Od;
                /arch:SSE2;
                /Oy-;
                ${DEFAULT_CXX_DEBUG_RUNTIME_LIBRARY};
                /Y-
            >
            $<$<CONFIG:XBOX_Release>:
                /O2;
                /Oi;
                ${DEFAULT_CXX_RUNTIME_LIBRARY};
                /Gy
            >
            /permissive-;
            /sdl;
            /W3;
            ${DEFAULT_CXX_DEBUG_INFORMATION_FORMAT};
            ${DEFAULT_CXX_EXCEPTION_HANDLING}
        )
    elseif("${CMAKE_VS_PLATFORM_NAME}" STREQUAL "x86")
        target_compile_options(${PROJECT_NAME} PRIVATE
            $<$<CONFIG:Debug>:
                /Od;
                ${DEFAULT_CXX_DEBUG_RUNTIME_LIBRARY}
            >
            $<$<CONFIG:Release>:
                /O2;
                /Oi;
                ${DEFAULT_CXX_RUNTIME_LIBRARY};
                /Gy
            >
            $<$<CONFIG:XBOX_Debug>:
                /Od;
                ${DEFAULT_CXX_DEBUG_RUNTIME_LIBRARY}
            >
            $<$<CONFIG:XBOX_Release>:
                /O2;
                /Oi;
                ${DEFAULT_CXX_RUNTIME_LIBRARY};
                /Gy
            >
            /permissive-;
            /sdl;
            /arch:SSE2;
            /W3;
            ${DEFAULT_CXX_DEBUG_INFORMATION_FORMAT};
            ${DEFAULT_CXX_EXCEPTION_HANDLING};
            /Y-
        )
    endif()
    if("${CMAKE_VS_PLATFORM_NAME}" STREQUAL "x64")
        target_link_options(${PROJECT_NAME} PRIVATE
            $<$<CONFIG:Debug>:
                /MACHINE:X64;
                /INCREMENTAL
            >
            $<$<CONFIG:Release>:
                /OPT:REF;
                /OPT:ICF;
                /INCREMENTAL:NO
            >
            $<$<CONFIG:XBOX_Debug>:
                /MACHINE:X64;
                /INCREMENTAL
            >
            $<$<CONFIG:XBOX_Release>:
                /OPT:REF;
                /OPT:ICF;
                /INCREMENTAL:NO
            >
            /DEBUG;
            /SUBSYSTEM:CONSOLE
        )
    elseif("${CMAKE_VS_PLATFORM_NAME}" STREQUAL "x86")
        target_link_options(${PROJECT_NAME} PRIVATE
            $<$<CONFIG:Debug>:
                /INCREMENTAL
            >
            $<$<CONFIG:Release>:
                /OPT:REF;
                /OPT:ICF;
                /INCREMENTAL:NO
            >
            $<$<CONFIG:XBOX_Debug>:
                /INCREMENTAL
            >
            $<$<CONFIG:XBOX_Release>:
                /OPT:REF;
                /OPT:ICF;
                /INCREMENTAL:NO
            >
            /DEBUG;
            /SUBSYSTEM:CONSOLE
        )
    endif()
endif()

################################################################################
# Dependencies
################################################################################
if("${CMAKE_VS_PLATFORM_NAME}" STREQUAL "x64")
    set(ADDITIONAL_LIBRARY_DEPENDENCIES
        "$<$<CONFIG:Debug>:"
            "SDL2;"
            "SDL2main;"
            "winmm;"
            "libvorbis_static;"
            "libvorbisfile_static;"
            "libogg_static"
        ">"
        "$<$<CONFIG:XBOX_Debug>:"
            "SDL2;"
            "SDL2main;"
            "winmm;"
            "libvorbis_static;"
            "libvorbisfile_static;"
            "libogg_static"
        ">"
    )
elseif("${CMAKE_VS_PLATFORM_NAME}" STREQUAL "x86")
    set(ADDITIONAL_LIBRARY_DEPENDENCIES
        "SDL2;"
        "SDL2main;"
        "winmm;"
        "libvorbis_static;"
        "libvorbisfile_static;"
        "libogg_static"
    )
endif()
target_link_libraries(${PROJECT_NAME} PUBLIC "${ADDITIONAL_LIBRARY_DEPENDENCIES}")

if("${CMAKE_VS_PLATFORM_NAME}" STREQUAL "x64")
    target_link_directories(${PROJECT_NAME} PUBLIC
        "$<$<CONFIG:Debug>:"
            "c:/prenos/remc2/sdl2/VisualC/x64/Debug/;"
            "C:/prenos/remc2/Debug;"
            "C:/prenos/remc2/fluidsynth/lib;"
            "C:/prenos/remc2/libvorbis/win32/VS2010/x64/Debug;"
            "C:/prenos/remc2/libogg/win32/VS2015/x64/Debug"
        ">"
        "$<$<CONFIG:XBOX_Debug>:"
            "c:/prenos/remc2/sdl2/VisualC/x64/Debug/;"
            "C:/prenos/remc2/Debug;"
            "C:/prenos/remc2/fluidsynth/lib;"
            "C:/prenos/remc2/libvorbis/win32/VS2010/x64/Debug;"
            "C:/prenos/remc2/libogg/win32/VS2015/x64/Debug"
        ">"
    )
elseif("${CMAKE_VS_PLATFORM_NAME}" STREQUAL "x86")
    target_link_directories(${PROJECT_NAME} PUBLIC
        "c:/prenos/remc2/sdl2/VisualC/Win32/Debug/;"
        "C:/prenos/remc2/Debug;"
        "C:/prenos/remc2/fluidsynth/lib;"
        "C:/prenos/remc2/libvorbis/win32/VS2010/Win32/Debug;"
        "C:/prenos/remc2/libogg/win32/VS2015/Win32/Debug"
    )
endif()

