#include "Status.h"
#include "def_SString.h"
#include "Basic_operation_functions.h"
#include "KMP.h"

int main(void)
{
	int i,*p;
	SString s1,s2;
	StrAssign(s1,"acabaabcacaabc");
	printf("����Ϊ:");
	StrPrint(s1);
	StrAssign(s2,"abaabcac");
	printf("�Ӵ�Ϊ:");
	StrPrint(s2);
	p = (int *)malloc((StrLength(s2) + 1)*sizeof(int));
	get_next(s2,p);
	printf("�Ӵ���next����Ϊ��");
	for(i = 1; i <= StrLength(s2); i++)
	{
		printf("%d  ",p[i]);
	}
	printf("\n");
	i = Index_KMP(s1,s2,1,p);
	if(i)
	{
		printf("�������Ӵ��ڵ�%d���ַ����״�ƥ��\n",i);
	}
	else
	{
		printf("�������Ӵ�ƥ�䲻�ɹ�\n");
	}
	get_nextval(s2,p);
	printf("�޸��㷨���Ӵ���next����Ϊ��");
	for(i = 1; i <= StrLength(s2); i++)
	{
		printf("%d  ",p[i]);
	}
	printf("\n");
	i = Index_KMP(s1,s2,1,p);
	if(i)
	{
		printf("�������Ӵ��ڵ�%d���ַ����״�ƥ��\n",i);
	}
	else
	{
		printf("�������Ӵ�ƥ�䲻�ɹ�\n");
	}

}