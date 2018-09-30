#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include "linklist.h"
/*
typedef  int ElementType;

typedef struct ListNode {
	ElementType Element;  //data
	struct ListNode *Next;    // point to the next node
}LinkList;
*/
LinkList *createList(int n){
	LinkList *head, *node, *end;
	head = malloc(sizeof(LinkList));
	end = head;
	printf("Please enter the value of list \n");
	for (int i = 0; i < n; i++){
		node = malloc(sizeof(LinkList));
		scanf_s("%d", &node->Element);
		end->Next = node;
		end = node;
	}
	end->Next = NULL;
	return head;
}

void TraverseList(LinkList *list){
	LinkList *p = list->Next;
	printf("Linklist is: ");
	if (p == NULL){
		printf("LinkList is empty");
	}
	while (p != NULL){
		printf("%d ", p->Element);
		p = p->Next;
	}

	printf("\n");
}

void InsertList(LinkList *list, int pos, int val){
	int position = 0;
	LinkList *p = list;
	while (p != NULL && position < pos -1){
		p = p->Next;
		++position;
	}
	LinkList *tmp = malloc(sizeof(LinkList));
	if (tmp == NULL)
	{
		printf("m err!");
		exit(-1);
	}

	tmp->Element = val;
	tmp->Next = p->Next;
	p->Next = tmp;
}

void UpdateElement(LinkList *list, int pos, int value){
	LinkList *p = list;
	for (int i = 0; i < pos; i++)
	{
		p = p->Next;
	}
	if (p != NULL){
		p->Element = value;
	}
	else{
		printf("node can not find");
	}
}


void DeleteList(LinkList *list, int pos){
	// find out the  pre node *p; make tmp = p's next which want to delete,
	// and point the p->next to tmp-> next ;and free tmp
	LinkList *p = list;
	for (int i = 0; i < pos-1; i++)
	{
		p = p->Next;
	}
	if (p != NULL){
		LinkList *tmp = p ->Next;
		p->Next = tmp->Next;
		free(tmp);
		tmp = NULL;
	}
}

int SearchList(LinkList *list, int value){
	int pos = 0;
	LinkList *p = list;
	while (p != NULL && p->Element != value) {
		p = p->Next;
		++pos;
	}
	if (p == NULL)
	{
		pos = 0;
	}
	return pos;
}



/* 
int main()
{
	LinkList *list = createList(5);
	TraverseList(list);
	InsertList(list, 3, 10);
	TraverseList(list);
	UpdateElement(list, 3, 40);
	printf("update list,");
	TraverseList(list);
	printf("delete 3 pos");
	DeleteList(list, 3);
	TraverseList(list);
	int pos = SearchList(list, 5);
	printf("pos is %d \n", pos);

}

*/