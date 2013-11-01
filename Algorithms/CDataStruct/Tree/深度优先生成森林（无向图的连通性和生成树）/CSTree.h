#include <stdio.h>
#include "Status.h"
//#include "TElmeType.h"
#include "VertexType.h"
typedef VertexType TElemType;
typedef struct CSNode//���Ķ�������洢�ṹ
{
	TElemType data;//����ֵ
	CSNode *firstchild, *nextsibling;//���Ӻ��ֵ�
}CSNode, *CSTree;


void InitTree(CSTree &T);
void DestroyTree(CSTree &T);
void PostOrderTraverse(CSTree T, void(*visit)(TElemType));
void LevelOrderTraverse(CSTree T,void (*visit)(TElemType));
void PreOrderTraverse(CSTree T,void (*visit)(TElemType));
