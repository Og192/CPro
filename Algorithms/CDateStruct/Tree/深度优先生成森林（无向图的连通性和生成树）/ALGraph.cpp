#include "ALGraph.h"

int LocateVex(ALGraph G,VertexType u)
{//���ض�����ͼ�е�λ��
	int i;
	for (i = 0; i < G.vexnum; ++i)
	{
		if (strcmp(G.vertices[i].data.name,u.name) == 0)
		{
			return i;
		}
	}
	return -1;
}

void CreateGraph(ALGraph &G)
{
	int i,j,k;
	VertexType v1,v2;
	ElemType e;
	char s[4] = "��";
	printf("������ͼ�����ͣ�����ͼ��0 ��������1 ����ͼ��2 ��������3��");
	scanf("%d",&G.kind);
	if (G.kind < 2)
	{
		strcpy(s,"��");
	}
	printf("������ͼ�Ķ�������%s��:",s);
	scanf("%d,%d",&G.vexnum,&G.arcnum);
	printf("������%d�������ֵ������<%d���ַ�����\n",G.vexnum,MAX_NAME);
	for (i = 0; i < G.vexnum; ++i)
	{
		Input(G.vertices[i].data);
		G.vertices[i].firstarc = NULL;//��ʼ��
	}
	printf("������%d��%s��",G.arcnum,s);
	switch (G.kind)
	{
	case DG:printf("��ͷ ��β��\n");
			break;
	case DN:printf("��β ��ͷ ������Ϣ��\n");
			break;
	case UDG:printf("����1 ����2��\n");
			break;
	case UDN:printf("����1 ����2 �ߵ���Ϣ:\n");
			break;
	}
	for (k = 0; k < G.arcnum; ++k)
	{
		scanf("%s%s",v1.name,v2.name);
		i = LocateVex(G,v1);
		j = LocateVex(G,v2);
		e.info = NULL;//������ı����������ֵ����ͼ�޻����ߣ���Ϣ
		if (G.kind % 2)//��
		{
			InputArc(e.info);
		}
		e.adjvex = j;//������ı����������ֵ
		ListInsert(G.vertices[i].firstarc,1,e);//���ڵ�i������ı�ͷ
		if (G.kind >= 2)//����ͼ������������2�����㣬�������ڵ�j������ı�ͷ
		{
			e.adjvex = i;
			ListInsert(G.vertices[j].firstarc,1,e);
		}
	}
}

void CreateFromFile(ALGraph &G,char *filename)
{
	int i,j,k;
	VertexType v1,v2;
	ElemType e;
	FILE *f;
	f = fopen(filename,"r");
	fscanf(f,"%d",&G.kind);
	fscanf(f,"%d",&G.vexnum);
	for (i = 0; i < G.vexnum; ++i)
	{
		InputFromFile(f,G.vertices[i].data);
		G.vertices[i].firstarc = NULL;
	}
	fscanf(f,"%d",&G.arcnum);
	for (k = 0; k < G.arcnum; ++k)
	{
		fscanf(f,"%s%s",v1.name,v2.name);
		i = LocateVex(G,v1);
		j = LocateVex(G,v2);
		e.info = NULL;
		if (G.kind%2)
		{
			InputArcFromFile(f,e.info);
		}
		e.adjvex = j;
		ListInsert(G.vertices[i].firstarc,1,e);
		if (G.kind >= 2)
		{
			e.adjvex = i;
			ListInsert(G.vertices[j].firstarc,1,e);
		}
	}
	fclose(f);
}

VertexType GetVex(ALGraph &G,int v)
{
	if (v >= G.vexnum || v < 0)
	{
		exit(OVERFLOW);
	}
	return G.vertices[v].data;
}

Status PutVex(ALGraph &G,VertexType v,VertexType value)
{
	int k = LocateVex(G,v);
	if (k != -1)
	{
		G.vertices[k].data = value;
		return OK;
	}
	return ERROR;
}

int FirstAdjVex(ALGraph G,int v)
{
	ArcNode *p = G.vertices[v].firstarc;
	if (p)
	{
		return p->data.adjvex;
	}
	return -1;
}

Status EqualVex(ElemType a,ElemType b)
{
	if (a.adjvex == b.adjvex)
	{
		return OK;
	}
	else
	{
		return ERROR;
	}
}

