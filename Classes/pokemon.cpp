// Function definitions for pokemon.h
#include "../main.h"
#include "pokemon.h"

    
Pokemon::Pokemon(string name,int id)
{
    this->name = name;
    this->id = id;    
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


