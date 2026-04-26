//
// Created by maxy2 on 4/25/2026.
//

#include "CPU.h"

#include <iostream>
#include <ostream>

#include "StomachLang.h"


CPU::CPU(Memory* mem) : memory(mem), accumulator("") {}

void CPU::load(int address) {
    accumulator = memory->read(address);
}

void CPU::store(int address) {
    memory->write(address, accumulator);
}


void CPU::add(std::string value) {
    accumulator = value;
}

// void CPU::add(Variable var) {
//     accumulator = var.getType() + ":" + var.getValue();
// }
// void CPU::add(Variable var1, Variable var2) {
//
// }
//
// void CPU::createVariable(Variable var) {
//     add(var);
//     store(var.getAddress());
// }

void CPU::DEVELOPER_Print() {
    std::cout << std::endl << accumulator ;
}