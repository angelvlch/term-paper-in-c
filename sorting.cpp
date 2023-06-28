
#include<string.h>
#include "sorting.h"
#include <conio.h>
#include "check.h"
using namespace std;

void menuSort(vector<plane>& vec)
{
    system("cls");
   
   char ch = 0;
   int a;
   const string goodSort = "\nСортировка прошла успешно!\n";
   const char SPACE = 32;
    while (ch != SPACE)
    {
    
        cout << setfill('-') << setw(210) << "-" << endl;
        cout << "\n1. Сортировать по цене\n2. Сортировать по вместимости самолета\n3. Сортировать по дате\n4. Сортировать по типу самолета\nSPACE Назад\n";
        ch = _getche();
        switch (ch)
        {
        case '1':
         a = isBorE();
        if (a == 1)
         sortBisClass(vec);  
        else if(a==2)
         sortEconClass(vec);
        if(a!=0)
         cout << goodSort;
        break;
        case '2':sortCapacity(vec); cout << goodSort;  break;
        case '3':sortDate(vec); cout << goodSort; break;
        case '4':sortType(vec); cout << goodSort; break;
        case SPACE:
            break;
        default:
            cout << "\a\nНеверный ввод!\n";
        }
    }
    system("cls");
}
int  isBorE()
{
    system("cls");
    cout << "\n1.Сортировать по цене билета бизнес-класса\n2.Сортировать по цене билета эконом-класса\n0-назад\n";
    int ch;
    do
    {
        cin >> ch;
     
    } while (!isNumberNumeric()||!isNumberRangeCorrect(ch,-1,3));
  
    return ch;
}
bool isIncrease()
{
    system("cls");
    int p;
    do {
        cout << "Сортировать по:1-возрастанию,2-убыванию? \n";
        cin >> p;
    } while (!isNumberNumeric()||!isNumberRangeCorrect(p,0,3));

    if (p == 1)
        return true;
    else
        return false;
}
void sortBisClass(vector <plane>& v)
{
    plane buf;
    for (int i = 0; i < v.size() - 1; i++)
        for (int j = 0; j < v.size() - i - 1; j++)
        {
            if (v[j].priceB > v[j + 1].priceB)
                swap(v[j], v[j + 1]);         
        }
    if (!isIncrease())
        for (int i = 0; i <= v.size() - i - 1; i++)
            swap(v[i], v[v.size() - i - 1]);
}
void sortEconClass(vector <plane>& v)
{
    plane buf;
    for (int i = 0; i < v.size() - 1; i++)
        for (int j = 0; j < v.size() - i - 1; j++)
        {
            if (v[j].priceE > v[j + 1].priceE)
                swap(v[j], v[j + 1]);
        }
    if (!isIncrease())
        for (int i = 0; i <= v.size() - i - 1; i++)
            swap(v[i], v[v.size() - i - 1]);
}
void sortCapacity(vector <plane>& v)
{
    plane buf;
    for (int i = 0; i < v.size() - 1; i++)
        for (int j = 0; j < v.size() - i - 1; j++)
        {
            if (v[j].capacity > v[j + 1].capacity)
                swap(v[j], v[j + 1]);
        }
    if (!isIncrease())
        for (int i = 0; i <= v.size() - i - 1; i++)
            swap(v[i], v[v.size() - i - 1]);
}
void sortDate(vector <plane>& v)
{
    plane buf;

    for (int i = 0; i < v.size() - 1; i++)
        for (int j = 0; j < v.size() - i - 1; j++)
        {
            if (v[j].year > v[j + 1].year)
                swap(v[j], v[j + 1]);
            else if (v[j].year == v[j + 1].year && v[j].month > v[j + 1].month)
                swap(v[j], v[j + 1]);
            else if (v[j].year == v[j + 1].year && v[j].month == v[j + 1].month && v[j].day > v[j + 1].day)
                swap(v[j], v[j + 1]);
        }
    if (!isIncrease())
        for (int i = 0; i <= v.size() - i - 1; i++)
            swap(v[i], v[v.size() - i - 1]);
}
void sortType(vector <plane>& v)
{
    plane buf;
    for (int i = 0; i < v.size() - 1; i++)
        for (int j = 0; j < v.size() - i - 1; j++)
        {
            if (isBig(v[j].type, v[j + 1].type))
                swap(v[j], v[j + 1]);

        }
    if (!isIncrease())
        for (int i = 0; i <= v.size() - i - 1; i++)
            swap(v[i], v[v.size() - i - 1]);
}
bool isBig(string type1, string type2)
{
    int i = 0;
    while (type1[i] != '\0' && type2[i] != '\0')
    {
        if (type1[i] > type2[i])
            return 1;
        if (type1[i] < type2[i])
            return 0;
        i++;
    }
    return 0;
}