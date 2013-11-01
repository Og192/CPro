#include "SSTable.h"
#include <math.h>
void Creat_SeqFromFile(SSTable &ST,char *filename)//�������ļ����쾲̬˳����ұ�
{//����˳���
	int i;
	FILE *f;
	f = fopen(filename,"r");//���ļ�
	fscanf(f,"%d",&ST.length);//���ļ��������ĳ���
	ST.elem = (SElemType*)malloc((ST.length + 1) * sizeof(SElemType));//��̬���䳤��ΪST.length + 1�ļ�¼�洢�ռ䣬0�ŵ�Ԫ����
	if (!ST.elem)
	{//����ʧ��
		exit(OVERFLOW);
	}
	for (i = 1; i <= ST.length; ++i)
	{//���ļ��������м�¼
		InputFromFile(f,ST.elem[i]);
	}
	fclose(f);//�ر��ļ�
}

void Ascend(SSTable &ST)
{//���ؼ����������б��еļ�¼���˴���ѡ��������ɣ�
	int i,j,k;//k�浱ǰ�ؼ�����Сֵ�����
	for (i = 1; i < ST.length; ++i)
	{
		k = i;
		for (j = i + 1; j <= ST.length; ++j)
		{
			if (LT(ST.elem[j].key,ST.elem[k].key))
			{//�б�[k]��С��ֵ����Ÿ���k
				k = j;
			}
		}
		if (k != i)
		{//�б�[i]��С��ֵ�򽻻� �˴�0�ŵ�Ԫ���ڸ�������
			ST.elem[0] = ST.elem[i];
			ST.elem[i] = ST.elem[k];
			ST.elem[k] = ST.elem[0];
		}
	}
}

void Creat_OrderFromFile(SSTable & ST,char *filename)
{//�������������
	Creat_SeqFromFile(ST,filename);
	Ascend(ST);
}

Status Destroy(SSTable &ST)
{//���پ�̬���ұ�
	free(ST.elem);
	ST.elem = NULL;
	ST.length = 0;
	return OK;
}

int Search_Seq(SSTable ST,KeyType key)
{//��˳���ST��˳�������ؼ��ʵ���key�ļ�¼
	int i;
	ST.elem[0].key = key;//0�õ�Ԫ��Źؼ��֣��������ڱ���
	for (i = ST.length; !EQ(ST.elem[i].key,ST.elem[0].key); --i)
	{//�Ӻ���ǰ��
		;
	}
	return i;
}

int Search_Bin(SSTable ST,KeyType key)
{//�������ST���۰������ؼ��ʵ���key�ļ�¼
	int mid, low = 1, high = ST.length;//�������ֵ����ֵΪ1����ֵΪlength
	while (low <= high)
	{
		mid = (low + high) / 2;
		if (EQ(key,ST.elem[mid].key))
		{//��ֵΪkey,�򷵻���ֵ
			return mid;
		}
		else if (LT(key,ST.elem[mid].key))
		{//keyС��[mid],��key��[low,mid)������,��ֵ����Ϊmid - 1
			high = mid - 1;
		}
		else
		{//key����[mid],��key��(mid,high]������,��ֵ����Ϊmid + 1
			low = mid + 1;
		}
	}
	return 0;
}

void Traverse(SSTable ST)
{
	int i;
	if (ST.length > 0)
	{
		for (i = 1; i <= ST.length; ++i)
		{
			visit(ST.elem[i]);
		}
	}
}

void FindSW(double sw[],SSTable ST)
{//���������ST�м�¼��Ȩֵ���ۼ�Ȩֵ����sw,CreateSOSTree()����
	int i;
	sw[0] = 0;//��Ϊ0
	printf("\nsw = 0");
	for (i = 1; i <= ST.length; ++i)
	{//������С�����ۼ�Ȩֵ
		sw[i] = sw[i - 1] + ST.elem[i].weight;
		printf("%-6.2f",sw[i]);
	}
	printf("\n");
}

Status SecondOptimal(BiTree &T,SElemType R[],double sw[],int low,int high)
{
	int j,i = low;//i�ǡ�PiΪ��Сֵʱ����ţ���ֵ��Ϊ��low == high (������һ��Ԫ��)ʱ��ֵ
	double dw = sw[high] + sw[low - 1];//��Pi = |sw[high] + sw[low - 1] - sw[j] - sw[j -1]|,����j = iʱ��Piȡ����Сֵ,��i��ֵ��
	double min = fabs(sw[high] - sw[low]);//��Pi����Сֵ,��ֵ��Ϊ��low == high ʱ��ֵ
	for (j = low + 1; j <= high; ++j)
	{
		if (fabs(dw - sw[j] - sw[j - 1]) < min)
		{
			min = fabs(dw - sw[j] - sw[j - 1]);//������Сֵ
			i = j;//������Сֵ���
		}
	}
	if (!(T = (BiTree)malloc(sizeof(BiTNode))))
	{//���ɽ��ʧ��
		exit (OVERFLOW);
	}
	T ->date = R[i];//������С��Piֵ�ļ�¼Ԫ�ظ�������������
	if (i == low)//����С��Piֵ���������С���
	{
		T->lchild = NULL;//����������
	}
	else
	{
		SecondOptimal(T->lchild,R,sw,low,i - 1);//�ݹ鹹����Ų���������
	}
	if (i == high)//����С��Piֵ�������������
	{
		T->rchild = NULL;//����������
	}
	else
	{
		SecondOptimal(T->rchild,R,sw,i + 1,high);//�ݹ鹹����Ų���������
	}
}

void CreateSOSTree(SOSTree &T,SSTable ST)
{//�������ST����һ�ô��Ų�����T
	double sw[N + 1];
	if (ST.length == 0)
	{
		T = NULL;
	}
	else
	{
		FindSW(sw,ST);
		SecondOptimal(T,ST.elem,sw,1,ST.length);
	}
}

Status Search_SOSTree(SOSTree &T,KeyType key)
{//�ڴ��Ų�����T�в������ؼ��ֵ���key��Ԫ��,�ҵ��򷵻�OK,Tָ���Ԫ��;���򷵻�FALSE
	while (T)
	{
		if (EQ(key,T->date.key))
		{
			return OK;
		}
		else if (LT(key,T->date.key))
		{
			T = T->lchild;
		}
		else
		{
			T = T->rchild;
		}
	}
	return FALSE;
}

