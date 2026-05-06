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
    StomachLang::cpu.compare(x.getAddress(),y, "==");
    return StomachLang::cpu.getAccumulatorDataValue() == "true";
}

bool operator!=(bool y, Edible x) {
    StomachLang::cpu.compare(x.getAddress(),y, "!=");
    return StomachLang::cpu.getAccumulatorDataValue() == "true";
}

bool operator==(Edible x, bool y) {
    StomachLang::cpu.compare(x.getAddress(),y, "==");
    return StomachLang::cpu.getAccumulatorDataValue() == "true";
}

bool operator!=(Edible x, bool y) {
    StomachLang::cpu.compare(x.getAddress(),y, "!=");
    return StomachLang::cpu.getAccumulatorDataValue() == "true";
}

bool operator&&(Edible x, bool y) {
    StomachLang::cpu.compare(x.getAddress(),y, "&&");
    return StomachLang::cpu.getAccumulatorDataValue() == "true";
}

bool operator||(Edible x, bool y) {
    StomachLang::cpu.compare(x.getAddress(),y, "||");
    return StomachLang::cpu.getAccumulatorDataValue() == "true";
}

bool operator&&(bool y, Edible x) {
    StomachLang::cpu.compare(x.getAddress(),y, "&&");
    return StomachLang::cpu.getAccumulatorDataValue() == "true";
}

bool operator||(bool y, Edible x) {
    StomachLang::cpu.compare(x.getAddress(),y, "||");
    return StomachLang::cpu.getAccumulatorDataValue() == "true";
}



// =========================
// Calorie comparisons
// =========================

// int getCalorieValue(Calorie& c) {
//     StomachLang::cpu.add(c.getAddress());
//
//     if (StomachLang::cpu.getAccumulatorDataType() != "INT") {
//         std::cout << "Type error in Calorie access\n";// added after my boolean problem :p
//         // the story goes
//         // bool num1 = 100;
//         // int num2 = 99;
//         // if(num1 > num2)
//         // COMPILES:
//         // Runtime Error:
//         // Headache...
//         return 0;
//     }
//
//     return std::stoi(StomachLang::cpu.getAccumulatorDataValue());
// }
bool operator>(Calorie x, Calorie y) {
    StomachLang::cpu.compare(x.getAddress(),y.getAddress(), ">");
    return StomachLang::cpu.getAccumulatorDataValue() == "true";
}

bool operator>=(Calorie x, Calorie y) {
    StomachLang::cpu.compare(x.getAddress(),y.getAddress(), ">=");
    return StomachLang::cpu.getAccumulatorDataValue() == "true";
}

bool operator==(Calorie x, Calorie y) {
    StomachLang::cpu.compare(x.getAddress(),y.getAddress(), "==");
    return StomachLang::cpu.getAccumulatorDataValue() == "true";
}

bool operator<=(Calorie x, Calorie y) {
    StomachLang::cpu.compare(x.getAddress(),y.getAddress(), "<=");
    return StomachLang::cpu.getAccumulatorDataValue() == "true";
}

bool operator<(Calorie x, Calorie y) {
    StomachLang::cpu.compare(x.getAddress(),y.getAddress(), "<");
    return StomachLang::cpu.getAccumulatorDataValue() == "true";
}

bool operator!=(Calorie x, Calorie y) {
    StomachLang::cpu.compare(x.getAddress(),y.getAddress(), "!=");
    return StomachLang::cpu.getAccumulatorDataValue() == "true";
}

// =========================
// Foods comparisons
// ========================

//added a central helper function templating this code was not worth it because order implications mess it up meaning i woudld have to make 3 template funcitons
std::string getFoodValue(Foods& f) {
    StomachLang::cpu.add(f.getAddress());
    return StomachLang::cpu.getAccumulatorDataValue();
}

bool operator==(Foods x, Foods y) {
    return getFoodValue(x) == getFoodValue(y);
}

bool operator==(Foods x, const char* y) {
    return getFoodValue(x) == std::string(y);
}

bool operator==(const char* y, Foods x) {
    return std::string(y) == getFoodValue(x);
}

bool operator!=(Foods x, Foods y) {
    return getFoodValue(x) != getFoodValue(y);
}

bool operator!=(Foods x, const char* y) {
    return getFoodValue(x) != std::string(y);
}

bool operator!=(const char* y, Foods x) {
    return std::string(y) != getFoodValue(x);
}
// =========================
// int + Variable ops
// chat-GPT helped me make a Template Helper for these overloaded funcions
// beacuse this is the specific case of ints plus Varibles its consistent and a template is useable here
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