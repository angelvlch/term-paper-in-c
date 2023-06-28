
#include<iostream>
#include "search.h"
#include <Windows.h>
#include "check.h"
#pragma comment (lib,"winmm.lib") 

using namespace std;
void searchMenu(vector <plane> v) {
  /*  PlaySound(TEXT("D:\\-sistema-poiska.wav"), NULL, SND_FILENAME | SND_ASYNC | SND_LOOP);*/
    cout << "\n\n������ ������ � �������� �� : \n1 - ������ �����\n2 - ���� ��������\n3 - ������ ����������\n4 - ��� ������\n";
    int ch;
    cin >> ch;
  
    switch (ch)
    {
    case 1:
        searchFlight(v);
        break;
    case 2:
        searchType(v);
        break;
    case 3:
        searchArrival(v);
        break;
    case 4:
        searchDay(v);
        break;
    default:
        system("cls");
        cout << "\a\n������������ ����\n";
    }
    /*PlaySound(NULL, NULL, SND_PURGE);*/
}
void searchFlight(vector <plane> v)
{
    
    cout << "������� ����� �����:";
    string flight;
    cin >> flight;
    int i;
    bool is = false;
    for (i = 0; i < v.size(); i++)
    {
        if (v[i].flight == flight)
        {
           if(is==false)
               headTable();
            show(v, i);
            is = true;
        }
    }
    if (!is)
        cout << "\n������ �� �������\n";
}

//int searchFlight(vector <plane> v,string s)
//{
//    int i;
//    bool is = false;
//    for (i = 0; i < v.size(); i++)
//    {
//        if (v[i].flight == s)
//        {
//            return i;
//        }
//    }
//    if (!is)
//        return -1;
//}

void searchType(vector <plane> v)
{
    cout << "������� ��� ��������:";
    string type;
    cin >> type;
    int i;
    bool is = false;
    for (i = 0; i < v.size(); i++)
    {
        if (v[i].type == type)
        {
            if (is == false)
                headTable();
            show(v, i);
            is = true;
        }
    }
    if (!is)
        cout << "\n������ �� �������\n";
}
void searchArrival(vector <plane> v)
{
    cout << "������� ����� ����������:";
    string arriv;
    cin >> arriv;
    int i;
    bool is = false;
    for (i = 0; i < v.size(); i++)
    {
        if (v[i].arrival == arriv)
        {
            if (is == false)
                headTable();
            show(v, i);
            is = true;
        }
    }
    if (!is)
        cout << "\n������ �� �������\n";
}
void searchDay(vector <plane> v)
{
    int day;
    do {
        cout << "������� ���� �����������:";
        cin >> day;
    } while (!isNumberNumeric());
    
    int i;
    bool is = false;
    for (i = 0; i < v.size(); i++)
    {
        if (v[i].day == day)
        {
            if (is == false)
                headTable();
            show(v, i);
            is = true;
        }
    }
    if (!is)
        cout << "\n������ �� �������\n";
}
//int searchTicketsBiss(vector <plane>v, int n)
//{
//    int i;
//    bool is = false;
//    for (i = 0; i < v.size(); i++)
//    {
//        if (v[i].ticketsLeftB >= n)
//        {
//            return i;
//        }
//    }
//    if (!is)
//        return - 1;
//}
//
//int searchTicketsEcon(vector <plane>v, int n)
//{
//    int i;
//    bool is = false;
//    for (i = 0; i < v.size(); i++)
//    {
//        if (v[i].ticketsLeftE >= n)
//        {
//            return i;
//        }
//    }
//    if (!is)
//        return -1;
//}