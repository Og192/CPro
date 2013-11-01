#include "Status.h"
#include "Struct_LinkQueue.h"
#include "Basic_called_functions.h"

int main()
{
	Status i;
	LinkQueue Q;
	QElemType e,e0;

	InitQueue(Q);
	printf("�ɹ��Ĺ����˿ն��У�\n");
	printf("�Ƿ�ն��У�%d(1:�� 0����)\n",IsQueueEmpty(Q));
	printf("���еĳ���Ϊ%d\n",QueueLength(Q));
	EnQueue(Q,-5);
	EnQueue(Q,5);
	EnQueue(Q,10);
	printf("��������Ԫ�أ�-5,5,10���󣬶��еĳ���Ϊ%d\n",QueueLength(Q));
	printf("�Ƿ�ն��У�%d(1:�� 0����)\n",IsQueueEmpty(Q));
    printf("���е�Ԫ������Ϊ��");
	QueueTraverse(Q,print);

	i = GetHead(Q,e);
	if (i == OK)
	{
		printf("��ͷԪ����%d\n",e);
	}

	DelQueue(Q,e);
	printf("ɾ���˶�ͷԪ��%d\n",e);

	i = GetHead(Q,e);
	if (i == OK)
	{
		printf("�µĶ�ͷԪ����%d\n",e);
	}

	ClearQueue(Q);
	printf("��ն��к�Q.front=%u,Q.rear=%u,Q.front->next=%u\n",Q.front,Q.rear,Q.front->next);
	printf("�Ƿ�ն��У�%d(1:�� 0����)\n",IsQueueEmpty(Q));

	DestroyQueue(Q);
	printf("���ٶ��к�Q.front=%u,Q.rear=%u\n",Q.front,Q.rear);

	return 0;
}

/*��VC++6.0�е�������Ϊ��
------------------------------------------------------------------------------------
�ɹ��Ĺ����˿ն��У�
�Ƿ�ն��У�1(1:�� 0����)
���еĳ���Ϊ0
��������Ԫ�أ�-5,5,10���󣬶��еĳ���Ϊ3
�Ƿ�ն��У�0(1:�� 0����)
���е�Ԫ������Ϊ��-5  5  10
��ͷԪ����-5
ɾ���˶�ͷԪ��-5
�µĶ�ͷԪ����5
��ն��к�Q.front=4986016,Q.rear=4986016,Q.front->next=0
�Ƿ�ն��У�1(1:�� 0����)
���ٶ��к�Q.front=0,Q.rear=0
�밴���������. . .
------------------------------------------------------------------------------------
�ҵĳ���Ա֮·��·��������Զ�⣬�Ὣ���¶�������
*/
