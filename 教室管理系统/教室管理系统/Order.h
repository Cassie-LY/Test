#pragma once
#include <string>
#include <iostream>
#include "globalfile.h"
#include <fstream>
#include <map>
#include <string>

using namespace std;


class Order
{
public:
	//Ĭ�Ϲ���
	Order();
	
	//����ԤԼ��¼
	void updateorder();


	//ԤԼ����
	int size=0;

	//��¼����ԤԼ������  intΪ�ڼ�����mapΪ��ֵ����Ϣ
	map<int, map<string, string>>m_orderData;


};

