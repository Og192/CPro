void DestroySMatrix(TSMatrix &M)//����ϡ�����
{
	M.mu = M.nu = M.tu = 0;
}

void PrintSMatrix(TSMatrix M)//��ӡϡ�����
{
	int i,j,k = 1;
	Triple * tp = &M.date[1];//tpָ����Ԫ����Ԫ�صĵ�ַ
	for (i = 1; i <= M.mu; i++)
	{
		for (j = 1; j <= M.nu; j++)
		{
			if (k <= M.tu && tp->i == i && tp->j == j)//ϡ�����Ԫ��Ϊ����
			{
				printf("%3d",tp->e);
				tp++;
				k++;
			}
			else //ϡ�����Ԫ��ֵΪΪ��
			{
				printf("%3d",0);
			}
		}
		printf("\n");
	}
}

void CopySMatrix(TSMatrix M, TSMatrix &T)//����ϡ�����
{
	T = M;
}

Status SubtSMatrix(TSMatrix M,TSMatrix N, TSMatrix &Q)//ϡ��������
{
	int p;
	if (M.mu != N.mu && M.nu != N.nu)
	{
		return ERROR;
	}

	for (p = 1; p <= N.tu; p++)
	{
		N.date[p].e *= -1;
	}
	AddSMatrix(M,N,Q);
	return OK;
}