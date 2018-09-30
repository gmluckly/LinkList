#include "avlTree.h"

/*
* ���������
* �����*TΪ�����Ķ���ƽ���������н��key������ʧ�ܣ���������FALSE��
* ���򽫽��key���뵽���У�������������ȻΪ����ƽ��������������TRUE��
*/
bool AVLInsert(BiTree *T, TElemType key)
{
	BiTree t;


	//�����ǰ���ҵĸ����Ϊ�������������޴˽�㣬�ʲ����㡣
	if (!*T)
	{
		t = (BiTree)malloc(sizeof(BiNode));
		t->data = key;
		t->height = 1;
		t->lchild = NULL;
		t->rchild = NULL;
		*T = t;
		return true;
	}
	//���д˽�㣬���ٲ��롣
	else if (key == (*T)->data)
	{
		return false;
	}
	//���������еݹ���롣
	else if (key < (*T)->data)
	{
		printf("T->data :%d ", (*T)->data);
		
		if (!AVLInsert(&((*T)->lchild), key))
			return false;
		else
		{
			//����ɹ����޸����ĸ߶ȡ�
			(*T)->height = max(GetHeight((*T)->lchild), GetHeight((*T)->rchild)) + 1;
			printf("height :%d \n", (*T)->height);
			//����*T��������������key���ж��Ƿ���Ҫ������ת�Ա��ֶ���ƽ���������ԡ�
			if (2 == GetHeight((*T)->lchild) - GetHeight((*T)->rchild))
			{	
				int a = GetHeight((*T)->lchild);
				int b = GetHeight((*T)->rchild);
				printf("left height:%d, right height: %d \n", a, b);
				//�����������������в����㡣
				if (GetHeight((*T)->lchild->lchild) > GetHeight((*T)->lchild->rchild))
				{
					LLRotate(T);
				}
				//�����������������в����㡣
				else
				{
					printf("111111111");
					LRRotate(T);
				}
			}
			return true;
		}
	}
	//���������еݹ���롣
	else // (key > (*T)->data)
	{
		if (!AVLInsert(&(*T)->rchild, key))
			return false;
		else
		{
			//����ɹ����޸����ĸ߶ȡ�
			(*T)->height = max(GetHeight((*T)->lchild), GetHeight((*T)->rchild)) + 1;

			//����*T��������������key���ж��Ƿ���Ҫ������ת�Ա��ֶ���ƽ���������ԡ�
			if (-2 == GetHeight((*T)->lchild) - GetHeight((*T)->rchild))
			{
				//�����������������в����㡣
				if (GetHeight((*T)->rchild->lchild) > GetHeight((*T)->rchild->rchild))
				{
					RLRotate(T);
				}
				//�����������������в����㡣
				else
				{
					RRRotate(T);
				}
			}
			return true;
		}
	}
}

/*
* ɾ��������
* �����*TΪ���������д��ڽ��key�������ɾ������������TRUE��
* ����ɾ��ʧ�ܣ���������FALSE��
*/
bool AVLDelete(BiTree *T, TElemType key)
{
	BiTree pre, post;

	//û���ҵ��ý�㡣
	if (!*T)
		return false;
	//�ҵ���㣬����ɾ����
	else if (key == (*T)->data)
	{
		//��ɾ���ڵ�ΪҶ�ӽ�㡣
		if (!(*T)->lchild && !(*T)->rchild)
			*T = NULL;
		//��ɾ�����ֻ���Һ��ӡ�
		else if (!(*T)->lchild)
			*T = (*T)->rchild;
		//��ɾ�����ֻ�����ӡ�
		else if (!(*T)->rchild)
			*T = (*T)->lchild;
		//��ɾ�����������ӣ������Һ��ӡ�
		else
		{
			//����ɾ�����*T�������ĸ߶ȴ����������ĸ߶�ʱ����*T��ǰ�����pre����*T��
			//�ٽ����pre������ɾ�����������Ա�֤ɾ�����������Ϊ����ƽ������
			if (GetHeight((*T)->lchild) > GetHeight((*T)->rchild))
			{
				//Ѱ��ǰ�����pre��
				pre = (*T)->lchild;
				while (pre->rchild)
				{
					pre = pre->rchild;
				}
				//��pre�滻*T��
				(*T)->data = pre->data;

				//ɾ���ڵ�pre��
				//��Ȼ�ܹ�ȷ��pre������С�����ĸ����Ϊ&pre��
				//���ǲ�����AVLDelete(&pre,pre->data)ɾ��pre��Ŀ���Ƿ���ݹ���Ľڵ�ĸ߶ȡ�
				AVLDelete(&((*T)->lchild), pre->data);
			}
			//����ɾ�����*T�������ĸ߶�С�ڻ��ߵ����������ĸ߶�ʱ����*T�ĺ�̽��post����*T��
			//�ٽ����post������ɾ�����������Ա�֤ɾ�����������Ϊ����ƽ������
			else
			{
				//Ѱ�Һ�̽ڵ�post��
				post = (*T)->rchild;
				while (post->lchild)
					post = post->lchild;
				//��post�滻*T��
				(*T)->data = post->data;

				//ɾ���ڵ�post��
				//��Ȼ�ܹ�ȷ��post������С�����ĸ����Ϊ&post��
				//���ǲ�����AVLDelete(&post,post->data)ɾ��post��Ŀ���Ƿ���ݹ���Ľڵ�ĸ߶ȡ�
				AVLDelete(&((*T)->rchild), post->data);
			}
		}
		return true;
	}
	//���������еݹ�ɾ����
	else if (key < (*T)->data)
	{
		if (!AVLDelete(&((*T)->lchild), key))
			return false;
		else
		{
			//ɾ���ɹ����޸����ĸ߶ȡ�
			(*T)->height = max(GetHeight((*T)->lchild), GetHeight((*T)->rchild)) + 1;
			//����*T��������ɾ�����key���ж��Ƿ���Ҫ������ת�Ա��ֶ���ƽ���������ԡ�
			if (-2 == GetHeight((*T)->lchild) - GetHeight((*T)->rchild))
			{
				if (GetHeight((*T)->lchild->lchild) > GetHeight((*T)->lchild->rchild))
				{
					LLRotate(T);
				}
				else
				{
					LRRotate(T);
				}
			}
			return true;
		}
	}
	//���������еݹ�ɾ����
	else
	{
		if (!AVLDelete(&((*T)->rchild), key))
			return false;
		else
		{
			//ɾ���ɹ����޸����ĸ߶ȡ�
			(*T)->height = max(GetHeight((*T)->lchild), GetHeight((*T)->rchild)) + 1;
			//����*T��������ɾ�����key���ж��Ƿ���Ҫ������ת�Ա��ֶ���ƽ���������ԡ�
			if (2 == GetHeight((*T)->lchild) - GetHeight((*T)->rchild))
			{
				if (GetHeight((*T)->rchild->lchild) > GetHeight((*T)->rchild->rchild))
				{
					RLRotate(T);
				}
				else
				{
					RRRotate(T);
				}
			}
			return true;
		}
	}
}

