#include <iostream>
#include <conio.h>
#include "menu.h"
#include"check.h"
const char ESC = 27;

void menuAdmin(string admin)
{
    char ch = '0';
    cout << setfill('-') << setw(110) << "Вы вошли в роли администратора" << setw(100) << "-" << endl;
    while (true)
    {

        std::cout << "\nВыберите режим\n1. Режим управления учетными записями\n2. Режим работы с данными.\n\nESC-выход из программы\n";
        ch = _getche();
        cout << endl;
        if (ch == '1')
            menuAdminAcc(admin);
        else if (ch == '2')
            menuAdminData();
        else if (ch == ESC)
        {
            system("cls");
            cout << "\nВы уверены,что хотите выйти?";
            if (isConfirmation()) exit(0);
        }
        else
        {
            system("cls");
            cout << "\nНеккоректный  ввод,попробуйте сначала" << endl;
        }
    }

}

void menuAdminData()
{
    
    char ch = 0;
    while (true)
    {
       
        cout << setfill('-') << setw(210) << "-" << endl;
        cout <<setfill(' ')<<' ' << setw(30) << "Режим работы с данными";
        cout << "\nBыберите режим\n1. Режим редактирования\n2. Режим обработки данных\n\nESC- Вернуться назад\n";
        ch = _getch();
        if (ch == '1')
            editData();
        else if (ch == '2')
            processData();
        else if (ch == ESC)
        {
            system("cls");
            break;
            
        }
        else
        {
            system("cls");
            cout << "\a\nНеккоректный ввод,попробуйте сначала\n";
        }
    }
  
}
void editData() {
   
    system("cls");
   vector<plane> vec =loadInVector();
    char ch = 0;
    while (ch != ESC)
    {
        
       
        cout << endl;
        cout << setfill('-') << setw(210) << "-" << endl;
        cout << setfill(' ') << ' ' << setw(30) << "Режим редактирования данных";
        cout << "\n1. Просмотреть все записи\n2. Добавить новую запись\n3. Отредактировать запись\n4. Удалить запись\n\nESC.Вернутся назад\n";
        ch = _getche();
        switch (ch)
        {
        case '1':
            headTable();
            for(int i=0;i<vec.size();i++)
            show(vec, i);
            break;
        case '2':
            add(vec);
            break;
        case '3':
           vec=edit(vec);
            break;
        case '4':
            delet(vec);
            break;
        case 27:
        {
            system("cls");
            break;
        }
        default:
            
        {
            system("cls");
            cout << "\a\nНеккоректный ввод,попробуйте сначала\n";
        }
           
        }
        fromVectorToFile(vec);
    }
}
void processData() {
 
    vector<plane> vec = loadInVector();
    char ch = 0;
    while (ch != ESC)
    {
       
        cout << setfill('-') << setw(210) << "-" << endl;
        cout << setfill(' ') << ' ' << setw(30) << "Меню обработки данных";
        cout << "\n1. Осортировать записи\n2. Поиск записи\n3. Купить билет билет\n4. Вывести информацию о рейсах,которые вылетают в этом месяце\n\nESC-Вернуться назад\n";
        ch = _getche();
        switch (ch)
        {
        case '1':
            menuSort(vec);
            break;
        case '2':
            searchMenu(vec);
            break;
        case '3':
            solveTask(vec,"h");
            break;
        case '4':
            findInThisMonth(vec);
            break;
        case 27:
            break;
        default:
            system("cls");
            cout << "Неккоректный ввод,попробуйте сначала\n";
           
        }
        fromVectorToFile(vec);
    }
    system("cls");
}

void menuUserData(string use)
{

    vector<plane> vec = loadInVector();
    char ch = 0;
    do
    {
        cout << "1.Просмотр\n2.Поиск\n3.Сортировка\n4.Купить билеты\n5.Вывести информацию о рейсах,которые вылетают в этом месяце\n6.Корзина\n\nESC выход из программы\n";
        ch = _getche();
            switch (ch)
            {
            case '1':
                headTable();
                for (int i = 0; i < vec.size(); i++)
                    show(vec, i);
                break;
            case '2':
                searchMenu(vec);
                break;
            case '3':
                menuSort(vec);
                break;         
            case '4':
                solveTask(vec,use);
                break;
            case '5':
                findInThisMonth(vec);
                break;
            case '6':
               basket(vec,use);
                break;
            case ESC:
                cout << "А Вы точно хотите выйти?";
                if(isConfirmation())
                exit(0);
            default:
            {
                system("cls");
                cout << "\a\nНеккоректный ввод,попробуйте сначала\n";
            }

            }
        fromVectorToFile(vec);
    } while (true);
}
