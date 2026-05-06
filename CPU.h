//
// Created by maxy2 on 4/25/2026.
//

#ifndef NEWSTOMACHLANGAUGE_CPU_H
#define NEWSTOMACHLANGAUGE_CPU_H

#include "Memory.h"
#include <string>
#include "Variable.h"
#include "Data.h"
#include <iostream>

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

    template<typename Op>
    // When debugging with ChatGPT I found that this has to be in the header.
    // It says templates aren’t fully defined functions, so it breaks if the compiler
    // can’t see the full definition when it instantiates them.
    //
    // This is not about calling it outside a function—templates must be fully visible
    // wherever they are used so the compiler can generate the correct version.
    // Other non-template functions work fine in .cpp files because they are fully compiled once.
    void applyIntOp(int b, int address, Op operation) {
            add(address);

            if (accumulator.type == "INT") {
                int acc = std::stoi(accumulator.value);
                int result = operation(acc, b);

                accumulator = Data{
                    "INT",
                    std::to_string(result)
                    };
            }else {
                std::cout << "\n\033[31mCannot operate on "
                      << accumulator.type
                      << " and INT\033[0m";
            }
    }

    // Note: This is another template function But it's declared in the header and defined in the .cpp,
    // and it works there. The difference is that it is not being instantiated with a lambda
    // type like this one, so it doesn’t trigger the same compile-time generation requirement.
    template<typename T>
    void operation(int address, int address2, T op, std::string opName);

    // =========================
    // Misc
    // =========================

    void DEVELOPER_Print();
};

#endif //NEWSTOMACHLANGAUGE_CPU_H