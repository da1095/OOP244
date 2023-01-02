/* ------------------------------------------------------
Workshop 9 part 1 (Only the coding part)
Module: HtmlText
Filename: HtmlText.cpp
Version 1.1
Author: Devang Ramubhai Ahir Ahir
Revision History
-----------------------------------------------------------
Date          Reason
1/04/2022
-----------------------------------------------------------*/
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <fstream>
#include <string.h>
#include "HtmlText.h"

namespace sdds {
    HtmlText::HtmlText() : Text()
    {
        M_Title = nullptr;
    }

    HtmlText::HtmlText(const char* ro) : Text()
    {
        M_Title = new char[strlen(ro) + 1];
        strcpy(M_Title, ro);
    }

    HtmlText& HtmlText ::operator=(const HtmlText& ro)
    {

        delete M_Title;

        M_Title = new char[strlen(ro.M_Title) + 1];
        strcpy(M_Title, ro.M_Title);

        Text::operator=(ro);

        return *this;
    }

    HtmlText ::~HtmlText()
    {
        delete[] M_Title;
    }

    std::ostream& HtmlText::write(std::ostream& ostr) const
    {
        // ostr << this->operator[](1);
        ostr << "<html><head><title>";
        if (M_Title != nullptr)
        {
            ostr << M_Title;
        }
        else
        {
            ostr << "No Title";
        }
        ostr << "</title></head>\n<body>\n";
        if (M_Title != nullptr)
        {
            ostr << "<h1>" << M_Title << "</h1>\n";
        }
        bool MS = false;
        int i = 0;
        while (this->operator[](i) != '\0')
        {
            const char ch = this->operator[](i);

            if (ch == ' ')
            {
                if (MS)
                {

                    ostr << "&nbsp;";
                }
                else
                {

                    MS = true;

                    ostr << ' ';
                }
            }
            else if (ch == '<')
            {
                MS = false;
                ostr << "&lt;";
            }
            else if (ch == '>')
            {
                MS = false;
                ostr << "&gt;";
            }
            else if (ch == '\n')
            {

                MS = false;
                ostr << "<br />\n";
            }
            else
            {
                MS = false;
                ostr << ch;
            }

            i++;
        }
        ostr << "</body>\n</html>";
        return ostr;
    }


    std::istream& operator>>(std::istream& istr, HtmlText& ro)
    {
        return ro.read(istr);
    }


    std::ostream& operator<<(std::ostream& ostr, const HtmlText& ro)
    {
        return ro.write(ostr);
    }
}