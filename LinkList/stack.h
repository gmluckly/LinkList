
typedef struct Stack
{
	int data;
	struct Stack *next;
}Stack;

Stack *push(Stack *stac,int v);
int stackPop(Stack *stack);
void stackDestroy(Stack *stack);