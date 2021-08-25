#include <iostream>
#include <fstream>
#include <vector>
#include "item.h"
#include "functions.h"

//Function to write to a file, creating completely new list
int writeToFile() {
    int num;
    int tempNum;
    std::string filename;
    std::string tempName;
    Item tempItem;

    //Prompt for filename and open writing file
    std::cout << "Please enter the file name you would like to work with." << std::endl;
    std::cout << "If the file does not exist, it will be created in the directory and allowed to be written in." << std::endl;
    std::cout << "File name: ";

    std::cin >> filename;

    std::ofstream writer(filename);

    //Gain number of items to enter and initialize list
    std::cout << "Enter in the number of items you would like to add: ";
    std::cin >> num;

    std::vector<Item> myList;

    //For loop to add items to list
    for (int i = 0; i < num; ++i) {
        std::cout << "Enter the name of the item you want to add: ";
        std::cin.ignore();
        std::getline(std::cin, tempName);
        std::cin.clear();

        tempItem.setName(tempName);

        std::cout << "What importance is it? ";
        std::cin >> tempNum;

        tempItem.setImportance(tempNum);

        myList.push_back(tempItem);

        sortList(myList, i+1);
    }

    //For loop to add items to file
    for (int i = 0; i < num; ++i) {
        writer << myList[i].getImportance();
        writer << ". ";
        writer << myList[i].getName();
        writer << std::endl;
    }

    writer.close();

    return(0);
}

//Function to read from file only
int readToFile() {
    int num = 0;
    int tempImp;
    std::string filename;
    std::string dummy;
    std::string tempName;
    Item tempItem;

    //Prompt user for filename and get amount of items in the list to initalize list
    std::cout << "Please enter the file name you would like to work with: ";
    std::cin >> filename;

    std::ifstream readFile(filename);

    if (readFile.is_open() == false) {
        return(-1);
    }

    while (std::getline(readFile, dummy)) {
        ++num;
    }

    std::vector<Item> myList;

    readFile.clear();
    readFile.seekg(0);

    //Read from file into list
    for (int i = 0; i < num; ++i) {
        readFile >> tempImp;
        tempItem.setImportance(tempImp);

        readFile.ignore();
        readFile.ignore();

        std::getline(readFile, tempName);
        tempItem.setName(tempName);

        myList.push_back(tempItem);
    }

    //Display list of items sorted to the user
    sortList(myList, myList.size());
    std::cout << "Your sorted list is:" << std::endl;

    for (int j = 0; j < num; ++j) {
        std::cout << myList.at(j).getImportance() << ". " << myList.at(j).getName() << std::endl;
    }

    readFile.close();

    return(0);
}

//Function to add certain number of items to preexisting list
int addToFile() {
    int num = 0;
    int tempImp;
    int num2;
    int writeOrNo;
    std::string filename;
    std::string dummy;
    std::string tempName;
    Item tempItem;

    //Prompt user for filename and initialize list based on number of preexisting items
    std::cout << "Please enter the file name you would like to work with: ";
    std::cin >> filename;

    std::ifstream readFile(filename);

    if (readFile.is_open() == false) {
        return(-1);
    }

    while (std::getline(readFile, dummy)) {
        ++num;
    }

    std::vector<Item> myList(num);

    readFile.clear();
    readFile.seekg(0);

    //Read file to list
    for (int i = 0; i < num; ++i) {
        readFile >> tempImp;
        myList.at(i).setImportance(tempImp);

        readFile.ignore();
        readFile.ignore();

        std::getline(readFile, tempName);
        myList.at(i).setName(tempName);
    }

    readFile.close();

    //Set number of items to add
    std::cout << "How many items would you like to add? ";
    std::cin >> num2;

    //For loop to add each item
    for (int i = 0; i < num2; ++i) {
        std::cout << "Enter the name of the item you would like to add: ";
        std::cin.ignore();
        std::getline(std::cin, tempName);
        std::cin.clear();
        tempItem.setName(tempName);

        std::cout << "Enter the imporance of the item: ";
        std::cin >> tempImp;
        tempItem.setImportance(tempImp);

        myList.push_back(tempItem);
    }

    sortList(myList, myList.size());

    std::cout << std::endl << "Your new list is: " << std::endl;
    
    //For loop to display new list to user
    for (int i = 0; i < myList.size(); ++i) {
        std::cout << myList.at(i).getImportance() << ". " << myList.at(i).getName() << std::endl;
    }

    //Prompt user if they would like to save it back to the file or not
    std::cout << "Would you like to save this to the file? 0 for yes 1 for no: ";
    std::cin >> writeOrNo;

    if (writeOrNo == 0) {
        std::ofstream writeFile(filename);

        for (int i = 0; i < myList.size(); ++i) {
            writeFile << myList.at(i).getImportance() << ". " << myList.at(i).getName() << std::endl;
        }

        writeFile.close();

        std::cout << "Writing done." << std::endl;
    }

    return(0);
}

