//
// Created by Gawayn Coqueugniot on 2019-05-16.
//

#ifndef LABWORK8_PATH_H
#define LABWORK8_PATH_H

#include <string>

struct Path {
    std::string id;
    std::string lineName;
    Station *station;
    std::string hour;
    int sequenceNumber;
};

#endif //LABWORK8_PATH_H
