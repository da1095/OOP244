/* ------------------------------------------------------
Workshop 3 part 1
Module: Train
Filename: Train.h
Version 1.1
Author: Devang Ramubhai Ahir Ahir
Revision History
-----------------------------------------------------------
Date          Reason
3/02/2022
-----------------------------------------------------------*/

#ifndef NAMESPACE_TRAIN_H
#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<iomanip>
#include<cstring>
const int MAX_NAME_LEN = 20;
const int MAX_PEOPLE = 1000;
const int MAX_SPEED = 320;


using namespace std;
namespace sdds
{
    class Train
    {

        private:
            char train_name[MAX_NAME_LEN];
            int number_of_people;
            double speed;


        public:
            void set(const char* name, int num, double s);
            double getSpeed();
            int getNumberOfPeople();
            char* getName();
            bool isSafeEmpty();
            void display();
    };

}
#endif