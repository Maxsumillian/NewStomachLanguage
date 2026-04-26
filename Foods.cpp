//
// Created by maxy2 on 4/25/2026.
//

#include "Foods.h"


Foods::Foods(): Variable() {// this calls after parent constructor but it does not place the variable in my virtual memory
    dataType = "String";//when declared it sets its dataType to "INT" so the cpu/Language can decode this to be usable for users
    dataValue = "NUll";// currently no known values (will need to use the assign operator to assign this.)
    storeInMemory();
}

void Foods::operator=(std::string foods) {
    dataValue = foods;
    storeInMemory();
}