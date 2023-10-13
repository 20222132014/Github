#include"student.h"
student::student(string id, string name, string sex, string situation,birthday birth)
{
	this->StuId = id;
	this->Name = name;
	this->Sex = sex;
	this->Situation = situation;
	this->Birth = birth;
}
student::student(){}
ostream& operator<<(ostream& cout, birthday& b)
{
	cout << b.year << " " << b.month << " " << b.day;
	return cout;
}
istream& operator>>(istream& cin, birthday& b)
{
	cin >> b.year >> b.month >> b.day;
	return cin;
}