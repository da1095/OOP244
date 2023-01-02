/* ------------------------------------------------------
Workshop 4 part 1
Module: Car Inventory
Filename: CarInventory.h
Version 1.1
Author: Devang Ramubhai Ahir Ahir
Revision History
-----------------------------------------------------------
Date          Reason
3/02/2022
-----------------------------------------------------------*/
#define _CRT_SECURE_NO_WARNINGS
#ifndef SDDS_CARINVENTORY_H
#define SDDS_CARINVENTORY_H

namespace sdds
{
    class CarInventory
    {
        char* m_type;
        char* m_brand;
        char* m_model;
        int m_year;
        int m_code;
        double m_price;

    public:
        CarInventory();
        CarInventory(const char* type, const char* brand, const char* model, int year = 2022, int code = 100, double price = 1);
        ~CarInventory();
        void resetInfo();
        CarInventory& setInfo(const char* type, const char* brand, const char* model, int year, int code, double price);
        void printInfo() const;
        bool isValid() const;
        bool isSimilarTo(const CarInventory& car) const;
    };
    bool find_similar(CarInventory car[], const int num_cars);
}
#endif
