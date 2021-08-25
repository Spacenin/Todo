#ifndef FUNCTIONS_H
#define FUNCTIONS_H
#include <vector>

//Functions to work with the file and list
int writeToFile();
int readToFile();
int addToFile();
int removeToFile();
void sortList(std::vector<Item> &, int);

#endif