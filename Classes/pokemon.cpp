

// Function definitions for data.h
#include "../main.h"
#include "pokemon.h"

    
    Pokemon::Pokemon(string Name,int Id)
    {
        name = Name;
        id = Id;    
    }
    
    //getters
    int Pokemon::getId(){
        return id;
    };
    string Pokemon::getName(){
        return name;
    };

    //setters
    void Pokemon::setId(int a){
        id = a;
    };

    void Pokemon::setName(string a){
        name = a;
    };


    