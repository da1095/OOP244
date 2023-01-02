/* ------------------------------------------------------
Milestone 2
Module: Menu
Filename: Menu.h
Version 1.1
Author: Devang Ramubhai Ahir Ahir
Revision History
-----------------------------------------------------------
Date          Reason
27/03/2022
-----------------------------------------------------------*/

#ifndef SDDS_MENU_H
#define SDDS_MENU_H

namespace sdds
{
	const int Max = 15;
	class Menu
	{
		char* Content{};
		unsigned int Option;

	public:
		Menu();
		~Menu();
		unsigned int run() const;
		void setMenu(const char* cString, int n);

	};
}

#endif // !SDDS_MENU_H