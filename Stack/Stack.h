#ifndef __STACK_H__
#define __STACK_H__
//定长的静态栈,实际中不实用,我们使用可以动态增长的栈
//typedef int STDataType;
//#define N 10
//typedef struct _Stack
//{
//	STDataType _a[N];
//	int _top;
//} Stack;
#include <stdbool.h>
#define DEFAULT_STACK_CAPACITY 4
typedef int  STDataType;
typedef struct _Stack
{
	STDataType* _pa;
	int _top;//栈顶下标
	int _capacity;
} Stack;
//初始化栈结构
void StackInit(Stack* ps);
//插入数据---压栈
void StackPush(Stack* ps, STDataType item);
//删除数据---出栈
void StackPop(Stack* ps);
//获取数据个数
int StackLen(Stack* ps);
//栈为空返回非零,非空返回0
int StackEmpty(Stack* ps);
//获取栈顶数据
STDataType StackTop(Stack* ps);
//销毁栈结构
void StackDestroy(Stack* ps);
#endif // __STACK_H__