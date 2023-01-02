/* ------------------------------------------------------
Workshop 5 part 2
Module: Portfolio
Filename: Flight.cpp
Version 1.1
Author: Devang Ramubhai Ahir Ahir
Revision History
-----------------------------------------------------------
Date          Reason
20/02/2022
-----------------------------------------------------------*/
#ifndef SDDS_Portfolio_H_
#define SDDS_Portfolio_H_
#include <iostream>
#include <string>

namespace sdds {

    class Portfolio {
        double m_value = 0;
        char m_stock[16];
        char m_type;

    public:
        Portfolio();
        Portfolio(double value, const char* stock, char type);
        void dispPortfolio() const;
        operator double() const;
        operator const char* () const;
        operator char() const;
        operator bool() const;
        Portfolio& operator +=(double value);
        Portfolio& operator -=(double value);
        double getvalue() const;
        Portfolio& operator <<(Portfolio& right);
        Portfolio& operator >>(Portfolio& right);
        bool istrueportfolio() const;
        void  emptyPortfolio();
        std::ostream& display() const;
    };
    bool operator ~(const Portfolio& port);
    double operator +(const Portfolio& p1, Portfolio& p2);
    double operator +=(double& value, const Portfolio& p1);
}
#endif // SDDS_Portfolio_H_