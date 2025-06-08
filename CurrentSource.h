//
// Created by Lenovo on 5/30/2025.
//

#ifndef OOP2025PROJECT_CURRENTSOURCE_H
#define OOP2025PROJECT_CURRENTSOURCE_H

#include "header.h"
#include "Element.h"

class Element;

class CurrentSource : public Element{
public:
    CurrentSource(std::string t, std::string n, Node *n1, Node *n2, long double v) : Element(t, n, n1, n2, v) {}


};


#endif //OOP2025PROJECT_CURRENTSOURCE_H
