#include"Sort.h"
#include<string.h>
int main()
{
	int a[] = { 1,5,6,7,8,4,2,9,3 };
	HeapSort(a, 9);
	for (int i = 0; i < 9; i++)
	{
		printf("%d ", a[i]);
	}
	return 0;
}