#include "Sq_HeapSort.h"
#include <stdio.h>

int main(void)
{
	FILE *f; 
	SqList m; 
	int i;
    f=fopen("1.txt","r"); 
    fscanf(f,"%d",&m.length); 
    for(i=1;i<=m.length;i++) 
    {  
	    InputFromFile(f,m.r[i]); 
	}
	fclose(f);  
    printf("����ǰ��\n");
    PrintL(m); 
    HeapSort(m); 
    printf("��ѡ�������\n");
    PrintL(m); 
	return 0;
}