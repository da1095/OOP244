/* ------------------------------------------------------
Workshop 3 part 2
Module: Train
Filename: Train.h
Version 1
Author: Devang Ramubhai Ahir Ahir
Revision History
-----------------------------------------------------------
Date       Reason
-----------------------------------------------------------*/
#ifndef __TRAIN_H__
#define __TRAIN_H__

const int MAX_NAME_LEN = 20;
const int MAX_PEOPLE = 1000;
const int MAX_SPEED = 320;


namespace sdds
{

    class Train
    {
    public:
        void set(const char*, int, double);
        int getNumberOfPeople() const;
        const char* getName() const;
        double getSpeed() const;
        bool isSafeEmpty() const;
        void display() const;
        bool loadPeople(int);
        bool changeSpeed(double);

    private:
        char name[MAX_NAME_LEN];
        int n_people;
        double speed;
    };

    int transfer(Train& src, Train& dst);
}
#endif // __TRAIN_H__
