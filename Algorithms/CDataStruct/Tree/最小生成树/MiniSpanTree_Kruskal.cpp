#include "MiniSpanTree_Kruskal.h"

void MiniSpanTree_Kruskal(MGraph G)
{
	int set[MAX_VERTEX_NUM];//�����ͨ����
	int senumber = 0,sb,i,j,k;
	side se[MAX_VERTEX_NUM * (MAX_VERTEX_NUM - 1) / 2];//һά����,�洢�ߵ���Ϣ
	for (i = 0; i < G.vexnum; ++i)
	{//�������б߲�����Ȩֵ����嵽se��
		for (j = i + 1; j < G.vexnum; ++j)
		{
			if (G.arcs[i][j].adj < INFINITY)
			{
				k = senumber - 1;
				while (k >= 0)
				{
					if (se[k].weight > G.arcs[i][j].adj)
					{//K��ָ��ֵ���ڸղ��ҵ��ߵ�Ȩֵ
						se[k + 1] = se[k];//k�ı������
						k--;//ָ��ǰһ����
					}
					else
					{
						break;
					}
				}
				se[k + 1].a = i;
				se[k + 1].b = j;
				se[k + 1].weight = G.arcs[i][j].adj;
				senumber++;
			}
		}
	}
	printf("i   se[i].a  se[i].b   se[i].weight\n");
	for (i = 0; i < senumber; ++i)
	{//�������se�а��������еĸ���
		printf("%d %4d %7d %9d \n",i,se[i].a,se[i].b,se[i].weight);
	}

	for (i = 0; i < G.vexnum; ++i)
	{
		set[i] = i;//���ֵ�������㶼��һ����ͨ����
	}	
	printf("��С��������������Ϊ��\n");
	j = 0;//jָʾseҪ��ǰҪ������С�������ߵıߵ���ţ���ֵΪ0
	k = 0;//kָʾ��ǰ������С�������ı���
	while (k < G.vexnum - 1)//��С������Ӧ��G.vexnum - 1 ����
	{
		if (set[se[j].a] != set[se[j].b])
		{//j��ָ�ߵ������㲻��ͬһ����ͨ�����У�������ͬһ�����ϣ�
			printf("(%s-%s)\n",G.vex[se[j].a].name,G.vex[se[j].b].name);
			sb = set[se[j].b];//���ñߵĶ���se[j].b���ڵ�����ͨ������־����sb
			for (i = 0; i < G.vexnum; ++i)
			{//��se[j].b��ͬһ����ͨ�����еĶ��㶼��ǵ�se[j].a������ͨ�����У�
				if (sb == set[i])
				{
					set[i] = set[se[j].a];
				}
			}
			k++;//����+1
		}
		j++;//jָʾ��һ��Ҫ������С�������еıߵ����
	}
}