//
// Created by maxy2 on 4/25/2026.
//

#include "Calorie.h"
#include <string>

#include "StomachLang.h"


Calorie::Calorie() : Variable() {
    storeInMemory(Data{"INT", "NULL"});
}

Calorie::Calorie(int value) {
    storeInMemory(Data{"INT", std::to_string(value)});
}

Calorie::Calorie(Variable variable) {
    storeInMemory(address, variable.getAddress());
}

void Calorie::operator=(int Calories) {
    storeInMemory(Data{"INT", std::to_string(Calories)});
}

Calorie& Calorie::operator=(Variable var2) {
    storeInMemory(address, var2.getAddress());
    return *this;
}


// =========================
// Calorie + operations
// =========================

Variable Calorie::operator+(int b) {
    StomachLang::cpu.add(address);

    if (StomachLang::cpu.getAccumulatorDataType() == "INT")
        return Variable(
            StomachLang::cpu.getAccumulatorDataType(),
            std::to_string(std::stoi(StomachLang::cpu.getAccumulatorDataValue()) + b)
        );

    std::cout << "\n\033[31mNot a valid \"+\" Operation\033[0m";
    return *this;
}

Variable Calorie::operator+(Calorie c) {
    StomachLang::cpu.add(address);

    if (StomachLang::cpu.getAccumulatorDataType() == "INT")
        StomachLang::cpu.add(address, c.getAddress());

    return Variable(
        StomachLang::cpu.getAccumulatorDataType(),
        StomachLang::cpu.getAccumulatorDataValue()
    );

    std::cout << "\n\033[31mNot a valid \"+\" Operation\033[0m";
    return *this;
}

Variable operator+(int b, Calorie &a) {
    StomachLang::cpu.add(a.getAddress());

    return Variable(
        StomachLang::cpu.getAccumulatorDataType(),
        std::to_string(std::stoi(StomachLang::cpu.getAccumulatorDataValue()) + b)
    );
}


// =========================
// Calorie - operations
// =========================

Variable Calorie::operator-(int b) {
    StomachLang::cpu.add(address);

    if (StomachLang::cpu.getAccumulatorDataType() == "INT")
        return Variable(
            StomachLang::cpu.getAccumulatorDataType(),
            std::to_string(std::stoi(StomachLang::cpu.getAccumulatorDataValue()) - b)
        );

    std::cout << "\n\033[31mNot a valid \"+\" Operation\033[0m";
    return *this;
}

Variable Calorie::operator-(Calorie c) {
    StomachLang::cpu.add(address);

    if (StomachLang::cpu.getAccumulatorDataType() == "INT")
        StomachLang::cpu.sub(address, c.getAddress());

    return Variable(
        StomachLang::cpu.getAccumulatorDataType(),
        StomachLang::cpu.getAccumulatorDataValue()
    );

    std::cout << "\n\033[31mNot a valid \"+\" Operation\033[0m";
    return *this;
}

Variable operator-(int b, Calorie &a) {
    StomachLang::cpu.add(a.getAddress());

    return Variable(
        StomachLang::cpu.getAccumulatorDataType(),
        std::to_string(b - std::stoi(StomachLang::cpu.getAccumulatorDataValue()))
    );
}


// =========================
// Calorie * operations
// =========================

Variable Calorie::operator*(int b) {
    StomachLang::cpu.add(address);

    if (StomachLang::cpu.getAccumulatorDataType() == "INT")
        return Variable(
            StomachLang::cpu.getAccumulatorDataType(),
            std::to_string(std::stoi(StomachLang::cpu.getAccumulatorDataValue()) * b)
        );

    std::cout << "\n\033[31mNot a valid \"*\" Operation\033[0m";
    return *this;
}

Variable Calorie::operator*(Calorie c) {
    StomachLang::cpu.add(address);

    if (StomachLang::cpu.getAccumulatorDataType() == "INT")
        StomachLang::cpu.multiply(address, c.getAddress());

    return Variable(
        StomachLang::cpu.getAccumulatorDataType(),
        StomachLang::cpu.getAccumulatorDataValue()
    );

    std::cout << "\n\033[31mNot a valid \"+\" Operation\033[0m";
    return *this;
}

Variable operator*(int b, Calorie &a) {
    StomachLang::cpu.add(a.getAddress());

    return Variable(
        StomachLang::cpu.getAccumulatorDataType(),
        std::to_string(b * std::stoi(StomachLang::cpu.getAccumulatorDataValue()))
    );
}


// =========================
// Calorie / operations
// =========================

