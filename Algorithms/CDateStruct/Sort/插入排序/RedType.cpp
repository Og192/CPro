#include "RedType.h"
void InputFromFile(FILE *f,RedType &c)
{//���ļ������¼�ĺ���
	fscanf(f,"%d%d",&c.key,&c.otherinfo);
}