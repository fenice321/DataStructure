#ifndef __SEQLIST_H__
#define __SEQLIST_H__

//顺序表要求有效数据在数组中必须是连续的
//静态顺序表的设计(固定大小,不能按需索取)
//typedef int SLDataType;
//#define N 10
////C++中STL库中的vector就是顺序表
//struct SeqList
//{
//	SLDataType _a[N];
//	int size;
//};

//动态顺序表---是vector的原型---大小可变
#include <stdio.h>
#include <stdbool.h>
#define DEFAULT_SEQLIST_CAPACITY 4
typedef int SLDataType;
typedef struct _SeqList
{
	SLDataType* base;//指向动态开辟的数组
	size_t size;	 //有效数据的个数
	size_t capacity; //容量空间的大小
} SeqList;
//初始化
void SeqListInit(SeqList* ps);
//打印顺序表内容
void SeqListPrint(SeqList* ps);
//尾插
void SeqListPushBack(SeqList* ps, SLDataType item);
//头插
void SeqListPushFront(SeqList* ps, SLDataType item);
//尾删
void SeqListPopBack(SeqList* ps);
//头删
void SeqListPopFront(SeqList* ps);
//任意位置插入数据
void SeqListInsert(SeqList* ps, size_t pos, SLDataType item);
//任意位置删除数据
void SeqListErase(SeqList* ps, size_t pos);
//顺序表查找
int SeqListFind(SeqList* ps, SLDataType findData);
//顺序表排序
void SeqListBubbleSort(SeqList* ps);
//顺序表二分查找
int SeqListBinaryFind(SeqList* ps, SLDataType findData);
//顺序表销毁
void SeqListDestroy(SeqList* ps);
//顺序表修改
bool SeqListModifyByPos(SeqList* ps, size_t pos, SLDataType value);
bool SeqListModifyByVal(SeqList* ps, SLDataType findData, SLDataType value);
#endif // !__SEQLIST_H__
