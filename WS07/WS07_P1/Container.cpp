/* ------------------------------------------------------
Workshop 7 part 1 (Only the coding part)
Module: Container
Filename: Container.cpp
Version 1.1
Author: Devang Ramubhai Ahir Ahir
Revision History
-----------------------------------------------------------
Date          Reason
17/03/2022
-----------------------------------------------------------*/
#define _CRT_SECURE_NO_WARNINGS
#include <cstring>
#include<string>
#include "Container.h"
using namespace std;

namespace sdds {
    void Container::setEmpty() {
        Valid_Container = false;
    }


    int Container::capacity() {
        return Capacity;
    }


    int Container::volume() {
        return Volume;
    }




    Container::Container(const char* Content, int Capacity, int Content_volume) {
        if (Content == NULL || Content_volume > Capacity) {
            Valid_Container = false;
        }
        else {
            strcpy(this->Description, Content);
            this->Capacity = Capacity;
            this->Volume = Content_volume;
            Valid_Container = true;
        }
    }



    int Container::operator += (int value) {
        if (Volume + value <= Capacity) {
            Volume += value;
        }
        else {
            value = Capacity - Volume;
            Volume = Capacity;
        }

        return value;
    }



    int Container::operator -= (int value) {
        if (Volume - value >= 0) {
            Volume -= value;
        }
        else {
            value = Volume;
            Volume = 0;
        }

        return value;
    }



    bool Container::valid() {
        return Valid_Container;
    }



    void Container::clear(int Capacity, const char* m_description) {
        if (Capacity >= 1 && m_description != NULL && strlen(m_description) >= 1) {
            this->Capacity = Capacity;
            strcpy(this->Description, m_description);
            this->Volume = 0;
            Valid_Container = true;
        }
    }




    ostream& Container::print(ostream& ostr) {
        if (Valid_Container) {
            ostr << Description << ": (" << Volume << "cc/" << Capacity << ")";
        }
        else {
            ostr << "****: (**cc/***)";
        }

        return ostr;
    }




    istream& Container::read(istream& istr) {

        int number;

        if (!Valid_Container) {
            cout << "Broken Container, adding aborted! Press <ENTER> to continue...." << endl;
            istr.ignore();

        }
        else {
            bool validValue = false;
            cout << "Add to ";
            print(cout);

            while (!validValue) {
                cout << endl << "> ";
                istr >> number;

                if (number > Capacity) {
                    cout << "Invalid Integer, retry:";
                }

                else if (number < 1 || number > 999) {
                    cout << "Value out of range [1<=val<=999]:";
                }

                else validValue = true;
            }


            number = (*this += number);
            cout << "Added " << number << " CCs" << endl;
        }

        return istr;
    }
}