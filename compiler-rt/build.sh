#!/bin/sh

NDK_PATH=/Users/user/Downloads/android-ndk-r16b
CC="clang -c -target arm-linux-androideabi -Os -fvisibility=hidden -march=armv7 -mthumb -mhwdiv=arm,thumb"

rm *.o
${NDK_PATH}/toolchains/llvm/prebuilt/darwin-x86_64/bin/${CC} *.c arm/*.S
${NDK_PATH}/toolchains/arm-linux-androideabi-4.9/prebuilt/darwin-x86_64/bin/arm-linux-androideabi-objcopy --remove-section=.comment aeabi_ldivmod.o
${NDK_PATH}/toolchains/arm-linux-androideabi-4.9/prebuilt/darwin-x86_64/bin/arm-linux-androideabi-objcopy --remove-section=.comment aeabi_uldivmod.o
${NDK_PATH}/toolchains/arm-linux-androideabi-4.9/prebuilt/darwin-x86_64/bin/arm-linux-androideabi-objcopy --remove-section=.comment divdi3.o
${NDK_PATH}/toolchains/arm-linux-androideabi-4.9/prebuilt/darwin-x86_64/bin/arm-linux-androideabi-objcopy --remove-section=.comment divmoddi4.o
${NDK_PATH}/toolchains/arm-linux-androideabi-4.9/prebuilt/darwin-x86_64/bin/arm-linux-androideabi-objcopy --remove-section=.comment moddi3.o
${NDK_PATH}/toolchains/arm-linux-androideabi-4.9/prebuilt/darwin-x86_64/bin/arm-linux-androideabi-objcopy --remove-section=.comment udivdi3.o
${NDK_PATH}/toolchains/arm-linux-androideabi-4.9/prebuilt/darwin-x86_64/bin/arm-linux-androideabi-objcopy --remove-section=.comment udivmoddi4.o
${NDK_PATH}/toolchains/arm-linux-androideabi-4.9/prebuilt/darwin-x86_64/bin/arm-linux-androideabi-objcopy --remove-section=.comment umoddi3.o
/usr/local/opt/llvm/bin/llvm-ar r ../linux-android/arch-arm/usr/lib/libcompiler_rt.a *.o 
rm *.o

CC="clang -c -target mipsel-linux-android -Os -fvisibility=hidden"

rm *.o
${NDK_PATH}/toolchains/llvm/prebuilt/darwin-x86_64/bin/${CC} *.c
${NDK_PATH}/toolchains/mipsel-linux-android-4.9/prebuilt/darwin-x86_64/bin/mipsel-linux-android-objcopy --remove-section=.comment divdi3.o
${NDK_PATH}/toolchains/mipsel-linux-android-4.9/prebuilt/darwin-x86_64/bin/mipsel-linux-android-objcopy --remove-section=.comment divmoddi4.o
${NDK_PATH}/toolchains/mipsel-linux-android-4.9/prebuilt/darwin-x86_64/bin/mipsel-linux-android-objcopy --remove-section=.comment moddi3.o
${NDK_PATH}/toolchains/mipsel-linux-android-4.9/prebuilt/darwin-x86_64/bin/mipsel-linux-android-objcopy --remove-section=.comment udivdi3.o
${NDK_PATH}/toolchains/mipsel-linux-android-4.9/prebuilt/darwin-x86_64/bin/mipsel-linux-android-objcopy --remove-section=.comment udivmoddi4.o
${NDK_PATH}/toolchains/mipsel-linux-android-4.9/prebuilt/darwin-x86_64/bin/mipsel-linux-android-objcopy --remove-section=.comment umoddi3.o
/usr/local/opt/llvm/bin/llvm-ar r ../linux-android/arch-mips/usr/lib/libcompiler_rt.a *.o 
rm *.o

CC="clang -c -target riscv32-linux-android -Os -fvisibility=hidden -menable-experimental-extensions -march=rv32gcv0p10 -mno-relax -I../linux-android/usr/include -I../linux-android/usr/include/riscv32-linux-android"

rm *.o
/usr/local/opt/llvm/bin/${CC} *.c
/usr/local/opt/llvm/bin/llvm-objcopy --remove-section=.comment divdi3.o
/usr/local/opt/llvm/bin/llvm-objcopy --remove-section=.comment divmoddi4.o
/usr/local/opt/llvm/bin/llvm-objcopy --remove-section=.comment moddi3.o
/usr/local/opt/llvm/bin/llvm-objcopy --remove-section=.comment udivdi3.o
/usr/local/opt/llvm/bin/llvm-objcopy --remove-section=.comment udivmoddi4.o
/usr/local/opt/llvm/bin/llvm-objcopy --remove-section=.comment umoddi3.o
/usr/local/opt/llvm/bin/llvm-ar r ../linux-android/arch-riscv32/usr/lib/libcompiler_rt.a *.o 
rm *.o

CC="clang -c -target i686-linux-android -Os -fvisibility=hidden"

rm *.o
${NDK_PATH}/toolchains/llvm/prebuilt/darwin-x86_64/bin/${CC} *.c
${NDK_PATH}/toolchains/x86-4.9/prebuilt/darwin-x86_64/bin/i686-linux-android-objcopy --remove-section=.comment divdi3.o
${NDK_PATH}/toolchains/x86-4.9/prebuilt/darwin-x86_64/bin/i686-linux-android-objcopy --remove-section=.comment divmoddi4.o
${NDK_PATH}/toolchains/x86-4.9/prebuilt/darwin-x86_64/bin/i686-linux-android-objcopy --remove-section=.comment moddi3.o
${NDK_PATH}/toolchains/x86-4.9/prebuilt/darwin-x86_64/bin/i686-linux-android-objcopy --remove-section=.comment udivdi3.o
${NDK_PATH}/toolchains/x86-4.9/prebuilt/darwin-x86_64/bin/i686-linux-android-objcopy --remove-section=.comment udivmoddi4.o
${NDK_PATH}/toolchains/x86-4.9/prebuilt/darwin-x86_64/bin/i686-linux-android-objcopy --remove-section=.comment umoddi3.o
/usr/local/opt/llvm/bin/llvm-ar r ../linux-android/arch-x86/usr/lib/libcompiler_rt.a *.o 
rm *.o
