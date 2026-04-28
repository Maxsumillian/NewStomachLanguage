//
// Created by maxy2 on 4/25/2026.
//

#ifndef NEWSTOMACHLANGAUGE_VARIABLE_H
#define NEWSTOMACHLANGAUGE_VARIABLE_H

#include <string>

class Variable{// Father of all Variable Types in my Coding langauge
protected:
    // std::string name;
    // std::string dataType = "dataType";// actually i need to move this to the memory and only keep the address in my variable Class and refrence my cpu to load and display the values i want will require more testing
    // std::string dataValue = "dataValue";
    int address;// right now address is garbage I need to have a counter that increments the size as my variable numbers grow
    inline static int maxAddress = 0;

public:
    Variable();

    Variable(std::string dataType2, std::string dataValue2);// only used by cpu to create temp variables

    int getAddress();
    void printTest();

    std::string getType();
    std::string getValue();

    virtual void storeInMemory(std::string, std::string);
    virtual void storeInMemory(int address,int address2);

    virtual Variable operator+(Variable var2);// returns a Variable so i can chain them

    virtual void operator-(Variable var2);

    Variable& operator=(Variable var2);//

    // void operator=(int Calories);
    // void operator=(bool Edible);
    // void operator=(std::string Foods);

};



#endif //NEWSTOMACHLANGAUGE_VARIABLE_H
