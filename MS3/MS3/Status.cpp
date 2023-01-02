/* ------------------------------------------------------
Milestone 3
Module: Status
Filename: Status.cpp
Version 1.1
Author: Devang Ramubhai Ahir Ahir
Revision History
-----------------------------------------------------------
Date          Reason
03/04/2022
-----------------------------------------------------------*/
#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<cstring>
#include"Status.h"
using namespace std;
namespace sdds
{
    Status::Status(const char* desc)
    {
        if (desc != nullptr) {
            delete[] Description;
            Description = new char(strlen(desc) + 1);
            strcpy(Description, desc);
        }
        else {
            Description = nullptr;
        }
        Codigo = 0;
    }

    Status::Status(const Status& S)
    {
        if (S.Description != nullptr) {
            delete[] Description;
            Description = new char[strlen(S.Description) + 1];
            strcpy(Description, S.Description);
            Codigo = S.Codigo;
        }
        else {
            Description = nullptr;
        }
    }

    Status& Status::operator=(const Status& S)
    {
        if (this != &S) {
            delete[] Description;
            Description = nullptr;
            Description = new char[strlen(S.Description) + 1];
            strcpy(Description, S.Description);
            Codigo = S.Codigo;
        }
        return *this;
    }

    Status& Status::operator=(int statusCode)
    {
        Codigo = statusCode;
        return *this;
    }

    Status& Status::operator=(const char* desc)
    {
        if (desc != nullptr) {
            delete[] Description;
            Description = nullptr;
            Description = new char[strlen(desc) + 1];
            strcpy(Description, desc);
        }
        else {
            Description = nullptr;
        }

        return *this;
    }

    Status::~Status()
    {
        delete[] Description;
        Description = nullptr;
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
        delete[] Description;
        Description = nullptr;
        Codigo = 0;
        return *this;
    }

    ostream& Status::display(ostream& ostr) const
    {
        if (Codigo != 0) {

            ostr << "ERR#" << Codigo << ": " << Description;

        }
        else {

            ostr << Description;

        }

        return ostr;
    }

    std::ostream& operator<<(std::ostream& ostr, const Status& S) {
        if (S.operator bool() == false) {
            S.display(ostr);
        }
        return ostr;
    }




}