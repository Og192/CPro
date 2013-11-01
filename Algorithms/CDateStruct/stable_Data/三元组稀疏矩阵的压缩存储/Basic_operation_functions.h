Status CreateSMatrix(TSMatrix &M)
{
	int i;
	Status k;
	Triple T;
	
	printf("������ϡ�����������������ͷ���Ԫ�ظ�����С��%d��:",MAX_SIZE);
	scanf("%d,%d,%d",&M.mu, &M.nu, &M.tu);
	if (M.tu > MAX_SIZE)
	{
		return ERROR;
	}
	M.date[0].i = M.date[0].j = 0;//��һ����Ϊ��
	for (i = 1; i <= M.tu; i++)
	{
		do 
		{
			printf("�������%d������Ԫ�ص��У�1~%d������(1~%d)��Ԫ��ֵ:",i,M.mu,M.nu);
			scanf("%d,%d,%d",&T.i, &T.j, &T.e);
			k = 0;//���������ȷ
			if (T.i < 1 || T.i > M.mu || T.j < 1 || T.j > M.nu)
			{
				k = 1;//���뷶Χ���󣬱���������
			}
			if (T.i < M.date[i - 1].i || T.i == M.date[i - 1].i && T.j <= M.date[i - 1].j)
			{
				k = 1;//����˳�����󣬱���������
			}

		}while(k);

		M.date[i] = T;//������Ԫ��
	}
	return OK;
}

Status AddSMatrix(TSMatrix M,TSMatrix N,TSMatrix &Q)
{
	int m = 1,n = 1,q = 0;
	if (M.mu != N.mu || M.nu != N.nu)//����������в�ͬ
	{
		return ERROR;
	}
	Q.mu = M.mu;//����ϡ�����Q���к���
	Q.nu = M.nu;
	while (m <= M.tu && n <= N.tu)
	{
		switch (comp(M.date[m].i,N.date[n].i))
		{//�Ƚϵ�ǰԪ�ص��й�ϵ
		case -1 :Q.date[++q] = M.date[m++];
			break;
		case 0:
			switch (comp(M.date[m].j,N.date[n].j))
			{//�Ƚϵ�ǰԪ�ص��й�ϵ
			case -1:Q.date[++q] = M.date[m++];
				break;
			case 0:Q.date[++q] = M.date[m++];
					Q.date[q].e +=N.date[n++].e; 
					if (0 == Q.date[q].e)//Ԫ�غ�Ϊ0��������
					{
						q--;
					}
					break;
			case 1:Q.date[++q] = N.date[n++];
			}
			break;
		case 1:Q.date[++q] = N.date[n++];
		}
	}

	while (m <= M.tu)//MԪ��δ������
	{
		Q.date[++q] = M.date[m++];
	}
	while (n <= N.tu)//NԪ��δ������
	{
		Q.date[++q] = N.date[n++];
	}
	if (q > MAX_SIZE)//Q�ķ���Ԫ�س������ֵ
	{
		return ERROR;
	}
	Q.tu = q;
	return OK;
}

void TransposeSMatrix(TSMatrix M,TSMatrix &T)//��ϡ�����M��ת�þ���T
{
	int col,p,q = 0;

	T.mu = M.nu;
	T.nu = M.mu;
	T.tu = M.tu;
	if (T.tu)//T.tu�ǿ�
	{
		for (col = 1; col <= M.nu; col++)
		{
			for (p = 1; p <= M.tu; p++)
			{
				if (col == M.date[p].j)
				{
					T.date[++q].i = M.date[p].j;
					T.date[q].j = M.date[p].i;
					T.date[q].e = M.date[p].e;
				}
			}
		}
	}
}

Status MultSMatrix(TSMatrix M,TSMatrix N,TSMatrix &Q)
{
	int i,j,p,q;
	ElemType Qs;//�洢��ʱ����
	TSMatrix T;//����N��ת�þ���

	if (M.nu != N.mu)
	{//�����Ͼ�����˵�����6
		return ERROR;
	}
	Q.mu = M.mu;//Q������
	Q.nu = N.nu;//Q������
	Q.tu = 0;	
	TransposeSMatrix(N,T);//��N��ת�þ���浽T

	for (i = 1; i <= Q.mu; i++)
	{
		q = 1;//ָ��T
		for (j = 1; j <= Q.nu; j++)
		{	
			Qs = 0;
			p = 1;//ָ��M
			while (M.date[p].i < i)
			{
				p++;
			}
			while (T.date[q].i < j)
			{
				q++;
			}
			while (p <= M.tu && q <= T.tu && M.date[p].i == i && M.date[q].i == j)
			{
				switch(comp(M.date[p].j, T.date[q].j))
				{
				case -1:p++;
						break;
				case 0:Qs += M.date[p++].e * T.date[q++].e;
						break;
				case 1:q++;
				}
			}

			if (Qs)
			{
				if (++Q.tu > MAX_SIZE)
				{
					return ERROR;
				}
				Q.date[Q.tu].i = i;
				Q.date[Q.tu].j = j;
				Q.date[Q.tu].e = Qs;
			}
		}
	}
	return OK;
}
