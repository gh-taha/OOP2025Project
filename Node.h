//
// Created by Lenovo on 5/14/2025.
//

#ifndef PROJECTCODE_NODE_H
#define PROJECTCODE_NODE_H
#include "header.h"
class Element;

class Node{

private:

    std::string name;

    vector<Element*> N1s;
    vector<Element*> N2s;

    unsigned ID;

public:
    Node(const string& n);

    static unsigned int nodeID;

    void setElement(Element* e, bool pn);

    string getName();

};


#endif //PROJECTCODE_NODE_H
