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

// append: searches the tree and appends a new node at its intendid position
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
void Pokedex<Y>::remove(Node<Y>* removing) {
    if (removing == nullptr) return;

    // Case 1: Node is a leaf (no children)
    if (removing->left == nullptr && removing->right == nullptr) {
        if (removing->parent) {
            if (removing->parent->left == removing) {
                removing->parent->left = nullptr;
            } else {
                removing->parent->right = nullptr;
            }
        } else {
            root = nullptr; // If it's the root node
        }
        delete removing;
        return;

    // Case 2: Node has only one child
    } else if (removing->left != nullptr && removing->right == nullptr) { // Only left child
        if (removing->parent) {
            if (removing->parent->left == removing) {
                removing->parent->left = removing->left;
            } else {
                removing->parent->right = removing->left;
            }
            removing->left->parent = removing->parent;
        } else {
            root = removing->left; // If it's the root node
            root->parent = nullptr;
        }
        delete removing;
        return;

    } else if (removing->left == nullptr && removing->right != nullptr) { // Only right child
        if (removing->parent) {
            if (removing->parent->left == removing) {
                removing->parent->left = removing->right;
            } else {
                removing->parent->right = removing->right;
            }
            removing->right->parent = removing->parent;
        } else {
            root = removing->right; // If it's the root node
            root->parent = nullptr;
        }
        delete removing;
        return;

    // Case 3: Node has two children
    } else {
        // Find the in-order successor (smallest node in the right subtree)
        Node<Y>* successor = removing->right;
        while (successor->left != nullptr) {
            successor = successor->left;
        }

        // Copy the successor's data to the node to be deleted
        removing->pokemon = successor->pokemon;

        // Recursively delete the successor, which now has at most one child
        remove(successor);
    }
}



#endif