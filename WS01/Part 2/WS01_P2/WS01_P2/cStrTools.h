/* ------------------------------------------------------
Workshop 1 part 2
Module: directory
Filename: cStrTools.h
Version 1
Author	Devang Ramubhai Ahir Ahir
Stu. ID 153484209
-----------------------------------------------------------
Date  1/22/2022     Reason
-----------------------------------------------------------*/
#ifndef NAMESPACE_CSTRTOOLS_H // replace with relevant names
#define NAMESPACE_CSTRTOOLS_H
#include <string>
using namespace std;
namespace sdds {

	// Your header file content goes here
	char toLower(char ch);
	int strCmp(const char* s1, const char* s2);
	const char* strStr(const char* str, const char* find);
	void strCpy(char* des, const char* src);
	int strLen(const char* str);
	int isAlpha(char ch);
	int isSpace(char ch);
	void trim(char word[]);
	void toLowerCaseAndCopy(char des[], const char source[]);
	

}
#endif
