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
    cout << LINE << "/n LOADING YOUR POKEMON";
    Pokedex<Pokemon> pokedex;
    string name,id;
    int choice;
    while (mainMenu()){
        switch (choice){
            case 1 : // Display entries
                pokedex.display();
                break;
            case 2 : // Add a Pokemon
                cout << "\n enter the name of the pokemon\n";
                getline(cin,name);
                cout << "\n enter the id for the pokemon\n";
                getline(cin,id);
                pokedex.appendPokemon(name,stoi(id));
            break;
            case 3 : // Remove a Pokemon
                cout << "\n enter the id of the pokemon you wish to remove\n";
                getline(cin,id);
                pokedex.remove(pokedex.getByIndex(stoi(id)));
                break;
            case 4 : // Add Pokemon From File
                cout << "\n enter the name of the file you want to import from\n";
                getline(cin,name);
                pokedex.import(name,'#');
                break;   
            case 5 : // END
                cout << LINE << "Shutting down";
                return 0; // end
                break;
        }
    }
}