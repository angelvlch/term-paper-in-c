#include<iostream>
#include<fstream>
#include<conio.h>
#include "account.h"
#include <iomanip>
#include "check.h"
#include "task.h"
vector <User> v = loadIVector();

vector<User> loadIVector()
{
    vector <User> vv;
    ifstream file;
    file.open("pass.txt");
    if (!file.is_open()) {
        cout << "Файл не существует!";
        exit(0);
    }
    
    vv.reserve(getCountOfUser());
    if (!file.is_open()) cout << "Файл не существует!";
    else
    {
        User p;
        int n = 0;
        while (n != getCountOfUser())
        {
           
            file >> p.login >> p.passwordWithSalt >> p.salt>>p.role>>p.accept;
            
            vv.push_back(p); n++;
        }
    }
    file.close();
    return vv;
}
void fromVectorToFile(vector<User> v)
{
    ofstream file;
    file.open("pass.txt");
    if (!file.is_open()) {
        cout << "Файл не существует!";
        exit(0);
    }
    for (int i = 0; i < v.size(); i++)
    {
        file << v[i].login << ' ' << v[i].passwordWithSalt << ' ' << v[i].salt << ' ';
        file << v[i].role<< ' ' << v[i].accept << endl;

    }
    file.close();
}


void menuAdminAcc(string admin)
{
    /*vector <User> v = loadInVector();*/
    system("cls");
    char ch= -1;
    const char ESC = 27;
    while (true)
    {
        cout << setfill('-') << setw(210) << "-" << endl;
        cout << "Выберите вариант действий:" << endl;
        cout << "1. Просмотр учётных записей" << endl;
        cout << "2. Регистрация учётной записи" << endl;
        cout << "3. Редактирование учётной записи" << endl;
        cout << "4. Удаление учётной записи" << endl;
        cout << "5. Подтверждение учетной записи" << endl;
        cout << "6. Просмотр купленных билетов у пользователя" << endl;
        cout << "7. Блокировка учетной записи" << endl << endl;
        cout << "ESC вернуться назад" << endl;
        ch = _getch();
   
        switch (ch)
        {
        case '1':
            system("cls");
            headUsers();
            for(int i=0;i<v.size();i++)
            showUsers(i);
            break;
        case '2':
            system("cls");
            registration(1);
            break;
        case '3':
            system("cls");
            edit(admin);
            break;
        case '4':
            system("cls");
            deleteUser(admin);
            break;
        case '5':
            system("cls");
            access();
            break;
        case '6':
            system("cls");
            showTickets();
            break;
        case '7':
            system("cls");
            block(admin);
            break;
        case ESC:
            system("cls");
            return;
        default:
            system("cls");
            cout << "\aНеверный ввод,попробуйте еще раз!"<<endl;
        }
        fromVectorToFile(v);
    }

}

void showTickets()
{
    headUsers();
        for (int i = 0; i < v.size(); i++)
        {
            showUsers(i);
        }
    cout << "\nВведите логин у которого хотите посмотреть билеты\n";
    string login;
    cin >> login;
    showBasket(login);

    
}

