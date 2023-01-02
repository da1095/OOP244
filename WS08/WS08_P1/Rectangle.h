/* ------------------------------------------------------
Workshop 8 part 1 (Only the coding part)
Module: Rectangle
Filename: Rectangle.h
Version 1.1
Author: Devang Ramubhai Ahir Ahir
Revision History
-----------------------------------------------------------
Date          Reason
24/03/2022
-----------------------------------------------------------*/

#ifndef SDDS_RECTANGLE_H
#define SDDS_RECTANGLE_H

#include "LblShape.h"

namespace sdds {
	class Rectangle : public LblShape {
	private:
		int m_width;
		int m_height;

	public:
		Rectangle();
		Rectangle(const char* cString, const int width, const int height);
		void getSpecs(std::istream& is);
		void draw(std::ostream& os) const;
	};
}
#endif // !SDDS_RECTANGLE_H
