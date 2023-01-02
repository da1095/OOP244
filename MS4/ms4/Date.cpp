/* ------------------------------------------------------
Milestone 4
Module: Date
Filename: Date.cpp
Version 1.1
Author: Devang Ramubhai Ahir Ahir
Revision History
-----------------------------------------------------------
Date          Reason
07/04/2022
-----------------------------------------------------------*/
#define _CRT_SECURE_NO_WARNINGS
#include <iomanip>
#include <iostream>
#include <ctime>
#include "Date.h"
#include "Utils.h"
#include "Status.h"
#include <string>
using namespace std;

namespace sdds
{
    bool Date::validate()
    {
        Utils a; //object for utils
        Status b; //object for status

        if (Month < 1 || Month > 12)
        {

            status.Description = new char[22];
            strcpy(status.Description, "Invalid month in date");
            status.Codigo = 2;

            return false;
        }
        else if (Year < sdds_Test_Year || Year > MAXIMUM_YEAR_VALUE)
        {
            status.Description = new char[21];
            strcpy(status.Description, "Invalid year in date");
            status.Codigo = 1;

            return false;
        }
        else if (Day < 1 || Day > a.daysOfMon(Month, Year))
        {

            status.Description = new char[20];
            strcpy(status.Description, "Invalid day in date");
            status.Codigo = 3;

            return false;
        }
        else
        {
            b.clear();
            return true;
        }
    }

    int Date::uniqueValue() const
    {
        return (Year - 2000) * 10000 + Month * 100 + Day;
    }

    const Status& Date::state()
    {
        return status;
    }

    bool Date::formatted(bool m_format)
    {
        Format = m_format;

        return *this;
    }

    Date::operator bool() const
    {
        return 0;
    }


    Date::Date()
    {
        //This is for getting the test date
        Year = sdds_Test_Year;
        Month = sdds_Test_Month;
        Day = sdds_Test_Day;


        /*
        //This is for getting the current day :
        Utils a;
        a.getSystemDate(&year, &month, &day);
        */
        formatted(true);
    }



    Date::Date(int m_year, int m_month, int m_day)
    {
        Year = m_year;
        Month = m_month;
        Day = m_day;
        formatted(true);
        validate();
    }


    bool operator==(const Date& one, const Date& two)
    {
        return one.uniqueValue() == two.uniqueValue();
    }

    bool operator!=(const Date& one, const Date& two)
    {
        return one.uniqueValue() != two.uniqueValue();
    }

    bool operator>=(const Date& one, const Date& two)
    {
        return one.uniqueValue() >= two.uniqueValue();
    }

    bool operator<=(const Date& one, const Date& two)
    {
        return one.uniqueValue() <= two.uniqueValue();
    }

    bool operator<(const Date& one, const Date& two)
    {
        return one.uniqueValue() < two.uniqueValue();
    }

    bool operator>(const Date& one, const Date& two)
    {
        return one.uniqueValue() > two.uniqueValue();
    }

    /*
    void Date::clear()
    {
        year = 0;
        month = 0;
        day = 0;
        status = false;
        format = false;
    }
    */

    std::istream& Date::read(std::istream& istr)
    {
        int value = 0;
        string input;

        istr >> value;
        if (istr.fail())
        {
            cout << "Invalid date value";
            cin.setstate(ios::badbit);
            return istr;
        }

        if (to_string(value).length() == 4 || to_string(value).length() == 3)
        {
            Year = sdds_Test_Year;
            Day = value % 100;
            Month = value / 100;
        }
        else if (to_string(value).length() == 6 || to_string(value).length() == 5)
        {
            Day = value % 100;
            value = value / 100;
            Month = value % 100;
            Year = value / 100 + 2000;
        }
        else
        {
            Month = 0;
            Day = 0;
            Year = 0;
        }
        if (validate() == false)
        {
            cin.setstate(ios::badbit);
        }
        return istr;
    }

    std::ostream& sdds::Date::write(std::ostream& ostr) const
    {
        if (Format == true)
        {
            ostr << Year << '/' << setw(2) << setfill('0') << Month << '/' << setw(2) << setfill('0') << Day;
        }
        else
        {
            ostr << Year % 100 << setw(2) << setfill('0') << Month << setw(2) << setfill('0') << Day;
        }

        return ostr;
    }

    std::ostream& operator<<(std::ostream& ostr, const Date& D)
    {
        D.write(ostr);
        return ostr;
    }


    std::istream& operator>>(std::istream& istr, Date& D)
    {
        D.read(istr);
        return istr;
    }
}
