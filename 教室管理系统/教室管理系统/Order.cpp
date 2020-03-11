#include "Order.h"


//Ĭ�Ϲ���
Order::Order()
{
	ifstream ifs;
	ifs.open(ORDER_FILR,ios::in);

	//���ڡ�ʱ��Ρ�ԤԼ�ˡ����ҡ�״̬
	string date, interval, name, room, status;

	this->size = 0;

	//��ȡÿ����¼
	while (ifs >> name && ifs >> date && ifs >> interval && ifs >> room && ifs >> status)
	{
		//��ȡname
		string key, value;
		map<string, string>m;
		int pos = name.find(":");
		if (pos != -1) {
			key = name.substr(0, pos);
			value = name.substr(pos + 1, -1);

			m.insert(make_pair(key, value));
		}

		//��ȡdate
	    pos = date.find(":");
		if (pos != -1) {
			key = date.substr(0, pos);
			value = date.substr(pos + 1, -1);

			m.insert(make_pair(key, value));
		}


		//��ȡinterval
		pos = interval.find(":");
		if (pos != -1) {
			key = interval.substr(0, pos);
			value = interval.substr(pos + 1, -1);

			m.insert(make_pair(key, value));
		}

		//��ȡroom
		pos = room.find(":");
		if (pos != -1) {
			key = room.substr(0, pos);
			value = room.substr(pos + 1, -1);

			m.insert(make_pair(key, value));
		}

		//��ȡstatus
		pos = status.find(":");
		if (pos != -1) {
			key = status.substr(0, pos);
			value = status.substr(pos + 1, -1);

			m.insert(make_pair(key, value));
		}

		//��Сmap�����map
		this->m_orderData.insert(make_pair(this->size, m));
		this->size++;
		

	}
	ifs.close();
	
	

}

//����ԤԼ��¼
void Order::updateorder()
{
	//�޼�¼
	if (this->size == 0)
	{
		return;
	}

	ofstream ofs(ORDER_FILR, ios::out | ios::trunc);
	for (int i = 0; i < this->size; i++)
	{
		ofs << "name:" << this->m_orderData[i]["name"] << " ";
		ofs << "date:" << this->m_orderData[i]["date"] << " ";
		ofs << "interval:" << this->m_orderData[i]["interval"] << " ";
		ofs << "room:" << this->m_orderData[i]["room"] << " ";
		ofs << "status:" << this->m_orderData[i]["status"] << endl;
	}
	ofs.close();

}

