#include "Manager.h"
#include <iostream>
#include <fstream>
#include "globalfile.h"
#include <algorithm>

//����showAccount�ص�
void printStudent(Student& s)
{
	cout << "ѧ�ţ�" << s.id << "     ������" << s.name << "    ���룺" << s.passwd << endl;
}
void printTeacher(Teacher& t)
{
	cout << "���ţ�" << t.id << "     ������" << t.name << "    ���룺" <<t.passwd << endl;
}
void printClassroom(Classroom& c)
{
	cout << "���ƣ�" << c.c_name << "     ������������" << c.num <<  endl;
}


//Ĭ�Ϲ���
Manager::Manager()
{
}


//�вι���
Manager::Manager(string id, string passwd, string name)
{
	this->id = id;
	this->passwd = passwd;
	this->name = name;

	//��ʼ������
	this->initVector();


}

//�˵�����
void Manager::openMenu()
{
	cout << endl << endl << endl;
	cout << "-----------------------------����Ա��"<<this->name<<"------------------------" << endl;
	cout << endl << endl;
	cout << "\t\t ---------------------------------\n";
	cout << "\t\t|                                 |\n";
	cout << "\t\t|        1������˺�              |\n";
	cout << "\t\t|                                 |\n";
	cout << "\t\t|        2���鿴�˺�              |\n";
	cout << "\t\t|                                 |\n";
	cout << "\t\t|        3���鿴ԤԼ              |\n";
	cout << "\t\t|                                 |\n";
	cout << "\t\t|        4�����ԤԼ              |\n";
	cout << "\t\t|                                 |\n";
	cout << "\t\t|        5�����ԤԼ              |\n";
	cout << "\t\t|                                 |\n";
	cout << "\t\t|        6��ע����¼              |\n";
	cout << "\t\t|                                 |\n";
	cout << "\t\t ---------------------------------\n";
}

//�鿴����ԤԼ
void Manager::showAllOrder()
{
	Order order;

	//�޼�¼ʱ
	if (order.size == 0)
	{
		cout << "��ԤԼ��¼" << endl;
		system("pause");
		system("cls");
		return;
	}

	for (int i = 0; i < order.size; i++)
	{
		cout << i + 1 << "��";
		cout << "ԤԼ�ˣ�" << order.m_orderData[i]["name"];
		cout << "  ԤԼ���ڣ���" << order.m_orderData[i]["date"];
		cout << "  ʱ��Σ���" << order.m_orderData[i]["interval"] << "�ڿ�";
		cout << "  ���ң�" << order.m_orderData[i]["room"];
		string status = "״̬��";
		//1������� 2����ԤԼ	3��ԤԼʧ��	4��ȡ��ԤԼ

		if (order.m_orderData[i]["status"] == "1")
		{
			status += "�����";
		}
		else if (order.m_orderData[i]["status"] == "2")
		{
			status += "ԤԼ�ɹ�";
		}
		else if (order.m_orderData[i]["status"] == "3")
		{
			status += "ԤԼʧ�ܣ����Ϊͨ��";
		}
		else
		{
			status += "ԤԼ��ȡ��";
		}
		cout << status << endl;



	}
}


//����˺�
void Manager::addAccount()
{
	ofstream ofs;
	ofs.open(ACCOUNT_FILE, ios::out | ios::app);   //д�ļ�+׷��
	string id;
	string name;
	string passwd;
	cout << "�������˺�" << endl;
	
	//����ظ��˺�
	while (true)
	{
		cin >> id;
		if (id == "q")
		{
			return;
		}
		bool repeat=checkRepeat(id);
		if (repeat)
		{
			cout << "�˺��Ѵ���" << endl;
		}
		else
		{
			break;
		}
		cout << "�����������˺ţ�����q�˳�" << endl;

	}

	int type = id.length();
	if ( type == 13 || type == 6)
	{
		cout << "����������" << endl;
		cin >> name;
		cout << "����������" << endl;
		cin >> passwd;

		ofs << id << " " << name << " " << passwd << " " << endl;
		
		ofs.close();
		this->initVector();
		cout << "��ӳɹ�" << endl;
		system("pause");
		system("cls");
	}
	else
	{
		cout << "�˺Ÿ�ʽ����" << endl;
		cout << "ѧ��������13λѧ��" << endl;
		cout << "����������6λְ����" << endl;
	}

}

