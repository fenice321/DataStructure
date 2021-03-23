#include "Stack.h"
#include <stdio.h>
#include <vld.h>
//栈的作用,如果有后进先出需求的地方
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

	//查看数据
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