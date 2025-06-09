//
// Created by Lenovo on 5/14/2025.
//

#include "Circuit.h"
#include "header.h"


Circuit::Circuit(const string& n)
{
    name = "circuit" + static_cast<char >(circuitID+ 48);
    ID = circuitID++;

}
unsigned Circuit::circuitID = 0;

Circuit::~Circuit()
{
    for(auto x : nodes)
    {
        delete[] x;
    }
    for (auto x : elements)
    {
        delete[] x;
    }

}
