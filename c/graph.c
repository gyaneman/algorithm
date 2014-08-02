#include "graph.h"
#include "simpleLinkedList.h"

static void* malloc_Graph(const int size){
	void* ret = malloc(size);
	if (ret == NULL){
		fprintf(stderr, "Faild to allocate memory\n");
		exit(1);
	}
	return ret;
}

static void errorHandling(char *text){
	fprintf(stderr, "Error in graph.c\n...in ");
	fprintf(stderr, text);
	exit(1);
}

void printAll_Graph(Graph* graph){
	SimpleLinkedList* setOfNode = &(graph->setOfNode);
	Iterator_sll iteNode = getIteratorSLL(setOfNode);
	Iterator_sll iteLink;
	Node* node = NULL;
	LinkedNode* lnode = NULL;
	printf("\n////////////// PRINT_ALL ///////////////\n\n");
	for (; hasNextSLL(&iteNode);){
		node = (Node*)getNextSLL(&iteNode);
		iteLink = getIteratorSLL(&(node->setOfLinked));
		printf("Node_id = %d\n", node->id);
		for (; hasNextSLL(&iteLink);){
			lnode = (LinkedNode*)getNextSLL(&iteLink);
			printf("........Linked_Node_id = %d   weight = %d\n", 
					lnode->link->id, lnode->weight);
		}
		printf("\n");
	}
	printf("/////////////////////////////////////////\n");
}

Graph* make_Graph(){
	Graph* graph;
	graph = (Graph*)malloc_Graph(sizeof(Graph));
	init_Graph(graph);
	return graph;
}

void init_Graph(Graph* graph){
	initSLL(&(graph->setOfNode));
	graph->numOfEge = 0;
}

void addNode_Graph(Graph* graph, const int id){
	Node* node;
	node = (Node*)malloc_Graph(sizeof(Node));
	node->id = id;
	initSLL(&(node->setOfLinked));
	
	addHeadSLL(&(graph->setOfNode), node);
}

void link_Graph(Graph* graph, int a, int b, int weight){
	Iterator_sll ite = getIteratorSLL(&(graph->setOfNode));
	Node* node_a = NULL;
	Node* node_b = NULL;
	Node* tmp = NULL;
	LinkedNode* lnode = NULL;

	// 指定されたidに間違いがないか確認
	// idからノードを見つける
	if (a == b) errorHandling("linkGraph...same value\n");
	for (; hasNextSLL(&ite);){
		tmp = (Node*)getNextSLL(&ite);
		if (tmp->id == a && node_a == NULL){
			node_a = tmp;
			printf("tmp id = %d\n", tmp->id);
		}
		if (tmp->id == b && node_b == NULL){
			node_b = tmp;
			printf("tmp id = %d\n", tmp->id);
		}
	}
	if (node_a == NULL || node_b == NULL)
		errorHandling("link_graph...not set yet\n");

	// 見つけたノードのつながっている先に互いに追加
	lnode = (LinkedNode*)malloc_Graph(sizeof(LinkedNode));
	lnode->link = node_a;
	printf("id = %d\n", node_b->id);
	addHeadSLL(&(node_b->setOfLinked), lnode);
	lnode->weight = weight;

	printf("3");

	lnode = (LinkedNode*)malloc_Graph(sizeof(LinkedNode));
	lnode->link = node_b;
	addHeadSLL(&(node_a->setOfLinked), lnode);
	lnode->weight = weight;
}

void free_Graph(Graph* graph){
	Iterator_sll ite;
	for (ite = getIteratorSLL(&(graph->setOfNode)); hasNextSLL(&ite);){
		freeSLL(&(((Node*)getNextSLL(&ite))->setOfLinked));	// LinkedNodeのメモリ解放
	}
	freeSLL(&(graph->setOfNode));	// ノードの集合データのメモリ解放
	free(graph);
}