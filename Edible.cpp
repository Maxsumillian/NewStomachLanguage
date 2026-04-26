//
// Created by maxy2 on 4/25/2026.
//

#include "Edible.h"

Edible::Edible(): Variable() {
    dataType = "Bool";
    dataValue = "NUll";
    storeInMemory();
}

void Edible::operator=(bool Edible) {

    if (Edible) {
        dataValue = "true";
    }
    else {
        dataValue = "false";
    }
    storeInMemory();
}