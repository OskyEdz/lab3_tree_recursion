#include "bin_tree.h"
#include <stddef.h>
#include <stdio.h>

//Search - return pointer to element in S s.t. x.key = k (tail recursion)
treeNode* search(treeNode* x, int k) {
	if (x == NULL || k == x->key) {
		if (x != NULL) {
			printf("Found the node->key %d\n", x->key);
			return x;
		}
		else {
			printf("Didn't find the key %d\n", k);
			return x;
		}
	}
	if (k < x->key) {
		return search(x->left, k);
	}
	else {
		return search(x->right, k);
	}
}

//Insert - Insert node (createNode) into Tree
void treeInsert(tree* T, int z) {
	treeNode* y = NULL;
	treeNode* x = T->root;

	treeNode* node = newNode(z);

	while (x != NULL) {
		y = x;
		if (node->key < x->key) {
			x = x->left;
		}
		else {
			x = x->right;
		}
	}
	node->parent = y;
	if (y == NULL) {
		T->root = node;	//tree T was empty
	}
	else if (node->key < y->key) {
		y->left = node;
		y->left->parent = y;	//Update parent to node
		printf("Insert node->key %d\n", node->key);
	}
	else {
		y->right = node;
		y->right->parent = y;	//Update parent to node
		printf("Insert node->key %d\n", node->key);
	}
}

//Delete - Delete node z from Tree T, return y (deleted node)
treeNode* treeDelete(tree* T, treeNode* z) {
	treeNode* y = NULL;
	treeNode* x = NULL;

	if (z != NULL) {
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
		printf("Deleted node->key %d\n", y->key);
		return y;
	}
	else {
		printf("Node was NULL, cannot delete that.");
		return NULL;
	}

}

//Minimum - Return smalest node
treeNode* minimum(treeNode* x) {
	while (x->left != NULL) {
		x = x->left;
	}
	return x;
}

//Maximum - Return largest node 
treeNode* maximum(treeNode* x) {
	while (x->right != NULL) {
		x = x->right;
	}
	return x;
}

//Successor - Find successor of node x and return it.
treeNode* treeSuccessor(treeNode* x) {
	treeNode* y = NULL;

	if (x->right != NULL) {
		return minimum(x->right);
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
		return maximum(x->left);
	}
	y = x->parent;
	while (y != NULL && x == y->left) {
		x = y;
		y = x->parent;
	}
	return y;
}

//depth of the tree
int maxDepth(treeNode* root) {
	if (root == NULL) {
		//Root null, bottom of tree
		return 0;
	}
	else {
		//recursivly find depth of left and right tree
		int leftDepth = maxDepth(root->left);
		int rightDepth = maxDepth(root->right);

		//go to the larger one
		if (leftDepth > rightDepth) {
			return leftDepth + 1;
		}
		else {
			return rightDepth + 1;
		}
	}
}

//Inorder-tree-walk
void inorder(treeNode* root) {
	if (root != NULL) {
		inorder(root->left);
		printf("%d ", root->key);
		inorder(root->right);
	}
}