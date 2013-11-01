#ifndef LINKQUE_H
#define LINKQUE_H
typedef int QElemType;
//#include"QElemType.h"
//����ṹ��(����)
typedef struct QNode
{
	QElemType data;
	QNode *next;
}*QueuePtr;

struct LinkQueue
{
	QueuePtr front;
	QueuePtr rear;
};
//��������(һ�����)
void InitQueue(LinkQueue &);
void DestroyQueue(LinkQueue &);//���ٶ���
void ClearQueue(LinkQueue &);//��ն���
Status IsQueueEmpty(LinkQueue &);//�ж϶����Ƿ�Ϊ��
int QueueLength(LinkQueue &);//���ض��г���
Status GetHead(LinkQueue &, QElemType &);//��e���ض�ͷԪ��
void EnQueue(LinkQueue &,QElemType );//�ڶ�β����Ԫ��e
Status DelQueue(LinkQueue &, QElemType &);//ɾ����ͷԪ��
Status QueueTraverse(LinkQueue &, void(*visit)(QElemType));

#endif