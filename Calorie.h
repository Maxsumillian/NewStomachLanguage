//
// Created by maxy2 on 4/25/2026.
//

#ifndef NEWSTOMACHLANGAUGE_CALORIE_H
#define NEWSTOMACHLANGAUGE_CALORIE_H
#include "Variable.h"


class Calorie : public Variable {// The Integer of my langauge type child of Variable
public:
    Calorie();
    Calorie(int value);

    void operator=(int Calories);

};



#endif //NEWSTOMACHLANGAUGE_CALORIE_H
