#define MAX_ARRAY_DIM 8//���ά��

typedef struct
{
	ElemType *base;//ָ��洢����Ŀռ�Ļ�ַ
	int dim;       //����ά��
	int * bounds;  //ָ��洢��ά�ȱ߽�Ŀռ�Ļ�ַ
	int * constants;//ָ��洢��ά������ӳ���������Ŀռ�Ļ�ַ
}Array;