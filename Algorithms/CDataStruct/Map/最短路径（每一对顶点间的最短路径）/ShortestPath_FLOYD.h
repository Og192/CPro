#include "MGraph.h"
typedef int PathMatrix[MAX_VERTEX_NUM][MAX_VERTEX_NUM][MAX_VERTEX_NUM];//��ά���飬���v��w�����·���ϵĶ��㣬����0Ϊ�У�0Ϊ��
typedef VRType DistancMatrix[MAX_VERTEX_NUM][MAX_VERTEX_NUM];//��ά���飬�洢v��w�����·������
void ShortestPath_FLOYD(MGraph G,PathMatrix P,DistancMatrix D);
