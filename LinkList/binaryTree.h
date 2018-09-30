#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct BinaryTree{
	int data;
	int height;
	struct BinaryTree *left;
	struct BinaryTree *right;
}BinaryTree;

// const int  num = 100;
// BinaryTree tree[num];



BinaryTree* createBinaryTree(int array [10]);
BinaryTree* searchBinaryTree(BinaryTree *tree);
void insertBinaryTreeNode(BinaryTree *tree, int value);

void preOrder(BinaryTree *tree);
