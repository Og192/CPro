#include "SL_InsertSort.h"

#include <stdio.h>
#include <stdlib.h>
void PrintL(SLinkListType L)
{//��˳��ṹ�����̬����
	int i;
	for (i = 1;i <= L.length; ++i)
	{
		printf("i = %d key = %d ord = %d next = %d\n",i,L.r[i].rc.key,
			    L.r[i].rc.otherinfo,L.r[i].next);
	}
}

void CreatTableFromFile(SLinkListType &SL,FILE*f)
{//�������ļ�f����Ϊ�����˳���SL(next��������)
	int i;
	fscanf(f,"%d",&SL.length);//���ļ������
	for (i = 1; i <= SL.length; ++i)
	{
		InputFromFile(f,SL.r[i].rc);//�������ļ������¼��SL.r[i].rc
	}
}

void MakeTableSorted(SLinkListType &SL)
{//ʹ�����˳���SL��Ϊ����ľ�̬ѭ������
	int i,p,q;
	SL.r[0].rc.key = INT_MAX;//��ͷ����¼�Ĺؼ���ȡ����������ǽ���ѭ������ı�β��
	SL.r[0].next = 0;//next��Ϊ0�γɿ�ѭ��������ʼ��
	for (i = 1; i <= SL.length; ++i)
	{
		q = 0;//qָ��̬����ı�ͷԪ��
		p = SL.r[0].next;//pָ��̬����ĵ�1��Ԫ��
		while (SL.r[p].rc.key <= SL.r[i].rc.key)
		{//p��ָ��¼�Ĺؼ��ֲ����ڴ������¼�Ĺؼ��֣����еġ�=��ʹ���򷽷����ȶ��ģ�
			q = p;//qָ����ָԪ��
			p = SL.r[p].next;//pָ����һ��Ԫ��
		}
		SL.r[q].next = i;//����ǰ��¼�嵽��̬�����У�qǰp��
		SL.r[i].next = p;//��ǰ��¼����һ����¼���
	}
}

void Arrange(SLinkListType &SL)
{//���ݾ�̬����SL�и�����ָ��ֵ������¼λ�ã�ʹ��SL��Ϊ�ǵݼ������˳���
	int i,p,q;
	SLNode t;
	p = SL.r[0].next;//pָʾ��һ����¼�ĵ�ǰλ��
	for (i = 1; i < SL.length; ++i)
	{//SL.r[1..i-1]�м�¼�鰸�ؼ����������У���i����¼��SL�еĵ�ǰλ��Ӧ��С��i
		while (p<i)//p��ָ�ļ�¼���ź�
		{
			p = SL.r[p].next;//��������ң�����������õĲ���
		}
		q = SL.r[p].next;//qָʾ��δ�����ı�β����
		if (p != i)//��i����¼����p��ָ��λ�ã����ƶ�
		{
			t = SL.r[p];
			SL.r[p] = SL.r[i];
			SL.r[i] = t;
			SL.r[i].next = p;//ָ�����ߵļ�¼��[i]���ź���ʹ���Ժ����whileѭ���һ�p��ָ��¼
		}
		p = q;//ָʾ��δ�����ı�β���֣�Ϊ�ҵ�i+1����¼��׼��
	}
}

void Sort(SqList L,int adr[])
{//���adr[1..L.length],adr[i]Ϊ��̬����L�ĵ�i����С��¼�����
	int i = 1, p = L.r[0].next;//pָ���һ����¼
	while (p)
	{//δ����β
		adr[i++] = p;//��p��ֵ��adr[i],i+1
		p = L.r[p].next;//pָ����һ����¼
	}
}

void Rearrange(SqList &L,int adr[])
{//adr����������̬����L��������򣬼�L.r[adr[i]]�ǵ�iС��¼
	int i,j,k;
	for (i = 1; i <= L.length; ++i)
	{
		if (adr[i] != i)
		{
			j = i;
			L.r[0] = L.r[i];//�ݴ��¼[i]��[0](�ճ�[i]��[j]��)
			while (adr[j]!=i)//��¼������ȷ��λ��
			{//����L.r[adr[j]]�ļ�¼��λ��֪��adr[j] = iΪֹ;
				k = adr[j];
				L.r[j] = L.r[k];//��[j]��Ӧ�ŵļ�¼��������[j]�գ�
				adr[j] = j;//��¼������ȷλ�õı�־
				j = k;//�¿ճ���λ�ø�ֵ��j���Ա����ѭ��ʹ��
			}
			L.r[j] = L.r[0];//ѭ��������ϣ����ݴ���[0]�еļ�¼��ֵ��L.r[j]
			adr[j] = j;
		}
	}
}