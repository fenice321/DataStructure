#define _CRT_SECURE_NO_WARNINGS 1
#include "DList.h"
#include <stdio.h>
#include <vld.h>

//������,10����֮��д��һ��˫��ѭ������
//��:��д�ṹ��,�ٳ�ʼ������,дɾ����ǰ�ڵ�ӿں͵�ǰ�ڵ�ǰһ���ڵ����ӿ�,Ȼ���ó�ͷ��,ͷɾ,β��,βɾ,���,����,��ӡ

//������:�����˳���(����)֮����������ϵ��ʲô
//��:˳�������������,β��,βɾЧ�ʸ�O(1),ͷ��ͷɾ,�м����ɾ����ҪŲ������Ч�ʲ���O(N),���������ʸ�,��������ʱ
//�����ݺ��п����пռ��˷�,���ݴ�����ʱ�俪����,����---�����ռ�(һ�ζ������˷ѿռ�)��ȡʱ��(���ݴ�������)

//����,һ��ָ��ͷ˫��ѭ������,����λ�ò���ɾ��Ч�ʶ��ܸ�O(1),���������ʲ���,ָ�������Ŀռ�,�����������,һ�������
//������Ƭ�ռ�,��һ�������С�Ľڵ�ռ䱻��������ڴ���Ƭ����

//�����˳�����ȱ���ǻ�����
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
		printf("û�ҵ�\n");
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
		printf("û���ҵ�\n");
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