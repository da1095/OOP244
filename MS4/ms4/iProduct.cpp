/* ------------------------------------------------------
Milestone 4
Module: iProduct
Filename: iProduct.cpp
Version 1.1
Author: Devang Ramubhai Ahir Ahir
Revision History
-----------------------------------------------------------
Date          Reason
07/04/2022
-----------------------------------------------------------*/
#define _CRT_SECURE_NO_WARNINGS
#include <string>
#include <iostream>
#include <fstream>
#include "iProduct.h"
using namespace std;
namespace sdds
{
    iProduct::~iProduct()
    {
    }

    int iProduct::readSku(std::istream& istr)
    {
        return 0;
    }

    int iProduct::operator-=(int qty)
    {
        return 0;
    }

    int iProduct::operator+=(int qty)
    {
        return 0;
    }

    iProduct::operator double() const
    {
        return 0;
    }

    iProduct::operator bool() const
    {
        return 0;
    }

    int iProduct::qtyNeeded() const
    {
        return 0;
    }

    int iProduct::qty() const
    {
        return 0;
    }

    void iProduct::linear(bool isLinear)
    {
        return;
    }

    std::ofstream& iProduct::save(std::ofstream& ofstr) const
    {
        return ofstr;
    }

    std::ifstream& iProduct::load(std::ifstream& ifstr)
    {
        return ifstr;
    }

    std::ostream& iProduct::display(std::ostream& ostr) const
    {
        return ostr;
    }

    std::istream& iProduct::read(std::istream& istr)
    {
        return istr;
    }

    bool iProduct::operator==(int sku) const
    {
        return true;
    }

    bool iProduct::operator==(const char* description) const
    {
        return true;
    }

    istream& operator>>(istream& in, iProduct& p)
    {
        return p.read(in);
    }

    ostream& operator<<(ostream& os, const iProduct& p)
    {
        return p.display(os);
    }

}