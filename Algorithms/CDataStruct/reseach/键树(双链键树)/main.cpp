#include "DLTree.h"
#define N 20 //数组可容纳的元素个数
int main(void)
{
   DLTree t;
   int i,j=0; 
   KeyType k;
   Status flag;
   Record *p,r[N]; 
   FILE *f; 
   InitDSTable(t); 
   f=fopen("1.txt","r"); 
   do 
   { i=fscanf(f,"%s%d",&r[j].key.ch,&r[j].others.order); 
     if(i!=-1) 
     { r[j].key.num=strlen(r[j].key.ch); 
       flag=InsertDSTable(t,&r[j]); 
       if(flag==FALSE)
         printf("树t中已存在关键字为%s的记录，故(%s,%d)无法插入。\n",
       r[j].key.ch,r[j].key.ch,r[j].others.order);
       j++; 
     }
   }while(!feof(f)&&j<N); 
   fclose(f); 
   printf("按关键字符串的顺序遍历树t：\n");
   TraverseDSTable(t,Visit); 
   printf("\n请输入待查找记录的关键字符串：");
   InputKey(k.ch); 
   k.num=strlen(k.ch); 
   p=SearchDLTree(t,k); 
   if(p) 
     Visit(p); 
   else 
     printf("未找到"); 
   printf("\n");
   DestroyDSTable(t); 

	return 0;
}