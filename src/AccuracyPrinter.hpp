/*
 * Copyright 2017 © Centre Interdisciplinaire de développement en Cartographie des Océans (CIDCO), Tous droits réservés
 */

/* 
 * File:   AccuracyPrinter.hpp
 * Author: jordan
 */

#ifndef ACCURACYPRINTER_HPP
#define ACCURACYPRINTER_HPP

#include "AccuracyProcessor.hpp"
#include <cstdio>
#include <string>

class AccuracyPrinter : public AccuracyProcessor {
public:

    AccuracyPrinter() {
        printf("Time NorthingSD EastingSD AltitudeSD SpeedNorthSD SpeedEastSD SpeedAltitudeSD RollSd PitchSd HeadingSd\n");
    }

    void processEntry(AccuracyEntry * entry) {
        printf("%lf %lf %lf %lf %lf %lf %lf %lf %lf %lf\n",
                entry->time,
                entry->northingSd,
                entry->eastingSd,
                entry->altitudeSd,
                entry->speedNorthSd,
                entry->speedEastSd,
                entry->speedAltitudeSd,
                entry->rollSd / 60,
                entry->pitchSd / 60,
                entry->headingSd / 60
                );
    }
};

#endif /* ACCURACYPRINTER_HPP */

