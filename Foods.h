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
        // Foods(std::string text);//kina dumb this doesn't work :(
        Foods(const char* value);

        // void operator=(std::string foods); doesnt work anymore beacuse of the char
        Foods& operator=(const std::string& value);
        Foods& operator=(const char* value);

        Foods& operator=(Variable var2);
};



#endif //NEWSTOMACHLANGAUGE_FOODS_H
