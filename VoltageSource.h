//
// Created by Lenovo on 5/30/2025.
//

#ifndef OOP2025PROJECT_VOLTAGESOURCE_H
#define OOP2025PROJECT_VOLTAGESOURCE_H

#include "header.h"
#include "Element.h"

class Element;

class VoltageSource : public Element{

public:
    VoltageSource(std::string t, std::string n, Node *n1, Node *n2, long double v);

};


#endif //OOP2025PROJECT_VOLTAGESOURCE_H