//�鿴�˺�
void Manager::showAccount()
{
	cout << "��ѡ��鿴���ݣ�" << endl;
	cout << "1���鿴����ѧ��" << endl;
	cout << "2���鿴������ʦ" << endl;
	cout << "3���鿴���н���" << endl;

	int select = 0;
	cin >> select;
	if (select == 1)
	{
		cout << "����ѧ����Ϣ����:" << endl;
		for_each(vstu.begin(), vstu.end(), printStudent);

	}
	else if(select==2)
	{
		cout << "������ʦ��Ϣ���£�" << endl;
		for_each(vtea.begin(), vtea.end(), printTeacher);
	}
	else
	{
		cout << "���н�����Ϣ���£�" << endl;
		for_each(vcla.begin(), vcla.end(), printClassroom);
	}
	system("pause");
	system("cls");
}

//���ԤԼ��¼
void Manager::clearFile()
{
	ofstream ofs(ORDER_FILR, ios::trunc);         //���Ǵ��ڵ��ļ�
	ofs.close();

	cout << "��ճɹ�" << endl;
	system("pause");
	system("cls");
}


void Manager::initVector()
{
	ifstream ifs;
	ifs.open(ACCOUNT_FILE, ios::in);
	if (!ifs.is_open())
	{
		cout << "�ļ���ȡʧ��" << endl;
		return;
	}
	vstu.clear();
	vtea.clear();
	
	Student s;
	Teacher t;
	Classroom c;
	
	//��ȡȫ��ѧ����Ϣ
	while (ifs >> s.id&& ifs >> s.name&& ifs >> s.passwd)
	{
		if(s.id.length()==13)
		{
			vstu.push_back(s);
		}
	}
	cout << "��ǰѧ������:" << vstu.size() << endl;
	ifs.close();


	//��ȡȫ����ʦ��Ϣ
	ifs.open(ACCOUNT_FILE, ios::in);
	while (ifs >> t.id&& ifs >> t.name&& ifs >> t.passwd)
	{
		if (t.id.length() == 6)
		{
			vtea.push_back(t);
		}
	}
	cout << "��ǰ��ʦ����:" << vtea.size() << endl;
	ifs.close();

	//��ȡȫ��������Ϣ
	ifs.open(CLASSROOM_FILE, ios::in);
	while (ifs >> c.c_name&& ifs >> c.num)
	{
		vcla.push_back(c);
	}
	cout << "��ǰ��������:" << vcla.size() << endl;
	ifs.close();
}

bool Manager::checkRepeat(string id)
{
	int type = id.length();
	if (type == 13)
	{
		//���ѧ��
		for (vector<Student>::iterator it = vstu.begin(); it != vstu.end(); it++)
		{
			if (id == it->id)
			{
				return true;
			}
		}

	}
	else 
	{
		//�����ʦ
		for (vector<Teacher>::iterator it = vtea.begin(); it != vtea.end(); it++)
		{
			if (id == it->id)
			{
				return true;
			}
		}
	}
	return false;
}


void Manager::review()
{
	Order order;

	//�޼�¼ʱ
	if (order.size == 0)
	{
		cout << "��ԤԼ��¼" << endl;
		system("pause");
		system("cls");
		return;
	}

	cout << "����˵�ԤԼ��¼���£�" << endl;

	vector<int>v;        
	int index = 1;
	for (int i = 0; i < order.size; i++)
	{
		if (order.m_orderData[i]["status"]=="1")
		{
			v.push_back(i);
			cout << index++ << "��";
			cout << "�����ˣ�" << order.m_orderData[i]["name"];
			cout << "  ԤԼ���ڣ���" << order.m_orderData[i]["date"];
			cout << "  ʱ��Σ���" << order.m_orderData[i]["interval"] << "�ڿ�";
			cout << "  ���ң�" << order.m_orderData[i]["room"];

			string status = "״̬��";
			if (order.m_orderData[i]["status"] == "1")
			{
				status += "�����";
			}
			cout << status << endl;
		}
	}
	cout << "��������˵�ԤԼ��¼��0���Է��أ�";
	int select = 0;
	int ret = 0;

	while (true)
	{
		cin >> select;
		if (select >= 0 && select <= v.size())
		{
			if (select == 0)
			{
				break;
			}
			else
			{
				cout << "��������˽����" << endl;
				cout << "1��ͨ��" << endl;
				cout << "2����ͨ��" << endl;
				cin >> ret;

				if (ret == 1)
				{
					order.m_orderData[v[select - 1]]["status"] = "2";
				}
				else
				{
					order.m_orderData[v[select - 1]]["status"] = "3";
				}
				order.updateorder();
				cout << "������" << endl;
				break;
			}
		}
		cout << "������������������" << endl;
	}

	system("pause");
	system("cls");
}