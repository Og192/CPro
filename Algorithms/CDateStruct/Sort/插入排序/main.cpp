#include "Sq_InsertSort.h"

 void main()
 {
   FILE *f; 
   SqList m1,m2,m3,m4; 
   int i;
   f=fopen("1.txt","r"); 
   fscanf(f,"%d",&m1.length); 
   for(i=1;i<=m1.length;i++) 
     InputFromFile(f,m1.r[i]); 
   fclose(f); 
   m2=m3=m4=m1; 
   printf("����ǰ��\n");
   Print(m1); 
   InsertSort(m1); 
   printf("ֱ�Ӳ��������\n");
   Print(m1); 
   BInsertSort(m2); 
   printf("�۰���������\n");
   Print(m2); 
   P2_InsertSort(m3,0); 
   printf("2-·���������\n");
   Print(m3); 
   P2_InsertSort(m4,1); 
   printf("�Ľ���2-·���������\n");
   Print(m4); 
 }