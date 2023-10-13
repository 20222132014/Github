#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<string>
using namespace std;
class birthday
{
public:
	int year;
	int month;
	int day;
};
class student
{
public:
	
	string StuId;
	string Name;
	string Sex;
	string Situation;
	birthday Birth;
	student();
	student(string id, string name, string sex, string situation,birthday birth);
};
 ostream& operator<<(ostream& cout, birthday& b);
istream& operator>>(istream& cin, birthday& b);