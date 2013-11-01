#include "MGraph.h"

int LocateVex(MGraph G,VertexType u)
{//���ض���u��ͼ�е�λ�ã���ţ�
	int i;
	for (i = 0; i < G.vexnum; ++i)
	{
		if (0 == strcmp(G.vex[i].name,u.name))
		{
			return i;
		}
	}
	return -1;
}

void CreateDG(MGraph &G)
{
	int i,j,k,IncInfo;
	VertexType v1,v2;
	printf("����������ͼ�Ķ����������������Ƿ�����Ϣ���ǣ�1 ��0):");
	scanf("%d,%d,%d",&G.vexnum,&G.arcnum,&IncInfo);

	printf("������%d�������ֵ(����<%d���ַ�)\n",G.vexnum,MAX_NAME);
	for (i = 0; i < G.vexnum; ++i)
	{
		Input(G.vex[i]);
	}

	for (i = 0;i < G.vexnum; ++i)
	{//��ʼ���ڽӾ��󣨻�����Ϣ��
		for (j = 0; j < G.vexnum; ++j)
		{
			G.arcs[i][j].adj = 0;//��������
			G.arcs[i][j].info = NULL;//���������Ϣ
		}
	}
	
	printf("����%d�����Ļ�β�ͻ�ͷ\n",G.arcnum);
	for (k = 0; k < G.arcnum; ++k)
	{
		scanf("%s%s%*c",&v1.name,&v2.name);//%*c�Ե��س���
		i = LocateVex(G,v1);//��β�����
		j = LocateVex(G,v2);//��ͷ�����
		G.arcs[i][j].adj = 1;//
		if (IncInfo)
		{//�������Ϣ
			InputArc(G.arcs[i][j].info);//��̬���ɴ洢�ṹ�����뻡����Ϣ
		}
	}
	
	G.kind = DG;//���Ϊ����ͼ
}

void CreateDN(MGraph &G)
{
	int i,j,k,IncInfo;
	VertexType v1,v2;
	VRType w;
	printf("�������������Ķ����������������Ƿ�����Ϣ���ǣ�1 ��0):");
	scanf("%d,%d,%d",&G.vexnum,&G.arcnum,&IncInfo);

	printf("������%d�������ֵ(����<%d���ַ�)\n",G.vexnum,MAX_NAME);
	for (i = 0; i < G.vexnum; ++i)
	{
		Input(G.vex[i]);
	}

	for (i = 0;i < G.vexnum; ++i)
	{//��ʼ���ڽӾ��󣨱ߵ���Ϣ��
		for (j = 0; j < G.vexnum; ++j)
		{
			G.arcs[i][j].adj = INFINITY;//�߲�����
			G.arcs[i][j].info = NULL;//���������Ϣ
		}
	}
	
	printf("����%d��������ͷ����β�Ͷ�Ӧ��Ȩֵ\n",G.arcnum);
	for (k = 0; k < G.arcnum; ++k)
	{
		scanf("%s%s%d%*c",&v1.name,&v2.name,&w);//%*c�Ե��س���
		i = LocateVex(G,v1);//����1���
		j = LocateVex(G,v2);//����2���
		G.arcs[i][j].adj = w;//�ߵ�Ȩֵ
		if (IncInfo)
		{//�������Ϣ
			InputArc(G.arcs[i][j].info);//��̬���ɴ洢�ṹ������ߵ���Ϣ
		}
	}
	G.kind = DN;//���Ϊ������ 	
}

