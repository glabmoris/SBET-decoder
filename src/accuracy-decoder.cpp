/**
 * @author Guillaume Labbe-Morissette
 */

#ifndef MAIN_CPP
#define MAIN_CPP
//For M_PI
#ifdef _WIN32
#define _USE_MATH_DEFINES
#endif


#include <cstdlib>
#include <cstdio>
#include <string>
#include <cmath>


#include "AccuracyProcessor.hpp"

void printUsage(){
	printf("Usage: accuracy-decoder input-file\n");
	exit(0);
}

//A simple printer class
class AccuracyPrinter: public AccuracyProcessor{
	public:
		AccuracyPrinter(){
			printf("Time a b c d e f g h i\n");
		}

		void processEntry(AccuracyEntry * entry){
			printf("%lf %lf %lf %lf %lf %lf %lf %lf %lf %lf\n",
				entry->time,
				entry->a,
				entry->b,
                                entry->c,
                                entry->d,
                                entry->e,
                                entry->f,
                                entry->g,
                                entry->h,
                                entry->i
			);
		}
};

/*
 * Main
 */
int main(int argc,char ** argv){

	if(argc != 2){
		printUsage();
	}

	std::string inputFile = argv[1];

	AccuracyPrinter accuracy;

	accuracy.readFile(inputFile);

	return 0;
}

#endif
