//
// Created by maxy2 on 4/25/2026.
//

#include "CPU.h"

#include <iostream>
#include <ostream>

#include "StomachLang.h"

#include "Data.h"


CPU::CPU(Memory* mem) : memory(mem), accumulator() {}


// std::string CPU::getAccumulator() {
//     return accumulator;
// }


std::string CPU::getAccumulatorDataType() {
    return accumulator.type;
}
std::string CPU::getAccumulatorDataValue() {
    return accumulator.value;
}



// Variable CPU::createVariable() {// no need to make Variable in CPU i can make it in my overlaoded function but instead i need a way to pass the data to my varibel class
// here i use getAccumulatorDataTyep/DataValue
//     return Variable(decodeDataType(accumulator), decodeDataValue(accumulator));
// }

void CPU::load(int address) {
    accumulator = memory->read(address);
}

void CPU::store(int address) {
    memory->write(address, accumulator);
}

//not needed now that im moving to struct
// std::string CPU::decodeDataType(std::string value) {
//     int pos = value.find(':');
//     return value.substr(0, pos);
// }
//
// std::string CPU::decodeDataValue(std::string value) {
//     int pos = value.find(':');
//     return value.substr( pos + 1);
// }

void CPU::add(Data d) {// single add so this acts as a set accumulator
    accumulator.type = d.type;
    accumulator.value = d.value;//doesnt follow the traditinal way of just adding to the acumulator
}// may change this and have a decicated send to register

//===================================================================
void CPU::add(int address) {
    accumulator = memory->read(address);
}

// repeating code can use template for most of it
void CPU::add(int address, int address2) {

    Data a = memory->read(address);
    Data b = memory->read(address2);

    if (a.type != b.type) {
        std::cout << "\n\033[31mError: Cannot add " << a.type << " & " << b.type << "\033[0m";
        return;
    }

    if (a.type == "INT") {
        accumulator.value = std::to_string(std::stoi(a.value) + std::stoi(b.value));
    }
    else {
        accumulator.value = a.value + b.value;
    }
}// SPECIAL CASE FOR STRINGS BEACUSE OF CONCATING
//
// //===================================================================
//
// // can use templates instead of this alot of copy and paste
// void CPU::sub(int address, int address2) {
//
//     Data a = memory->read(address);
//     Data b = memory->read(address2);
//
//     if (a.type == "INT" && b.type == "INT") {
//         accumulator.value = std::to_string(std::stoi(a.value) - std::stoi(b.value));
//     }
//     else {
//         std::cout << "\n\033[31mError: Cannot subtract " << a.type << " & " << b.type << "\033[0m";
//     }
// }
//
// void CPU::multiply(int address, int address2) {
//
//     Data a = memory->read(address);
//     Data b = memory->read(address2);
//
//     if (a.type == "INT" && b.type == "INT") {
//         accumulator.value = std::to_string(std::stoi(a.value) * std::stoi(b.value));
//     }
//     else {
//         std::cout << "\n\033[31mError: Cannot Multiply " << a.type << " & " << b.type << "\033[0m";
//     }
// }
//
// void CPU::divide(int address, int address2) {
//
//     Data a = memory->read(address);
//     Data b = memory->read(address2);
//
//     if (a.type == "INT" && b.type == "INT") {
//         accumulator.value = std::to_string(std::stoi(a.value) / std::stoi(b.value));
//     }
//     else {
//         std::cout << "\n\033[31mError: Cannot Multiply " << a.type << " & " << b.type << "\033[0m";
//     }
// }
//
// void CPU::modulo(int address, int address2) {
//
//     Data a = memory->read(address);
//     Data b = memory->read(address2);
//
//     if (a.type == "INT" && b.type == "INT") {
//         accumulator.value = std::to_string(std::stoi(a.value) % std::stoi(b.value));
//     }
//     else {
//         std::cout << "\n\033[31mError: Cannot Multiply " << a.type << " & " << b.type << "\033[0m";
//     }
// }




// much smaller funcitons after using a template
// void CPU::add(int a, int b) {
//     operation(a, b, [](auto x, auto y) {
//         return x + y;
//     });
// }

void CPU::sub(int a, int b) {
    operation(a, b, [](int x, int y) {
        return x - y;
    });
}

void CPU::multiply(int a, int b) {
    operation(a, b, [](int x, int y) {
        return x * y;
    });
}

void CPU::divide(int a, int b) {
    operation(a, b, [](int x, int y) {
        return x / y;
    });
}

void CPU::modulo(int a, int b) {
    operation(a, b, [](int x, int y) {
        return x % y;
    });
}

template<typename Op>
void CPU::operation(int address, int address2, Op op) {// chatgpt helped with the templating

    Data a = memory->read(address);
    Data b = memory->read(address2);

    if (a.type != "INT" || b.type != "INT") {
        std::cout << "\n\033[31mType error\033[0m";
        return;
    }

    int x = std::stoi(a.value);
    int y = std::stoi(b.value);

    int result = op(x, y);   // <-- ONLY ints here

    accumulator.type = "INT";
    accumulator.value = std::to_string(result);
}




void CPU::DEVELOPER_Print() {
    std::cout << std::endl << accumulator.type << ":" << accumulator.value <<std::endl ;
}