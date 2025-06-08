//
// Created by Lenovo on 6/8/2025.
//

#ifndef OOP2025PROJECT_CAPACITOR_H
#define OOP2025PROJECT_CAPACITOR_H
#include "header.h"
class Element;

class Capacitor : public Element{

public:
    Capacitor(std::string t, std::string n, Node *n1, Node *n2, long double v);

};


#endif //OOP2025PROJECT_CAPACITOR_H
