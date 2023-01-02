/* ------------------------------------------------------
Milestone 3
Module: Item
Filename: Item.h
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
#include<iomanip>
#include <string>
#include<sstream>
#include"Utils.h"
#include"Item.h"
using namespace std;
namespace sdds
{
    bool Item::linear() const
    {
        return Linear;
    }

    Item::Item()
    {
        Price = 0.0;
        Quantity = 0;
        Quantity_Needed = 0;
        Description = nullptr;
        Linear = false;

    }

    Item::Item(const Item& I)
    {
        operator=(I);
    }

    Item& Item::operator=(const Item& I)
    {
        if (this != &I) {
            Price = I.Price;
            Quantity = I.Quantity;
            Quantity_Needed = I.Quantity_Needed;
            Description = new char[strlen(I.Description) + 1];
            strcpy(Description, I.Description);
            state = I.state;
            SKU = I.SKU;
        }
        return *this;
    }


    Item::~Item()
    {
        delete[] Description;
    }

    int Item::qtyNeeded() const
    {
        return Quantity_Needed;
    }

    int Item::qty() const
    {
        return Quantity;
    }

    Item::operator double() const
    {
        return Price;
    }

    Item::operator bool() const
    {
        return state;
    }

    int Item::operator-=(int qty)
    {
        Quantity -= qty;
        return Quantity;
    }

    int Item::operator+=(int qty)
    {
        Quantity += qty;
        return Quantity;
    }

    void Item::linear(bool isLinear)
    {
        Linear = isLinear;
    }

    void Item::clear()
    {
        Price = 0.0;
        Quantity = 0;
        Quantity_Needed = 0;
        delete[] Description;
        Description = nullptr;
        Linear = false;
        state = nullptr;
        SKU = 0;
    }

    bool Item::operator==(int sku) const
    {
        return SKU == sku;
    }

    bool Item::operator==(const char* description) const
    {
        return strstr(Description, description);
    }

    std::ofstream& Item::save(std::ofstream& ofstr) const
    {
        ofstr << SKU << '\t' << Description << '\t' << Quantity << '\t' << Quantity_Needed << '\t' << fixed << setprecision(2) << Price << endl;
        return ofstr;
    }

    std::ifstream& Item::load(std::ifstream& ifstr)
    {
        delete[] Description;
        Description = nullptr;
        string desc;

        ifstr >> SKU;
        ifstr.ignore(10000, '\t');
        getline(ifstr, desc, '\t');
        ifstr >> Quantity;
        ifstr.ignore(10000, '\t');
        ifstr >> Quantity_Needed;
        ifstr.ignore(10000, '\t');
        ifstr >> Price;
        ifstr.ignore();
        if (ifstr.bad()) {
            state = "Input file stream read failed!";
        }

        ut.alocpy(Description, desc.c_str());
        return ifstr;

    }

    std::ostream& Item::display(std::ostream& ostr) const
    {
        if (!state) {
            ostr << state;
        }
        else {
            if (Linear) {
                ostr.width(5);
                ostr << SKU << " | ";
                int i;
                for (i = 0; i < 35; i++) {

                    if (Description[i] == '\0') {
                        break;
                    }
                    else {
                        cout << Description[i];
                    }
                }
                while (i < 35) {
                    cout << " ";
                    i++;
                }

                ostr << " | ";
                ostr.setf(ios::right);
                ostr.width(4);
                ostr << Quantity << " | ";
                ostr.unsetf(ios::right);
                ostr.setf(ios::right);
                ostr.width(4);
                ostr << Quantity_Needed << " | ";
                ostr.unsetf(ios::right);
                ostr.setf(ios::right);
                ostr.width(7);
                ostr << fixed << setprecision(2) << Price << " |";
            }
            else {
                ostr << "AMA Item:" << endl;
                ostr << SKU << ": " << Description << endl;
                ostr << "Quantity Needed: " << Quantity_Needed << endl;
                ostr << "Quantity Available: " << Quantity << endl;
                ostr << "Unit Price: $" << Price << endl;
                ostr << "Needed Purchase Fund: $" << Price * (Quantity_Needed - Quantity) << endl;
            }
        }
        return ostr;
    }


    int Item::readSku(std::istream& istr)
    {
        int sku;
        sku = ut.getint(40000, 99999, "SKU: ");
        SKU = sku;
        return sku;
    }

    std::istream& Item::read(std::istream& istr)
    {
        string desc;
        cout << "AMA Item:" << endl;
        cout << "SKU: " << SKU << endl;
        cout << "Description: ";
        istr >> desc;
        Quantity_Needed = ut.getint(1, 9999, "Quantity Needed: ");
        Quantity = ut.getint(0, Quantity_Needed, "Quantity On Hand: ");
        Price = ut.getdouble(0.00, 9999.00, "Unit Price: $");
        if (!istr) {
            state = "Console entry failed!";
        }
        ut.alocpy(Description, desc.c_str());
        return istr;
    }

}