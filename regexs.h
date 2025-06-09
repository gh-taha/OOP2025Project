//
// Created by Lenovo on 6/9/2025.
//

#ifndef OOP2025PROJECT_REGEXS_H
#define OOP2025PROJECT_REGEXS_H

#include "header.h"

//==========add_patterns==========
regex addResistor_pattern(R"(^\s*add\s+R([A-Za-z0-9_]+)\s+N([A-Za-z0-9_]+)\s+N([A-Za-z0-9_]+)\s+([+-]?\d+(?:\.\d+)?(?:[eE][+-]?\d+)?[a-zA-Z]*)\s*$)");
regex addCapacitor_pattern(R"(^\s*add\s+C([A-Za-z0-9_]+)\s+N([A-Za-z0-9_]+)\s+N([A-Za-z0-9_]+)\s+([+-]?\d+(?:\.\d+)?(?:[eE][+-]?\d+)?[a-zA-Z]*)\s*$)");
regex addInductor_pattern(R"(^\s*add\s+L([A-Za-z0-9_]+)\s+N([A-Za-z0-9_]+)\s+N([A-Za-z0-9_]+)\s+([+-]?\d+(?:\.\d+)?(?:[eE][+-]?\d+)?[a-zA-Z]*)\s*$)");
regex addDiode_pattern(R"(^\s*add\s+D([A-Za-z0-9_]+)\s+N([A-Za-z0-9_]+)\s+N([A-Za-z0-9_]+)\s+([A-Za-z0-9_]+)\s*$)");
regex addGND_pattern(R"(^\s*add\s+GND\s+N([A-Za-z0-9_]+)\s*$)");
regex addVoltageSource_pattern(R"(^\s*add\s+VoltageSource([A-Za-z0-9_]+)\s+N([A-Za-z0-9_]+)\s+N([A-Za-z0-9_]+)\s+([+-]?\d+(?:\.\d+)?(?:[eE][+-]?\d+)?[a-zA-Z]*)\s*$)");
regex addCurrentSource_pattern(R"(^\s*add\s+CurrentSource([A-Za-z0-9_]+)\s+N([A-Za-z0-9_]+)\s+N([A-Za-z0-9_]+)\s+([+-]?\d+(?:\.\d+)?(?:[eE][+-]?\d+)?[a-zA-Z]*)\s*$)");
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
regex deleteCapacitor_pattern(R"(^\s*delete\s+C([A-Za-z0-9_]+)\s*$)");
regex deleteInductor_pattern (R"(^\s*delete\s+L([A-Za-z0-9_]+)\s*$)");
regex deleteVoltageSource_pattern (R"(^\s*delete\s+VoltageSource([A-Za-z0-9_]+)\s*$)");
regex deleteCurrentSource_pattern (R"(^\s*delete\s+CurrentSource([A-Za-z0-9_]+)\s*$)");

//========== ==========
regex showNodes_pattern(R"(^\s*\.nodes\s*$)");


//==========exit_patterns=========
regex exit_pattern("^\\s*exit\\s*$");


smatch match;


#endif //OOP2025PROJECT_REGEXS_H
