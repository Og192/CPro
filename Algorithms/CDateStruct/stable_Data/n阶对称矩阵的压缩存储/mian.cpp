#include "Status.h"
typedef int ElemType; 
#include "struct SyMatrix.h"
#include "Basic_operation_functions.h"

int main()
{
	int i,j,e,e1,degree = 4;
	SyMatrix M;


	InitMatrix(M,degree);
	printf("M.degree =%d  M.comspace = %d\n\n",M.degree,M.comspace);

	printf("�������ǵĸ�ֵ�������Խ��ߣ����£�\n");
	for (i = 1; i <= degree; i++)
	{
		for (j = 1; j <= i; j++)
		{
			Assign(M,i*10 + j,i,j);
			Value(M,e,i,j);
			printf("%d ",e);
		}
		printf("\n");
	}
	printf("\n�õ��ĶԳƾ������£�\n");
	SymPrint(M);

	Assign(M,90,3,2);
	Assign(M,80,4,3);
	printf("��M[3][2]��ֵ��Ϊ90,M[4][3]��ֵ��Ϊ80�󣬾������£�\n");
	SymPrint(M);

	Value(M,e,2,1);
	Value(M,e1,2,4);
	printf("��M[2][1]��ֵ����eΪ%d,M[2][4]��ֵ����e1Ϊ%d\n",e,e1);

	return 0;
}