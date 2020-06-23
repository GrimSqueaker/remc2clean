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

* compiles and links on Fedora 32
* fix midi
* migrate all filesystem access to boost
* cleanup code
