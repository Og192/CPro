#include "MiniSpanTree_PRIM.h"

int minimun(minside sz,MGraph G)
{
	int i = 0,j,k,min;
	while (!sz[i].lowcost)
	{//Ѱ�ҵ�һ�����۲�Ϊ0�Ķ������
		i++;
	}
	min = sz[i].lowcost;//��ʼ����СֵΪ��һ����Ϊ0�Ĵ���
	k = i;//��ʼ�����Ϊ��һ�����۲�Ϊ0�Ķ������
	for (j = i + 1; j < G.vexnum; ++j)
	{//��������Сֵ
		if (sz[j].lowcost != 0 && sz[j].lowcost < min)//���ڱ�ǰһ����Сֵ��С�Ĵ��۲��Ҳ�Ϊ�㣬�������Сֵ������k������
		{
			min = sz[j].lowcost;
			k = j;
		}
	}
	return k;
}

void MiniSpanTree_PRIM(MGraph G,VertexType u)
{
	int i,j,k;
	minside closedge;//��������
	k = LocateVex(G,u);//�������
	for (j = 0; j < G.vexnum; ++j)
	{//��ʼ����������
		closedge[j].adjvex = k;//��ʱU��ֻ�ж���u,�����Ϊk
		closedge[j].lowcost = G.arcs[k][j].adj;//u����������Ĵ��ۡ���������ֵΪINT_MAX
	}
	closedge[k].lowcost = 0;//u��u��ʼΪ0
	printf("��С�������ĸ�����Ϊ��\n");
	for (i = 1; i < G.vexnum; ++i)
	{
		k = minimun(closedge,G);//����С��������T����һ�����:���Ϊk
		printf("(%s-%s)\n",G.vex[closedge[k].adjvex].name,G.vex[k].name);//�����С�������ı�
		closedge[k].lowcost = 0;//��k�����㲢��U��
		for (j = 0; j < G.vexnum; ++j)
		{
			if (G.arcs[k][j].adj < closedge[j].lowcost)
			{//�¶��㲢��U��������ѡ����С��
				closedge[j].adjvex = k;
				closedge[j].lowcost = G.arcs[k][j].adj;
			}
		}
	}
}

//void MiniSpanTree_Kruskal()