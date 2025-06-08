cmake_minimum_required(VERSION 3.30)
project(OOP2025Project)

set(CMAKE_CXX_STANDARD 20)

add_executable(OOP2025Project
        header.h
        main.cpp
        Node.h
        Node.cpp
        Element.h
        Element.cpp
        Resistor.h
        Resistor.cpp
        Capacitor.h
        Capacitor.cpp
        Inductor.h
        Inductor.cpp
        VoltageSource.h
        VoltageSource.cpp
        CurrentSource.h
        CurrentSource.cpp
        Circuit.h
        Circuit.cpp
        Controller.h
        Controller.cpp


        CircuitException.h
        CircuitException.cpp

        ElementException.h
        ElementException.cpp
)
