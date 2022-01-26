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
		cout << endl << "Часы: " << Hours << endl;
		cout << "Минуты: " << Minutes << endl;

	
	}
	void Read_time()
	{
		cout << "Введите время разговора в формате: часы, минуты" << endl;
		cout << "Введите часы: ";
		cin >> Hours;
		cout << "\nВведите минуты: ";
		cin >> Minutes;
		while (init_time() == false)
		{
			system("cls");
			cout << "Некорректный ввод!" << endl;
			cout << "Введите время разговора в формате: часы, минуты" << endl;
			cout << "Введите часы: ";
			cin >> Hours;
			cout << "\nВведите минуты: ";
			cin >> Minutes;
		}
	}


};