//
// Created by maxy2 on 4/25/2026.
//

#include "Calorie.h"
#include <string>

#include "StomachLang.h"


Calorie::Calorie(): Variable() {// this calls after parent constructor but it does not place the variable in my virtual memory
    // dataType = "Int";//when decalred it sets its dataType to "INT" so the cpu/Language can decode this to be usable for users
    // dataValue = "NUll";// currently no known values will need to use the assign operator for this.
    storeInMemory(Data{"INT", "NULL"});
}

Calorie::Calorie(int value) {
    storeInMemory(Data{"INT", std::to_string(value)});
}


Calorie::Calorie(Variable variable) {
    // dataType = "Int";
    // dataValue = variable.getValue();
    storeInMemory(address,variable.getAddress());
}

void Calorie::operator=(int Calories) {
    // dataValue = std::to_string(Calories);
    storeInMemory(Data{"INT", std::to_string(Calories)});
}

Calorie& Calorie::operator=(Variable var2) {
    // dataType = var2.getType();
    // dataValue = var2.getValue();
    storeInMemory(address,var2.getAddress());
    return *this;
}



// calorie + int
Variable Calorie::operator+(int b){
    StomachLang::cpu.add(address);
    if (StomachLang::cpu.getAccumulatorDataType() == "INT")
        return Variable(StomachLang::cpu.getAccumulatorDataType(), std::to_string(std::stoi(StomachLang::cpu.getAccumulatorDataValue()) + b));

    std::cout<<"\n\033[31mNot a valid \"+\" Operation\033[0m";
    return *this;
}

// calorie + calorie
Variable Calorie::operator+(Calorie c){
    StomachLang::cpu.add(address);
    if (StomachLang::cpu.getAccumulatorDataType() == "INT")
        StomachLang::cpu.add(address,c.getAddress());
        return Variable(StomachLang::cpu.getAccumulatorDataType(),(StomachLang::cpu.getAccumulatorDataValue()));

    std::cout<<"\n\033[31mNot a valid \"+\" Operation\033[0m";
    return *this;
}

// int + calorie
Variable operator+(int b, Calorie &a) {

    StomachLang::cpu.add(a.getAddress());
    // std::to_string(std::stoi(StomachLang::cpu.getAccumulatorDataValue()) + b);
    // std::cout << std::to_string(std::stoi(StomachLang::cpu.getAccumulatorDataValue()) + b) << b << StomachLang::cpu.getAccumulatorDataValue() << std::endl;
    return Variable(StomachLang::cpu.getAccumulatorDataType(), std::to_string(std::stoi(StomachLang::cpu.getAccumulatorDataValue()) + b));
    // return Calorie(value);
    // return Calorie(std::stoi(StomachLang::cpu.getAccumulatorDataValue(a.getAddress())) + b);
}

// calorie - int
Variable Calorie::operator-(int b){
    StomachLang::cpu.add(address);
    if (StomachLang::cpu.getAccumulatorDataType() == "INT")
        return Variable(StomachLang::cpu.getAccumulatorDataType(), std::to_string(std::stoi(StomachLang::cpu.getAccumulatorDataValue()) - b));

    std::cout<<"\n\033[31mNot a valid \"+\" Operation\033[0m";
    return *this;
}

// calorie - calorie
Variable Calorie::operator-(Calorie c){
    StomachLang::cpu.add(address);
    if (StomachLang::cpu.getAccumulatorDataType() == "INT")
        StomachLang::cpu.sub(address,c.getAddress());
    return Variable(StomachLang::cpu.getAccumulatorDataType(),(StomachLang::cpu.getAccumulatorDataValue()));

    std::cout<<"\n\033[31mNot a valid \"+\" Operation\033[0m";
    return *this;
}

// int - calorie
Variable operator-(int b, Calorie &a) {

    StomachLang::cpu.add(a.getAddress());
    // std::to_string(std::stoi(StomachLang::cpu.getAccumulatorDataValue()) + b);
    // std::cout << std::to_string(std::stoi(StomachLang::cpu.getAccumulatorDataValue()) + b) << b << StomachLang::cpu.getAccumulatorDataValue() << std::endl;
    return Variable(StomachLang::cpu.getAccumulatorDataType(), std::to_string( b - std::stoi(StomachLang::cpu.getAccumulatorDataValue())));
    // return Calorie(value);
    // return Calorie(std::stoi(StomachLang::cpu.getAccumulatorDataValue(a.getAddress())) + b);
}

// calorie * int
Variable Calorie::operator*(int b){
    StomachLang::cpu.add(address);
    if (StomachLang::cpu.getAccumulatorDataType() == "INT")
        return Variable(StomachLang::cpu.getAccumulatorDataType(), std::to_string(std::stoi(StomachLang::cpu.getAccumulatorDataValue()) * b));

    std::cout<<"\n\033[31mNot a valid \"*\" Operation\033[0m";
    return *this;
}

// calorie * calorie
Variable Calorie::operator*(Calorie c){
    StomachLang::cpu.add(address);
    if (StomachLang::cpu.getAccumulatorDataType() == "INT")
        StomachLang::cpu.multiply(address,c.getAddress());
    return Variable(StomachLang::cpu.getAccumulatorDataType(),(StomachLang::cpu.getAccumulatorDataValue()));

    std::cout<<"\n\033[31mNot a valid \"+\" Operation\033[0m";
    return *this;
}

