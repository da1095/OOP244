/* ------------------------------------------------------
Workshop 8 part 1 (Only the coding part)
Module: Line
Filename: Line.cpp
Version 1.1
Author: Devang Ramubhai Ahir Ahir
Revision History
-----------------------------------------------------------
Date          Reason
24/03/2022
-----------------------------------------------------------*/

#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include "Line.h"

using namespace std;
namespace sdds {
	Line::Line() : LblShape() {
		m_length = 0;
	};

	Line::Line(const char* cString, const int length) : LblShape(cString) {
		m_length = length;
	};

	void Line::getSpecs(std::istream& is) {
		LblShape::getSpecs(is);
		is >> m_length;
		is.ignore();
	};

	void Line::draw(std::ostream& os) const {
		if (m_length > 0 && label() != nullptr) {
			os << label() << endl;

			for (int i = 0; i < m_length; i++) {
				os << "=";
			}
		}
	};
}