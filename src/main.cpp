#include <utility>

#include <iostream>
#include <string>
#include <list>
#include <iterator>
#include <fstream>
#include <vector>

using namespace std;

#include "Station.h"

/////////////////////////////

Station *findStation(std::vector<Station *> *stations, int id);

void readStations(const char *filename, std::vector<Station *> *stations);

Station *createStation(int id, string name);

void displayStation(Station *item);

void displayList(std::vector<Station *> *stations);

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

    cerr << "Station id " << id << " not found " << endl;

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

Station *createStation(int id, string name) {
    Station *pStation = new Station;
    pStation->id = id;
    pStation->name = std::move(name);
    return pStation;
}

void displayStation(Station *item) {
    cout << item->id << ":" << item->name << endl;
}

void displayList(std::vector<Station *> *stations) {
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

int main() {

    std::vector<Station *> stations = std::vector<Station *>();

    readStations("data/stations.csv", &stations);

    displayList(&stations);

    int id = 105222;
    Station *station = findStation(&stations, id);
    if (station != nullptr) {
        cout << "Station id " << id << " found : " << station->name << endl;
    }
    // 99999 should not be founded
    findStation(&stations, 99999);


    cleanupStations(&stations);
}
