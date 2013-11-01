#include "TrieTree.h"
#define N 20//�����
int main(void)
{
	TrieTree t;
	int i,j=0; 
	KeyType k;
	Record *p,r[N]; 
	FILE *f; 
	InitDSTable(t); 
	f=fopen("1.txt","r"); 
	do 
	{ i=fscanf(f,"%s%d",&r[j].key.ch,&r[j].others.order); 
	if(i!=-1) 
	{ r[j].key.num=strlen(r[j].key.ch); 
	p=SearchTrie(t,r[j].key); 
	if(!p) 
		InsertTrie(t,&r[j++]);

	else 
		printf("��t���Ѵ��ڹؼ���Ϊ%s�ļ�¼����(%s,%d)�޷����롣\n",
		r[j].key.ch,r[j].key.ch,r[j].others.order);
	}
	}while(!feof(f)&&j<N); 
	fclose(f); 
	printf("���ؼ��ַ�����˳�������t��\n");
	TraverseDSTable(t,Visit); 
	printf("\n����������Ҽ�¼�Ĺؼ��ַ�����");
	InputKey(k.ch); 
	k.num=strlen(k.ch); 
	p=SearchTrie(t,k); 
	if(p) 
		Visit(p); 
	else 
		printf("δ�ҵ�"); 
	printf("\n");
	DestroyDSTable(t); 
	return 0;
}