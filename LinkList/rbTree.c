#include "rbTree.h"

RBT_Root * rbTreeInit(void)
{
	RBT_Root *T;
	T = (RBT_Root*)malloc(sizeof(RBT_Root));
	T->nil = (RB_TREE *)malloc(sizeof(RB_TREE));
	T->nil->color = BLACK;
	T->nil->left = NULL;
	T->nil->right = NULL;
	T->nil->p = NULL;
	T->root = T->nil;
	return T;
}

//插入操作分为 3 步：
//1、将红黑树当二叉查找树，找到其插入位置；
//2、初始化插入结点，将新结点的颜色设为红色；
//3、通过调用调整函数，将二叉查找树重新改为红黑树
void rbtree_insert(RBT_Root *T, int key)
{
	//1、找到其
	RB_TREE *p, *x;
	x = T->root;
	p = x;
	while (x != T->nil){
		p = x;
		if (key < p->key){
			x = x->left;
		}
		else if (key > p->key){
			x = x->right;
		}
		else{
			printf("已经存在");
			return;
		}
	}
	printf("p->key:%d", p->key);
	x = (RB_TREE*)malloc(sizeof(RB_TREE));
	x->color = RED;
	x->key = key;
	x->left = x->right = T->nil;
	x->p = p;
	//对新插入的结点，建立与其父结点之间的联系
	if (T->root == T->nil){
		x->color = BLACK;
		T->root = x;
	} else if (key < p->key)
	{
		p->left = x;
	}
	else{
		p->right = x;
	}
	RB_Insert_Fixup(T, x);
}

void RB_Insert_Fixup(RBT_Root* T, RB_TREE* x)
{
	//首先判断其父结点颜色为红色时才需要调整；为黑色时直接插入即可，不需要调整

	while (x != NULL && x->p->color == RED)
	{
		// 由于还涉及到其叔叔结点，所以此处需分开讨论，确定父结点是祖父结点的左孩子还是右孩子
		if (x->p = x->p->p->left){
			RB_TREE *y = x->p->p->right;//找到其叔叔结点
			//如果叔叔结点颜色为红色，此为第 1 种情况，处理方法为：父结点颜色改为黑色；叔叔结点颜色改为黑色；
			//祖父结点颜色改为红色，将祖父结点赋值为当前结点，继续判断；
			if (y->color = RED){
				x->p->color = BLACK;
				y->color = BLACK;
				y->p->p->color = RED;
				x = x->p->p;
			}
			else{
				//反之，如果叔叔结点颜色为黑色，此处需分为两种情况：1、当前结点是父结点的右孩子；
				//2、当前结点是父结点的左孩子
				if (x = x->p->right)
				{
					//第 2 种情况：当前结点时父结点的右孩子。解决方案：将父结点作为当前结点做左旋操作。
					x = x->p;
					if (x != NULL){
						rbTree_left_rotate(T, x);
					}
				}
				else{
					//第 3 种情况：当前结点是父结点的左孩子。解决方案：将父结点颜色改为黑色，祖父结点颜色改为红色，
					//从祖父结点处进行右旋处理。
					x->p->color = BLACK;
					x->p->p->color = RED;
					rbTree_right_rotate(T, x->p->p);
				}
			}
		}
		else{
			// 如果父结点是祖父结点的右孩子，换汤不换药，只需将以上代码部分中的left改为right即可，道理是一样的。
			RB_TREE *y = x->p->p->left;
			if (y->color == RED){
				x->p->color = BLACK;
				y->color = BLACK;
				y->p->p->color = RED;
				x = x->p->p;
			}
			else{
				if (x = x->p->left){
					x = x->p;
					if (x != NULL){
						rbTree_right_rotate(T, x);
					}
				}
				else{
					x->p->color = BLACK;
					x->p->p->color = RED;
					rbTree_left_rotate(T, x->p->p);
				}
			}
		}

	}
	if (x != NULL){
		x->p->color = BLACK;
	}
}

//T表示为数根，x 表示为需要左旋转的子树根节点
void rbTree_left_rotate(RBT_Root *T, RB_TREE *x)
{
	RB_TREE *y = x->right;
	x->right = y->left;//将右子树的左孩子移动至结点 x 的右孩子处
	if (x->right != T->nil) {//如果 x 的右子树不是nil，需重新连接 右子树的双亲结点为 x
		x->right->p = x;
	}
	y->p = x->p;//设置 y 的双亲结点为 x 的双亲结点
	//重新设置 y 的双亲结点同 y 的连接，分为 2 种情况：1、原 x 结点本身就是整棵树的数根结点，此时只需要将 T 指针指向 y；
	//2、根据 y 中关键字同其父结点关键字的值的大小，判断 y 是父结点的左孩子还是右孩子
	if (y->p == T->nil){
		T->root = y;
	}else if (y->key < y->p->key)
	{
		y->p->left = y;
	}
	else
	{
		y->p->right = y;
	}

	y->left = x; //将 x 连接给 y 结点的左孩子处
	x->p = y; //设置 x 的双亲结点为 y。
}

