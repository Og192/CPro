#include "GList.h"
 
void print(AtomType c)
 { 
   printf("%c ",c);
 }

int main(void)
{
    char p[80];
	SString t;
	GList n,m;
	InitGList(n);
	printf("�չ����n�����=%d,n�Ƿ�գ�%d(1���� 0����)\n",GListDepth(n),GListEmpty(n));
	printf("����������n(��д��ʽ���ձ�(),��ԭ�ӣ�(a),������(a,(b),c)):\n");
	gets(p);
	StrAssign(t,p);
	CreateGList(n,t);//((),(e),(a,(b,c,d)))
	printf("�����n�ĳ���=%d",GListLength(n));
	printf(" ���=%d,n�Ƿ�գ�%d(1���� 0����)\n",GListDepth(n),GListEmpty(n));
	printf("���������n��");
	Traverse_GL(n,print);
	CopyGList(m,n);
	printf("\n���ƹ����m=n,  m�ĳ���=%d",GListLength(m));
	printf("  m�����=%d\n���������m:",GListDepth(m));
	Traverse_GL(m,print);
	DestroyGList(m);
	m = GetHead(n);
	printf("\nm��n�ı�ͷԪ�أ�����m:");
	Traverse_GL(m,print);
	DestroyGList(m);
	m = GetTail(n);
	printf("\nm����n�ı�β�γɵĹ��������m:");
	Traverse_GL(m,print);
	InsertFirst_GL(m,n);
	printf("\n��������ΪnΪm�ı�ͷ,���������m:");
	Traverse_GL(m,print);
	DeleteFirst_GL(m,n);
	printf("\nɾ��m�ı�ͷ,����nָ��m,���������m:");
	Traverse_GL(m,print);
	printf("\n���������n(�����m��ԭ��ͷ)��");
	Traverse_GL(n,print);
	printf("\n");
	DestroyGList(m);
	DestroyGList(n);
	return 0;
}