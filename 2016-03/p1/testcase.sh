#! /bin/bash

rm -r -f testcases/ sol gen

mkdir testcases

g++ -std=c++11 -o sol sol.cpp
g++ -std=c++11 -o gen gen.cpp



rm -f sol gen