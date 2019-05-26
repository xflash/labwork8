#include <utility>
#include <iostream>
#include <string>
#include <sstream>
#include <list>
#include <iterator>
#include <fstream>
#include <vector>

using namespace std;

#include "Path.h"
#include "Station.h"
#include "StringUtils.h"

/**
 * Read a CSV file for Path and fill a list of Path with the help of a Staion vector
**/
void readPaths(const char *filename, list<Path *> *paths, vector<Station *> *stations) {

    //Open the CSV file to be read
    ifstream csvFile(filename);
    string line;
    // While there is some lines to be read
    while (getline(csvFile, line)) {
        //Split each line containing ; into cell vector
        const vector<string> &cells = split(line);

        // 301A_3_1_021AN_011004;A;105023;05:17:00;12

        //Extract each cell of interest
        string pathId = cells.at(0);
        string lineName = cells.at(1);
        string s_stationId = cells.at(2);
        string hour = cells.at(3);
        string s_sequence = cells.at(4);
        //Convert s_stationId to int
        int stationId = stoi(s_stationId);
        //Search the station with this id
        Station *station = findStation(stations, stationId);

        //Convert s_sequence to int
        int sequence = stoi(s_sequence);

        // Create a new Path
        Path *new_path = createPath(pathId, lineName, station, hour, sequence);

        // Add the path to the list pointer
        paths->push_back(new_path);
    }

    //Close the CSV file
    csvFile.close();
}

/**
 * Create a new instance of Path
**/
Path *createPath(string id, string lineName, Station *station, string hour, int sequence) {
    Path *pPath = new Path;
    pPath->id = id;
    pPath->lineName = lineName;
    pPath->station = station;
    pPath->hour = hour;
    pPath->sequenceNumber = sequence;
    return pPath;
}

/**
 * Display a whole list of Path to standard output
**/
void displayPaths(list<Path *> *paths) {
    cout << "## PATHS" << endl;

    // Declaring iterator to a list
    list<Path *>::iterator it;
    //Iterate over the whole paths vector
    for (it = paths->begin(); it != paths->end(); it++) {
        // Localize the path pointed by the iterator
        Path *item = *it;
        cout //<< item->id
                << " line:" << item->lineName
                << " station:" << item->station->name
                << " hour:" << item->hour
                << " seq:" << item->sequenceNumber
                << endl;

    }
    cout << endl;
}

/**
 * Cleanup from memory the created instances
**/
void cleanupPaths(list<Path *> *paths) {
//    cout << "Cleaning up " << paths->size() << " paths" << endl;
    // Declaring iterator to a list
    list<Path *>::iterator it;
    //Iterate over the whole paths vector
    for (it = paths->begin(); it != paths->end(); it++) {
        // Localize the path pointed by the iterator
        Path *item = *it;
        delete item;
    }
}

/**
 * Count the total number of subways starting at each sequence 1 in each lines
 * @param paths the list of paths
 * @param line the line to search for
 * @return the count
 */
int countSubwaysForLine(list<Path *> *paths, string line) {

    // Declaring iterator to a list
    list<Path *>::iterator it;

    int count = 0;

    //Iterate over the whole paths vector
    for (it = paths->begin(); it != paths->end(); it++) {
        Path *item = *it;
        if (item->lineName == line && item->sequenceNumber == 1) {
            count++;
        }
    }
    return count;
}
