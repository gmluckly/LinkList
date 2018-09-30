#include<stdio.h>
// #include <stdlib.h>
// #include <malloc.h>
#include "linklist.h"
#include "stack.h"
#include "binaryTree.h"
#include "avlTree.h"

#include "sort.h"



int main()
{
	/*
	LinkList *list = createList(5);
	TraverseList(list);
	InsertList(list, 3, 10);
	TraverseList(list);
	UpdateElement(list, 3, 40);
	printf("update list,");
	TraverseList(list);
	printf("delete 3 position");
	DeleteList(list, 3);
	TraverseList(list);
	int posistion = SearchList(list, 5);
	printf("posistion is %d \n", posistion);
	*/
	Stack *stack = NULL;
	stack = push(stack, 1);
	stack = push(stack, 9);

	int stackValue = stackPop(stack);
	printf("pop stackVlue:%d \n", stackValue);


	//binaryTree
	int array[10] = { 5, 1, 3, 4, 2, 6, 9, 7, 8, 10 };
// 	BinaryTree *tree = createBinaryTree(array);
// 	preOrder(tree);

// 	BiTree T = NULL;
// 	for (int i = 0; i < 10; i++){
// 		AVLInsert(&T, array[i]);
// 	}
// 	printf("pre order:\n");
// 	AVLPreOrderTraverse(T);
// 	printf("\nin Order: \n");
// 	AVLInOrderTraverse(T);
	printf("\n");
// 	InsertSort(array, 10);
// 	printf("InsertSort result: \n ");
// 	for (int i = 0; i < 10; i++){
// 		printf(" %d ",array[i]);
// 	}
// 	printf("\n");
	int array2[10] = { 5,3,1,4,8,9,2};
	BubbleSort(array2, 7);
	printf("\n BubbleSort result: \n ");
	for (int i = 0; i < 10; i++){
		printf(" %d ", array2[i]);
	}
 
	int array3[10] = { 51, 101, 31, 41, 20, 60, 90, 70, 80, 10 };
	QuickSort(array3, 0, 9);
	printf("\n QuitSort result: \n");
	for (int i = 0; i < 10; i++)
	{
		printf(" %d ", array3[i]);
	}

	return 0;
}