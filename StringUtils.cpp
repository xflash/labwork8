#include <string>
#include <sstream>
#include <vector>

using namespace std;

#include "StringUtils.h"


/**
 * Split a string into a vector of string based on a given delimitor
**/
vector<string> split(string line, char delim) {

    vector <string> cells;
    string cell;
    //create a stream fir the line characters
    stringstream stream_line(line);
    // Read each cell separated by delim into the streamed line
    while(getline(stream_line, cell, delim)) {
        // add the read cell to the results vector
        cells.push_back(cell);
    }

    return cells;
}
