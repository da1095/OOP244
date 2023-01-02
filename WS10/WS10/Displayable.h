/* ------------------------------------------------------
Workshop 10 part 1 (Only the coding part)
Module: Displayable
Filename: Displayebl.h
Version 1.1
Author: Devang Ramubhai Ahir Ahir
Revision History
-----------------------------------------------------------
Date          Reason
13/04/2022
-----------------------------------------------------------*/
#ifndef SDDS_DISPLAYABLE_H_
#define SDDS_DISPLAYABLE_H_
#include <iostream>
namespace sdds {
    class Displayable {
    public:
        virtual std::ostream& display(std::ostream& os)const = 0;
    };

    std::ostream& operator<<(std::ostream& os, const Displayable& D);
}

#endif
