/*
 * Copyright 2017 © Centre Interdisciplinaire de développement en Cartographie des Océans (CIDCO), Tous droits réservés
 */

/* 
 * File:   SbetPrinter.hpp
 * Author: glm,jordan
 */

#ifndef SBETPRINTER_HPP
#define SBETPRINTER_HPP

#include <cstdio>
#include <string>
#include <cmath>
#include "SbetProcessor.hpp"

class SbetPrinter: public SbetProcessor{
	public:
		SbetPrinter(){
			printf("Time Latitude Longitude Altitude SpeedX SpeedY SpeedZ Heading Pitch Roll Wander ForceX ForceY ForceZ AngularRateX AngularRateY AngularRateZ\n");
		}

		void processEntry(SbetEntry * entry){
			printf("%.12lf %.12lf %.12lf %lf %lf %lf %lf %.12lf %.12lf %.12lf %lf %lf %lf %lf %lf %lf %lf\n",
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

#endif /* SBETPRINTER_HPP */

