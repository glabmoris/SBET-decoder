/**
 * @author Guillaume Labbe-Morissette
 */

#ifndef MAIN_CPP
#define MAIN_CPP

#include <cstdlib>
#include <cstdio>
#include <string>
#include <cmath>


#include "SbetProcessor.hpp"

void printUsage(){
	printf("Usage: sbet-decoder input-file\n");
	exit(0);
}

//A simple printer class
class SbetPrinter: public SbetProcessor{
	public:
		SbetPrinter(){
			printf("Time Latitude Longitude Altitude SpeedX SpeedY SpeedZ Heading Pitch Roll Wander ForceX ForceY ForceZ AngularRateX AngularRateY AngularRateZ\n");
		}

		void processEntry(SbetEntry * entry){
			printf("%lf %lf %lf %lf %lf %lf %lf %lf %lf %lf %lf %lf %lf %lf %lf %lf %lf\n",
				entry->time,
				(entry->latitude * 180) / M_PI,
				(entry->longitude* 180) / M_PI,
				entry->altitude,
				entry->xSpeed,
				entry->ySpeed,
				entry->zSpeed,
				entry->heading,
				entry->pitch,
				entry->roll,
				entry->wander,
				entry->xForce,
				entry->yForce,
				entry->zForce,
				entry->xAngularRate,
				entry->yAngularRate,
				entry->zAngularRate
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

	SbetPrinter sbet;

	sbet.readFile(inputFile);

	return 0;
}

#endif
