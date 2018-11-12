/*
 * Copyright 2017 © Centre Interdisciplinaire de développement en Cartographie des Océans (CIDCO), Tous droits réservés
 */

/* 
 * File:   AccuracyOutputCountTest.hpp
 * Author: Hugo Valcourt
 *
 * Created on November 9, 2018
 */

#include "catch.hpp"
#include "../src/AccuracyProcessor.hpp"

//A simple printer class

class AccuracyPrinter : public AccuracyProcessor {
public:
    unsigned int lines = 0;
    AccuracyPrinter() {
    }

    void processEntry(AccuracyEntry * entry) {
        lines++;

    }
};

TEST_CASE(" AccuracyOutputCountTest ") {

    std::string inputFile = "test/data/2018-07-11.sbet";

    AccuracyPrinter accuracy;

    accuracy.readFile(inputFile);

    REQUIRE(accuracy.lines == 7296);
}