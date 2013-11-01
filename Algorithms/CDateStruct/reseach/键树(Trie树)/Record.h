#ifndef RECORD_H
#define RECORD_H

#include "Status.h"
#define MAX_KEY_LEN 16
typedef struct KeyType
{//����ؼ�������
	char ch[MAX_KEY_LEN];//�ؼ��ִ�
	int num;//�ؼ��ִ�����
}KeyType;

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
#define EQ(a,b) (!strcmp(a,b))
#define LT(a,b) (strcmp(a,b) > 0)
#define LE(a,b) (strcmp(a,b) >= 0)

#endif