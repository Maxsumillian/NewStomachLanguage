//
// Created by maxy2 on 4/25/2026.
//

#ifndef NEWSTOMACHLANGAUGE_FOODS_H
#define NEWSTOMACHLANGAUGE_FOODS_H
#include "Variable.h"
#include <string>


class Foods : public Variable{

    friend std::ostream& operator<<(std::ostream& lhs, Foods& pie);
    friend std::istream& operator>>(std::istream& in, Foods& pie);

    public:
        Foods();
        // Foods(std::string text);//kina dumb this doesn't work :(
        Foods(const char* value);
        Foods(Variable variable);

        // void operator=(std::string foods); doesnt work anymore beacuse of the char
        Foods& operator=(const std::string& value);
        Foods& operator=(const char* value);

        Foods& operator=(Variable var2);
};



#endif //NEWSTOMACHLANGAUGE_FOODS_H
