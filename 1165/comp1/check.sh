#!/bin/zsh

clang++ -g compress.cpp -o compress
clang -g decompress.c -o decompress

./compress ../dict.txt c.txt $1
./decompress c.txt d.txt $1

#diff ../dict.txt d.txt
wc -c ../dict.txt c.txt
