#include "ShortestPath_FLOYD.h"

void ShortestPath_FLOYD(MGraph G,PathMatrix P,DistancMatrix D)
{
	int v,w,u,i;
	int ordercount[MAX_VERTEX_NUM][MAX_VERTEX_NUM];//�������飬���ڸ����·���ϵĶ�����
	for (v = 0; v < G.vexnum; ++v)
	{
		for (w = 0; w < G.vexnum; ++w)
		{
			D[v][w] = G.arcs[v][w].adj;//��ʼ��v��w�����·������Ϊ����v��w��ֱ�Ӿ��룻
			ordercount[v][w] = 1;
			for (u = 0; u < G.vexnum; ++u)
			{
				P[v][w][u] = FALSE;//��ʼ������������·�����Ϊ0
			}
			if (D[v][w] < INFINITY)
			{
				P[v][w][v] = ordercount[v][w];//v��w�����·����������v,������
				if (v != w)
				{
					P[v][w][w] = ++ordercount[v][w];//v��w�����·����������w��������
				}
			}		
		}
	}

	for (u = 0; u < G.vexnum; ++u)
	{
		for (v = 0; v < G.vexnum; ++v)
		{
			for (w = 0; w < G.vexnum; ++w)
			{
				if (D[v][u] < INFINITY && D[u][w] < INFINITY && D[v][u] + D[u][w] < D[v][w])
				{//��v��u��w��һ��·������
					D[v][w] = D[v][u] + D[u][w];//������̾���
					ordercount[v][w] = ordercount[v][u];//���±��
					for (i = 0; i < G.vexnum; ++i)
					{
						P[v][w][i] = P[v][u][i];//��v��w��·��������v��u����·��������·��
						if (!P[v][w][i] && (P[v][u][i] || P[u][w][i]))
					    {
							P[v][w][i] = P[u][w][i] + ordercount[v][u] - 1;//��v��w��·��������u��w������·��������·������Ÿ���
							ordercount[v][w]++;//��ż�1
						}
					} 

				}
			}
		}
	}
}
