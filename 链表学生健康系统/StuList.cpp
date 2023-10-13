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
	cout << "ѧ�ţ�" << x.StuId << "������" << x.Name
		<< "���գ�" << x.Birth << "�Ա�" << x.Sex
		<< "����״����" << x.Situation << endl;
}
void ListPrint(StuNode* phead)
{
	StuNode* cur = phead;
	if (cur == NULL)
	{
		cout << "����ѧ����Ϣ��" << endl;
	}
	while (cur != NULL)
	{
		cout << "ѧ�ţ�" << cur->Stu.StuId << "������" << cur->Stu.Name
			<< "���գ�" << cur->Stu.Birth << "�Ա�" << cur->Stu.Sex
			<< "����״����" << cur->Stu.Situation << endl;
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
		cout << "���޴��ˣ�ɾ��ʧ�ܣ�" << endl;
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
		cout << "ɾ���ɹ���" << endl;
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
	cout << "����ɹ���" << endl;
}

void load(StuNode** pphead)
{
	ifstream ifs;
	ifs.open(FILENAME, ios::in);
	if (!ifs.is_open())
	{
		cout << "�ļ�������" << endl;
		ifs.close();
		return;
	}
	char ch;
	ifs >> ch;
	if (ifs.eof())//eof�����������β��
	{
		cout << "�ļ�Ϊ�գ�" << endl;
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
	cout << "��ȡ�ɹ���" << endl;
}