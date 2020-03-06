#include <stddef.h>
#include "bin_tree.h"

//Search - return pointer to element in S s.t. x.key = k (tail recursion)
treeNode* treeSearch(treeNode* x, int k) {
	if (x == NULL || k == x->key) {
		return x;
	}
	if (k < x->key) {
		return treeSearch(x->left, k);
	}
	else {
		return treeSearch(x->right, k);
	}
}

//Insert - Insert node (createNode) into Tree
void treeInsert(tree* T, treeNode* z) {
	treeNode* y = NULL;
	treeNode* x = T->root;

	while (x != NULL) {
		y = x;
		if (z->key < x->key) {
			x = x->left;
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

//Delete - Delete node z from Tree T, return y (deleted node)
treeNode* treeDelete(tree* T, treeNode* z) {
	treeNode* y = NULL;
	treeNode* x = NULL;

	if (z->left == NULL || z->right == NULL) {
		y = z;
	}
	else {
		y = treeSuccessor(z);
	}
	if (y->left != NULL) {
		x = y->left;
	}
	else {
		x = y->right;
	}
	if (x != NULL) {
		x->parent = y->parent;
	}
	if (y->parent == NULL) {
		T->root = x;
	}
	else {
		if (y == y->parent->left) {
			y->parent->left = x;
		}
		else {
			y->parent->right = x;
		}
	}
	if (y != z) {
		z->key = y->key;
	}
	return y;
}

//Minimum - Return smalest node
treeNode* treeMinimum(treeNode* x) {
	while (x->left != NULL) {
		x = x->left;
	}
	return x;
}

//Maximum - Return largest node 
treeNode* treeMaximum(treeNode* x) {
	while (x->right != NULL) {
		x = x->right;
	}
	return x;
}

//Successor - Find successor of node x and return it.
treeNode* treeSuccessor(treeNode* x) {
	treeNode* y = NULL;

	if (x->right != NULL) {
		return treeMinimum(x->right);
	}
	y = x->parent;
	while (y != NULL && x == y->right) {
		x = y;
		y = y->parent;
	}
	return y;
}

//Predecessor - Find predecessor of node x and return it.
treeNode* treePredecessor(treeNode* x) {
	treeNode* y = NULL;

	if (x->right != NULL) {
		return treeMaximum(x->left);
	}
	y = x->parent;
	while (y != NULL && x == y->left) {
		x = y;
		y = x->parent;
	}
	return y;
}