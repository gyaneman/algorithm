#ifndef GRAPH_H
#define GRAPH_H

#include <stdio.h>
#include <stdlib.h>
#include "simpleLinkedList.h"

struct Node_t{
	int id;							// 識別子的な
	SimpleLinkedList setOfLinked;	// つながっている辺の集合
};

struct LinkedNode_t{
	struct Node_t* link;		// つなっがっている先のノード
	int weight;					// 辺の重み
};

struct Graph_t{
	SimpleLinkedList setOfNode;	// ノードの集合
	int numOfEge;
};

typedef struct Node_t Node;
typedef struct LinkedNode_t LinkedNode;
typedef struct Graph_t Graph;

void printAll_Graph(Graph* graph);

Graph* makeGraph();
void init_Graph(Graph* graph);

void addNode_Graph(Graph* graph, const int id);
void link_Graph(Graph* graph, const int a, const int b, const weight);

void free_Graph(Graph* graph);

#endif