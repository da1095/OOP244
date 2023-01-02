/* ------------------------------------------------------
Milestone 2
Module: AidMan
Filename: AidMan.cpp
Version 1.1
Author: Devang Ramubhai Ahir Ahir
Revision History
-----------------------------------------------------------
Date          Reason
27/03/2022
-----------------------------------------------------------*/

#include "AidMan.h"
#include <iostream>
#include<string.h>
using namespace std;

namespace sdds
{
	unsigned int AidMan::menu() const
	{
		cout << "Aid Management System Version 0.1\n";
		cout << "Date: 2022/03/31\n";
		if (File == nullptr || strcmp(File, ""))
			cout << "Data file: No file\n";
		else
			cout << "Data file:  " << File << "\n";
		cout << "---------------------------------\n";

		return Menu_Obj.run();
	}
	AidMan::AidMan()
	{
		Menu_Obj.setMenu("1- List Items\n2- Add Item\n3- Remove Item\n4- Update Quantity\n5- Sort\n6- Ship Items\n7- New/Open Aid Database\n---------------------------------\n", 7);
		File = nullptr;
	}
	AidMan::~AidMan()
	{
	}
	void AidMan::run()
	{
		int n;

		do
		{
			n = menu();
			switch (n)
			{
			case 1:
				cout << "\n****List Items****\n\n";
				break;
			case 2:
				cout << "\n****Add Item****\n\n";
				break;
			case 3:
				cout << "\n****Remove Item****\n\n";
				break;
			case 4:
				cout << "\n****Update Quantity****\n\n";
				break;
			case 5:
				cout << "\n****Sort****\n\n";
				break;
			case 6:
				cout << "\n****Ship Items****\n\n";
				break;
			case 7:
				cout << "\n****New/Open Aid Database****\n\n";
				break;
			case 0:
				cout << "Exiting Program!\n";
				break;
			}


		} while (n != 0);
	}
}