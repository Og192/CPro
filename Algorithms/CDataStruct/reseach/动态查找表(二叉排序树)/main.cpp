#include "DSTable.h"
int main(void)
{
	BiTree dt,p;
	int i,n;
	KeyType j;
	DElemType r;
	Status k;
	FILE *f;
	f = fopen("1.txt","r");
	fscanf(f,"%d",&n);
	InitDSTable(dt);
	for (i = 0; i < n; ++i)
	{
		InputFromFile(f,r);
		k = InsertBST(dt,r);
		if (!k)
		{
			printf("������������dt�Ѵ��ڹؼ���Ϊ%d������,��(%d,%d)�޷����뵽dt�С�\n",r.key,r.key,r.others);
		}
	}
	fclose(f);
	printf("\n�����������������dt:\n");
	TraverseDSTable(dt,Visit);
	printf("\n�����������������dt:\n");
	PreOrderTraverse(dt,Visit);
	printf("\n����������ҵĹؼ��ֵ�ֵ:");
	InputKey(j);
	k = SearchBST(dt,j,NULL,p);
	if (k)
	{
		printf("dt�д��ڹؼ���Ϊ%d�Ľ�㡣",j);
		DeleteBST(dt,j);
		printf("ɾ���˽���,�����������������dt:\n");
		TraverseDSTable(dt,Visit);
		printf("\n�����������������\n");
		PreOrderTraverse(dt,Visit);
		printf("\n");
	}
	else
	{
		printf("dt�в����ڹؼ���Ϊ%d�Ľ��\n",j);
	}
	DestroyDSTable(dt);
	return 0;
}