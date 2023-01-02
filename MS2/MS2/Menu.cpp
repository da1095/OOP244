/* ------------------------------------------------------
Milestone 2
Module: Menu
Filename: Menu.cpp
Version 1.1
Author: Devang Ramubhai Ahir Ahir
Revision History
-----------------------------------------------------------
Date          Reason
27/03/2022
-----------------------------------------------------------*/

#define _CRT_SECURE_NO_WARNINGS
#include "Menu.h"
#include <iostream>
#include<string.h>
using namespace std;

namespace sdds
{
	Menu::Menu()
	{
		Content = nullptr;
		Option = 0;
	}
	Menu::~Menu()
	{
		delete[] Content;
	}
	unsigned int Menu::run() const
	{
		int n;

		cout << Content;
		cout << "0- Exit\n> ";
		cin >> n;
		while (!cin)
		{
			cout << "Invalid Integer, retry: ";
			cin.clear();
			cin.ignore(1000, '\n');
			cin >> n;
		}

		while (n<0 || n>int(Option))
		{
			cout << "Value out of range [0<=val<=" << Option << "]: ";
			cin >> n;
		}

		return n;
	}
	void Menu::setMenu(const char* cString, int n)
	{
		if (Content == nullptr || strcmp(Content, "") == 0)
		{
			Content = new char[strlen(cString) + 1];
			strcpy(Content, cString);
		}
		Option = n;
	}
}