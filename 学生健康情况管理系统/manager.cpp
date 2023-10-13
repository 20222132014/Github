#include"manager.h"

void ListInit(List* ps)
{
	ps->a = NULL;
	ps->capacity = 0;
	ps->size = 0;
}
void ListCheckCapacity(List* ps)
{
	if (ps->size == ps->capacity)
	{
		int newcapacity = ps->capacity == 0 ? 4 : ps->capacity * 2;
		student* temp = new student[newcapacity];//�����¿ռ�
		if (temp == NULL)
		{
			cout << "����ʧ��" << endl;
			exit(-1);
		}
		else
		{
			memcpy(temp, ps->a, sizeof(student) * ps->size);		
			ps->a = temp;
			ps->capacity = newcapacity;
		}
	}
}
void ListAdd(List* ps, student stu)
{
	ListCheckCapacity(ps);
	ps->a[ps->size] = stu;
	ps->size++;
	cout << "��ӳɹ���" << endl;
}
void ListSub(List* ps,string id)
{
	int x = ListFind(ps, id)+1;
	while (x < ps->size)
	{
		ps->a[x - 1] = ps->a[x];
		x++;
	}
	ps->size--;
	cout << "ɾ���ɹ���" << endl;
}
int ListFind(List* ps, string id)
{
	for (int i = 0; i < ps->size; i++)
	{
		if (ps->a[i].StuId == id)
		{
			return i;
		}
	}
	return -1;
}
void ListPrint(List* ps)
{
	if (ps->size == 0)
	{
		cout << "����ѧ����Ϣ��";
		return;
	}
	for (int i = 0; i < ps->size; i++)
	{
		cout << "ѧ�ţ�" << ps->a[i].StuId << "������" << ps->a[i].Name 
			 <<"���գ�"<<ps->a[i].Birth << "�Ա�" << ps->a[i].Sex
			 << "����״����" << ps->a[i].Situation << endl;
	}
}
void StudentPrint(List* ps, int i)
{
	cout << "ѧ�ţ�" << ps->a[i].StuId << "������" << ps->a[i].Name
		<< "���գ�" << ps->a[i].Birth << "�Ա�" << ps->a[i].Sex
		<< "����״����" << ps->a[i].Situation << endl;
}
void List::save()
{
	ofstream ofs;
	ofs.open(FILENAME, ios::out);//������ķ�ʽ���ļ�---д�ļ�
	for (int i = 0; i < this->size; i++)
	{
		ofs << this->a[i].StuId << " "
			<< this->a[i].Name << " "
			<< this->a[i].Birth <<" "
			<< this->a[i].Sex<<" "
			<< this->a[i].Situation<<endl;
	}
	ofs.close();
	cout << "����ɹ���" << endl;
}
int getNum()
{
	string StuId;
	string Name;
	string Sex;
	string Situation;
	birthday Birth;
	ifstream ifs;
	ifs.open(FILENAME, ios::in);
	int num = 0;
	while (ifs >> StuId >> Name >> Birth  >> Sex >> Situation)
	{
		num++;
	}
	return num;
}
void List::Init()
{
	ifstream ifs;
	ifs.open(FILENAME, ios::in);
	string StuId;
	string Name;
	string Sex;
	string Situation;
	birthday Birth;
	int index = 0;
	while (ifs >> StuId && ifs >> Name && ifs >> Birth && ifs >>Sex  && ifs >>Situation )
	{
		this->a[index].StuId = StuId;
		this->a[index].Name = Name;
		this->a[index].Sex = Sex;
		this->a[index].Situation = Situation;
		this->a[index].Birth = Birth;
		index++;
	}
	ifs.close();
}
void List::load()
{
	//1.�ļ�������
	ifstream ifs;
	ifs.open(FILENAME, ios::in);
	if (!ifs.is_open())
	{
		cout << "�ļ�������" << endl;
		this->size = 0;
		this->a = NULL;
		ifs.close();
		return;
	}
	//2.�ļ����ڵ�����Ϊ��
	char ch;
	ifs >> ch;
	if (ifs.eof())//eof�����������β��
	{
		cout << "�ļ�Ϊ�գ�" << endl;
		this->size = 0;
		this->a = NULL;
		ifs.close();
		return;
	}
	//3.�ļ����ڣ����ұ���������
	int num = getNum();
	this->size = num;
	//���ٿռ�
	this->a = new student [this->size];
	this->capacity = num;
	//���ļ��е����ݣ��浽������
	List::Init();
	cout << "��ȡ�ɹ���" << endl;
}