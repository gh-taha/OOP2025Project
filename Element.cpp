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
