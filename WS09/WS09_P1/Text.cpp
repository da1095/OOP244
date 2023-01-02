/* ------------------------------------------------------
Workshop 9 part 1 (Only the coding part)
Module: Text
Filename: Text.cpp
Version 1.1
Author: Devang Ramubhai Ahir Ahir
Revision History
-----------------------------------------------------------
Date          Reason
1/04/2022
-----------------------------------------------------------*/
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <fstream>
#include <string.h>
#include "Text.h"
using namespace std;
namespace sdds
{
    const char& Text::operator[](int index) const
    {

        if (strlen(M_Content) < size_t(index) || size_t(strlen(M_Content)) < 0)
        {
            return M_Content[strlen(M_Content)];
        }

        return M_Content[index];
    }

    Text::Text()
    {
        M_Content = nullptr;
    }

    Text::Text(const Text& ro)
    {
        M_Content = new char[strlen(ro.M_Content) + 1];
        strcpy(M_Content, ro.M_Content);
    }

    int Text::getFileLength(std::istream& is)
    {
        int len{};
        if (is)
        {
            std::streampos cur = is.tellg();
            is.seekg(0, ios::end);
            len = is.tellg();
            is.seekg(cur);
        }

        return len;
    }

    Text& Text ::operator=(const Text& ro)
    {
        delete[] M_Content;
        M_Content = new char[strlen(ro.M_Content) + 1];
        strcpy(M_Content, ro.M_Content);

        return *this;
    }

    Text ::~Text()
    {
        delete[] M_Content;
    }

    std::istream& Text::read(std::istream& istr)
    {
        char ch;
        istr.clear();
        istr.seekg(0, ios::beg);
        int len = getFileLength(istr);
        istr.clear();
        istr.seekg(0, ios::beg);

        M_Content = new char[len + 1];

        int i = 0;
        while (istr >> noskipws >> ch)
        {
            M_Content[i++] = ch;
        }

        M_Content[i] = '\0';
        return istr;
    }

    std::ostream& Text::write(std::ostream& ostr) const
    {
        ostr << M_Content;

        return ostr;
    }

    std::istream& operator>>(std::istream& istr, Text& ro)
    {
        return ro.read(istr);
    }

    std::ostream& operator<<(std::ostream& ostr, const Text& ro)
    {
        return ro.write(ostr);
    }

}