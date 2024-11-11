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

    To Test:
    - Insert
    - Append
    - Import
    - Remove
    - getByIndex
    

    ---- DONE! ----
    - Public Friend Function (operator <<)
    - Private Root Node
    - Private Node Struct
    - View Root Function
   
*/

#ifndef POKEDEX_H
#define POKEDEX_H

#include "../main.h"



template <typename X>
struct Node {
    Node *left, *right, *parent;
    X *object;

    Node(Node* left, Node* right, Node* parent, X *object) {
        this->left = left;
        this->right = right;
        this->parent = parent;
        this->object = object;
    }
};

template <typename Y>
class Pokedex {
    private:
        Node<Y> *root; 
    public:
        // Tree functions
        void insert(Node<Y>* insert, Node<Y>* position);
        bool appendPokemon(string Name, int Id);
        bool appendNode(Node<Y>* append);
        bool remove(Node<Y>* removing);
        void inOrderTraversal(Node<Y>* node);
        void deleteTree(Node<Y>* node);

        //util
        void display();
        
        //getters
        Node<Y>* getRoot();
        Node<Y>* getByIndex(int index);

        //setters
        void import(string Filename, char delim);
        
        //constructers && destructors
        Pokedex(const string filename) {
            import(filename, '#');
        }

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
    Node<Y> *check = root;
    Y *temp = new Y("temp", index);

    while (check != nullptr)// if not end
    {
        if (check->object == temp){
            delete temp;
            return check; // return if found
        } else if (check->object < temp){
            check = check->left; // left if smaller
        } else {
            check = check->right; // right if bigger
        } 
    }
    delete temp;
    return check;
}

// insert: Inserts a copy of insert's data after position. You should use remove to delete insert after this.
template <typename Y> 
void Pokedex<Y>::insert(Node<Y>* insert, Node<Y>* position){
    Node<Y> *copy;

    copy = new Node<Y>(nullptr, nullptr, position, insert->object);

    if (copy->object == position->object) { //do nothing if the object is a duplicate
        delete copy;
        return;
    }
    
    if (copy->object < position->object) { //inserts left

        if (copy->object == position->left->object) { //do nothing if the object is a duplicate
            delete copy;
            return;
        }

        if (copy->object < position->left->object) { //if the left object is less than copy, set it to the left pointer
            copy->left = position->left;
        } else {  //if the left object is more than copy, set it to the right pointer
            copy->right = position->left;
        }

        //sets position left's parent to copy
        position->left->parent = copy;

        //sets position's left pointer to copy
        position->left = copy;
    } else { //inserts right

        if (copy->object == position->right->object) { //do nothing if the object is a duplicate
            delete copy;
            return;
        }

        if (copy->object < position->right->object) { //if the right object is less than copy, set it to the left pointer
            copy->left = position->right;
        } else {  //if the right object is more than copy, set it to the right pointer
            copy->right = position->right;
        }

        //sets position right's parent to copy
        position->right->parent = copy;

        //sets position's right pointer to copy
        position->right = copy;
    }

};

// appendPokemon: makes a pokemon object then calls append node
template <typename Y>
bool Pokedex<Y>::appendPokemon(string name,int id){
    bool success;
    Y *newY = new Y(name, id);

    Node<Y> *newNode = new Node<Y>(nullptr, nullptr, nullptr, newY);
    success = appendNode(newNode);

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
        if (check->object < append->object) { // Smaller goes on the left
            if (check->left == nullptr) { // If left is empty, insert here
                check->left = append;
                append->parent = check;
                return true; // End early
            } else { // Otherwise, continue traversing left
                check = check->left;
            }
        } else if (check->object > append->object) { // Larger goes on the right
            if (check->right == nullptr) { // If right is empty, insert here
                check->right = append;
                append->parent = check;
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
    
    return false;
}

// import: overload to handle importing from a file;
template <typename Y>
void Pokedex<Y>::import(string filename, char delim){
    string temp1,temp2;
    fstream file;
    file.open(filename);

    if (!file.is_open()) {
       cout << "\nError: Could not open file " << filename << "\n";
       return;
    }

    while (getline(file,temp1,delim) && getline(file,temp2,delim)){ // constructs a new pokemon
        appendPokemon(temp2,stoi(temp1));
    }
  
};

template <typename Y>
bool Pokedex<Y>::remove(Node<Y>* removing) {
    if (removing == nullptr) return false;  // If the node to remove doesn't exist, return false.

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
        return true;
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
        return true;
    }

    // Case 3: Node has two children (find in-order successor)
    else {
        // Find the in-order successor (smallest node in the left subtree)
        Node<Y>* successor = removing->left;
        while (successor->left != nullptr) {
            successor = successor->left;
        }

        // Copy the successor's data into the current node
        removing->object = successor->object;

        // Recursively remove the successor (it can have at most one child)
        remove(successor);
        return true;
    }
};

template <typename Y>
void Pokedex<Y>::inOrderTraversal(Node<Y>* node) {
    if (node == nullptr) { // Base case: if node is null, return.
        return;    
    }
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

        delete node;// Finally, delete the current node
    }
    return;
}

#endif