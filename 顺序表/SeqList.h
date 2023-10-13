#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include<string.h>
typedef int SQDatatype;
typedef struct SeqList
{
	SQDatatype* a;
	int size;//有效数据的个数
	int capacity;//容量
}SL;
void SeqListInit(SL* ps);
void SeqListPrint(SL* ps);
void SeqListDestory(SL* ps);

void SeqListPushBack(SL* ps, SQDatatype x);
void SeqListPushFront(SL* ps, SQDatatype x);
void SeqListPopBack(SL* ps);
void SeqListPopFront(SL* ps);

void SeqListInsert(SL* ps, int pos, SQDatatype x);
void SeqListErase(SL* ps, int pos);
int SeqListFind(SL* ps, SQDatatype x);
void SeqListModify(SL* ps, int pos, SQDatatype x);