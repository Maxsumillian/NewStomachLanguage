//
// Created by maxy2 on 4/25/2026.
//

#include "CPU.h"

#include <iostream>
#include <ostream>

#include "StomachLang.h"
#include "Data.h"


CPU::CPU(Memory* mem)
    : memory(mem), accumulator() {}


// =========================
// Accumulator access
// =========================

std::string CPU::getAccumulatorDataType() {
    return accumulator.type;
}

std::string CPU::getAccumulatorDataValue() {
    return accumulator.value;
}


// =========================
// Memory operations
// =========================

void CPU::load(int address) {
    accumulator = memory->read(address);
}

void CPU::store(int address) {
    memory->write(address, accumulator);
}


// =========================
// Add operations
// =========================

void CPU::add(Data d) {
    accumulator.type = d.type;
    accumulator.value = d.value;
}

void CPU::add(int address) {
    accumulator = memory->read(address);
}

void CPU::add(int address, int address2) {
    Data a = memory->read(address);
    Data b = memory->read(address2);

    if (a.type != b.type) {
        std::cout << "\n\033[31mError: Cannot add "
                  << a.type << " & " << b.type << "\033[0m";
        return;
    }

    if (a.type == "INT") {
        accumulator.value = std::to_string(
            std::stoi(a.value) + std::stoi(b.value)
        );
    } else {
        accumulator.value = a.value + b.value;
    }
}


// =========================
// Arithmetic operations
// (templated system below)
// does not include add beacuse add has a special case with stings and ints
// =========================

void CPU::sub(int address1, int address2) {
    operation(address1, address2, [](int x, int y) {
        return x - y;
    },"subtract");
}

void CPU::multiply(int address1, int address2) {
    operation(address1, address2, [](int x, int y) {
        return x * y;
    },"multiply");
}

void CPU::divide(int address1, int address2) {
    operation(address1, address2, [](int x, int y) {
        return x / y;
    },"divide");
}

void CPU::modulo(int address1, int address2) {
    operation(address1, address2, [](int x, int y)  {
        return x % y;
    },"modulo");
}


// =========================
// Generic operation engine
// =========================

template<typename T>
void CPU::operation(int address, int address2, T op, std::string opName) {
    Data a = memory->read(address);
    Data b = memory->read(address2);

    if (a.type != "INT" || b.type != "INT") {
        std::cout << "\n\033[31mError: Cannot " << opName << " "
                  << a.type << " & " << b.type << "\033[0m";
        return;
    }
    if (a.type == "INT" && b.type == "INT") {
        int x = std::stoi(a.value);
        int y = std::stoi(b.value);

        int result = op(x, y);

        accumulator.type = "INT";
        accumulator.value = std::to_string(result);
    }

}
// =========================
// Compare operator
// =========================


void CPU::compare(int address, int address2, std::string op){
    Data a = memory->read(address);
    Data b = memory->read(address2);
    if (op == "==") {
        accumulator.value = (a.value == b.value ? "true" : "false");
    }
    if (op == "!=") {
        accumulator.value = (a.value != b.value ? "true" : "false");
    }
    if (a.type == "INT" && b.type == "INT") {
        if (op == ">") {
            accumulator.value = (a.value > b.value ? "true" : "false");
        }
        if (op == "<") {
            accumulator.value = (a.value < b.value ? "true" : "false");
        }
        if (op == ">=") {
            accumulator.value = (a.value >= b.value ? "true" : "false");
        }
        if (op == "<=") {
            accumulator.value = (a.value <= b.value ? "true" : "false");
        }
    }
    if (a.type == "Bool" && b.type == "Bool") {
        if (op == "&&") {
            accumulator.value = ((a.value == "true") && b.value == "true" ? "true" : "false");
        }
        if (op == "||") {
            accumulator.value = ((a.value == "true" )|| b.value == "true" ? "true" : "false");
        }
    }
}

void CPU::compare(bool b, int address2, std::string op) {
    Data a = memory->read(address2);
    if (a.type == "Bool") {
        if (op == "==") {
            accumulator.value = ((a.value == (b ? "true" : "false")) ? "true" : "false");//nested ternary operators beacuse alot of value changes...
        }// set accumularot value to either true or false if (value is the same value as b) (b is either true or false by string beacuse of ternary operator)
        if (op == "!=") {
            accumulator.value = ((a.value != (b ? "true" : "false")) ? "true" : "false");
        }
        if (op == "&&") {
            accumulator.value = ((a.value == "true") && b ? "true" : "false");
        }
        if (op == "||") {
            accumulator.value = ((a.value == "true") || b ? "true" : "false");
        }
    }

}
void CPU::compare(int address, bool b, std::string op) {
    Data a = memory->read(address);
    if (a.type == "Bool") {
        if (op == "==") {
            accumulator.value = (a.value == (b ? "true" : "false") ? "true" : "false");
        }
        if (op == "!=") {
            accumulator.value = (a.value != (b ? "true" : "false") ? "true" : "false");
        }
        if (op == "&&") {
            accumulator.value = (a.value == "true" && b ? "true" : "false");
        }
        if (op == "||") {
            accumulator.value = (a.value == "true" || b ? "true" : "false");
        }
    }

}


// =========================
// Debug
// =========================

void CPU::DEVELOPER_Print() {
    std::cout << "\n"
              << accumulator.type
              << ":"
              << accumulator.value
              << std::endl;
}