#include <stdio.h>
#include "Status.h"
#include "TElmeType.h"

enum PointerTag{Link, Thread};//PointerTagΪö�����ͣ�LinkΪ0,ThreadΪ1
typedef struct BiThrNode 
{
	TElemType data;//����ֵ
	BiThrNode *lchild, *rchild;//���Һ���ָ��
	PointerTag LTag:2;//���־��ռ2bit
	PointerTag RTag:2;//�ұ�־��ռ2bit 
} *BiThrTree;

void CreatBiThrTree (BiThrTree &T);//��������������T
void InThreading (BiThrTree p);//�������������
void InOrderThreading(BiThrTree &Thrt, BiThrTree T);//����������
void InOrderTraverse_Thr (BiThrTree T, void (*vist)(TElemType));//�����������������