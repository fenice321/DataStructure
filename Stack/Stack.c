#include "Stack.h"
#define _CRT_SECURE_NO_WARNINGS 1
#include <stdlib.h>
#include <assert.h>
#include <stdio.h>
#include <errno.h>
#include <string.h>
#include <stdbool.h>
void StackInit(Stack* ps)
{
	assert(ps != NULL);
	ps->_capacity = DEFAULT_STACK_CAPACITY;
	ps->_pa = (STDataType*)malloc(ps->_capacity * sizeof(STDataType));
	if (ps->_pa == NULL)
	{
		puts(strerror(errno));
		exit(-1);
	}
	ps->_top = 0;
}
static bool isFull(Stack* ps)
{
	assert(ps != NULL);
	return ps->_capacity == ps->_top;
}
static void ReallocStack(Stack* ps)
{
	assert(ps != NULL);
	ps->_capacity *= 2;
	STDataType* p = (STDataType*)realloc(ps->_pa, ps->_capacity * sizeof(STDataType));
	if (p == NULL)
	{
		puts(strerror(errno));
		free(ps->_pa);
		exit(-1);
	}
	ps->_pa = p;
}
void StackPush(Stack* ps, STDataType item)
{
	assert(ps != NULL);
	if (isFull(ps))
	{
		ReallocStack(ps);
	}
	ps->_pa[ps->_top++] = item;
}
static bool isEmpty(Stack* ps)
{
	assert(ps != NULL);
	return ps->_top == 0;
}
void StackPop(Stack* ps)
{
	assert(ps != NULL);
	if (isEmpty(ps))
	{
		printf("栈空,无法删除数据\n");
	}
	else
	{
		ps->_top--;
	}
}
int StackLen(Stack* ps)
{
	assert(ps != NULL);
	return ps->_top;
}
//为空返回非零,非空返回0
int StackEmpty(Stack* ps)
{
	assert(ps != NULL);
	if (ps->_top)
	{
		return 0;
	}
	else
	{
		return 1;
	}
}
STDataType StackTop(Stack* ps)
{
	assert(ps != NULL);
	if (StackEmpty(ps))
	{
		printf("栈空,栈顶没有元素\n");
		exit(-1);
	}
	return ps->_pa[ps->_top - 1];
}
void StackDestroy(Stack* ps)
{
	assert(ps != NULL);
	free(ps->_pa);
	ps->_pa = NULL;
	ps->_capacity = 0;
	ps->_top = 0;
}