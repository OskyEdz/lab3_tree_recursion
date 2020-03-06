#pragma once
#include <stdbool.h>

//Every node in the tree should have a pointer to its (data)-, (left and right child)- and (the preprevious) node.
typedef struct treeNode {
    int key; //Data of the node
    struct treeNode* left; //Left child
    struct treeNode* right; //Right child
    struct treeNode* parent; //Parent
} treeNode;

//Struct for the whole tree
typedef struct tree {
    struct treeNode* root; //Root
} tree;

//Create a new node
treeNode* newNode(int data);

//Create the tree
tree* createTree();

treeNode* treeSearch(treeNode* x, int k);