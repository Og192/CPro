#define ET 1
#include "BiThrTree.h"
#include <malloc.h>

void CreatBiThrTree (BiThrTree &T)//��������������T
{
	TElemType ch;
	scanf(form, &ch);
	if (ch == Nil)
	{
		T = NULL;
	}
	else
	{
		T = (BiThrTree)malloc(sizeof(BiThrNode));//������
		if (!T)
		{
			exit (OVERFLOW);		
		}
		T->data = ch;
		CreatBiThrTree (T->lchild);//����������
		if (T->lchild)
		{//T��ָ�Ľ�������ӣ������־ΪLink
			T->LTag = Link;
		}
		CreatBiThrTree(T->rchild);//����������
		if (T->rchild)
		{//T��ָ�Ľ�����Һ��ӣ����ұ�־ΪLink
			T->RTag = Link;
		}
	}
}

BiThrTree pre;
void InThreading (BiThrTree p)//�������������
{
	if (p)
	{
		InThreading (p->lchild);//������������
		if (!p->lchild)
		{//p��ǰ������
			p->LTag = Thread;
			p->lchild = pre;
		}
		if (!pre->rchild)
		{//pre�ĺ������
			pre->RTag = Thread;
			pre->rchild = p;
		}
		pre = p;//����preָ��p��ǰ��
		InThreading (p->rchild);//������������
	}
}
void InOrderThreading(BiThrTree &Thrt, BiThrTree T)//����������
{
	if (!(Thrt = (BiThrTree)malloc(sizeof(BiThrNode))))
	{
		exit (OVERFLOW);
	}
	Thrt->LTag = Link;
	Thrt->RTag = Thread;
	Thrt->rchild = Thrt;
	if (!T)
	{
		Thrt->lchild = Thrt;
	}
	else
	{		
		Thrt->lchild = T;
		pre = Thrt;
		InThreading (T);
		pre->RTag = Thread;
		pre->rchild = Thrt;
		Thrt->rchild = pre;
	}
}
void InOrderTraverse_Thr (BiThrTree T, void (*visit)(TElemType))//�����������������
{//TΪͷ���
	BiThrTree p = T->lchild;
	while (p != T)
	{
		while (p->LTag == Link)
		{
			p = p->lchild;
		}
		visit(p->data);
		while (p->RTag == Thread && p->rchild != T)
		{
			p = p->rchild;
			visit (p->data);
		}
		p = p->rchild;
	}

}