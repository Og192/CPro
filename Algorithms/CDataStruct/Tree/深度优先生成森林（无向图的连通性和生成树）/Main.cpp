#include "DFSForest.h"

int main(void)
{
	Graph g;
	CSTree t;
	printf("��ѡ������ͼ");
	CreateGraph(g);
	Display(g);
	DFSForest(g,t);
	printf("�����������ɭ�֣�");
	PreOrderTraverse(t,Visit);
	printf("\n");
	return 0;
}