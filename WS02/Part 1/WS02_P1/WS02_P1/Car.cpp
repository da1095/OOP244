/* ------------------------------------------------------
Workshop 2 part 1
Module: Cars
Filename: Car.cpp
Version 1
Author	Devang Ramubhai Ahir Ahir
Stu. ID 153484209
-----------------------------------------------------------
Date  1/22/2022     Reason
-----------------------------------------------------------*/
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "Car.h"
using namespace sdds;
using namespace std;

namespace sdds {

	Car* cars = nullptr;
	int allocationSize;
	int car_Array;
	int no_of_car;



	void VBPLE_Title() {
		cout << "Vehicle Border Passing Log Entry\n";
		cout << "Enter the data in the following format: \n";
		cout << "Make and model,LicensePlate,MilitaryTime<ENTER>\n";
		cout << "Exit the program by entering the following:\n";
		cout << "X,<ENTER>\n";

	}
	void initialize(int allocSize) {
		no_of_car = 0;
		allocationSize = car_Array = allocSize;
		cars = new Car[allocSize];

	}
	void deallocate(Car& C) {
		if (C.car_model != nullptr) {
			delete[] C.car_model;
		}
	}
	bool read(Car& C) {
		bool flag = false;
		char makeModel[61];
		int j;

		for (j = no_of_car; j < car_Array; j++) {

			read(makeModel, 61, ',');
			if (strCmp(makeModel, "X") != 0) {
				flag = true;

				cars[j].car_model = new char[strLen(makeModel) + 1];
				strCpy(cars[j].car_model, makeModel);

				read(cars[j].license_plate, 8, ',');
				cin >> cars[j].time;
				no_of_car++;
			}
			else
			{
				j = car_Array;
				flag = false;
			}
		}
		return flag;
	}
	void print(const Car& C) {
		cout << C.time << ": " << C.car_model << "," << C.license_plate << "\n";
	}
	void record(const Car& C) {

		if (no_of_car == car_Array) {
			Car* temp_cars = nullptr;
			int i;
			temp_cars = new Car[car_Array + allocationSize];
			for (i = 0; i < car_Array; i++) {
				temp_cars[i] = cars[i];
			}
			delete[] cars;
			cars = temp_cars;
			car_Array = car_Array + allocationSize;
		}
	}



	void endOfDay() {
		int i;
		for (i = 0; i < no_of_car; i++) {
			print(cars[i]);
			deallocate(cars[i]);
		}
		delete[] cars;
	}
}