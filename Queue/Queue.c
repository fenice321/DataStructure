#define _CRT_SECURE_NO_WARNINGS 1
#include <stdlib.h>
#include <vld.h>
#include <errno.h>
#include <string.h>
#include "Queue.h"
#include <assert.h>
//�ն���
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
		printf("����Ϊ�ն���,ɾ��ʧ��!\n");
		return;
	}
	else
	{
		QueueNode* next = pq->_qHead->_next;
		free(pq->_qHead);
		pq->_qHead = next;
	}

	//ע��˴�,���ɾ���������һ���ڵ�,����Ҫ��βָ���ÿ�,��ֹҰָ��ĳ���
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
		printf("�ն���,���ʶ�ͷԪ��ʧ��!\n");
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
		printf("�ն���,��βԪ�ط���ʧ��!\n");
		exit(-1);
	}
	else
	{
		return pq->_qTail->_data;
	}
}
//��Ҫ����ȥ����QueueSize,��Ϊʱ�临�Ӷ���O(n)
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