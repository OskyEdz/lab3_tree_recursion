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

//Create new node
treeNode* newNode(int data);

//Create tree
treeNode* createTree();

//Find depth of tree
int treeDepth(treeNode* node);

//Search tree for node
treeNode* treeSearch(treeNode* x, int k);

//Insert node to tree
void treeInsert(tree* T, treeNode* z);

//Delete node from tree
treeNode* treeDelete(tree* T, treeNode* z);

//Find min. node
treeNode* treeMinimum(treeNode* x);

//Find max. node
treeNode* treeMaximum(treeNode* x);

//Find node successor
treeNode* treeSuccessor(treeNode* x);

//Find node predecessor
treeNode* treePredecessor(treeNode* x);