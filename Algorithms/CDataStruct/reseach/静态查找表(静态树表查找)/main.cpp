#include "SSTable.h"

int main(void)
{
	SSTable st;
	SOSTree t;
	KeyType s;
	Status i;
	Creat_OrderFromFile(st,"1.txt");
	Traverse(st);
	CreateSOSTree(t,st);
	printf("����������ҵ��ַ�");
	InputKey(s);
	i = Search_SOSTree(t,s);
	if (i)
	{
		printf("%c��Ȩֵ��%.2lf\n",s,t->date.weight);
	}
	else
	{
		printf("���в����ڴ��ַ�!\n");
	}
	Destroy(st);//���پ�̬���ұ�
	return 0;
}