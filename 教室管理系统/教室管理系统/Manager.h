#pragma once
#include <iostream>
#include <vector>
#include "identity.h"
#include "Student.h"
#include "Teacher.h"
#include "Classroom.h"
using namespace std;


class Manager:public Identity
{
public:
	//Ĭ�Ϲ���
	Manager();

	//�вι���
	Manager(string id, string passwd, string name);

	//�˵�����
	virtual void openMenu();

	//�鿴����ԤԼ
	void showAllOrder();


	//����˺�
	void addAccount();

	//�鿴�˺�
	void showAccount();

	//���ԤԼ��¼
	void clearFile();

	//���ԤԼ
	void review();

	//����˺��ظ�
	bool checkRepeat(string id);

	//��ʼ������
	void initVector();

	//ѧ������
	vector<Student>vstu;
	//��ʦ����
	vector<Teacher>vtea;
	//��������
	vector<Classroom>vcla;


};

