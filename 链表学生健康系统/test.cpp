#include"StuList.h"
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
			cout << "�½��ɹ���" << endl;
			system("pause");
			system("cls");
			break;
		case 2:
			cout << "����������ѧ����ѧ�š��������������ڡ��Ա�����״��" << endl;	
			cin >> x.StuId >> x.Name >> x.Birth >> x.Sex >> x.Situation;
			ListAdd(&List, x);
			cout << "��ӳɹ���" << endl;
			system("pause");
			system("cls");
			break;
		case 3:
			cout << "������Ҫɾ����ѧ����ѧ�ţ�" << endl;
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
			cout << "������Ҫ���ҵ�ѧ����ѧ�ţ�" << endl;
			cin >> sid;
			pos = ListFind(List, sid);
			if (pos != NULL)
			{
				cout << "���ҳɹ���ѧ����Ϣ���£�" << endl;
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
			cout << "�����������������" << endl;
			system("pause");
			system("cls");
			break;
		}
	}
	
	
	return 0;
}