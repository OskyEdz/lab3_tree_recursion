#include "bin_tree.h"

int main() {

/*############### EXERCICE #1 #############*/
	
	//Testing number
	int testX = 15;

	//A tree for testing
	tree* testTree = createTree();

	//The root node
	treeNode* rootNode = testTree->root;

	//Testing function :)
	treeTests(rootNode);

	//Insert test node
	treeInsert(testTree, testX);
	treeTests(rootNode);

	//Try find some keys
	treeSearch(rootNode, 21);	//In the tree
	treeSearch(rootNode, 3);	//Not in the tree

	//Search for node and delete it.
	treeDelete(testTree, treeSearch(rootNode, 37)); //in the tree
	treeDelete(testTree, treeSearch(rootNode, 10));	//not in the tree
	treeTests(rootNode);

	//Find max. and min. in tree
	treeMinimum(rootNode);
	treeMaximum(rootNode);

	treeSuccPred(treeSearch(rootNode, 11));	//Both succ and pred
	treeSuccPred(treeSearch(rootNode, 99)); //No succssor
	treeSuccPred(treeSearch(rootNode, 40)); //No such node in tree

/*############### EXERCICE #2 #############*/

	tree* loadTree_1 = test_1(); // 10 numbers
	//tree* loadTree_2 = test_2();	//100 000 WARNING will spam console for minutes
									//inorder and treeInsert printf

	return 0;
}
