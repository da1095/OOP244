/* ------------------------------------------------------
Milestone 2
Module: AidMan
Filename: AidMan.h
Version 1.1
Author: Devang Ramubhai Ahir Ahir
Revision History
-----------------------------------------------------------
Date          Reason
27/03/2022
-----------------------------------------------------------*/

#ifndef SDDS_AIDMAN_H
#define SDDS_AIDMAN_H
#include "Menu.h"
namespace sdds
{
	class AidMan
	{
		char* File{};
		Menu Menu_Obj;
		unsigned int menu() const;
	public:
		AidMan();
		~AidMan();
		void run();
	};
}
#endif // !SDDS_AIDMAN_H