#ifndef __SLIST_H__
#define __SLIST_H__
//SList意为single list单向链表
//本工程做的是一个不带头结点的单向链表
typedef int SListDataType;
//结点
typedef struct _SListNode
{
	SListDataType data;
	struct _SListNode* next;
} SListNode;
//初始化头指针
void SListNodePointerInit(SListNode** ppList);
//尾插
void SListPushBack(SListNode** ppList, SListDataType item);
//尾删
void SListPopBack(SListNode** ppList);
//头插---不带头结点的单向链表头插需要更新头指针的指向
void SListPushFront(SListNode** ppList, SListDataType item);
//头删---不带头结点的单向链表头删需要更新头指针的指向
void SListPopFront(SListNode** ppList);
//遍历单链表
void SListTraverse(SListNode* pList);
//单链表长度---即结点个数
size_t SListLength(SListNode* pList);
//单链表查找
SListNode* SListNodeFind(SListNode* pList, SListDataType findData);
//单链表指定节点位置插入
void SListNodeInsertAfter(SListNode* pos, SListDataType item);
//单链表指定节点位置删除
void SListNodeEraseAfter(SListNode* pos);
//反转单链表
void SListNodeReverse(SListNode** ppList);
//链表销毁
void SListNodeDestroy(SListNode* pList);
#endif //__SLIST_H__