#ifndef BTREE_H
#define BTREE_H

#include "Status.h"
#define m 3//��B_���Ľ�Ϊ3
const int s = (m + 1)/2;//sΪ���ѽ�����ֵ
#include "Record.h"
typedef struct BTNode
{//B_���������
	int keynum;//����еĹؼ�����
	BTNode *parent;//ָ��˫�׽��
	KeyType key[m + 1];//�ؼ���������0�ŵ�Ԫδ��
	Record *recptr[m + 1];//��¼ָ��������0�ŵ�Ԫδ��
	BTNode *ptr[m + 1];//����ָ������,0�õ�Ԫָ���key[1]С�Ĺؼ������ڽ��
}BTNode,*BTree;//B_��������ͺ�B_��������

typedef struct Result
{//���ҽ������
	BTree pt;//ָ��ؼ������ڽ��
	int i;//�ؼ����������
	int tag;//����ֵ 1�����ҳɹ� 0������ʧ��
}Result;

void Visit(BTNode c,int i);

void InputKey(KeyType &k);

void InitDSTable(BTree &DT);

void DestroyDSTable(BTree &DT);

void TraverseDSTable(BTree &DT,void (*Visit)(BTNode,int));

int Search(BTNode *p,KeyType k);

Result SearchBTree(BTree T,KeyType k);

void Split(BTree q,BTree &ap);

void Insert(BTree q,int i,Record *r, BTree ap);

void NewRoot(BTree &T,Record *r,BTree ap);

void InsertBTree(BTree &T,Record *r,BTree q, int i);

#endif