#include"manager.h"


void menu()
{
	cout << "1.�½�ѧ��������" << endl;
	cout << "2.����ѧ����Ϣ" << endl;
	cout << "3.ɾ��ѧ����Ϣ" << endl;
	cout << "4.���ļ��ж�ȡ��������Ϣ" << endl;
	cout << "5.���ļ�д��ѧ����������Ϣ" << endl;
	cout << "6.��ѯѧ����Ϣ����ѧ��ѧ�������в��ң�" << endl;
	cout << "7.���ȫ��ѧ����Ϣ" << endl;
	cout << "8.�˳�" << endl;
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
			cout << "�½��ɹ���" << endl;
			system("pause");
			system("cls");
			break;
		case 2:
			cout << "����������ѧ����ѧ�š��������������ڡ��Ա�����״��" << endl;
			cin >> s.StuId >> s.Name >> s.Birth >> s.Sex >> s.Situation;
			ListAdd(&LT, s);
			system("pause");
			system("cls");
			break;
		case 3:
			cout << "������Ҫɾ����ѧ����ѧ�ţ�" << endl;
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
			cout << "������Ҫ��ѯ��ѧ����ѧ�ţ�" << endl;
			cin >> sid;
			 ans = ListFind(&LT, sid);
			if (ans != -1)
			{
				cout << "��ѯ�ɹ���ѧ����Ϣ���£�" << endl;
				StudentPrint(&LT, ans);
			}
			else
			{
				cout << "��ѯʧ�ܣ�ѧ����Ϣ�����ڣ�" << endl;
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
			cout << "�����������������" << endl;
			system("pause");
			system("cls");
			break;
		}
	}
	return 0;
}