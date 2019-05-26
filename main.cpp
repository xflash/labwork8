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

    cout << "Line A :" << countForLine("A") <<end;
    cout << "Line B :" << countForLine("B") <<end;
    cout << "Line C :" << countForLine("C") <<end;
    cout << "Line D :" << countForLine("D") <<end;

    cleanupPaths(&paths);
    cleanupStations(&stations);
}


