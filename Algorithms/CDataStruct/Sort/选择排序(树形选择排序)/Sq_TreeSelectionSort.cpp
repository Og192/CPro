#include "Sq_TreeSelectionSort.h"
#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>
void PrintL(SqList &L)
{//���˳���L
	int i;
	for (i = 1; i <= L.length; ++i)
	{
		printf("(%d,%d) ",L.r[i].key,L.r[i].otherinfo);
	}
	printf("\n");
}

void TreeSort(SqList &L)
{
	int i,j,n;
	RedType *t = (RedType *)malloc((2 * L.length - 1)*sizeof(RedType));//����������˳��洢�ṹ
	for (i = 1; i <= L.length; ++i)
	{//��L.r����Ҷ�ӽ�㣨���ϵ��£������ң�
		t[L.length - 2 + i] = L.r[i];
	}
	for ( i = L.length - 2; i >= 0; --i)
	{
		t[i] = t[2 * i + 1].key <= t[2 * i +2].key?t[2 * i + 1]:t[2 * i + 2];//��Ҷ�ӽ���ֵΪ�����Һ����йؼ���С��
	}
	for (i = 0; i < L.length; ++i)
	{
		L.r[i + 1] = t[0];//����ǰ��Сֵ����L.r[i]
		n = 0;//���������
		do
		{//���������������ҽ��t[0]��Ҷ���е����n
			n = t[2 * n + 1].key == t[n].key?2 *n + 1:2*n + 2;
		} while (n < L.length - 1);
		t[n].key = INT_MAX;//����Ҷ�ӽ��Ĺؼ��ָ������
		while (n)
		{
			n = (n + 1)/2 - 1;//���Ϊn�Ľ���˫�׽�����
			t[n] = t[2 * n + 1].key <= t[2 *n + 2].key?(t[2 * n + 1]):(t[2 * n + 2]);
			//��Ҷ�ӽ���ֵΪ�����Һ����йؼ���С��
		}
	}
	free(t);
}