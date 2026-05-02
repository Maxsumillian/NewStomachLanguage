//
// Created by maxy2 on 4/25/2026.
//

#ifndef NEWSTOMACHLANGAUGE_EDIBLE_H
#define NEWSTOMACHLANGAUGE_EDIBLE_H
#include "Variable.h"


class Edible : public Variable{

    friend bool operator==(bool y, Edible x);
    friend bool operator!=(bool y, Edible x);
    friend bool operator==(Edible x, bool y);
    friend bool operator!=(Edible x, bool y);
    friend bool operator||(Edible x, bool y);
    friend bool operator&&(Edible x, bool y);
    friend bool operator||(bool y, Edible x);
    friend bool operator&&(bool y, Edible x);

    friend std::ostream& operator<<(std::ostream& o, Edible& edible);

public:
    Edible();
    Edible(bool value);

    void operator=(bool edible);
};



#endif //NEWSTOMACHLANGAUGE_EDIBLE_H
