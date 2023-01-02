/* ------------------------------------------------------
Workshop 2 part 2
Module: Cars
Filename: cStrTools.h
Version 1
Author	Devang Ramubhai Ahir Ahir
Stu. ID 153484209
-----------------------------------------------------------
Date  2022     Reason
-----------------------------------------------------------*/
#ifndef NAMESPACE_CAR_H // replace with relevant names
#define NAMESPACE_CAR_H
#include <string>
#include "cStrTools.h"


using namespace std;
namespace sdds {

	// Your header file content goes here
	struct Car {
		char license_plate[9];// license plate
		char* car_model;// make and model
		int time;// the time in military format
	};


	void VBPLE_Title();
	void initialize(int allocSize);
	void deallocate(Car& C);
	bool read(Car& C);
	void print(const Car& C);
	void record(const Car& C);
	void endOfDay();
}
#endif
