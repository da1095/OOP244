/* ------------------------------------------------------
Milestone 1
Module: Date
Filename: Date.h
Version 1.1
Author: Devang Ramubhai Ahir Ahir
Revision History
-----------------------------------------------------------
Date          Reason
18/03/2022
-----------------------------------------------------------*/
#ifndef SDDS_DATE_H
#define SDDS_DATE_H
#include <iostream>
#include<cstring>
#include<sstream>
#include"Status.h"
namespace sdds {

    const int MAXIMUM_YEAR_VALUE = 2030;



    class Date
    {
        Status status;
        int Year;
        int Month;
        int Day;
        bool Format;
        bool Invalid;
        bool validate();
        int uniqueDateValue() const;
    public:
        Date();
        bool notint(bool chara = false);

        Date(int year, int month, int day);
        operator bool() const;
        const Status& state();
        Date& formatted(bool slash);
        bool operator==(const Date& right) const;
        bool operator!=(const Date& right) const;
        bool operator>=(const Date& right) const;
        bool operator<=(const Date& right) const;
        bool operator<(const Date& right) const;
        bool operator>(const Date& right) const;
        std::ostream& print(std::ostream& os) const;
        std::istream& read(std::istream& istr);
    };
    std::ostream& operator<<(std::ostream& os, const Date& dat);
    std::istream& operator>>(std::istream& is, Date& dat);
}
#endif