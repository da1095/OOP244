
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <ctime>
#include "Utils.h"
#include <string>
using namespace std;
namespace sdds
{
    Utils ut;
    void Utils::testMode(bool testmode)
    {
        m_testMode = testmode;
    }

    void Utils::getSystemDate(int* year, int* mon, int* day)
    {
        if (m_testMode)
        {
            if (day) *day = sdds_Test_Day;
            if (mon) *mon = sdds_Test_Month;
            if (year) *year = sdds_Test_Year;
        }
        else
        {
            time_t t = std::time(NULL);
            tm lt = *localtime(&t);
            if (day) *day = lt.tm_mday;
            if (mon) *mon = lt.tm_mon + 1;
            if (year) *year = lt.tm_year + 1900;
        }
    }
    int Utils::daysOfMon(int month, int year)const
    {
        int days[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31, -1 };
        int mon = (month >= 1 && month <= 12 ? month : 13) - 1;
        return days[mon] + ((mon == 1) && (((year % 4 == 0) && (year % 100 != 0)) || (year % 400 == 0)));
    }

    int Utils::checking_num(std::istream& istr, int x, int y)
    {
        string choice;
        int flag = 0;
        int num;

        while (1)
        {
            flag = 0;
            cin >> choice;
            for (char c : choice)
            {
                if (isdigit(c))
                {
                    continue;
                }
                flag = 1;
                break;
            }
            if (flag == 1)
            {
                cout << "Invalid Integer, retry: ";
            }
            else
            {
                num = stoi(choice);
                if (num >= x && num <= y)
                {
                    return num;
                }
                else
                {
                    cout << "Value out of range [";
                    cout << x << "<=val<=";
                    cout << y << "]: ";
                }
            }
        }
        return -1;
    }

    double Utils::checking_float(std::istream& istr, double x, double y)
    {

        string choice;
        int flag = 0;
        double num;
        int dec = 0;
        while (1)
        {
            flag = 0;
            cin >> choice;
            for (char c : choice)
            {
                if (isdigit(c))
                {
                    continue;
                }
                else if (c == '.' && dec == 0)
                {
                    dec++;
                    continue;
                }
                else
                {
                    flag = 1;
                    break;
                }
            }
            if (flag == 1)
            {
                cout << "Invalid number, retry: ";
            }
            else
            {
                num = stod(choice);
                if (num >= x && num <= y)
                {
                    return num;
                }
                else
                {
                    cout.setf(ios::fixed);
                    cout.precision(2);
                    cout << "Value out of range [";
                    cout << x << "<=val<=";
                    cout << y << "]: ";
                }
            }
        }
        return -1;
    }
}
