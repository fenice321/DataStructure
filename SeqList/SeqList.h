#ifndef __SEQLIST_H__
#define __SEQLIST_H__

//˳���Ҫ����Ч�����������б�����������
//��̬˳�������(�̶���С,���ܰ�����ȡ)
//typedef int SLDataType;
//#define N 10
////C++��STL���е�vector����˳���
//struct SeqList
//{
//	SLDataType _a[N];
//	int size;
//};

//��̬˳���---��vector��ԭ��---��С�ɱ�
#include <stdio.h>
#include <stdbool.h>
#define DEFAULT_SEQLIST_CAPACITY 4
typedef int SLDataType;
typedef struct _SeqList
{
	SLDataType* base;//ָ��̬���ٵ�����
	size_t size;	 //��Ч���ݵĸ���
	size_t capacity; //�����ռ�Ĵ�С
} SeqList;
//��ʼ��
void SeqListInit(SeqList* ps);
//��ӡ˳�������
void SeqListPrint(SeqList* ps);
//β��
void SeqListPushBack(SeqList* ps, SLDataType item);
//ͷ��
void SeqListPushFront(SeqList* ps, SLDataType item);
//βɾ
void SeqListPopBack(SeqList* ps);
//ͷɾ
void SeqListPopFront(SeqList* ps);
//����λ�ò�������
void SeqListInsert(SeqList* ps, size_t pos, SLDataType item);
//����λ��ɾ������
void SeqListErase(SeqList* ps, size_t pos);
//˳������
int SeqListFind(SeqList* ps, SLDataType findData);
//˳�������
void SeqListBubbleSort(SeqList* ps);
//˳�����ֲ���
int SeqListBinaryFind(SeqList* ps, SLDataType findData);
//˳�������
void SeqListDestroy(SeqList* ps);
//˳����޸�
bool SeqListModifyByPos(SeqList* ps, size_t pos, SLDataType value);
bool SeqListModifyByVal(SeqList* ps, SLDataType findData, SLDataType value);
#endif // !__SEQLIST_H__
