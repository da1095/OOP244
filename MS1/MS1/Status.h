/* ------------------------------------------------------
Milestone 1
Module: Status
Filename: Status.h
Version 1.1
Author: Devang Ramubhai Ahir Ahir
Revision History
-----------------------------------------------------------
Date          Reason
18/03/2022
-----------------------------------------------------------*/
#ifndef SDDS_STATUS_H
#define SDDS_STATUS_H
#include <iostream>
#include<cstring>
namespace sdds {
    class Status
    {
        char* Description{};
        int Codigo;// Spanish word for code is codigo
    public:
        Status(const char* description = nullptr);
        Status(const Status& stat);
        Status& operator =(const char* description);
        Status& operator =(int code);
        operator int() const;
        operator const char* () const;
        operator bool() const;
        Status& clear();
        std::ostream& print(std::ostream& ostr) const;
        ~Status();

    };
    std::ostream& operator<<(std::ostream& os, const Status& stat);

}
#endif