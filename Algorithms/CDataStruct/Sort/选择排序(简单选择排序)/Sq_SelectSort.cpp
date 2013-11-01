#include "Sq_SelectSort.h"
#include <stdio.h>

void PrintL(SqList &L)
{//���˳���L
	int i;
	for (i = 1; i <= L.length; ++i)
	{
		printf("(%d,%d) ",L.r[i].key,L.r[i].otherinfo);
	}
	printf("\n");
}

int SelectMinKey(SqList L,int i)
{//������L.r[i..L.length]��key��С�ļ�¼�����
	int j,k = i;//��ʩ��[i]�Ĺؼ���Ϊ��С����i��k
	for (j = i + 1; j <= L.length; ++j)
	{
		if (LT(L.r[j].key,L.r[k].key))
		{
			k = j;//����kΪ��С�ؼ������j
		}
	}
	return k;
}

void SelectSort(SqList &L)
{//��˳���L����ѡ������
	int i,k;
	for (i = 1; i < L.length; ++i)
	{
		k = SelectMinKey(L,i);
		if (k != i)
		{
			L.r[0] = L.r[k];
			L.r[k] = L.r[i];
			L.r[i] = L.r[0];
		}
	}
}