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

/* SimpleLinkedListオブジェクトをつくる */
SimpleLinkedList* makeSLL();
/* SimpleLinkedListオブジェクトの初期化処理 */
void initSLL(SimpleLinkedList* psll);

/* リストの頭に追加 */
void addHeadSLL(SimpleLinkedList* psll, void* data);

/* リストの頭を削除 */
int removeHeadSLL(SimpleLinkedList* psll);
/* リストの要素[num]を削除 (0から数えて) */
int removeSLL(SimpleLinkedList* psll, int num);

/* SimpleLinkedListが空であるか調べる */
int isEmptySLL(SimpleLinkedList* psll);

/* 要素[num]の中身のオブジェクトを返す */
void* getDataSLL(SimpleLinkedList* psll, int num);

/* SimpleLinkedListの先頭のイテレータを返す */
Iterator_sll getIteratorSLL(SimpleLinkedList* psll);

/* イテレータに次があるか調べる */
int hasNextSLL(Iterator_sll* ite);

/* イテレータを次に進める */
void* getNextSLL(Iterator_sll* ite);

/* 要素のメモリを全部解放 */
void freeSLL(SimpleLinkedList* psll);

#endif