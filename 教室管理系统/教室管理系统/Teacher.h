#pragma once
#include <iostream>
#include <vector>
#include "Classroom.h"
#include "Order.h"
#include "identity.h"
using namespace std;

class Teacher :public Identity
{
public:
	//Ĭ�Ϲ���
	Teacher();

	//�вι���
	Teacher(string id, string passwd, string name);

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

	//��ʦ����
	string name;

	//��������
	vector<Classroom>vcla;

	//ԤԼ����
	vector<Order>vorder;




};