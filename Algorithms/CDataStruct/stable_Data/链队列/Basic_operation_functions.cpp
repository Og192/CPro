#include "Status.h"
#include "Struct_LinkQueue.h"//�����ṹ�嶨�弰��������

//�ṹ�����͵Ļ�������
void InitQueue(LinkQueue &Q)//����һ���յĶ���Q
{
	Q.rear = Q.front = (QueuePtr)malloc(sizeof(QNode));//��ͷ�Ͷ�βָ��ͷ���

	if (!Q.front)
	{
		exit(OVERFLOW);
	}

	Q.front->next = NULL;

	return;
}

void DestroyQueue(LinkQueue &Q)//���ٶ���
{
	while (Q.front)            
	{
		Q.rear = Q.front->next;
		free(Q.front);
		Q.front = Q.rear;
	}
	return;
}

void ClearQueue(LinkQueue &Q)//��ն���
{
	DestroyQueue(Q);
	InitQueue(Q);

	return;
}

Status IsQueueEmpty(LinkQueue &Q)//�ж϶����Ƿ�Ϊ��
{
	if (Q.front->next == NULL)
	{
		return TRUE;
	}
	else
	{
		return FALSE;
	}
}

int QueueLength(LinkQueue &Q)//���ض��г���
{
	int i = 0;
	QueuePtr p = Q.front->next;
	while (p)
	{
		i++;
		p = p->next;
	}
	return i;
}

Status GetHead(LinkQueue &Q, QElemType &e)//��e���ض�ͷԪ��
{
	if (Q.front == Q.rear)
	{
		return ERROR;
	}
	e = Q.front->next->data;
	return OK;
}

void EnQueue(LinkQueue &Q,QElemType e)//�ڶ�β����Ԫ��e
{
	Q.rear = Q.rear ->next = (QueuePtr)malloc(sizeof(QNode));
	if (!Q.rear)
	{
		exit (OVERFLOW);
	}
	Q.rear ->data = e;
	Q.rear ->next = NULL;

	return;
}

Status DelQueue(LinkQueue &Q, QElemType &e)//ɾ����ͷԪ��
{
	QueuePtr p;
	if (Q.front == Q.rear)
	{
		return ERROR;
	}

	p = Q.front->next;
	e = p->data;
	Q.front->next = p->next;

	if (p == Q.rear)//ɾ�����Ƕ�βԪ��
	{
		Q.rear = Q.front;
	}
	free(p);

	return OK;	
}

Status QueueTraverse(LinkQueue &Q, void(*visit)(QElemType))
{
	QueuePtr p = Q.front->next;

	if (Q.front == Q.rear)
	{
		return ERROR;
	}
	while (p)
	{
		visit(p->data);
		p = p->next;
	}

	printf("\n");

	return OK;
}