#include "Status.h"
#include "InfoType.h"//�����ߣ��������Ϣ����
#include "VertexType.h"//��������

#define MAX_VERTEX_NUM 20//��󶥵���
enum GraphKind{DG,DN,UDG,UDN};//ö�ٳ���GraphKindΪͼ������

struct ElemType
{//�洢�����ߣ�����Ϣ
	int adjvex;//�û����ߣ���ָ��Ķ����λ��
	InfoType * info;//�û��������Ϣ����������Ȩֵ����ָ��
};

struct ArcNode
{//���㣬�洢�����ߣ��������Ϣ
	ElemType data;//������
	ArcNode *nextarc;//ָ����һ�������ߣ�
};

typedef struct
{//ͷ��㣬�洢������Ϣ
	VertexType data;//������Ϣ
	ArcNode *firstarc;//��һ������ĵ�ַ��ָ���һ�������ڸö���Ļ���ָ��
}VNode, AdjList[MAX_VERTEX_NUM];

struct ALGraph
{//�ڽӱ�ṹ
	AdjList vertices;//ͷ��㣨���㣩����
	int vexnum,arcnum;//�������������ߣ���
	GraphKind kind;//ͼ�����ͱ�־
};

/****���뵥����Ļ�������****/
#define LNode ArcNode//���ڽӱ�ı����滻����������еĽ��
#define next nextarc//�滻����ָ����
typedef ArcNode *LinkList ;//�����ͷָ��ָ�����
//���������������������

Status Equal(ElemType e1,ElemType e2);//����
void InitList(LinkList &L);
void ClearList(LinkList &L);
Status ListEmpity(LinkList L);
int ListLength(LinkList L);
Status GetElem(LinkList L,int i,ElemType &e);
int LocateElem(LinkList L,ElemType e,Status(*compare)(ElemType,ElemType));
Status ListInsert(LinkList &L,int i,ElemType e);
Status ListDelete(LinkList &L,int i,ElemType &e);
void ListTraverse(LinkList L, void (*vi)(ElemType));
Status PriorElem(LinkList L,ElemType cur_e,ElemType &pre_e);//���޸� 
Status NextElem(LinkList L,ElemType cur_e,ElemType &next_e);//���޸�
LinkList Point(LinkList L,ElemType e,Status(*equal)(ElemType ,ElemType),LinkList &pre);//����
//�ڽӱ����������������

int LocateVex(ALGraph G,VertexType u);
void CreateGraph(ALGraph &G);
void CreateFromFile(ALGraph &G,char *filename);
VertexType GetVex(ALGraph &G,int v);
Status PutVex(ALGraph &G,VertexType v,VertexType value);
int FirstAdjVex(ALGraph G,int v);
Status EqualVex(ElemType a,ElemType b);
int NextAdjVex(ALGraph G,int v,int w);
void InsertVex(ALGraph &G,VertexType v);
Status InsertArc(ALGraph &G,VertexType v,VertexType w);
Status DeleteArc(ALGraph &G,VertexType v,VertexType w);
Status DeleteVex(ALGraph &G,VertexType v);
void DestroyGraph(ALGraph &G);
void Display(ALGraph G);