/* ------------------------------------------------------
Workshop 1 part 2
Module: directory

Filename: Phone.cpp
Version 1
Author	Devang Ramubhai Ahir Ahir
Stu. ID 153484209
-----------------------------------------------------------
Date  1/22/2022     Reason
-----------------------------------------------------------*/
#define _CRT_SECURE_NO_WARNINGS
#include "Phone.h"
#include <iostream>
#include <stdio.h>

using namespace std;

namespace sdds
{
    void phoneDir(const char* programTitle, const char* fileName)
    {
        cout << programTitle << " phone direcotry search" << endl;
        cout << "-------------------------------------------------------" << endl;
        FILE* file = fopen(fileName, "r");

        if (file == 0)
        {
            cout << fileName << " file not found!" << endl;
            cout << "Thank you for using " << programTitle << " directory." << endl;
            return;
        }
        while (1)
        {
            char str[51] = { 0 }, find[51] = { 0 };
            cout << "Enter a partial name to search (no spaces) or enter '!' to exit" << endl;
            cout << "> ";
            cin >> str;
            if (strCmp(str, "!") == 0)
                break;


            char name[51] = { 0 }, lowerName[51] = { 0 }, number[5] = { 0 };
            int area, prefix;
            while (fscanf(file, "%[^\t]\t%d\t%d\t%s\n", name, &area, &prefix, number) != EOF)
            {
                toLowerCaseAndCopy(lowerName, name);
                toLowerCaseAndCopy(find, str);
                if (strStr(lowerName, find))
                    cout << name << ": (" << area << ") " << prefix << "-" << number << endl;
            }
            rewind(file);
        }
        fclose(file);
        cout << "Thank you for using " << programTitle << " directory." << endl;
    }
}