int NextAdjVex(ALGraph G,int v,int w)
{
	LinkList p,p1;
	ElemType e;
	e.adjvex = w;
	p = Point(G.vertices[v].firstarc,e,EqualVex,p1);
	if (!p || !p->nextarc)
	{
		return -1;
	}
	return p->nextarc->data.adjvex;
}

void InsertVex(ALGraph &G,VertexType v)
{
	G.vertices[G.vexnum].data = v;
	G.vertices[G.vexnum].firstarc = NULL;
	G.vexnum++;
}

Status InsertArc(ALGraph &G,VertexType v,VertexType w)
{
	int i,j;
	ElemType e;
	char s1[4] = "��",s2[4] = "-";
	i = LocateVex(G,v);
	j = LocateVex(G,w);
	if (i < 0 || j < 0 || i == j)
	{
		return ERROR;
	}
	if (G.kind < 2)
	{
		strcpy(s1,"��");
		strcpy(s2,"��");
	}
	G.arcnum++;
	e.info = NULL;
	if (G.kind%2)//��
	{
		printf("������%s%s%s%s����Ϣ: ",s1,v.name,s2,w.name);
		InputArc(e.info);
	}
	e.adjvex = j;
	ListInsert(G.vertices[i].firstarc,1,e);
	if (G.kind >= 2)
	{
		e.adjvex = i;
		ListInsert(G.vertices[j].firstarc,1,e);
	}
	return OK;
}

Status DeleteArc(ALGraph &G,VertexType v,VertexType w)
{
	int i,j,n;
	ElemType e;
	i = LocateVex(G,v);
	j = LocateVex(G,w);
	if (i < 0 || j < 0 || i == j)
	{
		return ERROR;
	}
	e.adjvex = j;
	n = LocateElem(G.vertices[i].firstarc,e,EqualVex);
	if (n)
	{
		ListDelete(G.vertices[i].firstarc,n,e);
		G.arcnum--;
		if (G.kind % 2)
		{
			free(e.info);
		}
		if (G.kind >= 2)
		{
			e.adjvex = i;
			n = LocateElem(G.vertices[j].firstarc,e,EqualVex);
			ListDelete(G.vertices[j].firstarc,n,e);
		}
		return OK;
	}
	return ERROR;	
}

Status DeleteVex(ALGraph &G,VertexType v)
{
	int i,k;
	LinkList p;
	k  = LocateVex(G,v);
	if (k < 0)
	{
		return ERROR;
	}
	for (i = 0; i < G.vexnum; ++i)
	{
		DeleteArc(G,v,G.vertices[i].data);
	}
	if (G.kind < 2)
	{
		for (i = 0; i < G.vexnum; ++i)
		{
			DeleteArc(G,G.vertices[i].data,v);
		}
	}
	for (i = 0; i < G.vexnum; ++i)
	{
		p = G.vertices[i].firstarc;
		while(p)
		{
			if (p->data.adjvex > k)
			{
				p->data.adjvex--;
			}
			p = p->nextarc;
		}
	}
	for (i = k + 1; i < G.vexnum;++i)
	{
		G.vertices[i - 1] = G.vertices[i];
	}
	G.vexnum--;
	return OK;
}

void DestroyGraph(ALGraph &G)
{
	int i;
	for (i = 0; i < G.vexnum; ++i)
	{
		DeleteVex(G,G.vertices[i].data);
	}
}

void Display(ALGraph G)
{
	int i;
	ArcNode *p;
	char s1[4] = "��",s2[4] = "-";
	if (G.kind < 2)
	{
		strcpy(s1,"��");
		strcpy(s2,"��");
	}
	switch (G.kind)
	{
	case DG:printf("����ͼ\n");
			break;
	case DN:printf("������\n");
			break;
	case UDG:printf("����ͼ\n");
			break;
	case UDN:printf("������\n");
			break;
	}
	printf("%d�����������ǣ�",G.vexnum);
	for (i = 0; i < G.vexnum; ++i)
	{
		Visit(G.vertices[i].data);
	}
	printf("\n%d��%s:\n",G.arcnum,s1);
	for (i = 0; i < G.vexnum; ++i)
	{
		p = G.vertices[i].firstarc;
		while (p)
		{
			if (G.kind < 2 || i < p->data.adjvex)
			{
				printf("%s%s%s ",G.vertices[i].data.name,s2,G.vertices[p->data.adjvex].data.name);
				if (G.kind%2)
				{
					OutputArc(p->data.info);
				}
			}

			p = p->nextarc;
		}
		printf("\n");
	}
}
