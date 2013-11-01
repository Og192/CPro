#include "Status.h"
#include "HString.h"
#include "Basic_operation_functions.h"
#include "Line_List.h"
int main()
{
	int i,num;
	char ch,str[100];
	HString s,t,r;
	LineList l;

	InitString(s);
	InitList(l,&s);
	InitString(t);
	InitString(r);

	printf("�������ı���s����ctrl + Z������\n");
	for(i = 0; (ch = getchar()) != EOF; i++)
	{
		str[i] = ch;
	}
	str[i] = '\0';
	StrAssign(s,str);
	printf("�ı���s���£�\n");
	StrPrint(s);
	UpdateList(l);
	printf("�ı���s���б����£�\n\n");
	ListPrint(l);

	printf("\n�����뽫Ҫ���뵽�ı���s�е��ı�t\n");
	for(i = 0; (ch = getchar()) != EOF; i++)
	{
		str[i] = ch;
	}
	str[i] = '\0';
	StrAssign(t,str);
	printf("��Ҫ���뵽�ı���s�е��ı�t���£�\n");
	StrPrint(t);
	printf("������s��t�Ĳ���λ�ã�t���ڸ�λ��ǰ��:");
	scanf("%d",&num);
	ListInsert(l,num,t);
	printf("\n����t���sΪ\n");
	StrPrint(s);
	printf("����t���ı���s���б����£�\n\n");
	ListPrint(l);

	printf("\n������s��Ҫɾ���е��к�:");
	scanf("%d",&num);
	ListDelete(l,num);
	printf("\nɾ��%d���sΪ\n",num);
	StrPrint(s);
	printf("��ʱ�ı���s���б����£�\n\n");
	ListPrint(l);

	
	ClearList(l);
	printf("���l��,�б�l�ļ�¼��Ϊ%d,�Ƿ�Ϊ�գ�%d��1���� 0����\n\n",ListLength(l),ListEmpty(l));
	DestroyList(l);

	return 0;
}
/*
------------------------------------------
�������ı���s����ctrl + Z������
int main()
{
  abcdefg;
  return 0;
}
^Z
�ı���s���£�
int main()
{
  abcdefg;
  return 0;
}

�ı���s���б����£�

 �к�  ��ʼ��ַ  ����
 100     201      11
 101     212      2
 102     214      11
 103     225      12
 104     237      2

�����뽫Ҫ���뵽�ı���s�е��ı�t
  printf("Hello World!");
^Z
��Ҫ���뵽�ı���s�е��ı�t���£�
  printf("Hello World!");

������s��t�Ĳ���λ�ã�t���ڸ�λ��ǰ��:102

����t���sΪ
int main()
{
  printf("Hello World!");
  abcdefg;
  return 0;
}

����t���ı���s���б����£�

 �к�  ��ʼ��ַ  ����
 100     201      11
 101     212      2
 102     214      26
 103     240      11
 104     251      12
 105     263      2

������s��Ҫɾ���е��к�:103

ɾ��103���sΪ
int main()
{
  printf("Hello World!");
  return 0;
}

��ʱ�ı���s���б����£�

 �к�  ��ʼ��ַ  ����
 100     201      11
 101     212      2
 102     214      26
 103     240      12
 104     252      2
���l��,�б�l�ļ�¼��Ϊ0,�Ƿ�Ϊ�գ�1��1���� 0����

�밴���������. . .
------------------------------------------
*/