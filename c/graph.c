#include "graph.h"
//#include "simpleLinkedList.h"

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
	graph->numOfNode = 0;
	graph->numOfEge = 0;
}

int addNode_Graph(Graph* graph){
	Node* node;
	node = (Node*)malloc_Graph(sizeof(Node));
	graph->numOfNode++;
	node->id = graph->numOfNode;
	initSLL(&(node->setOfLinked));
	
	addHeadSLL(&(graph->setOfNode), node);
	return graph->numOfNode;
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
		}
		if (tmp->id == b && node_b == NULL){
			node_b = tmp;
		}
	}
	if (node_a == NULL || node_b == NULL)
		errorHandling("link_graph...not set yet\n");

	// 見つけたノードのつながっている先に互いに追加
	lnode = (LinkedNode*)malloc_Graph(sizeof(LinkedNode));
	lnode->link = node_a;
	addHeadSLL(&(node_b->setOfLinked), lnode);
	lnode->weight = weight;

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

void solve_Dijkstra(Graph *graph, const int startId, int *result){
	Iterator_sll ite;
	Node* start = NULL;
	PQueue *pq = makePQueue(30, DESCENDING);
	LinkedNode *lnode = NULL;
	int numSolved = 0;
	int currentId;
	Node *currentNode = NULL;
	int i;
	int priority;
	int flg = 0;
	Node *tmpNode = NULL;
	PQItem pqitem;

	for (i = 0; i < graph->numOfNode; i++){
		result[i] = -1;
	}

	/* search start node */
	for (ite = getIteratorSLL(&(graph->setOfNode)); hasNextSLL(&ite);){
		start = (Node*)getNextSLL(&ite);
		if (start->id == startId) break;
	}
	if (start == NULL) errorHandling("Dijkstra    startId is not exist.\n");

	/* solve */
	currentId = startId;
	currentNode = start;
	result[currentId - 1] = 0;
	while (1){
		// 現在のノードからつながっているノードをすべてpush
		for (ite = getIteratorSLL(&(currentNode->setOfLinked)); hasNextSLL(&ite);){
			lnode = getNextSLL(&ite);
			PQ_push(pq, result[currentId-1] + lnode->weight, lnode->link);
		}
		// 順番にpopしていく
		priority = 0;
		while (1){
			if (pq->num == 0) {
				flg = 1;
				break;
			}
			pqitem = PQ_pop(pq);
			tmpNode = (Node*)(pqitem.obj);
			if (result[tmpNode->id - 1] != -1) continue;
			result[tmpNode->id - 1] = pqitem.priority;
			currentNode = tmpNode;
			currentId = tmpNode->id;
			break;
		}
		if (flg) break;
	}
}