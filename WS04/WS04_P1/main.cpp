/* ------------------------------------------------------
Workshop 4 part 1
Module: N/A
Filename: main.cpp
Version 1.0
Author: Asad Norouzi  Fall of 2021
Revised by: Fardad Soleimanloo
Revision History
-----------------------------------------------------------
Initials   Date           Reason
F.S.	     04/02/2022     Added covered topics and simplifed.
-----------------------------------------------------------*/


#include<iostream>
#include<iomanip>
#include "CarInventory.h"

using namespace std;
using namespace sdds;

int main()
{
	const int num_cars = 6;
	bool invalid_data = false;
	CarInventory cars[num_cars] = {
		{},
		{"suv", "volvo", "xc90"},
		{"Truck", "Ford", "F 150", 2021, 105, 55000},
		{"Sedan", "BMW", "M550i", 2022, 101, 91000},
		{"Truck", "Tesla", "Cybertruck", 2021, 102, 65000},
		{"Sedan", "BMW", "M550i"}
	};

	if (cars[2].setInfo("SUV", "Volvo", "XC90", 2019, 109, 80000).isValid()) {
		cout << "Information was set correctly!" << endl;
	}
	else {
		cout << "Information was set incorrectly!" << endl;
	}
	if (cars[1].setInfo("SUV", "Volvo", "XC90", 1234, 1, 1).isValid()) {
		cout << "Information was set correctly!" << endl;
	}
	else {
		cout << "Information was set incorrectly!" << endl;
	}


	cout << setw(60) << "----- Car Inventory Information -----" << endl << endl;;
	cout << "| Type       | Brand            | Model            | Year | Code |     Price |" << endl;
	cout << "+------------+------------------+------------------+------+------+-----------+" << endl;
	for (int i = 0; i < num_cars; i++) {
		if (cars[i].isValid())
			cars[i].printInfo();
		else
			invalid_data = true;
	}

	if (invalid_data) {
		cout << endl;
		cout << setfill('*') << setw(60) << "*" << endl;
		cout << "*  WARNING: There are invalid data in the inventory!      *" << endl;
		cout << setfill('*') << setw(60) << "*" << endl;
	}
	if (find_similar(cars, num_cars)) {
		cout << endl;
		cout << setfill('+') << setw(60) << "+" << endl;
		cout << "+  WARNING: There are similar entries in the inventory!   +" << endl;
		cout << setfill('+') << setw(60) << "+" << endl;
	}
	return 0;
}