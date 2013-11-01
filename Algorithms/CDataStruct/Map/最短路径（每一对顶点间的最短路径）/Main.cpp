#include "ShortestPath_FLOYD.h"
void RailwaySearch(MGraph g,PathMatrix p,DistancMatrix d);
int main(void)
{
	int i,j,k,n;
	MGraph g;
	PathMatrix p;
	DistancMatrix d;
	CreateFromFile(g,"map.txt",0);
	int order[MAX_VERTEX_NUM];//��·���Ͼ�������Ĵ���洢�������
	for (i = 0; i < MAX_VERTEX_NUM; ++i)
	{
		order[i] = -1;//��ʼ��Ϊ-1
	}
	for (i = 0; i < g.vexnum; ++i)
	{
		g.arcs[i][i].adj = 0;//�Խ�Ԫ��ֵΪ0,��Ϊ������ͬ�������Ϊ0
	}
	Display(g);//���������g
	ShortestPath_FLOYD(g,p,d);
	printf("d����\n");
	for (i = 0; i < g.vexnum; ++i)
	{
		for (j = 0; j < g.vexnum; ++j)
		{
			printf("%6d",d[i][j]);
		}
		printf("\n");
	}
	printf("p����\n");
	for (i = 0; i < g.vexnum; ++i)
	{
		for (j = 0; j < g.vexnum; ++j)
		{
			if (i != j)
			{
				printf("��%s��%s������",g.vex[i].name,g.vex[j].name);
				for (k = 0; k < g.vexnum; ++k)
				{
					if (p[i][j][k] > 0)
					{
						order[p[i][j][k]] = k;
					}
				}
				for (n = 1 ; n < g.vexnum; ++n)
				{
					if (order[n] > -1)
					{
						printf("%s->",g.vex[order[n]].name);
						order[n] = -1;//�ָ�Ĭ��ֵ
					}
				}
				printf("\b\b  ����Ϊ:%d\n",d[i][j]);
			}

			printf("\n");
		}
	}

	RailwaySearch(g,p,d);
	printf("\n");
	return 0;
}


/*
��A��B������ABDE
��A��C������AC
��A��D������AD
��A��E������ADE
��B��A������

��B��C������
��B��D������
��B��E������
��C��A������
��C��B������BC

��C��D������
��C��E������
��D��A������
��D��B������BDE
��D��C������

��D��E������DE
��E��A������
��E��B������BE
��E��C������
��E��D������
*/