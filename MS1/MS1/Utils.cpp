/* ------------------------------------------------------
Milestone 1
Module: Utils
Filename: Utils.cpp
Version 1.1
Author: Devang Ramubhai Ahir Ahir
Revision History
-----------------------------------------------------------
Date          Reason
18/03/2022
-----------------------------------------------------------*/
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <ctime>
#include "Utils.h"
using namespace std;
namespace sdds {
    // The ut object of type Utils that is accessible to any file including "Utils.h" to call the Utils
    // methods
    Utils ut;

    void Utils::testMode(bool testmode) {
        Test_Mode = testmode;
    }
    void Utils::getSystemDate(int* year, int* mon, int* day) {
        if (Test_Mode) {
            if (day) *day = sdds_Test_Day;
            if (mon) *mon = sdds_Test_Month;
            if (year) *year = sdds_Test_Year;
        }
        else {
            time_t t = std::time(NULL);
            tm lt = *localtime(&t);
            if (day) *day = lt.tm_mday;
            if (mon) *mon = lt.tm_mon + 1;
            if (year) *year = lt.tm_year + 1900;
        }
    }
    int Utils::daysOfMon(int month, int year)const {
        int days[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31, -1 };
        int mon = (month >= 1 && month <= 12 ? month : 13) - 1;
        return days[mon] + int((mon == 1) * ((year % 4 == 0) && (year % 100 != 0)) || (year % 400 == 0));
    }
    void Utils::alocpy(char*& destination, const char* source)
    {
        delete[] destination;
        destination = nullptr;
        if (source != NULL)
        {
            destination = new char[strlen(source) + 1];
            strcpy(destination, source);
        }
    }
    int Utils::getint(const char* prompt)
    {
        int input;
        if (prompt != nullptr)
        {

            cout << prompt;
            bool valid = true;
            while (valid) {

                cin >> input;
                if (cin.fail())
                {
                    valid = false;
                    cout << "Invalid Integer, retry: ";
                }
            }

        }
        return input;
    }
    int Utils::getint(int min, int max, const char* prompt, const char* errMes)
    {
        int tempInt;
        if (prompt != nullptr)
        {
            bool valid = true;

            cout << prompt;
            while (valid)
            {

                // prompt for a valid int
                cin >> tempInt;
                // check if the input is correct
                if (cin.fail() || tempInt <min || tempInt>max)
                {
                    valid = false;
                    if (errMes == nullptr)
                    {
                        cout << "Value out of range [" << min << "<= val <= " << max << "]: ";
                    }
                    else
                    {
                        cout << errMes << ", retry: ";
                    }
                    // display the error msg ---
                }

            }


        }
        return tempInt;
    }

}