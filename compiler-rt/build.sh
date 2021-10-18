#!/bin/sh

NDK_PATH=/Users/user/Downloads/android-ndk-r16b
CC="clang -c -target arm-linux-androideabi -Os -march=armv7 -mthumb -mhwdiv=arm,thumb"

${NDK_PATH}/toolchains/llvm/prebuilt/darwin-x86_64/bin/${CC} *.c arm/*.S
${NDK_PATH}/toolchains/arm-linux-androideabi-4.9/prebuilt/darwin-x86_64/bin/arm-linux-androideabi-strip --remove-section=.comment *.o
/usr/local/opt/llvm/bin/llvm-ar r ../linux-android/arch-arm/usr/lib/libcompiler_rt.a *.o 
rm *.o

CC="clang -c -target mipsel-linux-android -Os"

${NDK_PATH}/toolchains/llvm/prebuilt/darwin-x86_64/bin/${CC} *.c
${NDK_PATH}/toolchains/mipsel-linux-android-4.9/prebuilt/darwin-x86_64/bin/mipsel-linux-android-strip --remove-section=.comment *.o
/usr/local/opt/llvm/bin/llvm-ar r ../linux-android/arch-mips/usr/lib/libcompiler_rt.a *.o 
rm *.o

CC="clang -c -target riscv32-linux-android -Os -menable-experimental-extensions -march=rv32gcv0p10 -mno-relax -I../linux-android/usr/include -I../linux-android/usr/include/riscv32-linux-android"

/usr/local/opt/llvm/bin/${CC} *.c
/usr/local/opt/llvm/bin/llvm-strip --remove-section=.comment *.o
/usr/local/opt/llvm/bin/llvm-ar r ../linux-android/arch-riscv32/usr/lib/libcompiler_rt.a *.o 
rm *.o

CC="clang -c -target i686-linux-android -Os"

${NDK_PATH}/toolchains/llvm/prebuilt/darwin-x86_64/bin/${CC} *.c
${NDK_PATH}/toolchains/x86-4.9/prebuilt/darwin-x86_64/bin/i686-linux-android-strip --remove-section=.comment *.o
/usr/local/opt/llvm/bin/llvm-ar r ../linux-android/arch-x86/usr/lib/libcompiler_rt.a *.o 
rm *.o
