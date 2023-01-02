/* ------------------------------------------------------
Milestone 3
Module: Utils
Filename: Utils.h
Version 1.1
Author: Devang Ramubhai Ahir Ahir
Revision History
-----------------------------------------------------------
Date          Reason
03/04/2022
-----------------------------------------------------------*/
#ifndef SDDS_UTILS_H
#define SDDS_UTILS_H
namespace sdds {
    const int sdds_Test_Year = 2022;
    const int sdds_Test_Month = 03;
    const int sdds_Test_Day = 31;
    class Utils {
        bool m_testMode = false;
    public:
        void getSystemDate(int* year = nullptr, int* mon = nullptr, int* day = nullptr);
        int daysOfMon(int mon, int year)const;
        void testMode(bool testmode = true);
        void alocpy(char*& des, const char* source);
        int getint(const char* prompt = nullptr);
        int getint(int min, int max, const char* prompt = nullptr, const char* errMes = nullptr);
        double getdouble(double min, double max, const char* prompt = nullptr, const char* errMes = nullptr);
    };
    extern Utils ut;
}

#endif // !SDDS_UTILS_H
