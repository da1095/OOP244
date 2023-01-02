/* ------------------------------------------------------
Milestone 3
Module: Status
Filename: Status.h
Version 1.1
Author: Devang Ramubhai Ahir Ahir
Revision History
-----------------------------------------------------------
Date          Reason
03/04/2022
-----------------------------------------------------------*/
#ifndef SDDS_STATUS_H_
#define SDDS_STATUS_H_
namespace sdds {
    class Status {
        char* Description{};
        int Codigo{};// Spanish word for code is codigo
    public:
        Status(const char* desc = nullptr);
        // Rule of three
        Status(const Status& S);
        Status& operator=(const Status& S);
        ~Status();
        //
        Status& operator=(int statusCode);
        Status& operator=(const char* desc);
        operator int() const;
        operator const char* ()const;
        operator bool() const;
        Status& clear();
        std::ostream& display(std::ostream& ostr)const;
    };
    std::ostream& operator<<(std::ostream& ostr, const Status& S);
}


#endif // !SDDS_STATUS_H_