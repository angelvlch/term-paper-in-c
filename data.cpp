#include<iostream>
#include "data.h"
#include <conio.h>
#include "check.h"
#include <windows.h>
using namespace std;

void show(vector<plane> v,int i)//
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    cout << "�" << setiosflags(ios::left) << " " << setw(2) << i + 1 << "�" << "  " << setw(7) << v[i].flight;
    cout<< "�" << "  " << setw(12) << v[i].type << "\u00A6" << "     " << setw(15) << v[i].arrival << "�";
    cout << "  ";
    if (v[i].day < 10) {
         cout << 0;
         }
    cout << v[i].day << '.';
            if (v[i].month < 10) {
                cout << 0;
            }
            cout << v[i].month << "." << v[i].year << setw(3) << " " << "�";
            cout << "    ";
            if (v[i].start_hour < 10) {
                cout << 0;
            }
            
            cout << v[i].start_hour << ':';
            if (v[i].start_minute < 10) {
                cout << 0;
            }
           cout <<v[i].start_minute <<setw(5)<<" "<<"�";
           cout << "    ";
           if (v[i].end_hour < 10) {
               cout << 0;
           }
           cout << v[i].end_hour << ':';
           if (v[i].end_minute < 10) {
               cout << 0;
           }
           cout << v[i].end_minute<< setw(5) << " " << "�" <<setfill(' ')<<setw(10)<<" " /*<< "         "*/ << setw(12) << v[i].capacity << "�" <<setfill(' ')<<setw(13)<<" " << setw(14) << v[i].ticketsLeftB << "�";
            cout <<setfill(' ')<<setw(15)<<" " << setw(16) << v[i].ticketsLeftE << "�" <<setfill(' ')<<setw(6)<<" " << setw(9) << v[i].priceB << "�";
            cout<< setfill(' ') << setw(5) << " "<< setw(10) << v[i].priceE << "�" ;
            cout << std::setfill('-') << setw(210) << "-" << setfill(' ') << setw(0) << endl;
}
void headTable()//��� ������� show
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    system("cls");
    cout << endl;
    cout <<setfill(' ') << setw(70)<<" " << "-���������� � ��������� ������ (� - ����� ������������ � ���� ������)-" << endl;
    cout << std::setfill('-') << setw(210) << "-" << setfill(' ') << setw(0) << endl;
    cout << "�" << setiosflags(ios::left) << setw(3) << " �" << "�" << setw(9) << "  ����" << "�" << setw(14) << "  ���" << "�" << setw(15) << "  ����� ����������  " << "�";
    cout << setw(15) << " ���� ������" << "�" << setw(14) << " ����� ������" << "�" << setw(14);
    cout << " ����� �������" << "�" << setw(22) << " ����������� ��������" <<"�" << setw(26) << " ���-�� ���. ��� ���-������" << "�";
    cout << setw(31) << " ���-�� ���. ������� ��-������" << "�" << setw(15) << " ���� �-������" << "�";
    cout << setw(15) << " ���� �-������" << "�" ;
    cout << std::setfill('-') << setw(210) << "-" << setfill(' ') << setw(0) << endl;
}
void add(vector<plane>& v)//���� ����� ������ 10 �� �������� 0 ����� ������
{
    plane p;
        cout << "\n������� ����� �����:";
        cin >> p.flight;

    cout << "\n������� ��� ��������:";
    cin >> p.type;
    do
    {
        cout << "\n�������  ����� ����������:";
        cin >> p.arrival;
    } while (!isString(p.arrival));
    do {
        cout << "\n������� ���� ������:"; cin >> p.day;    
    } while (!isNumberNumeric()||!isNumberRangeCorrect(p.day,0,32));

    do {
        cout << "\n������� ����� ������:"; cin >> p.month;
    } while (!isNumberNumeric() || !isNumberRangeCorrect(p.month, 0, 13));

    do {
        cout << "\n������� ��� ������:"; cin >> p.year;
    } while (!isNumberNumeric()|| !isNumberRangeCorrect(p.year, 2022, 2030));

        cout << "\n������� ����  �����������:";
        do {
            cin >> p.start_hour;

        } while (!isNumberNumeric() || !isNumberRangeCorrect(p.start_hour, -1, 24));
        cout << "\n������� ������ �����������:";
        do {
            cin >> p.start_minute;

        } while (!isNumberNumeric() || !isNumberRangeCorrect(p.start_minute, -1, 60));
        cout << "\n������� ���� �������� :";
        do {
            cin >> p.end_hour;
        } while (!isNumberNumeric()|| !isNumberRangeCorrect(p.end_hour, -1, 24));
        cout << "\n������� ������ �������� :";
        do {
            cin >> p.end_minute;
         
        } while (!isNumberNumeric() || !isNumberRangeCorrect(p.end_minute, -1, 60));
        do {
            cout << "������� ����������� ��������:";
            cin >> p.capacity;
        } while (!isNumberNumeric() || !isNumberRangeCorrect(p.capacity,0, 1000));
        p.ticketsLeftE = 0;
        do {
            cout << "\n������� ���������� ���-�� ���������� ������-������:";
            cin >> p.ticketsLeftB;
            if (isNumberNumeric())
            {
                if (p.ticketsLeftB + p.ticketsLeftE <= p.capacity)
                    break;
                else
                    cout << "\a\n�������� ����, ���������� ���������� ������� � ����� � ����������� �������� ������-������ ������ ���� �� ������, ��� ����������� ��������";
            }
        } while (!isNumberNumeric() || !isNumberRangeCorrect(p.ticketsLeftB, 0, 1000));
        do {
            cout << "\n������� ���������� ���-�� ���������� ������-������:";
            cin >> p.ticketsLeftE;
            if (isNumberNumeric())
            {
                if (p.ticketsLeftB + p.ticketsLeftE <= p.capacity)
                    break;
                else
                    cout << "\a\n�������� ����, ���������� ���������� ������� � ����� � ����������� �������� ������-������ ������ ���� �� ������, ��� ����������� ��������";
            }
           
        } while (!isNumberNumeric() || !isNumberRangeCorrect(p.ticketsLeftB, 0, 1000));
        do {
            cout << "\n������� ���� ������ ������-������:";
            cin >> p.priceB;
        } while (!isNumberNumeric() ||!isNumberRangeCorrect(p.priceB, 0, 10000));
        do {
            cout << "\n������� ���� ������ ������-������:";
            cin >> p.priceE;
        } while (!isNumberNumeric() || !isNumberRangeCorrect(p.ticketsLeftB, 0, 10000));
   
        cout << "�� �������,��� ������ �������� ����� ������?";
        if (isConfirmation())
        {
            cout << "������ ���������!\n";
            v.push_back(p);
            return;
        }
        cout << "������ �� ���������\n"; 
}

