#!/bin/sh
rustc --emit asm -C opt-level=3 -C prefer-dynamic test.rs -o test_rs.s
cc test_rs.s -l$(basename $(find /usr/lib -name '*libstd-*.so' -print -quit) | cut -c 4- | cut -c -20) -o test_rs
g++ -S -Ofast -std=c++11 test.cpp -o test_cpp.s
g++ test_cpp.s -o test_cpp
chmod u+x test_cpp test_rs
strip --strip-all test_rs test_cpp
