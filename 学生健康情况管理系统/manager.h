#include"student.h"
#include<fstream>
#define FILENAME "List.txt"
typedef struct List
{
	student* a;
	int size;
	int capacity;
	void save();
	void load();
	void Init();
}List;

void ListInit(List* ps);
void ListAdd(List* ps, student stu);
void ListSub(List* ps, string id);
int ListFind(List* ps, string id);
void ListPrint(List* ps);
void StudentPrint(List* ps, int i);

