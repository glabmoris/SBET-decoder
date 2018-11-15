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
#define M_PI = 3.14159265358979323846
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
                std::string line = "";
                std::ostringstream tempStr;
                tempStr << std::fixed;
                tempStr << entries[entry].time;
                file << tempStr.str();
                file << " ";
                tempStr.clear();
                tempStr.str("");
                tempStr << (entries[entry].latitude * 180) / M_PI;
                file << tempStr.str();
                file << " ";
                tempStr.clear();
                tempStr.str("");
                tempStr << (entries[entry].longitude * 180) / M_PI;
                file << tempStr.str();
                file << " ";
                tempStr.clear();
                tempStr.str("");
                tempStr << entries[entry].altitude;
                file << tempStr.str();
                file << " ";
                tempStr.clear();
                tempStr.str("");
                tempStr << entries[entry].xSpeed;
                file << tempStr.str();
                file << " ";
                tempStr.clear();
                tempStr.str("");
                tempStr << entries[entry].ySpeed;
                file << tempStr.str();
                file << " ";
                tempStr.clear();
                tempStr.str("");
                tempStr << entries[entry].zSpeed;
                file << tempStr.str();
                file << " ";
                tempStr.clear();
                tempStr.str("");
                tempStr << entries[entry].heading;
                file << tempStr.str();
                file << " ";
                tempStr.clear();
                tempStr.str("");
                tempStr << entries[entry].pitch;
                file << tempStr.str();
                file << " ";
                tempStr.clear();
                tempStr.str("");
                tempStr << entries[entry].roll;
                file << tempStr.str();
                file << " ";
                tempStr.clear();
                tempStr.str("");
                tempStr << entries[entry].wander;
                file << tempStr.str();
                file << " ";
                tempStr.clear();
                tempStr.str("");
                tempStr << entries[entry].xForce;
                file << tempStr.str();
                file << " ";
                tempStr.clear();
                tempStr.str("");
                tempStr << entries[entry].yForce;
                file << tempStr.str();
                file << " ";
                tempStr.clear();
                tempStr.str("");
                tempStr << entries[entry].zForce;
                file << tempStr.str();
                file << " ";
                tempStr.clear();
                tempStr.str("");
                tempStr << entries[entry].xAngularRate;
                file << tempStr.str();
                file << " ";
                tempStr.clear();
                tempStr.str("");
                tempStr << entries[entry].yAngularRate;
                file << tempStr.str();
                file << " ";
                tempStr.clear();
                tempStr.str("");
                tempStr << entries[entry].zAngularRate;
                file << tempStr.str();
                file << " ";
                tempStr.clear();
                tempStr.str("");
                file << std::endl;
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

                std::string line = "";
                std::ostringstream tempStr;
                tempStr << std::fixed;
                tempStr << entries[entry].time;
                file << tempStr.str();
                file << " ";
                tempStr.clear();
                tempStr.str("");
                tempStr << entries[entry].northingSd;
                file << tempStr.str();
                file << " ";
                tempStr.clear();
                tempStr.str("");
                tempStr << entries[entry].eastingSd;
                file << tempStr.str();
                file << " ";
                tempStr.clear();
                tempStr.str("");
                tempStr << entries[entry].altitudeSd;
                file << tempStr.str();
                file << " ";
                tempStr.clear();
                tempStr.str("");
                tempStr << entries[entry].speedNorthSd;
                file << tempStr.str();
                file << " ";
                tempStr.clear();
                tempStr.str("");
                tempStr << entries[entry].speedEastSd;
                file << tempStr.str();
                file << " ";
                tempStr.clear();
                tempStr.str("");
                tempStr << entries[entry].speedAltitudeSd;
                file << tempStr.str();
                file << " ";
                tempStr.clear();
                tempStr.str("");
                tempStr << entries[entry].g;
                file << tempStr.str();
                file << " ";
                tempStr.clear();
                tempStr.str("");
                tempStr << entries[entry].h;
                file << tempStr.str();
                file << " ";
                tempStr.clear();
                tempStr.str("");
                tempStr << entries[entry].i;
                file << tempStr.str();
                file << " ";
                tempStr.clear();
                tempStr.str("");
                file << std::endl;
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
    accuracy.WriteEntries("output-accuracy-2018-07-11.txt");
    REQUIRE(accuracy.io.CheckLines(accuracy.io.GetStringVector("test/data/real-output-accuracy-2018-07-11.txt"), "output-accuracy-2018-07-11.txt"));

    SbetBuilder sbet;

    sbet.readFile(inputFile);
    sbet.WriteEntries("output-sbet-2018-07-11.txt");
    REQUIRE(sbet.io.CheckLines(accuracy.io.GetStringVector("test/data/real-output-sbet-2018-07-11.txt"), "output-sbet-2018-07-11.txt"));
}

#endif /* CHECKLINESTEST_HPP */

