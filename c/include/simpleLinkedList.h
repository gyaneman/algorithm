#ifndef __SIMPLELINKEDLIST_H__
#define __SIMPLELINKEDLIST_H__

#include <stdio.h>
#include <stdio.h>

#include "simpleLinkedList.h"

struct Element_t{
	void* data;
	struct Element_t* next;
};

struct SimpleLinkedList_t{
	struct Element_t* head;
	struct Element_t* tail;
	int num;
};

typedef struct Element_t Element;
typedef struct SimpleLinkedList_t SimpleLinkedList;
typedef struct Element_t* Iterator_sll;

/* SimpleLinkedList�I�u�W�F�N�g������ */
SimpleLinkedList* makeSLL();
/* SimpleLinkedList�I�u�W�F�N�g�̏��������� */
void initSLL(SimpleLinkedList* psll);

/* ���X�g�̓��ɒǉ� */
void addHeadSLL(SimpleLinkedList* psll, void* data);

/* ���X�g�̓����폜 */
int removeHeadSLL(SimpleLinkedList* psll);
/* ���X�g�̗v�f[num]���폜 (0���琔����) */
int removeSLL(SimpleLinkedList* psll, int num);

/* SimpleLinkedList����ł��邩���ׂ� */
int isEmptySLL(SimpleLinkedList* psll);

/* �v�f[num]�̒��g�̃I�u�W�F�N�g��Ԃ� */
void* getDataSLL(SimpleLinkedList* psll, int num);

/* SimpleLinkedList�̐擪�̃C�e���[�^��Ԃ� */
Iterator_sll getIteratorSLL(SimpleLinkedList* psll);

/* �C�e���[�^�Ɏ������邩���ׂ� */
int hasNextSLL(Iterator_sll* ite);

/* �C�e���[�^�����ɐi�߂� */
void* getNextSLL(Iterator_sll* ite);

/* �v�f�̃�������S����� */
void freeSLL(SimpleLinkedList* psll);

#endif