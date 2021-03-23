#ifndef __STACK_H__
#define __STACK_H__
//�����ľ�̬ջ,ʵ���в�ʵ��,����ʹ�ÿ��Զ�̬������ջ
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
	int _top;//ջ���±�
	int _capacity;
} Stack;
//��ʼ��ջ�ṹ
void StackInit(Stack* ps);
//��������---ѹջ
void StackPush(Stack* ps, STDataType item);
//ɾ������---��ջ
void StackPop(Stack* ps);
//��ȡ���ݸ���
int StackLen(Stack* ps);
//ջΪ�շ��ط���,�ǿշ���0
int StackEmpty(Stack* ps);
//��ȡջ������
STDataType StackTop(Stack* ps);
//����ջ�ṹ
void StackDestroy(Stack* ps);
#endif // __STACK_H__