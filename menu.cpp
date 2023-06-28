#include <iostream>
#include <conio.h>
#include "menu.h"
#include"check.h"
const char ESC = 27;

void menuAdmin(string admin)
{
    char ch = '0';
    cout << setfill('-') << setw(110) << "�� ����� � ���� ��������������" << setw(100) << "-" << endl;
    while (true)
    {

        std::cout << "\n�������� �����\n1. ����� ���������� �������� ��������\n2. ����� ������ � �������.\n\nESC-����� �� ���������\n";
        ch = _getche();
        cout << endl;
        if (ch == '1')
            menuAdminAcc(admin);
        else if (ch == '2')
            menuAdminData();
        else if (ch == ESC)
        {
            system("cls");
            cout << "\n�� �������,��� ������ �����?";
            if (isConfirmation()) exit(0);
        }
        else
        {
            system("cls");
            cout << "\n������������  ����,���������� �������" << endl;
        }
    }

}

void menuAdminData()
{
    
    char ch = 0;
    while (true)
    {
       
        cout << setfill('-') << setw(210) << "-" << endl;
        cout <<setfill(' ')<<' ' << setw(30) << "����� ������ � �������";
        cout << "\nB������� �����\n1. ����� ��������������\n2. ����� ��������� ������\n\nESC- ��������� �����\n";
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
            cout << "\a\n������������ ����,���������� �������\n";
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
        cout << setfill(' ') << ' ' << setw(30) << "����� �������������� ������";
        cout << "\n1. ����������� ��� ������\n2. �������� ����� ������\n3. ��������������� ������\n4. ������� ������\n\nESC.�������� �����\n";
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
            cout << "\a\n������������ ����,���������� �������\n";
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
        cout << setfill(' ') << ' ' << setw(30) << "���� ��������� ������";
        cout << "\n1. ������������ ������\n2. ����� ������\n3. ������ ����� �����\n4. ������� ���������� � ������,������� �������� � ���� ������\n\nESC-��������� �����\n";
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
            cout << "������������ ����,���������� �������\n";
           
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
        cout << "1.��������\n2.�����\n3.����������\n4.������ ������\n5.������� ���������� � ������,������� �������� � ���� ������\n6.�������\n\nESC ����� �� ���������\n";
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
                cout << "� �� ����� ������ �����?";
                if(isConfirmation())
                exit(0);
            default:
            {
                system("cls");
                cout << "\a\n������������ ����,���������� �������\n";
            }

            }
        fromVectorToFile(vec);
    } while (true);
}
