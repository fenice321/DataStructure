#include "Stack.h"
#include <stdio.h>
#include <vld.h>
//ջ������,����к���ȳ�����ĵط�
void Test1()
{
	Stack s;
	StackInit(&s);
	StackPush(&s, 1);
	StackPush(&s, 2);
	printf("%d ", StackTop(&s));
	StackPop(&s);
	StackPush(&s, 3);
	StackPush(&s, 4);

	//�鿴����
	while (!StackEmpty(&s))
	{
		printf("%d ", StackTop(&s));
		StackPop(&s);
	}
	puts("");
	StackDestroy(&s);
}
int main()
{
	Test1();
	return 0;
}