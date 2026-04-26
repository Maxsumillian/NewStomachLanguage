//
// Created by maxy2 on 4/25/2026.
//

#include "Calorie.h"
#include <string>


Calorie::Calorie(): Variable() {// this calls after parent constructor but it does not place the variable in my virtual memory
    dataType = "Int";//when decalred it sets its dataType to "INT" so the cpu/Language can decode this to be usable for users
    dataValue = "NUll";// currently no known values will need to use the assign operator for this.
    storeInMemory();
}

void Calorie::operator=(int Calories) {
    dataValue = std::to_string(Calories);
    storeInMemory();
}