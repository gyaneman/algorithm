#include "simpleLinkedList.h"
#include <stdio.h>
#include <stdlib.h>

SimpleLinkedList* makeSLL(){
	SimpleLinkedList* ret;
	ret = (SimpleLinkedList*)malloc(sizeof(SimpleLinkedList));
	initSLL(ret);
	return ret;
}

void initSLL(SimpleLinkedList* psll){
	psll->head = (Element*)malloc(sizeof(Element));
	psll->tail = (Element*)malloc(sizeof(Element));
	psll->head->data = NULL;
	psll->tail->data = NULL;
	psll->head->next = psll->tail;
	psll->tail->next = NULL;
	psll->num = 0;
}

void addHeadSLL(SimpleLinkedList* psll, void* data){
	Element* element;
	element = (Element*)malloc(sizeof(Element));
	element->data = data;
	element->next = psll->head->next;
	psll->head->next = element;
	psll->num++;
}

int removeHeadSLL(SimpleLinkedList* psll){
	Element* element = psll->head->next;
	if (element == psll->tail) return 0;
	psll->head->next = element->next;
	free(element);
	psll->num--;
	return 1;
}

int removeSLL(SimpleLinkedList* psll, int num){
	Element* e = psll->head;
	Element* remv;
	int i;
	if (psll->num < num) return 0;
	for (i = 0; i < num; i++){
		e = e->next;
	}
	remv = e->next;
	e->next = remv->next;
	free(remv);
	psll->num--;
	return 1;
}

int isEmptySLL(SimpleLinkedList* psll){
	if (psll->num == 0) return 1;
	return 0;
}

void* getDataSLL(SimpleLinkedList* psll, int num){
	Element* e;
	int i;
	if (psll->num < num) {
		printf("num=%d\n", psll->num);
		return NULL;
	}
	for (i = 0, e = psll->head->next; i < num; i++)
		e = e->next;
	return e->data;
}

Iterator_sll getIteratorSLL(SimpleLinkedList* psll){
	return (Iterator_sll)psll->head;
}

int hasNextSLL(Iterator_sll* ite){
	if ((*ite)->next->next == NULL) return 0;
	return 1;
}

void* getNextSLL(Iterator_sll* ite){
	*ite = (*ite)->next;
	return (*ite)->data;
}

void freeSLL(SimpleLinkedList* psll){
	Iterator_sll fr;
	Iterator_sll ite;
	ite = getIteratorSLL(psll);
	for (; hasNextSLL(&ite);){
		fr = ite;
		getNextSLL(&ite);
		free(fr);
	}
	getNextSLL(&ite);
	free(ite);
	free(psll);
}