/* ------------------------------------------------------
Workshop 3 part 1
Module: Train
Filename: Train.cpp
Version 1.1
Author: Devang Ramubhai Ahir Ahir 
Revision History
-----------------------------------------------------------
Date          Reason
3/02/2022    
-----------------------------------------------------------*/

#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<iomanip>
#include<cstring>
#include "Train.h"



using namespace std;
namespace sdds
{

    void Train::set(const char* name, int num, double s)
    {

        if (name != nullptr && strlen(name) > 0 && num >= 0 && s >= 0 && s <= MAX_SPEED)
        {
            strcpy(train_name, name);
            number_of_people = num;
            speed = s;
        }

        else
        {
            strcpy(train_name, "Seneca Express");
            number_of_people = 0;
            speed = 0;
        }
    }



    double Train::getSpeed()
    {
        return speed;
    }
    int Train::getNumberOfPeople()
    {
        return number_of_people;
    }
    char* Train::getName()
    {
        return train_name;
    }



    bool Train::isSafeEmpty()
    {
        if (strcmp("Seneca Express", train_name) == 0 && speed == 0 && number_of_people == 0)
        {
            return true;
        }
        return false;
    }



    void Train::display()
    {
        if (!isSafeEmpty())
        {
            cout << "NAME OF THE TRAIN : " << train_name << endl;
            cout << "NUMBER OF PEOPLE  : " << number_of_people << endl;
            cout << "SPEED             : " << speed << " km/h" << endl;
        }
        else
        {
            cout << "Safe Empty State!" << endl;
        }
    }


};