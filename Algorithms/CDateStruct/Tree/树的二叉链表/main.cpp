#define ET 1
#include "CSTree.h"

void visit(TElemType e)
{
	printf(form" ",e);
}

int main()
{ 
	int i;
	CSTree T,p,q;
	TElemType e,e1;
	InitTree(T);
	printf("������������շ�%d(1:�� 0:��)������Ϊ%c,�������Ϊ%d��\n",TreeEmpty(T),Root(T),TreeDepth(T));
	CreateTree(T);
	printf("������T�����շ�%d(1:�� 0:��)������Ϊ%c,�������Ϊ%d��\n",TreeEmpty(T),Root(T),TreeDepth(T));
	printf("���������T:\n");
	LevelOrderTraverse(T,visit);
	printf("��������޸ĵĽ���ֵ����ֵ��");
	scanf("%c%*c%c%*c",&e,&e1);
	Assign(T,e,e1);
	printf("��������޸ĺ������\n");
	LevelOrderTraverse(T,visit);
	printf("\n");	
	printf("%c��˫����%c,������%c����һ���ֵ���%c��\n",e1,Parent(T,e1),LeftChild(T,e1),RightSibling(T,e1));
	printf("������P��\n");
	CreateTree(p);
	printf("���������p:");
	LevelOrderTraverse(p,visit);
	printf("\n");
	printf("����p�嵽T�У�������T�е�˫�׵Ľ���������ţ�");
	scanf("%c%d%*c",&e,&i);
	q = Point(T,e);
	InsertChild(T,q,i,p);
	printf("��������޸ĺ����T:");
	LevelOrderTraverse(T,visit);
	printf("\n");
	printf("�ȸ�������T:");
	PreOrderTraverse(T,visit);
	printf("\n");
	printf("���������T:");
	PostOrderTraverse(T,visit);
	printf("\n");
	printf("ɾ����T�н��e�ĵ�i������������e i:");
	scanf("%c%d",&e,&i);
	q = Point(T,e);
	DeleteChild(T,q,i);
	printf("��������޸ĺ����T:\n");
	LevelOrderTraverse(T,visit);
	printf("\n");
	DestroyTree(T);
	return 0;
}