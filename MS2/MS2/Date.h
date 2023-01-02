/* ------------------------------------------------------
Milestone 2
Module: Date
Filename: Date.h
Version 1.1
Author: Devang Ramubhai Ahir Ahir
Revision History
-----------------------------------------------------------
Date          Reason
27/03/2022
-----------------------------------------------------------*/

#ifndef SDDS_DATE_H
#define SDDS_DATA_H
#include"Status.h"
#include <iostream>

namespace sdds
{
	const int MAXIMUM_YEAR_VALUE = 2030;
	class Date
	{
		int Year;
		int Month;
		int Day;
		Status status;
		bool Format;

		bool validate();
		int unique_date_value();

	public:
		Date();
		Date(int y, int m, int d);
		~Date();
		bool operator ==(Date& d);
		bool operator !=(Date& d);
		bool operator <(Date& d);
		bool operator >(Date& d);
		bool operator <=(Date& d);
		bool operator >=(Date& d);
		Status& state();
		Date& formatted(bool flag = false);
		operator bool() const;
		std::ostream& write(std::ostream& ostr = std::cout)const;
		std::istream& read(std::istream& istr = std::cin);
		friend std::ostream& operator<<(std::ostream& ostr, const Date& d);
		friend std::istream& operator>>(std::istream& istr, Date& d);
	};

	std::ostream& operator<<(std::ostream& ostr, const Date& d);
	std::istream& operator>>(std::istream& istr, Date& d);

}
#endif // !SDDS_DATE_H
