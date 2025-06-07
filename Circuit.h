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


public:
    std::string name;
    unsigned ID;
    std::vector<Node*> nodes;
    std::vector<Element*> elements;
    Circuit(string n = "temp");


    static unsigned circuitID;

    void analysCircuit();
    void saveCircuit();
    static void readCircuit();
    static void printCircuit();



    ~Circuit();
};


#endif //PROJECTCODE_CIRCUIT_H
