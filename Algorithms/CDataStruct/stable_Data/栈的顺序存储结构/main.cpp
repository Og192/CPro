#include "SqStack.h"
void print(SElemType e)
{
	printf("%d ",e);
}
int main(void)
{
	int j;
	SqStack s;
	SElemType e;
	InitStack(s);
	for (j = 1; j <= 12; j++)
	{
		Push(s,j);
	}
	printf("ջ�е�Ԫ������Ϊ");
	StackTraverse(s,print);
	Pop(s,e);
	printf("����ջ��Ԫ��e = %d\n",e);
	printf("ջ�Ƿ�Ϊ�գ�%d(1:�� 0������)\n",StackEmpty(s));
	GetTop(s,e);
	printf("ջ��Ԫ��e=%d,ջ�ĳ���Ϊ%d\n",e,StackLength(s));
	ClearStack(s);
	printf("���ջ�� �Ƿ�Ϊ�գ�%d(1:�� 0������)\n",StackEmpty(s));
	DestroyStack(s);
	printf("����ջ��s.base = %u,s.top = %u,s.stacksize = %d\n",s.top,s.base,s.stacksize);
	return 0;
}