//
// Created by Lenovo on 6/8/2025.
//

#ifndef OOP2025PROJECT_INDUCTOR_H
#define OOP2025PROJECT_INDUCTOR_H
#include "header.h"
#include "Element.h"
class Element;
class Inductor : public Element{

public:
    Inductor(std::string t, std::string n, Node *n1, Node *n2, long double v);

};


#endif //OOP2025PROJECT_INDUCTOR_H