void block(string admin)
{
    headUsers();
    for (int i = 0; i < v.size(); i++)
    {
            showUsers(i);
    }

        while (true)
        {
            string log;
            cout << "Какой логин хотите заблокировать?Введите логин: ";
            cin >> log;
            int i = 0;
            bool s = true;
            while (log != v[i].login) {
                i++;
                if (i == v.size())
                {
                    s = false;
                    cout << "\a\nВведен неверный логин!\n";
                    break;
                }
            }
            if (!s)
                break;
            if (admin == v[i].login)
            {
                cout << "\nНельзя заблокировать активный пользователь администратора!\n";
                break;
           }
            v[i].accept = -1;
            cout << "\nПользователь с логином " << v[i].login << " заблокирован!\n";
            cout << "\nХотие заблокировать еще? ";
            if (!isConfirmation())
            {
                system("cls");
                break;
            }
            
        }
}
void access()
{
    bool is = false;
  
    for (int i = 0; i < v.size(); i++)
    {
        if (v[i].accept == 0)
        {
           
            if (is == false)
            {
                is = true;
                
                headUsers();
                
            }
            showUsers( i );

        }
   }
    if (!is)
        cout << "\nПользователи,ожидающие подтверждения,не найдены\n";
    else
    {
        cout << "Пользователи,ожидающие подтверждения\n\n\n";
        while(true)
        {
            string log;
            cout << "\n\nКакой логин хотите подтвердить?Введите логин ";
            cin >> log;
            int i = 0;
            bool s = true;
            while (log != v[i].login) {
                i++;
                if (i == v.size())
                {
                    s = false;
                    cout << "\a\nВведен неверный логин!\n";
                    break;
                }
            }
            if (!s)
                break;
            
            v[i].accept = 1;
            cout << "\nПользователь с логином " << v[i].login << " подтвержден!\n";

            cout << "\nХотие подтвердить еще? ";
            if (!isConfirmation())
            {
                system("cls");
                break;
            }

        }
      
          
    }
}
void headUsers()
{
    system("cls");
    cout << setfill(' ') << setiosflags(ios::left) <<"№" << setw(3) << "|" << setw(10) << "Логин" << "|";
    cout << setw(20) << "Роль"<<"|" << setw(20) << "Доступ" << "|" << endl;
    cout << std::setfill('-') << setw(57) << "-" << setfill(' ') << setw(0) << endl;
}
void showUsers(int i)
{
   
        cout<<setfill(' ')<<setiosflags(ios::left) << i+1 << setw(3)<<"|" << setw(10) << v[i].login << "|";
        cout << setw(20);
        if (v[i].role == 1)
            cout << "Администратор";
        else 
            cout << "Пользователь";

      cout << "|" << setw(20);
        if (v[i].accept == 1)
            cout << "Подтвержденный";
        else if (v[i].accept == 0)
            cout << "Не подтвержденный";
        else
            cout << "Зaблокированный";
       cout<< "|" << endl;
       cout << std::setfill('-') << setw(57) << "-" << setfill(' ') << setw(0) << endl;
}

void registration(int acc)
{
    User u;
    do {
        cout << "Введите логин: ";
        cin >> u.login;
    } while (!isIndividual(u.login));
    cout << endl;
    enterPassword(u.passwordWithSalt);
    cout << endl;
    generateSalt(u.salt);
    u.passwordWithSalt += u.salt;
    u.passwordWithSalt = crypt(u.passwordWithSalt);
    while (true)
    {
        cout << "Введите роль(0 - пользватель /1 - администратор): ";
        cin >> u.role;
        if (u.role == 1 || u.role == 0)
            break;
    }
 
    system("cls");
    if (acc == 0)
        cout << "\nЖдите подтерждения администратора!\n";
    else
    {
        cout << "Аккаунт успешно добавлен!!\n";
        u.accept = 1;
    }
    v.push_back(u);
    fromVectorToFile(v);
}

bool isIndividual(string login)
{

    int n = getCountOfUser();
    while (n!=0)
    {

        if (v[n-1].login == login)
        {
            cout << "Такой логин уже существует!Придумайте новый\n";
            return false;
        }
        n--;
    }
   
    return true;
}

int getCountOfUser()
{
    ifstream file;
    file.open("pass.txt");
    if (!file.is_open()) {
        cout << "Файл не существует!";
        exit(0);
    }
    int n = 0;
    string buff;
    while (getline(file, buff))
    {
        if (buff.empty());
        else {
            n++;
        }
    }
    file.close();
    return n;
}

