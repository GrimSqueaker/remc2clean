# remc2

Original from https://github.com/turican0/remc2

* Cleaned up all binary data from the repo
* Added CMake setup (not tested on Windows)
* Made buildable on Linux (Fedora 32, gcc 10)

## Requirements

* SDL2
* SDL2_MIXER
* boost::filesystem
* libpng

## Build

```bash
mkdir build
cd build
cmake ..
make
```

## Run

```bash
./remc2/remc2
```

## TODO

* compiles and links on Fedora 32
* fix midi
* migrate all filesystem access to boost
* cleanup code
