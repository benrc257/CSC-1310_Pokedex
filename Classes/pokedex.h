/*
    TREE CLASS
    Requirements:
    - Private Root Node
    - Private Node Struct
    - Insert Function
    - View [Index] Function
    - View Root Function
    - Remove Function (by index or value)
    - Public Friend Function (operator <<)
    - Constructor, Destructor
*/

#ifndef POKEDEX_H
#define POKEDEX_H

#include "../main.h"
#include "pokemon.h"


template <typename X>
struct Node {
    Node *left, *right, *parent;
    X pokemon;
};

template <typename Y>
class Pokedex {
    private:
        Node<Y>* root;
        vector<Node<Y>*> pokedex;
    public:
        // Tree functions
        void insert(Node<Y>* insert, Node<Y>* position);
        void append(Node<Y>* append);
        void remove(Node<Y>* removing);
        Node<Y>* getRoot();

        


};

template <typename Y>
Node<Y>* Pokedex<Y>::getRoot() {
    return this->root;
}

template <typename Y>
void Pokedex<Y>::insert(Node<Y>* insert, Node<Y>* position){

    
};


#endif