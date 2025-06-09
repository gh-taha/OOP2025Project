//
// Created by Lenovo on 5/14/2025.
//

#include "header.h"
#include "regexs.h"
#include "Controller.h"

#include "ElementException.h"

Controller::Controller()
{
    currentCircuit = new Circuit;
//    cout<<currentCircuit;
}


void Controller::commandRun()
{


    string command;
    while(true) {

        getline(cin, command);

        smatch match;

        try
        {
            // add Element
            if(regex_match(command, match, addSimple_pattern))
            {
                addElement(match[1], match[2], match[3], match[4]);
            }








            // add resistor
            else if (regex_match(command, match, addResistor_pattern))
            {
                addResistor(match[1], match[2], match[3], match[4]);
            }
            //delete resistor
            else if (regex_match(command, match, deleteResistor_pattern))
            {
                deleteResistor(match[1]);
            }

            // add capacitor
            else if (regex_match(command, match, addCapacitor_pattern))
            {
                addCapacitor(match[1], match[2], match[3], match[4]);
            }
            // delete capacitor
            else if(regex_match(command, match, deleteCapacitor_pattern))
            {
                deleteCapacitor(match[1]);
            }

            // add Inductor
            else if (regex_match(command, match, addInductor_pattern))
            {
                addInductor(match[1], match[2], match[3], match[4]);
            }
            // delete inductor
            else if (regex_match(command, match, deleteInductor_pattern))
            {
                deleteInductor(match[1]);
            }

            // add voltage source
            else if (regex_match(command, match, addVoltageSource_pattern))
            {
                addVoltageSource(match[1], match[2], match[3], match[4]);
            }
            // delete VoltageSource
            else if (regex_match(command, match, deleteVoltageSource_pattern))
            {
                deleteVoltageSource(match[1]);
            }

            // add Current Source
            else if (regex_match(command, match, addCurrentSource_pattern))
            {
                addCurrentSource(match[1], match[2], match[3], match[4]);
            }
            //delete Courrent source
            else if (regex_match(command, match, deleteCurrentSource_pattern))
            {
                deleteCurrentSource( match[1]);
            }
            else if (regex_match(command, match, showNodes_pattern))
            {
                showNodes();
            }
            else if (regex_match(command, exit_pattern))
            {
                break;
            }
            else if (command.find("t") != string::npos)
            {
                //cout<<currentCircuit->elements[currentCircuit->elements.size()-1]->getName()<<endl;
//                cout<<currentCircuit<<"\n";
            }
            else {
                cout << "syntax error\n"<<command<<endl;
            }
        }
        catch (ValueException& e)
        {
            cerr << e.what()<<endl;
        }
        catch (const ElementException& e)
        {
            cerr << e.what()<<endl;
        }

    }

}


void Controller::addResistor(const std::string& n, const std::string& n1, const std::string& n2, const std::string& v)
{
    long double V = parseValue(v);
    if(V <= 0)
        throw ValueException("Resistance cannot be zero or negative");
    if(isElement("resistor", n))
        throw ElementException("Resistor " + n + " already exists in the circuit");

    Node *N1 = parseNode(n1);
//    cout<<N1<<"\n";
    Node *N2 = parseNode(n2);
//    cout<<N2<<"\n";

    auto *add = new Resistor("resistor", n, N1, N2, V);
    currentCircuit->elements.push_back(add);

}

void Controller::deleteResistor(const std::string& n)
{
    if (!isElement("resistor", n))
    {
        throw ElementException("Cannot delete resistor; component not found");
    }
    else
    {
        int i;
        for (i = 0; i < currentCircuit->elements.size(); ++i)
        {
            if (currentCircuit->elements[i]->getType() == "resistor" && currentCircuit->elements[i]->getName() == n)
            {
                delete currentCircuit->elements[i];
                currentCircuit->elements.erase(currentCircuit->elements.begin() + i);
            }
        }
    }
}


void Controller::addCapacitor(const string& n, const string& n1, const string& n2, const string& v)
{
    long double V = parseValue(v);
    if(V <= 0)
        throw ValueException("Capacitance cannot be zero or negative");
    if(isElement("capacitor", n))
        throw ElementException("Capacitor " + n + " already exists in the circuit");

    Node *N1 = parseNode(n1);
//    cout<<N1<<"\n";
    Node *N2 = parseNode(n2);
//    cout<<N2<<"\n";

    auto *add = new Capacitor("capacitor", n, N1, N2, V);
    currentCircuit->elements.push_back(add);

}

