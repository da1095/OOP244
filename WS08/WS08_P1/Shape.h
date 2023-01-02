/* ------------------------------------------------------
Workshop 8 part 1 (Only the coding part)
Module: Shape
Filename: Shape.h
Version 1.1
Author: Devang Ramubhai Ahir Ahir
Revision History
-----------------------------------------------------------
Date          Reason
24/03/2022
-----------------------------------------------------------*/

#ifndef SDDS_SHAPE_H
#define SDDS_SHAPE_H

#include <iostream>

namespace sdds {
	class Shape {
	public:
		virtual void draw(std::ostream& os) const = 0;
		virtual void getSpecs(std::istream& is) = 0;
		virtual ~Shape();
	};

	std::ostream& operator <<(std::ostream& os, const Shape& shape);
	std::istream& operator >>(std::istream& is, Shape& shape);
}
#endif // !SDDS_SHAPE_H
