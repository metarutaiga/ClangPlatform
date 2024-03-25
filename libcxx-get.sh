#!/bin/sh

define=$(grep 'define _LIBCPP_VERSION' /Applications/Xcode.app/Contents/Developer/Platforms/MacOSX.platform/Developer/SDKs/MacOSX.sdk/usr/include/c++/v1/__config)
arrays=($define)

major=$(echo ${arrays[3]} | cut -c1-2)
minor=$(echo ${arrays[3]} | cut -c4)
patch=$(echo ${arrays[3]} | cut -c6)

file=libcxx-${major}.${minor}.${patch}.src.tar.xz
url=https://github.com/llvm/llvm-project/releases/download/llvmorg-${major}.${minor}.${patch}/libcxx-${major}.${minor}.${patch}.src.tar.xz

echo ${define}
if [ ! -f ${file} ]; then 
  curl -LO ${url}
fi
