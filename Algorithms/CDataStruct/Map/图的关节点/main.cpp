#include "FindArticul.h"

int main(void)
{
	int i;
	ALGraph g;
	char filename[13];
	printf("�������ļ���:");
	scanf("%s",&filename);
	CreateFromFile(g,filename);
	Display(g);
	printf("����ؽڵ㣺\n");
	FindArticul(g);
	printf("i  G.vertices[i].data visited[i] low[i] lowOrder[i]\n");
	for (i = 0; i < g.vexnum; ++i)
	{
		printf("%2d %9s %14d %8d %8d\n",i,g.vertices[i].data.name,visited[i],low[i],lowOrder[i]);
	}
	return 0;
}