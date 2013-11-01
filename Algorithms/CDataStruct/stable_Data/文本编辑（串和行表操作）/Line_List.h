#define MAX_LINE_LIST 100//����б��¼
#define ADD_NUM 10//����
#define INIT_ADR 201//��һ����ʼ��ַ
#define	INIT_NUM 100//��һ���к�

//�����б�˳��洢��
//�����б�Ԫ��
typedef struct LineList_Elem
{
	int num; //�к�
	int address; //��ʼ��ַ
	int length; //����
} *P_LineList_Elem;//ָ���б�Ԫ�ص�ָ��

//�����б�ָ��
struct LineList
{
	P_LineList_Elem list;//ָ���б��ָ��
	HString * string; //ָ�򴮵�ָ��
};

void InitList(LineList &L, HString *S)//��ʼ���б�
{
	int i;
	//Ϊ�б����洢�ռ�
	if (!(L.list = (P_LineList_Elem)malloc( (MAX_LINE_LIST + 1) * sizeof(LineList_Elem))))//���һ����¼���ڱ�ǽ���
	{
		exit (OVERFLOW);
	}
	L.string = S; //ָ���
	L.list[0].num= 0;//����б����
}

void ClearList(LineList &L)//����б�
{
	L.list[0].num= 0;//����б����
}

void DestroyList(LineList &L)//�����б�
{
	free(L.list);
	L.list = NULL;
	L.string = NULL;
}

int ListLength(LineList L)//�б���
{
	int i = 0;
	while (L.list[i].num)
	{
		i++;
	}
	return i;
}

Status ListEmpty(LineList L)
{
	if (L.list[0].num)
	{
		return FALSE;
	}
	else
	{
		return TRUE;
	}
}
void UpdateList(LineList &L)//�����б�
{
	int i,j,max = MAX_LINE_LIST;
	L.list[0].num = INIT_NUM;
	L.list[0].address = INIT_ADR;
	for (i = 0,j = 1; i < (*L.string).length; i++)
	{
		if (L.list[j].num == max + 1)//����¼����������¼��ʱ���Ӽ�¼
		{
			if (!(L.list = (P_LineList_Elem)realloc( L.list,(max + ADD_NUM + 1) * sizeof(LineList_Elem))))
			{
				exit (OVERFLOW);
			}
			max += ADD_NUM;
		}
		if ((*L.string).ch[i] == '\n')
		{
			L.list[j].num = j + INIT_NUM ;
			L.list[j].address = i + INIT_ADR + 1;
			L.list[j - 1].length = L.list[j].address - L.list[j - 1].address;
			j++;
		}
	}
	if ((*L.string).ch[(*L.string).length - 1] != '\n')//
	{
		L.list[j - 1].length = (*L.string).length - ( L.list[j - 1].address - INIT_ADR);//���һ���ַ����ǻ��з����������һ����¼�ĳ���
		L.list[j].num = 0;//����б����
	}
	else
	{
		L.list[j - 1].num = 0;//���һ���ַ��ǻ��з������������һ����¼�������Ϊ����
	}
}

Status ListInsert(LineList &L,int num,HString S)//�ڵ�num�к�ǰ�����¼
{
	int i = num - INIT_NUM, pos;
	if (i < 0 || i > ListLength(L))
	{
		return ERROR;
	}
	pos = L.list[i].address - INIT_ADR  + 1;
	StrInsert((*L.string),pos,S);
	UpdateList(L);
	return OK;
}

Status ListDelete(LineList &L,int num)//ɾ���к�Ϊnum�ļ�¼
{
	int i = num - INIT_NUM, pos,len;
	if (i < 0 || i > ListLength(L) - 1)
	{
		return ERROR;
	}
	pos = L.list[i].address - INIT_ADR  + 1;
	len = L.list[i].length;
	StrDelete((*L.string),pos,len);
	UpdateList(L);
	return OK;
}

void ListPrint(LineList L)//��ӡ�б�
{
	int i;
	printf(" �к�  ��ʼ��ַ  ����\n");
	for (i = 0; i < ListLength(L); i++)
	{
		printf(" %d     %d      %d",L.list[i].num,L.list[i].address,L.list[i].length);
		printf("\n");
	}
}