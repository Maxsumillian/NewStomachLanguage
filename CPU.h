//
// Created by maxy2 on 4/25/2026.
//

#ifndef NEWSTOMACHLANGAUGE_CPU_H
#define NEWSTOMACHLANGAUGE_CPU_H

#include "Memory.h"
#include <string>
#include "Variable.h"

class CPU {
private:
    Memory* memory;  // pointer to memory so it knows where to reference from
    std::string accumulator;

    std::string decodeDataValue(std::string value);//I only want the cpu to be able to run this so its private
    std::string decodeDataType(std::string value);

public:
    CPU(Memory* mem);// uses a pointer/refrence for memory

    void load(int address);// loads into accumulator

    void store(int address);// takes accumulator value and stores it at location

    // std::string getAccumulator();
    std::string getAccumulatorDataType();
    std::string getAccumulatorDataValue();
//===================================================================
    void add(std::string value);// single input adds variable type and puts into accumulator doubles as a set accumulator function
    // void add(std::string value, std::string value2);// so instead of strings here i use addresses then load from memory and then I do the caculations

    // void sub(std::string value, std::string value2);
//===================================================================
    void add(int address);
    void add(int address, int address2);

    void sub(int address, int address2);


    // void add(Variable var1, Variable var2);// double input takes two and tries to add them together
    //
    Variable createVariable();

    void DEVELOPER_Print();

};



#endif //NEWSTOMACHLANGAUGE_CPU_H
