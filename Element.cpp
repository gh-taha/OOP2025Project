//
// Created by Lenovo on 5/13/2025.
//

#include "Element.h"

#include <utility>

Element::Element(std::string t, std::string n, Node *n1, Node *n2, long double v)
{
    type = std::move(t);
    name = std::move(n);
    positive = n1;
    negative = n2;
    value = v;

    Controller::setElementAtNodes(this,n1,n2);

}

string Element::getType()
{
    return type;
}

string Element::getName()
{
    return name;
}

Element::~Element()
{


}

// ===============Resistor===============

unsigned Resistor::ID = 1;

Resistor::Resistor(string t, string n, Node *n1, Node *n2, long double v) : Element(t, n, n1, n2, v) {}

//=================Capacitor=============

Capacitor::Capacitor(string t, string n, Node *n1, Node *n2, long double v) : Element(t, n, n1, n2, v) {}


//===============Inductor=================

Inductor::Inductor(string t, string n, Node *n1, Node *n2, long double v) : Element(t, n, n1, n2, v) {}

//===================VoltageSource=============

VoltageSource::VoltageSource(std::string t, std::string n, Node *n1, Node *n2, long double v) : Element(t, n, n1, n2, v) {}

//==================currentSource===============

CurrentSource::CurrentSource(std::string t, std::string n, Node *n1, Node *n2, long double v) : Element(t, n, n1, n2, v) {}
