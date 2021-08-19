#include <iostream>
#include <fstream>
#include <sstream>
#include "item.h"

int writeToFile();
int readToFile();
void sortList(Item[], int);

int main () {
    int choice = 0;

    while (choice != 2) {
        std::cout << "Welcome to the todo list manager program!" << std::endl;
        std::cout << "Would you like to write or read a file? 1 for write, 0 for read, and 2 for exit: ";
        std::cin >> choice;

        switch (choice) {
            case 0:
                readToFile();

                break;
            case 1:
                if (writeToFile() != 0) {
                    std::cout << "Error, file could not be found! Did you spell it right?" << std::endl;
                }
                
                break;
            case 2:
                break;
            default:
                std::cout << "Error, choice made was not an option!" << std::endl;
        }
    }
    
    std::cout << "Don't forget to do these!!" << std::endl;

    return(0);
}

int writeToFile() {
    int num;
    int tempNum;
    std::string filename;
    std::string tempName;

    std::cout << "Please enter the file name you would like to work with." << std::endl;
    std::cout << "If the file does not exist, it will be created in the directory and allowed to be written in." << std::endl;
    std::cout << "File name: ";

    std::cin >> filename;

    std::ofstream writer(filename);

    std::cout << "Enter in the number of items you would like to add: ";
    std::cin >> num;

    Item myList[num];

    for (int i = 0; i < num; ++i) {
        std::cout << "Enter the name of the item you want to add: ";
        std::cin >> tempName;
        std::cin.ignore();

        myList[i].setName(tempName);

        std::cout << "What importance is it? ";
        std::cin >> tempNum;

        myList[i].setImportance(tempNum);

        sortList(myList, i+1);
    }

    for (int i = 0; i < num; ++i) {
        writer << myList[i].getImportance();
        writer << ". ";
        writer << myList[i].getName();
        writer << std::endl;
    }

    writer.close();

    return(0);
}

int readToFile() {
    int num = 0;
    std::string filename;
    std::string dummy;

    std::cout << "Please enter the file name you would like to work with: ";
    std::cin >> filename;

    std::ifstream readFile(filename);

    if (readFile.is_open() == false) {
        return(-1);
    }

    while (std::getline(readFile, dummy)) {
        ++num;
    }

    Item myList[num];

    readFile.clear();
    readFile.seekg(0);

    return(0);
}

void sortList(Item myList[], int num) {
    Item temp;

    for (int j = 0; j < num - 1; ++j) {
        for (int h = 0; h < num - j - 1; ++h) {
            if (myList[h].getImportance() > myList[h+1].getImportance()) {
                temp = myList[h];
                myList[h] = myList[h+1];
                myList[h+1] = temp;
            }
        }
    }
}