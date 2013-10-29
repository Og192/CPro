#include "Sq_InsertSort.h"
#include <stdio.h>
#include <malloc.h>
void Print(SqList L)
{//���˳���L
	int i;
	for (i = 1; i <= L.length; ++i)
	{
		printf("(%d,%d)",L.r[i].key,L.r[i].otherinfo);
	}
	printf("\n");
}

void InsertSort(SqList &L)
{//��˳���L��ֱ�Ӳ�������
	int i,j;
	for (i = 2; i <= L.length; ++i)
	{//�ӵڶ�����¼�����Ӵ����¼
		if (LT(L.r[i].key,L.r[i - 1].key))
		{//��ǰ��¼<ǰһ����¼
			L.r[0] = L.r[i];//����ǰ��¼����Ϊ�ڱ�
			for (j = i - 1;LT(L.r[0].key,L.r[j].key); --j)
			{//�����ӱ�Ӻ�ǰ,���ڱ�С�ڼ�¼,���¼����һ����Ԫ
				L.r[j + 1] = L.r[j];//����һ����Ԫ
			}
			L.r[j + 1] = L.r[0];//���ڱ�����ǰ��¼�����뵽��ȷλ��
		}
	}
}

void BInsertSort(SqList &L)
{//�������L���۰��������
	int i,j,m,low,high;
	for (i = 2; i <= L.length; ++i)
	{//�ӵڶ�����¼�����Ӵ����¼
		if (LT(L.r[i].key,L.r[i - 1].key))
		{//��ǰ��¼<ǰһ����¼
			L.r[0] = L.r[i];//����ǰ��¼����Ϊ�ڱ�
			low = 1;//�Ͷ�Ϊ��һ����¼
			high = i - 1;//�߶˲�������ǰ��¼
			while (low <= high)
			{//��[low,high]�������۰������������λ��
				m = (low + high)/2;//�۰�
				if (LT(L.r[0].key,L.r[m].key))
				{//�ؼ���С���е�ؼ���
					high = m - 1;//������ڵͰ���
				}
				else//�ؼ��ִ��ڵ����е�ؼ���
				{
					low = m + 1;//������ڸ߰���
				}
			}
			for (j = i - 1; j >= high + 1; --j)
			{//�����ӱ�Ӻ�ǰ
				L.r[j + 1] = L.r[j];//��¼����
			}
			L.r[high + 1] = L.r[0]; //���뵽[high + 1]
		}
	}
}

void P2_InsertSort(SqList &L,int flag)
{//2-·��������flag = 0���͸Ľ���2-·��������flag = 1����L.r[1]�Ǵ�����ļ�¼�йؼ�����С�����ļ�¼ʱ��������Խ�ԣ�
	int i,j,first,final,mid=0;
	RedType *d;
	d=(RedType*)malloc(L.length*sizeof(RedType)); //����L.length����¼����ʱ�ռ�
	d[0]=L.r[1]; //��L�ĵ�1����¼Ϊd���ź���ļ�¼
	first=final=0; //first��final�ֱ�ָʾd���ź���ļ�¼�ĵ�1�������һ����¼��λ��
	for(i=2;i<=L.length;++i) //���ν�L�ĵ�2��~���1����¼����d��
	{ 
		if(flag) 
		{ 
			if(first>final)
			j=L.length; 
		else
			j=0;
	    mid=(first+final+j)/2%L.length; 
	}
	if(L.r[i].key<d[mid].key) 
	{ j=first; 
	first=(first-1+L.length)%L.length; 
	while(L.r[i].key>d[j].key) 
	{ d[(j-1+L.length)%L.length]=d[j]; 
	j=(j+1)%L.length; 
	}
	d[(j-1+L.length)%L.length]=L.r[i]; 
	}
	else 
	{ j=final++; 
	while(L.r[i].key<d[j].key) 
	{ d[(j+1)%L.length]=d[j]; 
	j=(j-1+L.length)%L.length; 
	}
	d[(j+1)%L.length]=L.r[i];

	}
	}
	for(i=1;i<=L.length;i++) 
		L.r[i]=d[(first+i-1)%L.length]; 
	free(d); 
}


















