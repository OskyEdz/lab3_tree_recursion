#include "bin_tree.h"
#include <stdio.h>

int main() {

	treeNode* rootNode = createTree();

	printf("Height of tree is %d", treeDepth(rootNode));

	return 0;
}
