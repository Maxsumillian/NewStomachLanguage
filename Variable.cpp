//
// Created by maxy2 on 4/25/2026.
//

#include <iostream>
#include "Variable.h"

#include "StomachLang.h"

Variable::Variable() {
    maxAddress++;// increments to add to a new location for memory
    address = maxAddress;
    storeInMemory();
}

Variable::Variable(std::string dataType2, std::string dataValue2) {// only used by virtual cpu to store Temp data
    dataType = dataType2;
    dataValue = dataValue2;
    StomachLang::cpu.store(0);//stores in zero
}

void Variable::storeInMemory() {// made this virtual because when I create the variable the parent constructor runs first then the child runs but i need a way to make the child run the store function after the parent runs it
    StomachLang::cpu.add(dataType +":"+dataValue);//sets data into cpu accumulator
    StomachLang::cpu.store(address);
}


//returns variable address in memory
int Variable::getAddress() {
    return address;
}

std::string Variable::getType() {
    return dataType;
}

std::string Variable::getValue() {
    return dataValue;
}

// for testing
void Variable::printTest() {
    std::cout << "\n the Variable " << dataType << " is located at memory[" << address << "]" << " The MaxAddress to be incremented to is at " << maxAddress << std::endl;
}

Variable Variable::operator+(Variable var2) {
    StomachLang::cpu.add(dataType +":"+dataValue, var2.getType() + ":" + var2.getValue());// this adds into register but how do i take that and use it here?

    return StomachLang::cpu.createVariable();
    // std::cout << dataType +":"+dataValue + var2.getType() + ":" + var2.getValue();
}


void Variable::operator-(Variable var2){
    StomachLang::cpu.sub(dataType + ":" + dataValue, var2.getType() + ":" + var2.getValue());
    // std::cout << dataType +":"+dataValue + var2.getType() + ":" + var2.getValue();
}

// Variable& Variable::operator=(Variable var2) {
//     dataType = var2.getType();
//     dataValue = var2.getValue();
//     storeInMemory();
//     return *this;
// }