//Function to remove a certain amount of items from the preexisting file
int removeToFile() {
    int num = 0;
    int num2;
    int tempImp;
    int op;
    std::string filename;
    std::string dummy;
    std::string tempName;

    //Prompt for filename and initalize and create list
    std::cout << "Please enter the file name you would like to work with: ";
    std::cin >> filename;

    std::ifstream readFile(filename);

    if (readFile.is_open() == false) {
        return(-1);
    }

    while (std::getline(readFile, dummy)) {
        ++num;
    }

    std::vector<Item> myList(num);

    readFile.clear();
    readFile.seekg(0);
    
    //Read list from file
    for (int i = 0; i < num; ++i) {
        readFile >> tempImp;
        myList.at(i).setImportance(tempImp);

        readFile.ignore();
        readFile.ignore();

        std::getline(readFile, tempName);
        myList.at(i).setName(tempName);
    }

    readFile.close();

    std::cout << "Here is your list:" << std::endl;

    //Display current list
    for (int i = 0; i < num; ++i) {
        std::cout << myList.at(i).getImportance() << ". " << myList.at(i).getName() << std::endl;
    }

    //Prompt for number of items to remove
    std::cout << "How many items would you like to take away?" << std::endl;
    std::cin >> num2;

    //For loop to remove each item at a time
    for (int i = 0; i < num2; ++i) {
        std::cout << "Enter the name of the item you would like to delete: ";
        std::cin.ignore();
        std::getline(std::cin, tempName);
        std::cin.clear();

        //For loop to compare each element to find the name that matches the one entered
        for (int j = 0; j < myList.size(); ++j) {
            if (myList.at(j).getName().compare(tempName) == 0) {
                myList.erase(myList.begin() + j);

                break;
            }

            if (j == myList.size() - 1) {
                std::cout << "Uh oh, it wasn't found!" << std::endl;
            }
        }
    }

    sortList(myList, myList.size());

    //Prompt user if they would like to save back to the file
    std::cout << "All items removed successfully. Save back to file? 0 for yes 1 for no: ";
    std::cin >> op;

    if (op == 0) {
        std::ofstream writeFile(filename);

        for (int i = 0; i < myList.size(); ++i) {
            writeFile << myList.at(i).getImportance() << ". " << myList.at(i).getName() << std::endl;
        }

        writeFile.close();

        std::cout << "Saved." << std::endl;
    }

    return(0);
}

//Sort list function based on bubble algorithm
void sortList(std::vector<Item> &myList, int num) {
    Item temp;

    for (int j = 0; j < num - 1; ++j) {
        for (int h = 0; h < num - j - 1; ++h) {
            if (myList.at(h).getImportance() > myList.at(h+1).getImportance()) {
                temp = myList.at(h);
                myList.at(h) = myList.at(h+1);
                myList.at(h+1) = temp;
            }
        }
    }
}