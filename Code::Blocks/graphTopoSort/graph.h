#ifndef _graph_h
#define _graph_h

#include <vector>
#include <string>
#include <list>
#include <map>

using namespace std;

typedef int Index;
typedef unsigned UInt32;

struct Node
{
	Index InternalNumber;
	string RealName;
};

struct Cell
{
	Node *CurrentNode;
	list<Node*> Children;
	UInt32 Indegree;
	UInt32 TopoNumber;
};

struct Graph
{
	vector<Cell*> Cells;
	UInt32 Size;
};

map<string, UInt32> mapping;

#endif
