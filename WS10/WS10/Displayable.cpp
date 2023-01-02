/* ------------------------------------------------------
Workshop 10 part 1 (Only the coding part)
Module: Displayable
Filename: Displayable.cpp
Version 1.1
Author: Devang Ramubhai Ahir Ahir
Revision History
-----------------------------------------------------------
Date          Reason
13/04/2022
-----------------------------------------------------------*/
#include "Displayable.h"
namespace sdds {
    std::ostream& operator<<(std::ostream& os, const Displayable& D) {
        return D.display(os);
    }
}