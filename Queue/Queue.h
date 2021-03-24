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
//��ʼ������
void QueueInit(Queue* pq);
//���(Enqueue)---��β��������
void QueuePush(Queue* pq, QDataType item);
//����(Dequeue)---��ͷɾ������
void QueuePop(Queue* pq);
//�ж϶����Ƿ�Ϊ��
int QueueEmpty(Queue* pq);
//������Ч���ݸ���
int QueueSize(Queue* pq);
//��ͷ����
QDataType QueueFront(Queue* pq);
//��β����
QDataType QueueBack(Queue* pq);
//���ٶ���
void QueueDestroy(Queue* pq);
#endif // __QUEUE_H__