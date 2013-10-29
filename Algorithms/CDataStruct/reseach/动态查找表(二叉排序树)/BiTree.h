#ifndef BITREE_H
#define BITREE_H

#include "Status.h"
#include "DElemType.h"
#include "TElmeType.h" 
//�����������Ľڵ�
typedef struct BiTNode
{
	TElemType date;//������
	BiTNode *lchild, *rchild;//ָ���򣬷ֱ�ָ����������������
} *BiTree;//����ָ��ڵ��ͷָ��

//����������һ�������

void InitBiTree(BiTree &T);

void DestroyBiTree(BiTree &T);

void PreOrderTraverse(BiTree T, void (*visit)(TElemType));

void InOrderTraverse(BiTree T, void (*visit)(TElemType));

void PostOrderTraverse(BiTree T, void (*visit)(TElemType));

Status BiTreeEmpty(BiTree &T);

int BiTreeDepth(BiTree &T);

TElemType Root(BiTree &T);

TElemType value(BiTree p);

void Assign(BiTree p, TElemType value);

Status DeleteChild(BiTree p, int LR);

void LevelOrderTraverse(BiTree T, void(*visit)(TElemType));

Status InsertChild(BiTree p, int LR, BiTree c);

void InOrderTraverse1(BiTree T, void(*visit)(TElemType));
#endif