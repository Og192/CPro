#include "Sq_InsertSort.h"
#include <malloc.h>
#define N 10//��¼���鳤��
#define T 3//�����������鳤��
int main(void)
{
   RedType d[N] = {{49,1},{38,2},{65,3},{97,4},{76,5},{13,6},{27,7},{49,8},
   {55,9},{4,10}};//��¼����
   SqList m;//˳���
   //int i,dt[T] = {5,3,1};//�����������飨�ɴ�С�����һ���ֵ��Ϊ1��
   int i;
   for (i = 0; i < N; ++i)
   {//������d����˳���m
	   m.r[i + 1] = d[i];
   }
   m.length = N;
   printf("ϣ������ǰ��");
   Print(m);//�������ǰ��˳���m
   ShellSort(m);//����������dt[0..T-1]��˳���m��ϣ������
   printf("ϣ�������");
   Print(m);
   return 0;
}

