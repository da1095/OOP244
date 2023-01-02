/* ------------------------------------------------------
Workshop 7 part 1 (Only the coding part)
Module: Container
Filename: Container.h
Version 1.1
Author: Devang Ramubhai Ahir Ahir
Revision History
-----------------------------------------------------------
Date          Reason
17/03/2022
-----------------------------------------------------------*/
#ifndef CONTAINER_H
#define CONTAINER_H

#include <iostream>
#include <cstring>
using namespace std;

namespace sdds {
    class Container {
    private:
        char Description[50];
        int Capacity;
        int Volume;
        bool Valid_Container;

    protected:
        void setEmpty();
        int capacity();
        int volume();

    public:

        Container(const char* Content, int Capacity, int Content_volume = 0);
        int operator += (int value);
        int operator -= (int value);
        bool valid();
        void clear(int Capacity, const char* Content);
        ostream& print(ostream& out);
        istream& read(istream& in);
        friend ostream& operator << (ostream& out, Container& C) {
            return C.print(out);
        }

        friend istream& operator >> (istream& in, Container& C) {
            return C.read(in);
        }
    };
}

#endif