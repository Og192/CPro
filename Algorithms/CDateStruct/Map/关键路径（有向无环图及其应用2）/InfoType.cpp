#include "InfoType.h"
#include <stdio.h>
#include <malloc.h>

void InputArc(InfoType *&arc)
{//���뻡���ߣ�����Ϣ
	arc = (InfoType *)malloc(sizeof(InfoType));
	scanf("%d",&arc->weight);
}
void OutputArc(InfoType *arc)
{//�����Ϣ
	printf(":%d ",arc->weight);
}
void OutputArcwel(InfoType *arc)
{//�������Ȩֵ��ee��el
	printf("%3d %3d %3d",arc->weight,arc->ee,arc->el);
}
void InputArcFromFile(FILE *f,InfoType *&arc)
{//���ļ���������Ϣ
	arc = (InfoType *)malloc(sizeof(InfoType));
	fscanf(f,"%d",&arc->weight);
}