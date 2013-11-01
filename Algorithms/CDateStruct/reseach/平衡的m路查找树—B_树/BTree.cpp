#include "BTree.h"

void Visit(BTNode c,int i)
{//���ʽ���ϵ�i���ؼ��ֵļ�¼
	printf("(%d,%d)",c.recptr[i]->key,c.recptr[i]->others);
}

void InputKey(KeyType &k)
{//����ؼ���
	scanf("%d",&k);
}

void InitDSTable(BTree &DT)
{//����һ���յ�B_��DT
	DT = NULL;
}

void DestroyDSTable(BTree &DT)
{//����һ��B_��
	int i;
	if (DT)
	{
	  for (i = 0; i <= DT->keynum; ++i)
	  {
		 DestroyDSTable(DT->ptr[i]);//���εݹ����ٵ�i������
	  }
	  free(DT);
	  DT = NULL;
	}
}

void TraverseDSTable(BTree &DT,void (*Visit)(BTNode,int))
{//����B_��DT
	int i;
	if (DT)
	{
		for (i = 0; i <= DT->keynum;++i)
		{
			if (i > 0)
			{
				Visit(*DT,i);
			}
			TraverseDSTable(DT->ptr[i],Visit);
		}
	}
}

int Search(BTNode *p,KeyType k)
{//�����۰���ҷ��ڽ��*p�в�������k��[p->key[i],p->key[i + 1])�����i
	int mid,low = 1,high = p->keynum;
	if LT(k,p->key[low])
	{
		return 0;
	}
	while (low < high)
	{
		mid = (low + high + 1)/2;//��ֵȥ�ϴ��
		if (EQ(k,p->key[mid]))
		{
			return mid;//�ҵ�����k = p->key[i]�����mid����mid
		}
		else if (LT(k,p->key[mid]))
		{
			high = mid - 1;//��[low,mid)�����н��в���
		}
		else
		{
			low = mid;//��[mid,high]�����н��в���
		}
	}
	return low;//�ҵ�����p->key[i] < i < p->key[i + 1]�����low����low
}

Result SearchBTree(BTree T,KeyType k)
{//��B_��DT�в��ҹؼ��ֵ���k�ļ�¼�����ؽ��(pt,i,tag);�����ҳɹ���������ֵtag=1,pt��ָ����е�i��������k;��������ֵtag=0,
 //����k�Ĺؼ���Ӧ�嵽ָ��pt��ָ���ĵ�i�͵�i+1���ؼ���֮��
	BTree p = T,q = NULL;
	Status found = FALSE;
	int i = 0;
	Result r;
	while(p && !found)
	{//p������δ�ҵ�k
		i = Search(p,k);//��*p����в���k
		if (i > 0 && p->key[i] == k)
		{//���ҵ�k���ڽ�㣬�˳�ѭ��
			found = TRUE;
		}
		else
		{
			q = p;//����Ѱ�ң���ǰ�ڵ��Ϊ˫�׽��
			p = p->ptr[i];//pָ��������ҵĽ��
		}
	}

	if (found)
	{//���ҳɹ�
		r.pt = p;//ptָ��ؼ���k��ָ��Ľ��
		r.tag = 1;//���ҳɹ�
	}
	else
	{
		r.pt = q;//ptָ��ؼ���kӦ����Ľ��
		r.tag = 0;//����ʧ��
	}
	r.i = i;
	return r;
}

void Split(BTree q,BTree &ap)
{//��q����Ϊ�������,ǰһ�뽫������*q,��һ�������������*ap
	int i;
	ap = (BTree)malloc(sizeof(BTNode));//�����µĽ��
	ap->ptr[0] = q->ptr[s];//���ؼ��ִ���q->key[s]�Ľ��ָ�븳��ap->ptr[0]
	if (ap->ptr[0])
	{//���ڹؼ��ִ���q->key[s]�ǿս��
		ap->ptr[0]->parent = ap;//�޸ĸý���˫��ָ�룬ʹ��ָ��ap
	}
	for (i = s + 1; i <= m; ++i)
	{//�ƶ�3����Ա�ĵ�*ap
		ap->key[i - s] = q->key[i];//�ؼ���
		ap->recptr[i - s] = q->recptr[i];//��¼ָ��
		ap->ptr[i - s] = q->ptr[i];//���ָ��
		if (ap->ptr[i - s])
		{//�޸ĺ��ӵ�˫��
			ap->ptr[i - s]->parent = ap;
		}
	}
	ap->keynum = m - s;//ap�ؼ�����
	q->keynum = s - 1;//����q�Ĺؼ�����
}

void Insert(BTree q,int i,Record *r, BTree ap)
{//����¼��ַr��r->key�ֱ𸳸�q->recptr[i + 1]��q->key[i + 1],q->ptr[i + 1]ָ����*ap
	int j;
	for (j = q->keynum;j > i;j--)
	{//�ɺ���ǰ���ճ���*q��[i + 1]
		q->key[j + 1] = q->key[j];//3����Ա�������
		q->recptr[j + 1] = q->recptr[j];
		q->ptr[j + 1] = q->ptr[j];
	}
	q->key[i+1] = r->key;
	q->recptr[i+1] = r;
	q->ptr[i + 1] = ap;
	if (ap)
	{
		ap->parent = q;
	}
	q->keynum++;
}

void NewRoot(BTree &T,Record *r,BTree ap)
{//���ɺ���Ϣ(T,r,ap)���µĸ����*T,ԭ�����T��apΪ������ָ��
	BTree p = (BTree)malloc(sizeof(BTNode));//�����µĸ����
	p->parent = NULL;//�������˫��
	p->keynum = 1;//�����Ĺؼ������Ϊ1
	p->key[1] = r->key;//
	p->recptr[1] = r;
	p->ptr[0] = T;
	p->ptr[1] = ap;
	if (T)
	{
		T->parent = p;
	}
	if (ap)
	{
		ap->parent = p;
	}
	T = p;
}

void InsertBTree(BTree &T,Record *r,BTree q, int i)
{//��B_����q�ڵ��в���
	BTree ap = NULL;
	Status finished = FALSE;//������ɱ�־����ʼΪλ���
	while (q && !finished)
	{//q������Ϊ��ɲ���
		Insert(q,i,r,ap);
		if (q->keynum < m)
		{//�ؼ��ֳ����������
			finished = TRUE;//�������
		}
		else
		{
			r = q->recptr[s];//���ѵ�ĵ�ַ����r
			Split(q,ap);//���ѽ��q
			q = q->parent;//��ǰ�ڵ�Ϊ�����ѽ���˫�׽��
			if (q)//�����ѽ���˫�׽�����
			{
				i = Search(q,r->key);//�ڱ����ѽ���˫�׽��*q�в���r->key�Ĳ���λ��
			}
		}
	}
	if (!finished)
	{//T�ǿ���
		NewRoot(T,r,ap);//�����µĸ����
	}
}
