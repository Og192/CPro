#define MAX_SYM_DEGREE 10//�Գƾ����������

typedef struct
{
	ElemType *base;//�洢�Գƾ����һά�����ַ
	int degree;    //�Գƾ������
	int comspace;//ѹ���ռ��С
}SyMatrix;