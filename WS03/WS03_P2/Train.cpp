/* ------------------------------------------------------
Workshop 3 part 2
Module: Train
Filename: Train.cpp
Version 1
Author: Devang Ramubhai Ahir Ahir
Revision History
-----------------------------------------------------------
Date       Reason
-----------------------------------------------------------*/
#define _CRT_SECURE_NO_WARNINGS
#include "Train.h"
#include <iomanip>
#include <iostream>
#include <string.h>
using namespace std;

namespace sdds
{
    void Train::set(const char* _name, int _n_people, double _speed)
    {
        bool valid1 = false, valid2 = false, valid3 = false;

        if (_name != nullptr && strlen(_name) > 0)
        {
            strncpy(this->name, _name, MAX_NAME_LEN);
            valid1 = true;
        }

        if (_n_people >= 0 && _n_people <= MAX_PEOPLE)
        {
            this->n_people = _n_people;
            valid2 = true;
        }

        if (_speed >= 0 && _speed <= MAX_SPEED)
        {
            this->speed = _speed;
            valid3 = true;
        }
        if (!valid1 || !valid2 || !valid3)
        {
            memset(this->name, 0, MAX_NAME_LEN);
            this->n_people = MAX_PEOPLE + 1;
            this->speed = MAX_SPEED + 1;
        }
    }

    int Train::getNumberOfPeople() const
    {
        return this->n_people;
    }

    const char* Train::getName() const
    {
        return this->name;
    }

    double Train::getSpeed() const
    {
        return this->speed;
    }

    bool Train::isSafeEmpty() const
    {
        if (strcmp(this->name, "") == 0 && this->n_people == MAX_PEOPLE + 1 && this->speed == MAX_SPEED + 1)
            return true;
        return false;
    }

    void Train::display() const
    {
        if (isSafeEmpty())
        {
            cout << "Safe Empty State!" << endl;
            return;
        }
        cout << "NAME OF THE TRAIN : " << this->name << endl;
        cout << "NUMBER OF PEOPLE  : " << this->n_people << endl;
        cout << "SPEED             : " << fixed << setprecision(2) << this->speed << " km/h" << endl;
    }

    bool Train::loadPeople(int value)
    {
        if (this->isSafeEmpty())
            return false;
        if (this->n_people + value < 0)
        {
            this->n_people = 0;
            return false;
        }
        if (this->n_people + value > MAX_PEOPLE)
        {
            this->n_people = MAX_PEOPLE;
            return false;
        }
        if (this->n_people + value >= 0 && this->n_people + value <= MAX_PEOPLE)
        {
            this->n_people += value;
            return true;
        }
        return false;
    }

    bool Train::changeSpeed(double value)
    {
        if (this->isSafeEmpty())
            return false;
        if (this->speed + value < 0)
        {
            this->speed = 0;
            return false;
        }
        if (this->speed + value > MAX_SPEED)
        {
            this->speed = MAX_SPEED;
            return false;
        }
        if (this->speed + value >= 0 && this->speed + value <= MAX_SPEED)
        {
            this->speed += value;
            return true;
        }
        return false;
    }

    int transfer(Train& src, Train& dst)
    {
        if (src.isSafeEmpty() || dst.isSafeEmpty())
            return -1;
        int cnt = 0;
        while (dst.loadPeople(-1))
        {
            if (src.loadPeople(1))
                cnt++;
            else
            {
                dst.loadPeople(1);
                break;
            }
        }
        return cnt;
    }
}
