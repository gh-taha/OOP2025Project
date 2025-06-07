//
// Created by Lenovo on 6/5/2025.
//

#ifndef OOP2025PROJECT_RESISTOR_H
#define OOP2025PROJECT_RESISTOR_H
#include "Element.h"
class Element;

class Resistor : public Element{

public:
    static unsigned ID;

    Resistor(std::string t, std::string n, Node *n1, Node *n2, long double v);
};


#endif //OOP2025PROJECT_RESISTOR_H
