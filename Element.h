//
// Created by Lenovo on 5/13/2025.
//

#ifndef PROJECTCODE_ELEMENT_H
#define PROJECTCODE_ELEMENT_H
#include "header.h"
#include "Node.h"
class Node;


class Element{
protected:


    std::string type;
    std::string name;
    Node* positive;
    Node* negative;
    long double value;

public:
    Element(std::string t, std::string n, Node *n1, Node *n2, long double v);

    string getName();
    string getType();

    ~Element();

};


#endif //PROJECTCODE_ELEMENT_H
