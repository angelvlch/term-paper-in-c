#include "task.h"
#include <iostream>
#include <string>
#include "check.h"
#include "file.h"
//#include <fstream>
using namespace std;



int getCountOfTicket()
{
    ifstream file;
    file.open("tickets.txt");
    int n = 0;
    string buff;
    while (getline(file, buff))
    {
        if (buff.empty());
        else {
            n++;
        }
    }
    return n;
}
vector<Ticket> loadInVec()
{
    vector <Ticket> vvv;
    ifstream file;
    file.open("tickets.txt");
    if (!file.is_open()) {
        cout << "���� �� ����������!";
        exit(0);
    }

    vvv.reserve(getCountOfTicket());
    if (!file.is_open()) cout << "���� �� ����������!";
    else
    {
        Ticket p;
        int n = 0;
        while (n != getCountOfTicket())
        {

            file >> p.login >> p.numberTicket >> p.clas >> p.flight;

            vvv.push_back(p); n++;
        }
    }
    file.close();
    return vvv;
}
void fromVectorToFile(vector <Ticket> l)
{
    ofstream file;
    file.open("tickets.txt");
    if (!file.is_open()) {
        cout << "���� �� ����������!";
        exit(0);
    }
    for (int i = 0; i < l.size(); i++)
    {
        file << l[i].login << ' ' << l[i].numberTicket << ' ' << l[i].clas << ' ';
        file << l[i].flight<< endl;

    }
    file.close();
}

void solveTask(vector<plane>& vec,string use)
{
 
    system("cls");
    const string error = "\a�������� ����,���������� ��� ���\n";
    headTable();
    for (int i = 0; i < vec.size(); i++)
        show(vec, i);
    int index;
    do
    {
        cout << "\n�� ����� ���� ������ ������ ������? ������� ����� �� ���� ������:\n";
        cin >> index;
        if (index > vec.size())
            cout << "\n����� ������ ���,��������� ����!\n";
    } while (index > vec.size());
    index--;
    int n;
    do
    {
        cout << "\n������� ���������� �������:";
        cin >> n;
    } while (!isNumberNumeric());
    int clas;
    do
    {
        cout << "\n����� ����� ��� ����������? 1-������-�����,0-������-�����.";
        cin >> clas;
        if (clas != 1 && clas != 0)
            cout << error;
    } while (clas != 1 && clas != 0);
    system("cls");
    cout << setfill('-') << setw(210) << "-" << endl;
    findTicket(vec, index, n, clas,use);
}

void findTicket(vector<plane>& v, int index, int numTickets, int ticketClass,string user) {

    Ticket tt;
    vector <Ticket> l=loadInVec();
            if (ticketClass == 1 && v[index].ticketsLeftB >= numTickets) {
                
                tt.clas = 1;
                tt.flight = v[index].flight;
                tt.login = user;
                tt.numberTicket = numTickets;
                l.push_back(tt);
                v[index].ticketsLeftB -= numTickets;
                fromVectorToFile(l);
                cout << "������ �� ���� " << v[index].flight << "� ���������� "<<numTickets<<" ���������� "<<v[index].priceB*numTickets<<" ������ � ������ - ������ ������� �������!" << endl;
                return;
            }
            else if (ticketClass == 0 && v[index].ticketsLeftE >= numTickets) {
                tt.clas = 0;
                tt.flight = v[index].flight;
                tt.login = user;
                tt.numberTicket = numTickets;
                l.push_back(tt);
                v[index].ticketsLeftE -= numTickets;
                fromVectorToFile(l);
                cout << "������ �� ���� " << v[index].flight << " � ����������" << numTickets << " ���������� " << v[index].priceE * numTickets << " ������ � ������ - ������ ������� �������!" << endl;
                return;
            }

   
        cout << setfill(' ')<< "�� ���� " << v[index].flight << " � ��������� ������ ��� "<<numTickets<<" ����!" << endl;
        if (ticketClass == 1&&v[index].ticketsLeftE>=numTickets) {
            cout << setfill(' ')<<" " << " ������ ������ ������ � ������-������? (��-1/���-2) ";
            int answer;
            cin >> answer;
            if (answer == 1) {
                findTicket(v, index, numTickets, 0,user);
            }
        }
        else if (ticketClass == 0 && v[index].ticketsLeftB >= numTickets) {
            cout << setfill(' ') <<" " << " ������ ������ ������ � ������-������? (��-1/���-2) ";
           int answer;
           cin >> answer;
            if (answer == 1) {
                findTicket(v, index, numTickets, 1,user);
            }
        
    }
}


