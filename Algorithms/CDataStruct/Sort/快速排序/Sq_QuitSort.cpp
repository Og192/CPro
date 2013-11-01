/*****************Sq_QuitSort.cpp*****************/
#include "Sq_QuitSort.h"
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

int Parition1(SqList &L,int low,int high)
{//����˳���L���ӱ�L.r[low...high]�ļ�¼��ʹ�����¼��λ
//�������ؽ����������λ�ã���ǰ�ļ�¼С������ؼ��֣���������
	KeyType pivotkey;//����ؼ���
	pivotkey = L.r[low].key;//���ӱ�ĵ�һ���ؼ���������Ĺؼ���
	while (low < high)
	{//�ӱ�����˽�������м�ɨ��
		while (low < high && L.r[high].key >= pivotkey)
		{//�߶˹ؼ��ִ��ڵ�������ؼ���
			--high;//�߶�����ƣ������Ƚ�
		}
		L.r[0]	= L.r[low];//��������С�Ĺؼ��ʼ�¼�������Ͷˣ����ᵽ�߶�
		L.r[low] = L.r[high];
		L.r[high] = L.r[0];
		while (low < high && L.r[low].key <= pivotkey)
		{//�Ͷ˹ؼ���С�ڵ�������ؼ���
			++low;//�Ͷ�����ƣ������Ƚ�
		}
		L.r[0]	= L.r[low];//���������Ĺؼ��ʼ�¼�������߶ˣ����ᵽ�Ͷ�
		L.r[low] = L.r[high];
		L.r[high] = L.r[0];
	}
	return low;//��������λ��
}

int Parition2(SqList &L,int low,int high)
{//���Ľ��㷨1������˳���L���ӱ�L.r[low...high]�ļ�¼��ʹ�����¼��λ
//�������ؽ����������λ�ã���ǰ�ļ�¼С������ؼ��֣���������
	KeyType pivotkey;//����ؼ���
	pivotkey = L.r[low].key;//���ӱ�ĵ�һ���ؼ���������Ĺؼ���
	L.r[0] = L.r[low];//�������¼���浽[0]���Ľ���
	while (low < high)
	{//�ӱ�����˽�������м�ɨ��
		while (low < high && L.r[high].key >= pivotkey)
		{//�߶˹ؼ��ִ��ڵ�������ؼ���
			--high;//�߶�����ƣ������Ƚ�
		}
		L.r[low] = L.r[high];//��������ؼ���С�ļ�¼�ƶ����Ͷˣ�������[0]���������Ľ���
		while (low < high && L.r[low].key <= pivotkey)
		{//�Ͷ˹ؼ���С�ڵ�������ؼ���
			++low;//�Ͷ�����ƣ������Ƚ�
		}
		L.r[high] = L.r[low];//��������ؼ��ִ�ļ�¼�ƶ����߶ˣ�������[0]���������Ľ���
	}
	L.r[low] = L.r[0];//�������¼�ƶ���λ���Ľ���
	return low;//��������λ��
}

