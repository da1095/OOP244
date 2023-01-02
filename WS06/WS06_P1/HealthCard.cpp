/* ------------------------------------------------------
Workshop 6 part 1
Module: HealthCard
Filename: HealthCard.cpp
Version 1.1
Author: Devang Ramubhai Ahir Ahir
Revision History
-----------------------------------------------------------
Date          Reason
03/03/2022
-----------------------------------------------------------*/

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string.h>
#include "HealthCard.h"
using namespace std;
namespace sdds
{

    bool HealthCard::validID(const char* name, long long number, const char vCode[], const char sNumber[]) const
    {

        return name && name[0] && number > 999999999 && number < 9999999999 && strlen(vCode) == 2 && strlen(sNumber) == 9;
    }
    void HealthCard::setEmpty()
    {

        delete[] m_name;
        m_name = nullptr;
    }
    void HealthCard::allocateAndCopy(const char* name)
    {
        delete[] m_name;
        m_name = new char[strlen(name) + 1];
        strcpy(m_name, name);
    }
    void HealthCard::extractChar(istream& istr, char ch) const
    {
        if (istr.peek() == ch)
            istr.ignore();
        else
        {
            istr.ignore(1000, ch);
            istr.setstate(ios::failbit);
        }
    }
    ostream& HealthCard::printIDInfo(ostream& ostr) const
    {
        return ostr << m_number << "-" << m_vCode << ", " << m_sNumber;
    }
    void HealthCard::set(const char* name, long long number, const char vCode[], const char sNumber[])
    {
        delete[] m_name;
        m_name = nullptr;
        setEmpty();
        if (validID(name, number, vCode, sNumber))
        {
            allocateAndCopy(name);
            m_number = number;
            strcpy(m_vCode, vCode);
            strcpy(m_sNumber, sNumber);
        }
    }

    HealthCard::HealthCard(const char* name, long long number, const char vCode[], const char sNumber[])
    {
        set(name, number, vCode, sNumber);
    }
    HealthCard::HealthCard(const HealthCard& hc)
    {
        *this = hc;
    }
    HealthCard& HealthCard::operator=(const HealthCard& hc)
    {
        if (this != &hc)
        {
            set(hc.m_name, hc.m_number, hc.m_vCode, hc.m_sNumber);
        }
        return *this;
    }
    HealthCard::~HealthCard()
    {
        delete[] m_name;
    }
    HealthCard::operator bool() const
    {
        return m_name != nullptr;
    }
    ostream& HealthCard::print(ostream& ostr, bool toFile) const
    {

        if (*this)
        {
            if (toFile)
            {
                ostr << m_name;
                ostr << ',';
                printIDInfo(ostr);
                ostr << endl;
            }
            else
            {
                ostr.width(50);
                ostr.fill('.');
                ostr.setf(ios::left);
                ostr << m_name;
                printIDInfo(ostr);
            }
        }

        return ostr;
    }
    istream& HealthCard::read(istream& istr)
    {

        char name[MaxNameLength]{ '\0' };
        long long number{ 0 };
        char vCode[3]{ 0 };
        char sNumber[10]{ 0 };
        istr.get(name, MaxNameLength, ',');
        extractChar(istr, ',');
        istr >> number;
        extractChar(istr, '-');
        istr.get(vCode, 3, ',');
        extractChar(istr, ',');
        istr.get(sNumber, 10, '\n');
        extractChar(istr, '\n');
        if (istr)
        {
            set(name, number, vCode, sNumber);
        }
        else
        {
            istr.clear();
            istr.ignore(1000, '\n');
        }
        return istr;
    }
    ostream& operator<<(ostream& ostr, const HealthCard& hc)
    {

        if (hc)
        {
            hc.print(ostr, false);
        }
        else
        {
            ostr << "Invalid Health Card Record";
        }

        return ostr;
    }
    istream& operator>>(istream& istr, HealthCard& hc)
    {
        return hc.read(istr);
    }

}
