#define _CRT_SECURE_NO_WARNINGS 1
#include"SeqList.h"
void SeqListInit(SL* ps)
{
	ps->a = NULL;
	ps->capacity = 0;
	ps->size = 0;
}
void SeqListCheckCapacity(SL* ps)
{
	if (ps->size == ps->capacity)
	{
		int newcapacity = ps->capacity == 0 ? 4 : ps->capacity * 2;
		SQDatatype* temp = (SQDatatype*)realloc(ps->a, newcapacity * sizeof(SQDatatype));
		if (temp == NULL)
		{
			printf("À©ÈÝÊ§°Ü£¡\n");
			exit(-1);
		}
		else
		{
			ps->a = temp;
			ps->capacity = newcapacity;
		}
	}
}
void SeqListPrint(SL* ps)
{
	for (int i = 0; i < ps->size; ++i)
	{
		printf("%d ", ps->a[i]);
	}
	printf("\n");
}
void SeqListDestory(SL* ps)
{
	free(ps->a);
	ps->a = NULL;
	ps->capacity = ps->size = 0;
}

void SeqListPushBack(SL* ps, SQDatatype x)
{
	SeqListInsert(ps, ps->size, x);
}
void SeqListPushFront(SL* ps, SQDatatype x)
{
	SeqListInsert(ps, 0, x);
}
void SeqListPopBack(SL* ps)
{
	SeqListErase(ps, ps->size-1);
}
void SeqListPopFront(SL* ps)
{
	SeqListErase(ps, 0);
}

void SeqListInsert(SL* ps, int pos, SQDatatype x)
{
	assert(pos <= ps->size);
	SeqListCheckCapacity(ps);
	int end = ps->size - 1;
	while (end >= pos)
	{
		ps->a[end + 1] = ps->a[end];
		--end;
	}
	ps->a[pos] = x;
	ps->size++;
}
void SeqListErase(SL* ps, int pos)
{
	assert(pos < ps->size);
	int start = pos + 1;
	while (start < ps->size)
	{
		ps->a[start - 1] = ps->a[start];
		start++;
	}
	ps->size--;
}
int SeqListFind(SL* ps, SQDatatype x)
{
	for (int i = 0; i < ps->size; i++)
	{
		if (ps->a[i] == x)return i;
	}
	return -1;
}
void SeqListModify(SL* ps, int pos, SQDatatype x)
{
	ps->a[pos] = x;
}