/* ------------------------------------------------------
Milestone 4
Module: Perishable
Filename: Perishable.cpp
Version 1.1
Author: Devang Ramubhai Ahir Ahir
Revision History
-----------------------------------------------------------
Date          Reason
07/04/2022
-----------------------------------------------------------*/
#define _CRT_SECURE_NO_WARNINGS
#include <string>
#include <iomanip>
#include <iostream>
#include "Perishable.h"
#include "Item.h"
#include "Utils.h"
using namespace std;
namespace sdds {

    Perishable::Perishable() : Item::Item()
    {
        Instructions = nullptr;
        Expiry.formatted(true);
    }

    Perishable::Perishable(const Perishable& perishable) : Item::Item(perishable)
    {


        Expiry = perishable.Expiry;

        if (perishable)
        {
            Instructions = new char[strlen(perishable.Instructions) + 1];
            strcpy(Instructions, perishable.Instructions);
        }
        else
        {
            Instructions = nullptr;
        }
    }

    Perishable& Perishable::operator=(const Perishable& perishable)
    {
        delete[] Instructions;
        Instructions = nullptr;
        Expiry = perishable.Expiry;

        if (perishable)
        {
            Item::operator=(perishable);
            Instructions = new char[strlen(perishable.Instructions) + 1];
            strcpy(Instructions, perishable.Instructions);
        }
        else
        {
            Instructions = nullptr;
        }
        return *this;
    }

    Perishable::~Perishable()
    {
        delete[] Instructions;
        Instructions = nullptr;
        Expiry.formatted(false);
    }

    const Date& Perishable::expiry() const
    {
        return Expiry;
    }

    int Perishable::readSku(std::istream& istr)
    {
        Utils a;
        cout << "SKU: ";
        SKU = a.checking_num(istr, 10000, 39999);
        return -1;
    }

    std::ofstream& Perishable::save(std::ofstream& ofstr) const
    {
        if (state)
        {
            Item::save(ofstr);
            ofstr << "\t";
            if (Instructions != nullptr) {
                ofstr << Instructions << "\t";
            }
            ofstr << Expiry.uniqueValue();
        }
        return ofstr;
    }

    std::ifstream& Perishable::load(std::ifstream& ifstr) {
        Item::load(ifstr);

        delete[] Instructions;
        Instructions = nullptr;

        if (ifstr)
        {
            ifstr.ignore(1000, '\t');
            Instructions = new char[1000];
            ifstr.getline(Instructions, 1000, '\t');
            ifstr >> Expiry;
            ifstr.ignore(1000, '\n');
        }


        return ifstr;
    }

    std::ostream& Perishable::display(std::ostream& ostr) const {
        if (Linear) {
            ostr << setfill(' ');
            Item::display(ostr);
            if (Instructions != nullptr && strlen(Instructions) != 0)
            {
                ostr << "*";
            }
            else
            {
                ostr << " ";
            }
            ostr << Expiry;
        }
        else
        {
            ostr << std::setfill(' ');
            ostr << "Perishable ";
            Item::display(ostr);
            ostr << "Expiry date: " << Expiry << endl;
            if (Instructions != nullptr && strlen(Instructions) != 0)
            {
                ostr << "Handling Instructions: " << Instructions << endl;
            }
        }
        return ostr;
    }

    std::istream& Perishable::read(std::istream& istr) {
        Item::read(istr);

        delete[] Instructions;
        Instructions = nullptr;
        Instructions = new char[1000];

        cout << "Expiry date (YYMMDD): ";
        istr >> Expiry;
        istr.ignore(1000, '\n');

        cout << "Handling Instructions, ENTER to skip: ";
        istr.getline(Instructions, 1000);

        if (Instructions[0] == '\n')
        {
            Instructions = nullptr;
        }


        state = true;

        return istr;
    }
}

