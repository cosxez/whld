# WHLD Custom Image Format

## Installing Dependencies:

#### Dependencies:

`g++` - Compiler
`SDL2` - For Display 
`Opencv` - For Convert

#### Debian:
`sudo apt install g++ libsdl2-dev libopencv-dev`

#### Fedora:
`sudo dnf install gcc-c++ opencv-devel SDL2-devel`

#### Arch:
`sudo pacman -S gcc opencv sdl2`
## Compilation:

#### Compilation converter:

convert/to_binary/convert_to_binary.cpp
`g++ convert_to_binary.cpp -o convert_to_binary $(pkg-config -cflags -libs opencv4)`

convert/to_text/convert_to_text.cpp
`g++ convert_to_text.cpp -o convert_to_text $(pkg-config -cflags -libs opencv4)`

#### Compilation viewer:
viewer/binary/viewer.cpp
`g++ viewer.cpp -o viewer -lSDL2`

viewer/text/viewer.cpp
`g++ viewer.cpp -o viewer -lSDL2`