/*
* ��T�����������������ϵĽڵ�ʹ��T��ƽ���Ϊ2ʱ����TΪ���Ľ���������
*/
bool LLRotate(BiTree *T)
{
	BiTree lc;
	lc = (*T)->lchild;
	(*T)->lchild = lc->rchild;
	lc->rchild = (*T);

	//ע��Ҫ���½��ĸ߶ȡ���������ֻ��*T����������lc�������������˱仯������ֻ��������������ĸ߶ȡ�
	(*T)->height = max(GetHeight((*T)->lchild), GetHeight((*T)->rchild)) + 1;
	lc->height = max(GetHeight(lc->lchild), GetHeight(lc->rchild)) + 1;

	*T = lc;
	return true;
}

/*
* ��T�����������������ϵĽڵ�ʹ��T��ƽ���Ϊ2ʱ��
* ����T��������Ϊ���Ľ�������������TΪ���Ľ���������
*/
bool LRRotate(BiTree *T)
{
	RRRotate(&((*T)->lchild));
	LLRotate(T);
	return true;
}

/*
* ��T�����������������ϵĽڵ�ʹ��T��ƽ���Ϊ-2ʱ��
* ����T��������Ϊ���Ľ�������������TΪ���Ľ���������
*/
bool RLRotate(BiTree *T)
{
	LLRotate(&((*T)->rchild));
	RRRotate(T);
	return true;
}

/*
* ��T�����������������ϵĽڵ�ʹ��T��ƽ���Ϊ-2ʱ����TΪ���Ľ���������
*/
bool RRRotate(BiTree *T)
{
	BiTree rc;
	rc = (*T)->rchild;
	(*T)->rchild = rc->lchild;
	rc->lchild = (*T);

	//ע��Ҫ���½��ĸ߶ȡ���������ֻ��*T����������lc�������������˱仯������ֻ��������������ĸ߶ȡ�
	(*T)->height = max(GetHeight((*T)->lchild), GetHeight((*T)->rchild)) + 1;
	rc->height = max(GetHeight(rc->lchild), GetHeight(rc->rchild)) + 1;

	*T = rc;
	return true;
}

/*
* ��T=NULL ,����Ϊ����ʱ���޷�ͨ��T->height��ȡ���ĸ߶�0������Ҫ�����д�ú�����
*/
int GetHeight(BiTree T)
{
	if (T)
		return T->height;
	return 0;
}

bool AVLPreOrderTraverse(BiTree T){
	if (T)
	{
		printf("%-3d ", T->data);
		AVLPreOrderTraverse(T->lchild);
		AVLPreOrderTraverse(T->rchild);
	}
	return true;
}


bool AVLInOrderTraverse(BiTree T)
{
	if (T)
	{
		AVLInOrderTraverse(T->lchild);
		printf("%-3d ", T->data);
		AVLInOrderTraverse(T->rchild);
	}
	return true;
}
