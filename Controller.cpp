//
// Created by Lenovo on 5/14/2025.
//

#include "header.h"
#include "Controller.h"
#include "Resistor.h"

Controller::Controller()
{
    currentCircuit = new Circuit;
}


void Controller::commandRun()
{

    //==========add_patterns==========
    regex addResistor_pattern(R"(^\s*add\s+R([A-Za-z0-9_]+)\s+([A-Za-z0-9_]+)\s+([A-Za-z0-9_]+)\s+([+-]?\d+(?:\.\d+)?(?:[eE][+-]?\d+)?[a-zA-Z]*)\s*$)");
    regex addCapacitor_pattern(R"(^\s*add\s+C([A-Za-z0-9_]+)\s+([A-Za-z0-9_]+)\s+([A-Za-z0-9_]+)\s+([+-]?\d+(?:\.\d+)?(?:[eE][+-]?\d+)?[a-zA-Z]*)\s*$)");
    regex addInductor_pattern(R"(^\s*add\s+L([A-Za-z0-9_]+)\s+([A-Za-z0-9_]+)\s+([A-Za-z0-9_]+)\s+([+-]?\d+(?:\.\d+)?(?:[eE][+-]?\d+)?[a-zA-Z]*)\s*$)");
    regex addDiode_pattern(R"(^\s*add\s+D([A-Za-z0-9_]+)\s+([A-Za-z0-9_]+)\s+([A-Za-z0-9_]+)\s+([A-Za-z0-9_]+)\s*$)");
    regex addGND_pattern(R"(^\s*add\s+GND\s+([A-Za-z0-9_]+)\s*$)");
    regex addVoltageSource_pattern(R"(^\s*add\s+VoltageSource([A-Za-z0-9_]+)\s+([A-Za-z0-9_]+)\s+([A-Za-z0-9_]+)\s+([+-]?\d+(?:\.\d+)?(?:[eE][+-]?\d+)?[a-zA-Z]*)\s*$)");
    regex addCurrentSource_pattern(R"(^\s*add\s+CurrentSource([A-Za-z0-9_]+)\s+([A-Za-z0-9_]+)\s+([A-Za-z0-9_]+)\s+([+-]?\d+(?:\.\d+)?(?:[eE][+-]?\d+)?[a-zA-Z]*)\s*$)");
    regex addSinusoidalVoltageSource_pattern
            (
                    "^\\s*add\\s+V([A-Za-z0-9_]+)\\s+"
                    "([A-Za-z0-9_]+)\\s+([A-Za-z0-9_]+)\\s+"
                    "SIN\\s*\\(\\s*"
                    "([+-]?\\d+(?:\\.\\d+)?(?:[eE][+-]?\\d+)?)\\s+"
                    "([+-]?\\d+(?:\\.\\d+)?(?:[eE][+-]?\\d+)?)\\s+"
                    "([+-]?\\d+(?:\\.\\d+)?(?:[eE][+-]?\\d+)?)\\s*\\)\\s*$"
            );
    regex addSinusoidalCurrentSource_pattern
            (
                    "^\\s*add\\s+I([A-Za-z0-9_]+)\\s+"
                    "([A-Za-z0-9_]+)\\s+([A-Za-z0-9_]+)\\s+"
                    "SIN\\s*\\(\\s*"
                    "([+-]?\\d+(?:\\.\\d+)?(?:[eE][+-]?\\d+)?)\\s+"
                    "([+-]?\\d+(?:\\.\\d+)?(?:[eE][+-]?\\d+)?)\\s+"
                    "([+-]?\\d+(?:\\.\\d+)?(?:[eE][+-]?\\d+)?)\\s*\\)\\s*$"
            );



    //==========delete_patterns===========
    regex deleteResistor_pattern(R"(^\s*delete\s+R([A-Za-z0-9_]+)\s*$)");


    //==========exit_patterns=========
    regex exit_pattern("^\\s*exit\\s*$");


    smatch match;



    string command;
    while(true)
    {
        getline(cin, command);
        // add resistor
        if (regex_match(command, match, addResistor_pattern))
        {
            addResistor(match[1], match[2], match[3], match[4]);
        }
        //delete resistor
        else if (regex_match(command, match, deleteResistor_pattern))
        {
            deleteResistor(match[1]);
        }





        else if (regex_match(command, match, addCapacitor_pattern))
        {
            addCapacitor(match[1], match[2], match[3], match[4]);
        } else if (regex_match(command, match, addInductor_pattern))
        {
            addInductor(match[1], match[2], match[3], match[4]);
        }
        else if (regex_match(command, exit_pattern))
        {
            break;
        }
        else
        {
            cout<<"syntax error\n";
        }
    }
}


