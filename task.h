#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include "data.h"
#include <time.h>
using namespace std;

struct Ticket {
	string login;
	int numberTicket=0;
	int clas=0;
	string flight;
};


void solveTask(vector<plane>&,string);
void findTicket(vector<plane>&,int, int, int,string);
void findInThisMonth(vector <plane> );
vector<Ticket> loadInVec();
void fromVectorToFile(vector <Ticket>);
int getCountOfTicket();
void basket(vector <plane>,string);
void showBasket(string);
