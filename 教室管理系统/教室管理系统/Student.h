#pragma once
#include <iostream>
#include <vector>
#include "identity.h"
#include "Order.h"
#include "Classroom.h"
using namespace std;

class Student:public Identity
{
public:
	//Ĭ�Ϲ���
	Student();
	
	//�вι���
	Student(string id, string passwd, string name);

	//�˵�����
	virtual void openMenu();

	//����ԤԼ
	void applyOrder();

	//�鿴����ԤԼ
	void showSelf();

	//�鿴����ԤԼ
	void showAllOrder();

	//ȡ��ԤԼ
	void canceOrder();

	//ѧ������
	string name;

	//��������
	vector<Classroom>vcla;

	//ԤԼ����
	vector<Order>vorder;
};

