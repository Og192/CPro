//������ķ�㷨����С������
#include "MGraph.h"

typedef struct
{
	int adjvex;//���㼯U�е��õ㣨һά�������Ŷ�Ӧ��Ӧ�Ķ��㣩Ϊ��СȨֵ���Ǹ���������
	VRType lowcost;//�Ǹ����㵽�õ��Ȩֵ������С�ģ�
}minside[MAX_VERTEX_NUM];//��¼�Ӷ��㼯U�����㼯V-U�Ĵ�����С�ıߵĸ������鶨��

//������������
void MiniSpanTree_PRIM(MGraph G,VertexType u);