#include "bin_tree.h"
#include "load_files/load_file.h"

#include <stddef.h>
#include <stdbool.h> 
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

//Allocate memory for every node in the tree
treeNode* newNode(int data){
    // Allocate memory for new node  
    treeNode* node = NULL;
    node = malloc(sizeof(treeNode));

    if (node != NULL) {
        // Assign data to this node 
        node->key = data;

        // Initialize left and right children as NULL 
        node->left = NULL;
        node->right = NULL;
        node->parent = NULL;

        return node;
    }
    return 0;
}

//Create-Tree function
tree* createTree() {
    //Create tree
    tree* newTree = NULL;
    newTree = malloc(sizeof(tree));

    if (newTree != NULL) {

        //Create the root node
        newTree->root = newNode(32);
        treeInsert(newTree, 11);
        treeInsert(newTree, 7);
        treeInsert(newTree, 28);
        treeInsert(newTree, 17);
        treeInsert(newTree, 13);
        treeInsert(newTree, 21);
        treeInsert(newTree, 42);
        treeInsert(newTree, 37);
        treeInsert(newTree, 99);
        treeInsert(newTree, 50);

        printf("\nTree created\n");
        return newTree;
    }
    return 0;
}

//Create tree from load file
tree* createLoadTree(char* argv[], char* sol[]) {
    //Create tree
    tree* loadTree = NULL;
    loadTree = malloc(sizeof(tree));

    if (loadTree != NULL) {
        const char* fName_problem = argv[0];
        const char* fName_solution = sol[0];

        int* a = load_file(fName_problem);
        int* b = load_file(fName_solution);

        int size = a[0];

        //Create the root node
        int rootKey = (b[size] / 2);

        loadTree->root = newNode(rootKey);

        for (int i = 1; i <= size; i++) {
            if (a[i] != rootKey) {
                treeInsert(loadTree, a[i]);
            }
        }
        return loadTree;
    }
    return 0;
}

//Find node
treeNode* treeSearch(treeNode* x, int k) {
    if (x != NULL) {
        printf("Searching...");
        return search(x, k);
    }
    return 0;
}

//Find maximum node
treeNode* treeMaximum(treeNode* root) {
    if (root != NULL) {
        treeNode* node = maximum(root);
        printf("Maximum node->key is %d\n", node->key);
    }
    return 0;
}

//Find minimum node
treeNode* treeMinimum(treeNode* root) {
    if (root != NULL) {
        treeNode* node = minimum(root);
        printf("Minimum node->key is %d\n", node->key);
    }
    return 0;
}

//Find successor and predecessor for searched node
treeNode* treeSuccPred(treeNode* x) {
    if (x != NULL) {
        treeNode* succNode = treeSuccessor(x);
        if (succNode != NULL) {
            printf("The successor of %d is %d\n", x->key, succNode->key);
        }
        else {
            printf("There is no successor for %d\n", x->key);
        }

        treeNode* predNode = treePredecessor(x);
        if (predNode != NULL) {
            printf("The predecessor of %d is %d\n", x->key, predNode->key);
        }
        else {
            printf("There is no predecessor for %d\n", x->key);
        }
    }
    return 0;
}

//Find tree Depth
int treeDepth(treeNode* root){
    if (root != NULL) {
        int depth = maxDepth(root);
        printf("Height of the tree is %d\n", depth);
        return depth;
    }
    return 0;
}

//Print tree in order
void treeInorder(treeNode* root) {
    printf("Starting in-order tree walk...\n");
    inorder(root);
    printf("\n");
}

//Collection of tests to run
void treeTests(treeNode* root) {
    printf("\nStarting test...\n");
    treeDepth(root);
    treeInorder(root);
    printf("Tests completed!\n\n");
}

//Test 1 - create tree from file
tree* test_1() {
    char* sortingProblem[] = { "sorting_problems/test-10-1-problem" };
    char* sortingSolution[] = { "sorting_problems/test-10-1-solution" };

    //Test 1 - 10
    tree* loadTree = createLoadTree(sortingProblem, sortingSolution);
    treeTests(loadTree->root);
    return loadTree;
}

//Test 2 - create tree from file WARNING 100 000 numbers spam in console!!
tree* test_2() {
    char* sortingProblem[] = { "sorting_problems/test-100000-1-problem" };
    char* sortingSolution[] = { "sorting_problems/test-100000-1-solution" };

    //Test 2 - 100 000
    tree* loadTree = createLoadTree(sortingProblem, sortingSolution);
    treeTests(loadTree->root);
    return loadTree;
}