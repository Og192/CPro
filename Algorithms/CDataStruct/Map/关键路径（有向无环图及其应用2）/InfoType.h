#include <stdio.h>
typedef int VRType;//Ȩֵ����
struct InfoType
{//����Ȩֵ��Ļ����ߣ���Ϣ�ṹ�����ͣ����԰���������Ŀ��
	VRType weight;
	int ee,el;
};

void InputArc(InfoType *&arc);
void OutputArc(InfoType *arc);
void OutputArcwel(InfoType *arc);
void InputArcFromFile(FILE *f,InfoType *&arc);

