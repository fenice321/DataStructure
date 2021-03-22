#ifndef __DLIST_H__
#define __DLIST_H__
//带头双向循环链表,结构复杂,操作简单,一般用于链表的使用,STL中的list就是这种结构
typedef int LTDataType;
typedef struct _ListNode
{
	struct _ListNode* next;
	struct _ListNode* prev;
	LTDataType data;
} ListNode;
void ListInit1(ListNode** pphead);
//创建空链表
ListNode* ListInit2();
//尾插
void ListPushBack(ListNode* phead, LTDataType item);
//顺序遍历
void ListPrint1(ListNode* phead);
//逆序遍历
void ListPrint2(ListNode* phead);
//尾删
void ListPopBack(ListNode* phead);
//头插
void ListPushFront(ListNode* phead, LTDataType item);
//头删
void ListPopFront(ListNode* phead);
//在pos的前面进行插入
void ListInsert(ListNode* pPos, LTDataType item);
//删除pos位置的节点
void ListErase(ListNode* pPos);
//查找
ListNode* ListFind(ListNode* phead, LTDataType findData);
//销毁
void ListDestroy1(ListNode* phead);
//销毁链表
void ListDestroy(ListNode** pphead);
//清空链表
void ListClear(ListNode* phead);
#endif