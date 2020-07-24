# need to use gdbserver and connect remotely, because vscode runs in a flatpak container and cannot debug directly
cd build_debug
cmake -G Ninja -DCMAKE_BUILD_TYPE=Debug -DALL_WARNINGS=True -DUSE_SANITIZERS=True -DCMAKE_INSTALL_PREFIX=./installed ..
ninja install
export MAGICCARPET2_GAMEPATH=../magiccarpet2/netherw
gdbserver localhost:9999 installed/bin/remc2
