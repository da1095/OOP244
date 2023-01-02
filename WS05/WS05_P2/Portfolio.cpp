/* ------------------------------------------------------
Workshop 5 part 2
Module: Portfolio
Filename: Portfolio.cpp
Version 1.1
Author: Devang Ramubhai Ahir Ahir
Revision History
-----------------------------------------------------------
Date          Reason
20/02/2022
-----------------------------------------------------------*/
#define _CRT_SECURE_NO_WARNINGS

#include "Portfolio.h"
#include <string.h>

using namespace std;
namespace sdds {


    Portfolio::Portfolio() {
        emptyPortfolio();
    }

    void Portfolio::emptyPortfolio()
    {
        m_value = 0;
        m_stock[0] = 0;
        m_type = 'E';
    }
    Portfolio::Portfolio(double value, const char* stock, char type) {
        emptyPortfolio();
        if (value >= 0 && (type == 'V' || type == 'G' || type == 'I')) {
            m_value = value;
            m_type = type;
            strcpy(m_stock, stock);
        }
    }

    void Portfolio::dispPortfolio() const {
        cout << " ";
        cout.width(10);
        cout << (const char*)(*this);
        cout << " | ";
        cout << "Value: ";
        cout.width(10);
        cout << double(*this);
        cout << " | ";
        cout << " Type: ";
        cout << char(*this);
    }

    std::ostream& Portfolio::display() const {

        if (~*this) {
            cout << " Portfolio  |  Bad-NG |";
            dispPortfolio();
        }
        else if (*this) {
            cout << " Portfolio  |  Active |";
            dispPortfolio();

        }
        else {
            cout << " Portfolio  |  EMPTY  |";
            dispPortfolio();
        }
        return cout;
    }

    Portfolio::operator double() const
    {
        return m_value;
    }

    Portfolio::operator const char* () const
    {
        return m_stock;
    }
    Portfolio::operator char() const
    {
        return m_type;
    }

    Portfolio::operator bool() const
    {
        bool sahi = false;
        if (m_type == 'G' || m_type == 'V' || m_type == 'I')
        {
            sahi = true;
        }
        return sahi;
    }

    Portfolio& Portfolio::operator +=(double value)
    {
        if ((value > 0) && (m_type == 'G' || m_type == 'V' || m_type == 'I'))
        {
            m_value += value;
        }

        return *this;
    }

    Portfolio& Portfolio::operator -=(double value)
    {
        if ((value >= 0) && (m_type == 'G' || m_type == 'V' || m_type == 'I'))
        {
            m_value -= value;
        }

        return *this;
    }
    double Portfolio::getvalue() const
    {
        return m_value;
    }

    bool operator ~(const Portfolio& port)
    {
        bool isnegative = false;
        if (port.getvalue() < 0)
        {
            isnegative = true;
        }
        return isnegative;
    }

    bool Portfolio::istrueportfolio() const
    {
        bool portfo = false;
        if ((m_value >= 0) && (m_type == 'G' || m_type == 'V' || m_type == 'I'))
        {
            portfo = true;
        }
        return portfo;
    }

    Portfolio& Portfolio::operator <<(Portfolio& right)
    {

        m_value += right.m_value;
        right.m_value = 0;
        right.m_stock[0] = 0;
        right.m_type = 'E';

        return *this;
    }
    Portfolio& Portfolio::operator >>(Portfolio& right)
    {

        right.m_value += m_value;
        m_value = 0;
        m_stock[0] = 0;
        m_type = 'E';


        return *this;
    }

    double operator +(const Portfolio& p1, Portfolio& p2)
    {
        double value = 0;
        if (p1.istrueportfolio() && p2.istrueportfolio())
        {
            value = p1.getvalue() + p2.getvalue();
        }
        return value;
    }

    double operator +=(double& value, const Portfolio& p1)
    {
        value += p1.getvalue();
        return value;
    }
}