void CreateUDG(MGraph &G)
{
	int i,j,k,IncInfo;
	VertexType v1,v2;
	printf("����������ͼ�Ķ������������������Ƿ�����Ϣ���ǣ�1 ��0��:");
	scanf("%d,%d,%d",&G.vexnum,&G.arcnum,&IncInfo);

	printf("������%d�������ֵ(����<%d���ַ�)\n",G.vexnum,MAX_NAME);
	for (i = 0; i < G.vexnum; ++i)
	{
		Input(G.vex[i]);
	}

	for (i = 0;i < G.vexnum; ++i)
	{//��ʼ���ڽӾ��󣨻�����Ϣ��
		for (j = 0; j < G.vexnum; ++j)
		{
			G.arcs[i][j].adj = 0;//��������
			G.arcs[i][j].info = NULL;//���������Ϣ
		}
	}
	
	printf("����%d���ߵĶ���1�Ͷ���2\n",G.arcnum);
	for (k = 0; k < G.arcnum; ++k)
	{
		scanf("%s%s%*c",&v1.name,&v2.name);//%*c�Ե��س���
		i = LocateVex(G,v1);//��β�����
		j = LocateVex(G,v2);//��ͷ�����
		G.arcs[i][j].adj = 1;
		if (IncInfo)
		{//�������Ϣ
			InputArc(G.arcs[i][j].info);//��̬���ɴ洢�ṹ�����뻡����Ϣ
		}
		G.arcs[j][i].adj = G.arcs[i][j].adj;//����Գ�
	}
	
	G.kind = UDG;//���Ϊ����ͼ

}

void CreateUDN(MGraph &G)
{
	int i,j,k,IncInfo;
	VertexType v1,v2;
	VRType w;
	printf("�������������Ķ����������������Ƿ�����Ϣ���ǣ�1 ��0):");
	scanf("%d,%d,%d",&G.vexnum,&G.arcnum,&IncInfo);

	printf("������%d�������ֵ(����<%d���ַ�)",G.vexnum,MAX_NAME);
	for (i = 0; i < G.vexnum; ++i)
	{
		Input(G.vex[i]);
	}

	for (i = 0;i < G.vexnum; ++i)
	{//��ʼ���ڽӾ��󣨱ߵ���Ϣ��
		for (j = 0; j < G.vexnum; ++j)
		{
			G.arcs[i][j].adj = INFINITY;//�߲�����
			G.arcs[i][j].info = NULL;//���������Ϣ
		}
	}
	
	printf("����%d���ߵĶ���1������2�Ͷ�Ӧ��Ȩֵ\n",G.arcnum);
	for (k = 0; k < G.arcnum; ++k)
	{
		scanf("%s%s%d%*c",&v1.name,&v2.name,&w);//%*c�Ե��س���
		i = LocateVex(G,v1);//����1���
		j = LocateVex(G,v2);//����2���
		G.arcs[i][j].adj = w;//�ߵ�Ȩֵ
		if (IncInfo)
		{//�������Ϣ
			InputArc(G.arcs[i][j].info);//��̬���ɴ洢�ṹ������ߵ���Ϣ
		}
		G.arcs[j][i].adj = G.arcs[i][j].adj;//����Գ�
	}
	G.kind = UDN;//���Ϊ������ 	
}

void CreateGraph(MGraph &G)
{
	printf("������ͼG�����ͣ�����ͼ��0 ��������1 ����ͼ��2 ��������3��");
	scanf("%d",&G.kind);
	switch(G.kind)
	{//����ͼG�����ͣ����ò�ͬ�Ĺ���ͼ�ĺ���
	case DG: CreateDG(G);//����ͼ
		break;
	case DN:CreateDN(G);//������
		break;
	case UDG:CreateUDG(G);//����ͼ
		break;
	case UDN:CreateUDN(G);//������
	}
}

VertexType GetVex(MGraph G,int v)
{//�������Ϊv�Ķ���ֵ
	if (v > G.vexnum || v < 0)
	{
		exit(OVERFLOW);
	}
	return G.vex[v];
}

Status PutVex(MGraph &G,VertexType v,VertexType value)
{//��v����ֵ
	int k = LocateVex(G,v);
	if (k > G.vexnum || k < 0)
	{
		return ERROR;
	}
	G.vex[k] = value;
	return OK;
}

int FirstAdjVex(MGraph G,int v)
{//�������Ϊv�Ķ���ĵ�һ���ڽӵ�����
	int i;
	VRType j = 0;//Ĭ��Ϊͼ�ķ����ڱ�ʾ��0��
	if (v > G.vexnum || v < 0)
	{
		return ERROR;
	}
	if (G.kind % 2)//��
	{
		j = INFINITY;//��Ϊ���ķ����ڱ�ʾ��INFINITY��
	}

	for (i = 0; i < G.vexnum; ++i)
	{
		if (G.arcs[v][i].adj != j)//��Ϊ�����ڣ�������
		{
			return i;
		}
	}
	return -1;
}

