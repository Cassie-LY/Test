#pragma once
#include <iostream>
using namespace std;


//�ײ���ݳ�����
class Identity
{
public:
	
	//�����˵�
	virtual void openMenu() = 0;

	//�˺�
	string id;
	//����
	string passwd;
	//����
	string name;
};