void SwapMid(SqList &L,int low,int high)
{//��˳���L�м�¼L.r[low],L.r[(low + high)/2],L.r[high]�Ĺؼ���Ϊ��ֵ�ļ�¼�͵�һ����¼L.r[low]����
	int i,j,mid,m = (low + high)/2;
	SqList t;//�洢����������¼����ʱ˳���������������¼�����Ա��ҳ���ֵ
	t.length = 3;
	t.r[1] = L.r[low];
	t.r[2] = L.r[m];
	t.r[3] = L.r[high];
	Status change = TRUE;//�����ı�־,��ֵΪTRUE
	for (i = t.length - 1; i >= 1 && change; --i)
	{
		change = FALSE;//����ѭ��δ�����ı�־
		for (j = 1; j <= t.length - 1; ++j)
		{
			if (LT(t.r[j + 1].key,t.r[j].key))//ǰ���¼�Ĺؼ��ִ��ں����¼�Ĺؼ���
			{//����¼����
				t.r[0] = t.r[j];
				t.r[j] = t.r[j + 1];
				t.r[j + 1] = t.r[0];
				change = TRUE;//�ѵ����ı�־
			}
		}
	}

	if (EQ(t.r[2].key,L.r[high].key))
	{//��ֵΪL.r[high].key
		mid = high;
	}
	else if (EQ(t.r[2].key,L.r[m].key))
	{//��ֵΪL.r[m].key
		mid = m;
	}
	else
	{//��ֵΪL.r[low].key
		mid = low;
	}
	if (mid != low)
	{//��ֵ��¼�͵�һ����¼����
		L.r[0] = L.r[mid];
		L.r[mid] = L.r[low];
		L.r[low] = L.r[0];
	}
}
int Parition3(SqList &L,int low,int high)
{//���Ľ��㷨2������˳���L���ӱ�L.r[low...high]�ļ�¼��ʹ�����¼��λ
//�������ؽ����������λ�ã���ǰ�ļ�¼С������ؼ��֣���������
	KeyType pivotkey;//����ؼ���
	SwapMid(L,low,high);//��¼L.r[low],L.r[(low + high)/2],L.r[high]�Ĺؼ���Ϊ��ֵ�ļ�¼��L.r[low]����,�Ľ���
	pivotkey = L.r[low].key;//���ӱ�ĵ�һ���ؼ���������Ĺؼ���
	L.r[0] = L.r[low];//�������¼���浽[0]
	while (low < high)
	{//�ӱ�����˽�������м�ɨ��
		while (low < high && L.r[high].key >= pivotkey)
		{//�߶˹ؼ��ִ��ڵ�������ؼ���
			--high;//�߶�����ƣ������Ƚ�
		}
		L.r[low] = L.r[high];//��������ؼ���С�ļ�¼�ƶ����Ͷˣ�������[0]������
		while (low < high && L.r[low].key <= pivotkey)
		{//�Ͷ˹ؼ���С�ڵ�������ؼ���
			++low;//�Ͷ�����ƣ������Ƚ�
		}
		L.r[high] = L.r[low];//��������ؼ��ִ�ļ�¼�ƶ����߶ˣ�������[0]������
	}
	L.r[low] = L.r[0];//�������¼�ƶ���λ
	return low;//��������λ��
}
int Parition4(SqList &L,int low,int high)
{//���Ľ��㷨2������˳���L���ӱ�L.r[low...high]�ļ�¼��ʹ�����¼��λ
//�������ؽ����������λ�ã���ǰ�ļ�¼С������ؼ��֣���������
	KeyType pivotkey;//����ؼ���
	RedType t;
	SwapMid(L,low,high);//��¼L.r[low],L.r[(low + high)/2],L.r[high]�Ĺؼ���Ϊ��ֵ�ļ�¼��L.r[low]����
	pivotkey = L.r[low].key;//���ӱ�ĵ�һ���ؼ���������Ĺؼ���
	L.r[0] = L.r[low];//�������¼���浽[0]
	while (low < high)
	{//�ӱ�����˽�������м�ɨ��
		while (low < high && L.r[high].key >= pivotkey)
		{//�߶˹ؼ��ִ��ڵ�������ؼ���
			if (LT(L.r[high].key,L.r[high - 1].key))
			{//����������¼���ڡ�����ʱ�����л������Ľ���
				t = L.r[high];
				L.r[high] = L.r[high - 1];
				L.r[high - 1] = t;
			}
			--high;
		}
		L.r[low] = L.r[high];//��������ؼ���С�ļ�¼�ƶ����Ͷˣ�������[0]������
		while (low < high && L.r[low].key <= pivotkey)
		{//�Ͷ˹ؼ���С�ڵ�������ؼ���
			if (LT(L.r[low + 1].key,L.r[low].key))
			{//����������¼���ڡ�����ʱ�����л������Ľ���
				t = L.r[low];
				L.r[low] = L.r[low + 1];
				L.r[low + 1] = t;
			}
			++low;//�Ͷ�����ƣ������Ƚ�
		}
		L.r[high] = L.r[low];//��������ؼ��ִ�ļ�¼�ƶ����߶ˣ�������[0]������
	}
	L.r[low] = L.r[0];//�������¼�ƶ���λ
	return low;//��������λ��
}

void Qsort(SqList &L,int low ,int high)
{//��˳���L�е�������L.r[low..high]����������
	static int c = 1;//ͳ������
	int pivotloc;//����λ��
	if (low < high)
	{//�����г��ȴ���1
		pivotloc = Parition4(L,low,high);//��L.r[low..high]���ؼ���һ��Ϊ����pivotlc������λ��
		printf("��%d������� ˳���L:\n",c++);
		PrintL(L);
		Qsort(L,low,pivotloc - 1);//�Թؼ���С������ؼ��ֵĵ��ӱ�ݹ��������
		Qsort(L,pivotloc + 1,high);//�Թؼ��ִ�������ؼ��ֵĸ��ӱ�ݹ��������
	}
}

void QuikSort(SqList &L)
{//������˳���L����������
	Qsort(L,1,L.length);
}
//


