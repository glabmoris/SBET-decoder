/*
 * Copyright 2017 © Centre Interdisciplinaire de développement en Cartographie des Océans (CIDCO), Tous droits réservés
 */

/* 
 * File:   SbetOutputCountTest.hpp
 * Author: Hugo Valcourt
 *
 * Created on November 9, 2018
 */

#include "catch.hpp"
#include "../src/SbetProcessor.hpp"
//A simple printer class

class SbetPrinter : public SbetProcessor {
public:
    unsigned int lines = 0;
    SbetPrinter() {}

    void processEntry(SbetEntry * entry) {
        lines++;
    }
};

TEST_CASE(" SbetOutputCountTest ") {

    std::string inputFile = "test/data/2018-07-11.sbet";

    SbetPrinter sbet;

    sbet.readFile(inputFile);
    REQUIRE(sbet.lines == 4292);
}