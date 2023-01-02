/* ------------------------------------------------------
Workshop 2 part 2
Module: cStrTools
Filename: cStrTools.h
Version 1
Author	Devang Ramubhai Ahir Ahir
Revision History
-----------------------------------------------------------
Date       Reason
-----------------------------------------------------------*/
#ifndef NAMESPACE_CSTRTOOLS_H // replace with relevant names
#define NAMESPACE_CSTRTOOLS_H
namespace sdds
{

    char toLower(char ch);

    int strCmp(const char* s1, const char* s2);

    int strnCmp(const char* s1, const char* s2, int len);

    const char* strStr(const char* str, const char* find);

    void strCpy(char* des, const char* src);

    int strLen(const char* str);

    int isAlpha(char ch);

    int isSpace(char ch);

    void trim(char word[]);

    void toLowerCaseAndCopy(char des[], const char source[]);

    void read(char* cString, unsigned int maxSize, char delimiter = '\n');
}
#endif