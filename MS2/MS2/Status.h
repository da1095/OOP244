/* ------------------------------------------------------
Milestone 2
Module: Status
Filename: Status.h
Version 1.1
Author: Devang Ramubhai Ahir Ahir
Revision History
-----------------------------------------------------------
Date          Reason
27/03/2022
-----------------------------------------------------------*/

#ifndef SDDS_STATUS_H
#define SDDS_STATUS_H

#include<ostream>

namespace sdds
{
	class Status
	{
		char* Description = nullptr;
		int Codigo;// Spanish word for code is codigo
	public:
		Status(const char* desc = nullptr);

		Status& operator=(int num);
		Status& operator=(const char* source);
		operator int() const;
		operator const char* () const;
		operator bool() const;
		Status& clear();
		friend std::ostream& operator<<(std::ostream& ostr, const Status& st);
	};
	std::ostream& operator<<(std::ostream& ostr, const Status& st);
}
#endif // !SDDS_STATUS_H
