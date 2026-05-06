#ifndef VARIABLE_H
#define VARIABLE_H

#include <string>
#include "Data.h"


class Variable {

    friend Variable operator+(int b, const Variable& a);
    friend Variable operator-(int b, const Variable& a);
    friend Variable operator*(int b, const Variable& a);
    friend Variable operator/(int b, const Variable& a);
    friend Variable operator%(int b, const Variable& a);

    template<typename Op>
    friend Variable applyIntOp(int b, const Variable& a, Op operation);

protected:
    int address;
    static int maxAddress; // NOTE: update this for Dev-C++

public:
    Variable();
    Variable(std::string dataType2, std::string dataValue2); // CPU temp variable

    int getAddress();

    void printTest();

    std::string getType();
    std::string getValue();

    virtual void storeInMemory(Data d);
    virtual void storeInMemory(int address, int address2);

    virtual Variable operator+(Variable var2);
    virtual Variable operator-(Variable var2);

    Variable operator+(int i);
    Variable operator-(int i);
    Variable operator*(int i);
    Variable operator/(int i);
    Variable operator%(int i);

    Variable operator+(const char* value);
};

#endif 
