#include "Status.h"
//�������Ͷ��岿��
#define MAX_STR_LEN 40//�û�����255��1���ֽ����ܱ�ʾ��������������ڶ�����󴮳�
typedef unsigned char SString[MAX_STR_LEN + 1];//0�ŵ�Ԫ�洢����
//������������

#define DestroyString ClearString
#define InitString ClearString
Status StrAssign(SString T,char *chars);
void StrCopy(SString T, SString S);
Status StrEmpty(SString S);
int StrCompare(SString S,SString T);
int StrLength(SString S);
void ClearString(SString S);
Status Concat(SString T,SString S1,SString S2);
Status SubString(SString Sub,SString S,int pos,int len);
int Index(SString S,SString T,int pos);
int Index1(SString S,SString T,int pos);
Status StrInsert(SString S,int pos,SString T);
Status StrDelete(SString S,int pos,int len);
void StrPrint(SString S);
int next(SString S, int j);