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
			printf("Time NorthingSD EastingSD AltitudeSD SpeedNorthSD SpeedEastSD SpeedAltitudeSD RollSd PitchSd HeadingSd\n");
		}

		void processEntry(AccuracyEntry * entry){
			printf("%lf %lf %lf %lf %lf %lf %lf %lf %lf %lf\n",
				entry->time,
				entry->northingSd,
				entry->eastingSd,
                                entry->altitudeSd,
                                entry->speedNorthSd,
                                entry->speedEastSd,
                                entry->speedAltitudeSd,
                                entry->rollSd/60,
                                entry->pitchSd/60,
                                entry->headingSd/60
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
