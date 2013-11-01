//��ʼ������
Status InitArray(Array &A, int dim,...)//�䳤���������ά�ȳ���
{
	int elemtotal = 1, i;//elemtotal���ڼ�¼����Ԫ������
	va_list ap;//��������ָ��䳤�����������ָ��ap   va_lis��va_start��va_arg��va_end������ͷ�ļ�stdarg.h��

	if (dim < 1 || dim > MAX_ARRAY_DIM)
	{
		return ERROR;
	}
	A.dim = dim;//ά�ȸ�ֵ

	if (!(A.bounds = (int *)malloc(dim * sizeof(int))))//Ϊ�洢��ά�ȱ߽�����ַ
	{
		exit (OVERFLOW);
	}

	va_start(ap,dim); //��ʼ��ָ�룬�䳤������...���Ӳ���dim��ʼ
	for (i = 0; i < dim; ++i)
	{
		if ((A.bounds[i] = va_arg(ap,int)) < 0)//��ȡ�����ά�ȳ��ȵı䳤������ֵ������ά���ַ
		{
			return (UNDERFLOW);//����
		}
		elemtotal *= A.bounds[i];//�ۼ�����Ԫ���Լ�������
	}
	va_end(ap);//������ȡ�䳤����
	
	if (!(A.base = (ElemType*)malloc(elemtotal * sizeof(ElemType))))//��̬��������洢�ռ�
	{
		exit (OVERFLOW);
	}

	if (!(A.constants = (int *)malloc(dim * sizeof(int))))//��̬����ӳ���������洢�ռ�
	{
		exit (OVERFLOW);
	}

	A.constants[dim - 1] = 1;//���һά��ƫ����Ϊһ
	for (i = dim - 2; i >= 0; --i)
	{
		A.constants[i] = A.bounds[i + 1] * A.constants[i + 1];//ÿһά��ƫ����
	}
	return OK;
}

void DestroyArray(Array &A)//��������
{
	if (A.base)
	{
		free(A.base);
	}
	if (A.bounds)
	{
		free(A.bounds);
	}
	if (A.constants)
	{
		free(A.constants);
	}
	A.base = A.bounds = A.constants = NULL;
	A.dim = 0;
}

Status Locate(Array A,va_list ap,int &off)//��λ�����±��Ӧ����Ե�ַ
{
	int i,ind;
    off = 0;//��Ե�ַ

	for (i = 0; i < A.dim; ++i)
	{
		ind = va_arg(ap,int);
		if (ind < 0 || ind >= A.bounds[i])
		{
			return OVERFLOW;
		}
		off += ind * A.constants[i];
	}
	return OK;
}

Status Value(ElemType &e ,Array A,...)//������Ԫ�ظ�ֵ��e
{
	va_list ap;
	int off;
	va_start(ap,A);
	if (Locate(A,ap,off) == OVERFLOW)
	{
		return ERROR;
	}
	e = *(A.base + off);
	return OK;
}

Status Assign(Array &A, ElemType e,...)
{
	va_list ap;
	int off;
	va_start(ap,e);
	if (Locate(A,ap,off) == OVERFLOW)
	{
		return ERROR;
	}
	*(A.base + off) = e;
	return OK;
}