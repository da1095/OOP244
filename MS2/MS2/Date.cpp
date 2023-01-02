/* ------------------------------------------------------
Milestone 2
Module: Date
Filename: Date.cpp
Version 1.1
Author: Devang Ramubhai Ahir Ahir
Revision History
-----------------------------------------------------------
Date          Reason
27/03/2022
-----------------------------------------------------------*/

#include "Date.h"
#include "Utils.h"
#include <iostream>
#include<iomanip>
#include <string>
using namespace std;

namespace sdds
{
	bool Date::validate()
	{
		bool valid = true;
		int currentYear;
		ut.getSystemDate(&currentYear);

		if (Year<currentYear || Year>MAXIMUM_YEAR_VALUE)
		{
			status = "Invalid year in date";
			status = 1;
			valid = false;
			return valid;
		}
		if (Month < 1 || Month>12)
		{
			status = "Invalid month in date";
			status = 2;
			valid = false;
			return valid;
		}
		if (Day<1 || Day>ut.daysOfMon(Month, Year))
		{
			status = "Invalid day in date";
			status = 3;
			valid = false;
			return valid;
		}

		if (valid)
			status.clear();

		return valid;
	}

	int Date::unique_date_value()
	{
		return Year * 372 + Month * 31 + Day;
	}

	Date::Date()
	{
		ut.getSystemDate(&Year, &Month, &Day);
		Format = true;
	}

	Date::Date(int year, int month, int day)
	{
		Year = year;
		Month = month;
		Day = day;
		Format = true;

		validate();
	}

	bool Date::operator==(Date& d)
	{
		if (unique_date_value() == d.unique_date_value())
			return true;
		else
			return false;
	}

	bool Date::operator!=(Date& d)
	{
		if (unique_date_value() != d.unique_date_value())
			return true;
		else
			return false;
	}

	bool Date::operator<(Date& d)
	{
		if (unique_date_value() < d.unique_date_value())
			return true;
		else
			return false;
	}

	bool Date::operator>(Date& d)
	{
		if (unique_date_value() > d.unique_date_value())
			return true;
		else
			return false;
	}

	bool Date::operator<=(Date& d)
	{
		if (unique_date_value() <= d.unique_date_value())
			return true;
		else
			return false;
	}

	bool Date::operator>=(Date& d)
	{
		if (unique_date_value() >= d.unique_date_value())
			return true;
		else
			return false;
	}


	Status& Date::state()
	{
		return status;
	}

	Date& Date::formatted(bool flag)
	{
		Format = flag;
		return *this;
	}

	Date::operator bool() const
	{
		if (status)
			return true;
		else
			return false;
	}

	ostream& Date::write(ostream& ostr) const
	{
		if (Format == true)
		{
			ostr << Year << "/";
			ostr << std::setfill('0') << std::setw(2) << Month << "/";
			ostr << std::setfill('0') << std::setw(2) << Day;
		}

		else
		{
			ostr << Year % 100;
			ostr << std::setfill('0') << std::setw(2) << Month;
			ostr << std::setfill('0') << std::setw(2) << Day;
		}


		return ostr;
	}

	istream& Date::read(istream& istr)
	{
		int n;
		istr >> n;

		if (istr.fail())
		{
			status = "Invalid date value";
			return istr;
		}

		if (to_string(n).length() == 4)
		{
			Month = n / 100;
			Day = n % 100;
			ut.getSystemDate(&Year);
		}
		else if (to_string(n).length() == 6)
		{
			string temp = "20" + to_string(n / 10000);
			Year = atoi(&temp[0]);
			Month = (n % 10000) / 100;
			Day = n % 100;
		}
		else if (to_string(n).length() == 2)
		{
			status = "Invalid month in date";
			status = 2;
			istr.setstate(ios::badbit);
			return istr;
		}

		if (!validate())
			istr.setstate(ios::badbit);

		return istr;
	}

	Date::~Date()
	{
		status.clear();
	}

	std::ostream& operator<<(std::ostream& ostr, const Date& d)
	{
		return d.write(ostr);
	}

	std::istream& operator>>(std::istream& istr, Date& d)
	{
		return d.read(istr);
	}
}