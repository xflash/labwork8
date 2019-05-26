#include <utility>

#include <utility>

#include <utility>

#include <iostream>
#include <string>
#include <list>
#include <iterator>
#include <fstream>
#include <vector>

using namespace std;

#include "Station.h"
#include "Path.h"


/////////////////////////////

Station *findStation(std::vector<Station *> *stations, int id);

void readStations(const char *filename, std::vector<Station *> *stations);

Station *createStation(int id, string name);

Path *
createPath(std::vector<Station *> *stations, string id, string lineName, int stationId, string hour, int sequence);

void displayStation(Station *item);

void displayStations(std::vector<Station *> *stations);

void displayPaths(std::list<Path *> *paths);

void cleanupStations(std::vector<Station *> *stations);

/////////////////////////////

vector<string> split(const char *str, char c = ';') {
    vector<string> result;
    do {
        const char *begin = str;

        while (*str != c && *str)
            str++;

        result.emplace_back(begin, str);
    } while (0 != *str++);

    return result;
}

Station *findStation(std::vector<Station *> *stations, int id) {
    for (const auto &item : *stations) {
        if (item->id == id)
            return item;
    }


    return nullptr;
}


void readStations(const char *filename, std::vector<Station *> *stations) {
    std::ifstream stations_file(filename);
    std::string line;
    while (std::getline(stations_file, line)) {
        const vector<string> &cells = split(line.data());
        stations->push_back(createStation(
                std::stoi(cells.at(1)),
                cells.at(0)));
    }
}

void readPaths(const char *filename, std::list<Path *> *paths, std::vector<Station *> *stations) {
    std::ifstream file(filename);
    std::string line;
    while (std::getline(file, line)) {
        const vector<string> &cells = split(line.data());
        // 301A_3_1_021AN_011004;A;105023;05:17:00;12

        paths->push_back(createPath(stations,
                                    cells.at(0),
                                    cells.at(1),
                                    std::stoi(cells.at(2)),
                                    cells.at(3),
                                    std::stoi(cells.at(4))
        ));
    }
}

Station *createStation(int id, string name) {
    Station *pStation = new Station;
    pStation->id = id;
    pStation->name = std::move(name);
    return pStation;
}


Path *createPath(std::vector<Station *> *stations,
                 string id, string lineName, int stationId, string hour, int sequence) {
    Path *pPath = new Path;
    pPath->id = std::move(id);
    pPath->lineName = std::move(lineName);
    pPath->station = findStation(stations, stationId);
    pPath->hour = std::move(hour);
    pPath->sequenceNumber = sequence;
    return pPath;
}

void displayStation(Station *item) {
    cout << item->id << ":" << item->name << endl;
}

void displayPaths(std::list<Path *> *paths) {
    cout << "## PATHS" << endl;
    for (const auto &item : *paths) {
        cout << item->id
             << " line:" << item->lineName
             << " station:" << item->station->name
             << " hour:" << item->hour
             << " seq:" << item->sequenceNumber
             << endl;

    }
    cout << endl;
}

void displayStations(std::vector<Station *> *stations) {
    cout << "## STATIONS" << endl;
    for (const auto &item : *stations) {
        displayStation(item);
    }
    cout << endl;
}

void cleanupStations(std::vector<Station *> *stations) {
    cout << "Cleaning up " << stations->size() << " stations" << endl;
    for (auto &item : *stations) {
        delete item;
    }
}

void cleanupPaths(std::list<Path *> *paths) {
    cout << "Cleaning up " << paths->size() << " paths" << endl;
    for (auto &item : *paths) {
        delete item;
    }
}

int main() {

    std::vector<Station *> stations = std::vector<Station *>();
    readStations("data/stations.csv", &stations);
    displayStations(&stations);

    std::list<Path *> paths = std::list<Path *>();
    readPaths("data/path.csv", &paths, &stations);
    displayPaths(&paths);

    int id = 105222;
    Station *station = findStation(&stations, id);
    if (station != nullptr) {
        cout << "Station id " << id << " found : " << station->name << endl;
    } else {
        cout << "Station id " << id << " not found " << endl;
    }
    // 99999 should not be founded  
    id = 99999;
    station = findStation(&stations, id);
    if (station != nullptr) {
        cout << "Station id " << id << " found : " << station->name << endl;
    } else {
        cout << "Station id " << id << " not found " << endl;
    }

    cleanupPaths(&paths);
    cleanupStations(&stations);
}
