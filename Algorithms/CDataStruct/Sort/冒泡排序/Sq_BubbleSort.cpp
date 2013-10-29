#include "Sq_BubbleSort.h"
#include <stdio.h>

typedef int Status;//״̬����
#define TRUE 1
#define FALSE 0

void PrintL(SqList &L)
{//���˳���L
	int i;
	for (i = 1; i <= L.length; ++i)
	{
		printf("(%d,%d) ",L.r[i].key,L.r[i].otherinfo);
	}
	printf("\n");
}

void BubbleSort(SqList &L)
{//��˳��L����ð������
	int i,j;
	Status change = TRUE;//�����ı�־,��ֵΪTRUE
	for (i = L.length - 1; i >= 1 && change; --i)
	{
		change = FALSE;//����ѭ��δ�����ı�־
		for (j = 1; j <= L.length - 1; ++j)
		{
			if (LT(L.r[j + 1].key,L.r[j].key))//ǰ���¼�Ĺؼ��ִ��ں����¼�Ĺؼ���
			{//����¼����
				L.r[0] = L.r[j];
				L.r[j] = L.r[j + 1];
				L.r[j + 1] = L.r[0];
				change = TRUE;//�ѵ����ı�־
			}
		}
	}
	
}