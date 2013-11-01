#ifndef SSTABLE_H
#define SSTABLE_H

#include "SElemType.h"
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
#endif