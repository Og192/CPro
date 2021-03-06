#include "graph.h"

void InitTable(Table table[], int tableSize)
{
	for(int i = 0; i < tableSize; i++)
	{
		table[i].Distance = -1;
		table[i].Known = false;
		table[i].ParentNode = NULL;
	}
}

void ShortPathUnweighted(Table table[], Graph *graph, Node *startNode)
{
	UInt32 currentDistance;
	table[startNode->InternalNumber - 1].Distance = 0;
	for(currentDistance = 0; currentDistance < graph->Size; currentDistance)
	{
		vector<Cell*>::iterator iter = graph->Cells.begin();
		for(;iter != graph->Cells.end(); iter++)
		{
			if(table[(*iter)->CurrentNode->InternalNumber - 1].Distance == currentDistance &&
					!table[(*iter)->CurrentNode->InternalNumber - 1].Known)
			{
				table[(*iter)->CurrentNode->InternalNumber - 1].Known = true;
				list<Node*>::iterator iterNode = (*iter)->Children.begin();
				for(;iterNode != (*iter)->Children.end(); iterNode++)
				{
					table[(*iterNode)->InternalNumber - 1].Distance = currentDistance + 1;
					table[(*iterNode)->InternalNumber - 1].ParentNode =(*iter)->CurrentNode;
				}
			}
		}
	}
}
