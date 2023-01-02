/* ------------------------------------------------------
Milestone 2
Module: N/A
Filename: main.cpp
Version 1.1
Author: Devang Ramubhai Ahir Ahir
Revision History
-----------------------------------------------------------
Date          Reason
27/03/2022
-----------------------------------------------------------*/
#include <iostream>
#include "AidMan.h"
#include "Utils.h"
int main() {
	std::cout << "Enter the following:\nabc\n1\n2\n3\n4\n5\n6\n7\n8\n0\n--------\n";
	sdds::ut.testMode();
	sdds::AidMan().run();
	return 0;
}