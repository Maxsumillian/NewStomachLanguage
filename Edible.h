//
// Created by maxy2 on 4/25/2026.
//

#ifndef NEWSTOMACHLANGAUGE_EDIBLE_H
#define NEWSTOMACHLANGAUGE_EDIBLE_H
#include "Variable.h"


class Edible : public Variable{
public:
    Edible();
    Edible(bool value);

    void operator=(bool edible);
};



#endif //NEWSTOMACHLANGAUGE_EDIBLE_H
