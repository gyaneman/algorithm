#ifndef __PRIORITYQUEUE_H__
#define __PRIORITYQUEUE_H__

#include <stdio.h>
#include <stdlib.h>

struct PQItem_t{
	int priority;
	void* obj;
};

struct PQueue_t{
	int length;		// pqitem�̒���
	int num;		// pqitem�ɂ͂����Ă���I�u�W�F�N�g�̐�
	struct PQItem_t* pqitem;
};

typedef struct PQItem_t PQItem;
typedef struct PQueue_t PQueue;

PQueue* makePQueue(int _length);
void* PQ_pop(PQueue* pq);
int PQ_push(PQueue* pq, int _priority, void* _obj);
void PQ_printAll(PQueue* pq);

#endif