Variable Calorie::operator/(int b) {
    StomachLang::cpu.add(address);

    if (StomachLang::cpu.getAccumulatorDataType() == "INT")
        return Variable(
            StomachLang::cpu.getAccumulatorDataType(),
            std::to_string(std::stoi(StomachLang::cpu.getAccumulatorDataValue()) / b)
        );

    std::cout << "\n\033[31mNot a valid \"/\" Operation\033[0m";
    return *this;
}

Variable Calorie::operator/(Calorie c) {
    StomachLang::cpu.add(address);

    if (StomachLang::cpu.getAccumulatorDataType() == "INT")
        StomachLang::cpu.divide(address, c.getAddress());

    return Variable(
        StomachLang::cpu.getAccumulatorDataType(),
        StomachLang::cpu.getAccumulatorDataValue()
    );

    std::cout << "\n\033[31mNot a valid \"+\" Operation\033[0m";
    return *this;
}

Variable operator/(int b, Calorie &a) {
    StomachLang::cpu.add(a.getAddress());

    return Variable(
        StomachLang::cpu.getAccumulatorDataType(),
        std::to_string(b / std::stoi(StomachLang::cpu.getAccumulatorDataValue()))
    );
}


// =========================
// Calorie % operations
// =========================

Variable Calorie::operator%(int b) {
    StomachLang::cpu.add(address);

    if (StomachLang::cpu.getAccumulatorDataType() == "INT")
        return Variable(
            StomachLang::cpu.getAccumulatorDataType(),
            std::to_string(std::stoi(StomachLang::cpu.getAccumulatorDataValue()) % b)
        );

    std::cout << "\n\033[31mNot a valid \"%\" Operation\033[0m";
    return *this;
}

Variable Calorie::operator%(Calorie c) {
    StomachLang::cpu.add(address);

    if (StomachLang::cpu.getAccumulatorDataType() == "INT")
        StomachLang::cpu.modulo(address, c.getAddress());

    return Variable(
        StomachLang::cpu.getAccumulatorDataType(),
        StomachLang::cpu.getAccumulatorDataValue()
    );

    std::cout << "\n\033[31mNot a valid \"+\" Operation\033[0m";
    return *this;
}

Variable operator%(int b, Calorie &a) {
    StomachLang::cpu.add(a.getAddress());

    return Variable(
        StomachLang::cpu.getAccumulatorDataType(),
        std::to_string(b % std::stoi(StomachLang::cpu.getAccumulatorDataValue()))
    );
}


// =========================
// Variable + Calorie ops
// =========================

Variable operator+(Variable b, Calorie &a) {
    StomachLang::cpu.add(b.getAddress());

    if (StomachLang::cpu.getAccumulatorDataType() == "INT")
        StomachLang::cpu.add(b.getAddress(), a.getAddress());

    return Variable(
        StomachLang::cpu.getAccumulatorDataType(),
        StomachLang::cpu.getAccumulatorDataValue()
    );
}

Variable operator-(Variable b, Calorie &a) {
    StomachLang::cpu.add(b.getAddress());

    if (StomachLang::cpu.getAccumulatorDataType() == "INT")
        StomachLang::cpu.sub(b.getAddress(), a.getAddress());

    return Variable(
        StomachLang::cpu.getAccumulatorDataType(),
        StomachLang::cpu.getAccumulatorDataValue()
    );
}

Variable operator*(Variable b, Calorie &a) {
    StomachLang::cpu.add(b.getAddress());

    if (StomachLang::cpu.getAccumulatorDataType() == "INT")
        StomachLang::cpu.multiply(b.getAddress(), a.getAddress());

    return Variable(
        StomachLang::cpu.getAccumulatorDataType(),
        StomachLang::cpu.getAccumulatorDataValue()
    );
}

Variable operator/(Variable b, Calorie &a) {
    StomachLang::cpu.add(b.getAddress());

    if (StomachLang::cpu.getAccumulatorDataType() == "INT")
        StomachLang::cpu.divide(b.getAddress(), a.getAddress());

    return Variable(
        StomachLang::cpu.getAccumulatorDataType(),
        StomachLang::cpu.getAccumulatorDataValue()
    );
}

Variable operator%(Variable b, Calorie &a) {
    StomachLang::cpu.add(b.getAddress());

    if (StomachLang::cpu.getAccumulatorDataType() == "INT")
        StomachLang::cpu.modulo(b.getAddress(), a.getAddress());

    return Variable(
        StomachLang::cpu.getAccumulatorDataType(),
        StomachLang::cpu.getAccumulatorDataValue()
    );
}