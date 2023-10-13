#include"manager.h"


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
	List LT;
	student s;
	string sid;
	int ans = 0;
	while (input != 8)
	{
		menu();
		cin >> input;
		switch (input)
		{
		case 1:		
			ListInit(&LT);
			cout << "新建成功！" << endl;
			system("pause");
			system("cls");
			break;
		case 2:
			cout << "请依次输入学生的学号、姓名、出生日期、性别、身体状况" << endl;
			cin >> s.StuId >> s.Name >> s.Birth >> s.Sex >> s.Situation;
			ListAdd(&LT, s);
			system("pause");
			system("cls");
			break;
		case 3:
			cout << "请输入要删除的学生的学号：" << endl;
			cin >> sid;
			ListSub(&LT, sid);
			system("pause");
			system("cls");
			break;
		case 4:LT.load();
			system("pause");
			system("cls");
			break;
		case 5:LT.save();
			system("pause");
			system("cls");
			break;
		case 6:
			cout << "请输入要查询的学生的学号：" << endl;
			cin >> sid;
			 ans = ListFind(&LT, sid);
			if (ans != -1)
			{
				cout << "查询成功！学生信息如下：" << endl;
				StudentPrint(&LT, ans);
			}
			else
			{
				cout << "查询失败，学生信息不存在！" << endl;
			}
			system("pause");
			system("cls");
			break;
		case 7:
			ListPrint(&LT);
			system("pause");
			system("cls");
			break;
		case 8:break;
		default:
			cout << "输入错误，请重新输入" << endl;
			system("pause");
			system("cls");
			break;
		}
	}
	return 0;
}