#include "CriticalPath.h"
int main(void)
{
	ALGraph h;
	printf("��ѡ������ͼ\n");
//	CreateGraph(h);
	CreateFromFile(h,"1.txt");
	Display(h);
	CriticalPath(h);
	return 0;
}