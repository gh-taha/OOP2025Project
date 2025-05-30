//
// Created by Lenovo on 5/14/2025.
//

#ifndef PROJECTCODE_CIRCUIT_H
#define PROJECTCODE_CIRCUIT_H
#include "header.h"
#include "Element.h"
#include "Node.h"


class Circuit {
protected:

    std::string name;
    unsigned ID;
    std::vector<Node*> nodes;
    std::vector<Element*> elements;
public:
    static unsigned circuitID;


};


#endif //PROJECTCODE_CIRCUIT_H
