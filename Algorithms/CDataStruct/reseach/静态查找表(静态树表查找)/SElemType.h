#ifndef SELEMTYPE_H
#define SELEMTYPE_H

#include "Status.h"
typedef char KeyType; //����ؼ�������Ϊ�ַ���

struct SElemType//��¼���������ͣ�����Ԫ�����ͣ�
{
	KeyType key;
	double weight;
};
//��������ֵ�͹ؼ��ֵıȽ�Լ��Ϊ���µĺ궨�塣
#define EQ(a,b) ((a) == (b))
#define LT(a,b) ((a) < (b))
#define LE(a,b) ((a) <= (b))

void visit(SElemType c);
void InputFromFile(FILE*f,SElemType &c);
void InputKey(KeyType &c);
#endif