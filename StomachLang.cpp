//
// Created by maxy2 on 4/25/2026.
//

#include "StomachLang.h"
#include <iostream>


Memory StomachLang::memory(1080);
CPU StomachLang::cpu(&StomachLang::memory);


// =========================
// Output helpers (poop)
// =========================

std::ostream& StomachLang::poop() {
    return std::cout;
}

std::ostream& StomachLang::poop(std::string& value) {
    return std::cout << value;
}

std::ostream& StomachLang::poop(Variable& value) {
    cpu.add(value.getAddress());
    return std::cout << cpu.getAccumulatorDataValue();
}





// =========================
// Stream operators
// =========================

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

// =========================
// Input helper (eat)
// =========================

std::istream& StomachLang::eat() {
    return std::cin;
}

// =========================
// Input operators
// =========================

std::istream& operator>>(std::istream& in, Foods& food) {
    std::string value;
    in >> value;

    StomachLang::cpu.add(Data{"String", value});
    StomachLang::cpu.store(food.getAddress());

    return in;
}

std::istream& operator>>(std::istream& in, Calorie& calorie) {
    int value;
    in >> value;

    StomachLang::cpu.add(Data{"INT", std::to_string(value)});
    StomachLang::cpu.store(calorie.getAddress());

    return in;
}

std::istream& operator>>(std::istream& in, Edible& edible) {
    bool value;
    in >> value;

    StomachLang::cpu.add(Data{"Bool", (value ? "true" : "false")});
    StomachLang::cpu.store(edible.getAddress());

    return in;
}





// =========================
// Edible comparisons
// =========================

bool operator==(bool y, Edible x) {
    StomachLang::cpu.add(x.getAddress());
    return y == (StomachLang::cpu.getAccumulatorDataValue() == "true");
}

bool operator!=(bool y, Edible x) {
    StomachLang::cpu.add(x.getAddress());
    return y != (StomachLang::cpu.getAccumulatorDataValue() == "true");
}

bool operator==(Edible x, bool y) {
    StomachLang::cpu.add(x.getAddress());
    return (StomachLang::cpu.getAccumulatorDataValue() == "true") == y;
}

bool operator!=(Edible x, bool y) {
    StomachLang::cpu.add(x.getAddress());
    return (StomachLang::cpu.getAccumulatorDataValue() == "true") != y;
}

bool operator&&(Edible x, bool y) {
    StomachLang::cpu.add(x.getAddress());
    return (StomachLang::cpu.getAccumulatorDataValue() == "true") && y;
}

bool operator||(Edible x, bool y) {
    StomachLang::cpu.add(x.getAddress());
    return (StomachLang::cpu.getAccumulatorDataValue() == "true") || y;
}

bool operator&&(bool y, Edible x) {
    StomachLang::cpu.add(x.getAddress());
    return (StomachLang::cpu.getAccumulatorDataValue() == "true") && y;
}

bool operator||(bool y, Edible x) {
    StomachLang::cpu.add(x.getAddress());
    return (StomachLang::cpu.getAccumulatorDataValue() == "true") || y;
}



// =========================
// Calorie comparisons
// =========================

bool operator>(Calorie x, Calorie y) {
    StomachLang::cpu.add(x.getAddress());
    int xVal = std::stoi(StomachLang::cpu.getAccumulatorDataValue());

    StomachLang::cpu.add(y.getAddress());
    int yVal = std::stoi(StomachLang::cpu.getAccumulatorDataValue());

    return xVal > yVal;
}

bool operator>=(Calorie x, Calorie y) {
    StomachLang::cpu.add(x.getAddress());
    int xVal = std::stoi(StomachLang::cpu.getAccumulatorDataValue());

    StomachLang::cpu.add(y.getAddress());
    int yVal = std::stoi(StomachLang::cpu.getAccumulatorDataValue());

    return xVal >= yVal;
}

bool operator==(Calorie x, Calorie y) {
    StomachLang::cpu.add(x.getAddress());
    int xVal = std::stoi(StomachLang::cpu.getAccumulatorDataValue());

    StomachLang::cpu.add(y.getAddress());
    int yVal = std::stoi(StomachLang::cpu.getAccumulatorDataValue());

    return xVal == yVal;
}

bool operator<=(Calorie x, Calorie y) {
    StomachLang::cpu.add(x.getAddress());
    int xVal = std::stoi(StomachLang::cpu.getAccumulatorDataValue());

    StomachLang::cpu.add(y.getAddress());
    int yVal = std::stoi(StomachLang::cpu.getAccumulatorDataValue());

    return xVal <= yVal;
}

