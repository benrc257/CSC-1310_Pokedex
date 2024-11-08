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

template <typename Y>
void Pokedex<Y>::append(Node<Y>* append) {
    Node<Y>* check = root;
    // If root is empty, insert at the root
    if (root == nullptr) {
        root = append;
        return;
    }

    while (check != nullptr) {
        if (check->pokemon > append->pokemon) { // Larger goes on the left
            if (check->left == nullptr) { // If left is empty, insert here
                check->left = append;
                return; // End early
            } else { // Otherwise, continue traversing left
                check = check->left;
            }
        } else if (check->pokemon < append->pokemon) { // Smaller goes on the right
            if (check->right == nullptr) { // If right is empty, insert here
                check->right = append;
                return; // End early
            } else { // Otherwise, continue traversing right
                check = check->right;
            }
        } else { // Node with the same id exists
            std::cout << "\n------------------- ERROR ----------------------\n"
                      << "  A Pokemon already exists with the same entry\n"
                      << "------------------------------------------------\n";
            return;
        }
    }
}

template <typename Y>
void Pokedex<Y>::remove(Node<Y>* removing){

    
};


#endif