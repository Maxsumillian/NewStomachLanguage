//
// Created by maxy2 on 4/25/2026.
//

#include <iostream>
#include "Variable.h"

#include "StomachLang.h"
#include "Data.h"

Variable::Variable() {
    maxAddress++;// increments to add to a new location for memory
    address = maxAddress;
    storeInMemory(Data{"dataType", "dataValue"});
}

Variable::Variable(std::string dataType2, std::string dataValue2) {// only used by virtual cpu to store Temp data
    // dataType = dataType2;
    // dataValue = dataValue2;
    maxAddress++;
    address = maxAddress;
    StomachLang::cpu.add(Data{dataType2, dataValue2});
    StomachLang::cpu.store(address);//since this is a temp vairble i can instead create a bool in vairbel to check if is temp and flag it if i want to handle garbage
}

void Variable::storeInMemory(Data d) {// made this virtual because when I create the variable the parent constructor runs first then the child runs but i need a way to make the child run the store function after the parent runs it
    StomachLang::cpu.add(d);//sets data into cpu accumulator
    StomachLang::cpu.store(address);
}

void Variable::storeInMemory(int address,int address2) {// made this virtual because when I create the variable the parent constructor runs first then the child runs but i need a way to make the child run the store function after the parent runs it
    StomachLang::cpu.add(address2);//sets data into cpu accumulator
    StomachLang::cpu.store(address);
}

//returns variable address in memory
int Variable::getAddress() {
    return address;
}

// std::string Variable::getType() {
//     return dataType;
// }

// std::string Variable::getValue() {
//     return dataValue;
// }

// for testing
// void Variable::printTest() {
//     std::cout << "\n the Variable " << dataType << " is located at memory[" << address << "]" << " The MaxAddress to be incremented to is at " << maxAddress << std::endl;
// }

Variable Variable::operator+(Variable var2) {// adjust this instead of grabbing its inhearent values i need to grab from my virtual memory using the addresses from variables
    //NOtes "getType" is not needed when i transistion to cpu and virtual memory beacause i will use my decoder in my memory
    StomachLang::cpu.add(address, var2.getAddress());
    // StomachLang::cpu.operation(address, var2.getAddress(), [](int x, int y){ return x + y; });
    //StomachLang::cpu.add(dataType +":"+dataValue, var2.getType() + ":" + var2.getValue());// this adds into register but how do i take that and use it here?
    return Variable(StomachLang::cpu.getAccumulatorDataType(), StomachLang::cpu.getAccumulatorDataValue());
    //NOTE: if i make a struct to hold the data instead of just one string i can pas teh data as one entity instead of parts and then extract that way

    //return StomachLang::cpu.createVariable();// this is when I use createVarible beacause I need this opeartor+ overload to return a varible to be used for chainging;
    // std::cout << dataType +":"+dataValue + var2.getType() + ":" + var2.getValue();
}


Variable Variable::operator-(Variable var2){
    StomachLang::cpu.sub(address, var2.getAddress());
    return Variable(StomachLang::cpu.getAccumulatorDataType(), StomachLang::cpu.getAccumulatorDataValue());
    // std::cout << dataType +":"+dataValue + var2.getType() + ":" + var2.getValue();
}

// Variable& Variable::operator=(Variable var2) {
//     dataType = var2.getType();
//     dataValue = var2.getValue();
//     storeInMemory();
//     return *this;
// }


// beacuse using ints from c++ some limitation so i have to do it here unless i pass more informatino making more complex
Variable Variable::operator+(int i) {
    StomachLang::cpu.add(address);
    if (StomachLang::cpu.getAccumulatorDataType() == "INT")
        return Variable(StomachLang::cpu.getAccumulatorDataType(), std::to_string(std::stoi(StomachLang::cpu.getAccumulatorDataValue()) + i));

    std::cout<<"\n\033[31mCannot add "<<StomachLang::cpu.getAccumulatorDataType() <<" and INT\033[0m";
    return *this;
}

Variable Variable::operator-(int i) {
    StomachLang::cpu.add(address);
    if (StomachLang::cpu.getAccumulatorDataType() == "INT")
        return Variable(StomachLang::cpu.getAccumulatorDataType(), std::to_string(std::stoi(StomachLang::cpu.getAccumulatorDataValue()) - i));

    std::cout<<"\n\033[31mCannot add "<<StomachLang::cpu.getAccumulatorDataType() <<" and INT\033[0m";
    return *this;
}

