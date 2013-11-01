Status InitMatrix(SyMatrix &M,int n)
{
	int space;//�Գƾ����ѹ���洢�ռ��С
	if (n < 1 || n > MAX_SYM_DEGREE)
	{
		return ERROR;
	}
	M.degree = n;//����
	M.comspace = (n * (n + 1))/2; //ѹ���洢�ռ�

	if (!(M.base = (ElemType*)malloc(M.comspace * sizeof(ElemType))))//��̬�������ѹ���洢�ռ�
	{
		exit (OVERFLOW);
	}
	return OK;
}

void DestroyMaxtrix(SyMatrix &M)//���ٶԳƾ���
{
	if (M.base)
	{
		free(M.base);
	}
	M.base = NULL;
    M.degree = 0;
	M.comspace = 0;
}

Status Locate(SyMatrix M,int i,int j,int &off)//ͨ���±귵�ضԳƾ�����ѹ���ռ��е����λ��
{
	int m,n;
	if (i < 1 || i > M.degree || j < 1 || j > M.degree)
	{
		return ERROR;
	}
	if (i >= j)
	{
		m = i;
		n = j;
	}
	else
	{
		m = j;
		n = i;
	}

	off = ( m*( m - 1 ) )/2 + n - 1;//ͨ���±����Գƾ�����ѹ���ռ��е����λ��

	return OK;
}

Status Value(SyMatrix M,ElemType &e,int i,int j)//���Գƾ�������Ӧ�±��Ԫ�ظ���e
{
	int off = 0;
	if (Locate(M,i,j,off) == ERROR)
	{
		return ERROR;
	}
	e = M.base[off];
	return OK;
}

Status Assign(SyMatrix &M,ElemType e,int i,int j)//��e��ֵ���Գƾ�������Ӧ�±��Ԫ��
{
	int off = 0;
	if (Locate(M,i,j,off) == ERROR)
	{
		return ERROR;
	}
	M.base[off] = e;
	return OK;	
}

void SymPrint(SyMatrix M)
{
	int i,j,off;
	for (i = 1; i <= M.degree; i++)
	{
		for (j = 1; j <= M.degree; j++)
		{
			Locate(M,i,j,off);
			printf("%d ",M.base[off]);
		}
		printf("\n");
	}
}