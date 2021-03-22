#define _CRT_SECURE_NO_WARNINGS 1
#include "DList.h"
#include <stdio.h>
#include <vld.h>

//面试题,10分钟之内写出一个双向循环链表
//解:先写结构体,再初始化链表,写删除当前节点接口和当前节点前一个节点插入接口,然后复用出头插,头删,尾插,尾删,清除,销毁,打印

//面试题:链表和顺序表(数组)之间的区别和联系是什么
//答:顺序表可以随机访问,尾插,尾删效率高O(1),头插头删,中间插入删除需要挪动数据效率不高O(N),缓存命中率高,插入数据时
//会增容很有可能有空间浪费,增容带来的时间开销大,本质---牺牲空间(一次多增容浪费空间)换取时间(增容次数减少)

//链表,一般指带头双向循环链表,任意位置插入删除效率都很高O(1),缓存命中率不高,指针域消耗空间,不能随机访问,一方面可以
//利用碎片空间,另一方面许多小的节点空间被申请造成内存碎片增多

//链表和顺序表优缺点是互补的
void TestList1()
{
	printf("TestList1=====================\n");
	ListNode* phead = NULL;
	ListInit1(&phead);
	ListPushBack(phead, 1);
	ListPushBack(phead, 2);                                                                                                                                                                                                                                                                                                                                                                                                     

	ListPushBack(phead, 3);
	ListPushBack(phead, 4);
	ListPrint1(phead);

	ListPopBack(phead);
	ListPrint1(phead);

	ListPopBack(phead);
	ListPrint1(phead);

	ListPopBack(phead);
	ListPrint1(phead);

	ListPopBack(phead);
	ListPrint1(phead);

	//ListPopBack(phead);
	//ListPrint1(phead);

	ListPushFront(phead, 1);
	ListPushFront(phead, 2);
	ListPushFront(phead, 3);
	ListPushFront(phead, 4);
	ListPrint1(phead);

	ListPopFront(phead);
	ListPrint1(phead);
	ListPopFront(phead);
	ListPrint1(phead);
	ListPopFront(phead);
	ListPrint1(phead);
	ListPopFront(phead);
	ListPrint1(phead);
	//ListPopFront(phead);

	ListPushFront(phead, 1);
	ListPushFront(phead, 2);
	ListPushFront(phead, 3);
	ListPushFront(phead, 4);
	ListPrint1(phead);
	LTDataType findData = 2;
	ListNode * pPos = ListFind(phead, findData);
	if (pPos == NULL)
	{
		printf("没找到\n");
	}
	else
	{
		pPos->data = 888;
		ListPrint1(phead);
		ListInsert(pPos, 666);
	}
	ListPrint1(phead);
	findData = 1;
	pPos = ListFind(phead, findData);
	if (pPos == NULL)
	{
		printf("没有找到\n");
	}
	else
	{
		ListErase(pPos);
	}
	ListPrint1(phead);
	ListDestroy(&phead);
}
void TestList2()
{
	printf("TestList2=====================\n");
	ListNode* phead = ListInit2();
	ListPushBack(phead, 1);
	ListPushBack(phead, 2);
	ListPushBack(phead, 3);
	ListPushBack(phead, 4);
	ListPrint2(phead);

	ListPopBack(phead);
	ListPrint2(phead);

	ListPopBack(phead);
	ListPrint2(phead);

	ListPopBack(phead);
	ListPrint2(phead);

	ListPopBack(phead);
	ListPrint2(phead);

	ListPopBack(phead);
	ListPrint2(phead);

	ListPushFront(phead, 1);
	ListPushFront(phead, 2);
	ListPushFront(phead, 3);
	ListPushFront(phead, 4);
	ListPrint2(phead);

	ListPopFront(phead);
	ListPrint2(phead);
	ListPopFront(phead);
	ListPrint2(phead);
	ListPopFront(phead);
	ListPrint2(phead);
	ListPopFront(phead);
	ListPrint2(phead);
	ListPopFront(phead);
}
int main()
{
	TestList1();
	//TestList2();
	return 0;
}