#include <stdio.h>
#include "MGraph.h"
typedef MGraph Graph;

int main()
{
	int i,j,k,n;
	char s[4] = "��";
	Graph g;

	VertexType v1,v2;
	printf("������ѡ������ͼ��������������ͼ����������\n");
	for (i = 0; i < 4; i++)
	{
		CreateGraph(g);
		Display(g);
		printf("�����¶��㣬�������¶����ֵ��");
		Input(v1);
		InsertVex(g,v1);
		if (g.kind < 2)
		{
			strcpy(s,"��");
		}
		printf("�������¶����йص�%s,������%s����",s,s);
		scanf("%d",&n);
		for (k = 0; k < n; ++k)
		{
			printf("��������һ��������ƣ�");
			scanf("%s",&v2.name);
			if (g.kind <= 1)
			{
				printf("��������һ����ķ���0����ͷ 1����β��");
				scanf("%d",&j);
				if (j)
				{
					InsertArc(g,v2,v1);
				}
				else
				{
					InsertArc(g,v1,v2);
				}
			}
			else
			{
				InsertArc(g,v1,v2);
			}
		}
		Display(g);
		printf("ɾ�����㼰��ص�%s,�������ɾ���Ķ������ƣ�",s);
		scanf("%s",&v1.name);
		DeleteVex(g,v1);
		Display(g);
		if (3 == i)
		{
			printf("�޸Ķ����ֵ����������޸Ķ�������� ��ֵ:");
			scanf("%s",&v1.name);
			Input(v2);
			PutVex(g,v1,v2);
			if (g.kind < 2)
			{
				printf("ɾ��һ��%s,�������ɾ��%s�Ļ�β����ͷ��",s,s);
			}
			else
			{
				printf("ɾ��һ��%s���������ɾ����%s�Ķ���1������2��",s,s);
			}
			scanf("%s%s",v1.name,v2.name);
			DeleteArc(g,v1,v2);
			Display(g);
		}
		DestroyGraph(g);
	}


	return 0;
}
