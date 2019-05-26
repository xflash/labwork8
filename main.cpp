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
int main() {

    vector<Station *> stations = vector<Station *>();

    readStations("data/stations.csv", &stations);

    displayStations(&stations);


    list<Path *> paths = list<Path *>();

    readPaths("data/path.csv", &paths, &stations);

    displayPaths(&paths);

    cout << "Line A : " << countSubwaysForLine(&paths, "A") <<endl;
    cout << "Line B : " << countSubwaysForLine(&paths, "B") <<endl;
    cout << "Line C : " << countSubwaysForLine(&paths, "C") <<endl;
    cout << "Line D : " << countSubwaysForLine(&paths, "D") <<endl;

    cleanupPaths(&paths);
    cleanupStations(&stations);
}


