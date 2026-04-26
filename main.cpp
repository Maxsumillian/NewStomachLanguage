#include <iostream>

#include "Edible.h"
#include "StomachLang.h"

int main() {


    Variable test;// creates empty space in memory // Parent Class of all variable class
    Calorie test2;// test for ints
    Foods test3;// test for strings
    Edible test4;// test for boolean
    Edible test5 = false;// requires constructor


    StomachLang::cpu.load(1);
    StomachLang::cpu.DEVELOPER_Print();

    StomachLang::cpu.load(2);
    StomachLang::cpu.DEVELOPER_Print();

    StomachLang::cpu.load(3);
    StomachLang::cpu.DEVELOPER_Print();

    StomachLang::cpu.load(4);
    StomachLang::cpu.DEVELOPER_Print();
    // std::cout<<"\ntest  address :"<<test.getAddress();
    // std::cout<<"\ntest2 address :"<<test2.getAddress();
    // std::cout<<"\ntest3 address :"<<test3.getAddress();
    // std::cout<<"\ntest4 address :"<<test4.getAddress();

    // test.printTest();
    // test2.printTest();
    // test3.printTest();
    // test4.printTest();

    test2 = 123;// nice this works
    test3 = "Wassup";// this also works!
    test4 = false;

    //prints out what's stored in my virtual memory
    StomachLang::cpu.load(1);
    StomachLang::cpu.DEVELOPER_Print();

    StomachLang::cpu.load(2);
    StomachLang::cpu.DEVELOPER_Print();

    StomachLang::cpu.load(3);
    StomachLang::cpu.DEVELOPER_Print();

    StomachLang::cpu.load(4);
    StomachLang::cpu.DEVELOPER_Print();


    // StomachLang::memoryToType(test2);
    // StomachLang::memoryToType(test3);
    // StomachLang::memoryToType(test4);
    //
    // StomachLang::poop(test2);

    std::cout<<test2;
    std::cout<<test3;
    std::cout<<test4;

    return 0;
}