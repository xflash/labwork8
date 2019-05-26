//
// Created by Gawayn Coqueugniot on 2019-05-16.
//

#ifndef LABWORK8_STATION_H
#define LABWORK8_STATION_H

#include <string>

struct Station {
    int id;
    std::string name;
};

/////////////////////////////

Station *findStation(std::vector<Station *> *stations, int id);

void readStations(const char *filename, std::vector<Station *> *stations);

Station *createStation(int id, string name);

void displayStation(Station *item);

void displayStations(std::vector<Station *> *stations);

void cleanupStations(std::vector<Station *> *stations);

/////////////////////////////

#endif //LABWORK8_STATION_H
