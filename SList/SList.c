#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include "SList.h"
#include <stdlib.h>
#include <stdbool.h>
#include <assert.h>
#include <errno.h>
#include <string.h>
void SListNodePointerInit(SListNode** ppList)
{
	assert(ppList != NULL);
	*ppList = NULL;
}
static SListNode* allocSListNode()
{
	SListNode* cur = (SListNode*)malloc(1 * sizeof(SListNode));
	if (NULL == cur)
	{
		puts(strerror(errno));
		exit(-1);
	}
	return cur;
}
void SListPushBack(SListNode** ppList, SListDataType item)
{
	assert(ppList != NULL);
	SListNode* cur = allocSListNode();
	cur->data = item;
	if (*ppList != NULL)
	{
		SListNode* tail = *ppList;
		while (tail->next != NULL)
		{
			tail = tail->next;
		}
		tail->next = cur;
	}
	else
	{
		*ppList = cur;
	}
	cur->next = NULL;
}
void SListPopBack(SListNode** ppList)
{
	assert(ppList != NULL);
	if (*ppList == NULL)
	{
		printf("链表为空,尾删失败!\n");
	}
	else if ((*ppList)->next == NULL)
	{
		free(*ppList);
		*ppList = NULL;
	}
	else
	{
		//法一
		//SListNode* tmp = *ppList;
		//while (tmp->next->next != NULL)
		//{
		//	tmp = tmp->next;
		//}
		//free(tmp->next);
		//tmp->next = NULL;

		//法二
		SListNode* tmp = *ppList;
		SListNode* prev = NULL;
		while (tmp->next != NULL)
		{
			prev = tmp;
			tmp = tmp->next;
		}
		free(tmp);
		prev->next = NULL;
	}
}
void SListPopFront(SListNode** ppList)
{
	assert(ppList != NULL);
	//法一
	//1.空链表头删失败
	//2.一个节点
	//3.两个以及两个以上节点
	//if (NULL == *ppList)
	//{
	//	printf("单链表为空链表,头删失败!\n");
	//}
	//else if (NULL == (*ppList)->next)
	//{
	//	free(*ppList);
	//	*ppList = NULL;
	//}
	//else
	//{
	//	SListNode* ptmp = *ppList;
	//	*ppList = (*ppList)->next;
	//	free(ptmp);
	//	ptmp = NULL;
	//}

	//法二
	//1.空链表
	//2.一个节点+3.两个节点以及两个以上节点
	if (NULL == *ppList)
	{
		printf("单链表为空链表,头删失败!\n");
	}
	else
	{
		SListNode* tmp = (*ppList)->next;
		free(*ppList);
		*ppList = tmp;
	}
}
void SListPushFront(SListNode** ppList, SListDataType item)
{
	assert(ppList != NULL);

	//1.空链表的头插+2.非空链表的头插
	SListNode* cur = allocSListNode();
	cur->data = item;
	cur->next = *ppList;
	*ppList = cur;
}
void SListTraverse(SListNode* pList)
{
	//不需要断言
	while (pList != NULL)
	{
		printf("%d->", pList->data);
		pList = pList->next;
	}
	puts("");
}
size_t SListLength(SListNode* pList)
{
	//不需要断言
	size_t len = 0;
	for (len = 0; pList != NULL; ++len)
	{
		pList = pList->next;
	}
	return len;
}
void SListNodeReverse(SListNode** ppList)
{
	assert(ppList != NULL);
	if (*ppList == NULL || (*ppList)->next == NULL)
	{
		return;
	}
	SListNode* cur = (*ppList)->next;
	(*ppList)->next = NULL;
	while (cur != NULL)
	{
		SListNode* pt = cur;
		cur = cur->next;
		pt->next = *ppList;
		*ppList = pt;
	}
}
SListNode* SListNodeFind(SListNode* pList, SListDataType findData)
{
	while (pList != NULL)
	{
		if (findData == pList->data)
			return pList;
		pList = pList->next;
	}
	return NULL;
}
void SListNodeInsertAfter(SListNode* pos, SListDataType item)
{
	assert(pos != NULL);
	SListNode* cur = allocSListNode();
	cur->data = item;
	cur->next = pos->next;
	pos->next = cur;
}
void SListNodeEraseAfter(SListNode* pos)
{
	assert(pos != NULL && pos->next != NULL);
	SListNode* pt = pos->next;
	pos->next = pos->next->next;
	free(pt);
}
void SListNodeDestroy(SListNode* pList)
{
	if (pList == NULL)
	{
		return 0;
	}
	while (pList)
	{
		SListNode* pListCpy = pList;
		pList = pList->next;
		free(pListCpy);
	}
}