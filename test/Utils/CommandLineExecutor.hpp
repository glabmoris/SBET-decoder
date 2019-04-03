/*
 * Copyright 2017 © Centre Interdisciplinaire de développement en Cartographie des Océans (CIDCO), Tous droits réservés
 */

/* 
 * File:   CommandLineExecutor.hpp
 * Author: jordan
 */

#ifndef COMMANDLINEEXECUTOR_HPP
#define COMMANDLINEEXECUTOR_HPP

#include <sstream>
#include <string>

class CommandLineExecutor {
private:

public:
    
    CommandLineExecutor(){};
    
    ~CommandLineExecutor(){};
    


    std::stringstream execute(const std::string& command) {

        std::stringstream out;
        FILE *fp;
        char path[1035];

#ifdef _WIN32
        fp = _popen(command.c_str(), "r");
#else
        fp = popen(command.c_str(), "r");
#endif
        if (fp == NULL) {
            printf("Failed to run command\n");
            exit(1);
        }

        while (fgets(path, sizeof (path) - 1, fp) != NULL) {
            out << path;
        }

#ifdef _WIN32
        _pclose(fp);
#else
        pclose(fp);
#endif

        return out;
    }

};

#endif /* COMMANDLINEEXECUTOR_HPP */