bool operator<(Calorie x, Calorie y) {
     StomachLang::cpu.add(x.getAddress());

    if (StomachLang::cpu.getAccumulatorDataType() != "INT") {
        std::cout << "Type error in < comparison (x)\n";
        return false;
    }

    int xVal = std::stoi(StomachLang::cpu.getAccumulatorDataValue());

    StomachLang::cpu.add(y.getAddress());

    if (StomachLang::cpu.getAccumulatorDataType() != "INT") {
        std::cout << "Type error in < comparison (y)\n";
        return false;
    }

    int yVal = std::stoi(StomachLang::cpu.getAccumulatorDataValue());

    return xVal < yVal;
}

bool operator!=(Calorie x, Calorie y) {
    StomachLang::cpu.add(x.getAddress());
    int xVal = std::stoi(StomachLang::cpu.getAccumulatorDataValue());

    StomachLang::cpu.add(y.getAddress());
    int yVal = std::stoi(StomachLang::cpu.getAccumulatorDataValue());

    return xVal != yVal;
}


// =========================
// Foods comparisons
// ========================

bool operator==(Foods x, Foods y) {
    StomachLang::cpu.add(x.getAddress());
    std::string xVal = StomachLang::cpu.getAccumulatorDataValue();

    StomachLang::cpu.add(y.getAddress());
    std::string yVal = StomachLang::cpu.getAccumulatorDataValue();

    return xVal == yVal;
}

bool operator==(Foods x, const char* y) {
    StomachLang::cpu.add(x.getAddress());
    std::string xVal = StomachLang::cpu.getAccumulatorDataValue();

    return xVal == std::string(y);
}

bool operator==(const char* y, Foods x) {
    StomachLang::cpu.add(x.getAddress());
    std::string xVal = StomachLang::cpu.getAccumulatorDataValue();

    return std::string(y) == xVal;
}

bool operator!=(Foods x, Foods y) {
    StomachLang::cpu.add(x.getAddress());
    std::string xVal = StomachLang::cpu.getAccumulatorDataValue();

    StomachLang::cpu.add(y.getAddress());
    std::string yVal = StomachLang::cpu.getAccumulatorDataValue();

    return xVal != yVal;
}

bool operator!=(Foods x, const char* y) {
    StomachLang::cpu.add(x.getAddress());
    std::string xVal = StomachLang::cpu.getAccumulatorDataValue();

    return xVal != std::string(y);
}

bool operator!=(const char* y, Foods x) {
    StomachLang::cpu.add(x.getAddress());
    std::string xVal = StomachLang::cpu.getAccumulatorDataValue();

    return std::string(y) != xVal;
}

// =========================
// int + Variable ops
// chat gpt helped me make a Template Helper for these overloaded funcions
// =========================

Variable operator+(int b, const Variable& a) {
    StomachLang::cpu.applyIntOp(b,a.address,[](int x, int y) { return x + y; });
    return Variable(StomachLang::cpu.getAccumulatorDataType(), StomachLang::cpu.getAccumulatorDataValue());
}

Variable operator-(int b, const Variable& a) {
    StomachLang::cpu.applyIntOp(b,a.address,[](int x, int y) { return x - y; });
    return Variable(StomachLang::cpu.getAccumulatorDataType(), StomachLang::cpu.getAccumulatorDataValue());
}

Variable operator*(int b, const Variable& a) {
    StomachLang::cpu.applyIntOp(b,a.address,[](int x, int y) { return x * y; });
    return Variable(StomachLang::cpu.getAccumulatorDataType(), StomachLang::cpu.getAccumulatorDataValue());
}

Variable operator/(int b, const Variable& a) {
    StomachLang::cpu.applyIntOp(b,a.address,[](int x, int y) { return x / y; });
    return Variable(StomachLang::cpu.getAccumulatorDataType(), StomachLang::cpu.getAccumulatorDataValue());
}

Variable operator%(int b, const Variable& a) {
    StomachLang::cpu.applyIntOp(b,a.address,[](int x, int y) { return x % y; });
    return Variable(StomachLang::cpu.getAccumulatorDataType(), StomachLang::cpu.getAccumulatorDataValue());
}


// template<typename Op>
// Variable applyIntOp(int b, const Variable& a, Op operation) {
//     StomachLang::cpu.add(a.address);
//
//     if (StomachLang::cpu.getAccumulatorDataType() == "INT") {
//         int acc = std::stoi(StomachLang::cpu.getAccumulatorDataValue());
//         int result = operation(acc, b);
//
//         return Variable(
//             "INT",
//             std::to_string(result)
//         );
//     }
//
//     std::cout << "\n\033[31mCannot operate on "
//               << StomachLang::cpu.getAccumulatorDataType()
//               << " and INT\033[0m";
//
//     return Variable();
// }