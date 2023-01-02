/* ------------------------------------------------------
Workshop 8 part 1 (Only the coding part)
Module: Rectangle
Filename: Rectangle.cpp
Version 1.1
Author: Devang Ramubhai Ahir Ahir
Revision History
-----------------------------------------------------------
Date          Reason
24/03/2022
-----------------------------------------------------------*/

#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <iomanip>
#include <string.h>
#include "Rectangle.h"
#include "Line.h"

using namespace std;

namespace sdds
{
	Rectangle::Rectangle() : LblShape() {
		m_width = 0;
		m_height = 0;
	};

	Rectangle::Rectangle(const char* cString, const int width, const int height) : LblShape(cString)
	{
		int value = strlen(label()) + 2;

		if (height < 3 || width < value) {
			m_width = 0;
			m_height = 0;
		}
		else {
			m_width = width;
			m_height = height;
		}
	};

	void Rectangle::getSpecs(std::istream& is)
	{
		LblShape::getSpecs(is);
		is >> m_width;
		is.ignore(2000, ',');
		is >> m_height;
		is.ignore(2000, '\n');
	};

	void Rectangle::draw(std::ostream& os) const
	{
		if (m_width > 0 && m_height > 0) {
			os << "+";
			for (int i = 0; i < m_width - 2; i++) {
				os << "-";
			}
			os << "+" << endl;

			os << "|";
			os << setw((streamsize)m_width - 2) << setfill(' ') << left << label();
			os << "|" << endl;

			for (int i = 0; i < m_height - 3; i++) {
				os << "|" << setw((streamsize)m_width - 2) << " " << "|" << endl;
			}

			os << "+";
			for (int i = 0; i < m_width - 2; i++) {
				os << "-";
			}
			os << "+";
		}
	};
}

