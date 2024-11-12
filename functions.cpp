// Function definitions for main.h

#include "main.h"


int mainMenu(){
    int choice = 0;
    bool valid = 0;

    cout << LINE << "\n Main Menu:"
        << "\n 1: Display Entries"
        << "\n 2: Add a Pokemon"
        << "\n 3: Remove a Pokemon" 
        << "\n 4: Add Pokemon From File"
        << "\n 5: END Program\n"
        << "\n Enter a number between 1-5.\n >> ";
    while (!(cin >> choice) || choice > 5 || choice < 1) { //input validation
        cout << "\n Invalid choice. Please try again.\n >> ";
        cin.clear();
        cin.ignore(10000, '\n');
    }
        
    return choice;
};



