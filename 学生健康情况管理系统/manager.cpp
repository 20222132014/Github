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
		student* temp = new student[newcapacity];//开辟新空间
		if (temp == NULL)
		{
			cout << "扩容失败" << endl;
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
	cout << "添加成功！" << endl;
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
	cout << "删除成功！" << endl;
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
		cout << "暂无学生信息！";
		return;
	}
	for (int i = 0; i < ps->size; i++)
	{
		cout << "学号：" << ps->a[i].StuId << "姓名：" << ps->a[i].Name 
			 <<"生日："<<ps->a[i].Birth << "性别：" << ps->a[i].Sex
			 << "身体状况：" << ps->a[i].Situation << endl;
	}
}
void StudentPrint(List* ps, int i)
{
	cout << "学号：" << ps->a[i].StuId << "姓名：" << ps->a[i].Name
		<< "生日：" << ps->a[i].Birth << "性别：" << ps->a[i].Sex
		<< "身体状况：" << ps->a[i].Situation << endl;
}
void List::save()
{
	ofstream ofs;
	ofs.open(FILENAME, ios::out);//用输出的方式打开文件---写文件
	for (int i = 0; i < this->size; i++)
	{
		ofs << this->a[i].StuId << " "
			<< this->a[i].Name << " "
			<< this->a[i].Birth <<" "
			<< this->a[i].Sex<<" "
			<< this->a[i].Situation<<endl;
	}
	ofs.close();
	cout << "保存成功！" << endl;
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
	//1.文件不存在
	ifstream ifs;
	ifs.open(FILENAME, ios::in);
	if (!ifs.is_open())
	{
		cout << "文件不存在" << endl;
		this->size = 0;
		this->a = NULL;
		ifs.close();
		return;
	}
	//2.文件存在但数据为空
	char ch;
	ifs >> ch;
	if (ifs.eof())//eof代表读到函数尾了
	{
		cout << "文件为空！" << endl;
		this->size = 0;
		this->a = NULL;
		ifs.close();
		return;
	}
	//3.文件存在，并且保存着数据
	int num = getNum();
	this->size = num;
	//开辟空间
	this->a = new student [this->size];
	this->capacity = num;
	//将文件中的数据，存到数组中
	List::Init();
	cout << "读取成功！" << endl;
}