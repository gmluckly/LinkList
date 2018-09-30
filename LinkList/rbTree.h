#include <stdio.h>
#include <stdlib.h>

typedef enum{RED,BLACK} ColorType;
typedef struct RB_TREE{
	int key;
	struct RB_TREE *left;
	struct RB_TREE *right;
	struct RB_TREE *p;
	ColorType color;
}RB_TREE;

typedef struct RBT_Root{
	RB_TREE *root;
	RB_TREE *nil;
}RBT_Root;

RBT_Root * rbTreeInit(void);
void rbtree_insert(RBT_Root *T, int key);
void RB_Insert_Fixup(RBT_Root* T, RB_TREE* x);
void rbtree_delete(RBT_Root *T, int key);
void RB_Delete_Fixup(RBT_Root *T, RB_TREE *x);
void rbTree_left_rotate(RBT_Root *T, RB_TREE *x);
void rbTree_right_rotate(RBT_Root *T, RB_TREE *x);
RB_TREE* rbtree_find_min(RBT_Root *T, RB_TREE *x);

void rbtree_transplant(RBT_Root* T, RB_TREE* u, RB_TREE* v);
void rbTree_inPrint(RBT_Root* T, RB_TREE* t);
