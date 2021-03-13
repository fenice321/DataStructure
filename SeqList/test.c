#define _CRT_SECURE_NO_WARNINGS 1
#include "SeqList.h"
void test1()
{
	SeqList s;
	SeqListInit(&s);
	SeqListPushBack(&s, 1);
	SeqListPushBack(&s, 2);
	SeqListPushBack(&s, 3);
	SeqListPushBack(&s, 4);
	SeqListPushBack(&s, 5);
	SeqListPushBack(&s, 6);
	SeqListPushBack(&s, 7);
	SeqListPushBack(&s, 8);
	SeqListPushBack(&s, 9);

	SeqListPrint(&s);

	SeqListPopBack(&s);
	SeqListPopBack(&s);

	SeqListPrint(&s);

	SeqListPushFront(&s, -10);
	SeqListPushFront(&s, 11);

	SeqListPrint(&s);

	SeqListPopFront(&s);
	SeqListPopFront(&s);
	SeqListPushFront(&s, 111);
	SeqListPrint(&s);

	int idx = SeqListBinaryFind(&s, 5);
	if (idx != -1)
		SeqListErase(&s, idx);
	SeqListPrint(&s);
	idx = SeqListFind(&s, 6);
	if (idx != -1)
		SeqListInsert(&s, idx, 888);
	SeqListPrint(&s);

	SeqListModifyByPos(&s, 0, 666);
	SeqListPrint(&s);

	SeqListModifyByVal(&s, 888, 99999);
	SeqListPrint(&s);

	SeqListDestroy(&s);
}
int main()
{
	test1();
	return 0;
}