#define MAX_SIZE  100//��Ԫ��Ԫ�ص����洢��

typedef struct
{
	int i,j;   //�洢�±꣨�к��У�
	ElemType e;//����Ԫ��
}Triple;

typedef struct
{
	Triple date[MAX_SIZE + 1];//����ϡ�����ľ�̬˳��洢�ռ�
	int mu,nu,tu;//������С��кͷ���Ԫ�ظ���
}TSMatrix;