#include "TopologicalSort.h"
int main(void)
{
	ALGraph f;
//	printf("��ѡ������ͼ\n");
//	CreateGraph(f);
	CreateFromFile(f,"1.txt");
	Display(f);
	TopologicalSort(f);
	printf("DFSTopo:\n");
	DFSTopoSort(f);
	return 0;
}