#include "Status.h"
#define STACK_INIT_SIZE 10//ջ�ĳ�ʼ����ռ�
#define STACK_INCREMENT 10//�洢�ռ��������
typedef int SElemType;

typedef struct SqStack
{
	SElemType *base;//�ڹ���ջ֮ǰ������֮��base��ֵΪNULL
	SElemType *top;//ջ��ָ��
	int stacksize;//��ǰ�Է���Ĵ洢�ռ�
};

//����������������
void InitStack(SqStack &S);

void DestroyStack(SqStack &S);

void ClearStack(SqStack &S);

Status StackEmpty(SqStack &S);

int StackLength(SqStack S);

Status GetTop(SqStack &S,SElemType &e);

void Push(SqStack &S,SElemType e);

Status Pop(SqStack &S,SElemType &e);

void StackTraverse(SqStack S, void (* visit)(SElemType));
