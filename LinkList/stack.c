#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>
#include "stack.h"




Stack * push(Stack *stack, int value){
	Stack *line = (Stack*)malloc(sizeof(Stack));
	line->data = value;
	line->next = stack;
	stack = line;
	return stack;
}

int stackPop(Stack *stack){
	int tmp = 0;
	if (stack){
		Stack *p = stack;
		stack = stack->next;
		tmp = p->data;
		printf("pop value:",tmp);
	}
	else{
		printf("there are no data in stack");
	}
	return  tmp;
}


void stackDestroy(Stack *stack){
	stack->next = NULL;
	free(stack);
}