/*****************Sq_QuitSort.h*****************/
#ifndef SQ_QUITSORT_H
#define SQ_QUITSORT_H

#include "RedType.h"
#define MAX_SIZE 20 //һ������ʾ����С˳������󳤶�
typedef struct SqList
{//˳�������
	RedType r[MAX_SIZE];//r[0]���û������ڱ���Ԫ
	int length;//˳�����
}SqList;
//��������

void PrintL(SqList &L);

int Parition1(SqList &L,int low,int high);

int Parition2(SqList &L,int low,int high);

int Parition3(SqList &L,int low,int high);

int Parition4(SqList &L,int low,int high);

void Qsort(SqList &L,int low ,int high);

void QuikSort(SqList &L);

#endif 