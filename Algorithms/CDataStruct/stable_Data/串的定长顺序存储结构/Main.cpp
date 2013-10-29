#include "Status.h"
#include "def_SString.h"
#include "Basic_operation_functions.h"

int main(void)
{
	int i,j;
	Status k;
	char s,c[MAX_STR_LEN];
	SString t,s1,s2;

	printf("�����봮s1:");
	gets(c);
	StrAssign(s1,c);
	printf("����Ϊ%d,���Ƿ�Ϊ�գ�%d��1:�� 0����\n",StrLength(s1),StrEmpty(s1));

	StrCopy(s2,s1);
	printf("����s1���ɵĴ�Ϊ��");
	StrPrint(s1);
	printf("�����봮s2��");
	gets(c);
	StrAssign(s2,c);

	i = StrCompare(s1,s2);
	if (i<0)
	{
		s = '<';
	}
	else if (0 == i)
	{
		s = '=';
	}
	else
	{
		s = '>';
	}
	printf("��s1%c��s2\n",s);

	k = Concat(t,s1,s2);
	printf("��s1���Ӵ�s2�õ��Ĵ�tΪ��");
	StrPrint(t);
	if (k == FALSE)
	{
		printf("��t�нض�\n");
	}
	ClearString(s1);
	printf("��մ�s1�󣬴���s1Ϊ:");
	StrPrint(s1);
	printf("����Ϊ%d,���Ƿ�Ϊ�գ�%d��1:�� 0����\n",StrLength(s1),StrEmpty(s1));
    
	printf("��t���Ӵ����������Ӵ�����ʼλ�ú��Ӵ����ȣ�");
	scanf("%d,%d",&i,&j);
		k = SubString(s2,t,i,j);
	if (k)
	{
		printf("�Ӵ�s2Ϊ��");
		StrPrint(s2);
	}
	printf("�Ӵ�t�ĵ�pos���ַ���ɾ��len���ַ���������pos��len��");
	scanf("%d,%d",&i,&j);
	StrDelete(t,i,j);
	printf("ɾ�����tΪ��");
	StrPrint(t);

	i = StrLength(s2)/2;
	StrInsert(s2,i,t);
	printf("�ڴ�s2�ĵ�%d���ַ�֮ǰ���봮t�󣬴�s2Ϊ��",i);
	StrPrint(s2);

	i = Index(s2,t,1);
	printf("s2�ĵ�%d�ַ����t�ĵ�һ��ƥ��\n",i);
	i = Index1(s2,t,1);
	printf("s2�ĵ�%d�ַ����t�ĵ�һ��ƥ��\n",i);

}
/*
------------------------------------------
�����봮s1:ABCD
����Ϊ4,���Ƿ�Ϊ�գ�0��1:�� 0����
����s1���ɵĴ�Ϊ��ABCD
�����봮s2��123456
��s1<��s2
��s1���Ӵ�s2�õ��Ĵ�tΪ��ABCD123456
��մ�s1�󣬴���s1Ϊ:
����Ϊ0,���Ƿ�Ϊ�գ�1��1:�� 0����
��t���Ӵ����������Ӵ�����ʼλ�ú��Ӵ����ȣ�3,7
�Ӵ�s2Ϊ��CD12345
�Ӵ�t�ĵ�pos���ַ���ɾ��len���ַ���������pos��len��4,4
ɾ�����tΪ��ABC456
�ڴ�s2�ĵ�3���ַ�֮ǰ���봮t�󣬴�s2Ϊ��CDABC45612345
s2�ĵ�3�ַ����t�ĵ�һ��ƥ��
�밴���������. . .
------------------------------------------
*/