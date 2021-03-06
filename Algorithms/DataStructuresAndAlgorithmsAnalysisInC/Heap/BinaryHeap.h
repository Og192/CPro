#ifndef _BinHeap_H
#define _BinHeap_H

#define MINQUEUESIZE 10
#define MINIDATA -1
//type of priority queue contained.
typedef int ElementType;
//Struct of Priority Queue
typedef struct HeapStruct
{
	int Capacity;
	int Size;
	ElementType *Elements;
} HeapStruct;
//Pointer of Priority Queue
typedef HeapStruct *PriorityQueue;
//Initialize with "MaxElements" elements in priotity queue
PriorityQueue Initialize(int MaxElements);
//Destroy the Priority queue
void Destroy(PriorityQueue H);
//make a Priority queue empty.
void MakeEmpty(PriorityQueue H);

void Insert(ElementType X, PriorityQueue H);
//Delete minimus element in priority queue.
ElementType DeleteMin(PriorityQueue H);
//Fnd the mininum element in priority queue.
ElementType FindMin(PriorityQueue H);
int IsEmpty(PriorityQueue H);
int IsFull(PriorityQueue H);

#endif
