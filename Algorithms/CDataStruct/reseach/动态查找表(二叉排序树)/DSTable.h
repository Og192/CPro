#ifndef BISORTTREE_H
#define BISORTTREE_H
#include "Status.h"
#include "DElemType.h"
#include "BiTree.h"
//�������ݽṹ
typedef BiTree DSTable;
#define InitDSTable InitBiTree
#define DestroyDSTable DestroyBiTree
#define TraverseDSTable InOrderTraverse
//����������������
Status SearchBST(BiTree &T,KeyType key,BiTree f,BiTree &p);
Status InsertBST(BiTree &T,DElemType e);
void Delete(BiTree &p);
Status DeleteBST(BiTree &T,KeyType key);
#endif

