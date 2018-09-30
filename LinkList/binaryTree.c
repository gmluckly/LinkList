#include "binaryTree.h"

#define ARRAY_SIZE(x) (sizeof(x)/sizeof((x)[0]))

BinaryTree * createBinaryTree(int array [10]){
	BinaryTree *tree = (BinaryTree*)malloc(sizeof(BinaryTree));
	tree->data = array[0];
	tree->height = 0;
	tree->left = NULL;
	tree->right = NULL;
	printf("The array is:\n");
	for (int i = 0; i < 10; i++){
		printf("%d ", array[i]);
	}

	int len = 10;
	for (int i = 2;i <= len;i++)
	{
		insertBinaryTreeNode(tree, array[i-1]);
	}
	return tree;
}


void insertBinaryTreeNode(BinaryTree *tree,  int value){
	BinaryTree * node = NULL;
	BinaryTree *p = tree, *p_last = NULL;
	node = (BinaryTree *)malloc(sizeof(BinaryTree));
	node->data = value;
	node->height = 0;
	node->left = NULL;
	node->right = NULL;
	//printf("value: %d", value);
	while (p!=NULL)
	{
		p_last = p;
		if (node->data < p->data){
			p = p->left;
		}else if (node ->data > p->data){
			p = p->right;
		}
		else{
			free(node);
			printf("there is the same data in tree");
			return;
		}
	}
	p = p_last;
	printf("value:%d,pre data,%d, height:%d \n", value,p->data,p->height);
	if (node->data < p->data){
		p->left = node;
	}
	else{
		p->right = node;
	}
}


//先序遍历的递归
void preOrder(BinaryTree *tree)
{
	if (tree)
	{
		//vi(tree->data);			//访问结点
		printf("%d ", tree->data);
		preOrder(tree->left);       //遍历左子树
		preOrder(tree->right);      //遍历右子树
	}
}
