# remc2

Original from https://github.com/turican0/remc2

* Cleaned up all binary data from the repo
* Added CMake setup (not tested on Windows)
* Made buildable on Linux (Fedora 32, gcc 10)

## CI

![Build Status](https://github.com/GrimSqueaker/remc2clean/workflows/C/C++%20CI/badge.svg)

## Requirements

* SDL2
* SDL2_MIXER
* libpng

## Build

```bash
export BUILDTYPE=Debug # or Release
mkdir build_${BUILDTYPE}
cd build_${BUILDTYPE}
cmake -G Ninja -DCMAKE_BUILD_TYPE=${BUILDTYPE} -DCMAKE_INSTALL_PREFIX=./installed ..
ninja
ninja install
```

## Run

```bash
cd build_${BUILDTYPE}/installed/bin
./remc2
```

## TODO

* compiles and links on Fedora 32 and Ubuntu 20.04
* fix midi and sound in general
* migrate all filesystem access to c++17 (std::filesystem, ...)
* c++-ify code
* cleanup code
* remove dos specific stuff like
  * sound ini files (dig.ini, mid.ini)
  * findfirst, etc.
    * instead load all files at the start in a c++ fashion, decompress and provide buffers - this way we do not have to bother with malloc/free
