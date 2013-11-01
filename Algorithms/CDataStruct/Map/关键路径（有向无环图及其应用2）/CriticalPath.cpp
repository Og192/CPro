#include "CriticalPath.h"

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

Status TopologicalOrder(ALGraph &G,SqStack &T)
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
	InitStack(T);
	for (i = 0; i < G.vexnum; ++i)//��ʼ��veΪ0
	{
		G.vertices[i].data.ve = 0;
	}
	while (!StackEmpty(S))//��ջ����ʱ
	{
		Pop(S,i);//��ջһ������ȶ�������,�����丳ֵ��i
		Visit(G.vertices[i].data);
		Push(T,i);//i�Ŷ���������������ջT(ջ��Ԫ��Ϊ��������ĵ�1��Ԫ��)
		++count;//�����������+1
		for (p = G.vertices[i].firstarc; p; p = p->nextarc)//��i�ŵĶ����ÿ���ڽӶ���
		{
			k = p->data.adjvex;//�����ΪK
			if (!(--indegree[k]))//k����ȼ�1,����Ϊ0,��k��ջS
			{
				Push(S,k);
			}
			if ((G.vertices[i].data.ve + p->data.info->weight) > G.vertices[k].data.ve)
			{//����i�¼������緢��ʱ�� + <i,k>��Ȩֵ  > ����j�¼������緢��ʱ��
				G.vertices[k].data.ve = G.vertices[i].data.ve + p->data.info->weight;
				//����j�¼������緢��ʱ�� = ����i�¼������緢��ʱ�� + <i,k>��Ȩֵ
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
		return OK;
	}
}

Status CriticalPath(ALGraph &G)
{
	SqStack T;
	int i,j,k;
	ArcNode *p;
	if (!TopologicalOrder(G,T))
	{
		return ERROR;
	}
	j = G.vertices[0].data.ve;//j�ĳ�ֵ
	for (i = 1; i < G.vexnum;++i)
	{
		if (G.vertices[i].data.ve > j)
		{
			j = G.vertices[i].data.ve;//j = MAX(ve)��ɵ�����緢��ʱ��
		}
	}
	for (i = 0; i < G.vexnum; ++i)//��ʼ�������¼�����ٷ���ʱ��
	{
		G.vertices[i].data.vl = j;
	}
	while (!StackEmpty(T))//������������������vlֵ
	{
		Pop(T,j);
		p = G.vertices[j].firstarc;
		while (p)
		{
			k = p->data.adjvex;//���򶥵��ֵ
			if (G.vertices[k].data.vl - p->data.info->weight < G.vertices[j].data.vl)
			{//�¼�j����ٷ���ʱ�� > ��ֱ�Ӻ���¼�����ٷ���ʱ�� - <j,k>��Ȩֵ
				G.vertices[j].data.vl = G.vertices[k].data.vl - p->data.info->weight;
			 //�¼�j����ٷ���ʱ�� = ��ֱ�Ӻ���¼�����ٷ���ʱ�� - <j,k>��Ȩֵ
			}
			 p = p->nextarc;
		}
	}
	printf("\ni  ve  vl\n");
	for (i = 0; i < G.vexnum; ++i)
	{
		printf("%d  ",i);//������
		Visitel(G.vertices[i].data);//���ve��vl��ֵ
		if (G.vertices[i].data.ve == G.vertices[i].data.vl)
		{//�¼������㣩�����緢��ʱ�� = ��ٷ���ʱ��
			printf("  �ؼ�·�������Ķ���");
		}
		printf("\n");
	}
	printf("j  k  Ȩֵ  ee  el\n");
	for (j = 0; j < G.vexnum; ++j)
	{
		for (p = G.vertices[j].firstarc;p;p = p->nextarc)
		{
			k = p->data.adjvex;//�ڽӶ��㣨ֱ�Ӻ���¼��������
			p->data.info->ee = G.vertices[j].data.ve;//ee(�<i,j>�����翪ʼʱ�� = ������j���¼����緢��ʱ��)
			p->data.info->el = G.vertices[k].data.vl - p->data.info->weight;
			////el(�<j,k>����ٿ�ʼʱ��)=������k���¼���ٷ���ʱ��-<j,k>��Ȩֵ
			printf("%s->%s",G.vertices[j].data.name,G.vertices[k].data.name);
			OutputArcwel(p->data.info);
			if (p->data.info->ee == p->data.info->el)
			{//����翪ʼʱ�� = ���ٿ�ʼʱ�� 
				printf("  �ؼ��");
			}
			printf("\n");
		}
	}
	return OK;
}


