#define _CRT_SECURE_NO_WARNINGS 1
#include <stdlib.h>
#include <vld.h>
#include <errno.h>
#include <string.h>
#include "Queue.h"
#include <assert.h>
//空队列
void QueueInit(Queue* pq)
{
	assert(pq != NULL);
	pq->_qHead = NULL;
	pq->_qTail = NULL;
}
static QueueNode* AllocQueueNode()
{
	QueueNode* q = (QueueNode*)malloc(1 * sizeof(QueueNode));
	if (q == NULL)
	{
		puts(strerror(errno));
		exit(-1);
	}
	q->_data = 0;
	q->_next = NULL;
	return q;
}
void QueuePush(Queue* pq, QDataType item)
{
	assert(pq != NULL);
	QueueNode* newQueueNode = AllocQueueNode();
	if (pq->_qHead == NULL)
	{
		pq->_qHead = newQueueNode;
		pq->_qTail = newQueueNode;
	}
	else
	{
		pq->_qTail->_next = newQueueNode;
		pq->_qTail = newQueueNode;
	}
	newQueueNode->_data = item;
	newQueueNode->_next = NULL;
}
void QueuePop(Queue* pq)
{
	assert(pq != NULL);
	if (pq->_qHead == NULL)
	{
		printf("队列为空队列,删除失败!\n");
		return;
	}
	else
	{
		QueueNode* next = pq->_qHead->_next;
		free(pq->_qHead);
		pq->_qHead = next;
	}

	//注意此处,如果删除的是最后一个节点,则需要将尾指针置空,防止野指针的出现
	if (pq->_qHead == NULL)
	{
		pq->_qTail = NULL;
	}
}
int QueueEmpty(Queue* pq)
{
	if (pq->_qHead == NULL)
		return 1;
	else
		return 0;
}
QDataType QueueFront(Queue* pq)
{
	assert(pq != NULL);
	if (pq->_qHead == NULL)
	{
		printf("空队列,访问队头元素失败!\n");
		exit(-1);
	}
	else
	{
		return pq->_qHead->_data;
	}
}
QDataType QueueBack(Queue* pq)
{
	assert(pq != NULL);
	if (pq->_qTail == NULL)
	{
		printf("空队列,队尾元素访问失败!\n");
		exit(-1);
	}
	else
	{
		return pq->_qTail->_data;
	}
}
//不要轻易去调用QueueSize,因为时间复杂度是O(n)
int QueueSize(Queue* pq)
{
	assert(pq != NULL);
	int sz = 0;
	while (pq->_qHead != NULL)
	{
		pq->_qHead = pq->_qHead->_next;
		sz++;
	}
	return sz;
}
void QueueDestroy(Queue* pq)
{
	assert(pq != NULL);
	QueueNode* cur = pq->_qHead;
	while (cur != NULL)
	{
		QueueNode* next = cur;
		cur = cur->_next;
		free(next);
	}
	pq->_qHead = NULL;
	pq->_qTail = NULL;
}