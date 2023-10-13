#include"StuList.h"

StuNode* BuyNewNode(student x)
{
	StuNode* newnode = new StuNode;
	newnode->Stu = x;
	newnode->next = NULL;
	return newnode;
}
void ListInit(StuNode** List)
{
	 *List = NULL;
}

void StuPrint(student x)
{
	cout << "学号：" << x.StuId << "姓名：" << x.Name
		<< "生日：" << x.Birth << "性别：" << x.Sex
		<< "身体状况：" << x.Situation << endl;
}
void ListPrint(StuNode* phead)
{
	StuNode* cur = phead;
	if (cur == NULL)
	{
		cout << "暂无学生信息！" << endl;
	}
	while (cur != NULL)
	{
		cout << "学号：" << cur->Stu.StuId << "姓名：" << cur->Stu.Name
			<< "生日：" << cur->Stu.Birth << "性别：" << cur->Stu.Sex
			<< "身体状况：" << cur->Stu.Situation << endl;
		cur = cur->next;
	}
}
void ListAdd(StuNode** pphead, student x)
{
	StuNode* newnode = BuyNewNode(x);
	if (*pphead == NULL)
	{
		*pphead = newnode;
	}
	else
	{
		StuNode* tail = *pphead;
		while (tail->next != NULL)
		{
			tail = tail->next;
		}
		tail->next = newnode;
	}
	
}
StuNode* ListFind(StuNode* phead, string id)
{
	StuNode* cur = phead;
	while (cur != NULL)
	{
		if (cur->Stu.StuId == id)
		{
			return cur;
		}
		cur = cur->next;
	}
	return NULL;
}
void ListSub(StuNode** pphead, StuNode* pos)
{
	if (pos == NULL)
	{
		cout << "查无此人，删除失败！" << endl;
		return;
	}
	if (pos == *pphead)
	{
		StuNode* next = (*pphead)->next;
		delete* pphead;
		*pphead = next;
	}
	else
	{
		StuNode* prev = *pphead;
		while (prev ->next != pos)
		{
			prev = prev->next;
		}
		prev->next = pos->next;
		delete pos;
		cout << "删除成功！" << endl;
	}
}
void save(StuNode* phead)
{
	ofstream ofs;
	ofs.open(FILENAME, ios::out);
	StuNode* cur = phead;
	while (cur != NULL)
	{
		ofs << cur->Stu.StuId << " " << cur->Stu.Name
			<< " " << cur->Stu.Birth << " " << cur->Stu.Sex
			<< " " << cur->Stu.Situation << endl;
		cur = cur->next;
	}
	ofs.close();
	cout << "保存成功！" << endl;
}

void load(StuNode** pphead)
{
	ifstream ifs;
	ifs.open(FILENAME, ios::in);
	if (!ifs.is_open())
	{
		cout << "文件不存在" << endl;
		ifs.close();
		return;
	}
	char ch;
	ifs >> ch;
	if (ifs.eof())//eof代表读到函数尾了
	{
		cout << "文件为空！" << endl;
		ifs.close();
		return;
	}
	ifs.close();
	ifs.open(FILENAME, ios::in);
	StuNode* cur = *pphead;
	student s;
	while (ifs >> s.StuId && ifs >> s.Name && ifs >> s.Birth && ifs >> s.Sex && ifs >> s.Situation)
	{
		ListAdd(pphead, s);
	}
	ifs.close();
	cout << "读取成功！" << endl;
}