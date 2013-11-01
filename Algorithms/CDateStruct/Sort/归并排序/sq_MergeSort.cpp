#include "sq_MergeSort.h"
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

void Merge(RedType SR[],RedType TR[],int i,int m,int n)
{//�������SR[i..m]��SR[m + 1..n]�鲢Ϊ�����TR[i..n]
	int j,k,p;
	for (j = m + 1, k = i; i <= m && j <= n; ++k)
	{//��SR��������������С����鲢��TR��
		if LQ(SR[i].key,SR[j].key)
		{
			TR[k] = SR[i++];
		}
		else
		{
			TR[k] = SR[j++];
		}
	}
	if (i <= m)
	{
		for (p = 0; p <= m - i; ++p)
		{
			TR[k + p] = SR[i + p]; //��ʣ���SR[i..m]���Ƶ�TR
		}
	}
	if (j <= n)
	{
		for (p = 0; p <= n - j; ++p)
		{
			TR[k + p] = SR[j + p]; //��ʣ���SR[j..n]���Ƶ�TR
		}
	}
}

void MSort(RedType SR[],RedType TR1[],int s,int t)
{//��SR[s..t]�鲢����ΪTR1[s..t]
	int m;
	RedType TR2[MAX_SIZE + 1];
	if (s == t)
	{//ֻ��һ��Ԫ�ش��鲢
		TR1[s] = SR[s];//ֱ�Ӹ�ֵ
	}
	else
	{//�жԸ�Ԫ�ش��鲢
		m = (s + t)/2;//��SR[s..t]ƽ��ΪSR[s..m]��SR[m+1..t]
		MSort(SR,TR2,s,m);//�ݹ�Ľ�SR[s..m]�鲢Ϊ�����TR2[s..m]
		MSort(SR,TR2,m + 1,t);//�ݹ�Ľ�SR[m+1..t]�鲢Ϊ�����TR2[m+1..t]
		Merge(TR2,TR1,s,m,t);//��TR2[s..m]��TR2[m+1..t]�鲢��TR1[s..t]
	}
}

void MergeSort(SqList &L)
{//��˳���L���鲢����
	MSort(L.r,L.r,1,L.length);
	//��˳���L[1..L.length]�鲢����Ϊ�����˳���L.r[1..L.length]
}