#include "SElemType.h"

void visit(SElemType c)//���ʼ�¼
{
	printf("(%c,%.2lf) ",c.key,c.weight);
}
void InputFromFile(FILE*f,SElemType &c)//���ļ��������¼
{
	fscanf(f,"%*c%c%lf",&c.key,&c.weight); 
}
void InputKey(KeyType &k)//����ؼ���
{
	scanf("%c",&k);
}