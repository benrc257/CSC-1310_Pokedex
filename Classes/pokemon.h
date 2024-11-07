/*
    DATA CLASS
    Requirements:
    - Private Data
    - Modifiable Data
    - Accessors, Setters
    - Comparison and Stream Operators (<<, <, >, ==)
    - [Optional] Other Comparison Operators (~=, <=, >=)
    - Constructor, Destructor
*/

#ifndef POKEMON_H
#define POKEMON_H

#include "../main.h"

    class Pokemon
    {
    private:

        int id;
        string name;

    public:
        //constructor
            Pokemon(int id, string name);
        //getters
            int    getId();
            string getName();
        //setters
            void setId(int);
            void setName(string);

        // Friends
        friend ostream& operator<<(ostream& os, Pokemon& pokemon) { // prints pokemon
            os << "\n- ID:" << pokemon.getId() << " - - NAME: " << pokemon.getName() << " -";
            return os;
        }

        friend bool operator==(Pokemon& poke1, Pokemon& poke2) { // == comparison of ids
            if (poke1.getId() == poke2.getId()) {
                return true;
            }

            return false;
        }
        
        friend bool operator<(Pokemon& poke1, Pokemon& poke2) { // < comparison of ids
            if (poke1.getId() < poke2.getId()) {
                return true;
            }
            return false;
        }
        
        friend bool operator>(Pokemon& poke1, Pokemon& poke2) { // > comparison of ids
            if (poke1.getId() > poke2.getId()) {
                return true;
            }
            return false;
        }
    };

    









#endif