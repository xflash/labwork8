#include <string>
#include <sstream>
#include <vector>

using namespace std;

#include "StringUtils.h"


/**
 * Split a string into a vector of string based on a delimitor ';'
**/
vector<string> split(string line ) {

    vector <string> cells;
    string cell;
    //create a stream fir the line characters
    stringstream stream_line(line);
    // Read each cell separated by ';' into the streamed line
    while(getline(stream_line, cell, ';')) {
        // add the read cell to the results vector
        cells.push_back(cell);
    }

    return cells;
}
