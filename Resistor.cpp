//
// Created by Lenovo on 6/5/2025.
//

#include "Resistor.h"

unsigned Resistor::ID = 1;

Resistor::Resistor(std::string t, std::string n, Node *n1, Node *n2, long double v) : Element(t, n, n1, n2, v) {}
