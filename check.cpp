#include "check.h"
#include <iostream>
#include<conio.h>
using namespace std;

bool isNumberNumeric()
{
	if (cin.get() == '\n')
		return true;

	else
	{
		cin.clear();
		cin.ignore(std::numeric_limits<streamsize>::max(), '\n'); 
		cout << "\a\n ������������ ����!��������� ������ �����!! ��������� �������\n";
		return false;
	}
}
bool isNumberRangeCorrect(int number, int left_range,int right_range)
{
	if (number > left_range && number < right_range)
		return true;
	cout << "����� �� �������!\n";
	return false;
}
bool isConfirmation()
{
	cout << " ������� Enter ��� ������������� ��� ������ ����� ������� ��� ������ ";
	char ch = 0;
	ch=_getche();
	if (ch == 13)
		return true;

	return false;
}
bool isString(string str)
{
	for (int k = 0; k< str.size(); k++)
	{

		if ((str[k] < 'a' || str[k]>'z') && (str[k] < 'A' || str[k]>'Z'))
		{
			cout<<"\a\n������! ��������� ������ �����!";
			return false;
		}
		
	}
	return true;
}