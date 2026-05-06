//
// Created by maxy2 on 4/25/2026.
//

#ifndef NEWSTOMACHLANGAUGE_STOMACHLANG_H
#define NEWSTOMACHLANGAUGE_STOMACHLANG_H

#include <iostream>
#include <string>

#include "CPU.h"
#include "Memory.h"
#include "Calorie.h"
#include "Foods.h"
#include "Edible.h"


class StomachLang {

protected:

public:
    static Memory memory;
    static CPU cpu;

    static void memoryToType(Variable var);

    static void poop(Variable var);

    // stream-style output helpers
    static std::ostream& poop();
    static std::ostream& poop(std::string& value);
    static std::ostream& poop(Variable& value);

    static std::istream& eat();
};

#endif //NEWSTOMACHLANGAUGE_STOMACHLANG_H