#ifndef __QUEUE_H__
#define __QUEUE_H__
typedef int QDataType;
typedef struct _QueueNode
{
	QDataType _data;
	struct _QueueNode* _next;
} QueueNode;
typedef struct _Queue
{
	QueueNode* _qHead;
	QueueNode* _qTail;
} Queue;
//初始化队列
void QueueInit(Queue* pq);
//入队(Enqueue)---队尾插入数据
void QueuePush(Queue* pq, QDataType item);
//出队(Dequeue)---队头删除数据
void QueuePop(Queue* pq);
//判断队列是否为空
int QueueEmpty(Queue* pq);
//队列有效数据个数
int QueueSize(Queue* pq);
//队头数据
QDataType QueueFront(Queue* pq);
//队尾数据
QDataType QueueBack(Queue* pq);
//销毁队列
void QueueDestroy(Queue* pq);
#endif // __QUEUE_H__