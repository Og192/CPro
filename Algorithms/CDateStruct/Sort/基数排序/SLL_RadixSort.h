#ifndef SLL_RADIXSORT_H
#define SLL_RADIXSORT_H
#include <stdio.h>
#define MAX_NUM_OF_KEY 8//�ؼ������������ֵ
#define RADIX 10//�ؼ��ֻ��������ֵ,��ʱ��ʮ�������Ļ���
#define MAX_SPACE 100//����¼��
typedef char KeysType;//����ؼ�������Ϊ�ַ�������
typedef int infoType;//��������������Ϊ����

typedef struct SLCell
{//��̬����Ľ������
	KeysType keys[MAX_NUM_OF_KEY];//�ؼ���
	infoType otheritems;//����������
	int next;//��һ����¼�����
}SLCell;

typedef struct SLList
{//��̬��������
	SLCell r[MAX_SPACE];//��̬����Ŀ����ÿռ䣬r[0]Ϊͷ���
	int keynum;//��¼�ĵ�ǰ�ؼ��ָ���
	int recnum;//��̬����ĵ�ǰ���ȣ����ڼ�¼��������
}SLList;

typedef int ArrType[RADIX];//ָ���������ͣ���������
typedef SLList SqList;//����SLList����ΪSqList���ͣ��Ա�����Sort()��Rearrange()
#define length recnum//����length����Ϊrenum���ͣ��Ա�����Sort()��Rearrange()

//��������
void Print2(SLList L);

void PrintLL(SLList L);

void Sort(SqList L,int adr[]);

void Rearrange(SqList &L,int adr[]);

void MadeListFromFile(SqList &L,FILE *f);

int ord(char c);

void Distribute(SLCell r[],int i,ArrType f,ArrType e);

int succ(int i);

void Collect(SLCell r[],ArrType f,ArrType e);

void RadixSort(SLList &L);

#endif