/* ------------------------------------------------------
Milestone 1
Module: Status
Filename: Status.cpp
Version 1.1
Author: Devang Ramubhai Ahir Ahir
Revision History
-----------------------------------------------------------
Date          Reason
18/03/2022
-----------------------------------------------------------*/
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include"Status.h"
#include "Utils.h"
using namespace std;
namespace sdds {
    Status::Status(const char* description)
    {
        Codigo = 0;
        if (description != nullptr)
        {
            ut.alocpy(Description, description);
        }
    }
    Status::Status(const Status& stat)
    {


        if (stat.Description != nullptr)
        {
            ut.alocpy(Description, stat.Description);
            Codigo = stat.Codigo;
        }
        else
        {
            delete[] Description;
            Description = nullptr;
            Codigo = 0;
        }
    }
    Status& Status::operator =(const char* description)
    {
        if (description != nullptr)
        {
            ut.alocpy(Description, description);
        }
        return *this;
    }
    Status& Status::operator =(int code)
    {
        Codigo = code;
        return *this;

    }
    Status::operator int() const
    {
        return Codigo;
    }
    Status::operator const char* () const
    {
        return Description;
    }
    Status::operator bool() const
    {
        return Description == nullptr;
    }
    Status& Status::clear()
    {
        if (Description != nullptr)
        {
            delete[] Description;
            Description = nullptr;
            Codigo = 0;
        }
        return *this;
    }
    Status::~Status()
    {
        delete[] Description;
    }

    std::ostream& Status::print(std::ostream& ostr) const
    {

        if (Codigo == 0)
        {
            ostr << Description;
        }
        else
        {
            ostr << "ERR#" << Codigo << ": ";
            ostr << Description;
        }
        return ostr;
    }

    std::ostream& operator<<(std::ostream& os, const Status& stat)
    {
        if (stat)
        {
            //do nothing
        }
        else
        {
            stat.print(os);
        }
        return os;
    }



}