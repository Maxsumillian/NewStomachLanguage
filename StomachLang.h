//
// Created by maxy2 on 4/25/2026.
//

#ifndef NEWSTOMACHLANGAUGE_STOMACHLANG_H
#define NEWSTOMACHLANGAUGE_STOMACHLANG_H

#include <iostream>
#include <string>
#include "CPU.h"
#include "Memory.h"
// #include "Variable.h"// class for variable will poly-morph to get different types
#include "Calorie.h"
#include "Foods.h"
#include "Edible.h"




class StomachLang {

protected:

public:
    static Memory memory;
    static CPU cpu;


    static void memoryToType(Variable var);//this converts memory encoded data to usable code data EX: string:hi -> "hi" // parser
    //note: with my cpu i can decode the data already this is redundent

    static void poop(Variable var);
    //also note: will proably have to make a new class for ostream maybe instead of this?

    // void eat(Calorie prompt);


};

// overloading the cout operator so i can use them like std::cout<<test2
static std::ostream& operator<<(std::ostream& o, Calorie var)
{
    o<<var.getValue();
    return o;
}

static std::ostream& operator<<(std::ostream& o, Foods var)
{
    o<<var.getValue();
    return o;
}

static std::ostream& operator<<(std::ostream& o, Edible var)
{
    o << (var.getValue() == "1" ? "1" : "0");
    return o;
}





#endif //NEWSTOMACHLANGAUGE_STOMACHLANG_H
