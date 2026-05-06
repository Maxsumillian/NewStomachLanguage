// Created by maxy2 on 4/25/2026.
//

#include "Foods.h"
#include "StomachLang.h"


Foods::Foods() : Variable() {
    storeInMemory(Data{"String", "NUll"});
}

Foods::Foods(Variable variable) {
    storeInMemory(address, variable.getAddress());
}


// std::string literals are const char*, not std::string

Foods::Foods(const char* value) {
    storeInMemory(Data{"String", value});
}


// =========================
// Assignment operators
// =========================

Foods& Foods::operator=(const std::string& value) {
    storeInMemory(Data{"String", value});
    return *this;
}

Foods& Foods::operator=(const char* value) {
    storeInMemory(Data{"String", value});
    return *this;
}

Foods& Foods::operator=(Variable var2) {
    storeInMemory(address, var2.getAddress());
    return *this;
}
