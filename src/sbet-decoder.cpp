/**
 * @author Guillaume Labbe-Morissette
 */

#ifndef MAIN_CPP
#define MAIN_CPP
//For M_PI
#ifdef _WIN32
#define _USE_MATH_DEFINES
#endif

#include <cstdio>
#include <string>
#include "SbetPrinter.hpp"

void printUsage(){
	printf("Usage: sbet-decoder input-file\n");
	exit(0);
}

/*
 * Main
 */
int main(int argc,char ** argv){

	if(argc != 2){
		printUsage();
	}

	std::string inputFile = argv[1];

	SbetPrinter sbet;

	sbet.readFile(inputFile);

	return 0;
}

#endif
