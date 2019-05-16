#include <iostream>
#include <string>
#include <list>
#include <iterator>
#include <fstream>
#include <vector>

using namespace std;

#include "Station.h"

Station *findStation(int id);

void readStations(const char *filename, std::list<Station *> *list);

Station *createStation(int id, string name);

void displayStation(Station *item);

void displayList(std::list<Station *> *list);

void cleanupList(std::list<Station *> *list);

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

Station *findStation(std::list<Station *> *list, int id) {
    for (const auto &item : *list) {
        if (item->id == id)
            return item;
    }

    return nullptr;
}


void readStations(const char *filename, std::list<Station *> *list) {
    std::ifstream stations_file(filename);
    std::string line;
    while (std::getline(stations_file, line)) {
        const vector<string> &cells = split(line.data());
        list->push_back(createStation(
                std::stoi(cells.at(1)),
                cells.at(0)));
    }
}

Station *createStation(int id, string name) {
    Station *pStation = new Station;
    pStation->id = id;
    pStation->name = name;
    return pStation;
}

void displayStation(Station *item) { cout << item->id << ":" << item->name << endl; }

void displayList(std::list<Station *> *list) {
    for (const auto &item : *list) {
        displayStation(item);
    }
    cout << endl;
}

void cleanupList(std::list<Station *> *list) {
    cout << "Cleaning up list of " << list->size() << " elements" << endl;

    for (auto &item : *list) {
        delete item;
    }
}

int main() {

    std::list<Station *> stations = std::list<Station *>();

    readStations("data/stations.csv", &stations);

    displayList(&stations);

    int id = 105222;
    Station *station = findStation(&stations, id);
    if (station != nullptr) {
        cout << "Station id " << id << " found : " << station->name << endl;
    } else {
        cerr << "Station not found " << endl;
    }


    cleanupList(&stations);
}
