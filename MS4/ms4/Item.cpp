/* ------------------------------------------------------
Milestone 4
Module: Item
Filename: Item.cpp
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
#include "Item.h"
#include "Utils.h"
using namespace std;
namespace sdds
{
    Item::Item()
    {

        Price = 0;
        Quantity = 0;
        Quantity_Needed = 0;
        SKU = 0;
        Linear = false;
        state = false;
        Description = nullptr;
    }

    Item::Item(const Item& item)
    {

        if (item)
        {

            Price = item.Price;
            Quantity = item.Quantity;
            Quantity_Needed = item.Quantity_Needed;
            SKU = item.SKU;

            Linear = item.Linear;


            state = item.state;


            Description = new char[strlen(item.Description) + 1];
            strcpy(Description, item.Description);
        }
        else
        {
            Description = nullptr;
        }

    }


    Item& Item::operator=(const Item& item)
    {
        delete[] Description;
        Description = nullptr;
        Price = item.Price;
        Quantity = item.Quantity;
        Quantity_Needed = item.Quantity_Needed;
        SKU = item.SKU;

        Linear = item.Linear;
        state = item.state;

        if (item)
        {
            Description = new char[strlen(item.Description) + 1];
            strcpy(Description, item.Description);
        }
        else
        {
            Description = nullptr;
        }
        return *this;
    }

    Item::~Item()
    {
        Price = 0;
        Quantity = 0;
        Quantity_Needed = 0;
        SKU = 0;

        Linear = false;
        state = false;

        delete[] Description;
        Description = nullptr;
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
        if (state)
        {
            return true;
        }
        return false;
    }

    int Item::operator-=(int qty)
    {
        return Quantity -= qty;
        return Quantity;
    }

    int Item::operator+=(int qty)
    {
        return Quantity += qty;
        return Quantity;
    }

    void Item::linear(bool isLinear)
    {

        if (isLinear)
        {
            Linear = true;
        }
        else
        {
            Linear = false;
        }
    }

    void Item::clear()
    {
        Price = 0;
        Quantity = 0;
        Quantity_Needed = 0;
        SKU = 0;

        delete[] Description;
        Description = nullptr;

        Linear = false;
        state = false;
    }

    bool Item::operator==(int sku) const
    {
        bool value = false;
        if (SKU == sku)
        {
            value = true;
        }
        return value;
    }

    bool Item::operator==(const char* description) const
    {
        if (strstr(Description, description))
            return true;
        return false;
    }

    std::ofstream& Item::save(std::ofstream& ofstr) const
    {
        if (state)
        {
            ofstr << SKU << "\t";
            ofstr << Description << "\t";
            ofstr << Quantity << "\t" << Quantity_Needed << "\t" << Price;
        }
        return ofstr;
    }

    std::ifstream& Item::load(std::ifstream& ifstr)
    {
        delete[] Description;
        Description = new char[1000];

        if (ifstr)
        {
            ifstr >> SKU;
            ifstr.ignore(1000, '\t');
            ifstr.getline(Description, 1000, '\t');
            ifstr >> Quantity;
            ifstr >> Quantity_Needed;
            ifstr >> Price;
            state.clear();
            state = "This object is in a good state!";
            state = true;
        }

        return ifstr;
    }

    std::ostream& Item::display(std::ostream& ostr) const
    {
        if (Linear == true)
        {
            ostr << SKU << " | ";
            char des[36];

            strncpy(des, Description, 35);
            des[35] = '\0';
            ostr << left << setw(35) << des;
            ostr << " | ";
            // int x1 = to_string(m_qty).length();
            // int x2 = to_string(m_qty).length();
            // int  x3 = to_string(m_price).length();
            // ostr << 
            ostr << right << setw(4) << Quantity << " | " << right << setw(4)
                << Quantity_Needed << " | " << right << setw(7) << Price << " |";
        }
        else
        {
            ostr << "AMA Item:" << endl;
            ostr << SKU << ": " << Description << endl;
            ostr << "Quantity Needed: " << Quantity_Needed << endl;
            ostr << "Quantity Available: " << Quantity << endl;
            ostr.setf(ios::fixed);
            ostr.precision(2);
            ostr << "Unit Price: $" << Price << endl;
            ostr.setf(ios::fixed);
            ostr.precision(2);
            ostr << "Needed Purchase Fund: $";
            ostr << Price * (Quantity_Needed - Quantity) << endl;
        }
        return ostr;
    }

    std::istream& Item::read(std::istream& istr)
    {
        Utils a;
        delete[] Description;
        Description = nullptr;
        Description = new char[1000];

        cout << "AMA Item:\n";
        cout << "SKU: ";
        cout << SKU << endl;
        cout << "Description: ";

        istr.ignore(1000, '\n');
        istr.getline(Description, 1000);

        if (Description == nullptr)
        {
            cout << "Console entry failed!";
        }

        cout << "Quantity Needed: ";
        Quantity_Needed = a.checking_num(istr, 1, 9999);

        if (Quantity_Needed < 1 || Quantity_Needed > 9999)
        {
            cout << "Console entry failed!";
        }

        cout << "Quantity On Hand: ";
        Quantity = a.checking_num(istr, 0, 22);

        if (Quantity_Needed < 0 || Quantity_Needed > Quantity_Needed)
        {
            cout << "Console entry failed!";
        }

        cout << "Unit Price: $";
        Price = a.checking_float(istr, 0, 9999);

        if (Price < 0.0 || Price > 9999.0)
        {
            cout << "Console entry failed!";
        }
        state.clear();
        state = "This object is in a good state!";
        state = true;

        return istr;
    }

    int Item::readSku(std::istream& istr)
    {
        Utils a;
        cout << "SKU: ";
        SKU = a.checking_num(istr, 40000, 99999);
        return -1;
    }
}
