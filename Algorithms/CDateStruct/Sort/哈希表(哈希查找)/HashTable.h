/***************************HashTable.h***************************/
/*���㷨�в��õĹ����ϣ��ķ����У�
1.�����ϣ�����ķ�������������������
   H(key) = key MOD p (p �� m),����mΪ�������㷨��ȡp��m;(һ������£���ѡpΪ�����򲻰���С��20���������ĺ���)
2.�����ͻ�ķ����������Ŷ�ַ����
   Hi = (H(key) + di) MOD m, i=1,2,3,...,k(k <= m - 1),����diΪ��������,������������ȡ����
   (1) ����̽����ɢ�У�di = 1,2,3,...,m-1
   (2) ����̽����ɢ�У�di = 1,-1^2,2,-2^2,...,��k^2(k <= m - 1)
   (3) α���̽����ɢ�У�di = α���������
*/
#ifndef HASHTABLE_H//ͷ�ļ�������
#define HASHTABLE_H

#include "ElemType.h"
static int hashsize[] = {11,19,29,37};//�ڲ����Ӿ�̬��������ϣ����������m��������һ�����ʵ��������С�
typedef struct HashTable
{//��ϣ��Ĵ洢�ṹ
	ElemType *elem;//��¼�洢��ַ��������̬��������
	int count;//��ǰ��¼����
	int sizeindex;//hashsize[sizeindex]Ϊ��ǰ��
}HashTable;

//�궨��
typedef int Status; // Status�Ǻ���������,��ֵ�Ǻ������״̬���룬���±������궨��
#define SUCCESS 1 //���ҳɹ�
#define UNSUCCESS 0//����ʧ��
#define DUPLICATE -1//��¼�ظ�

//����������������
void InitHashTable(HashTable &H);

void DestroyHashTable(HashTable &H);

unsigned Hash(KeyType k);

int d(int i);

void collision(KeyType &k,int &p,int i);

Status SearchHash(HashTable H,KeyType k,int &p,int &c);

Status InsertHash(HashTable &H,ElemType e);

void RecreateHashTable(HashTable &H);

void TraverseHash(HashTable H,void (*Visit)(int,ElemType));

#endif
