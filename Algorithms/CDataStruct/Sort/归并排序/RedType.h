/*****************RedType.h*****************/
#ifndef RED_TYPE
#define RED_TYPE
#include <stdio.h>
typedef int KeyType;//����ؼ�������Ϊ����
typedef int infoType;//���嶨�����������������Ϊ����

typedef struct RedType
{//��¼������
	KeyType key;//�ؼ���
	infoType otherinfo;//����������

}RedType;

//��������ֵ�͹ؼ��ֵıȽ�Լ��Ϊ���µĺ궨�塣
#define EQ(a,b) ((a) == (b))
#define LT(a,b) ((a) < (b))
#define LQ(a,b) ((a) <= (b))

//������������
void InputFromFile(FILE *f,RedType &c);

#endif