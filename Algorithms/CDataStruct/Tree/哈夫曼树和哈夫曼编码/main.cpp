#include "HuffmanTree.h"

void main()
{
	HuffmanTree HT;
	HuffmanCode HC;
	int *w, n, i;
	printf("������Ȩֵ�ø�����n > 1):");
	scanf("%d",&n);
	w = (int *)malloc(n * sizeof(int));
	printf("����������%d��Ȩֵ�����ͣ�:\n",n);
	for (i = 0; i <= n - 1; ++i)
	{
		scanf("%d", w + i);
	}
	HuffmanCoding(HT,HC,w,n);
	for (i = 1; i <= n; ++i)
	{
		puts(HC[i]);
	}
}