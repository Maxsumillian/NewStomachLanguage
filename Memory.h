//
// Created by maxy2 on 4/25/2026.
//

#ifndef NEWSTOMACHLANGAUGE_MEMORY_H
#define NEWSTOMACHLANGAUGE_MEMORY_H

#include <vector>
#include <string>
#include "Data.h"

// use Vector first then upgrade to map

class Memory {
private:
    std::vector<Data> memory;

public:
    Memory(int size);

    Data read(int address);
    void write(int address, Data value);
};

#endif //NEWSTOMACHLANGAUGE_MEMORY_H