// Function definitions for main.h

#include "main.h"


int mainMenu(){
    int choice;
    bool valid = 0;

        cout << LINE << "\n Main Menu:"
            << "\n 1: Display entries"
            << "\n 2: Add a Pokemon"
            << "\n 3: Remove a Pokemon" 
            << "\n 4: Add Pokemon From File"
            << "\n 5: END program\n"
            << "\n enter a number between 1-4\n";
            cin >> choice;
            cin.ignore();
            
            if(!((choice < 4) && (choice > 1))){
                cout << "\n --- INVALID RESPONSE --- ";
                return mainMenu();
            } else {
                return choice;
            }
};



