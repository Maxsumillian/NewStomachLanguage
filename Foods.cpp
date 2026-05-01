//
// Created by maxy2 on 4/25/2026.
//

#include "Foods.h"

#include "StomachLang.h"


Foods::Foods(): Variable() {// this calls after parent constructor but it does not place the variable in my virtual memory
    // dataType = "String";//when declared it sets its dataType to "INT" so the cpu/Language can decode this to be usable for users
    // dataValue = "NUll";// currently no known values (will need to use the assign operator to assign this.)
    storeInMemory(Data{"String","NUll"});
}

Foods::Foods(Variable variable) {
    // dataType = "Int";
    // dataValue = variable.getValue();
    storeInMemory(address,variable.getAddress());
}



//this doesnt work beacuse "test String" are actually cosnt cahr* so we need to convert it
// Foods::Foods(std::string text) {
//     dataType = "String";
//     dataValue =  text;
//     storeInMemory();
// }
// so we need to use this sadly
Foods::Foods(const char* value) {
    // dataType = "String";
    // dataValue = value;
    storeInMemory(Data{"String",value});
}


Foods& Foods::operator=(const std::string& value) {
    // dataType = "String";
    // dataValue = value;
    storeInMemory(Data{"String",value});
    return *this;
}

Foods& Foods::operator=(const char* value) {
    // dataType = "String";
    // dataValue = value;
    storeInMemory(Data{"String",value});
    return *this;
}

Foods& Foods::operator=(Variable var2) {
    // dataType = "String";
    // dataValue = var2.getValue();
    storeInMemory(address,var2.getAddress());
    return *this;

}





