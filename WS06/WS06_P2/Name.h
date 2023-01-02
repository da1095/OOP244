/* ------------------------------------------------------
Workshop 6 part 2
Module: Name
Filename: Name.h
Version 1.1
Author: Devang Ramubhai Ahir Ahir
Revision History
-----------------------------------------------------------
Date          Reason
07/03/2022
-----------------------------------------------------------*/

#ifndef SDDS_NAME_H
#define SDDS_NAME_H

namespace sdds
{
    class Name
    {
        char* First_Name{};
        char* Middle_Name{};
        char* Last_Name{};
        bool Short{ false };
        bool Valid{ true };

    public:
        Name();
        Name(const char* first);
        Name(const char* first, const char* last);
        Name(const char* first, const char* middle, const char* last);
        Name(const Name& src);
        Name& operator=(const Name& src);
        ~Name();
        void setShort(bool value);
        std::ostream& write(std::ostream& ostr) const;
        std::istream& read(std::istream& istr);
        operator bool() const;
        Name& operator+=(const char* cStr);
        void setEmpty();
    };
    std::ostream& operator<<(std::ostream& ostr, const Name& right);
    std::istream& operator>>(std::istream& istr, Name& right);

}
#endif
