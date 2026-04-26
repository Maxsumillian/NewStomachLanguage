//
// Created by maxy2 on 4/25/2026.
//

#ifndef NEWSTOMACHLANGAUGE_MEMORY_H
#define NEWSTOMACHLANGAUGE_MEMORY_H

#include <vector>
#include <string>
//use Vector first then upgrade to map


class Memory {
private:
    std::vector<std::string> memory;

public:
    Memory(int size);

    std::string read(int address);

    void write(int address, std::string value);
};


#endif //NEWSTOMACHLANGAUGE_MEMORY_H
