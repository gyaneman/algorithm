#ifndef PRIORITYQUEUE_H
#define PRIORITYQUEUE_H

#include <stdio.h>
#include <stdlib.h>

#define ASCENDING 0
#define DESCENDING 1

struct PQItem_t{
	int priority;
	void* obj;
};

struct PQueue_t{
	int length;		// pqitemの長さ
	int num;		// pqitemにはいっているオブジェクトの数
	int order;
	struct PQItem_t* pqitem;
};

typedef struct PQItem_t PQItem;
typedef struct PQueue_t PQueue;

PQueue* makePQueue(int _length, const int order);
PQItem PQ_pop(PQueue* pq);
int PQ_push(PQueue* pq, int _priority, void* _obj);
void PQ_printAll(PQueue* pq);
void freePQ(PQueue *pq);


#endif