/*
 * Copyright 2017 © Centre Interdisciplinaire de développement en Cartographie des Océans (CIDCO), Tous droits réservés
 */

/* 
 * File:   SbetPrinterTest.hpp
 * Author: jordan
 */

#ifndef SBETPRINTERTEST_HPP
#define SBETPRINTERTEST_HPP

#include "catch.hpp"
#include <string>
#include <sstream>
#include <cmath>
#include "Utils/CommandLineExecutor.hpp"

double absoluteDifference(double a, double b) {
    return std::abs(std::abs(a) - std::abs(b));
}

TEST_CASE("Accuracy Test") {
    std::string binexec("build/bin/accuracy-decoder");
    std::string file(" test/data/20181023accuracy.out");

    CommandLineExecutor exec;

    std::stringstream ss;
    ss = exec.execute(binexec + file);

    //read header
    std::string header;
    for (int i = 0; i < 10; i++) {
        ss >> header;
    }
    
    double Time;
    double NorthingSD;
    double EastingSD;
    double AltitudeSD;
    double SpeedNorthSD;
    double SpeedEastSD;
    double SpeedAltitudeSD;
    double RollSd;
    double PitchSd;
    double HeadingSd;
    
    ss >> Time >> NorthingSD >> EastingSD >> AltitudeSD >> SpeedNorthSD >> SpeedEastSD >> SpeedAltitudeSD >> RollSd >> PitchSd >> HeadingSd;
    double eps = 1e-9;
    
    //Time NorthingSD EastingSD AltitudeSD SpeedNorthSD SpeedEastSD SpeedAltitudeSD RollSd PitchSd HeadingSd
    //225092.532698 0.023356 0.023366 0.018463 0.005244 0.005267 0.004156 0.002758 0.002759 0.044579
    
    REQUIRE(absoluteDifference(Time, 225092.532698) < eps);
    REQUIRE(absoluteDifference(NorthingSD, 0.023356) < eps);
    REQUIRE(absoluteDifference(EastingSD, 0.023366) < eps);
    REQUIRE(absoluteDifference(AltitudeSD, 0.018463) < eps);
    REQUIRE(absoluteDifference(SpeedNorthSD, 0.005244) < eps);
    REQUIRE(absoluteDifference(SpeedEastSD, 0.005267) < eps);
    REQUIRE(absoluteDifference(SpeedAltitudeSD, 0.004156) < eps);
    REQUIRE(absoluteDifference(RollSd, 0.002758) < eps);
    REQUIRE(absoluteDifference(PitchSd, 0.002759) < eps);
    REQUIRE(absoluteDifference(HeadingSd, 0.044579) < eps);
    
}

TEST_CASE("Sbet Test") {

    std::string binexec("build/bin/sbet-decoder");
    std::string file(" test/data/20181023.out");

    CommandLineExecutor exec;

    std::stringstream ss;
    ss = exec.execute(binexec + file);

    //read header
    std::string header;
    for (int i = 0; i < 17; i++) {
        ss >> header;
    }

    // read data
    double Time;
    double Latitude;
    double Longitude;
    double Altitude;
    double SpeedX;
    double SpeedY;
    double SpeedZ;
    double Heading;
    double Pitch;
    double Roll;
    double Wander;
    double ForceX;
    double ForceY;
    double ForceZ;
    double AngularRateX;
    double AngularRateY;
    double AngularRateZ;

    ss >> Time >> Latitude >> Longitude >> Altitude >> SpeedX >> SpeedY >> SpeedZ >> Heading >> Pitch >> Roll >> Wander >> ForceX >> ForceY >> ForceZ >> AngularRateX >> AngularRateY >> AngularRateZ;

    double eps = 1e-9;

    //Time Latitude Longitude Altitude SpeedX SpeedY SpeedZ Heading Pitch Roll Wander ForceX ForceY ForceZ AngularRateX AngularRateY AngularRateZ
    //225092.532698499999 46.783019673976 -71.272710666896 55.886139 0.003063 -0.002033 0.001337 4.601874186733 0.012073070456 0.079737922580 0.000000 0.000000 0.000000 0.000000 0.000000 0.000000 0.000000

    REQUIRE(absoluteDifference(Time, 225092.532698499999) < eps);
    REQUIRE(absoluteDifference(Latitude, 46.783019673976) < eps);
    REQUIRE(absoluteDifference(Longitude, -71.272710666896) < eps);
    REQUIRE(absoluteDifference(Altitude, 55.886139) < eps);
    REQUIRE(absoluteDifference(SpeedX, 0.003063) < eps);
    REQUIRE(absoluteDifference(SpeedY, -0.002033) < eps);
    REQUIRE(absoluteDifference(SpeedZ, 0.001337) < eps);
    REQUIRE(absoluteDifference(Heading, 4.601874186733) < eps);
    REQUIRE(absoluteDifference(Pitch, 0.012073070456) < eps);
    REQUIRE(absoluteDifference(Roll, 0.079737922580) < eps);
    REQUIRE(absoluteDifference(Wander, 0.0) < eps);
    REQUIRE(absoluteDifference(ForceX, 0.0) < eps);
    REQUIRE(absoluteDifference(ForceY, 0.0) < eps);
    REQUIRE(absoluteDifference(ForceZ, 0.0) < eps);
    REQUIRE(absoluteDifference(AngularRateX, 0.0) < eps);
    REQUIRE(absoluteDifference(AngularRateY, 0.0) < eps);
    REQUIRE(absoluteDifference(AngularRateZ, 0.0) < eps);
}

#endif /* SBETPRINTERTEST_HPP */

