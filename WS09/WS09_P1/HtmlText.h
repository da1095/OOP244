/* ------------------------------------------------------
Workshop 9 part 1 (Only the coding part)
Module: HtmlText
Filename: HtmlText.h
Version 1.1
Author: Devang Ramubhai Ahir Ahir
Revision History
-----------------------------------------------------------
Date          Reason
1/04/2022
-----------------------------------------------------------*/
#ifndef SDDS_HtmlText_H
#define SDDS_HtmlText_H
#include <iostream>
#include <fstream>
#include <string.h>
#include "Text.h"


namespace sdds
{
    class HtmlText : public Text
    {
        char* M_Title{};
    public:
        HtmlText();

        HtmlText(const char* ro);

        HtmlText& operator=(const HtmlText& ro);

        ~HtmlText();

        std::ostream& write(std::ostream& ostr) const;
    };
    std::istream& operator>>(std::istream& istr, HtmlText& ro);

    std::ostream& operator<<(std::ostream& ostr, const HtmlText& ro);
}

#endif // !SDDS_EMPPROFILE_H