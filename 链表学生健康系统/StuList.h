#pragma once
#include"student.h"
#include<fstream>
#define FILENAME "List.txt"
typedef struct StuNode
{
	student Stu;
	StuNode* next;
}StuNode;

void ListInit(StuNode** phead);//�½�����
StuNode* BuyNewNode(student x);//����һ���½ڵ�
void ListAdd(StuNode** pphead, student x);//���һ���ڵ�
StuNode* ListFind(StuNode* pphead, string id);//���ҽڵ㣬���ؽڵ�ĵ�ַ
void ListSub(StuNode** pphead, StuNode* pos);//ɾ���ڵ�
void ListPrint(StuNode* phead);//��ӡ����������ѧ����Ϣ
void StuPrint(student x);//��ӡһ��ѧ������Ϣ
void save(StuNode* phead);//������Ϣ���ļ���
void load(StuNode**pphead);//���ļ��ж�ȡ��Ϣ