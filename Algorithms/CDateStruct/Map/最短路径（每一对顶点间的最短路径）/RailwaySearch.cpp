#include "ShortestPath_FLOYD.h"

void RailwaySearch(MGraph g,PathMatrix p,DistancMatrix d)
{
	int i,j,k,n,q = 1;
	int order[MAX_VERTEX_NUM];//��·���Ͼ�������Ĵ���洢�������
	for (i = 0; i < MAX_VERTEX_NUM; ++i)
	{
		order[i] = -1;//��ʼ��Ϊ-1
	}
	while (q)
	{
		printf("��ѡ��1 ��ѯ  0 ����\n");
		scanf("%d",&q);
		if (q)
		{
			printf("���д��룺\n");
			for (i = 0; i < g.vexnum; i++)
			{
				printf("%2d.%-8s",i+1,g.vex[i].name);
				if (i%7 == 6)
				{
					printf("\n");
				}
			}
			printf("\n������Ҫ��ѯ�������д��� �յ���д��룺");
			scanf("%d%d",&i,&j);
			i--;
			j--;
			if (d[i][j] < INFINITY)
			{
				printf("��%s��%s����̾���Ϊ%d \n",g.vex[i].name,g.vex[j].name,d[i][j]);
				printf("���ξ����ĳ��У�\n");
				for (k = 0; k < g.vexnum; ++k)
				{
					if (p[i][j][k] > 0)
					{
						order[p[i][j][k]] = k;
					}
				}
				for (n = 1 ; n < MAX_VERTEX_NUM; ++n)
				{
					if (order[n] > -1)
					{
						printf("%s->",g.vex[order[n]].name);
						order[n] = -1;//�ָ�Ĭ��ֵ
					}
				}
				printf("\b\b  \n");
			}
			else
			{
				printf("%s��%sû��·����ͨ�� \n",g.vex[i].name,g.vex[j].name,d[i][j]);
			}
		}

	}
}
