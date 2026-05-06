//
// Created by maxy2 on 4/25/2026.
//

#include "Edible.h"

Edible::Edible(): Variable() {
    storeInMemory(Data{"Bool", "NULL"});
}

Edible::Edible(bool value) {
    storeInMemory(Data{"Bool",(value ? "true" : "false")});
}

void Edible::operator=(bool value) {
    storeInMemory(Data{"Bool",(value ? "true" : "false")});
}