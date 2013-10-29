#include "Status.h"
#include "HString.h"
#include "Basic_operation_functions.h"
#include "Line_List.h"
int main()
{
	int i;
	char c,*p = "God bye!",*q = "God luck!";
	char ps[100];
	HString s,t,r;
	InitString(s);
	InitString(t);
	InitString(r);
	StrAssign(s,p);
	printf("��sΪ��");
	StrPrint(s);
	printf("����Ϊ%d,���շ�%d(1:�� 0����)\n",StrLength(s),StrEmpty(s));
	StrAssign(t,q);
	printf("��tΪ��");
	StrPrint(t);
    
	i = StrCompare(s,t);
	if (i < 0)
	{
		c = '<';
	}
	else if (0 == i)
	{
		c = '=';
	}
	else
	{
		c = '>';
	}
	printf("��s%c��t\n",c);

	Concat(r,s,t);
	printf("���Ӵ�s�ʹ�t�ô�rΪ");
	StrPrint(r);

	StrAssign(t,"oo");
	printf("��tΪ��");
	StrPrint(t);
	StrAssign(s,"o");
	printf("��sΪ��");
	StrPrint(s);
	Replace(r,s,t);
	printf("�Ѵ�r�����кʹ�s��ͬ�Ĵ��ô�t�滻�󣬴�rΪ");
	StrPrint(r);

	ClearString(t);
	printf("��մ�t��,����Ϊ%d,���շ�%d(1:�� 0����)\n",StrLength(t),StrEmpty(t));
	SubString(t,r,6,4);
	printf("��tΪ�Ӵ�r�ĵ�6���ַ����4���ַ�������Ϊ%d,��tΪ",StrLength(t));
	StrPrint(t);

	StrCopy(s,r);
	printf("��r���Ƶ�s�У���sΪ");
	StrPrint(s);

	StrInsert(s,6,t);
	printf("�ڴ�s�ĵ�6���ַ�ǰ����t�󣬴�sΪ");
	StrPrint(s);

	StrDelete(s,1,5);
	printf("�Ӵ�s�ĵ�1���ַ���ɾ��5���ַ��󣬴�sΪ");
	StrPrint(s);

	printf("%d�Ǵ�s�ĵ�1���ַ��𣬺ʹ�t��ͬ�ĵ�һ���Ӵ�λ��\n",Index1(s,t,1));
	printf("%d�Ǵ�s�ĵ�2���ַ��𣬺ʹ�t��ͬ�ĵ�һ���Ӵ�λ��\n",Index1(s,t,2));

	return 0;
}
/*
------------------------------------------
��sΪ��God bye!
����Ϊ8,���շ�0(1:�� 0����)
��tΪ��God luck!
��s<��t
���Ӵ�s�ʹ�t�ô�rΪGod bye!God luck!
��tΪ��oo
��sΪ��o
�Ѵ�r�����кʹ�s��ͬ�Ĵ��ô�t�滻�󣬴�rΪGood bye!Good luck!
��մ�t��,����Ϊ0,���շ�1(1:�� 0����)
��tΪ�Ӵ�r�ĵ�6���ַ����4���ַ�������Ϊ4,��tΪbye!
��r���Ƶ�s�У���sΪGood bye!Good luck!
�ڴ�s�ĵ�6���ַ�ǰ����t�󣬴�sΪGood bye!bye!Good luck!
�Ӵ�s�ĵ�1���ַ���ɾ��5���ַ��󣬴�sΪbye!bye!Good luck!
�Ǵ�s�ĵ�1���ַ��𣬺ʹ�t��ͬ�ĵ�һ���Ӵ�λ��
�Ǵ�s�ĵ�2���ַ��𣬺ʹ�t��ͬ�ĵ�һ���Ӵ�λ��
�밴���������. . .
------------------------------------------
*/