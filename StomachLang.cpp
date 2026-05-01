//
// Created by maxy2 on 4/25/2026.
//

#include "StomachLang.h"
#include <iostream>


Memory StomachLang::memory(1080);

CPU StomachLang::cpu(&StomachLang::memory);

void StomachLang::poop(Variable var) {
    // std::cout << var.getValue();
}

std::ostream& StomachLang::poop() {
    return std::cout;
}

std::ostream& StomachLang::poop(std::string& value) {
    return std::cout << value;
}

std::ostream& StomachLang::poop(Variable &value) {
    cpu.add(value.getAddress());
    return std::cout << cpu.getAccumulatorDataValue();
}


std::istream& StomachLang::eat() {
    return std::cin;
}

// freinds for operator overloads out of scope
std::ostream& operator<<(std::ostream& o, Foods& food) {
    StomachLang::cpu.add(food.getAddress());
    o << StomachLang::cpu.getAccumulatorDataValue();
    return o;
}

std::ostream& operator<<(std::ostream& o, Calorie& calorie) {
    StomachLang::cpu.add(calorie.getAddress());
    o << StomachLang::cpu.getAccumulatorDataValue();
    return o;
}

std::ostream& operator<<(std::ostream& o, Edible& edible) {
    StomachLang::cpu.add(edible.getAddress());
    o << StomachLang::cpu.getAccumulatorDataValue();
    return o;
}

std::istream& operator>>(std::istream& in, Foods& food) {
    std::string value;
    in >> value;
    StomachLang::cpu.add(Data{"String",value});
    StomachLang::cpu.store(food.getAddress());
    return in;
}

std::istream& operator>>(std::istream& in, Calorie& calorie) {
    int value;
    in >> value;
    StomachLang::cpu.add(Data{"Int",std::to_string(value)});
    StomachLang::cpu.store(calorie.getAddress());
    return in;
}

std::istream& operator>>(std::istream& in, Edible& edible) {
    bool value;
    in >> value;
    StomachLang::cpu.add(Data{"Bool",(value ? "true" : "false")});
    StomachLang::cpu.store(edible.getAddress());
    return in;
}