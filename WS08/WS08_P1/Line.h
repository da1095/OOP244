/* ------------------------------------------------------
Workshop 8 part 1 (Only the coding part)
Module: Line
Filename: Line.h
Version 1.1
Author: Devang Ramubhai Ahir Ahir
Revision History
-----------------------------------------------------------
Date          Reason
24/03/2022
-----------------------------------------------------------*/


#ifndef SDDS_LINE_H
#define SDDS_LINE_H

#include "LblShape.h"

namespace sdds
{
	class Line : public LblShape
	{
	private:
		int m_length;

	public:
		Line();
		Line(const char* cString, const int length);
		void getSpecs(std::istream& is);
		void draw(std::ostream& os) const;
	};
}
#endif // !SDDS_LINE_H
