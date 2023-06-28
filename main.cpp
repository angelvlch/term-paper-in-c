#include <iostream>
#include <conio.h>
#include "account.h"
#include "menu.h"
#include "check.h"
char ESC = 27;

void main()
{
 
    setlocale(LC_ALL, "Ru");
    cout << setfill('-') << setw(105) << "Добро пожаловать!!" << setw(105) << "-" << endl;
    char ch = '0';
    do
    {
        cout << "\n   Нажмите:\n 1 - для регистрации\n 2 - для входа\n\n ESC - для выхода из программы\n";
        ch = _getche();
        if (ch == '1') {
            system("cls");
            registration(0);
        }
        else if (ch == '2')
        {
            system("cls");
            User us;
            if (login_password(us) == false)
            {
                continue;
            }
            cout << endl;
            if (isAdmin(us))
                menuAdmin(us.login);
            else
            {
                system("cls");
                cout << setfill('-') << setw(110) << "Вы вошли в роли пользователя с логином "<<us.login << setw(90) << "-" << endl;
                menuUserData(us.login);
            }
            system("cls");
        }
        else if (ch == ESC)
        {
            system("cls");
            cout << "\n\nА Вы уверены,что хотите выйти?\n";
            if (isConfirmation()) exit(0);
        }
        else
            system("cls");
    } while (true);
}
    

