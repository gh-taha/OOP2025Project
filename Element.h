//
// Created by Lenovo on 5/13/2025.
//

#ifndef PROJECTCODE_ELEMENT_H
#define PROJECTCODE_ELEMENT_H
#include "header.h"
#include "Node.h"
class Node;

// ===============Element===============
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



// ==============Resistor==============
class Resistor : public Element{

public:
    static unsigned ID;

    Resistor(std::string t, std::string n, Node *n1, Node *n2, long double v);
};

// ================Capacitor==============
class Capacitor : public Element{

public:
    Capacitor(std::string t, std::string n, Node *n1, Node *n2, long double v);

};
// ==============Inductor====================
class Inductor : public Element{

public:
    Inductor(std::string t, std::string n, Node *n1, Node *n2, long double v);

};

// ============VoltageSource=================

class VoltageSource : public Element{

public:
    VoltageSource(std::string t, std::string n, Node *n1, Node *n2, long double v);

};

// ===========CurrentSource=================


class CurrentSource : public Element{
public:
    CurrentSource(std::string t, std::string n, Node *n1, Node *n2, long double v);

};




#endif //PROJECTCODE_ELEMENT_H
