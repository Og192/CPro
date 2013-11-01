#include "Sq_HeapSort.h"
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

void HeapAdjust(HeapType &H,int s,int m)
{//��֪H.[s..m]�м�¼�Ĺؼ��ֳ�H.r[s].key֮�������󶥶ѵĶ��壬
//����������H.r[s]�Ĺؼ��֣�ʹH.r[s..m]�м�¼�Ĺؼ��־�����󶥶ѵĶ���
	int j;
	H.r[0] = H.r[s];//���ÿ��н��洢�������ļ�¼
	for (j = 2 * s; j <= m; j *= 2)
	{//jָ��������ļ�¼[s]�����ӣ���key�ϴ�ĺ��ӽ������ɸѡ
		if (j < m && LT(H.r[j].key,H.r[j + 1].key))
		{//���ӵĹؼ��� < �Һ��ӵĹؼ���
			++j;//jָ��[s]���Һ���
		}
		if (!LT(H.r[0].key,H.r[j].key))
		{//[s]�ؼ��ֲ�С���亢�ӵĵĹؼ���
			break;//�����ٵ���������forѭ��
		}
		H.r[s] = H.r[j];//����[j]Ϊ�󶥣�����[s]
		s = j;//[s]��λ�������ƶ���[j]��ԭ����Һ��Ӵ���
	}
	H.r[s] = H.r[0];//���������ļ�¼����[s]
}

void HeapSort(HeapType &H)
{//��˳���H���ж�����
	int i;
	for (i = H.length/2;i > 0; --i)
	{//�����һ����Ҷ�ӽ�㵽��1�����
		HeapAdjust(H,i,H.length);//����H.r[i]��ʹH.r[i..H.length]��Ϊ�󶥶�
	}
	for (i = H.length; i > 1; --i)
	{
		H.r[0] = H.r[1];//���Ѷ���¼[1]��δ��ȫ�����H.r[1..i]�е����һ����¼����
		H.r[1] = H.r[i];
		H.r[i] = H.r[0];
		HeapAdjust(H,1,i - 1);//����H.r[1],ʹH.r[1..i-1]���³�Ϊ�󶥶�
	}
}