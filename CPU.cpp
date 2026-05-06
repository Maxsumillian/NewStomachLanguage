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
// CHAT GPT ASSISTED WITH THIS TEMPLATE
// =========================

void CPU::sub(int a, int b) {
    operation(a, b, [](int x, int y) {
        return x - y;
    },"subtract");
}

void CPU::multiply(int a, int b) {
    operation(a, b, [](int x, int y) {
        return x * y;
    },"multiply");
}

void CPU::divide(int a, int b) {
    operation(a, b, [](int x, int y) {
        return x / y;
    },"divide");
}

void CPU::modulo(int a, int b) {
    operation(a, b, [](int x, int y)  {
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
// Debug
// =========================

void CPU::DEVELOPER_Print() {
    std::cout << "\n"
              << accumulator.type
              << ":"
              << accumulator.value
              << std::endl;
}