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
		visit(T->date);//�ȷ��ʸ��ڵ�
		PreOrderTraverse(T->lchild,visit);//���������������
		PreOrderTraverse(T->rchild,visit);//����������������
	}
}

void InOrderTraverse(BiTree T, void (*visit)(TElemType))
{
	if (T)
	{
		InOrderTraverse(T->lchild, visit);//���������������
		visit(T->date);                   //�ٷ��ʸ��ڵ�
		InOrderTraverse(T->rchild, visit);//����������������
	}
}

void PostOrderTraverse(BiTree T, void (*visit)(TElemType))
{
	if (T)
	{
		PostOrderTraverse(T->lchild,visit);//�Ⱥ������������
		PostOrderTraverse(T->rchild,visit);//�ٺ������������
		visit(T->date);//�����ʸ��ڵ�
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
		return T->date;
	}
	else
	{
		return Nil;
	}
}

TElemType value(BiTree p)
{//����p��ָ��������Ԫ��
	return p->date;
}

void Assign(BiTree p, TElemType value)
{//��p��ָ��������Ԫ�ظ�ֵΪvalue
	p->date = value;
}

BiTree Point(BiTree T, TElemType e)
{//����Ԫ��ֵΪe�Ľ��ָ��
	LinkQueue q;//���е�Ԫ������Ϊָ�����������ָ��
	QElemType p;
	if (T)
	{//�ǿ���
		InitQueue(q);//��ʼ������
		EnQueue(q,T);//��ָ�����
		while(!IsQueueEmpty(q))
		{
			DelQueue(q,p);//�ӳ���һ�����ָ�룬����ֵ����p
			if (e == p->date)
			{//��ɾ���Ľ��ָ����ָ��Ԫ��Ϊ���ҵ�Ԫ�أ��򷵻ظ�ָ��
				return p;
			}
			if (p->lchild)//������
			{
				EnQueue(q,p->lchild);//���������ָ��
			}
			if (p->rchild)//���Һ���
			{
				EnQueue(q,p->rchild);//����� ����ָ��
			}
		}
	}
	return NULL;
}

TElemType LeftChild(BiTree T, TElemType e)
{//����e������
	if (T)
	{
		BiTree p = Point(T,e);//��e�����ڽ��ָ�븳ֵ��p
		if (p && p->lchild)
		{//p�ǿ����������ӣ��򷵻����ӵ�ֵ
			return p->lchild->date;
		}
	}
	return Nil;
}

TElemType RightChild(BiTree T, TElemType e)
{//����e���Һ���
	if (T)
	{
		BiTree p = Point(T,e);//��e�����ڽ��ָ�븳ֵ��p
		if (p && p->rchild)
		{//p�ǿ��������Һ��ӣ��򷵻��Һ��ӵ�ֵ
			return p->rchild->date;
		}
	}
	return Nil;
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
			visit(p->date);//����Ԫ��
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


void CreatBiTree(BiTree &T)
{//����������������Ϊ���ֱ���˳��Ĳ�������Ϊ�����ʸ��ڵ�--�������������--������������������ȷ��ʸ��ڵ�Ļ����޷������������ˣ�
	TElemType ch;
	scanf(form"",&ch);

	if (ch == Nil)
	{//������Nil��T������
		T = NULL;
	}
	else
	{
		if (!(T = (BiTNode *)malloc(sizeof(BiTNode))))
		{//��̬�������ڵ�
			exit (0);
		}
		T->date = ch;//��������
		CreatBiTree(T->lchild);//�ݹ����,Tָ��������
		CreatBiTree(T ->rchild);//�ݹ����,Tָ��������
	}

}

TElemType Parent(BiTree T, TElemType e)
{//����e��˫�׽��
	LinkQueue q;
	BiTree p;
	if (T)
	{
		InitQueue(q);
		EnQueue(q,T);
		while (!IsQueueEmpty(q))
		{
			DelQueue(q,p);
			if (p->lchild && e == p->lchild->date || p->lchild && e == p->rchild->date)
			{//��p��ָ�����������ֵΪe�����Һ�����ֵΪe
				return p->date;
			}
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
	return Nil;
}

TElemType LeftSibling(BiTree T, TElemType e)
{//����e�����ֵ�
	TElemType a;
	BiTree p;
	if (T)
	{
		a = Parent(T,e);
		if (a != Nil)
		{
			p = Point(T,a);
			if (p->rchild && e == p->rchild->date && p->lchild)
			{
				return p->lchild->date;
			}
		}
	}
	return Nil;
}

TElemType RightSibling(BiTree T, TElemType e)
{//����e�����ֵ�
	TElemType a;
	BiTree p;
	if (T)
	{
		a = Parent(T,e);
		if (a != Nil)
		{
			p = Point(T,a);
			if (p->lchild && e == p->lchild->date && p->rchild)
			{
				return p->rchild->date;
			}
		}
	}
	return Nil;
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
			visit(T->date);
			T = T->rchild;
		}

	}
	printf("\n");

}