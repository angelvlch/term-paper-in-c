#pragma once
#include <string>
#include "heshWithSalt.h"
#include <vector> 
#include <iterator> 
#include <algorithm>
#include <vector> 

using namespace std;
struct User
{
    string login, passwordWithSalt, salt;
    bool role=false;
    int accept = 0;
  
};
void access();
void menuAdminAcc(string);
void showUsers(int);
void headUsers();
void registration(int );
void edit(string);
void editUser(int);
void deleteUser(string); 
bool login_password(User&);
bool isAdmin(User);
bool isIndividual(string);
int getCountOfUser();
void enterPassword(string&);
string getSalt(string );
void accauntWithoutAccept(User );
void block(string);
void fromVectorToFile(vector<User> );
vector<User> loadIVector();
void showTickets();