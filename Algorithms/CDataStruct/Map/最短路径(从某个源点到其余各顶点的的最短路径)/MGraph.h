#ifndef MGR_H
#define MGR_H
#include "Status.h"
#include "InfoType.h"
#include "VertexType.h"
#include <stdio.h>
#include <string>

#define INFINITY INT_MAX
typedef int VRType;//���嶨������Ϊ���ͣ���INFINITY������һ��
#define MAX_VERTEX_NUM 26
enum GraphKind{DG,DN,UDG,UDN};

typedef struct //�ߣ��򻡣�����Ϣ�ṹ
{
	VRType adj; //�����ϵ���͡�����Ȩͼ����1���ǣ���2���񣩱�ʾ���ڷ񣻶Դ�Ȩֵ����ΪȨֵ
	InfoType *info;//�û��������Ϣ��ָ�루���ޣ�
}ArcCell,AdjMatrix[MAX_VERTEX_NUM][MAX_VERTEX_NUM];//��ά���飬������Ŷ�Ӧ��Ӧ�Ķ�����ţ�����ֵ��ʾ�������ϵ

struct MGraph//ͼ����Ϣ�ṹ
{
	VertexType vex[MAX_VERTEX_NUM];//�������� һά����洢������Ϣ
	AdjMatrix arcs;//�ڽӾ���,�洢�ߣ��򻡣��Ĺ�ϵ
	int vexnum, arcnum;//ͼ�ĵ�ǰ�������ͱߣ��򻡣���
	GraphKind kind;//ͼ�����ͱ�־
};

int LocateVex(MGraph G,VertexType u);
void CreateDG(MGraph &G);
void CreateDN(MGraph &G);
void CreateUDG(MGraph &G);
void CreateUDN(MGraph &G);
void CreateGraph(MGraph &G);
VertexType GetVex(MGraph G,int v);
Status PutVex(MGraph &G,VertexType v,VertexType value);
int FirstAdjVex(MGraph G,int v);
int NextAdjVex(MGraph G,int v,int w);
void InsertVex(MGraph &G, VertexType v);
Status InsertArc(MGraph &G, VertexType v,VertexType w);
Status DeleteArc(MGraph &G,VertexType v,VertexType w);
Status DeleteVex(MGraph &G, VertexType v);
void DestroyGraph(MGraph &G);
void Display(MGraph G);
void CreateFromFile(MGraph &G,char *filename,int IncInfo);
#endif

