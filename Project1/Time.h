#pragma once
#include <iostream>

using namespace std;

struct Time
{
public:
	unsigned int Hours;
	unsigned int Minutes;


	bool init_time()
	{
		if ((Hours > 23) || (Hours < 0) || (Minutes > 59) || (Minutes < 0))
			return false;
		else return true;
	}

	void Display_time()
	{
		cout << endl << "����: " << Hours << endl;
		cout << "������: " << Minutes << endl;

	
	}
	void Read_time()
	{
		cout << "������� ����� ��������� � �������: ����, ������" << endl;
		cout << "������� ����: ";
		cin >> Hours;
		cout << "\n������� ������: ";
		cin >> Minutes;
		while (init_time() == false)
		{
			system("cls");
			cout << "������������ ����!" << endl;
			cout << "������� ����� ��������� � �������: ����, ������" << endl;
			cout << "������� ����: ";
			cin >> Hours;
			cout << "\n������� ������: ";
			cin >> Minutes;
		}
	}


};