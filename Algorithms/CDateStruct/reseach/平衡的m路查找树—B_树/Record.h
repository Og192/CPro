#ifndef RECORD_H
#define RECORD_H
typedef int KeyType;//����ؼ�������Ϊint��

typedef struct Others
{//��¼����������
	int order;
}Others;

typedef struct Record
{//��¼����
	KeyType key;//�ؼ���
	Others others;//��������
} Record;

//��������ֵ�͹ؼ��ֵıȽ�Լ��Ϊ���µĺ궨�塣
#define EQ(a,b) ((a) == (b))
#define LT(a,b) ((a) < (b))
#define LE(a,b) ((a) <= (b))

#endif