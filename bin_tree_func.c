#include "bin_tree.h"
#include <stddef.h>
#include <stdbool.h> 
#include <stdio.h>
#include <stdlib.h>

//Allocate memory for every node in the tree
treeNode* newNode(int data){
    // Allocate memory for new node  
    treeNode* node = (treeNode*)malloc(sizeof(treeNode));

    if (node != NULL) {
        // Assign data to this node 
        node->data = data;

        // Initialize left and right children as NULL 
        node->left = NULL;
        node->right = NULL;
        return(node);
    }
    return(node);
}

//Create Tree function
void* createTree() {
    //Root Node
    treeNode* root = newNode(1);

    root->left = newNode(2);        //left noe
    root->right = newNode(3);       //right node
    root->left->left = newNode(4);  //left of left node

    root->prev = NULL;

    return 0;
}