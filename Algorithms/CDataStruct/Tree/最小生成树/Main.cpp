#include "MiniSpanTree_PRIM.h"
#include "MiniSpanTree_Kruskal.h"
int main(void)
{
	MGraph g;
	char filename[13];
	printf("�������ļ���:");
	scanf("%s",&filename);
	CreateFromFile(g,filename,0);
	Display(g);
	printf("������ķ�㷨��\n");
	MiniSpanTree_PRIM(g,g.vex[0]);
	printf("����³˹�����㷨��\n");
	MiniSpanTree_Kruskal(g);
	return 0;
}