vector<plane> edit(vector<plane> v)
{
    vector<plane> buf = v;
    headTable();
    for (int i = 0; i < v.size(); i++)
        show(v, i);
    int index;
    do
    {
        cout << "\n����� ������ ������ �������������? ������� ����� �� ���� ������:\n";
        cin >> index;
        if (index > v.size())
            cout << "\n����� ������ ���,��������� ����!\n";
    } while (index > v.size());
   
    int ch = -1;
    const int ESC = 27;
    while (ch != 0)
    {
        cout << "0-��������� ��������������\n" << "��� �������������?\n1.����� �����,\n2.��� ��������,\n3.����� ����������\n4.���� ������";
        cout << "\n5.����� ������\n6.����� �������\n7.����������� ��������\n8.���-�� ���������� ������� ������-������\n9.���-�� ���������� ������� ������ ������";
        cout << "\n10.���� ������ ������-������\n11.���� ������ ������-������\n";
        cin >> ch;
        switch (ch)
        {
        case 1:
            cout << "\n������� ����� ����� �����:";
            cin >> v[index - 1].flight;
            break;
        case 2:
            cout << "\n������� ����� ��� ��������:";
            cin >> v[index - 1].type;
            break;
        case 3:
            do
            {
                cout << "\n������� ����� ����� ����������:";
                cin >> v[index - 1].arrival;
            } while (!isString(v[index - 1].arrival));
           
            break;
        case 4:
                cout << "\n������� ����� ���� ������:\n";
                do
                {
                    cout << "������� ����:";
                    cin >> v[index - 1].day;
                } while (!isNumberNumeric() || !isNumberRangeCorrect(v[index - 1].day, 0, 32));
                
                do
                {
                    cout << "\n������� �����:";
                    cin >> v[index - 1].month;
                } while (!isNumberNumeric() || !isNumberRangeCorrect(v[index - 1].month, 0, 13));
                
                do
                {
                    cout << "\n������� ���:";
                    cin >> v[index - 1].year;
                } while (!isNumberNumeric() || !isNumberRangeCorrect(v[index - 1].year, 2022, 2040));

            break;
        case 5:
            cout << "\n������� ����� ����� ������:\n";
            do
            {
                cout << "������� ��� ������:";
                cin >> v[index - 1].start_hour;
            } while (!isNumberNumeric() || !isNumberRangeCorrect(v[index - 1].start_hour,-1, 25));
            do
            {
                cout << "������� ������ ������:";
                cin >> v[index - 1].start_minute;
            } while (!isNumberNumeric() || !isNumberRangeCorrect(v[index - 1].start_minute, -1, 61));
          
            break;
        case 6:
            
                cout << "\n������� ����� ����� �������:\n";
                do
                {
                    cout << "������� ��� �������:";
                    cin >> v[index - 1].end_hour;
                } while (!isNumberNumeric() || !isNumberRangeCorrect(v[index - 1].end_hour, -1, 25));
                do
                {
                    cout << "������� ������ �������:";
                    cin >> v[index - 1].end_minute;
                } while (!isNumberNumeric() || !isNumberRangeCorrect(v[index - 1].end_minute, -1, 61));
               
            break;
        case 7:
            do {
                cout << "\n������� ����� ����������� ��������:";
                cin >> v[index - 1].capacity;
                if (isNumberNumeric())
                {
                    if (v[index - 1].capacity >= v[index - 1].ticketsLeftB + v[index - 1].ticketsLeftE)
                        break;
                    else
                        cout << "\a\n�������� ����,����� ����������� ������ ���� �� ������, ��� ���������� ���������� ������� ������-������ � ������-������";
                }
                  
            } while (!isNumberNumeric());
            break;
        case 8:
            do {
                cout << "\n������� ����� ���-�� ���������� ������� ������-������:";
                cin >> v[index - 1].ticketsLeftB;
                if (isNumberNumeric())
                {
                    if (v[index - 1].ticketsLeftB+v[index-1].ticketsLeftE <= v[index - 1].capacity)
                        break;
                    else
                        cout << "\a\n�������� ����,����� ���������� ���������� ������� � ����� � ����������� �������� ������-������ ������ ���� �� ������, ��� ����������� ��������";
                }
            } while (!isNumberNumeric());
           
            break;
        case 9:
            do {
                cout << "\n������� ����� ���-�� ���������� ������� ������-������:";
                cin >> v[index - 1].ticketsLeftE;
                if (isNumberNumeric())
                {
                    if (v[index - 1].ticketsLeftB + v[index - 1].ticketsLeftE <= v[index - 1].capacity)
                        break;
                    else
                        cout << "\a\n�������� ����,����� ���������� ���������� ������� � ����� � ����������� �������� ������-������ ������ ���� �� ������, ��� ����������� ��������";
                }
            } while (!isNumberNumeric());
            
            break;
        case 10:
            do {
                cout << "\n������� ����� ���� ������ ������-������:";//������ ������������� 
                cin >> v[index - 1].priceB;
                if (isNumberNumeric())
                {
                    if (v[index - 1].priceB>0)
                        break;
                    else
                        cout << "\a\n�������� ����, ���� �� ����� ���� �������������!!!";
                }
            } while (!isNumberNumeric());
           
            break;
        case 11:
            do {
                cout << "\n������� ����� ���� ������ ������-������:";
                cin >> v[index - 1].priceE;
                if (isNumberNumeric())
                {
                    if (v[index - 1].priceE > 0)
                        break;
                    else
                        cout << "\a\n�������� ����, ���� �� ����� ���� �������������!!!";
                }
            } while (!isNumberNumeric());
         
        case 0:
            break;
         default:
             system("cls");
             cout << "\a\n�������� ����,���������� �������";
         
        }

    }
    system("cls");
    cout << "�� ������������� ������ �������� ������?";
    if (isConfirmation())
    {
        cout << "��������� ������ �������!\n";
        return v;
    }
    cout << "��������� �� ���������\n";
    return buf;
   
   
}
void delet(vector<plane>& v)
{
    headTable();
    for (int i = 0; i < v.size(); i++)
        show(v, i);
    int index;
    cout << "������� ����� ��������� ������:";
    do {
        cin >> index;

    } while (!isNumberNumeric() || !isNumberRangeCorrect(index, 0, v.size()));
    cout << "�� �������,��� ������ ������� ������ ��� ������� " << index << "?\n";
    if (isConfirmation())
    {
        v.erase(v.begin() + index - 1);
        cout << "������ ��� ������� " << index << " ������� �������!\n";
        return;
    }
    cout << "������ �� �������" << endl;
}



