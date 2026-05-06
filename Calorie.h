//
// Created by maxy2 on 4/25/2026.
//

#ifndef CALORIE_H
#define CALORIE_H
#include "Variable.h"


class Calorie : public Variable {// The Integer of my langauge type child of Variable

    friend Variable operator+( int b,Calorie& a);
    friend Variable operator+(Variable v, Calorie& a);
    friend Variable operator*(int b,Calorie& a);
    friend Variable operator*(Variable v, Calorie& a);
    friend Variable operator/(int b,Calorie& a);
    friend Variable operator/(Variable v, Calorie& a);
    friend Variable operator%(int b,Calorie& a);
    friend Variable operator%(Variable v, Calorie& a);
    friend Variable operator-(int b,Calorie& a);
    friend Variable operator-(Variable v, Calorie& a);

    friend bool operator>(Calorie x, Calorie y);
    friend bool operator>=(Calorie x, Calorie y);
    friend bool operator==(Calorie x, Calorie y);
    friend bool operator!=(Calorie x, Calorie y);
    friend bool operator<(Calorie x, Calorie y);
    friend bool operator<=(Calorie x, Calorie y);


    friend std::ostream& operator<<(std::ostream& o, Calorie& calorie);
    friend std::istream& operator>>(std::istream& in, Calorie& calorie);

public:
    Calorie();
    Calorie(int value);
    Calorie(Variable variable);

    void operator=(int Calories);

    Calorie& operator=(Variable var2);//


    Variable operator+(Calorie c);
    Variable operator+(int b);

    Variable operator-(Calorie c);
    Variable operator-(int b);

    Variable operator*(int b);
    Variable operator/(int b);
    Variable operator%(int b);
    Variable operator*(Calorie c);
    Variable operator/(Calorie c);
    Variable operator%(Calorie c);
};



#endif 
