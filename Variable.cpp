//
// Created by maxy2 on 4/25/2026.
//

#include <iostream>
#include "Variable.h"
#include "StomachLang.h"
#include "Data.h"

int Variable::maxAddress = 0;


// =========================
// Construction
// =========================

Variable::Variable() {
    maxAddress++;
    address = maxAddress;

    storeInMemory(Data{"dataType", "dataValue"});
}

Variable::Variable(std::string dataType2, std::string dataValue2) {
    maxAddress++;
    address = maxAddress;

    StomachLang::cpu.add(Data{dataType2, dataValue2});
    StomachLang::cpu.store(address);
}


// =========================
// Memory helpers
// =========================

void Variable::storeInMemory(Data d) {
    StomachLang::cpu.add(d);
    StomachLang::cpu.store(address);
}

void Variable::storeInMemory(int address, int address2) {
    StomachLang::cpu.add(address2);
    StomachLang::cpu.store(address);
}

int Variable::getAddress() {
    return address;
}


// =========================
// Variable + Variable ops
// =========================

Variable Variable::operator+(Variable var2) {
    StomachLang::cpu.add(address, var2.getAddress());

    return Variable(
        StomachLang::cpu.getAccumulatorDataType(),
        StomachLang::cpu.getAccumulatorDataValue()
    );
}

Variable Variable::operator-(Variable var2) {
    StomachLang::cpu.sub(address, var2.getAddress());

    return Variable(
        StomachLang::cpu.getAccumulatorDataType(),
        StomachLang::cpu.getAccumulatorDataValue()
    );
}


// =========================
// Variable + int ops
// =========================

Variable Variable::operator+(int i) {
    StomachLang::cpu.add(address);

    if (StomachLang::cpu.getAccumulatorDataType() == "INT")
        return Variable(
            StomachLang::cpu.getAccumulatorDataType(),
            std::to_string(
                std::stoi(StomachLang::cpu.getAccumulatorDataValue()) + i
            )
        );

    std::cout << "\n\033[31mCannot add "
              << StomachLang::cpu.getAccumulatorDataType()
              << " and INT\033[0m";

    return *this;
}

Variable Variable::operator-(int i) {
    StomachLang::cpu.add(address);

    if (StomachLang::cpu.getAccumulatorDataType() == "INT")
        return Variable(
            StomachLang::cpu.getAccumulatorDataType(),
            std::to_string(
                std::stoi(StomachLang::cpu.getAccumulatorDataValue()) - i
            )
        );

    std::cout << "\n\033[31mCannot add "
              << StomachLang::cpu.getAccumulatorDataType()
              << " and INT\033[0m";

    return *this;
}

Variable Variable::operator*(int i) {
    StomachLang::cpu.add(address);

    if (StomachLang::cpu.getAccumulatorDataType() == "INT")
        return Variable(
            StomachLang::cpu.getAccumulatorDataType(),
            std::to_string(
                std::stoi(StomachLang::cpu.getAccumulatorDataValue()) * i
            )
        );

    std::cout << "\n\033[31mCannot add "
              << StomachLang::cpu.getAccumulatorDataType()
              << " and INT\033[0m";

    return *this;
}

Variable Variable::operator/(int i) {
    StomachLang::cpu.add(address);

    if (StomachLang::cpu.getAccumulatorDataType() == "INT")
        return Variable(
            StomachLang::cpu.getAccumulatorDataType(),
            std::to_string(
                std::stoi(StomachLang::cpu.getAccumulatorDataValue()) / i
            )
        );

    std::cout << "\n\033[31mCannot add "
              << StomachLang::cpu.getAccumulatorDataType()
              << " and INT\033[0m";

    return *this;
}

Variable Variable::operator%(int i) {
    StomachLang::cpu.add(address);

    if (StomachLang::cpu.getAccumulatorDataType() == "INT")
        return Variable(
            StomachLang::cpu.getAccumulatorDataType(),
            std::to_string(
                std::stoi(StomachLang::cpu.getAccumulatorDataValue()) % i
            )
        );

    std::cout << "\n\033[31mCannot add "
              << StomachLang::cpu.getAccumulatorDataType()
              << " and INT\033[0m";

    return *this;
}


// =========================
// Variable + string ops
// =========================

Variable Variable::operator+(const char* value) {
    StomachLang::cpu.add(address);

    if (StomachLang::cpu.getAccumulatorDataType() == "String")
        return Variable(
            StomachLang::cpu.getAccumulatorDataType(),
            StomachLang::cpu.getAccumulatorDataValue() + value
        );

    std::cout << "\n\033[31mCannot add "
              << StomachLang::cpu.getAccumulatorDataType()
              << " and String\033[0m";

    return *this;
}
