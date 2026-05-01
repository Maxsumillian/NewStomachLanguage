//
// Created by maxy2 on 4/25/2026.
//

#include "Memory.h"
#include <iostream>
#include "Data.h"

Memory::Memory(int size) {
    memory.resize(size);  // initialize with empty strings
}

Data Memory::read(int address) {
    if (address < 0) {
        std::cout<<"\n\033[31mNegative address not allowed\033[0m";
        return Data{};
    }
    else if (address >= memory.size()) {
        std::cout<<"\n\033[31mAddress out of range " << address << " Not in scope of Memory Size[" << memory.size()-1 << "]\033[0m";
        return Data{};
        // memory.resize(address + 1);// auto-expand memory if needed
    }else {
        return memory[address];
    }
}

void Memory::write(int address, Data value) {
    if (address < 0) {
        std::cout<<"\n\033[31mNegative address not allowed\033[0m";
    }
    else if (address >= memory.size()) {
        std::cout<<"\n\033[31m[" << value.type << "] Address out of range " << address << " Not in scope of Memory Size[" << memory.size()-1 << "]\033[0m";
        // memory.resize(address + 1);// auto-expand memory if needed
    }else {
        memory[address] = value;
    }
}