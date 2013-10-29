/***************************main.cpp***************************/
#include <stdio.h>
#include "HashTable.h"

#define N 15//��������ɵļ�¼����
int main(void)
{
	ElemType r[N];//��¼����
	HashTable h;
	int i,n = 0,p = 0;
	Status s;
	KeyType k;
	FILE *f;//�ļ�ָ������
	f = fopen("Records.txt","r");//�򿪼�¼�ļ�Record.txt
	do
	{
		i = fscanf(f,"%d%d",&r[p].key,&r[p].order);//�Ƚ���¼�ݴ����¼����r[p]
		if (i != -1)
		{//�������ݳɹ�
			p++;
		}
	} while (!feof(f) && p < N);//δ���������ļ���β�Ҽ�¼����δ��
	fclose(f);//�ر������ļ�
	InitHashTable(h);
	for (i = 0; i < p - 1; ++i)
	{//��h�в���ǰp-1����¼(���һ����¼������,�������һ����¼���ؽ���ϣ��)
		s = InsertHash(h,r[i]);
		if (DUPLICATE == s)
		{
			printf("�������йؼ���Ϊ%d�ļ�¼���޷��ٲ����¼��%d,%d��\n",r[i].key,r[i].key,r[i].order);
		}
	}
	printf("����ϣ��ַ��˳�������ϣ��:\n");
	TraverseHash(h,Visit);
	printf("����������Ҽ�¼�Ĺؼ��֣�");
	scanf("%d",&k);
	s = SearchHash(h,k,p,n);
	if (SUCCESS == s)
	{//���ҳɹ�
		Visit(p,h.elem[p]);//����ü�¼
	}
	else
	{//����ʧ��
		printf("δ�ҵ�\n");
	}
	s = InsertHash(h,r[i]);//�������һ����¼�����ؽ���ϣ��
	if (UNSUCCESS == s)
	{//���벻�ɹ�
		s = InsertHash(h,r[i]);//�ؽ���ϣ������²���
	}
	printf("����ϣ���ַ��˳������ؽ���Ĺ�ϣ��:\n");
	TraverseHash(h,Visit);

	printf("����������Ҽ�¼�Ĺؼ��֣�");
	scanf("%d",&k);
	s = SearchHash(h,k,p,n);
	if (SUCCESS == s)
	{//���ҳɹ�
		Visit(p,h.elem[p]);//����ü�¼
	}
	else
	{//����ʧ��
		printf("δ�ҵ�\n");
	}
	DestroyHashTable(h);
	return 0;
}


/*******************************���н��*******************************/
/*

�������йؼ���Ϊ60�ļ�¼���޷��ٲ����¼��60,9��
����ϣ��ַ��˳�������ϣ��:
��ϣ��ַ 0 ~ 10
address = 1(1,5)
address = 2(2,6)
address = 3(3,7)
address = 4(4,8)
address = 5(60,2)
address = 6(17,1)
address = 7(29,3)
address = 8(38,4)
����������Ҽ�¼�Ĺؼ��֣�13
δ�ҵ�
����ϣ���ַ��˳������ؽ���Ĺ�ϣ��:
��ϣ��ַ 0 ~ 18
address = 0(38,4)
address = 1(1,5)
address = 2(2,6)
address = 3(3,7)
address = 4(4,8)
address = 5(60,2)
address = 10(29,3)
address = 13(13,10)
address = 17(17,1)
����������Ҽ�¼�Ĺؼ��֣�13
address = 13(13,10)
�밴���������. . .

*/

