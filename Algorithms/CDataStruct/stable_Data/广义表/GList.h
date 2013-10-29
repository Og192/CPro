#include <stdio.h>
#include "SString.h"
typedef char AtomType;
enum ElemTag{ATM,LIST};//ATOM == 0:ԭ�ӣ�LIST == 1���ӱ�
typedef struct GLNode
{
	ElemTag tag;//�������֣���������ԭ�ӽڵ�ͱ���
	union//����������
	{
		AtomType atom;//atom��ԭ�ӽ���ֵ��AtomType���û�����
		struct
		{
			GLNode *hp;
			GLNode *tp;
		}ptr;//ptr�Ǳ����ָ����prt.hp��prt.tp�ֱ�ָ���ͷ�ͱ�β��������б�ͷ֮�������Ԫ�أ�
	};
} *GList,GLNode;//���������

void Divide(SString str,SString hstr); 

void InitGList(GList &L);

void CreateGList(GList &L,SString S);

void DestroyGList(GList &L);

void CopyGList(GList &T,GList L);

int GListLength(GList L);
;
int GListDepth(GList L);

Status GListEmpty(GList L);

GList GetHead(GList L);

GList GetTail(GList L);

void InsertFirst_GL(GList &L,GList e);

void DeleteFirst_GL(GList &L,GList &e);

void Traverse_GL(GList L,void (*visit)(AtomType));
