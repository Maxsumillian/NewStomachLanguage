//
// Created by maxy2 on 4/25/2026.
//

#include "CPU.h"

#include <iostream>
#include <ostream>

#include "StomachLang.h"


CPU::CPU(Memory* mem) : memory(mem), accumulator("") {}


// std::string CPU::getAccumulator() {
//     return accumulator;
// }


std::string CPU::getAccumulatorDataType() {
    return decodeDataType(accumulator);
}
std::string CPU::getAccumulatorDataValue() {
    return decodeDataValue(accumulator);
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
//
// void CPU::add(std::string value, std::string value2) {
//     if (decodeDataType(value) == decodeDataType(value2)) {
//         if (decodeDataType(value) == "Int") {
//             accumulator = decodeDataType(value) +":"+ std::to_string(std::stoi(decodeDataValue(value)) + std::stoi(decodeDataValue(value2)));
//             // this is funny first converts string data to get only the value then converts that value to integer then
//             // adds then proceeds to turn back into string to be set into the accumulator
//         }
//         else {
//             accumulator = decodeDataType(value) +":"+ decodeDataValue(value) + decodeDataValue(value2);
//         }
//
//     }
//     else {
//         std::cout << "\n\033[31m" << "Error: Cannot add "<< decodeDataType(value) << " & " << decodeDataType(value2) << "\033[0m" ;
//     }
// }

//===================================================================
void CPU::add(int address) {
    accumulator = memory->read(address);

}
void CPU::add(int address, int address2) {
    if (decodeDataType(memory->read(address)) == decodeDataType(memory->read(address2))) {
        if (decodeDataType(memory->read(address)) == "Int") {
            // load(address);// NOTE: Im setting the accumulator but im not using the load function to actually load the function and
            // also i should be doing somthing like accumulator += newaddress,
            // However beacuse of how i am storing hte information i woudl need to seperate the values and recombine into parts, if i were using a struct that would make it simpler and bea ble to onl yadd to the second part
            accumulator = decodeDataType(memory->read(address)) +":"+ std::to_string(std::stoi(decodeDataValue(memory->read(address))) + std::stoi(decodeDataValue(memory->read(address2))));
        }
        else {
            accumulator = decodeDataType(memory->read(address)) +":"+ decodeDataValue(memory->read(address)) + decodeDataValue(memory->read(address2));
        }
    }
    else {
        std::cout << "\n\033[31m" << "Error: Cannot add "<< decodeDataType(memory->read(address)) << " & " << decodeDataType(memory->read(address2)) << "\033[0m" ;
    }
}

//===================================================================

void CPU::sub(int address, int address2) {
    if (decodeDataType(memory->read(address)) == decodeDataType(memory->read(address2)) && decodeDataType(memory->read(address)) == "Int") {
            accumulator = std::to_string(std::stoi(decodeDataValue(memory->read(address))) - std::stoi(decodeDataValue(memory->read(address2))));
    }
    else {
        std::cout << "\n\033[31m" << "Error: Cannot subtract "<< decodeDataType(memory->read(address)) << " & " << decodeDataType(memory->read(address2)) << "\033[0m" ;
    }
}


void CPU::DEVELOPER_Print() {
    std::cout << std::endl << accumulator ;
}