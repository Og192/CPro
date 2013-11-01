#include "FindArticul.h"
int count,lowcount = 1;//ȫ�ֱ���count�Զ������˳�������lowcount�����lowֵ��˳�����
int visited[MAX_VERTEX_NUM];//���ʱ�־����
int low[MAX_VERTEX_NUM],lowOrder[MAX_VERTEX_NUM];//low����涥���lowֵ,lowOrder�涥�����lowֵ��˳�򣨺����
void DFSArticul(ALGraph G, int v0)
{
	int min,w;
	ArcNode *p;
	visited[v0] = min = ++count;//v0�ǵ�count�����ʶ���,min�ĳ�ֵΪv0�ķ���˳��
	for (p = G.vertices[v0].firstarc;p;p = p->nextarc)
	{
		w = p->data.adjvex;//wΪv0���ڽӵ��λ��
		if (0 == visited[w])//wδ������,��v0�ĺ���
		{
			DFSArticul(G,w);//�ӵ�w�����������ȱ���ͼG,���Ҳ�����ؽڵ㡣����ǰ���low[w]
			if (low[w] < min)//���v0�ĺ��ӽ���lowֵС����˵�����ӽ�㻹�������ڵ㣨���ȣ�����
			{
				min = low[w];//ȡminֵΪ���ӽ���lowֵ����v0���ǹؽڵ�
			}
			else if (low[w] >= visited[v0])//v0�ĺ��ӽ��wֻ��v0����,��v0�ǹؽڵ�
			{
				printf("%d %s\n",v0,G.vertices[v0].data.name);//����ؽڵ�v0
			}
		}
		else
		{
			if (visited[w] < min)//w�ѷ���,��w��v0���������ϵ�����,���ķ���˳���С��min
			{
				min = visited[w];//��ȡminΪvisited[w]
			}
		}
	}
	low[v0] = min;//v0��lowֵΪ�����е���Сֵ
	lowOrder[v0] = lowcount++;//��¼v0���lowֵ����˳�������ڷ�����������֮ǰ���low[].
}

void FindArticul(ALGraph G)
{
	int i,v;
	ArcNode *p;
	count = 1;//����˳��
	visited[0] = count;//�趨�ڽӱ��ϵ�0�Ŷ���Ϊ�������ĸ�����i�������ʵĽ�㣻
	for (i = 1; i < G.vexnum; ++i)//�����ඥ���ʼ��
	{
		visited[i] = 0;
	}
	p = G.vertices[0].firstarc;
	v = p->data.adjvex;
	DFSArticul(G,v);
	if (count < G.vexnum)//˵���������ĸ�������������������ǹؽڵ�
	{
		printf("%d %s\n",0,G.vertices[0].data.name);//���ǹؽڵ㣬�������
		while (p->nextarc)//������һ���ڽӵ�
		{
			p = p->nextarc;//pָ����һ���ڽӵ�
			v = p->data.adjvex;
			if (visited[v] == 0)//���ڽӵ�δ������
			{
				DFSArticul(G,v);
			}
		}
	}
}