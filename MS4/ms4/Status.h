/* ------------------------------------------------------
Milestone 4
Module: Status
Filename: Status.h
Version 1.1
Author: Devang Ramubhai Ahir Ahir
Revision History
-----------------------------------------------------------
Date          Reason
07/04/2022
-----------------------------------------------------------*/
#ifndef SDDS_STATUS_H
#define SDDS_STATUS_H
#include <cstring>
#include <iostream>
using namespace std;
namespace sdds
{
	class Status
	{
	public:
		char* Description;
		int Codigo;// Spanish word for code is codigo
		Status(char* str = nullptr, int code = 0);
		Status(const Status& status);
		Status& operator=(const Status& status);
		~Status();
		Status& operator=(const char* str);
		Status& operator=(const int code);
		operator bool() const;
		operator int() const;
		operator char* () const;
		friend ostream& operator<<(ostream& os, const Status& status);
		Status& clear();
	};
}

#endif // !SDDS_STATUS_H