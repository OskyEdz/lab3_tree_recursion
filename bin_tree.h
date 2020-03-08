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

//Create tree with n nodes
tree* createTree();

//Create tree from load file
tree* createLoadTree(char* argv[], char* sol[]);

//Find depth of tree
int treeDepth(treeNode* root);
int maxDepth(treeNode* root);

//Search tree for node
treeNode* treeSearch(treeNode* x, int k);
treeNode* search(treeNode* x, int k);

//Insert node to tree
void treeInsert(tree* T, int z);

//Delete node from tree
treeNode* treeDelete(tree* T, treeNode* z);

//Find min. node
treeNode* treeMinimum(treeNode* x);
treeNode* minimum(treeNode* x);

//Find max. node
treeNode* treeMaximum(treeNode* x);
treeNode* maximum(treeNode* x);

//Find node successor
treeNode* treeSuccessor(treeNode* x);

//Find node predecessor
treeNode* treePredecessor(treeNode* x);

//quick find succ n' pred
treeNode* treeSuccPred(treeNode* x);

//Inorder Tree Walk
void treeInorder(treeNode* root);
void inorder(treeNode* root);

//Tree tests
void treeTests(treeNode* root);

//Load Testing
tree* test_1();
tree* test_2();