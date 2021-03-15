#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include "SList.h"
void test1()
{
	SListNode* pList;//头指针
	SListNodePointerInit(&pList);
	SListPushBack(&pList, 1);
	SListPushBack(&pList, 2);
	SListPushBack(&pList, 3);
	SListPushBack(&pList, 4);

	printf("%u\n", SListLength(pList));

	SListTraverse(pList);

	SListPopBack(&pList);
	SListTraverse(pList);

	SListPopBack(&pList);
	SListTraverse(pList);

	SListPopBack(&pList);
	SListTraverse(pList);

	SListPopBack(&pList);
	SListTraverse(pList);

	SListPopBack(&pList);
	SListTraverse(pList);

	SListPushFront(&pList, 2);
	SListTraverse(pList);

	SListPushFront(&pList, 2);
	SListTraverse(pList);

	SListPushFront(&pList, 3);
	SListTraverse(pList);

	SListPushFront(&pList, 4);
	SListTraverse(pList);

	SListNode* pt = SListNodeFind(pList, 4);
	if (pt)
	{
		printf("单链表中找到了4\n");
		pt->data = 888;
		SListTraverse(pt);
	}
	else
	{
		printf("买找到4\n");
	}
	//SListNodeReverse(&pList);
	//SListTraverse(pList);

	//SListPopFront(&pList);
	//SListTraverse(pList);

	//SListPopFront(&pList);
	//SListTraverse(pList);

	//SListPopFront(&pList);
	//SListTraverse(pList);

	//SListPopFront(&pList);
	//SListTraverse(pList);

}
void test2()
{
	SListNode* pList;//头指针
	SListNodePointerInit(&pList);
	SListPushBack(&pList, 1);
	SListPushBack(&pList, 2);
	SListPushBack(&pList, 3);
	SListPushBack(&pList, 4);

	printf("%u\n", SListLength(pList));

	SListTraverse(pList);

	SListPopBack(&pList);
	SListTraverse(pList);

	SListPopBack(&pList);
	SListTraverse(pList);

	SListPopBack(&pList);
	SListTraverse(pList);

	SListPopBack(&pList);
	SListTraverse(pList);

	SListPopBack(&pList);
	SListTraverse(pList);

	SListPushFront(&pList, 2);
	SListTraverse(pList);

	SListPushFront(&pList, 2);
	SListTraverse(pList);

	SListPushFront(&pList, 3);
	SListTraverse(pList);

	SListPushFront(&pList, 4);
	SListTraverse(pList);

	SListNode* pt = SListNodeFind(pList, 4);
	if (pt)
	{
		printf("单链表中找到了4\n");
		pt->data = 888;
		SListTraverse(pt);
	}
	else
	{
		printf("没找到4\n");
	}
	SListNodeEraseAfter(pt);
	SListTraverse(pt);

	SListNodeInsertAfter(pt, 666);
	SListTraverse(pt);
	SListNodeReverse(&pList);
	SListTraverse(pList);
	SListNodeDestroy(pList);
	pList = NULL;
}
//如何在链表OJ题快速构建测试用
typedef struct node
{
	int data;
	struct node* next;
} Node;
Node* removeElem(Node* phead, int val)
{
	Node* pheadCpy = phead;
	Node* prev = NULL;
	while (pheadCpy != NULL)
	{
		if (pheadCpy->data == val)
		{
			if (prev == NULL)
			{
				pheadCpy = pheadCpy->next;
				free(phead);
				phead = pheadCpy;
			}
			else
			{
				prev->next = pheadCpy->next;
				free(pheadCpy);
				pheadCpy = prev->next;
			}
		}
		else
		{
			prev = pheadCpy;
			pheadCpy = pheadCpy->next;
		}
	}
	return phead;
}
void test3()
{
	Node* pn1 = (Node*)malloc(1 * sizeof(Node));
	if (NULL == pn1)
	{
		printf("error1!\n");
		exit(-1);
	}
	Node* pn2 = (Node*)malloc(1 * sizeof(Node));
	if (NULL == pn2)
	{
		printf("error2!\n");
		exit(-1);
	}
	Node* pn3 = (Node*)malloc(1 * sizeof(Node));
	if (NULL == pn3)
	{
		printf("error3!\n");
		exit(-1);
	}
	Node* pn4 = (Node*)malloc(1 * sizeof(Node));
	if (NULL == pn4)
	{
		printf("error1!\n");
		exit(-1);
	}
	Node* pn5 = (Node*)malloc(1 * sizeof(Node));
	if (NULL == pn5)
	{
		printf("error1!\n");
		exit(-1);
	}
	pn1->data = 6;
	pn2->data = 3;
	pn3->data = -2;
	pn4->data = 6;
	pn5->data = 6;
	pn1->next = pn2;
	pn2->next = pn3;
	pn3->next = pn4;
	pn4->next = pn5;
	pn5->next = NULL;
	Node* phead = pn1;
	phead = removeElem(phead, 6);
}
int main()
{
	//test1();
	//test2();
	test3();
	return 0;
}