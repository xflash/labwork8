#include <utility>
#include <iostream>
#include <string>
#include <sstream>
#include <list>
#include <iterator>
#include <fstream>
#include <vector>

using namespace std;

#include "Station.h"
#include "StringUtils.h"

/**
 * Read a CSV file named filename, and fill up a vector of Station pointer with newly created Station
**/
void readStations(const char *filename, vector<Station *> *stations) {

    // Open the CSV file to be read
    ifstream stations_file(filename);

    string line;
    // While the CSV file have some lines to be read
    while (getline(stations_file, line)) {
        //Split each line containing ; into cell vector
        const vector<string> &cells = split(line);
        //Extracting cells content
        string name = cells.at(0);
        string sid = cells.at(1);
        //Convert sid to int
        int id = std::stoi(sid);
        //Create new station with converted id and name
        Station* station = createStation(id,  name);
        //Add new station to vector pointer
        stations->push_back(station);
    }
    //Close the CSV file
    stations_file.close();

}

/**
 *
**/
void displayStations(vector<Station *> *stations) {
    cout << "## STATIONS" << endl;
     // Declaring iterator to a vector
    vector<Station *>::iterator it;
    //Iterate over the whole stations vector
     for (it = stations->begin(); it != stations->end(); it++) {
        displayStation(*it);
    }
    cout << endl;
}


/**
 * Iterate over a vector of Station to find one with its id matching parameter id
**/
Station *findStation(vector<Station *> *stations, int id) {
     // Declaring iterator to a vector
    vector<Station *>::iterator it;
    //Iterate over the whole stations vector
     for (it = stations->begin(); it != stations->end(); it++) {
        // Localize the station pointed by the iterator
        Station* station_to_check = *it;
        // if id matchs -> return the Station
        if (station_to_check->id == id){
            return station_to_check;
        }
    }
    // it no station have been found return NULL
    return nullptr;
}
/**
 * Create a new instance of Station
**/
Station *createStation(int id, string name) {
    Station *pStation = new Station;
    pStation->id = id;
    pStation->name = name;
    return pStation;
}

/**
 * Display a single station on standrad output
**/
void displayStation(Station *item) {
    cout << item->id << ":" << item->name << endl;
}

/**
 * Cleanup from memory the created instances
**/
void cleanupStations(std::vector<Station *> *stations) {
    cout << "Cleaning up " << stations->size() << " stations" << endl;
     vector<Station *>::iterator it;
    //Iterate over the whole stations vector
     for (it = stations->begin(); it != stations->end(); it++) {
        // Localize the station pointed by the iterator
        Station* item = *it;
        // Cleanup memory instance
        delete item;
    }
}

