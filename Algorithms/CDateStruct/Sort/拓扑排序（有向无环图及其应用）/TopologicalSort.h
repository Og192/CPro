#include "ALGraph.h"
#include "SqStack.h"

//����������������
void FindIndegree(ALGraph G,int indegree[]);
Status TopologicalSort(ALGraph G);
void DFSTopo(Graph G,int v);
void DFSTopoSort(Graph G);