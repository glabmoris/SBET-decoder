CC=g++
CFLAGS=-Wall

default: src/main.cpp
	mkdir -p build
	g++ -o build/sbet-decoder src/main.cpp


