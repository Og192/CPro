#ifndef TELEMTYPE_H//ͷ�ļ�������ֻ�ܱ���ͬһ��Դ�ļ��е�Ƕ�װ������޷����ⲻͬԴ�ļ����е�ͳһͷ�ļ����ظ�������
#define TELEMTYPE_H
//������������е�Ԫ������
#if ET
typedef char TElemType;
const TElemType Nil = ' ';
#define form "%c"
#else
typedef int TElemType;
const TElemType Nil = 0;//ͷ�ļ��в��ܶ������������ܻ����ΰ�����ͷ�ļ�������ظ�����Ĵ��󣬵����Զ��峣��
#define form "%d"
#endif

#endif