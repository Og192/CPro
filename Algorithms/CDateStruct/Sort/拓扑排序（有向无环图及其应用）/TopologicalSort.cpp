#include"TopologicalSort.h"

void FindIndegree(ALGraph G,int indegree[])
{//�󶥵����� 
	int i;
	ArcNode *p;
	for (i = 0; i < G.vexnum; ++i)
	{
		indegree[i] = 0;//�����еĶ������ȳ�ʼ��Ϊ0
	}
	for (i = 0; i < G.vexnum; ++i)
	{//�����ж���ͳ�����
		p = G.vertices[i].firstarc;//pָ���ڽӱ��ͷָ��
		while (p)//p����
		{
			indegree[p->data.adjvex]++;//p��ָ���ڽӽڵ���ȼ�1
			p = p->nextarc;//pָ����һ�ڽӵ�		
		}
	}
}

Status TopologicalSort(ALGraph G)
{
	int i,k,count = 0;
	int indegree[MAX_VERTEX_NUM];//�������,��Ÿ�����ǰ�����
	SqStack S;//�����ջ Ҳ���ö��д���
	ArcNode *p;
	FindIndegree(G,indegree);//��G�ĸ����������indegree[]
	InitStack(S);//��ʼ�������ջ
	for(i = 0; i < G.vexnum; ++i)//������ȵĶ��������ջ
	{
		if (!indegree[i])//���Ϊ��
		{
			Push(S,i);
		}
	}
	while (!StackEmpty(S))//��ջ����ʱ
	{
		Pop(S,i);//��ջһ������ȶ�������,�����丳ֵ��i
		printf("%s ",G.vertices[i].data.name);//��������
		++count;//�����������+1
		for (p = G.vertices[i].firstarc; p; p = p->nextarc)//��i�ŵĶ����ÿ���ڽӶ���
		{
			k = p->data.adjvex;//�����ΪK
			if (!(--indegree[k]))//k����ȼ�1,����Ϊ0,��k��ջS
			{
				Push(S,k);
			}
		}
	}
	if (count < G.vexnum)//����ȶ���ջS�ѿ�,ͼ���ж���δ���
	{
		printf("������ͼ�л�·��\n");
		return ERROR;
	}
	else
	{
		printf("����һ����������\n");
		return OK;
	}
}


/***�����������***/
extern bool visited[MAX_VERTEX_NUM];
SqStack topo;
void visit(SElemType e)
{
	printf("%d ",e);
}
void DFSTopo(Graph G,int v)
{
	ArcNode *p;
	visited[v] = TRUE;
	p = G.vertices[v].firstarc;
	while(p)
	{
		if (!visited[p->data.adjvex])
		{
			DFSTopo(G,p->data.adjvex);
			Push(topo,p->data.adjvex);
		}
		p = p->nextarc;
	}
}

void DFSTopoSort(Graph G)
{
	int v;
	for (v = 0; v < G.vexnum; ++v)
	{
		visited[v] = FALSE;
	}
	for (v = 0; v < G.vexnum; ++v)
	{
		if (!visited[v])
		{
			DFSTopo(G,v);
			Push(topo,v);
		}
	};
	while (!StackEmpty(topo))
	{
		Pop(topo,v);
		printf("%s ", G.vertices[v].data.name);
	}
	printf("\n");
}

