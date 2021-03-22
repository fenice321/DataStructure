#ifndef __DLIST_H__
#define __DLIST_H__
//��ͷ˫��ѭ������,�ṹ����,������,һ�����������ʹ��,STL�е�list�������ֽṹ
typedef int LTDataType;
typedef struct _ListNode
{
	struct _ListNode* next;
	struct _ListNode* prev;
	LTDataType data;
} ListNode;
void ListInit1(ListNode** pphead);
//����������
ListNode* ListInit2();
//β��
void ListPushBack(ListNode* phead, LTDataType item);
//˳�����
void ListPrint1(ListNode* phead);
//�������
void ListPrint2(ListNode* phead);
//βɾ
void ListPopBack(ListNode* phead);
//ͷ��
void ListPushFront(ListNode* phead, LTDataType item);
//ͷɾ
void ListPopFront(ListNode* phead);
//��pos��ǰ����в���
void ListInsert(ListNode* pPos, LTDataType item);
//ɾ��posλ�õĽڵ�
void ListErase(ListNode* pPos);
//����
ListNode* ListFind(ListNode* phead, LTDataType findData);
//����
void ListDestroy1(ListNode* phead);
//��������
void ListDestroy(ListNode** pphead);
//�������
void ListClear(ListNode* phead);
#endif