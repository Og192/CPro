//#define MG
#ifdef MG//ͼ�Ĵ洢�ṹΪ�ڽӾ���
#include "MGraph.h"
typedef MGraph Graph; 
#else//ͼ�Ĵ洢�ṹΪ�ڽӱ�
#include "ALGraph.h"
typedef ALGraph Graph;
#endif

//����������йصĻ�����������
void DFS(Graph G,int v);
void DFSTraverse(Graph G,void(*Visit)(VertexType));
void BFSTraverse(Graph G,void (* Visit)(VertexType));
