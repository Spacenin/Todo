#include <iostream>
#include <fstream>
#include "item.h"
#include "functions.h"

int main () {
    int choice = 0;

    //Display menu and choices
    std::cout << "Welcome to the todo list manager program!" << std::endl;

    while (choice != 5) {
        std::cout << "Please make a selection of which function to use:" << std::endl;
        std::cout << "1. Read a list from a file and sort it" << std::endl;
        std::cout << "2. Write to a file and sort it" << std::endl;
        std::cout << "3. Add to a pre-existing file" << std::endl;
        std::cout << "4. Take away from a pre-existing file" << std::endl;
        std::cout << "5. End program" << std::endl;
        std::cout << "--> ";
        std::cin >> choice;
        std::cout << std::endl;

        //Switch statement to go through each choice
        switch (choice) {
            case 1:
                //Reading choice
                readToFile();

                std::cout << std::endl;
                break;
            case 2:
                //Writing choice
                if (writeToFile() != 0) {
                    std::cout << "Error, file could not be found! Did you spell it right?" << std::endl;
                }
                
                std::cout << std::endl;
                break;
            case 3:
                //Add to a file choice
                if (addToFile() != 0) {
                    std::cout << "Error, file could not be found! Uh oh!" << std::endl;
                }

                std::cout << std::endl;
                break;
            case 4:
                //Remove from a file choice
                if (removeToFile() != 0) {
                    std::cout << "Error, file could not be found! Uh oh!" << std::endl;
                }

                std::cout << std::endl;
                break;
            case 5:
                //End program choice
                break;
            default:
                //Default error
                std::cout << "Error, choice made was not an option!" << std::endl << std::endl;
        }
    }
    
    std::cout << "Don't forget to do these!!" << std::endl;

    return(0);
}