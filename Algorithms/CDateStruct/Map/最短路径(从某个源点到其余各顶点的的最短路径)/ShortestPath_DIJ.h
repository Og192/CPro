#include "MGraph.h"
typedef int PathMatrix[MAX_VERTEX_NUM][MAX_VERTEX_NUM];//·������
typedef VRType ShortestPathTable[MAX_VERTEX_NUM]; //��̾����
void ShortestPath_DIJ(MGraph G,int v0,PathMatrix P,ShortestPathTable D);