Variable Variable::operator*(int i) {
    StomachLang::cpu.add(address);
    if (StomachLang::cpu.getAccumulatorDataType() == "INT")
        return Variable(StomachLang::cpu.getAccumulatorDataType(), std::to_string(std::stoi(StomachLang::cpu.getAccumulatorDataValue()) * i));

    std::cout<<"\n\033[31mCannot add "<<StomachLang::cpu.getAccumulatorDataType() <<" and INT\033[0m";
    return *this;
}

Variable Variable::operator/(int i) {
    StomachLang::cpu.add(address);
    if (StomachLang::cpu.getAccumulatorDataType() == "INT")
        return Variable(StomachLang::cpu.getAccumulatorDataType(), std::to_string(std::stoi(StomachLang::cpu.getAccumulatorDataValue()) / i));

    std::cout<<"\n\033[31mCannot add "<<StomachLang::cpu.getAccumulatorDataType() <<" and INT\033[0m";
    return *this;
}

Variable Variable::operator%(int i) {
    StomachLang::cpu.add(address);
    if (StomachLang::cpu.getAccumulatorDataType() == "INT")
        return Variable(StomachLang::cpu.getAccumulatorDataType(), std::to_string(std::stoi(StomachLang::cpu.getAccumulatorDataValue()) % i));

    std::cout<<"\n\033[31mCannot add "<<StomachLang::cpu.getAccumulatorDataType() <<" and INT\033[0m";
    return *this;
}



//weird i have to use this char* instead of string but i guess // limitations with concatting
Variable Variable::operator+(const char* value) {
    StomachLang::cpu.add(address);
    if (StomachLang::cpu.getAccumulatorDataType() == "String")
        return Variable(StomachLang::cpu.getAccumulatorDataType(), StomachLang::cpu.getAccumulatorDataValue() + value);

    std::cout<<"\n\033[31mCannot add "<<StomachLang::cpu.getAccumulatorDataType() <<" and String\033[0m";
    return *this;
}

Variable operator+( int b, const Variable& a) {
    StomachLang::cpu.add(a.address);
    if (StomachLang::cpu.getAccumulatorDataType() == "INT")
        return Variable(StomachLang::cpu.getAccumulatorDataType(), std::to_string(std::stoi(StomachLang::cpu.getAccumulatorDataValue()) + b));

    std::cout<<"\n\033[31mCannot add "<<StomachLang::cpu.getAccumulatorDataType() <<" and INT\033[0m";
}

Variable operator-( int b, const Variable& a){
    StomachLang::cpu.add(a.address);
    if (StomachLang::cpu.getAccumulatorDataType() == "INT")
        return Variable(StomachLang::cpu.getAccumulatorDataType(), std::to_string(std::stoi(StomachLang::cpu.getAccumulatorDataValue()) - b));

    std::cout<<"\n\033[31mCannot add "<<StomachLang::cpu.getAccumulatorDataType() <<" and INT\033[0m";
}

Variable operator*( int b, const Variable& a){
    StomachLang::cpu.add(a.address);
    if (StomachLang::cpu.getAccumulatorDataType() == "INT")
        return Variable(StomachLang::cpu.getAccumulatorDataType(), std::to_string(std::stoi(StomachLang::cpu.getAccumulatorDataValue()) * b));

    std::cout<<"\n\033[31mCannot add "<<StomachLang::cpu.getAccumulatorDataType() <<" and INT\033[0m";
}

Variable operator/( int b, const Variable& a){
    StomachLang::cpu.add(a.address);
    if (StomachLang::cpu.getAccumulatorDataType() == "INT")
        return Variable(StomachLang::cpu.getAccumulatorDataType(), std::to_string(std::stoi(StomachLang::cpu.getAccumulatorDataValue()) / b));

    std::cout<<"\n\033[31mCannot add "<<StomachLang::cpu.getAccumulatorDataType() <<" and INT\033[0m";
}

Variable operator%( int b, const Variable& a){
    StomachLang::cpu.add(a.address);
    if (StomachLang::cpu.getAccumulatorDataType() == "INT")
        return Variable(StomachLang::cpu.getAccumulatorDataType(), std::to_string(std::stoi(StomachLang::cpu.getAccumulatorDataValue()) % b));

    std::cout<<"\n\033[31mCannot add "<<StomachLang::cpu.getAccumulatorDataType() <<" and INT\033[0m";
}
