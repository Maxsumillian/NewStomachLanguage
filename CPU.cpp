//
// Created by maxy2 on 4/25/2026.
//

#include "CPU.h"

#include <iostream>
#include <ostream>

#include "StomachLang.h"


CPU::CPU(Memory* mem) : memory(mem), accumulator("") {}


std::string CPU::getAccumulator() {
    return accumulator;
}

Variable CPU::createVariable() {
    return Variable(decodeDataType(accumulator), decodeDataValue(accumulator));
}

void CPU::load(int address) {
    accumulator = memory->read(address);
}

void CPU::store(int address) {
    memory->write(address, accumulator);
}



std::string CPU::decodeDataType(std::string value) {
    int pos = value.find(':');
    return value.substr(0, pos);
}

std::string CPU::decodeDataValue(std::string value) {
    int pos = value.find(':');
    return value.substr( pos + 1);
}

void CPU::add(std::string value) {// single add so this acts as a set accumulator
    accumulator = value;
}

void CPU::add(std::string value, std::string value2) {
    if (decodeDataType(value) == decodeDataType(value2)) {
        if (decodeDataType(value) == "Int") {
            accumulator = decodeDataType(value) +":"+ std::to_string(std::stoi(decodeDataValue(value)) + std::stoi(decodeDataValue(value2)));
            // this is funny first converts string data to get only the value then converts that value to integer then
            // adds then proceeds to turn back into string to be set into the accumulator
        }
        else {
            accumulator = decodeDataType(value) +":"+ decodeDataValue(value) + decodeDataValue(value2);
        }

    }
    else {
        std::cout << "\n\033[31m" << "Error: Cannot add "<< decodeDataType(value) << " & " << decodeDataType(value2) << "\033[0m" ;
    }
}

void CPU::sub(std::string value, std::string value2) {
    if (decodeDataType(value) == decodeDataType(value2) && decodeDataType(value) == "Int") {
            accumulator = std::to_string(std::stoi(decodeDataValue(value)) - std::stoi(decodeDataValue(value2)));
    }
    else {
        std::cout << "\n\033[31m" << "Error: Cannot subtract "<< decodeDataType(value) << " & " << decodeDataType(value2) << "\033[0m" ;
    }
}


void CPU::DEVELOPER_Print() {
    std::cout << std::endl << accumulator ;
}