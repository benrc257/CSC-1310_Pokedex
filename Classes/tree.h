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

#ifndef TREE_H
#define TREE_H

#include "../main.h"

template <typename T>
class Tree {
    private:
        struct Node {
            Node *left, *right;
            T value;
        };

        

    public:



};

#endif