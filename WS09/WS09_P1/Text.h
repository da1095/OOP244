/* ------------------------------------------------------
Workshop 9 part 1 (Only the coding part)
Module: Text
Filename: Text.h
Version 1.1
Author: Devang Ramubhai Ahir Ahir
Revision History
-----------------------------------------------------------
Date          Reason
1/04/2022
-----------------------------------------------------------*/
#ifndef SDDS_Text_H
#define SDDS_Text_H
#include <iostream>
#include <fstream>
#include <string.h>

namespace sdds {
    class Text
    {
    private:
        char* M_Content{};

    protected:
        const char& operator[](int index) const;

    public:
        Text();

        Text(const Text& ro);

        virtual int getFileLength(std::istream& is);

        virtual Text& operator=(const Text& ro);
        ~Text();
        virtual std::istream& read(std::istream& istr);

        virtual std::ostream& write(std::ostream& ostr) const;
    };

    std::istream& operator>>(std::istream& istr, Text& ro);

    std::ostream& operator<<(std::ostream& ostr, const Text& ro);
}
#endif // !SDDS_EMPPROFILE_H