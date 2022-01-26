#include <iostream>
#include <string>
#include <cstring>
#include "Time.h"
#include <Windows.h>
#include <stdlib.h>

using namespace std;

class Bill
{

    string name;			// ������� �����������, ����� ��������, ����� �� ������ ���������, ������ (� ���������),
    Time Start = { 0,0 };
    Time End = { 0,0 };
    unsigned long long int number = 0;             // ����� ������ ���������, ����� ��������� ���������, ����� � ������.
    double price = 0;              // ����� �������� ��������� time 
    double discount = 0;           // ����� - ��������� ������� #include <������>
    double summary = 0;
public:
    // -- ��������������� ����� -- �������������� � ������ --
    int toMinute(Time smth)
    {
        return ((smth.Hours * 60) + smth.Minutes);
    }

    // -- ��������������� ����� -- �������������� � ������ --
    string tostring (Bill who)
    {
        string str;
        system("cls");
        str = "�������: " + name + " | �����: ";
        str += price;
        str += "  |  ������: ";
        str += discount;
        str += "  |  ����� ������: ";
        str += (((toMinute(End) - toMinute(Start)) * price) * (discount * 0.01));
        str += "  |  ����� ������ ���������: ";
        Start.Display_time();
        str += "  |  ����� ����� ���������: ";
        End.Display_time();
        str += "  |  ������������ ��������� (� �������): ";
        str += (toMinute(End) - toMinute(Start));
        str += "  |  ����� � ������: ";
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
    void Read(); // ��� ����������, ���� ��� ��� ������ ��������    
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
    cout << "�������: " << name << endl;
    cout << "�����: " << price << endl;
    cout << "������: " << discount << "  |  ����� ������: " << (((toMinute(End) - toMinute(Start)) * price) * (discount * 0.01)) << endl;
    cout << "����� ������ ���������: ";
    Start.Display_time();
    cout << "����� ����� ���������: ";
    End.Display_time();
    cout << "������������ ��������� (� �������): " << (toMinute(End) - toMinute(Start)) << endl;
    cout << "����� � ������: " << summary << endl;



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
    cout << "\n������� ������� ��������: ";
    cin >> name;
    cout << "\n������� ����� ��������: ";
    cin >> n;
    cout << "\n������� �����: ";
    cin >> p;
    cout << "\n������� ������� ������: ";
    cin >> d;
    while(init(name, n, p, d) == false) {
        system("cls");
        cout << "\n������� ������� ��������: ";
        cin >> name;
        cout << "\n������� ����� ��������: ";
        cin >> n;
        cout << "\n������� �����: ";
        cin >> p;
        cout << "\n������� ������� ������: ";
        cin >> d;
    }
 
    cout << "\n������� ����� ������ ���������." << endl;
    Start.Read_time();
    while (Start.init_time() == false)
    {
        cout << "\n������� ����� ������ ���������." << endl;
        Start.Read_time();
    }
    cout << "\n������� ����� ����� ���������. (����� ������)" << endl;
    End.Read_time();
    while (End.init_time() == false || toMinute(Start) > toMinute(End))
    {
        cout << "\n������� ����� ����� ���������. (����� ������)" << endl;
        End.Read_time();
    }
    Summary();
}





int main()
{
    system("chcp 1251 > nul");
    cout << "\t\t\t-------------------------------------\n\t\t\t������������ ������ �1. ������� 2.\n\t\t\t��������� �. ������ �����-21";
    cout << "\n\t\t\t-------------------------------------" << endl;
    Bill Abonent;
    Bill Abonent_2;
    Abonent.Read();
    Abonent.Display();
    Abonent_2.Read();
    Abonent_2.Display();
    if (Abonent.Compare(Abonent_2) == true)
    {
        cout << "������� �����";
    }
    else cout << "������� �������";
	system("pause");
	return 0;
}
