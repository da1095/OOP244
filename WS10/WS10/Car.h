/* ------------------------------------------------------
Workshop 10 part 1 (Only the coding part)
Module: Car
Filename: Car.h
Version 1.1
Author: Devang Ramubhai Ahir Ahir
Revision History
-----------------------------------------------------------
Date          Reason
13/04/2022
-----------------------------------------------------------*/
#ifndef SDDS_CAR_H_
#define SDDS_CAR_H_
#include "Displayable.h"
namespace sdds {
    class Car :public Displayable {
        char m_plate[9]{};
        char m_make[41]{};
        char m_model[41]{};
        void set(const char* plate, const char* make, const char* model);
    public:
        Car();
        Car(const char* plate, const char* make, const char* model);
        std::ostream& display(std::ostream& os)const;
        bool operator==(const Car& C)const;
    };
}


#endif