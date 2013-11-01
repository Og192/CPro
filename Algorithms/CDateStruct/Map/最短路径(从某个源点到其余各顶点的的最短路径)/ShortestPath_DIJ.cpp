#include "ShortestPath_DIJ.h"

void ShortestPath_DIJ(MGraph G,int v0,PathMatrix P,ShortestPathTable D)
{//�õϽ�˹�����㷨��Dijkstra algorithm�������·�� 
	int v,w,i,j;
	VRType min;
	Status Final[MAX_VERTEX_NUM];//��������S����������·���Ƿ��Ѿ���ã�Ϊ���ʾv0���ö������̾������������ֵΪ��
	int OrderCount[MAX_VERTEX_NUM];//�������飬��¼v0��v���·���ϵĶ����������ڸ�·���϶��㰴����
	for(v = 0; v < G.vexnum; ++v)
	{
		Final[v] = FALSE;//��ʼ��Ϊ��
		OrderCount[v] = 1;//��ʼ�����Ϊ1
		D[v] = G.arcs[v0][v].adj;//��̾����ʼ��Ϊv0
		for (w = 0; w < G.vexnum; ++w)
		{
			P[v][w] = 0;//·�������ʼ��Ϊ��
		}
		if(D[v] < INFINITY)//v0��v����·��
		{
			P[v][v0] = OrderCount[v];//·����������v ������
			P[v][v] = ++OrderCount[v];//·����������v0 ������
		}
	}
	D[v0] = 0;//v0��v0�����·��Ϊ0
	Final[v0] = TRUE;//�����v0��v0�����·��
	for (i = 0; i < G.vexnum - 1; ++i)//�Գ�v0��Ķ��������·��
	{
		min = INFINITY;//��ʼ����СֵΪ����ֵ
		for (w = 0; w < G.vexnum; ++w)//�����ж�����бȽ�
		{
			if (!Final[w] && D[w] < min)//��S����Ķ��㣨FInal[] = FALSE����
			{//����v0�����w,����ֵ��v,���븳ֵ��min
				v = w;//��Сֵ
				min = D[w];
			}
		}
		Final[v] = TRUE;//v0��v����̾��������,��v����S��
		for (w = 0; w < G.vexnum; ++w)
		{
			if (!Final[w] && min < INFINITY && G.arcs[v][w].adj < INFINITY && min + G.arcs[v][w].adj < D[w])
			{//w������S��������v0-v-w�ľ���С��v0-w�ľ���
				D[w] = min + G.arcs[v][w].adj;//����v��w����̾���D[w]����̾���Ϊv0-v-w
				for (j = 0; j < G.vexnum; ++j)
				{
					P[w][j] = P[v][j];//��v0-v·�����Ƶ�p[w]��
				}
				OrderCount[w] = OrderCount[v];//p[w]����p[v]�ı��
				P[w][w] = ++OrderCount[w];//·������w ������
			}

		}

	}
}