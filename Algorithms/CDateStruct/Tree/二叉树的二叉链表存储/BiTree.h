#ifndef BITREE_H
#define BITREE_H

#include "Status.h"
#include "TElmeType.h" 
//�����������Ľڵ�
typedef struct BiTNode
{
	TElemType date;//������
	BiTNode *lchild, *rchild;//ָ���򣬷ֱ�ָ����������������
} *BiTree;//����ָ��ڵ��ͷָ��

//����������һ�������
void InitBiTree(BiTree &);
void DestroyBiTree(BiTree &);
void PreOrderTraverse(BiTree , void (*visit)(TElemType));
void InOrderTraverse(BiTree , void (*visit)(TElemType));
void PostOrderTraverse(BiTree , void (*visit)(TElemType));
Status BiTreeEmpty(BiTree &);
int BiTreeDepth(BiTree &);
TElemType Root(BiTree &);
TElemType value(BiTree );
void Assign(BiTree , TElemType );
BiTree Point(BiTree , TElemType );
TElemType LeftChild(BiTree , TElemType );
TElemType RightChild(BiTree , TElemType );
Status DeleteChild(BiTree , int );
void CreatBiTree(BiTree &);
TElemType Parent(BiTree , TElemType );
void LevelOrderTraverse(BiTree , void (*visit)(TElemType));
TElemType LeftSibling(BiTree , TElemType );
TElemType RightSibling(BiTree , TElemType );
Status InsertChild(BiTree , int , BiTree );
void InOrderTraverse1(BiTree , void(*visit)(TElemType));
#endif