/* ------------------------------------------------------
Workshop 10 part 1 (Only the coding part)
Module: Car
Filename: Car.cpp
Version 1.1
Author: Devang Ramubhai Ahir Ahir
Revision History
-----------------------------------------------------------
Date          Reason
13/04/2022
-----------------------------------------------------------*/
#define _CRT_SECURE_NO_WARNINGS
#include <cstring>
#include "Car.h"
namespace sdds {
    void Car::set(const char* plate, const char* make, const char* model) {
        std::strncpy(m_plate, plate, 8);
        m_plate[8] = 0;
        std::strncpy(m_make, make, 40);
        m_make[40] = 0;;
        std::strncpy(m_model, model, 40);
        m_make[40] = 0;;
    }
    Car::Car() {
    }
    Car::Car(const char* plate, const char* make, const char* model) {
        set(plate, make, model);
    }
    std::ostream& Car::display(std::ostream& os)const {
        return os << m_plate << " " << m_make << " " << m_model;
    }
    bool Car::operator==(const Car& C)const {
        return std::strcmp(m_make, C.m_make) == 0;
    }
}