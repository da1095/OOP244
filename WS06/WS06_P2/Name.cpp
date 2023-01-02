/* ------------------------------------------------------
Workshop 6 part 2
Module: Name
Filename: Name.cpp
Version 1.1
Author: Devang Ramubhai Ahir Ahir
Revision History
-----------------------------------------------------------
Date          Reason
07/03/2022
-----------------------------------------------------------*/
#include <iostream>
#include <string.h>
#include "Name.h"
#include "Utils.h"
using namespace std;
namespace sdds
{
    Name::Name() {}
    Name::Name(const char* first)
    {
        allocCopy(First_Name, first);
    }
    Name::Name(const char* first, const char* last)
    {
        allocCopy(First_Name, first);
        allocCopy(Last_Name, last);
    }
    Name::Name(const char* first, const char* middle, const char* last)
    {
        allocCopy(First_Name, first);
        allocCopy(Middle_Name, middle);
        allocCopy(Last_Name, last);
    }
    Name::Name(const Name& src)
    {
        *this = src;
    }
    Name& Name::operator=(const Name& src)
    {
        if (this != &src)
        {

            allocCopy(First_Name, src.First_Name);
            allocCopy(Middle_Name, src.Middle_Name);
            allocCopy(Last_Name, src.Last_Name);
        }
        return *this;
    }
    void Name::setEmpty()
    {

        delete[] First_Name;
        delete[] Middle_Name;
        delete[] Last_Name;
        First_Name = nullptr;
        Middle_Name = nullptr;
        Last_Name = nullptr;
    }
    Name::~Name()
    {
        setEmpty();
    }
    void Name::setShort(bool value)
    {
        Short = value;
    }
    Name& Name::operator+=(const char* N)
    {

        if (!NullEmpty(N) && Valid)
        {
            bool result = false;
            for (int i = 0; N[i] != 0 && !result; i++, result = N[i] == ' ')
                ;

            if (!result && Valid)
            {

                if (NullEmpty(First_Name))
                {
                    allocCopy(First_Name, N);
                }
                else if (NullEmpty(Middle_Name))
                {
                    allocCopy(Middle_Name, N);
                }
                else if (NullEmpty(Last_Name))
                {
                    allocCopy(Last_Name, N);
                }
                else
                {
                    setEmpty();
                    Valid = false;
                }
            }
        }
        return *this;
    }
    std::ostream& Name::write(std::ostream& os) const
    {
        if (*this)
        {

            if (!NullEmpty(First_Name))
                os << First_Name;
            if (!NullEmpty(Middle_Name))
            {
                if (Short)
                    os << " " << Middle_Name[0] << ".";
                else
                    os << " " << Middle_Name;
            }
            if (!NullEmpty(Last_Name))
                os << " " << Last_Name;
        }
        else
        {
            os << "Bad Name";
        }

        return os;
    }
    std::istream& Name::read(std::istream& is)
    {
        string f = "";
        string m = "";
        string l = "";
        setEmpty();
        is >> f;
        if (is.peek() != '\n')
            is >> m;
        if (is.peek() != '\n')
            is >> l;

        if (is.peek() == '\n')
        {

            if (f != "")
            {
                allocCopy(First_Name, f.c_str());
            }
            if (l != "")
            {
                allocCopy(Middle_Name, m.c_str());
                allocCopy(Last_Name, l.c_str());
            }
            if (m != "" && l == "")
            {
                allocCopy(Last_Name, m.c_str());
            }
        }

        return is;
    }
    Name::operator bool() const
    {
        return !NullEmpty(First_Name);
    }

    std::ostream& operator<<(std::ostream& ostr, const Name& right)
    {
        return right.write(ostr);
    }
    std::istream& operator>>(std::istream& istr, Name& right)
    {
        return right.read(istr);
    }

}