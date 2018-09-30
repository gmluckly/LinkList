#include <stdio.h>
#include <stdlib.h>    //�ں�max(a,b)�꣬�ʲ����Լ���д��
#include <stdbool.h>

/*
* �������Ķ�������洢�ṹ��
* ����������ĸ߶ȣ����жϽ���ƽ��ȡ�
*/
typedef int TElemType;
typedef struct BiNode
{
	TElemType data;
	struct BiNode *lchild;
	struct BiNode *rchild;
	int height;
}BiNode, *BiTree;

//��������
bool AVLInsert(BiTree *T, TElemType key);
bool AVLDelete(BiTree *T, TElemType key);
bool LLRotate(BiTree *T);
bool LRRotate(BiTree *T);
bool RLRotate(BiTree *T);
bool RRRotate(BiTree *T);
int GetHeight(BiTree T);
bool AVLInOrderTraverse(BiTree T);
bool AVLPreOrderTraverse(BiTree T);
