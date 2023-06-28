
#include<iostream>
#include "search.h"
#include <Windows.h>
#include "check.h"
#pragma comment (lib,"winmm.lib") 

using namespace std;
void searchMenu(vector <plane> v) {
  /*  PlaySound(TEXT("D:\\-sistema-poiska.wav"), NULL, SND_FILENAME | SND_ASYNC | SND_LOOP);*/
    cout << "\n\nИскать данные о самолете по : \n1 - Номеру рейса\n2 - Типу самолета\n3 - Пункту назначения\n4 - Дне вылета\n";
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
        cout << "\a\nНеккоректный ввод\n";
    }
    /*PlaySound(NULL, NULL, SND_PURGE);*/
}
void searchFlight(vector <plane> v)
{
    
    cout << "Введите номер рейса:";
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
        cout << "\nЗапись не найдена\n";
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
    cout << "Введите тип самолета:";
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
        cout << "\nЗапись не найдена\n";
}
void searchArrival(vector <plane> v)
{
    cout << "Введите пункт назначения:";
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
        cout << "\nЗапись не найдена\n";
}
void searchDay(vector <plane> v)
{
    int day;
    do {
        cout << "Введите день отправления:";
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
        cout << "\nЗапись не найдена\n";
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