#ifndef BBSTREE_H
#define BBSTREE_H
#include "Status.h"
#include "DElemType.h"
//ƽ��������Ĵ洢�ṹ
typedef struct BBSTNode
{
	DElemType data;//����Ԫ�����͵Ľ��ֵ
	int BF;//����ƽ�����ӣ��ȶ������ṹ�����
	BBSTNode *lchild,*rchild;//���Һ���ָ��
}BBSTNode, *BBSTree;
//����������������
void R_Rotate(BBSTree &p);

void L_Rotate(BBSTree &p);

void LR_Rotate(BBSTree &p);

void RL_Rotate(BBSTree &p);

void LeftBalance(BBSTree &T);

void RightBalance(BBSTree &T);

Status InsertAVL(BBSTree &T,DElemType e,Boolean &taller);
#endif