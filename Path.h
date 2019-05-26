//
// Created by Gawayn Coqueugniot on 2019-05-16.
//

#ifndef LABWORK8_PATH_H
#define LABWORK8_PATH_H

#include <string>

#include "Station.h"

struct Path {
    std::string id;
    std::string lineName;
    Station *station;
    int hour;
    int sequenceNumber;

    bool operator<(const Path &str) const {
        return (hour < str.hour);
    }
};

void readPaths(const char *filename, list<Path *> *paths, vector<Station *> *stations);

Path *createPath(string id, string lineName, Station *station, string hour, int sequence);

void displayPaths(std::list<Path *> *paths);

void cleanupPaths(list<Path *> *paths);

int countSubwaysForLine(list<Path *> *paths, string line);

int strToHour(string str);

string hourToString(int hour);

vector<Station *> findStation4LineAt(list<Path *> *pList, string basicString, int hour);


#endif //LABWORK8_PATH_H