void Controller::deleteCapacitor(const string& n)
{
    if (!isElement("capacitor", n))
    {
        throw ElementException("Cannot delete capacitor; component not found");
    }
    else
    {
        int i;
        for (i = 0; i < currentCircuit->elements.size(); ++i)
        {
            if (currentCircuit->elements[i]->getType() == "capacitor" && currentCircuit->elements[i]->getName() == n)
            {
                delete currentCircuit->elements[i];
                currentCircuit->elements.erase(currentCircuit->elements.begin() + i);
            }
        }
    }
}


void Controller::addInductor(const string& n, const string& n1, const string& n2, const string& v)
{
    long double V = parseValue(v);
    if(V <= 0)
        throw ValueException("Inductance cannot be zero or negative");
    if(isElement("inductor", n))
        throw ElementException("Inductor " + n + " already exists in the circuit");

    Node *N1 = parseNode(n1);
//    cout<<N1<<"\n";
    Node *N2 = parseNode(n2);
//    cout<<N2<<"\n";

    auto *add = new Inductor("inductor", n, N1, N2, V);
    currentCircuit->elements.push_back(add);
}

void Controller::deleteInductor(const string &n)
{
    if (!isElement("Inductor", n))
    {
        throw ElementException("Cannot delete inductor; component not found");
    }
    else
    {
        int i;
        for (i = 0; i < currentCircuit->elements.size(); ++i)
        {
            if (currentCircuit->elements[i]->getType() == "inductor" && currentCircuit->elements[i]->getName() == n)
            {
                delete currentCircuit->elements[i];
                currentCircuit->elements.erase(currentCircuit->elements.begin() + i);
            }
        }
    }
}


void Controller::addVoltageSource(const string &n, const string &n1, const string &n2, const string &v)
{
    long double V = parseValue(v);

    if(isElement("VoltageSource", n))
        throw ElementException("VoltageSource " + n + " already exists in the circuit");

    Node *N1 = parseNode(n1);
//    cout<<N1<<"\n";
    Node *N2 = parseNode(n2);
//    cout<<N2<<"\n";

    auto *add = new VoltageSource("VoltageSource", n, N1, N2, V);
    currentCircuit->elements.push_back(add);
}

void Controller::deleteVoltageSource(const string &n)
{
    if (!isElement("VoltageSource", n))
    {
        throw ElementException("Cannot delete voltage source; component not found");
    }
    else
    {
        int i;
        for (i = 0; i < currentCircuit->elements.size(); ++i)
        {
            if (currentCircuit->elements[i]->getType() == "VoltageSource" && currentCircuit->elements[i]->getName() == n)
            {
                delete currentCircuit->elements[i];
                currentCircuit->elements.erase(currentCircuit->elements.begin() + i);
            }
        }
    }
}

void Controller::addCurrentSource(const string &n, const string &n1, const string &n2, const string &v)
{
    long double V = parseValue(v);
   if(isElement("CurrentSource", n))
        throw ElementException("CurrentSource " + n + " already exists in the circuit");

    Node *N1 = parseNode(n1);
//    cout<<N1<<"\n";
    Node *N2 = parseNode(n2);
//    cout<<N2<<"\n";

    auto *add = new CurrentSource("CurrentSource", n, N1, N2, V);
    currentCircuit->elements.push_back(add);
}

void Controller::deleteCurrentSource(const string &n)
{
    if (!isElement("CurrentSource", n))
    {
        throw ElementException("Cannot delete current source; component not found");
    }
    else
    {
        int i;
        for (i = 0; i < currentCircuit->elements.size(); ++i)
        {
            if (currentCircuit->elements[i]->getType() == "CurrentSource" && currentCircuit->elements[i]->getName() == n)
            {
                delete currentCircuit->elements[i];
                currentCircuit->elements.erase(currentCircuit->elements.begin() + i);
            }
        }
    }
}



