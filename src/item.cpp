#include <iostream>
#include <fstream>
#include "item.h"

//Constructors defined
Item::Item() {
    name = "NULL";
    importance = 0;
}

Item::Item(std::string s, int i) {
    name = s;
}

//Setters defined
void Item::setImportance(int i) {
    importance = i;
}

void Item::setName(std::string s) {
    name = s;
}

//Getters defined
std::string Item::getName() {
    return(name);
}

int Item::getImportance() {
    return(importance);
}