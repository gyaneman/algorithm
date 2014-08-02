#ifndef GRAPH_H
#define GRAPH_H

#include <stdio.h>
#include <stdlib.h>
#include "simpleLinkedList.h"
#include "priorityQueue.h"

struct Node_t{
	int id;							// 識別子的な
	SimpleLinkedList setOfLinked;	// つながっている辺の集合
};

struct LinkedNode_t{
	struct Node_t* link;		// つなっがっている先のノード
	int weight;					// 辺の重み
};

struct Graph_t{
	int numOfNode;
	int numOfEge;
	SimpleLinkedList setOfNode;	// ノードの集合
};

typedef struct Node_t Node;
typedef struct LinkedNode_t LinkedNode;
typedef struct Graph_t Graph;

void printAll_Graph(Graph* graph);

Graph* make_Graph();
void init_Graph(Graph* graph);

int addNode_Graph(Graph* graph);
void link_Graph(Graph* graph, const int a, const int b, const weight);

void free_Graph(Graph* graph);


/* Dijkstra's algorithm */
void solve_Dijkstra(Graph *graph, const int startId, int *result);

#endif