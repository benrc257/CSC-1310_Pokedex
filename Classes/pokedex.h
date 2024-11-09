/*
    TREE CLASS
    --------------------------------------------------
    Requirements:
    - Private Root Node
    - Private Node Struct
    - Insert Function
    - View [Index] Function
    - View Root Function
    - Remove Function (by index or value)
    - Public Friend Function (operator <<)
    - Constructor, Destructor

    To Do:
    - Insert
    - Destructor
    - Read from file

    To Test:
    - Append
    - Import
    - Remove
    - getByIndex

    ---- DONE! ----
    - Public Friend Function (operator <<)
    - Private Root Node
    - Private Node Struct
   
*/

#ifndef POKEDEX_H
#define POKEDEX_H

#include "../main.h"
//#include "pokemon.h"


template <typename X>
struct Node {
    Node *left, *right, *parent;
    X object;
    Node(Node* left, Node* right,Node* parent, X object){
        this->left = left;
        this->right = right;
        this->parent = parent;
        this->object = object;
    }
};

template <typename Y>
class Pokedex {
    private:
        Node<Y>* root; 
    public:
        // Tree functions
        void insert(Node<Y>* insert, Node<Y>* position);
        bool appendPokemon(string Name, int Id);
        bool appendNode(Node<Y>* append);
        void remove(Node<Y>* removing);
        void inOrderTraversal(Node<Y>* node);
        void deleteTree(Node<Y>* node);

        //util
        void display();
        
        //getters
        Node<Y>* getRoot();
        Node<Y>* getByIndex(int index);

        //setters
        void import(string Filename, char delim, Y pokemon);
        

        ~Pokedex() {
            deleteTree(root);
        }

};


template <typename Y>
Node<Y>* Pokedex<Y>::getRoot() {
    return this->root;
}

template <typename Y>
Node<Y>* Pokedex<Y>::getByIndex(int index) {
    Node<Y>* check = root;

    while (check != nullptr)// if not end
    {
        if (check->object.id == index){
            return check; // return if found
        } else if (check->object.id > index){
            check = check->left; // left if bigger
        } else {
            check = check->right; // right if smaller
        } 
    }
    return nullptr;
}

template <typename Y> //TODO
void Pokedex<Y>::insert(Node<Y>* insert, Node<Y>* position){

};

// appendPokemon: makes a pokemon object then calls append node
template <typename Y>
bool Pokedex<Y>::appendPokemon(string name,int id){
    Node<Y>* newNode = new Node<Y>(nullptr, nullptr, nullptr, Y(name, id));
        bool success = appendNode(newNode);
    if (!success) {
        delete newNode;  // Free memory if appending fails
    }
    return success;
};

// appendNode: searches the tree and appends a new node at its intendid position
template <typename Y>
bool Pokedex<Y>::appendNode(Node<Y>* append) {
    Node<Y>* check = root;
    // If root is empty, insert at the root
    if (root == nullptr) {
        root = append;
        return true;
    }

    while (check != nullptr) {
        if (check->object > append->object) { // Larger goes on the left
            if (check->left == nullptr) { // If left is empty, insert here
                check->left = append;
                return true; // End early
            } else { // Otherwise, continue traversing left
                check = check->left;
            }
        } else if (check->object < append->object) { // Smaller goes on the right
            if (check->right == nullptr) { // If right is empty, insert here
                check->right = append;
                return true; // End early
            } else { // Otherwise, continue traversing right
                check = check->right;
            }
        } else if (check->object == append->object) { // Node with the same id exists
               cout << "\n------------------- ERROR ----------------------\n"
                      << "  A Pokemon already exists with the same entry\n"
                      << "------------------------------------------------\n";
            return false;// end with false
        }
    }
}

// import: overload to handle importing from a file;
template <typename Y>
void Pokedex<Y>::import(string filename, char delim, Y pokemon){
    string temp1,temp2;
    fstream file;
    file.open(filename);

    if (!file.is_open()) {
        throw runtime_error("Error: Could not open file " + filename);
    }

    while (getline(file,temp1,delim) && getline(file,temp2,delim)){ // constructs a new pokemon
        appendPokemon(temp2,stoi(temp1));
    }
  
};

template <typename Y>
void Pokedex<Y>::remove(Node<Y>* removing) {
    if (removing == nullptr) return;  // If the node to remove doesn't exist, return.

    // Case 1: Node is a leaf (no children)
    if (removing->left == nullptr && removing->right == nullptr) {
        if (removing->parent) {
            if (removing->parent->left == removing) {
                removing->parent->left = nullptr;
            } else {
                removing->parent->right = nullptr;
            }
        } else {
            root = nullptr;  // If the node is the root
        }
        delete removing;  // Deallocate memory
        return;
    }

    // Case 2: Node has only one child (left or right)
    else if (removing->left == nullptr || removing->right == nullptr) {
        Node<Y>* child;

        if (removing->left != nullptr) {
            child = removing->left;
        } else {
            child = removing->right;
        }

        if (removing->parent) {
            if (removing->parent->left == removing) {
                removing->parent->left = child;
            } else {
                removing->parent->right = child;
            }
        } else {
            root = child;  // If the node is the root
        }

        child->parent = removing->parent;  // Update the parent of the child
        delete removing;  // Deallocate memory
        return;
    }

    // Case 3: Node has two children (find in-order successor)
    else {
        // Find the in-order successor (smallest node in the right subtree)
        Node<Y>* successor = removing->right;
        while (successor->left != nullptr) {
            successor = successor->left;
        }

        // Copy the successor's data into the current node
        removing->object = successor->object;

        // Recursively remove the successor (it can have at most one child)
        remove(successor);
    }
};

template <typename Y>
void Pokedex<Y>::inOrderTraversal(Node<Y>* node) {
    if (node == nullptr) return;  // Base case: if node is null, return.
    inOrderTraversal(node->left);// Traverse left subtree
    cout << node->object;// Process current node (print object details)
    inOrderTraversal(node->right);// Traverse right subtree
}

template <typename Y>
void Pokedex<Y>::display() {
    inOrderTraversal(root);  // Start the in-order traversal from the root
}

template <typename Y>
void Pokedex<Y>::deleteTree(Node<Y>* node) {
    if (node != nullptr) {
        
        deleteTree(node->left);// Recursively delete left and right children
        deleteTree(node->right);

        // Finally, delete the current node
        delete node;
    }
}

#endif