void Controller::showNodes()
{
    cout<<"Available nodes:"<<endl;
    if (currentCircuit->nodes.empty())
    {
        cout<<"nodes empty"<<endl;
    }
    else
    {
        for(auto x : currentCircuit->nodes)
            cout<< x->getName()<<", ";
        cout<<endl;

    }
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
        if( n == x->getName())
            return x;
    }
    if (!jf)
    {
        Node* N = new Node(n);
        currentCircuit->nodes.push_back(N);
        return N;
    }
    return nullptr;
}













bool Controller::isElement(const string &t, const string &n)
{
    for (auto x : currentCircuit->elements)
    {
        if(x->getType() == t && x->getName() == n)
            return true;
    }
    return false;
}

Element *Controller::findElement(const string& t, const string& n) const
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
Controller::~Controller()
{
    for(auto x : currentCircuit->elements)
        delete x;

    for (auto x : currentCircuit->nodes)
        delete x;
//    cout<<currentCircuit;
    delete &currentCircuit;
}

void Controller::setElementAtNodes(Element *e, Node *n1, Node *n2)
{
    n1->setElement(e, true);
    n2->setElement(e, false);
}

void Controller::addElement(const string &tan, const string &n1, const string &n2, const string& v)
{
    smatch m;

    Node *N1 = parseNode(n1);
    Node *N2 = parseNode(n2);
    // R
    if (regex_match(tan, m, addR_pattern))
    {
        string n = m[1];
        string t = "R";
        long double V = parseValue(v);
        if(V <= 0)
            throw ValueException("Resistance cannot be zero or negative");
        if(currentCircuit->isElement(t, n))
            throw ElementException("Resistor " + n + " already exists in the circuit");


        auto *add = new Resistor(t, n, N1, N2, V);
        currentCircuit->elements.push_back(add);
        setElementAtNodes(add,N1,N2);

        cout<<"Resistor "<<n<<" added successfully"<<endl;

    }
    // C
    else if (regex_match(tan,m, addC_pattern))
    {
        string n = m[1];
        string t = "C";
        long double V = parseValue(v);
        if(V <= 0)
            throw ValueException("Capacitance cannot be zero or negative");
        if(currentCircuit->isElement(t, n))
            throw ElementException("Capacitor " + n + " already exists in the circuit");


        auto *add = new Capacitor(t, n, N1, N2, V);
        currentCircuit->elements.push_back(add);
        setElementAtNodes(add,N1,N2);

        cout<<"Capacitor "<<n<<" added successfully"<<endl;

    }
    // I
    else if(regex_match(tan, m, addI_pattern))
    {
        string n = m[1];
        string t = "I";
        long double V = parseValue(v);
        if(V <= 0)
            throw ValueException("Inductance cannot be zero or negative");
        if(currentCircuit->isElement(t, n))
            throw ElementException("Inductor " + n + " already exists in the circuit");


        auto *add = new Inductor(t, n, N1, N2, V);
        currentCircuit->elements.push_back(add);
        setElementAtNodes(add,N1,N2);

        cout<<"Inductor "<<n<<" added successfully"<<endl;

    }
    // VS
    else if(regex_match(tan, m, addVS_pattern))
    {
        string n = m[1];
        string t = "VoltageSource";
        long double V = parseValue(v);

        if(currentCircuit->isElement(t, n))
            throw ElementException("VoltageSource " + n + " already exists in the circuit");


        auto *add = new VoltageSource(t, n, N1, N2, V);
        currentCircuit->elements.push_back(add);
        setElementAtNodes(add,N1,N2);

        cout<<"VoltageSource "<<n<<" added successfully"<<endl;


    }
    // CS
    else if (regex_match(tan, m, addCS_pattern))
    {
        string n = m[1];
        string t = "CurrentSource";
        long double V = parseValue(v);

        if(currentCircuit->isElement(t, n))
            throw ElementException("CurrentSource " + n + " already exists in the circuit");


        auto *add = new CurrentSource(t, n, N1, N2, V);
        currentCircuit->elements.push_back(add);
        setElementAtNodes(add,N1,N2);

        cout<<"CurrentSource "<<n<<" added successfully"<<endl;

    }
    else
    {
        cerr<<"Error: Element "<<tan<<" not found in library"<<endl;
    }

}









