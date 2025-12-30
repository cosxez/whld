# WHLD Custom Image Format

## Structure binary file:

<img src="https://github.com/cosxez/whld/blob/main/struct_binary_file.png" width="600" height="400"/>

**Each number in the uint8_t range stores 1 byte.**

## Structure text file:

<img src="https://github.com/cosxez/whld/blob/main/struct_text_file.png" width="600" height="400"/>

**The size depends on the length of the string because 1 char = 1 byte**

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
`sudo pacman -S g++ opencv sdl2`

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
