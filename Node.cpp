//
// Created by Lenovo on 5/14/2025.
//

#include "Node.h"

Node::Node(const string &n) {
    ID = nodeID++;
    name = n;


}

unsigned Node::nodeID = 1;

string Node::getName() {
    return name;
}

void Node::setElement(Element *e, bool pn)
{
    if(pn)
    {
        N1s.push_back(e);
    }
    else
    {
        N2s.push_back(e);
    }

}

