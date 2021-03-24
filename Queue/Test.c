#define _CRT_SECURE_NO_WARNINGS 1
#include "Queue.h"
#include <stdio.h>
void TestQueue1()
{
	Queue q;
	QueueInit(&q);

	QueuePush(&q, 1);
	QueuePush(&q, 2);

	//��ջ��ͬ����,�����ȳ�����,��Ӱ�����˳��
	printf("%d %d\n", QueueFront(&q), QueueBack(&q));
	QueuePop(&q);

	QueuePush(&q, 3);
	QueuePush(&q, 4);

	while (!QueueEmpty(&q))
	{
		printf("%d %d\n", QueueFront(&q), QueueBack(&q));
		QueuePop(&q);
	}
	QueueDestroy(&q);

}
int main()
{
	TestQueue1();
	return 0;
}