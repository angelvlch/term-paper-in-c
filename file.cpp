#include<iostream>
#include "file.h"
#include <string>

using namespace std;

int getCountOfPlane()
{
    ifstream file;
    file.open("data.txt");
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
vector<plane> loadInVector()
{
    ifstream file;
    file.open("data.txt");
    vector<plane> vector_plane;
    vector_plane.reserve(getCountOfPlane());

    if (!file.is_open()) cout << "Файл не существует!";
    else
    {
        plane p;
        int n = 0;
        while (n != getCountOfPlane())
        {
            file >> p.flight;
            file >> p.type;
            file >> p.arrival;
            file >> p.day >> p.month >> p.year;
            file >> p.start_hour;
            file >> p.start_minute;
            file >> p.end_hour;
            file >> p.end_minute;
            file >> p.capacity;
            file >> p.ticketsLeftB;
            file >> p.ticketsLeftE;
            file >> p.priceB;
            file >> p.priceE;

            vector_plane.push_back(p); n++;
        }
    }
    file.close();
    return vector_plane;
}
void fromVectorToFile(vector<plane> v)
{
    ofstream file;
    file.open("data.txt");
    for (int i = 0; i < v.size(); i++)
    {
        file << v[i].flight << ' ' << v[i].type << ' ' << v[i].arrival << ' ';
        file << v[i].day << ' ' << v[i].month << ' ' << v[i].year << ' ';
        file << v[i].start_hour << ' ' << v[i].start_minute << ' ' << v[i].end_hour << ' ';
        file << v[i].end_minute << ' ' << v[i].capacity << ' ';
        file << v[i].ticketsLeftB << ' ' << v[i].ticketsLeftE << ' ' << v[i].priceB << ' ' << v[i].ticketsLeftE << endl;

    }
    file.close();
}
