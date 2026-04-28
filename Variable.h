//
// Created by maxy2 on 4/25/2026.
//

#ifndef NEWSTOMACHLANGAUGE_VARIABLE_H
#define NEWSTOMACHLANGAUGE_VARIABLE_H

#include <string>

class Variable{// Father of all Variable Types in my Coding langauge
protected:
    std::string name;
    std::string dataType = "dataType";
    std::string dataValue = "dataValue";
    int address;// right now address is garbage I need to have a counter that increments the size as my variable numbers grow
    inline static int maxAddress = 0;

public:
    Variable();

    int getAddress();
    void printTest();

    std::string getType();
    std::string getValue();

    virtual void storeInMemory();

    virtual void operator+(Variable var2);

    virtual void operator-(Variable var2);

    virtual void operator=(Variable var2);

    // void operator=(int Calories);
    // void operator=(bool Edible);
    // void operator=(std::string Foods);

};



#endif //NEWSTOMACHLANGAUGE_VARIABLE_H
