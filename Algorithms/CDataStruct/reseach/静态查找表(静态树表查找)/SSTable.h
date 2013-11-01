#ifndef SSTABLE_H
#define SSTABLE_H

#include "SElemType.h"
#include "BiTree.h"
struct SSTable//��̬���ұ�����
{
	SElemType *elem;//����Ԫ�أ���¼���洢�ռ��ַ,����ʱ��ʵ�ʼ�¼�����䣬0�ŵ�Ԫ���գ��������ڱ���
	int length;//����
};

//��������

void Creat_SeqFromFile(SSTable &ST,char *filename);

void Ascend(SSTable &ST);

void Creat_OrderFromFile(SSTable & ST,char *filename);

Status Destroy(SSTable &ST);

int Search_Seq(SSTable ST,KeyType key);

int Search_Bin(SSTable ST,KeyType key);

void Traverse(SSTable ST);

//��̬�������Ĳ���
void FindSW(double sw[],SSTable ST);

Status SecondOptimal(BiTree &T,SElemType R[],double sw[],int low,int high);

typedef BiTree SOSTree;//���Ų��������ö�������Ĵ洢�ṹ
#define N 100 //��̬���ұ������

void CreateSOSTree(SOSTree &T,SSTable ST);

Status Search_SOSTree(SOSTree &T,KeyType key);



#endif