// int * calorie
Variable operator*(int b, Calorie &a) {

    StomachLang::cpu.add(a.getAddress());
    // std::to_string(std::stoi(StomachLang::cpu.getAccumulatorDataValue()) + b);
    // std::cout << std::to_string(std::stoi(StomachLang::cpu.getAccumulatorDataValue()) + b) << b << StomachLang::cpu.getAccumulatorDataValue() << std::endl;
    return Variable(StomachLang::cpu.getAccumulatorDataType(), std::to_string( b * std::stoi(StomachLang::cpu.getAccumulatorDataValue())));
    // return Calorie(value);
    // return Calorie(std::stoi(StomachLang::cpu.getAccumulatorDataValue(a.getAddress())) + b);
}

// calorie / int
Variable Calorie::operator/(int b){
    StomachLang::cpu.add(address);
    if (StomachLang::cpu.getAccumulatorDataType() == "INT")
        return Variable(StomachLang::cpu.getAccumulatorDataType(), std::to_string(std::stoi(StomachLang::cpu.getAccumulatorDataValue()) / b));

    std::cout<<"\n\033[31mNot a valid \"/\" Operation\033[0m";
    return *this;
}

// calorie / calorie
Variable Calorie::operator/(Calorie c){
    StomachLang::cpu.add(address);
    if (StomachLang::cpu.getAccumulatorDataType() == "INT")
        StomachLang::cpu.divide(address,c.getAddress());
    return Variable(StomachLang::cpu.getAccumulatorDataType(),(StomachLang::cpu.getAccumulatorDataValue()));

    std::cout<<"\n\033[31mNot a valid \"+\" Operation\033[0m";
    return *this;
}

// int / calorie
Variable operator/(int b, Calorie &a) {

    StomachLang::cpu.add(a.getAddress());
    // std::to_string(std::stoi(StomachLang::cpu.getAccumulatorDataValue()) + b);
    // std::cout << std::to_string(std::stoi(StomachLang::cpu.getAccumulatorDataValue()) + b) << b << StomachLang::cpu.getAccumulatorDataValue() << std::endl;
    return Variable(StomachLang::cpu.getAccumulatorDataType(), std::to_string( b / std::stoi(StomachLang::cpu.getAccumulatorDataValue())));
    // return Calorie(value);
    // return Calorie(std::stoi(StomachLang::cpu.getAccumulatorDataValue(a.getAddress())) + b);
}

// calorie % int
Variable Calorie::operator%(int b){
    StomachLang::cpu.add(address);
    if (StomachLang::cpu.getAccumulatorDataType() == "INT")
        return Variable(StomachLang::cpu.getAccumulatorDataType(), std::to_string(std::stoi(StomachLang::cpu.getAccumulatorDataValue()) % b));

    std::cout<<"\n\033[31mNot a valid \"%\" Operation\033[0m";
    return *this;
}

// calorie % calorie
Variable Calorie::operator%(Calorie c){
    StomachLang::cpu.add(address);
    if (StomachLang::cpu.getAccumulatorDataType() == "INT")
        StomachLang::cpu.modulo(address,c.getAddress());
    return Variable(StomachLang::cpu.getAccumulatorDataType(),(StomachLang::cpu.getAccumulatorDataValue()));

    std::cout<<"\n\033[31mNot a valid \"+\" Operation\033[0m";
    return *this;
}

// int % calorie
Variable operator%(int b, Calorie &a) {

    StomachLang::cpu.add(a.getAddress());
    // std::to_string(std::stoi(StomachLang::cpu.getAccumulatorDataValue()) + b);
    // std::cout << std::to_string(std::stoi(StomachLang::cpu.getAccumulatorDataValue()) + b) << b << StomachLang::cpu.getAccumulatorDataValue() << std::endl;
    return Variable(StomachLang::cpu.getAccumulatorDataType(), std::to_string( b % std::stoi(StomachLang::cpu.getAccumulatorDataValue())));
    // return Calorie(value);
    // return Calorie(std::stoi(StomachLang::cpu.getAccumulatorDataValue(a.getAddress())) + b);
}

// Variable + calorie
Variable operator+(Variable b, Calorie &a) {
    StomachLang::cpu.add(b.getAddress());
    if (StomachLang::cpu.getAccumulatorDataType() == "INT")
        StomachLang::cpu.add(b.getAddress(),a.getAddress());
    return Variable(StomachLang::cpu.getAccumulatorDataType(),(StomachLang::cpu.getAccumulatorDataValue()));
}

Variable operator-(Variable b, Calorie &a) {
    StomachLang::cpu.add(b.getAddress());
    if (StomachLang::cpu.getAccumulatorDataType() == "INT")
        StomachLang::cpu.sub(b.getAddress(),a.getAddress());
    return Variable(StomachLang::cpu.getAccumulatorDataType(),(StomachLang::cpu.getAccumulatorDataValue()));
}

Variable operator*(Variable b, Calorie &a) {
    StomachLang::cpu.add(b.getAddress());
    if (StomachLang::cpu.getAccumulatorDataType() == "INT")
        StomachLang::cpu.multiply(b.getAddress(),a.getAddress());
    return Variable(StomachLang::cpu.getAccumulatorDataType(),(StomachLang::cpu.getAccumulatorDataValue()));
}

Variable operator/(Variable b, Calorie &a) {
    StomachLang::cpu.add(b.getAddress());
    if (StomachLang::cpu.getAccumulatorDataType() == "INT")
        StomachLang::cpu.divide(b.getAddress(),a.getAddress());
    return Variable(StomachLang::cpu.getAccumulatorDataType(),(StomachLang::cpu.getAccumulatorDataValue()));
}

Variable operator%(Variable b, Calorie &a) {
    StomachLang::cpu.add(b.getAddress());
    if (StomachLang::cpu.getAccumulatorDataType() == "INT")
        StomachLang::cpu.modulo(b.getAddress(),a.getAddress());
    return Variable(StomachLang::cpu.getAccumulatorDataType(),(StomachLang::cpu.getAccumulatorDataValue()));
}