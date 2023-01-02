/* ------------------------------------------------------
Workshop 10 part 1 (Only the coding part)
Module: Student
Filename: Student.h
Version 1.1
Author: Devang Ramubhai Ahir Ahir
Revision History
-----------------------------------------------------------
Date          Reason
13/04/2022
-----------------------------------------------------------*/
#ifndef SDDS_STUDENT_H_
#define SDDS_STUDENT_H_
#include "Displayable.h"
namespace sdds {

    class Student :public Displayable {
        int m_stno{};
        char m_name[41]{};
        char m_subject[7]{};
        void set(int stno, const char* name, const char* subject);
    public:
        Student();
        Student(int stno, const char* name, const char* subject);
        std::ostream& display(std::ostream& os)const;
        bool operator==(const Student& S)const;
    };
}
#endif 