/* ------------------------------------------------------
Milestone 3
Module: Utils
Filename: Utils.cpp
Version 1.1
Author: Devang Ramubhai Ahir Ahir
Revision History
-----------------------------------------------------------
Date          Reason
03/04/2022
-----------------------------------------------------------*/
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <ctime>
#include<cstring>
#include<iomanip>
#include "Utils.h"
using namespace std;
namespace sdds {
    Utils ut;
    void Utils::testMode(bool testmode) {
        m_testMode = testmode;
    }

    void Utils::getSystemDate(int* year, int* mon, int* day) {
        if (m_testMode) {
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

    void Utils::alocpy(char*& des, const char* source)
    {
        delete[] des;
        if (source != NULL) {
            des = new char[strlen(source) + 1];
            strcpy(des, source);
        }
    }

    int Utils::getint(const char* prompt)
    {
        int input;
        bool flag = false;
        char buffer;
        if (prompt != nullptr) {
            cout << prompt;
        }
        do {
            cin >> input;
            if (!cin) {
                cout << "Invalid Integer, retry: ";
                cin.clear();
                cin.ignore(10000, '\n');
            }
            else {
                cin.get(buffer);
                if (buffer != '\n') {
                    cout << "Enter only an integer, try again: ";
                    cin.clear();
                    cin.ignore(10000, '\n');
                }
                else {
                    flag = true;
                }
            }
        } while (!flag);
        return input;
    }

    int Utils::getint(int min, int max, const char* prompt, const char* errMes)
    {
        int input;
        char buffer;
        bool flag = false;
        if (prompt) {
            cout << prompt;
        }
        do {
            cin >> input;
            if (!cin) {
                cout << "Invalid Integer, retry: ";
                cin.clear();
                cin.ignore(10000, '\n');
            }
            else {
                cin.get(buffer);
                if (buffer != '\n') {
                    cout << "Enter only an integer, try again: ";
                    cin.clear();
                    cin.ignore(10000, '\n');
                }
                else if (input < min || input > max) {
                    if (errMes) {
                        cout << errMes << ", retry: ";
                    }
                    else {
                        cout << "Value out of range [" << min << "<=val<=" << max << "]: ";
                    }
                }
                else {
                    flag = true;
                }
            }
        } while (!flag);
        return input;
    }

    double Utils::getdouble(double min, double max, const char* prompt, const char* errMes)
    {
        double input;
        char buffer;
        bool flag = false;
        if (prompt) {
            cout << prompt;
        }
        do {
            cin >> input;
            if (!cin) {
                cout << "Invalid number, retry: ";
                cin.clear();
                cin.ignore(10000, '\n');
            }
            else {
                cin.get(buffer);
                if (buffer != '\n') {
                    cout << "Enter only a double, try again: ";
                    cin.clear();
                    cin.ignore(10000, '\n');
                }
                else if (input < min || input > max) {
                    if (errMes) {
                        cout << errMes << ", retry: ";
                    }
                    else {
                        cout << "Value out of range [" << fixed << setprecision(2) << min << "<=val<=" << max << "]: ";
                    }
                }
                else {
                    flag = true;
                }
            }
        } while (!flag);
        return input;
    }




}