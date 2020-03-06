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
        node->key = data;

        // Initialize left and right children as NULL 
        node->left = NULL;
        node->right = NULL;
        return(node);
    }
    return(node);
}

//Create Tree function
treeNode* createTree() {
    treeNode* root = newNode(1);

    root->left = newNode(2);        //left node
    root->right = newNode(3);       //right node
    root->left->left = newNode(4);  //left of left node
    root->parent = NULL;

    return root;
}

//Find tree Depth
int treeDepth(treeNode* node){
    if (node == NULL) {
        return 0;
    }
    else {
        int leftDepth = treeDepth(node->left);
        int rightDepth = treeDepth(node->right);

        /* use the larger one */
        if (leftDepth > rightDepth) {
            return(leftDepth + 1);
        }
        else {
            return(rightDepth + 1);
        }
    }
}