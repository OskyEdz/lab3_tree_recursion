#pragma once
#include <stdbool.h>

//Every node in the tree should have a pointer to its (data)-, (left and right child)- and (the preprevious) node.
typedef struct treeNode {
    int data; //Data of the node
    struct treeNode* left; //Left child
    struct treeNode* right; //Right child
    struct treeNode* prev; //Parrent
} treeNode;

//Create a new node
treeNode* newNode(int data);

//Create the tree
void* createTree();