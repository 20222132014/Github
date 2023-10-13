#include"StuList.h"
void menu()
{
	cout << "1.新建学生健康表" << endl;
	cout << "2.插入学生信息" << endl;
	cout << "3.删除学生信息" << endl;
	cout << "4.从文件中读取健康表信息" << endl;
	cout << "5.向文件写入学生健康表信息" << endl;
	cout << "6.查询学生信息（按学生学号来进行查找）" << endl;
	cout << "7.输出全部学生信息" << endl;
	cout << "8.退出" << endl;
}
int main()
{
	int input = 0;
	StuNode* List = NULL;
	StuNode* pos = NULL;
	student x;
	string sid;
	while (input != 8)
	{
		menu();
		cin >> input;
		switch (input)
		{
		case  1:
			ListInit(&List);
			cout << "新建成功！" << endl;
			system("pause");
			system("cls");
			break;
		case 2:
			cout << "请依次输入学生的学号、姓名、出生日期、性别、身体状况" << endl;	
			cin >> x.StuId >> x.Name >> x.Birth >> x.Sex >> x.Situation;
			ListAdd(&List, x);
			cout << "添加成功！" << endl;
			system("pause");
			system("cls");
			break;
		case 3:
			cout << "请输入要删除的学生的学号：" << endl;
			cin >> sid;
			pos = ListFind(List, sid);
			ListSub(&List, pos);
			system("pause");
			system("cls");
			break;
		case 4:
			load(&List);
			system("pause");
			system("cls");
			break;
		case 5:
			save(List);
			system("pause");
			system("cls");
			break;
		case 6:
			cout << "请输入要查找的学生的学号：" << endl;
			cin >> sid;
			pos = ListFind(List, sid);
			if (pos != NULL)
			{
				cout << "查找成功！学生信息如下：" << endl;
				StuPrint(pos->Stu);
			}
			system("pause");
			system("cls");
			break;
		case 7:
			ListPrint(List);
			system("pause");
			system("cls");
			break;
		case 8:
			break;
		default:
			cout << "输入错误，请重新输入" << endl;
			system("pause");
			system("cls");
			break;
		}
	}
	
	
	return 0;
}