#ifndef SQ_TREESLECTIONSORT_H
#define SQ_TREESLECTIONSORT_H

#include "RedType.h"
#define MAX_SIZE 20 //һ������ʾ����С˳������󳤶�
typedef struct SqList
{//˳�������
	RedType r[MAX_SIZE];//r[0]���û������ڱ���Ԫ
	int length;//˳�����
}SqList;
//��������
void PrintL(SqList &L);
void TreeSort(SqList &L);

#endif