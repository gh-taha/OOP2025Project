//
// Created by Lenovo on 5/14/2025.
//

#ifndef PROJECTCODE_CONTROLLER_H
#define PROJECTCODE_CONTROLLER_H

class Circuit;


class Controller{

public:
    Controller();
    Circuit* currentCircuit;


    void commandRun();

    void addResistor(string n, string n1, string n2, string v);
    void deleteResistor(const string& n);


    void addCapacitor(string n, string n1, string n2, string v);
    void addInductor(string n, string n1, string n2, string v);
    void addDiode(string n, string n1, string n2, string v);


    Element* findElement(const string& t, const string& n);


    Node* parseNode(const string& n, bool jf = false);

    long double parseValue(const std::string& input);



    ~Controller();
};



#endif //PROJECTCODE_CONTROLLER_H
