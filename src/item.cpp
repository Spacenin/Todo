#include <iostream>
#include <fstream>
#include <sstream>
#include "item.h"

Item::Item() {
    name = "NULL";
    importance = 0;
}

Item::Item(std::string s, int i) {
    name = s;
}

void Item::setImportance(int i) {
    importance = i;
}

void Item::setName(std::string s) {
    name = s;
}

std::string Item::getName() {
    return(name);
}

int Item::getImportance() {
    return(importance);
}