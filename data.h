#pragma once
#include <iostream>
#include <vector> 
#include <iterator> 
#include <algorithm>
#include <iomanip>
#include <string>
struct plane
{
    int capacity, day, month, year;
    int ticketsLeftB, ticketsLeftE;
    int start_hour, start_minute;
    int end_hour, end_minute;
    double priceE, priceB;
   std:: string flight, type, arrival;
};
 

void editData();
void add(std::vector<plane>&);
void show(std::vector<plane>,int );
std::vector<plane> edit(std::vector<plane>);
void delet(std::vector<plane>&);
void headTable();
