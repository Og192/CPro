#ifndef SQ_MERGESORT_H
#define SQ_MERGESORT_H
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

void Merge(RedType SR[],RedType TR[],int i,int m,int n);

void MSort(RedType SR[],RedType TR1[],int s,int t);

void MergeSort(SqList &L);




#endif