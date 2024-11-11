/*
    MAIN FUNCTION
    Requirements:
    - All Classes Used
    - All Necessary Functions Accessible/Tested
    - Takes User Input
    - Has Natural Way To End Program
*/

#include "main.h"
#include "Classes/pokemon.h"
#include "Classes/pokedex.h"

int main() {
    cout << LINE << "\n LOADING YOUR POKEMON";
    Pokedex<Pokemon> pokedex(FILENAME);
    string name;
    int choice, id;
    while (choice != 5){
        choice = mainMenu();
        switch (choice){
            case 1 : // Display entries
                pokedex.display();
                break;
            case 2 : // Add a Pokemon
                cout << "\n Enter the name of the Pokemon you'd like to add.\n >> ";
                cin.ignore();
                getline(cin,name);
                cout << "\n Enter the ID for the Pokemon.\n >> ";
                while (!(cin >> id) || id < 0) { //input validation
                    cout << "\nInvalid ID. Please enter an integer. >> ";
                    cin.clear();
                    cin.ignore(10000, '\n');
                }
                pokedex.appendPokemon(name, id);
            break;
            case 3 : // Remove a Pokemon
                cout << "\n Enter the ID of the Pokemon you wish to remove.\n >> ";
                while (!(cin >> id) || id < 0) { //input validation
                    cout << "\nInvalid ID. Please enter an integer. >> ";
                    cin.clear();
                    cin.ignore(10000, '\n');
                }
                pokedex.remove(pokedex.getByIndex(id));
                break;
            case 4 : // Add Pokemon From File
                cout << "\n Enter the name of the file you want to import from.\n >> ";
                cin.ignore();
                getline(cin,name);
                pokedex.import(name,'#');
                break;   
            case 5 : // END
                cout << LINE << "\n Goodbye!" << LINE;
                return 0; // end
                break;
        }
    }
}