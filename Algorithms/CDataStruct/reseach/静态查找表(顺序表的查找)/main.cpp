#include "SSTable.h"

int main(void)
{
	SSTable st;
	int i;
	long s;
	char filename[13];
	printf("�����������ļ���: ");
	scanf("%s",filename);
	Creat_SeqFromFile(st,filename);
//	Creat_OrderFromFile(st,filename);
	for (i = 1; i <= st.length; i++)
	{//�����ܳɼ�
		st.elem[i].total = st.elem[i].politics + st.elem[i].Chinese + st.elem[i].English + st.elem[i].math
			+ st.elem[i].physics + st.elem[i].chemisty + st.elem[i].biology;
	}
	printf("׼��֤��  ����     ����  ����  ����  ��ѧ  ����  ��ѧ  ����   �ܷ�\n");
	Traverse(st);//�����¼��
	printf("������������˵Ŀ���:");
	InputKey(s);
	i = Search_Seq(st,s);//������ؼ�����ͬ�ļ�¼
//	i = Search_Bin(st,s);
	if (i)
	{
		visit(st.elem[i]);
	}
	else
	{
		printf("δ�ҵ�!\n");
	}
	Destroy(st);//���پ�̬���ұ�

	return 0;
}