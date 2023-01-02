/* ------------------------------------------------------
Workshop 8 part 1 (Only the coding part)
Module: Shape
Filename: Shape.cpp
Version 1.1
Author: Devang Ramubhai Ahir Ahir
Revision History
-----------------------------------------------------------
Date          Reason
24/03/2022
-----------------------------------------------------------*/

#include <iostream>
#include "Shape.h"

using namespace std;
namespace sdds {
	std::ostream& operator<<(std::ostream& os, const Shape& shape) {
		shape.draw(os);
		return os;
	};

	std::istream& operator>>(std::istream& is, Shape& shape) {
		shape.getSpecs(is);
		return is;
	};

	Shape::~Shape() {
	};
}