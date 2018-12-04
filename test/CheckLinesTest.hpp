/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   CheckLinesTest.hpp
 * Author: hugo
 *
 * Created on November 15, 2018, 9:26 AM
 */

#include "catch.hpp"
#include "../src/AccuracyProcessor.hpp"
#include "../src/SbetProcessor.hpp"
#include "Utils/IO.hpp"

#ifdef _WIN32
#define M_PI 3.14159265358979323846
#endif

#ifndef CHECKLINESTEST_HPP
#define CHECKLINESTEST_HPP

class SbetBuilder : public SbetProcessor {
public:
    unsigned int lines = 0;
    IO io;
    std::vector<SbetEntry> entries;

    SbetBuilder() {
    }

    void processEntry(SbetEntry * entry) {
        entries.push_back(*entry);
    }

    bool WriteEntries(std::string fileName) {

        std::ofstream file;
        file.open(fileName);

        if (!file) {
            std::cerr << "Error writing in the file " << fileName << std::endl;
            return false;
        } else {
            file << "Time Latitude Longitude Altitude SpeedX SpeedY SpeedZ Heading Pitch Roll Wander ForceX ForceY ForceZ AngularRateX AngularRateY AngularRateZ\n";

            for (unsigned int entry = 0; entry < entries.size(); entry++) {
                char tempBuffer[1024];
                sprintf(tempBuffer, "%lf %lf %lf %lf %lf %lf %lf %lf %lf %lf %lf %lf %lf %lf %lf %lf %lf\n",
                        entries[entry].time,
                        (entries[entry].latitude * 180) / M_PI,
                        (entries[entry].longitude * 180) / M_PI,
                        entries[entry].altitude,
                        entries[entry].xSpeed,
                        entries[entry].ySpeed,
                        entries[entry].zSpeed,
                        entries[entry].heading,
                        entries[entry].pitch,
                        entries[entry].roll,
                        entries[entry].wander,
                        entries[entry].xForce,
                        entries[entry].yForce,
                        entries[entry].zForce,
                        entries[entry].xAngularRate,
                        entries[entry].yAngularRate,
                        entries[entry].zAngularRate
                        );
                file << tempBuffer;
            }
        }
        file.close();
        return true;
    }
};

class AccuracyBuilder : public AccuracyProcessor {
public:
    unsigned int lines = 0;
    IO io;
    std::vector<AccuracyEntry> entries;

    AccuracyBuilder() {
    }

    void processEntry(AccuracyEntry * entry) {
        entries.push_back(*entry);
    }

    bool WriteEntries(std::string fileName) {

        std::ofstream file;
        file.open(fileName);

        if (!file) {
            std::cerr << "Error writing in the file " << fileName << std::endl;
            return false;
        } else {
            file << "Time NorthingSD EastingSD AltitudeSD SpeedNorthSD SpeedEastSD SpeedAltitudeSD g h i\n";

            for (unsigned int entry = 0; entry < entries.size(); entry++) {
                char tempBuffer[1024];
                sprintf(tempBuffer, "%lf %lf %lf %lf %lf %lf %lf %lf %lf %lf\n",
                        entries[entry].time,
                        entries[entry].northingSd,
                        entries[entry].eastingSd,
                        entries[entry].altitudeSd,
                        entries[entry].speedNorthSd,
                        entries[entry].speedEastSd,
                        entries[entry].speedAltitudeSd,
                        entries[entry].rollSd,
                        entries[entry].pitchSd,
                        entries[entry].headingSd
                        );
                file << tempBuffer;
            }
        }
        file.close();
        return true;
    }
};

TEST_CASE(" CheckLinesTest ") {

    std::string inputFile = "test/data/2018-07-11.sbet";

    AccuracyBuilder accuracy;

    accuracy.readFile(inputFile);
    accuracy.WriteEntries("test//data//output-accuracy-2018-07-11.txt");
    REQUIRE(accuracy.io.CheckLines(accuracy.io.GetStringVector("test/data/real-output-accuracy-2018-07-11.txt"), "test//data//output-accuracy-2018-07-11.txt"));

    SbetBuilder sbet;

    sbet.readFile(inputFile);
    sbet.WriteEntries("test//data//output-sbet-2018-07-11.txt");
    REQUIRE(sbet.io.CheckLines(accuracy.io.GetStringVector("test/data/real-output-sbet-2018-07-11.txt"), "test//data//output-sbet-2018-07-11.txt"));
}

#endif /* CHECKLINESTEST_HPP */

