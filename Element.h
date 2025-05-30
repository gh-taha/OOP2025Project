//
// Created by Lenovo on 5/13/2025.
//

#ifndef PROJECTCODE_ELEMENT_H
#define PROJECTCODE_ELEMENT_H
#include "header.h"
#include "Node.h"


class Element{
protected:

    std::string type;
    std::string name;
    Node* positive;
    Node* negative;
    double value;

public:
    Element(std::string t, std::string n, Node* P, Node* N, double v);

    virtual void analisis();

    ~Element();
};


#endif //PROJECTCODE_ELEMENT_H
