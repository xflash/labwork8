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
#include "Path.h"
#include "StringUtils.h"


/***********************************************/

string dumpStation(Station *station) {
    stringstream ss;
    if (station != NULL) {
        ss << station->name << "(" << station->id << ")";
    } else {
        ss << "NONE";
    }
    return ss.str();
}

int main() {

    vector<Station *> stations = vector<Station *>();

    readStations("data/stations.csv", &stations);

    displayStations(&stations);


    list<Path *> paths = list<Path *>();

    readPaths("data/path.csv", &paths, &stations);

    displayPaths(&paths);

    cout << "Line A : " << countSubwaysForLine(&paths, "A") << endl;
    cout << "Line B : " << countSubwaysForLine(&paths, "B") << endl;
    cout << "Line C : " << countSubwaysForLine(&paths, "C") << endl;
    cout << "Line D : " << countSubwaysForLine(&paths, "D") << endl;


    string ask;
    cout << "Please type a line name A, B, C or D : " << endl;
    getline(cin, ask);
    if (ask != "A" && ask != "B" && ask != "C" && ask != "D") {
        cerr << "Unknown line name" << endl;
        exit(-1);
    }
    string line = ask;

    cout << "Please type an hour HH:MM:SS : " << endl;
    getline(cin, ask);
    vector<string> parts = split(ask, ':');
    if (parts.size() != 3) {
        cerr << "Unknown hour format. Should be HH:MM:SS" << endl;
        exit(-1);
    }


    //WARNING the findStation4LineAt implementation really crappy due to the content of the CSV ???
    //TODO To be check
    vector<Station *> result = findStation4LineAt(&paths, line, strToHour(ask));

    cout << "On line " << line << " at " << ask << " the subway location ";
    if (result.size() == 1) {
        cout << "is at station " << dumpStation(result.at(0));
    } else if (result.size() == 2) {
        Station *previous = result.at(0);
        Station *next = result.at(1);
        if (previous == NULL || next == NULL) {
            cout << "is unknown";
        } else {
            cout << "is between stations " << dumpStation(previous) << " and " << dumpStation(next);
        }
    } else {
        cout << " is unknown ";
    }
    cout << endl;

    cleanupPaths(&paths);
    cleanupStations(&stations);
}





