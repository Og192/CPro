#include "SLL_RadixSort.h"
#include <string.h>

void Print2(SLList L)
{//��������������̬����
	int i = 0;
	printf("keynum = %d recnum = %d i = %d next = %d\n",L.keynum,L.recnum,i,L.r[i].next);
	for(i = 1; i <= L.recnum;i ++)
	{
		printf("i = %d keys = %s otheritems = %d next = %d \n",i,L.r[i].keys,L.r[i].otheritems,L.r[i].next);
	}
}

void PrintLL(SLList L)
{//������˳�������̬����L
	int i = L.r[0].next;
	while (i)
	{
		printf("%s ",L.r[i].keys);
		i = L.r[i].next;
	}
}

void Sort(SqList L,int adr[])
{//���adr[1..L.length],adr[i]Ϊ��̬����L�ĵ�i����С��¼�����
	int i = 1, p = L.r[0].next;//pָ���һ����¼
	while (p)
	{//δ����β
		adr[i++] = p;//��p��ֵ��adr[i],i+1
		p = L.r[p].next;//pָ����һ����¼
	}
}

void Rearrange(SqList &L,int adr[])
{//adr����������̬����L��������򣬼�L.r[adr[i]]�ǵ�iС��¼
	int i,j,k;
	for (i = 1; i <= L.length; ++i)
	{
		if (adr[i] != i)
		{
			j = i;
			L.r[0] = L.r[i];//�ݴ��¼[i]��[0](�ճ�[i]��[j]��)
			while (adr[j]!=i)//��¼������ȷ��λ��
			{//����L.r[adr[j]]�ļ�¼��λ��֪��adr[j] = iΪֹ;
				k = adr[j];
				L.r[j] = L.r[k];//��[j]��Ӧ�ŵļ�¼��������[j]�գ�
				adr[j] = j;//��¼������ȷλ�õı�־
				j = k;//�¿ճ���λ�ø�ֵ��j���Ա����ѭ��ʹ��
			}
			L.r[j] = L.r[0];//ѭ��������ϣ����ݴ���[0]�еļ�¼��ֵ��L.r[j]
			adr[j] = j;
		}
	}
}

void MadeListFromFile(SqList &L,FILE *f)
{//ͨ���ļ�f����˳���L
	int i;
	fscanf(f,"%d",&L.recnum);//���������ļ������ΪL.recnum
	for (i = 1; i <= L.recnum; ++i)
	{//�����������ֵ����next��
		fscanf(f,"%s%d",&L.r[i].keys,&L.r[i].otheritems);
	}
	L.keynum = strlen(L.r[1].keys);//�ؼ��ֳ���
}

int ord(char c)
{//���عؼ���c�����
	return c - '0';
}

void Distribute(SLCell r[],int i,ArrType f,ArrType e)
{//��̬����L��r���м�¼�Ѱ�(keys[i-1],..,key[0])���򣬱��㷨����i���ؼ���key[i](keys[0]�����λ�ؼ���)����RADIX���ӱ�
//ʹͬһ���ӱ��м�¼��key[i]��ͬ��f[0..RADIX - 1]��e[0..RADIX-1]�ֱ�ָ����ӱ��е�һ�������һ����¼
	int j,p;
	for (j = 0; j < RADIX; ++j)
	{//���ӱ��ʼ��Ϊ�ձ�
		f[j] = 0;
	}
	for (p = r[0].next;p;p = r[p].next)
	{//p����ʽ�ṹ����ָ��̬����ļ�¼
		j = ord(r[p].keys[i]);//��ǰ��¼�ĵ�iλ�ؼ��ֵ���ţ����½���ǰ��¼����Ų����ӱ�
		if (!f[j])
		{//�ӱ�f[j]��
			f[j] = p;//��ͷָ��ǰ��¼
		}
		else
		{//�ӱ���
			r[e[j]].next = p;//�޸�ԭ�ӱ�[j]�ı�β��¼��next��ָ��ǰ��¼
		}
		e[j] = p;//���ñ�βָ��ָ��p��ָ�ı�β��¼
	}

	//���������ͷָ��f[]�ͱ�βָ��e[]����ɾ��
	printf("\nf[j] = ");
	for (j = 0; j < RADIX; ++j)
	{
		printf("%3d",f[j]);
	}
	printf("\ne[j] = ");
	for (j = 0; j < RADIX; ++j)
	{
		if (f[j])
		{
			printf("%3d",e[j]);
		}
		else
		{
			printf("%3d",0);
		}
	}
	printf("\n");
}

int succ(int i)
{//���̺���
	return ++i;
}

void Collect(SLCell r[],ArrType f,ArrType e)
{//���㷨��keys[i]��С����ؽ�f[0..RADIX-1]��ָ���ӱ��������ӳ�һ������e[0..RADIX-1]Ϊ���ӱ��βָ��
	int j,t;
	for (j = 0;!f[j]; j = succ(j));
	//�ҵ���1���ǿ��ӱ�[j],succΪ���̺���
	r[0].next = f[j];//r[0]ָ���һ���ǿ��ӱ�[j]�ĵ�һ��Ԫ��
	t = e[j];//tָ���1���ǿ��ӱ�[j]�ı�βԪ��
	while (j < RADIX - 1)
	{//δ�����һλ�ؼ���
		for (j = succ(j); j < RADIX - 1 && !f[j]; j = succ(j));//����һ���ǿ��ӱ�
		if (f[j])//�ӱ���
		{
			r[t].next = f[j];//���������ǿ��ӱ�
			t = e[j];//tָ���µı�βԪ��
		}
	}
	r[t].next = 0;//��β
}

void RadixSort(SLList &L)
{//L�ǲ��þ�̬�����ʾ��˳�����L����������ʹL��Ϊ���ؼ�����С���������̬����,L,r[0]Ϊͷ���
	int i,j = 1;
	ArrType f,e;//��ͷ��βָ��
	for (i = 0; i < L.recnum; ++i)
	{//��L����Ϊ��̬����
		L.r[i].next = i + 1;
	}
	L.r[L.recnum].next = 0;
	for  (i = L.keynum - 1;i >= 0; --i,++j)//�����λ���ȣ�LSD�����ζԸ��ؼ��ֽ��з�����ռ����޸�
	{
		Distribute(L.r,i,f,e);//��i�˷���
		printf("��%d�˷����\n",j);
		Print2(L); 
		Collect(L.r,f,e);
		printf("��%d���ռ���\n",j);
		Print2(L); 
		PrintLL(L); 
	}
}