//
// Created by maxy2 on 4/25/2026.
//

#include "StomachLang.h"
#include <iostream>


Memory StomachLang::memory(10);

CPU StomachLang::cpu(&StomachLang::memory);

void StomachLang::poop(Variable var) {
    std::cout << var.getValue();
}

void StomachLang::memoryToType(Variable var) {
    // var.getType()
    //"Bool"    "String"    "Int"
    if (var.getType() == "Int") {
        std::cout << "\n" << std::stoi(var.getValue());
    }
    else if (var.getType() == "Bool") {
        std::cout << "\n" << (var.getValue() == "1" ? "true" : "false");// ternary operator
    }
    else if (var.getType() == "String") {
        std::cout << "\n" << var.getValue();
    }
    else {
        std::cout << "\n[UNKNOWN TYPE]";
    }
}