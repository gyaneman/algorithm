#include "priorityQueue.h"

PQueue* makePQueue(int _length){
	PQueue* ret;
	int i;
	ret = (PQueue*)malloc(sizeof(PQueue));
	ret->length = _length;
	ret->pqitem = (PQItem*)calloc(_length, sizeof(PQItem));
	ret->num = 0;

	return ret;
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
		if (pq->pqitem[n].priority > pq->pqitem[i].priority){
			tmp = pq->pqitem[n];
			pq->pqitem[n] = pq->pqitem[i];
			pq->pqitem[i] = tmp;
		}
		n = i;
	}
	return 0;
}

void* PQ_pop(PQueue* pq){
	int n = pq->num - 1;
	int i, j;
	void* ret = pq->pqitem[0].obj;
	PQItem tmp;
	if (pq->num <= 0) return NULL;
	pq->num--;
	pq->pqitem[0] = pq->pqitem[n];
	for (i = 0; (j = 2 * i + 1) < n;){
		if ((j != n - 1) && (pq->pqitem[j].priority) < pq->pqitem[j + 1].priority)
			j++;
		if (pq->pqitem[i].priority < pq->pqitem[j].priority){
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