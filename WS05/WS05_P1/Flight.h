/* ------------------------------------------------------
Workshop 5 part 1
Module: Flight
Filename: Flight.h
Version 1.1
Author: Devang Ramubhai Ahir Ahir
Revision History
-----------------------------------------------------------
Date          Reason
13/02/2022
-----------------------------------------------------------*/
#ifndef SDDS_FLIGHT_H
#define SDDS_FLIGHT_H
#include <iostream>
#include <string>

namespace sdds {

    const int Boen747_Capacity = 388;
    const int Fuel_Tank_Capacity = 238840;

    class Flight {

        char m_title[16];
        double m_fuel;
        int m_passengers;
        void emptyPlane();

    public:
        Flight();
        Flight(int passengers, double fuel, const char* title);
        std::ostream& display()const;
        operator bool() const;
        operator int() const;
        operator double() const;
        operator const char* () const;
        bool operator ~() const;
        Flight& operator=(Flight& rhs);
        Flight& operator=(int rhs);
        Flight& operator=(double rhs);
        Flight& operator+=(double rhs);
        Flight& operator+=(int rhs);
        Flight& operator-=(double rhs);
        Flight& operator-=(int rhs);
        Flight& operator<<(Flight& rhs);
        Flight& operator>>(Flight& rhs);
    };

    int operator+(const Flight& f1, const Flight& f2);
    int operator+=(int& lhs, const Flight& rhs);

}
#endif // SDDS_FLIGHT_H
