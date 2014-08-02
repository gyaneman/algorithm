#ifndef GRAPH_H
#define GRAPH_H

#include <stdio.h>
#include <stdlib.h>
#include "simpleLinkedList.h"

struct Node_t{
	int id;							// ���ʎq�I��
	SimpleLinkedList setOfLinked;	// �Ȃ����Ă���ӂ̏W��
};

struct LinkedNode_t{
	struct Node_t* link;		// �Ȃ������Ă����̃m�[�h
	int weight;					// �ӂ̏d��
};

struct Graph_t{
	SimpleLinkedList setOfNode;	// �m�[�h�̏W��
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