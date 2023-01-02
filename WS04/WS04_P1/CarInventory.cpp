/* ------------------------------------------------------
Workshop 4 part 1
Module: Car inventory
Filename: CarInventory.cpp
Version 1.1
Author: Devang Ramubhai Ahir Ahir
Revision History
-----------------------------------------------------------
Date          Reason
3/02/2022
-----------------------------------------------------------*/
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "CarInventory.h"
#include <cstring>

using namespace std;

namespace sdds
{
    CarInventory::CarInventory()
    {
        resetInfo();
    }

    CarInventory::CarInventory(const char* type, const char* brand, const char* model, int year, int code, double price)
    {
        resetInfo();
        setInfo(type, brand, model, year, code, price);
        if (!isValid()) resetInfo();

    }

    CarInventory::~CarInventory()
    {
        delete[] m_type;
        delete[] m_brand;
        delete[] m_model;

    }

    void CarInventory::resetInfo()
    {
        m_type = nullptr;
        m_brand = nullptr;
        m_model = nullptr;
        m_year = 0;
        m_code = 0;
        m_price = 0;

    }

    CarInventory& CarInventory::setInfo(const char* type, const char* brand, const char* model, int year, int code, double price)
    {
        delete[] m_type;
        delete[] m_brand;
        delete[] m_model;
        m_type = new char[strlen(type) + 1];
        m_brand = new char[strlen(brand) + 1];
        m_model = new char[strlen(model) + 1];
        strcpy(m_type, type);
        strcpy(m_brand, brand);
        strcpy(m_model, model);
        m_year = year;
        m_code = code;
        m_price = price;

        return *this;

    }

    void CarInventory::printInfo() const
    {
        cout.setf(ios::left);
        cout << "| ";
        cout.width(10);
        cout << m_type;
        cout << " | ";
        cout.width(16);
        cout << m_brand;
        cout << " | ";
        cout.width(16);
        cout << m_model;
        cout << " | ";
        cout << m_year;
        cout << " |  ";
        cout << m_code;
        cout << " | ";
        cout.unsetf(ios::left);
        cout.width(9);
        cout.setf(ios::right);
        cout.precision(2);
        cout.setf(ios::fixed);
        cout << double(m_price);
        cout.unsetf(ios::right);
        cout << " |" << "\n";
    }

    bool CarInventory::isValid() const
    {
        return m_type != nullptr && m_brand != nullptr && m_model != nullptr && m_year >= 1990 && m_code >= 100 && m_code <= 999 && m_price > 0;

    }

    bool CarInventory::isSimilarTo(const CarInventory& car) const
    {
        return(strcmp(m_type, car.m_type) == 0 && strcmp(m_model, car.m_model) == 0 && strcmp(m_brand, car.m_brand) == 0 && m_year == car.m_year);

    }

    bool find_similar(CarInventory car[], const int num_cars)
    {
        bool result = false;
        for (int i = 0; (i < num_cars) && !result; i++)
        {
            for (int j = i + 1; (j < num_cars) && !result; j++)
            {

                if ((car[i].isValid() && car[j].isValid()) && car[i].isSimilarTo(car[j]))
                {
                    result = true;
                }
            }
        }
        return result;
    }
}
