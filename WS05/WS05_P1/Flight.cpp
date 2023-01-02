/* ------------------------------------------------------
Workshop 5 part 1
Module: Flight
Filename: Flight.cpp
Version 1.1
Author: Devang Ramubhai Ahir Ahir
Revision History
-----------------------------------------------------------
Date          Reason
17/02/2022
-----------------------------------------------------------*/
#define _CRT_SECURE_NO_WARNINGS
#include <cstring>
#include "Flight.h"

using namespace std;
namespace sdds {

    void Flight::emptyPlane() {
        strcpy(m_title, "EmptyPlane");
        m_fuel = 0;
        m_passengers = 0;
    }

    // New Flight
    Flight::Flight() {
        emptyPlane();
    }

    Flight::Flight(int passengers, double fuel, const char* title) {
        emptyPlane();
        if (passengers > 0 && passengers <= Boen747_Capacity && fuel >= 0 &&
            fuel <= Fuel_Tank_Capacity) {
            m_passengers = passengers;
            m_fuel = fuel;
            strcpy(m_title, title);
        }
    }

    std::ostream& Flight::display() const {

        if (*this) {
            cout << " Flight  |  Ready to Depart";
            cout << " ";
            cout.width(10);
            cout << (const char*)(*this);
            cout << " | ";
            cout << "Pass: ";
            cout.width(10);
            cout << int(*this);
            cout << " | ";
            cout.width(12);
            cout.precision(2);
            cout.setf(ios::right);
            cout.setf(ios::fixed);
            cout << double(*this);
            cout.unsetf(ios::right);
            cout << " Liters";
        }
        else if (~*this) {
            cout << " Flight  |  Empty Plane    ";
        }
        else {
            cout << " Flight  |  Low Fuel       ";
            cout << " ";
            cout.width(10);
            cout << (const char*)(*this);
            cout << " | ";
            cout << "Pass: ";
            cout.width(10);
            cout << int(*this);
            cout << " | ";
            cout.width(12);
            cout.precision(2);
            cout.setf(ios::right);
            cout.setf(ios::fixed);
            cout << double(*this);
            cout.unsetf(ios::right);
            cout << " Liters";
        }
        return cout;
    }


    Flight::operator bool() const {
        return m_passengers > 0 && (m_fuel >= 600 * m_passengers);
    }

    Flight::operator int() const {
        return m_passengers;
    }

    Flight::operator double() const {
        return m_fuel;
    }

    Flight::operator const char* () const {
        return m_title;
    }

    bool Flight::operator ~() const {
        return m_passengers == 0;
    }

    Flight& Flight::operator=(Flight& rhs) {
        if (this == &rhs) {
            return *this;
        }
        strcpy(m_title, rhs.m_title);
        m_fuel = rhs.m_fuel;
        m_passengers = rhs.m_passengers;
        rhs.emptyPlane();
        return *this;
    }

    Flight& Flight::operator=(int rhs) {
        if (rhs > 0 && rhs <= Boen747_Capacity) {
            m_passengers = rhs;
        }
        return *this;
    }

    Flight& Flight::operator=(double rhs) {
        if (rhs > 0 && rhs < Fuel_Tank_Capacity) {
            m_fuel = rhs;
        }
        return *this;
    }

    Flight& Flight::operator+=(double rhs) {
        if (rhs > 0) {
            m_fuel += rhs;

            if (m_fuel > Fuel_Tank_Capacity) {
                m_fuel = Fuel_Tank_Capacity;
            }
        }
        return *this;
    }

    Flight& Flight::operator+=(int rhs) {
        if (rhs > 0) {
            m_passengers += rhs;

            if (m_passengers > Boen747_Capacity) {
                m_passengers = Boen747_Capacity;
            }
        }
        return *this;
    }

    Flight& Flight::operator-=(double rhs) {
        if (rhs > 0) {
            m_fuel -= rhs;

            if (m_fuel < 0) {
                m_fuel = 0;
            }
        }
        return *this;
    }

    Flight& Flight::operator-=(int rhs) {
        if (rhs > 0) {
            m_passengers -= rhs;

            if (m_passengers < 0) {
                m_passengers = 0;
            }
        }
        return *this;
    }

    Flight& Flight::operator<<(Flight& rhs) {
        if (this == &rhs) {
            return *this;
        }
        if (*this && rhs) {
            int total_passengers = m_passengers + rhs.m_passengers;
            if (total_passengers <= Boen747_Capacity) {
                m_passengers = total_passengers;
                rhs.m_passengers = 0;
            }
            else {
                m_passengers = Boen747_Capacity;
                rhs.m_passengers = total_passengers - Boen747_Capacity;
            }
        }
        return *this;
    }

    Flight& Flight::operator>>(Flight& rhs) {
        rhs << *this;
        return *this;
    }

    int operator+(const Flight& f1, const Flight& f2) {
        if (f1 && f2) {
            return (int)f1 + (int)f2;
        }
        return 0;
    }

    int operator+=(int& lhs, const Flight& rhs) {
        lhs += (int)rhs;
        return lhs;
    }
}