#include <iostream>

#include "Edible.h"
#include "StomachLang.h"

int main() {


    Variable test;// creates empty space in memory // Parent Class of all variable class

    Calorie test2;// test for ints
    Foods test3;// test for strings
    Edible test4;// test for boolean

    Edible test5 = false;// requires constructor
    Foods test6 = "test String";
    Calorie test7 = 321;
    Calorie test8(213);



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

    //since its from cpu it returns the encoded values
    //prints out what's stored in my virtual memory
    // StomachLang::cpu.load(1);


    // StomachLang::cpu.DEVELOPER_Print();
    //
    // StomachLang::cpu.load(2);
    // StomachLang::cpu.DEVELOPER_Print();
    //
    // StomachLang::cpu.load(3);
    // StomachLang::cpu.DEVELOPER_Print();
    //
    // StomachLang::cpu.load(4);
    // StomachLang::cpu.DEVELOPER_Print();
    //
    // StomachLang::cpu.load(5);
    // StomachLang::cpu.DEVELOPER_Print();
    //
    // StomachLang::cpu.load(6);
    // StomachLang::cpu.DEVELOPER_Print();
    //
    // StomachLang::cpu.load(7);
    // StomachLang::cpu.DEVELOPER_Print();
    //
    // std::cout << std::endl << "Test Addition:";
    // test2 + test2;
    // StomachLang::cpu.DEVELOPER_Print();
    //
    // test + test2;
    // StomachLang::cpu.DEVELOPER_Print();
    //
    // test3 + test6;
    // StomachLang::cpu.DEVELOPER_Print();
    //
    //
    // test3 - test6;
    // StomachLang::cpu.DEVELOPER_Print();

    // test8 = test8 - test2;
    test2 + test2 + test2;// chaining aquired!
    StomachLang::cpu.DEVELOPER_Print();

    std::cout <<std::endl;
    StomachLang::poop(test2);// returns 123

    test2 = test2 + test2;// Yay i got it working!
    StomachLang::cpu.DEVELOPER_Print();

    std::cout <<std::endl;
    StomachLang::poop(test2); // returns 246


    test6 = test6 + test6;// nice i got strings working!
    StomachLang::cpu.DEVELOPER_Print();

    Calorie applePie = 100;
    Calorie milkShake = 50;
    Calorie peachPie = applePie + milkShake;// currently doesnt work...
    //EDIT: works now! need to create a construcor to take in Variables

    int one = 1;
    int two = 2;
    int myint = one + two;

    // test8 - test2;
    // StomachLang::cpu.DEVELOPER_Print();

    // StomachLang::poop(test2 - test8);// simple display for now

    //I didnt know you can add bools in c++
    // std::cout << true + false;//. funny implementation is to turn the value of bool into a int of either 0 or 1 for cases when adding to ints
    // std::cout << false + false;
    // std::cout << true + true + 100;
    // std::cout << true + 100;



    // StomachLang::memoryToType(test2);
    // StomachLang::memoryToType(test3);
    // StomachLang::memoryToType(test4);
    //
    // StomachLang::poop(test2);

    // std::cout<<test2;// uses the overloaded funcitons in my langauge class for output
    // std::cout<<test3;// will potentially not need in the future
    // std::cout<<test4;

    return 0;
}