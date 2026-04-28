//
// Created by maxy2 on 4/25/2026.
//

#include "Edible.h"

Edible::Edible(): Variable() {
    // dataType = "Bool";
    // dataValue = "NUll";
    storeInMemory("Bool","NUll");
}

Edible::Edible(bool value) {
    // dataType = "Bool";
    // dataValue = (value ? "true" : "false");
    storeInMemory("Bool",(value ? "true" : "false"));
}

void Edible::operator=(bool value) {
    // dataValue = (value ? "true" : "false");
    storeInMemory("Bool",(value ? "true" : "false"));
}