#ifndef SQ_INSERTSORT_H
#define SQ_INSERTSORT_H
#include "RedType.h"
#define MAX_SIZE 20 //һ������ʾ����С˳������󳤶�
typedef struct SqList
{//˳�������
	RedType r[MAX_SIZE];//r[0]���û������ڱ���Ԫ
	int length;//˳�����
}SqList;
void Print(SqList L);

void InsertSort(SqList &L);

void BInsertSort(SqList &L);

void P2_InsertSort(SqList &L,int flag);

#endif