int NextAdjVex(MGraph G,int v,int w)
{//�������Ϊv�Ķ������һ���ڽӵ㣨�����w��
	int i;
	VRType j = 0;
	if (v > G.vexnum || v < 0)
	{
		return ERROR;
	}
	if (G.kind % 2)//��
	{
		j = INFINITY;//��Ϊ���ķ����ڱ�ʾ��INFINITY��
	}

	for (i = w + 1; i < G.vexnum; ++i)
	{
		if (G.arcs[v][i].adj != j)//��Ϊ�����ڣ�������
		{
			return i;
		}
	}
	return -1;
}

void InsertVex(MGraph &G, VertexType v)
{//��ͼ�������¶���v(�������붥����صĻ���ߣ�����InsertArc()ȥ��)
	int i;
	VRType j = 0;
	G.vex[G.vexnum] = v;
	if (G.kind % 2)//��
	{
		j = INFINITY;
	}
	for (i = 0; i <= G.vexnum; ++i)
	{//��ʼ���ڽӾ���
		G.arcs[G.vexnum][i].adj = G.arcs[i][G.vexnum].adj = j;
		G.arcs[G.vexnum][i].info = G.arcs[i][G.vexnum].info = NULL;
	}
	G.vexnum++;//��������1
}
Status InsertArc(MGraph &G, VertexType v,VertexType w)
{//��ͼ������<v,w>,��������ͼ��������Գƻ�<w,v>
	int i,v1,w1;
	v1 = LocateVex(G,v);
	w1 = LocateVex(G,w);
	if (v1 < 0 || w1 < 0)
	{
		return ERROR;
	}
	if (G.kind % 2)//��
	{
		printf("������˻�����ߣ���Ȩֵ��");
		scanf("%d",&G.arcs[v1][w1].adj);
	}
	else
	{
		G.arcs[v1][w1].adj = 1;
	}
	printf("�Ƿ��иû���ߵ������Ϣ��0����  1���У�");
	scanf("%d%*c",&i);
	if (i)
	{//���뻡����Ϣ
		InputArc(G.arcs[v1][w1].info);
	}
	if (G.kind > 1)
	{//����
		G.arcs[w1][v1] = G.arcs[v1][w1];
	}
	G.arcnum++;
	return OK;
} 

Status DeleteArc(MGraph &G,VertexType v,VertexType w)
{//��ͼ��ɾ����<v,w>,�����������ɾ����<w,v>
	int v1,w1;
	VRType j = 0;
	v1 = LocateVex(G,v);
	w1 = LocateVex(G,w);
	if (v1 < 0 || w1 < 0)
	{
		return ERROR;
	}
	if (G.kind % 2)//��
	{
		j = INFINITY;
	}
	if (G.arcs[v1][w1].adj != j)
	{
		G.arcs[v1][w1].adj = j;
		if (G.arcs[v1][w1].info)
		{
			free(G.arcs[v1][w1].info);
			G.arcs[v1][w1].info = NULL;
		}
		if (G.kind > 1)//����
		{
			G.arcs[w1][v1] = G.arcs[v1][w1];
		}
		G.arcnum--;
	}
	return OK;	
}

