int main()
{
	TSMatrix A,B,C;
	printf("����ϡ�����A:");
	CreateSMatrix(A);
	PrintSMatrix(A);
	
	printf("�ɾ���A���ƾ���B:\n");
	CopySMatrix(A,B);
	PrintSMatrix(B);

	printf("���پ���B��\n");
	DestroySMatrix(B);
	PrintSMatrix(B);

	printf("��������B2:(�����A���С�������ͬ���С��зֱ�Ϊ3,3)\n");
	CreateSMatrix(B);
	PrintSMatrix(B);

	printf("����C1(A + B):\n");
	AddSMatrix(A,B,C);
	PrintSMatrix(C);

	printf("����C2(A - B):\n");
	SubtSMatrix(A,B,C);
	PrintSMatrix(C);

	printf("����C3(A��ת�þ���):\n");
	TransposeSMatrix(A,C);
	PrintSMatrix(C);

	printf("����ϡ�����A2:");
	CreateSMatrix(A);
	PrintSMatrix(A);
	printf("����ϡ�����B3(�����;���A2��������ͬ = 3):");
	CreateSMatrix(B);
	PrintSMatrix(B);

	printf("����C5(A * B):\n");
#ifndef FLAG
	MultSMatrix(A,B,C);
#else
	MultSMatrix1(A,B,C);
#endif
	PrintSMatrix(C);
	return 0;
}