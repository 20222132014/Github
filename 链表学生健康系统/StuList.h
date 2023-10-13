#pragma once
#include"student.h"
#include<fstream>
#define FILENAME "List.txt"
typedef struct StuNode
{
	student Stu;
	StuNode* next;
}StuNode;

void ListInit(StuNode** phead);//新建链表
StuNode* BuyNewNode(student x);//创建一个新节点
void ListAdd(StuNode** pphead, student x);//添加一个节点
StuNode* ListFind(StuNode* pphead, string id);//查找节点，返回节点的地址
void ListSub(StuNode** pphead, StuNode* pos);//删除节点
void ListPrint(StuNode* phead);//打印链表中所有学生信息
void StuPrint(student x);//打印一个学生的信息
void save(StuNode* phead);//保存信息到文件中
void load(StuNode**pphead);//从文件中读取信息