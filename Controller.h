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

    void addResistor(const string& n, const string& n1, const string& n2, const string& v);
    void deleteResistor(const string& n);

    void addCapacitor(const string& n, const string& n1, const string& n2, const string& v);
    void deleteCapacitor(const string& n);

    void addInductor(const string& n, const string& n1, const string& n2, const string& v);
    void deleteInductor(const string& n);

    void addVoltageSource(const string& n, const string& n1, const string& n2, const string& v);
    void deleteVoltageSource(const string& n);

    void addCurrentSource(const string& n, const string& n1, const string& n2, const string& v);
    void deleteCurrentSource(const string& n);

    void showNodes();

    bool isElement(const string& t, const string& n);
    Element* findElement(const string& t, const string& n);


    Node* parseNode(const string& n, bool jf = false);

    long double parseValue(const std::string& input);


    static void setElementAtNodes(Element* e, Node* n1, Node* n2);



    ~Controller();
};



#endif //PROJECTCODE_CONTROLLER_H
