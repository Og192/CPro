#include <stdio.h>
#include <string>

#ifdef MG

#define MAX_INFO 20
typedef char InfoType;

#else

typedef int VRType;//Ȩֵ����
struct InfoType
{//����Ȩֵ��Ļ����ߣ���Ϣ�ṹ�����ͣ����԰���������Ŀ��
	VRType weight;
};

#endif

void InputArc(InfoType *&arc);
void InputArcFromFile(FILE *f,InfoType *&arc);
void OutputArc(InfoType *arc);