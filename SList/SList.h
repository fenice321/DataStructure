#ifndef __SLIST_H__
#define __SLIST_H__
//SList��Ϊsingle list��������
//������������һ������ͷ���ĵ�������
typedef int SListDataType;
//���
typedef struct _SListNode
{
	SListDataType data;
	struct _SListNode* next;
} SListNode;
//��ʼ��ͷָ��
void SListNodePointerInit(SListNode** ppList);
//β��
void SListPushBack(SListNode** ppList, SListDataType item);
//βɾ
void SListPopBack(SListNode** ppList);
//ͷ��---����ͷ���ĵ�������ͷ����Ҫ����ͷָ���ָ��
void SListPushFront(SListNode** ppList, SListDataType item);
//ͷɾ---����ͷ���ĵ�������ͷɾ��Ҫ����ͷָ���ָ��
void SListPopFront(SListNode** ppList);
//����������
void SListTraverse(SListNode* pList);
//��������---��������
size_t SListLength(SListNode* pList);
//���������
SListNode* SListNodeFind(SListNode* pList, SListDataType findData);
//������ָ���ڵ�λ�ò���
void SListNodeInsertAfter(SListNode* pos, SListDataType item);
//������ָ���ڵ�λ��ɾ��
void SListNodeEraseAfter(SListNode* pos);
//��ת������
void SListNodeReverse(SListNode** ppList);
//��������
void SListNodeDestroy(SListNode* pList);
#endif //__SLIST_H__