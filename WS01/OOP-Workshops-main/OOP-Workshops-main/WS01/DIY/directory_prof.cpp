/* ------------------------------------------------------
Workshop 1 part 2
Module: directory
Filename: directory_prof.cpp
Version 1
Author	Fardad Soleimanloo
Revision History
-----------------------------------------------------------
Date       Reason
-----------------------------------------------------------*/
#include <iostream>
#include "Phone.h"
using namespace sdds;
int main() {
   std::cout << "Enter the following Data:" << std::endl
      << "----------------------\n"
         "lukE\nsky\nfett\nfeT\nJack\n!\n"
         "----------------------\n";
   phoneDir("Star Wars", "phones.txt");
   std::cout << std::endl << "----------------------------------" << std::endl;
   phoneDir("Broken Phone Book", "badDataFile.txt");
   return 0;
}