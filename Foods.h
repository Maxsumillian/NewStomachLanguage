//
// Created by maxy2 on 4/25/2026.
//

#ifndef NEWSTOMACHLANGAUGE_FOODS_H
#define NEWSTOMACHLANGAUGE_FOODS_H

#include "Variable.h"
#include <string>


class Foods : public Variable {

    friend std::ostream& operator<<(std::ostream& lhs, Foods& pie);
    friend std::istream& operator>>(std::istream& in, Foods& pie);

    friend bool operator==(Foods x, Foods y);
    friend bool operator==(Foods x, const char* y);
    friend bool operator==(const char* y, Foods x);

    friend bool operator!=(Foods x, Foods y);
    friend bool operator!=(Foods x, const char* y);
    friend bool operator!=(const char* y, Foods x);

public:
    Foods();
    Foods(const char* value);
    Foods(Variable variable);

    Foods& operator=(const std::string& value);
    Foods& operator=(const char* value);
    Foods& operator=(Variable var2);
};

#endif //NEWSTOMACHLANGAUGE_FOODS_H