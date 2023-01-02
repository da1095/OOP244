/* ------------------------------------------------------
Workshop 8 part 1 (Only the coding part)
Module: LblShape
Filename: LblShape.h
Version 1.1
Author: Devang Ramubhai Ahir Ahir
Revision History
-----------------------------------------------------------
Date          Reason
24/03/2022
-----------------------------------------------------------*/
#ifndef SDDS_LBL_SHAPE_H
#define SDDS_LBL_SHAPE_H

#include "Shape.h"

namespace sdds {
	class LblShape : public Shape {
	private:
		char* m_label = nullptr;

	protected:
		const char* label() const;

	public:
		LblShape();
		LblShape(const char* cString);
		void getSpecs(std::istream& is);
		~LblShape();
	};
}
#endif // !SDDS_LBL_SHAPE_H
