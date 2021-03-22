#define _CRT_SECURE_NO_WARNINGS 1
#include "DList.h"
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <vld.h>
#include <string.h>
#include <assert.h>
void ListInit1(ListNode** ppList)
{
	assert(ppList != NULL);
	*ppList = (ListNode*)malloc(1 * sizeof(ListNode));
	if (*ppList == NULL)
	{
		puts(strerror(errno));
		exit(-1);
	}
	(*ppList)->prev = *ppList;
	(*ppList)->next = *ppList;
}
ListNode* ListInit2()
{
	ListNode* phead = (ListNode*)malloc(1 * sizeof(ListNode));
	if (phead == NULL)
	{
		puts(strerror(errno));
		exit(-1);
	}
	phead->prev = phead;
	phead->next = phead;
	return phead;
}
static ListNode* allocListNode()
{
	ListNode* cur = (ListNode*)malloc(1 * sizeof(ListNode));
	if (cur == NULL)
	{
		puts(strerror(errno));
		exit(-1);
	}
	cur->data = 0;
	cur->next = NULL;
	cur->prev = NULL;
	return cur;
}
void ListPushBack(ListNode* phead, LTDataType item)
{
	assert(phead != NULL);
	ListInsert(phead, item);
}
void ListPushFront(ListNode* phead, LTDataType item)
{
	assert(phead != NULL);
	ListInsert(phead->next, item);
}
void ListPopBack(ListNode* phead)
{
	assert(phead != NULL);
	ListErase(phead->prev);
}
void ListPopFront(ListNode* phead)
{
	assert(phead != NULL);
	ListErase(phead->next);
}
#if 0
void ListPushBack(ListNode* phead, LTDataType item)
{
	assert(phead != NULL);
	//wgl方法
	//ListNode* cur = allocListNode();
	//cur->data = item;

	//cur->next = phead;
	//cur->prev = phead->prev;
	//phead->prev->next = cur;
	//phead->prev = cur;

	//xjh方法,简单
	ListNode* cur = allocListNode();
	cur->data = item;
	ListNode* tail = phead->prev;
	cur->next = phead;
	cur->prev = tail;
	tail->next = cur;
	phead->prev = cur;
}
#endif
void ListPrint1(ListNode* phead)
{
	assert(phead != NULL);
	ListNode* cur = phead->next;
	while (cur != phead)
	{
		printf("%d ", cur->data);
		cur = cur->next;
	}
	puts("");
}
void ListPrint2(ListNode* phead)
{
	assert(phead != NULL);
	ListNode* ptail = phead->prev;
	while (ptail != phead)
	{
		printf("%d ", ptail->data);
		ptail = ptail->prev;
	}
	puts("");
}
#if 0
void ListPopBack(ListNode* phead)
{
	//自己写的
	//assert(phead != NULL);
	//if (phead->next == phead)
	//{
	//	printf("双向链表为空!无法进行尾删 \n");
	//	return;
	//}
	//ListNode* pheadCpy = phead;
	//ListNode* ptail = phead->prev;
	//while (phead->next != ptail)
	//{
	//	phead = phead->next;
	//}
	//free(ptail);
	//ptail = NULL;
	//pheadCpy->prev = phead;
	//phead->next = pheadCpy;

	//xjh写的
	assert(phead != NULL);
	if (phead->next == phead)
	{
		printf("双向链表为空,尾删失败!\n");
		return;
	}
	ListNode* ptail = phead->prev;
	ListNode* ptailPrev = ptail->prev;
	ptailPrev->next = phead;
	phead->prev = ptailPrev;
	free(ptail);
	ptail = NULL;
}
#endif
#if 0
void ListPushFront(ListNode* phead, LTDataType item)
{
	assert(phead != NULL);
	ListNode* cur = allocListNode();
	cur->data = item;
	ListNode* next = phead->next;
	phead->next = cur;
	cur->next = next;
	cur->prev = phead;
	next->prev = cur;
}
#endif
#if 0
void ListPopFront(ListNode* phead)
{
	assert(phead != NULL);
	if (phead->next == phead)
	{
		printf("双向循环链表为空,头删失败!\n");
		return;
	}
	ListNode* cur = phead->next;
	ListNode* next = phead->next->next;
	phead->next = next;
	next->prev = phead;
	free(cur);
}
#endif
void ListInsert(ListNode* pPos, LTDataType item)
{
	assert(pPos != NULL);
	ListNode* prevpPos = pPos->prev;
	ListNode* cur = allocListNode();
	cur->data = item;
	prevpPos->next = cur;
	cur->prev = prevpPos;
	cur->next = pPos;
	pPos->prev = cur;
}
void ListErase(ListNode* pPos)
{
	assert(pPos != NULL);
	ListNode* prevpPos = pPos->prev;
	ListNode* next = pPos->next;
	prevpPos->next = next;
	next->prev = prevpPos;
	free(pPos);
}
ListNode* ListFind(ListNode* phead, LTDataType findData)
{
	assert(phead != NULL);
	ListNode* pheadCpy = phead->next;
	while (pheadCpy != phead)
	{
		if (pheadCpy->data == findData)
		{
			return pheadCpy;
		}
		pheadCpy = pheadCpy->next;
	}
	return NULL;
}

//优点:保持了函数接口设计的一致性
void ListDestroy1(ListNode* phead)
{
	assert(phead != NULL);
	phead->prev->next = NULL;
	ListNode* pt = NULL;
	while (phead != NULL)
	{
		pt = phead;
		phead = phead->next;
		free(pt);
	}
}
void ListClear(ListNode* phead)
{
	assert(phead != NULL);
	ListNode* cur = phead->next;
	while (cur != phead)
	{
		ListNode* next = cur;
		cur = cur->next;
		free(next);
	}

	//注意:销毁双向循环链表节点后继续保持双向链表是双向循环的
	phead->next = phead;
	phead->prev = phead;
}
void ListDestroy(ListNode** pphead)
{
	assert(pphead != NULL);
	ListClear(*pphead);
	free(*pphead);
	*pphead = NULL;
}