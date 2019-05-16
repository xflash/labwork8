#include <iostream>
#include <string>
#include <list>
#include <iterator>

using namespace std;

#include "Station.h"

Station *createStation(int id, const char *name);

void displayList(list<Station *> *list);

void cleanupList(std::list<Station *> list);

Station *createStation(int id, const char *name) {
    Station *pStation = new Station;
    pStation->id = id;
    pStation->name = name;
    return pStation;
}

void displayList(list<Station *> *list) {
    for (const auto &item : *list) {
        cout << item->id << ":" << item->name << endl;
    }
    cout << endl;
}

void cleanupList(std::list<Station *> *list) {
    cout << "Cleaning up list " << list->size() << endl;

    for (auto &item : *list) {
        delete item;
    }

}

int main() {

    auto list = std::list<Station *>();

    list.push_back(createStation(1, "station 1"));

    displayList(&list);

    cleanupList(&list);
}