void rbTree_right_rotate(RBT_Root *T, RB_TREE *x){
	RB_TREE *y = x->left;
	x->left = y->right;
	if (T->nil ==x->left)
	{
		x->left->p = x;
	}
	y->p = x->p;
	if (y->p == T->nil){
		T->root = y;
	}else if (y->key < y->p->key)
	{
		y->p->right = y;
	}
	else{
		y->p->left = y;
	}
	y->right = x;
	x->p = y;
}



void RB_Delete_Fixup(RBT_Root *T, RB_TREE *x){
	while (x != T->root && x->color == BLACK)
	{
		if (x == x->p ->left)
		{
			RB_TREE *w = x->p->right;
			// 兄弟节点是红色
			if (w->color == RED){
				w->color = BLACK;
				w->p->color = RED;
				rbTree_left_rotate(T, w->p);
				w = x->p->right;
			}
			//第2种情况：兄弟是黑色的，并且兄弟的两个儿子都是黑色的。
			if (w->color == BLACK && w->left->color == BLACK && w->right->color ==BLACK)
			{
				w->color = RED;
				x = x->p;
			}
			//第3种情况
			if (w->left->color == RED && w->right->color == BLACK){
				w->color = RED;
				w->left->color = BLACK;
				rbTree_right_rotate(T, w);
				w = w->p->right;
			}
			//第4种情况
			if (w->right->color == RED)
			{
				w->color = w->p->color;
				x->p->color = BLACK;
				w->right->color = BLACK;
				rbTree_left_rotate(T, x->p);
				x = T->root;
			}
		}
		else{
			RB_TREE* w = x->p->left;
			if (w->color == RED)
			{
				w->color = BLACK;
				w->p->color = RED;
				rbTree_right_rotate(T, x->p);
				w = x->right->p;
			}
			if (w->color == BLACK && w->left->color==BLACK && w->right->color ==BLACK)
			{
				w->color = RED;
				x = x->p;
			}
			if (w->left->color ==BLACK && w->right->color ==RED)
			{
				w->color = RED;
				w->right->color = BLACK;
				//rbTree_right_rotate(T, w);
				w = w->p->left;
			}
			if (w->right->color == BLACK){
				w->color =w->p->color;
				x->p->color = BLACK;
				x->p->left->color= BLACK;
				rbTree_right_rotate(T, x->p);
				x = T->root;
			}
		}
	}
	x->color = BLACK; //将根节点设为黑色
}

RB_TREE* rbtree_find_min(RBT_Root *T, RB_TREE *x)
{
	if (x == T->nil){
		return T->nil;
	}
	while (x->left != T->nil){
		x = x->left;
	}
	return x;
}

void rbtree_delete(RBT_Root *T, int key)
{
	if (T->root == NULL)
	{
		return;
	}
	RB_TREE *d = T->nil;
	RB_TREE *x = NULL;
	while (d->key !=key && d != T->nil)
	{
		if (key < d->key)
		{
			d = d->left;
		}
		else{
			d = d->right;
		}
	}
	if (d == T->nil){
		printf("the node is not exist");
		return;
	}
	if (d->left != T->nil && d->right != T->nil)
	{
		//TODO 处理存在左右节点都存在的情况
		RB_TREE *p = rbtree_find_min(T, d->right);
		key = d->key = p->key;
		d = p;
	}
	//如果只有一个孩子结点（只有左孩子或只有右孩子），直接用孩子结点顶替该结点位置即可（没有孩子结点的也走此判断语句）。
	if (d->left == T->nil){
		x = d->right;
		rbtree_transplant(T, d, d->right);
	}else if (d->right == T->nil)
	{
		x = d->left;
		rbtree_transplant(T, d, d->left);
	}
	if (d->color == BLACK)
	{
		RB_Delete_Fixup(T, x);
	}

	free(d);
}

void rbtree_transplant(RBT_Root* T, RB_TREE* u, RB_TREE* v)
{
	if (u->p == T->nil)
	{
		T->root = v;
	}else if (u == u->p->left)
	{
		u->p->left = v;
	}
	else{
		u->p->right = v;
	}
	v->p = u->p;
}


void rbTree_inPrint(RBT_Root* T, RB_TREE* t)
{
	if (T->nil == t){
		return;
	}
	rbTree_inPrint(T, t->left);
	if (t->color == RED){
		printf("%dR ", t->key);
	}
	else{
		printf("%dB ", t->key);
	}
	rbTree_inPrint(T, t->right);
}


void rbTree_prePrint(RBT_Root *T, RB_TREE* t)
{
	if (T->nil == t)
	{
		return;
	}
	if (t->color == RED)
	{
		printf("%dR ", t->key);
	}
	else{
		printf("%dB ", t->key);
	}
	rbTree_prePrint(T, t->left);
	rbTree_prePrint(T, t->right);
}