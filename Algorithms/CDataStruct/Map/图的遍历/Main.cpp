#include "MTraverse.h"
int main(void)
{
	Graph g;
	char filename[13];
	printf("�����������ļ�����");
	scanf("%s", filename);
#ifdef MG
	CreateFromFile(g,filename,0);
	Display(g);
#else
	CreateFromFile(g,filename);
	Display(g);
#endif
	printf("������������Ľ����\n");
	DFSTraverse(g,Visit);
	printf("������������Ľ����\n");
	BFSTraverse(g,Visit);
	return 0;
}