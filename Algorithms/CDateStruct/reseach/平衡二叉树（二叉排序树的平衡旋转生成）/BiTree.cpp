#include "Status.h"
#define ET 1//ֻҪÿ��Դ�ļ���������ͷ�ļ�����QElemType.h�����붨��ET
#include "BiTree.h"
#include "LinkQueue.h"//�������"QElemType.h"���а���"BiTree.h",����"BiTree.h"��Ӧ��ͷ�ļ���������������ظ�����
//C++
#include <stack>
#include <vector>
#include <list>
#define ClearBiTree DestroyBiTree //��ն�������ͬ���ٶ�������

using namespace std;

void InitBiTree(BiTree &T)
{//��ʼ��������Ϊ�ն�����
	T = NULL;
}

void DestroyBiTree(BiTree &T)
{//�������ٶ���������Ϊ���ֱ���˳��Ĳ�������Ϊ���������������--�������������--���ʸ��ڵ㣬�ȷ��ʸ��ڵ�Ļ����޷������������ˣ�
	if (T)
	{
		DestroyBiTree(T->lchild);//�ݹ����,Tָ��������
		DestroyBiTree(T->rchild);//�ݹ����,Tָ��������
		free(T);//�ͷŽ��
		T = NULL;
	}
}

void PreOrderTraverse(BiTree T, void (*visit)(TElemType))
{//���������������
	if (T)
	{
		visit(T->data);//�ȷ��ʸ��ڵ�
		PreOrderTraverse(T->lchild,visit);//���������������
		PreOrderTraverse(T->rchild,visit);//����������������
	}
}

void InOrderTraverse(BiTree T, void (*visit)(TElemType))
{
	if (T)
	{
		InOrderTraverse(T->lchild, visit);//���������������
		visit(T->data);                   //�ٷ��ʸ��ڵ�
		InOrderTraverse(T->rchild, visit);//����������������
	}
}

void PostOrderTraverse(BiTree T, void (*visit)(TElemType))
{
	if (T)
	{
		PostOrderTraverse(T->lchild,visit);//�Ⱥ������������
		PostOrderTraverse(T->rchild,visit);//�ٺ������������
		visit(T->data);//�����ʸ��ڵ�
	}
}

Status BiTreeEmpty(BiTree &T)
{//���������п�
	if (!T)
	{//��������Ϊ��
		return TRUE;
	}
	else
	{//��������Ϊ��
		return FALSE;
	}
}

int BiTreeDepth(BiTree &T)
{//���ض��������
	int i,j;
	if (!T)
	{//������Ϊ���򷵻�0
		return 0;
	}
	i = BiTreeDepth(T->lchild);//iΪ����������ȣ���������Ϊ�գ���iΪ0��
	j = BiTreeDepth(T->rchild);//jΪ����������ȣ���������Ϊ�գ���jΪ0��
	return i > j ? i + 1: j + 1;//T�����Ϊ�����еĴ��߼�1��
}

TElemType Root(BiTree &T)
{//���ض�����T�ĸ�
	if (T)
	{
		return T->data;
	}
	else
	{
		return Nil;
	}
}

TElemType value(BiTree p)
{//����p��ָ��������Ԫ��
	return p->data;
}

void Assign(BiTree p, TElemType value)
{//��p��ָ��������Ԫ�ظ�ֵΪvalue
	p->data = value;
}

Status DeleteChild(BiTree p, int LR)
{//ɾ��p����������������
	if (p)
	{
		if (0 == LR)
		{//���������
			ClearBiTree(p->lchild);
		}
		else
		{//���������
			ClearBiTree(p->rchild);
		}
		return OK;
	}
	return ERROR;
}

void LevelOrderTraverse(BiTree T, void(*visit)(TElemType))
{//�������������
	LinkQueue q;
	BiTree p;
	if (T)
	{
		InitQueue(q);
		EnQueue(q,T);
		while (!IsQueueEmpty(q))
		{
			DelQueue(q,p);
			visit(p->data);//����Ԫ��
			if (p->lchild != NULL)
			{
				EnQueue(q, p->lchild);
			}
			if (p->rchild != NULL)
			{
				EnQueue(q, p->rchild);
			}
		}
		printf("\n"); 
	}
}

Status InsertChild(BiTree p, int LR, BiTree c)
{//�����������eΪ��������������
	if (p)
	{
		if (LR = 0)
		{
			c->rchild = p->lchild;
			p->lchild = c;
		}
		else
		{
			c->rchild = p->rchild;
			p->rchild = c;
		}
		return OK;
	}
	return ERROR;
}

void InOrderTraverse1(BiTree T, void(*visit)(TElemType))
{//�������������
	stack<BiTree,vector<BiTree>> S;//ջ��C++�е�����������stack
	while (T || !S.empty())
	{
		if (T)
		{
			S.push(T);
			T = T->lchild;
		}
		else
		{
			T = S.top();
			S.pop();
			visit(T->data);
			T = T->rchild;
		}

	}
	printf("\n");

}