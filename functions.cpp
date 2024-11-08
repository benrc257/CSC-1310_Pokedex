// Function definitions for main.h

#include "main.h"


void mainMenu(){
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

        
        switch (choice)
        {
        case 1 : // Display entries
            
            
            break;
        case 2 : // Add a Pokemon
           
            
            break;
        case 3 : // Remove a Pokemon
          
            
            break;
        case 4 : // Add Pokemon From File
            
            
            break;   
        case 5 : // END
            
            
            break;

        default:
                cout << "\n --- INVALID RESPONSE --- ";
                return mainMenu();
            break;
        }
       
};