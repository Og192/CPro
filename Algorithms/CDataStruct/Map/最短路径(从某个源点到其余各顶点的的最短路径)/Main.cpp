#include "ShortestPath_DIJ.h"
int main(void)
{
	int i,j,k;
	MGraph g;
	PathMatrix p;
	ShortestPathTable d;
	int order[MAX_VERTEX_NUM];//�������飬�����·���ϵĶ���������δ洢�������
	for (i = 0; i < MAX_VERTEX_NUM;++i)
	{//��ʼ���������Ϊ-1
		order[i] = -1;
	}
	CreateFromFile(g,"2.txt",0);
	Display(g);
	ShortestPath_DIJ(g,0,p,d);
	printf("���·������p[i][j]���£�\n");
	for (i = 0; i < g.vexnum; ++i)
	{
		for (j = 0; j < g.vexnum; ++j)
		{
			printf("%2d",p[i][j]);
		}
		printf("\n");
	}
	
	for (i = 1; i < g.vexnum; ++i)
	{
		printf("%s->%s�����·��Ϊ:  ",g.vex[0].name,g.vex[i].name);
		for (j = 0; j < g.vexnum; ++j)
		{
			if (p[i][j] > 0)
			{
				order[p[i][j]] = j;//��·���������δ洢�������
			}
		}
		for (k = 1;order[k] > -1;++k)
		{
			printf("%s->",g.vex[order[k]].name);//����������źõĶ������
			order[k] = -1;                      //�ָ�Ĭ��ֵ���Ա�洢��һ�����·���Ķ������
		}
		printf("\b\b  ����Ϊ��%d",d[i]);
		printf("\n");
	}
	return 0;
}

