#ifndef TRIETREE_H
#define TRIETREE_H

#include "Record.h"
#define LENGTH 27//�������ȣ�0+��дӢ����ĸ��
#define Nil 0 //���崮������Ϊ0
enum NodeKind{BRANCH,LEAF};
typedef struct TrieNode
{//Trie���Ĵ洢�ṹ
	NodeKind kind;
	union 
	{//����������
		
		struct 
		{
			KeyType k;//�ؼ���
			Record *infoptr;//��¼ָ��
		}lf;//Ҷ�ӽڵ�
		struct 
		{
			TrieNode *ptr[LENGTH];//ָ��Tire����һ����ָ��
			int  num; //��֧���ĺ��Ӹ���
		}bh;//��֧���
	};
}TrieNode,*TrieTree;//����ָ��Trie������ָ��TrieTree

//������������
void Visit(Record *r);
void InputKey(char *k);
int ord(char c);
void InitDSTable(TrieTree &T);
void DestroyDSTable(TrieTree &T);
Record *SearchTrie(TrieTree T,KeyType k);
void InsertTrie(TrieTree &T,Record* r);
void TraverseDSTable(TrieTree T,void(*Visit)(Record*));

#endif