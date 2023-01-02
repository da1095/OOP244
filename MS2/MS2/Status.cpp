/* ------------------------------------------------------
Milestone 2
Module: Status
Filename: Status.cpp
Version 1.1
Author: Devang Ramubhai Ahir Ahir
Revision History
-----------------------------------------------------------
Date          Reason
27/03/2022
-----------------------------------------------------------*/

#include"Status.h"
#include <string.h>
#include"Utils.h"
#include<ostream>

namespace sdds
{
	Status::Status(const char* desc)
	{
		if (desc != nullptr)
		{
			ut.alocpy(Description, desc);
		}
		else
			ut.alocpy(Description, "");
		Codigo = 0;
	}

	Status& Status::operator=(int num)
	{
		Codigo = num;
		return *this;
	}
	Status& Status::operator=(const char* source)
	{
		ut.alocpy(Description, source);
		return *this;
	}
	Status::operator int() const
	{
		return Codigo;
	}
	Status::operator const char* () const
	{
		return Description;
	}
	Status::operator bool() const
	{
		if (Description == nullptr)
			return true;
		else
			return false;
	}
	Status& Status::clear()
	{
		delete[] Description;
		Description = nullptr;

		Codigo = 0;

		return *this;
	}

	std::ostream& operator<<(std::ostream& ostr, const Status& st)
	{
		if (int(st) != 0)
			ostr << "ERR#" << st.Codigo << ": ";

		if (!st)
			ostr << st.Description;

		return ostr;
	}
}