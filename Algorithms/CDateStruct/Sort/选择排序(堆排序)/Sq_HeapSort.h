#ifndef SQ_HEAPSORT_H
#define SQ_HEAPSORT_H
#include "RedType.h"
#define MAX_SIZE 20 //һ������ʾ����С˳������󳤶�
typedef struct SqList
{//˳�������
	RedType r[MAX_SIZE];//r[0]���û������ڱ���Ԫ
	int length;//˳�����
}SqList;

typedef SqList HeapType;//�����Ϊ˳���洢�ṹ

//��������
void PrintL(SqList &L);
void HeapAdjust(HeapType &H,int s,int m);

void HeapSort(HeapType &H);

#endif