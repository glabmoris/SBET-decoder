/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   IO.hpp
 * Author: hugo
 *
 * Created on November 15, 2018, 9:28 AM
 */

#ifndef IO_HPP
#define IO_HPP

#include <vector>
#include <string>
#include <fstream>
#include <sstream>
#include <iomanip>
#include "../../src/AccuracyProcessor.hpp"
#include "../../src//SbetProcessor.hpp"

class IO {
public:
    bool CheckLines(std::vector<std::string> fileLines, std::string fileName);
    std::vector<std::string> GetStringVector(std::string fileName);

private:

};

bool IO::CheckLines(std::vector<std::string> fileLines, std::string fileName) {
    std::ifstream file;
    file.open(fileName);

    if (!file) {
        std::cerr << "Error while reading the file " << fileName << std::endl;
        return false;
    } else {
        std::string str;
        int lIndex = 0;
        while (std::getline(file, str)) {
            if (lIndex > 0) {
                if (!str.compare(fileLines[lIndex])) {
                    std::cerr << "Line " << lIndex << " is incorrect in the file " << fileName << std::endl;
                    std::cerr << str << " is not == to " << fileLines[lIndex] << std::endl;
                    std::cout << str << std::endl;
                    std::cout << fileLines[lIndex] << std::endl;
                    return false;
                }
            }
            lIndex++;
        }
    }
    file.close();
    return true;
}

std::vector<std::string> IO::GetStringVector(std::string fileName) {
    std::ifstream file;
    file.open(fileName);
    std::vector<std::string> tempStrV;
    if (!file) {
        std::cerr << "Error while reading the file " << fileName << std::endl;
    } else {
        std::string str;
        while (std::getline(file, str)) {
            tempStrV.push_back(str);
        }
    }
    file.close();

    return tempStrV;
}

#endif /* IO_HPP */

