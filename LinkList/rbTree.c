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

//���������Ϊ 3 ����
//1�����������������������ҵ������λ�ã�
//2����ʼ�������㣬���½�����ɫ��Ϊ��ɫ��
//3��ͨ�����õ�����������������������¸�Ϊ�����
void rbtree_insert(RBT_Root *T, int key)
{
	//1���ҵ���
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
			printf("�Ѿ�����");
			return;
		}
	}
	printf("p->key:%d", p->key);
	x = (RB_TREE*)malloc(sizeof(RB_TREE));
	x->color = RED;
	x->key = key;
	x->left = x->right = T->nil;
	x->p = p;
	//���²���Ľ�㣬�������丸���֮�����ϵ
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
	//�����ж��丸�����ɫΪ��ɫʱ����Ҫ������Ϊ��ɫʱֱ�Ӳ��뼴�ɣ�����Ҫ����

	while (x != NULL && x->p->color == RED)
	{
		// ���ڻ��漰���������㣬���Դ˴���ֿ����ۣ�ȷ����������游�������ӻ����Һ���
		if (x->p = x->p->p->left){
			RB_TREE *y = x->p->p->right;//�ҵ���������
			//�����������ɫΪ��ɫ����Ϊ�� 1 �������������Ϊ���������ɫ��Ϊ��ɫ����������ɫ��Ϊ��ɫ��
			//�游�����ɫ��Ϊ��ɫ�����游��㸳ֵΪ��ǰ��㣬�����жϣ�
			if (y->color = RED){
				x->p->color = BLACK;
				y->color = BLACK;
				y->p->p->color = RED;
				x = x->p->p;
			}
			else{
				//��֮�������������ɫΪ��ɫ���˴����Ϊ���������1����ǰ����Ǹ������Һ��ӣ�
				//2����ǰ����Ǹ���������
				if (x = x->p->right)
				{
					//�� 2 ���������ǰ���ʱ�������Һ��ӡ�������������������Ϊ��ǰ���������������
					x = x->p;
					if (x != NULL){
						rbTree_left_rotate(T, x);
					}
				}
				else{
					//�� 3 ���������ǰ����Ǹ��������ӡ�������������������ɫ��Ϊ��ɫ���游�����ɫ��Ϊ��ɫ��
					//���游��㴦������������
					x->p->color = BLACK;
					x->p->p->color = RED;
					rbTree_right_rotate(T, x->p->p);
				}
			}
		}
		else{
			// �����������游�����Һ��ӣ���������ҩ��ֻ�轫���ϴ��벿���е�left��Ϊright���ɣ�������һ���ġ�
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

//T��ʾΪ������x ��ʾΪ��Ҫ����ת���������ڵ�
void rbTree_left_rotate(RBT_Root *T, RB_TREE *x)
{
	RB_TREE *y = x->right;
	x->right = y->left;//���������������ƶ������ x ���Һ��Ӵ�
	if (x->right != T->nil) {//��� x ������������nil������������ ��������˫�׽��Ϊ x
		x->right->p = x;
	}
	y->p = x->p;//���� y ��˫�׽��Ϊ x ��˫�׽��
	//�������� y ��˫�׽��ͬ y �����ӣ���Ϊ 2 �������1��ԭ x ��㱾�������������������㣬��ʱֻ��Ҫ�� T ָ��ָ�� y��
	//2������ y �йؼ���ͬ�丸���ؼ��ֵ�ֵ�Ĵ�С���ж� y �Ǹ��������ӻ����Һ���
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

	y->left = x; //�� x ���Ӹ� y �������Ӵ�
	x->p = y; //���� x ��˫�׽��Ϊ y��
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
			// �ֵܽڵ��Ǻ�ɫ
			if (w->color == RED){
				w->color = BLACK;
				w->p->color = RED;
				rbTree_left_rotate(T, w->p);
				w = x->p->right;
			}
			//��2��������ֵ��Ǻ�ɫ�ģ������ֵܵ��������Ӷ��Ǻ�ɫ�ġ�
			if (w->color == BLACK && w->left->color == BLACK && w->right->color ==BLACK)
			{
				w->color = RED;
				x = x->p;
			}
			//��3�����
			if (w->left->color == RED && w->right->color == BLACK){
				w->color = RED;
				w->left->color = BLACK;
				rbTree_right_rotate(T, w);
				w = w->p->right;
			}
			//��4�����
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
	x->color = BLACK; //�����ڵ���Ϊ��ɫ
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
		//TODO ����������ҽڵ㶼���ڵ����
		RB_TREE *p = rbtree_find_min(T, d->right);
		key = d->key = p->key;
		d = p;
	}
	//���ֻ��һ�����ӽ�㣨ֻ�����ӻ�ֻ���Һ��ӣ���ֱ���ú��ӽ�㶥��ý��λ�ü��ɣ�û�к��ӽ���Ҳ�ߴ��ж���䣩��
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