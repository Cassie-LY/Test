#include "Teacher.h"
#include "Order.h"
#include "Classroom.h"


//Ĭ�Ϲ���
Teacher::Teacher()
{
}

//�вι���
Teacher::Teacher(string id, string passwd, string name)
{
	//��ʼ��
	this->id = id;
	this->name = name;
	this->passwd = passwd;


	//��ȡ������Ϣ
	ifstream ifs;
	ifs.open(CLASSROOM_FILE, ios::in);

	Classroom c;
	while (ifs >> c.c_name&& ifs >> c.num)
	{
		vcla.push_back(c);
	}
	ifs.close();

}

//�˵�����
void Teacher::openMenu()
{
	cout << endl << endl << endl;
	cout << "-----------------------------" << this->name << "��ʦ------------------------" << endl;
	cout << endl << endl;
	cout << "\t\t ---------------------------------\n";
	cout << "\t\t|                                 |\n";
	cout << "\t\t|        1������ԤԼ              |\n";
	cout << "\t\t|                                 |\n";
	cout << "\t\t|        2���鿴�ҵ�ԤԼ          |\n";
	cout << "\t\t|                                 |\n";
	cout << "\t\t|        3���鿴����ԤԼ          |\n";
	cout << "\t\t|                                 |\n";
	cout << "\t\t|        4��ȡ��ԤԼ              |\n";
	cout << "\t\t|                                 |\n";
	cout << "\t\t|        5��ע����¼              |\n";
	cout << "\t\t|                                 |\n";
	cout << "\t\t ---------------------------------\n";
}

//����ԤԼ
void Teacher::applyOrder()
{
	cout << "ԤԼ����ʱ��Ϊÿ��������" << endl;
	cout << "ԤԼʱ��Ϊ������һ������" << endl;
	cout << "����������ԤԼ��ʱ�䣺" << endl;
	cout << "1����һ" << endl;
	cout << "2���ܶ�" << endl;
	cout << "3������" << endl;
	cout << "4������" << endl;
	cout << "5������" << endl;

	int date = 0;            //����
	int interval = 0;        //ʱ���
	string room = "";            //����

	while (true)
	{
		cin >> date;
		if (date >= 1 && date <= 5)
		{
			break;
		}
		cout << "����������������������" << endl;
	}

	cout << "����������ԤԼ��ʱ��Σ�" << endl;
	cout << "1�������һ�ڿ�" << endl;
	cout << "2������ڶ��ڿ�" << endl;
	cout << "3�������һ�ڿ�" << endl;
	cout << "4������ڶ��ڿ�" << endl;
	cout << "5�����ϵ�һ�ڿ�" << endl;
	cout << "6�����ϵڶ��ڿ�" << endl;

	while (true)
	{
		cin >> interval;
		if (interval >= 1 && interval <= 6)
		{
			break;
		}
		cout << "ʱ���������������������" << endl;
	}


	for (int i = 0; i < vcla.size(); i++)
	{
		cout << vcla[i].c_name << "���ҿ�ԤԼ��������" << vcla[i].num << "��" << endl;
	}

	cout << "��ѡ�����";
	while (true) {
		cin >> room;
		if (room == "�ɽ�105" || room == "�ɽ�106" || room == "�ɽ�107" || room == "�ɽ�108" || room == "�ɽ�205" || room == "�ɽ�206" || room == "�ɽ�207" || room == "�ɽ�208" || room == "�ɽ�309" || room == "�ɽ�310" || room == "�ɽ�311" || room == "�ɽ�312" || room == "��ƽһ" || room == "��ƽ��" || room == "��ƽ��" || room == "��ƽ��" || room == "��һ" || room == "���" || room == "����")
		{
			break;
		}
		cout << "������������������" << endl;
	}


	cout << "ԤԼ�ɹ�,�����" << endl;

	ofstream ofs;
	ofs.open(ORDER_FILR, ios::app);

	ofs << "name:" << this->name << " ";
	ofs << "date:" << date << " ";
	ofs << "interval:" << interval << " ";
	ofs << "room:" << room << " ";
	ofs << "status:" << 1 << endl;

	ofs.close();
	system("pause");
	system("cls");


}

//�鿴����ԤԼ
void Teacher::showSelf()
{
	Order order;
	if (order.size == 0)
	{
		cout << "��ԤԼ��¼" << endl;
		system("pause");
		system("cls");
		return;
	}

	for (int i = 0; i < order.size; i++)
	{
		if (this->name == order.m_orderData[i]["name"])
		{
			cout << "ԤԼ���ڣ���" << order.m_orderData[i]["date"];
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

	system("pause");
	system("cls");
}

//�鿴����ԤԼ
void Teacher::showAllOrder()
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

//ȡ��ԤԼ
void Teacher::canceOrder()
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

	cout << "����л�ԤԼ�ɹ��ļ�¼����ȡ����������ȡ���ļ�¼" << endl;

	vector<int>v;         //�������������е��±���
	int index = 1;
	for (int i = 0; i < order.size; i++)
	{
		if (this->name == order.m_orderData[i]["name"])
		{
			if (order.m_orderData[i]["status"] == "1" || order.m_orderData[i]["status"] == "2")
			{
				v.push_back(i);
				cout << index++ << "��";
				cout << "  ԤԼ���ڣ���" << order.m_orderData[i]["date"];
				cout << "  ʱ��Σ���" << order.m_orderData[i]["interval"] << "�ڿ�";
				cout << "  ���ң�" << order.m_orderData[i]["room"];

				string status = "״̬��";
				if (order.m_orderData[i]["status"] == "1")
				{
					status += "�����";
				}
				else if (order.m_orderData[i]["status"] == "2")
				{
					status += "ԤԼ�ɹ�";
				}
				cout << status << endl;
			}
		}
	}
	cout << "������ȡ���ļ�¼��0���Է��أ�";
	int select = 0;
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
				//v[select-1]���ڼ������ȥ�����ݣ����ú�v���±�-1��Ӧ
				order.m_orderData[v[select - 1]]["status"] = 4;
				order.updateorder();

				cout << "��ȡ��ԤԼ" << endl;
				break;
			}
		}
		cout << "������������������" << endl;

	}
	system("pause");
	system("cls");

}