void Controller::addResistor(std::string n, std::string n1, std::string n2, std::string v)
{

    Node* N1 = parseNode(n1);
    Node* N2 = parseNode(n2);
    Resistor* adding= new Resistor("resistor", n, N1, N2, parseValue(v));
    currentCircuit->elements.push_back(adding);
}

void Controller::deleteResistor(const std::string& n) {

}







void Controller::addInductor(string n, string n1, string n2, string v)
{
    Node* N1 = parseNode(n1);
    Node* N2 = parseNode(n2);
    Resistor* adding= new Resistor("inductor", n, N1, N2, parseValue(v));
    currentCircuit->elements.push_back(adding);
}

void Controller::addDiode(string n, string n1, string n2, string v) {
    Node* N1 = parseNode(n1);
    Node* N2 = parseNode(n2);
    Resistor* adding= new Resistor("diode", n, N1, N2, parseValue(v));
    currentCircuit->elements.push_back(adding);
}






long double Controller::parseValue(const std::string& input) {
    size_t i = 0;
    bool foundExponent = false;

    while (i < input.size() &&(
                    isdigit(input[i]) ||
                    input[i] == '.' ||
                    input[i] == '-' ||
                    input[i] == '+' ||
                    input[i] == 'e' ||
                    input[i] == 'E'))
    {
        if (input[i] == 'e' || input[i] == 'E') {
            foundExponent = true;
            ++i;
            if (i < input.size() && (input[i] == '-' || input[i] == '+'))
                ++i;
            while (i < input.size() && std::isdigit(input[i]))
                ++i;
            break;
        }
        ++i;
    }

    string numberPart = input.substr(0, i);
    string unitPart = input.substr(i);

    transform(unitPart.begin(), unitPart.end(), unitPart.begin(), ::tolower);

    long double value = std::stold(numberPart);

    if (!unitPart.empty()) {
        if        (unitPart == "k") value *= 1e3;
        else if (unitPart == "meg") value *= 1e6;
        else if (unitPart == "g"  ) value *= 1e9;
        else if (unitPart == "t" ) value *= 1e12;
        else if (unitPart == "m" ) value *= 1e-3;
        else if (unitPart == "u" ) value *= 1e-6;
        else if (unitPart == "n" ) value *= 1e-9;
        else if (unitPart == "p") value *= 1e-12;
    }

    return value;
}

Node *Controller::parseNode(const string& n, bool jf)
{
    for(auto x : currentCircuit->nodes)
    {
        if( n == x->name)
            return x;
        else if (!jf)
        {
            Node* N = new Node;
            return N;
        }
    }
    return nullptr;
}











Controller::~Controller()
{
    for(auto x : currentCircuit->elements)
        delete[] x;

    for (auto x : currentCircuit->nodes)
        delete[] x;
//    cout<<currentCircuit;
    delete currentCircuit;
}

Element *Controller::findElement(const string& t, const string& n)
{
    for (auto x : currentCircuit->elements)
    {
        if (x->getType() == t && x->getName() == n)
        {
            return x;
        }
    }
    return nullptr;
}

//            cout<<match[1]<<"===="<< match[2]<<"====="<< match[3]<<"====="<< match[4]<<endl;
