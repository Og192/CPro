#include "ALGraph.h"
//ȫ�ֱ�������
extern int count,lowcount;//ȫ�ֱ���count�Զ������˳�������lowcount�����lowֵ��˳�����
extern int visited[MAX_VERTEX_NUM];//���ʱ�־����
extern int low[MAX_VERTEX_NUM],lowOrder[MAX_VERTEX_NUM];//low����涥���lowֵ,lowOrder�涥�����lowֵ��˳�򣨺����
//��������
void DFSArticul(ALGraph G, int v0);
void FindArticul(ALGraph G);	

