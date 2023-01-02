/* ------------------------------------------------------
Workshop 6 part 2
Module: Utils
Filename: Utils.cpp
Version 1.1
Author: Devang Ramubhai Ahir Ahir
Revision History
-----------------------------------------------------------
Date          Reason
07/03/2022
-----------------------------------------------------------*/

#define _CRT_SECURE_NO_WARNINGS
#include <string.h>
#include "Utils.h"
namespace sdds
{

    bool NullEmpty(const char* cStr)
    {

        bool result = false;
        if (cStr && cStr[0])
        {
            for (int i = 0; cStr[i] != 0 && !result; i++, result = cStr[i] != ' ')
                ;
        }
        return !result;
    }
    void allocCopy(char*& des, const char* src)
    {
        if (!NullEmpty(src))
        {
            delete[] des;
            des = new char[strlen(src) + 1];
            strcpy(des, src);
        }
    }

}