void findInThisMonth(vector <plane> vec)
{

    time_t currentTime = time(nullptr);
    tm* localTime = localtime(&currentTime);
    int year = 1900 + localTime->tm_year;
    int month = 1 + localTime->tm_mon;
    bool is = false;
    for (int i = 0; i < vec.size(); i++)
    {
        if (year == vec[i].year && month == vec[i].month)
        {
            if (!is)
            {
                
                headTable();
                is = true;
            }
            show(vec,i);
        }
    }
    cout << "\n���������� � ������,���������� � ���� ������\n\n";
    if (!is)
        cout << "\n������,�������������� � ���� ������ �� �������!\n";

}
void basket(vector <plane> v, string login)
{
    system("cls");
    vector <Ticket> ticket = loadInVec();
    bool is = false;
    plane p; int count = 0;
    for (int i = 0; i < ticket.size(); i++) {
        if (login == ticket[i].login)
        {
            if (!is)
            {
                is = true;
                cout << "\n  ��������� ������: ";
            }
            int l = 0;
            cout << setiosflags(ios::right);
            while (v[l].flight != ticket[i].flight)l++;
            
            cout << "\n               �" << ++count << endl;
            cout << setw(15) << setfill(' ') << "-" << setw(36) << setfill('-') << "-" << endl;
            cout << setw(15) << setfill(' ') << "|" << "����� �����" << setw(12) << setfill('-') << "|" << setw(12) << setfill(' ')<< v[l].flight << "|" <<endl;
            cout << setw(15) << setfill(' ') << "|" << "��� ��������" << setw(11) << setfill('-') << "|" << setw(12) << setfill(' ') << v[l].type << "|" << endl;
            cout << setw(15) << setfill(' ') << "|" << "����� ����������" << setw(7) << setfill('-') << "|" << setw(12) << setfill(' ') << v[l].arrival << "|" << endl;
            cout << setw(15) << setfill(' ') << "|" << "���� ������" << setw(12) << setfill('-') << "|" << setw(2) << setfill(' ') << " ";
            if (v[l].day < 10)
                cout << 0;
         
            cout << v[l].day << ".";
            if (v[l].month < 10)
                cout << 0;
      
            cout<< v[l].month << "." << v[l].year << "|" << endl;
            cout << setw(15) << setfill(' ') << "|" << "����� ������" << setw(11) << setfill('-') << "|" << setw(7) << setfill(' ') << " ";
            if (v[l].start_hour < 10)
                cout << 0;
            cout << v[l].start_hour << ":";
            if (v[l].start_minute < 10)
                cout << 0;
            cout<< v[l].start_minute << "|" << endl;
            cout << setw(15) << setfill(' ') << "|" << "����� �������" << setw(10) << setfill('-') << "|" << setw(7) << setfill(' ') << " ";
            if (v[l].end_hour < 10)
                cout << 0;
            cout << v[l].end_hour << ":";
            if (v[l].end_minute < 10)
                cout << 0;
              cout  << v[l].end_minute << "|" << endl;
              cout << setw(15) << setfill(' ') << "|" << "�����" << setw(18) << setfill('-') << "|" << setw(12) << setfill(' ');
              
              if (ticket[i].clas == 1)
                  cout << "������";
              else
                  cout << "������";
              cout<< "|" << endl;
            cout << setw(15) << setfill(' ') << "|" << "����� �������" << setw(10) << setfill('-') << "|" << setw(12) << setfill(' ') << ticket[i].numberTicket << "|" << endl;
            cout << setw(15) << setfill(' ') << "-" << setw(36) << setfill('-') << "-" << endl;

        }
    }
    if (!is)
        cout << "������� �����!\n";
}

void showBasket(string login)
{
    vector <plane> vv = loadInVector();
    basket(vv, login);
}