//
// Created by Lenovo on 5/14/2025.
//

#ifndef PROJECTCODE_CIRCUIT_H
#define PROJECTCODE_CIRCUIT_H
#include <bits/stdc++.h>
using namespace std;

class Element;
class Node;

class Circuit {
protected:
    std::string name;
    unsigned ID;


public:
    std::vector<Node*> nodes;
    std::vector<Element*> elements;

    vector<Element*> getElements();
    vector<Node*> getNodes();
    Circuit(const string& n = "temp");
    bool isElement(const string& t, const string& n);


    static unsigned circuitID;

    void analysCircuit();
    void saveCircuit();
    static void readCircuit();
    static void printCircuit();



    ~Circuit();
};


#endif //PROJECTCODE_CIRCUIT_H