void edit(string admin)//
{
    headUsers();
    for(int i=0;i<v.size();i++)
    showUsers(i);
    int c, c1 = 0;
    do
    {
        cout << "\nВведите номер аккаунта для редактирования: ";
        cin >> c;
    } while (!isNumberNumeric() || !isNumberRangeCorrect(c, 0, getCountOfUser() + 1));;
    system("cls");
    cout << "Вы уверены,что хотите редактировать запись под номером " << c << "? ";
    if (!isConfirmation())
        return;

            if (v[c-1].role == 1&&v[c-1].login==admin)
            {
                cout << "\n\aНевозможно отредактировать текущий аккаунт администратора!\n";
                return;
            }        
                editUser(c);
    cout << "\nЗапись отредактирована\n";
}
void editUser(int index)
{
    string login;
    cout << "\nВыберите параметр для редактирования\n1. Логин\n2. Пароль\n3. Роль\n";
    switch (_getch())
    {
    case '1':
       
        do {

            cout << "Введите логин: ";
            cin >>login;
        } while (!isIndividual(login));
        v[index - 1].login = login;
        break;
    case '2':
        enterPassword(v[index-1].passwordWithSalt);
        cout << endl;
        generateSalt(v[index-1].salt);
        v[index - 1].passwordWithSalt += v[index - 1].salt;
        v[index - 1].passwordWithSalt = crypt(v[index - 1].passwordWithSalt);
        break;
    case '3':
       
            do {
                cout << "Введите роль(0 - пользователь /1 - администратор): ";
                cin >> v[index - 1].role;
            } while (!isNumberNumeric() || !isNumberRangeCorrect(v[index - 1].role, -1, 2));          
        
      
    
     default:
            cout << "\n\aНеккоректный ввод,попробуйте еще раз\n";
    }
    
}
void deleteUser(string admin)//
{
    headUsers();
    for(int i=0;i<v.size();i++)
    showUsers(i);
    int c = 0;
    do
    {
        cout << "\nВведите номер аккаунта для удаления: ";
        cin >> c;
    } while (!isNumberNumeric()||!isNumberRangeCorrect(c,0,getCountOfUser()+1));

    if (v[c-1].role==1 && v[c-1].login == admin)
    {
        cout << "\a\nНевозможно удалить текущий аккаунт администратора!\n";
        return;
    }
    cout << "Вы уверены,что хотите удалить пользователя под номером " << c << "?";
    if (isConfirmation())
    {
        v.erase(v.begin() + c - 1);
        system("cls");
        cout << "\nЗапись под номером " << c<< " успешно удалена!\n";
        return;
    }
    cout << "Запись не удалена" << endl;
}
bool check_login( User& us)
{
    int n = getCountOfUser();
    for (int i = 0; i < n; i++)
    {
        if (v[i].login == us.login && v[i].passwordWithSalt == us.passwordWithSalt)
        {
            
            us.role = v[i].role;
            us.accept = v[i].accept;
            return true;
        }
    }
    return false;
}

bool isAdmin(User us)
{
    if (us.role==1)
        return true;
    else
        return false;
}
string getSalt(string login)
{
    for (int i = 0; i < getCountOfUser(); i++)
    {
        if (v[i].login == login )
            return v[i].salt;
    }
    return "0";
}
bool login_password(User& us)
{
  
     cout << endl;
        cout << "Введите логин: ";
        cin >> us.login;
        cout << endl;
        enterPassword(us.passwordWithSalt);
        us.salt = getSalt(us.login);
        if (us.salt == "0")
        {
            system("cls");
            cout << "\n\aНеверный логин или пароль!\n";
            us.passwordWithSalt.clear();
            return false;
        }
        us.passwordWithSalt += us.salt;
        us.passwordWithSalt=crypt(us.passwordWithSalt);
        if (check_login(us))
        {
            if (us.accept == 0)
            {
                cout << "\nВаш аккаунт не подтвержден администратором,войдите позже\n";
                return false;
            }
            else if (us.accept == -1)
            {
                cout << "\nВаш аккаунт заблокирован администратором\n";
                return false;
            }
            else
                return true;
        }
        system("cls");
        cout << "\n\aНеверный логин или пароль!\n";    
        us.passwordWithSalt.clear();
        return false;
    
}

void enterPassword(string& password)
{
    cout << "Введите пароль: ";
    char c;
    while ((c = _getch()) != '\r')
    {
        if (c == '\b' && !password.empty()) {
            password.pop_back();
            cout << "\b \b";
        }
        else if (isprint(c)) {
            password.push_back(c);
            cout << "*";
        }
    }
}