#include <iostream>
#include <string>
#include <cstring>
#include "Time.h"
#include <Windows.h>
#include <stdlib.h>

using namespace std;

class Bill
{

    string name;			// фамилия плательщика, номер телефона, тариф за минуту разговора, скидка (в процентах),
    Time Start = { 0,0 };
    Time End = { 0,0 };
    unsigned long long int number = 0;             // время начала разговора, время окончания разговора, сумма к оплате.
    double price = 0;              // нужно написать структуру time 
    double discount = 0;           // лучше - отдельным модулем #include <модуль>
    double summary = 0;
public:
    // -- вспомогательный метод -- Преобразование в минуты --
    int toMinute(Time smth)
    {
        return ((smth.Hours * 60) + smth.Minutes);
    }

    // -- всмопогательный метод -- преобразование в строку --
    string tostring (Bill who)
    {
        string str;
        system("cls");
        str = "Абонент: " + name + " | Тариф: ";
        str += price;
        str += "  |  Скидка: ";
        str += discount;
        str += "  |  Сумма скидки: ";
        str += (((toMinute(End) - toMinute(Start)) * price) * (discount * 0.01));
        str += "  |  Время начала разговора: ";
        Start.Display_time();
        str += "  |  Время конца разговора: ";
        End.Display_time();
        str += "  |  Длительность разговора (в минутах): ";
        str += (toMinute(End) - toMinute(Start));
        str += "  |  Итого к оплате: ";
        str += summary;
    }


    bool init(string name, unsigned long long int n, double p, double d)
    {
        if ((name.length() < 1) || (n > 99999999999) || (n < 10000000000) || (p < 0) || (d < 0) || (d > 100)) return false;
        else 
        {
            this->name = name;
            number = n;
            price = p;
            discount = d;
            return true;
        }
    }

    bool init_obj(Bill who)
    {
        if ((name.length() < 1) || (who.number > 99999999999) || (who.number < 10000000000) || (who.price < 0) || (who.discount < 0) || (who.discount > 100)) return false;
        else
        {
            this->name = name;
            number = who.number;
            price = who.price;
            discount = who.discount;
            return true;
        }
    }
    void Read(); // Это объявление, сюда еще все методы закинуть    
    void Display();
    void Summary();
    bool Compare(Bill two) 
    {
        bool flag = false;
        if (name == two.name) flag = true;
        if (number == two.number) flag = true;
        if (price == two.price) flag = true;
        if (discount == two.discount) flag = true;
        if (Start.Minutes == two.End.Minutes) flag = true;
        if (Start.Minutes == two.End.Minutes) flag = true;
        return flag;
    };
};

void Bill::Display()
{
    
    system("cls");
    cout << "Абонент: " << name << endl;
    cout << "Тариф: " << price << endl;
    cout << "Скидка: " << discount << "  |  Сумма скидки: " << (((toMinute(End) - toMinute(Start)) * price) * (discount * 0.01)) << endl;
    cout << "Время начала разговора: ";
    Start.Display_time();
    cout << "Время конца разговора: ";
    End.Display_time();
    cout << "Длительность разговора (в минутах): " << (toMinute(End) - toMinute(Start)) << endl;
    cout << "Итого к оплате: " << summary << endl;



}

void Bill::Summary()
{
    summary = ((toMinute(End) - toMinute(Start)) * price);
    
    summary = summary - (summary * (discount * 0.01));
}

void Bill::Read() // 
{
   
    string name;
    double  p, d;
    unsigned long long n;
    cout << "\nВведите фамилию абонента: ";
    cin >> name;
    cout << "\nВведите номер абонента: ";
    cin >> n;
    cout << "\nВведите тариф: ";
    cin >> p;
    cout << "\nВведите процент скидки: ";
    cin >> d;
    while(init(name, n, p, d) == false) {
        system("cls");
        cout << "\nВведите фамилию абонента: ";
        cin >> name;
        cout << "\nВведите номер абонента: ";
        cin >> n;
        cout << "\nВведите тариф: ";
        cin >> p;
        cout << "\nВведите процент скидки: ";
        cin >> d;
    }
 
    cout << "\nВведите время начала разговора." << endl;
    Start.Read_time();
    while (Start.init_time() == false)
    {
        cout << "\nВведите время начала разговора." << endl;
        Start.Read_time();
    }
    cout << "\nВведите время конца разговора. (позже начала)" << endl;
    End.Read_time();
    while (End.init_time() == false || toMinute(Start) > toMinute(End))
    {
        cout << "\nВведите время конца разговора. (позже начала)" << endl;
        End.Read_time();
    }
    Summary();
}





int main()
{
    system("chcp 1251 > nul");
    cout << "\t\t\t-------------------------------------\n\t\t\tЛабораторная работа №1. Вариант 2.\n\t\t\tКамоликов В. Группа ДИНРБ-21";
    cout << "\n\t\t\t-------------------------------------" << endl;
    Bill Abonent;
    Bill Abonent_2;
    Abonent.Read();
    Abonent.Display();
    Abonent_2.Read();
    Abonent_2.Display();
    if (Abonent.Compare(Abonent_2) == true)
    {
        cout << "Объекты равны";
    }
    else cout << "Объекты неравны";
	system("pause");
	return 0;
}
