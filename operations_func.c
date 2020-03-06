#include <stddef.h>
#include "bin_tree.h"

//Search - return pointer to element in S s.t. x.key = k
treeNode* treeSearch(treeNode* x, int k) {
	if (x == NULL || k == x->key) {
		return x;
	}
	if (k < x->key) {
		return treeSearch(x->key, k);
	}
	else {
		return treeSearch(x->key, k);
	}
}

//Insert - Insert node (createNode) into Tree
bool treeInsert(tree* T, treeNode* z) {
	treeNode* y = NULL;
	treeNode* x = T->root;

	while (x != NULL) {
		y = x;
		if (z->key < x->key) {
			x = x->key;
		}
		else {
			x = x->right;
		}
	}
	z->parent = y;
	if (y == NULL) {
		T->root = z;	//tree T was empty
	}
	else if (z->key < y->key) {
		y->left = z;
	}
	else{
		y->right = z;
	}
}

//Delete

//Minimum

//Maximum

//Successor

//Predecessor