Status DeleteVex(MGraph &G, VertexType v)
{//ɾ��ͼ�еĶ���v
	int i,j,k;
	k = LocateVex(G,v);
	if (k < 0)
	{
		return ERROR;
	}
	for (i = 0; i < G.vexnum; ++i)
	{//ɾ���ɶ���v���������л�
		DeleteArc(G,v,GetVex(G,i));
	}
	if (G.kind < 2)//����
	{//ɾ�����򶥵�v�����л�
		for (i = 0; i < G.vexnum; ++i)
		{
			DeleteArc(G,GetVex(G,i),v);
		}
	}
	for (i = k + 1; i < G.vexnum; ++i)
	{//ɾ������v�����
		G.vex[i - 1] = G.vex[i]; 
	}
	for (i = k + 1; i < G.vexnum; ++i)
	{//�ƶ���ɾ������֮�ҵľ���Ԫ��
		for (j = 0; j < G.vexnum; ++j)
		{
			G.arcs[j][i - 1] = G.arcs[j][i];
		}
	}
	for (i = k + 1; i < G.vexnum; ++i)
	{//�ƶ���ɾ������֮�µľ���Ԫ��
		for (j = 0; j < G.vexnum; ++j)
		{
			G.arcs[i - 1][j] = G.arcs[i][j];
		}
	}
	G.vexnum--;
	return OK;
}
void DestroyGraph(MGraph &G)
{
	int i;
	for (i = G.vexnum - 1; i >= 0; --i)
	{
		DeleteVex(G,G.vex[i]);
	}
}	

void Display(MGraph G)
{
	int i,j;
	char s[10] = "������", s1[4] = "��";
	switch(G.kind)
	{
	case DG:strcpy(s,"����ͼ");
			strcpy(s1,"��");
			break;
	case DN:strcpy(s,"������");
			strcpy(s1,"��");
			break;
	case UDG:strcpy(s,"����ͼ");
			break;
	case UDN:;
	}
	printf("%d������%d��%s��%s�����������ǣ�",G.vexnum,G.arcnum,s1,s);
	for (i = 0; i < G.vexnum; ++i)
	{
		Visit(GetVex(G,i));
	}
	printf("\nG.arcs.adj:\n");
	for (i = 0; i < G.vexnum; ++i)
	{
		for (j = 0; j < G.vexnum; ++j)
		{
			printf("%11d",G.arcs[i][j].adj);
		}
		printf("\n");
	}
	printf("G.arcs.info:\n");
	if (G.kind < 2)//����
	{
		printf("��β ��ͷ ��%s����Ϣ\n",s1);
	}
	else
	{
		printf("����1 ����2 ��%s����Ϣ:\n",s1);
	}
	for (i = 0; i < G.vexnum; ++i)
	{
		if (G.kind < 2)
		{
			for (j = 0; j < G.vexnum; ++j)
			{
				if (G.arcs[i][j].info)
				{
					printf("%5s%5s  ",G.vex[i].name,G.vex[j].name);
					OutputArc(G.arcs[i][j].info);
				}
			}
		}
		else
		{
			for (j = i + 1; j < G.vexnum; ++j)
			{
				if (G.arcs[i][j].info)
				{
					printf("%5s%5s ",G.vex[i].name,G.vex[j].name);
					OutputArc(G.arcs[i][j].info);
				}
			}
		}
	}
}

void CreateFromFile(MGraph &G,char *filename,int IncInfo)
{
	int i,j,k;
	VRType w = 0;
	VertexType v1,v2;
	FILE *f;
	f = fopen(filename,"r");
	fscanf(f,"%d",&G.kind);
	if (G.kind%2)
	{ 
		w = INFINITY;
	}
	fscanf(f,"%d",&G.vexnum);
	for (i = 0; i < G.vexnum; ++i)
	{
		InputFromFile(f,G.vex[i]);
	}
	fscanf(f,"%d",&G.arcnum);
	for (i = 0; i < G.vexnum; ++i)
	{//��ʼ���ڽӾ���
		for (j = 0; j < G.vexnum; ++j)
		{
			G.arcs[i][j].adj = w;
			G.arcs[i][j].info = NULL;
		}
	}
	if (!(G.kind%2))
	{
		w = 1;
	}
	for (k = 0; k < G.arcnum; ++k)
	{
		fscanf(f,"%s%s",v1.name,v2.name);
		if (G.kind%2)
		{
			fscanf(f,"%d",&w);
		}
		i = LocateVex(G,v1);
		j = LocateVex(G,v2);
		G.arcs[i][j].adj = w;
		if (IncInfo)
		{
			InputArcFromFile(f,G.arcs[i][j].info);
		}
		if (G.kind > 1)
		{
			G.arcs[j][i] = G.arcs[i][j];
		}
	}
	fclose(f);
}

