#include "SSTable.h"

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
			if (LT(ST.elem[j].number,ST.elem[k].number))
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