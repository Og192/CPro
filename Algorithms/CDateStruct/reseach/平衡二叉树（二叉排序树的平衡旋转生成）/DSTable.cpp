#include "DSTable.h"

Status SearchBST(BiTree &T,KeyType key,BiTree f,BiTree &p)
{//�ڶ����������в��ҹؼ��ֵ���key�ļ�¼�����ҳɹ����򷵻�True,��pָ��ָ��ü�¼�Ľ�㣬����ʧ�ܣ��򷵻�FALSE,pָ��ָ�����·���ϵ����һ�����
	if (!T)
	{
		p = f;
		return FALSE;
	}
	else if (EQ(key,T->data.key))
	{//�ҵ�����key�ļ�¼
		p = T;
		return TRUE;
	}
	else if(LT(key,T->data.key))
	{//���������в���
		return SearchBST(T->lchild,key,T,p);
	}
	else
	{//���������в���
		return  SearchBST(T->rchild,key,T,p);
	}
}

Status InsertBST(BiTree &T,DElemType e)
{//�ڶ��������T�в����¼e
	BiTree p,s;
	if (!SearchBST(T,e.key,NULL,p))
	{//����ʧ�ܣ�����FALSE,pָ��ָ�����·���ϵ����һ�����
		s = (BiTree)malloc(sizeof(BiTNode));//�����½��
		s->data.key = e.key;
		s->data.others = e.others;
		s->lchild = s->rchild = NULL;
		if (!T)
		{//TΪ�գ������eΪ����������ĸ����
			T = s;
		}
		else if (LT(e.key,p->data.key))
		{//e.keyС�������T��key����e��ΪT������
			p->lchild = s;
		}
		else
		{//e.key���������T��key����e��ΪT���Һ���
			p->rchild = s;
		}
		return TRUE;
	}
	return FALSE;
}

void Delete(BiTree &p)
{//�Ӷ�����������ɾ��p��ָ��Ľ�㣨p�Ǹýڵ��˫�׵�����һ��ָ���򣬶��Ƕ�����ָ������������ؽ�������������
	BiTree s,q = p;//qָ���ɾ�����
	if (!p->lchild)
	{//p��������Ϊ�գ����ؽ���������������
		p = p->rchild;
		free(q);
	}
	else if (!p->rchild)
	{//p��������Ϊ�գ����ؽ���������������
		p = p->lchild;
		free(q);
	}
	else
	{//p����������������
		s = p->lchild;//sָ���ɾ����������
		while (s->rchild)
		{//s���ҵ���ͷ
			q = s;
			s = s->rchild;
		}
		p->data = s->data;//����ɾ����ǰ�����ؼ������򣩵�ֵȡ����ɾ���
		if (q != p)
		{//�´�ɾ���*s�������ؽӵ���˫�׽��q��������
			q->rchild = s->lchild;
		}
		else
		{//�´�ɾ���*s���������ؽӵ���˫�׽��q��������
			q->lchild = s->lchild;
		}
		free(s);
	}
}

Status DeleteBST(BiTree &T,KeyType key)
{//������������T�д��ڹؼ��ֵ���Key������Ԫ��ʱ����ɾ��֮
	if (!T)//����
	{
		return FALSE;
	}
	else
	{
		if (EQ(key,T->data.key))
		{//�ҵ���ɾ��¼
			Delete(T);
		}
		else if (LT(key,T->data.key))
		{//������Ҵ�ɾ���
			DeleteBST(T->lchild,key);
		}
		else
		{//���Ҳ��Ҵ�ɾ���
			DeleteBST(T->rchild,key);
		}
		return TRUE;
	}
}







