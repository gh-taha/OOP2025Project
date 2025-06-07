//
// Created by Lenovo on 6/7/2025.
//

#ifndef OOP2025PROJECT_CIRCUITEXCEPTION_H
#define OOP2025PROJECT_CIRCUITEXCEPTION_H
#include "header.h"

class CircuitException : public std::exception{
protected:
    string message;

public:
    explicit CircuitException(const string& msg) : message(msg){}

    const char* what() const noexcept override {
        return message.c_str();
    }
};


#endif //OOP2025PROJECT_CIRCUITEXCEPTION_H
