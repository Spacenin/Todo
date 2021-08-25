#ifndef ITEM_H
#define ITEM_H

//Class template for item, containing importance and the name
class Item {
    private:
        std::string name;
        int importance;
    
    public:
        //Constructors
        Item();
        Item(std::string, int);

        //Setters   
        void setName(std::string);
        void setImportance(int);
        
        //Getters
        std::string getName();
        int getImportance();
};

#endif