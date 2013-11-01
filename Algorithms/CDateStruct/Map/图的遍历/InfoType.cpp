#include "InfoType.h"
#include <stdio.h>
#include <malloc.h>

#ifdef MG

void InputArc(InfoType *&arc)
{
	int m;
	char s[MAX_INFO];
	printf("������ߣ���������Ϣ");
	gets(s);
	m = strlen(s);

	if (m > 0)
	{
		arc = (char *)malloc((m + 1) * sizeof(char));
		strcpy(arc,s);
	}
}
void InputArcFromFile(FILE *f,InfoType *&arc)
{
	char s[MAX_INFO];
	fgets(s,MAX_INFO,f);
	arc = (char *)malloc((strlen(s) + 1) * sizeof(char));
	strcpy(arc,s);
}
void OutputArc(InfoType *arc)
{
	printf("%s\n",arc);
}

#else

void InputArc(InfoType *&arc)
{//���뻡���ߣ�����Ϣ
	arc = (InfoType *)malloc(sizeof(InfoType));
	scanf("%d",&arc->weight);
}
void OutputArc(InfoType *arc)
{//�����Ϣ
	printf(":%d ",arc->weight);
}
void InputArcFromFile(FILE *f,InfoType *&arc)
{//���ļ���������Ϣ
	arc = (InfoType *)malloc(sizeof(InfoType));
	fscanf(f,"%d",&arc->weight);
}

#endif