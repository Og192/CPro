#ifndef SL_INSERTSORT_H
#define SL_INSERTSORT_H
#include "RedType.h"

#define SIZE 100
typedef struct SLNode
{//��������
	RedType rc;//��¼��
	int next;//ָ����
}SLNode;

typedef struct SLinkListType
{//��̬��������
	SLNode r[SIZE];//0�ŵ�ԪΪ��ͷ���
	int length;//����ǰ����
}SLinkListType;

//����������������

void PrintL(SLinkListType L);

void CreatTableFromFile(SLinkListType &SL,FILE*f);

void MakeTableSorted(SLinkListType &SL);

void Arrange(SLinkListType &SL);

typedef SLinkListType SqList;

void Sort(SqList L,int adr[]);

void Rearrange(SqList &L,int adr[]);

#endif