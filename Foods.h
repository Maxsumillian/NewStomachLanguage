//
// Created by maxy2 on 4/25/2026.
//

#ifndef NEWSTOMACHLANGAUGE_FOODS_H
#define NEWSTOMACHLANGAUGE_FOODS_H
#include "Variable.h"
#include <string>


class Foods : public Variable{
    public:
        Foods();

        void operator=(std::string foods);
};



#endif //NEWSTOMACHLANGAUGE_FOODS_H
