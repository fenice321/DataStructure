#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <errno.h>
#include <string.h>
#include <assert.h>
#include <stdlib.h>
#include <stdbool.h>
#include "SeqList.h"
void SeqListInit(SeqList* ps)
{
	assert(ps != NULL);
	ps->base = (SLDataType*)malloc(DEFAULT_SEQLIST_CAPACITY * sizeof(SLDataType));
	if (ps->base == NULL)
	{
		puts(strerror(errno));
		exit(-1);
	}
	ps->capacity = DEFAULT_SEQLIST_CAPACITY;
	ps->size = 0;
}
void SeqListPrint(SeqList* ps)
{
	assert(ps != NULL);
	for (size_t i = 0; i < ps->size; i++)
	{
		printf("%d ", ps->base[i]);
	}
	puts("");
}
static bool IsFull(SeqList* ps)//����
{
	assert(ps != NULL);
	return ps->size == ps->capacity;
}
static bool IsEmpty(SeqList* ps)//�п�
{
	assert(ps != NULL);
	return ps->size == 0;
}
static void SeqListCheckCapacity(SeqList* ps)//���˳����Ƿ���,������������
{
	assert(ps != NULL);
	if (IsFull(ps))
	{
		ps->capacity *= 2;
		SLDataType* p = (SLDataType*)realloc(ps->base, ps->capacity * sizeof(SLDataType));
		if (NULL == p)
		{
			free(ps->base);
			puts(strerror(errno));
			exit(-1);
		}
		ps->base = p;
	}
}
void SeqListPushBack(SeqList* ps, SLDataType item)
{
	assert(ps != NULL);
	SeqListCheckCapacity(ps);
	ps->base[ps->size] = item;
	ps->size++;
	//SeqListInsert(ps, ps->size, item);//��Ӳ�������λ�õĲ�������
}
void SeqListPushFront(SeqList* ps, SLDataType item)
{
	assert(ps != NULL);
	SeqListCheckCapacity(ps);
	for (size_t i = ps->size; i > 0; i--)
	{
		ps->base[i] = ps->base[i - 1];
	}
	ps->base[0] = item;
	ps->size++;
	//SeqListInsert(ps, 0, item);//��Ӳ�������λ�õĲ�������
}
void SeqListPopBack(SeqList* ps)
{
	assert(ps != NULL);
	if (IsEmpty(ps))
	{
		printf("˳����ѿ�, βɾʧ��!\n");
	}
	else
	{
		ps->size--;
		//SeqListErase(ps, ps->size - 1);//��Ӳ��԰�����λ��ɾ����������ȷ
	}
}
void SeqListPopFront(SeqList* ps)
{
	assert(ps != NULL);
	if (IsEmpty(ps))
	{
		printf("˳����ѿ�,�޷�����ͷ��ɾ��!\n");
	}
	else
	{
		for (size_t i = 1; i < ps->size; ++i)
		{
			ps->base[i - 1] = ps->base[i];
		}
		--ps->size;
		//SeqListErase(ps, 0);//��Ӳ��԰�����λ��ɾ����������ȷ��
	}
}
void SeqListInsert(SeqList* ps, size_t pos, SLDataType item)
{
	assert(ps != NULL);
	SeqListCheckCapacity(ps);
	if (pos > ps->size)
	{
		printf("����λ��pos�Ƿ�,������λ�ò�������ʧ��!\n");
	}
	else
	{
		for (size_t i = ps->size; i > pos; i--)
		{
			ps->base[i] = ps->base[i - 1];
		}
		ps->base[pos] = item;
		++ps->size;
	}
}
void SeqListErase(SeqList* ps, size_t pos)
{
	assert(ps != NULL);
	if (IsEmpty(ps))
	{
		printf("˳����ѿ�,����λ��ɾ������ʧ��\n");
	}
	else if (pos >= ps->size)
	{
		printf("˳���ɾ��λ�÷Ƿ�,������λ��ɾ������ʧ��\n");
	}
	else
	{
		for (size_t i = pos; i < ps->size - 1; ++i)
		{
			ps->base[i] = ps->base[i + 1];
		}
		--ps->size;
	}
}
int SeqListFind(SeqList* ps, SLDataType findData)
{
	assert(ps != NULL);
	for (size_t i = 0; i < ps->size; i++)
	{
		if (findData == ps->base[i])
			return i;
	}
	return -1;
}
static void mySwap(SLDataType* p, SLDataType* q)
{
	assert(p != NULL && q != NULL);
	SLDataType tmp = *p;
	*p = *q;
	*q = tmp;
}
void SeqListBubbleSort(SeqList* ps)
{
	assert(ps != NULL);
	int flag = 0;
	for (size_t i = 0; i < ps->size - 1; i++)
	{
		flag = 0;
		for (size_t j = 0; j < ps->size - 1 - i; j++)
		{
			if (ps->base[j] > ps->base[j + 1])
			{
				mySwap(&ps->base[j], &ps->base[j + 1]);
				flag = 1;
			}
		}
		if (flag == 0)
		{
			break;
		}
	}
}
int SeqListBinaryFind(SeqList* ps, SLDataType findData)
{
	assert(ps != NULL);
	SeqListBubbleSort(ps);
	int mid = 0;
	int left = 0;
	int right = ps->size;
	while (left < right)
	{
		mid = (left & right) + ((left ^ right) >> 1);
		if (ps->base[mid] == findData)
			return mid;
		else if (ps->base[mid] > findData)
			right = mid;
		else
			left = mid + 1;
	}
	return -1;
}
void SeqListDestroy(SeqList* ps)
{
	assert(ps != NULL);
	free(ps->base);
	ps->base = NULL;
	ps->size = 0;
	ps->capacity = 0;
}
bool SeqListModifyByPos(SeqList* ps, size_t pos, SLDataType value)
{
	assert(ps != NULL);
	if (pos >= ps->size)
		return false;
	else
	{
		ps->base[pos] = value;
		return true;
	}
}
bool SeqListModifyByVal(SeqList* ps, SLDataType findData, SLDataType value)
{
	assert(ps != NULL);
	int idx = SeqListFind(ps, findData);
	if (-1 == idx)
		return false;
	else
	{
		ps->base[idx] = value;
		return true;
	}
}