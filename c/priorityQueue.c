#include "priorityQueue.h"

PQueue* makePQueue(int _length, int _order){
	PQueue* ret;
	int i;
	ret = (PQueue*)malloc(sizeof(PQueue));
	ret->length = _length;
	if (_order != ASCENDING && _order != DESCENDING) return NULL;
	ret->order = _order;
	ret->pqitem = (PQItem*)calloc(_length, sizeof(PQItem));
	ret->num = 0;

	return ret;
}

static int comp(int order, const int a, const int b){
	if (order == ASCENDING) return a > b;
	else return a < b;
}

int PQ_push(PQueue* pq, int _priority, void* _obj){
	int n = pq->num;
	int i;
	PQItem tmp;
	pq->num++;
	pq->pqitem[n].priority = _priority;
	pq->pqitem[n].obj = _obj;
	
	while (n != 0){
		i = (n - 1) / 2;
		if (comp(pq->order, pq->pqitem[n].priority, pq->pqitem[i].priority)){
			tmp = pq->pqitem[n];
			pq->pqitem[n] = pq->pqitem[i];
			pq->pqitem[i] = tmp;
		}
		n = i;
	}
	return 0;
}

PQItem PQ_pop(PQueue* pq){
	int n = pq->num - 1;
	int i, j;
	PQItem ret = pq->pqitem[0];
	PQItem tmp;
	if (pq->num <= 0) printf("error");
	pq->num--;
	pq->pqitem[0] = pq->pqitem[n];
	for (i = 0; (j = 2 * i + 1) < n;){
		if ((j != n - 1) && 
				comp(pq->order, pq->pqitem[j+1].priority, pq->pqitem[j].priority))
			j++;
		if (comp(pq->order, pq->pqitem[j].priority, pq->pqitem[i].priority)){
			tmp = pq->pqitem[i];
			pq->pqitem[i] = pq->pqitem[j];
			pq->pqitem[j] = tmp;
		}
		i = j;
	}

	return ret;
}

void PQ_printAll(PQueue* pq){
	int i;
	printf("PQ...\n");
	for (i = 0; i < pq->num; i++){
		printf("%d ", pq->pqitem[i].priority);
	}
	printf("\n");
}

void freePQ(PQueue *pq){
	free(pq);
}