#!/bin/sh
rustc -O -C prefer-dynamic test.rs -o test_rs
g++ -O2 test.cpp -o test_cpp
strip --strip-all test_rs test_cpp