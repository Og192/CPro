#ifndef SELEMTYPE_H
#define SELEMTYPE_H

#include "Status.h"
typedef long KeyType; //����ؼ�������Ϊ������
#define key number//׼��֤Ϊ�ؼ���
struct SElemType//��¼���������ͣ�����Ԫ�����ͣ�
{
	long number;//׼��֤��
	char name[9];//����
	int politics;//���γɼ�
	int Chinese;//���ĳɼ�
	int English;//Ӣ��ɼ�
	int math;//��ѧ�ɼ�
	int physics;//����ɼ�
	int chemisty;//��ѧ�ɼ�
	int biology;//����ɼ�
	int total;//�ܷ�
};
//��������ֵ�͹ؼ��ֵıȽ�Լ��Ϊ���µĺ궨�塣
#define EQ(a,b) ((a) == (b))
#define LT(a,b) ((a) < (b))
#define LE(a,b) ((a) <= (b))

void visit(SElemType c);
void InputFromFile(FILE*f,SElemType &c);
void InputKey(KeyType &c);
#endif