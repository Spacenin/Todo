#ifndef ITEM_H
#define ITEM_H
#include <sstream>
#include <iostream>
#include <fstream>

class Item {
    private:
        std::string name;
        int importance;
    
    public:
        Item();
        Item(std::string, int);

        void setName(std::string);
        void setImportance(int);

        std::string getName();
        int getImportance();
};

#endif