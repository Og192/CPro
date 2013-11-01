void InitStack(SqStack &S)//����һ����ջ
{
	if (!(S.base = (SElemType*)malloc(STACK_INIT_SIZE*sizeof(SElemType))))
	{
		exit (OVERFLOW);
	}
	S.top = S.base;
	S.stacksize = STACK_INIT_SIZE;
	return;
}

void DestroyStack(SqStack &S)//����ջS
{
	free(S.base);
	S.base = S.top = NULL;
	S.stacksize = 0;
	return;
}

void ClearStack(SqStack &S)//��S��Ϊ��ջ
{
	S.top = S.base;
	return;
}

Status IsStackEmpty(SqStack S)//�ж�S�Ƿ�Ϊ��ջ
{
	if (S.top == S.base)
	{
		return TRUE;
	}
	else
	{
		return FALSE;
	}
}

int StackLength(SqStack S)
{
	return S.top - S.base;
}

Status GetTop(SqStack S,SElemType &e)//��e����S��ջ��Ԫ��
{
	if (S.top > S.base)
	{
		e = *(S.top - 1);
		return OK;
	}
	else
	{
		return ERROR;
	}
}

void Push(SqStack &S,SElemType e)
{
	if (S.top - S.base == S.stacksize)//�ж�S�Ƿ�����
	{
		S.base = (SElemType *)realloc(S.base,(S.stacksize + STACK_INCREMENT )*sizeof(SElemType));
		
		if (!S.base)
		{
			exit (OVERFLOW);
		}
		
		S.top = S.stacksize + S.base; //ָ���µ�ջ��
		S.stacksize += STACK_INCREMENT; 
	}
	
	*S.top++ = e; 
}

Status Pop(SqStack &S,SElemType &e)//ɾ��ջ��Ԫ�أ���e������ֵ
{
	if (S.top == S.base)
	{
		return ERROR;
	}
	e = *--S.top;
    
	return OK;
}

void StackTraverse(SqStack S,void(*visit)(SElemType))//��ջ�׵�ջ�����ζ�S��ûһ��Ԫ�ص��ú���visit()
{
	while (S.base < S.top)
	{
		visit(*S.base++);
	}
	printf("\n");
}