# need to use gdbserver and connect remotely, because vscode runs in a flatpak container and cannot debug directly
gdbserver localhost:9999 build_debug/installed/bin/remc2
