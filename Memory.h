

#ifndef NEWSTOMACHLANGAUGE_MEMORY_H
#define NEWSTOMACHLANGAUGE_MEMORY_H
#include <string>
#include "Data.h"

#include <map>



class Memory {
private:
    std::map<int,Data> memory;
    int maxMemorySize;

public:
    Memory(int size);

    Data read(int address);
    void write(int address, Data value);
};

#endif
