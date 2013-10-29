#ifndef DLTREE_H
#define DLTREE_H

#include "Status.h"
#include "Record.h"

enum NodeKind{LEAF,BRANCH};//������ࣺ{Ҷ�ӣ���֧}
#define Nil '&' //�������������Ϊ$
typedef struct DLTNode
{//˫������������͵Ĵ洢�ṹ
	char symbol;//�ؼ����ַ�
	NodeKind kind;//��������
	DLTNode *next;//ָ���ֵܽ���ָ��
	union
	{//����������
		DLTNode *first;//���ڷ�֧��㣬��ָ���䳤�ӵ�ָ��
		Record *infoptr;//����Ҷ�ӽ�㣬��ָ���¼��ָ��
	};
}DLTNode,*DLTree;//����˫������ͷָ��

void Visit(Record *r);

void InputKey(char *k);

void InitDSTable(DLTree &DT);

 void DestroyDSTable(DLTree &DT);

 Record* SearchDLTree(DLTree T,KeyType K);

 Status InsertDSTable(DLTree &DT,Record* r);

 void TraverseDSTable(DLTree p,void(*Visit)(Record*));

#endif