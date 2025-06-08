//
// Created by Lenovo on 5/14/2025.
//

#ifndef PROJECTCODE_NODE_H
#define PROJECTCODE_NODE_H
#include "header.h"

class Node{

private:
//    vector<Element*> N1s;
//    vector<Element*> N2s;

    unsigned ID;

public:
    Node(const string& n);

    static unsigned int nodeID;

    std::string name;
};


#endif //PROJECTCODE_NODE_H
