//
// Created by maxy2 on 4/25/2026.
//

#ifndef NEWSTOMACHLANGAUGE_CPU_H
#define NEWSTOMACHLANGAUGE_CPU_H

#include "Memory.h"
#include <string>
#include "Variable.h"
#include "Data.h"


class CPU {
private:
    Memory* memory;   // pointer to memory so it knows where to reference from
    Data accumulator;

    // std::string decodeDataValue(std::string value);
    // std::string decodeDataType(std::string value);

public:
    CPU(Memory* mem);

    void load(int address);
    void store(int address);

    // =========================
    // Accumulator access
    // =========================

    std::string getAccumulatorDataType();
    std::string getAccumulatorDataValue();

    // =========================
    // Core operations
    // =========================

    void add(Data d);

    void add(int address);
    void add(int address, int address2);

    void sub(int address, int address2);
    void multiply(int address, int address2);
    void divide(int address, int address2);
    void modulo(int address, int address2);

    // =========================
    // Generic operation system
    // =========================

    template<typename T>
    void operation(int address, int address2, T op, std::string opName);

    // =========================
    // Misc
    // =========================

    void DEVELOPER_Print();
};

#endif //NEWSTOMACHLANGAUGE_CPU_H