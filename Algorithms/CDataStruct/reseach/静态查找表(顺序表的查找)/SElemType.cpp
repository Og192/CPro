#include "SElemType.h"

void visit(SElemType c)//���ʼ�¼
{
	printf("%-8ld %-8s %4d %5d %5d %5d %5d %5d %5d  %5d \n",c.number,c.name,c.politics,c.Chinese,c.English,c.math,c.physics,
		c.chemisty,c.biology,c.total);
}
void InputFromFile(FILE*f,SElemType &c)//���ļ��������¼
{
	fscanf(f,"%ld%s%d%d%d%d%d%d%d",&c.number,&c.name,&c.politics,&c.Chinese,&c.English,&c.math,&c.physics,
		&c.chemisty,&c.biology);
}
void InputKey(KeyType &k)//����ؼ���
{
	scanf("%ld",&k);
}