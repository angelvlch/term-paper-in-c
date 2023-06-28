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
    cout << "¦" << setiosflags(ios::left) << " " << setw(2) << i + 1 << "¦" << "  " << setw(7) << v[i].flight;
    cout<< "¦" << "  " << setw(12) << v[i].type << "\u00A6" << "     " << setw(15) << v[i].arrival << "¦";
    cout << "  ";
    if (v[i].day < 10) {
         cout << 0;
         }
    cout << v[i].day << '.';
            if (v[i].month < 10) {
                cout << 0;
            }
            cout << v[i].month << "." << v[i].year << setw(3) << " " << "¦";
            cout << "    ";
            if (v[i].start_hour < 10) {
                cout << 0;
            }
            
            cout << v[i].start_hour << ':';
            if (v[i].start_minute < 10) {
                cout << 0;
            }
           cout <<v[i].start_minute <<setw(5)<<" "<<"¦";
           cout << "    ";
           if (v[i].end_hour < 10) {
               cout << 0;
           }
           cout << v[i].end_hour << ':';
           if (v[i].end_minute < 10) {
               cout << 0;
           }
           cout << v[i].end_minute<< setw(5) << " " << "¦" <<setfill(' ')<<setw(10)<<" " /*<< "         "*/ << setw(12) << v[i].capacity << "¦" <<setfill(' ')<<setw(13)<<" " << setw(14) << v[i].ticketsLeftB << "¦";
            cout <<setfill(' ')<<setw(15)<<" " << setw(16) << v[i].ticketsLeftE << "¦" <<setfill(' ')<<setw(6)<<" " << setw(9) << v[i].priceB << "¦";
            cout<< setfill(' ') << setw(5) << " "<< setw(10) << v[i].priceE << "¦" ;
            cout << std::setfill('-') << setw(210) << "-" << setfill(' ') << setw(0) << endl;
}
void headTable()//для функций show
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    system("cls");
    cout << endl;
    cout <<setfill(' ') << setw(70)<<" " << "-Информация о найденных рейсах (№ - номер расположения в базе данных)-" << endl;
    cout << std::setfill('-') << setw(210) << "-" << setfill(' ') << setw(0) << endl;
    cout << "¦" << setiosflags(ios::left) << setw(3) << " №" << "¦" << setw(9) << "  Рейс" << "¦" << setw(14) << "  Тип" << "¦" << setw(15) << "  Пункт назначения  " << "¦";
    cout << setw(15) << " Дата вылета" << "¦" << setw(14) << " Время вылета" << "¦" << setw(14);
    cout << " Время прилета" << "¦" << setw(22) << " Вместимость самолета" <<"¦" << setw(26) << " Кол-во ост. бил биз-класса" << "¦";
    cout << setw(31) << " Кол-во ост. билетов эк-класса" << "¦" << setw(15) << " Цена б-класса" << "¦";
    cout << setw(15) << " Цена э-класса" << "¦" ;
    cout << std::setfill('-') << setw(210) << "-" << setfill(' ') << setw(0) << endl;
}
void add(vector<plane>& v)//если время меньше 10 то добавить 0 перед цифрой
{
    plane p;
        cout << "\nВведите номер рейса:";
        cin >> p.flight;

    cout << "\nВведите тип самолета:";
    cin >> p.type;
    do
    {
        cout << "\nВведите  пункт назначения:";
        cin >> p.arrival;
    } while (!isString(p.arrival));
    do {
        cout << "\nВведите день вылета:"; cin >> p.day;    
    } while (!isNumberNumeric()||!isNumberRangeCorrect(p.day,0,32));

    do {
        cout << "\nВведите месяц вылета:"; cin >> p.month;
    } while (!isNumberNumeric() || !isNumberRangeCorrect(p.month, 0, 13));

    do {
        cout << "\nВведите год вылета:"; cin >> p.year;
    } while (!isNumberNumeric()|| !isNumberRangeCorrect(p.year, 2022, 2030));

        cout << "\nВведите часы  отправления:";
        do {
            cin >> p.start_hour;

        } while (!isNumberNumeric() || !isNumberRangeCorrect(p.start_hour, -1, 24));
        cout << "\nВведите минуты отправления:";
        do {
            cin >> p.start_minute;

        } while (!isNumberNumeric() || !isNumberRangeCorrect(p.start_minute, -1, 60));
        cout << "\nВведите часы прибытия :";
        do {
            cin >> p.end_hour;
        } while (!isNumberNumeric()|| !isNumberRangeCorrect(p.end_hour, -1, 24));
        cout << "\nВведите минуты прибытия :";
        do {
            cin >> p.end_minute;
         
        } while (!isNumberNumeric() || !isNumberRangeCorrect(p.end_minute, -1, 60));
        do {
            cout << "Введите вместимость самолета:";
            cin >> p.capacity;
        } while (!isNumberNumeric() || !isNumberRangeCorrect(p.capacity,0, 1000));
        p.ticketsLeftE = 0;
        do {
            cout << "\nВведите количество кол-во оставшихся бизнес-класса:";
            cin >> p.ticketsLeftB;
            if (isNumberNumeric())
            {
                if (p.ticketsLeftB + p.ticketsLeftE <= p.capacity)
                    break;
                else
                    cout << "\a\nНеверный ввод, количество оставшихся билетов в сумме с оставшимися билетами эконом-класса должно быть не больше, чем вместимость самолета";
            }
        } while (!isNumberNumeric() || !isNumberRangeCorrect(p.ticketsLeftB, 0, 1000));
        do {
            cout << "\nВведите количество кол-во оставшихся эконом-класса:";
            cin >> p.ticketsLeftE;
            if (isNumberNumeric())
            {
                if (p.ticketsLeftB + p.ticketsLeftE <= p.capacity)
                    break;
                else
                    cout << "\a\nНеверный ввод, количество оставшихся билетов в сумме с оставшимися билетами бизнес-класса должно быть не больше, чем вместимость самолета";
            }
           
        } while (!isNumberNumeric() || !isNumberRangeCorrect(p.ticketsLeftB, 0, 1000));
        do {
            cout << "\nВведите цену билета бизнес-класса:";
            cin >> p.priceB;
        } while (!isNumberNumeric() ||!isNumberRangeCorrect(p.priceB, 0, 10000));
        do {
            cout << "\nВведите цену билета эконом-класса:";
            cin >> p.priceE;
        } while (!isNumberNumeric() || !isNumberRangeCorrect(p.ticketsLeftB, 0, 10000));
   
        cout << "Вы уверены,что хотите добавить новую запись?";
        if (isConfirmation())
        {
            cout << "Запись добавлена!\n";
            v.push_back(p);
            return;
        }
        cout << "Запись не добавлена\n"; 
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
        cout << "\nКакую запись хотите редактировать? Введите номер из базы данных:\n";
        cin >> index;
        if (index > v.size())
            cout << "\nТакой записи нет,повторите ввод!\n";
    } while (index > v.size());
   
    int ch = -1;
    const int ESC = 27;
    while (ch != 0)
    {
        cout << "0-Завершить редактирование\n" << "Что редактировать?\n1.Номер рейса,\n2.Тип самолета,\n3.Пункт назначения\n4.Дата вылета";
        cout << "\n5.Время вылета\n6.Время прилета\n7.Вместимость самолета\n8.Кол-во оставшихся билетов бизнес-класса\n9.Кол-во оставшихся билетов эконом класса";
        cout << "\n10.Цена билета бизнес-класса\n11.Цена билета эконом-класса\n";
        cin >> ch;
        switch (ch)
        {
        case 1:
            cout << "\nВведите новый номер рейса:";
            cin >> v[index - 1].flight;
            break;
        case 2:
            cout << "\nВведите новый тип самолета:";
            cin >> v[index - 1].type;
            break;
        case 3:
            do
            {
                cout << "\nВведите новый пункт назначения:";
                cin >> v[index - 1].arrival;
            } while (!isString(v[index - 1].arrival));
           
            break;
        case 4:
                cout << "\nВведите новую дату вылета:\n";
                do
                {
                    cout << "Введите день:";
                    cin >> v[index - 1].day;
                } while (!isNumberNumeric() || !isNumberRangeCorrect(v[index - 1].day, 0, 32));
                
                do
                {
                    cout << "\nВведите месяц:";
                    cin >> v[index - 1].month;
                } while (!isNumberNumeric() || !isNumberRangeCorrect(v[index - 1].month, 0, 13));
                
                do
                {
                    cout << "\nВведите год:";
                    cin >> v[index - 1].year;
                } while (!isNumberNumeric() || !isNumberRangeCorrect(v[index - 1].year, 2022, 2040));

            break;
        case 5:
            cout << "\nВведите новое время вылета:\n";
            do
            {
                cout << "Введите час вылета:";
                cin >> v[index - 1].start_hour;
            } while (!isNumberNumeric() || !isNumberRangeCorrect(v[index - 1].start_hour,-1, 25));
            do
            {
                cout << "Введите минуты вылета:";
                cin >> v[index - 1].start_minute;
            } while (!isNumberNumeric() || !isNumberRangeCorrect(v[index - 1].start_minute, -1, 61));
          
            break;
        case 6:
            
                cout << "\nВведите новое время прилета:\n";
                do
                {
                    cout << "Введите час прилета:";
                    cin >> v[index - 1].end_hour;
                } while (!isNumberNumeric() || !isNumberRangeCorrect(v[index - 1].end_hour, -1, 25));
                do
                {
                    cout << "Введите минуты прилета:";
                    cin >> v[index - 1].end_minute;
                } while (!isNumberNumeric() || !isNumberRangeCorrect(v[index - 1].end_minute, -1, 61));
               
            break;
        case 7:
            do {
                cout << "\nВведите новую вместимость самолета:";
                cin >> v[index - 1].capacity;
                if (isNumberNumeric())
                {
                    if (v[index - 1].capacity >= v[index - 1].ticketsLeftB + v[index - 1].ticketsLeftE)
                        break;
                    else
                        cout << "\a\nНеверный ввод,новая вместимость должна быть не меньше, чем количество оставшихся блиетов бизнес-классе и эконом-классе";
                }
                  
            } while (!isNumberNumeric());
            break;
        case 8:
            do {
                cout << "\nВведите новое кол-во оставшихся билетов бизнес-класса:";
                cin >> v[index - 1].ticketsLeftB;
                if (isNumberNumeric())
                {
                    if (v[index - 1].ticketsLeftB+v[index-1].ticketsLeftE <= v[index - 1].capacity)
                        break;
                    else
                        cout << "\a\nНеверный ввод,новое количество оставшихся билетов в сумме с оставшимися билетами эконом-класса должно быть не больше, чем вместимость самолета";
                }
            } while (!isNumberNumeric());
           
            break;
        case 9:
            do {
                cout << "\nВведите новое кол-во оставшихся билетов эконом-класса:";
                cin >> v[index - 1].ticketsLeftE;
                if (isNumberNumeric())
                {
                    if (v[index - 1].ticketsLeftB + v[index - 1].ticketsLeftE <= v[index - 1].capacity)
                        break;
                    else
                        cout << "\a\nНеверный ввод,новое количество оставшихся билетов в сумме с оставшимися билетами бизнес-класса должно быть не больше, чем вместимость самолета";
                }
            } while (!isNumberNumeric());
            
            break;
        case 10:
            do {
                cout << "\nВведите новую цену билета бизнес-класса:";//только положительные 
                cin >> v[index - 1].priceB;
                if (isNumberNumeric())
                {
                    if (v[index - 1].priceB>0)
                        break;
                    else
                        cout << "\a\nНеверный ввод, цена не может быть отрицательной!!!";
                }
            } while (!isNumberNumeric());
           
            break;
        case 11:
            do {
                cout << "\nВведите новую цену билета эконом-класса:";
                cin >> v[index - 1].priceE;
                if (isNumberNumeric())
                {
                    if (v[index - 1].priceE > 0)
                        break;
                    else
                        cout << "\a\nНеверный ввод, цена не может быть отрицательной!!!";
                }
            } while (!isNumberNumeric());
         
        case 0:
            break;
         default:
             system("cls");
             cout << "\a\nНеверный ввод,попробуйте сначала";
         
        }

    }
    system("cls");
    cout << "Вы действительно хотите изменить данные?";
    if (isConfirmation())
    {
        cout << "Изменения прошли успешно!\n";
        return v;
    }
    cout << "Изменения не сохранены\n";
    return buf;
   
   
}
void delet(vector<plane>& v)
{
    headTable();
    for (int i = 0; i < v.size(); i++)
        show(v, i);
    int index;
    cout << "Введите номер удаляемой записи:";
    do {
        cin >> index;

    } while (!isNumberNumeric() || !isNumberRangeCorrect(index, 0, v.size()));
    cout << "Вы уверены,что хотите удалить запись под номером " << index << "?\n";
    if (isConfirmation())
    {
        v.erase(v.begin() + index - 1);
        cout << "Запись под номером " << index << " успешно удалена!\n";
        return;
    }
    cout << "Запись не удалена" << endl;
}



