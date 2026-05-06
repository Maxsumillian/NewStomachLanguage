

#include "Memory.h"
#include <iostream>
#include "Data.h"


Memory::Memory(int size) {
//    memory.resize(size);
    maxMemorySize = size;
}


// =========================
// Read
// =========================

Data Memory::read(int address) {
    if (address < 0) {
        std::cout << "\n\033[31mNegative address not allowed\033[0m";
        return Data{};
    }

    if (address >= maxMemorySize) {
        std::cout << "\n\033[31mAddress out of range "
                  << address
                  << " Not in scope of Memory Size["
                  << maxMemorySize
                  << "]\033[0m";

        return Data{};
    }
	//map testing
    return memory[address];
}


// =========================
// Write
// =========================

void Memory::write(int address, Data value) {
    if (address < 0) {
        std::cout << "\n\033[31mNegative address not allowed\033[0m";
        return;
    }

    if (address >= maxMemorySize) {
        std::cout << "\n\033[31m["
                  << value.type
                  << "] Address out of range "
                  << address
                  << " Not in scope of Memory Size["
                  << maxMemorySize
                  << "]\033[0m";

        return;
    }

    memory[address] = value;
//	mem.insert(std::make_pair(address,value));
    
}
