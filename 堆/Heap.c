#include"Heap.h"
//这个是小堆
void Swap(HPDataType* p1, HPDataType* p2)
{
	HPDataType tmp = *p1;
	*p1 = *p2;
	*p2 = tmp;
}
void AdjustUp(HPDataType* a,int child)//向上调整
{
	int parent = (child - 1) / 2;
	while (child > 0)
	{
		if (a[child] > a[parent])
		{
			Swap(&a[child], &a[parent]);
			child = parent;
			parent = (parent - 1) / 2;
		}
		else
		{
			break;
		}
	}
}
void AdjustDown(HPDataType* a, int n, int parent)//向下调整
{
	int child = parent * 2 + 1;
	while (child < n)
	{
		if (child + 1 < n && a[child + 1] > a[child])
		{
			++child;
		}
		if (a[child] > a[parent])
		{
			Swap(&a[child], &a[parent]);
			parent = child;
			child = parent * 2 + 1;
		}
		else
		{
			break;
		}
	}
}
void HeapCreate(Heap* hp, HPDataType* a, int n)
{
	assert(hp);
	assert(a);
	hp->_a = (HPDataType*)malloc(sizeof(HPDataType)*n);
	if (hp->_a == NULL)
	{
		printf("malloc fail\n");
		exit(-1);
	}
	hp->_size = n;
	hp->_capacity = n;
	memcpy(hp->_a, a, sizeof(HPDataType) * n);
	for (int i = 1; i < n; i++)
	{
		AdjustUp(hp->_a, i);
	}
}
void HeapDestory(Heap* hp)
{
	assert(hp);
	free(hp->_a);
	hp->_a = NULL;
	hp->_size = hp->_capacity = 0;
}
void HeapPush(Heap* hp, HPDataType x)
{
	assert(hp);
	if (hp->_size == hp->_capacity)
	{
		int newCapacity = hp->_capacity == 0 ? 4 : hp->_capacity * 2;
		HPDataType* tmp = (HPDataType*)realloc(hp->_a, sizeof(HPDataType) * newCapacity);
		if (tmp == NULL)
		{
			printf("realloc fail\n");
			exit(-1);
		}
		hp->_a = tmp;
		hp->_capacity = newCapacity;
	}
	hp->_a[hp->_size] = x;
	hp->_size++;
	AdjustUp(hp->_a, hp->_size - 1);
}
void HeapPop(Heap* hp)
{
	assert(hp);
	assert(hp->_size > 0);
	Swap(&hp->_a[0], &hp->_a[hp->_size - 1]);
	hp->_size--;
	AdjustDown(hp->_a, hp->_size, 0);
}
HPDataType HeapTop(Heap* hp)
{
	assert(hp);
	assert(hp->_size > 0);
	return hp->_a[0];
}
int HeapSize(Heap* hp)
{
	assert(hp);
	return hp->_size;
}
int HeapEmpty(Heap* hp)
{
	assert(hp);
	assert(hp->_size > 0);
	return hp->_size == 0;
}