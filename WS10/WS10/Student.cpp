/* ------------------------------------------------------
Workshop 10 part 1 (Only the coding part)
Module: Student
Filename: Student.cpp
Version 1.1
Author: Devang Ramubhai Ahir Ahir
Revision History
-----------------------------------------------------------
Date          Reason
13/04/2022
-----------------------------------------------------------*/
#define _CRT_SECURE_NO_WARNINGS
#include <cstring>
#include "Student.h"
namespace sdds {
    void Student::set(int stno, const char* name, const char* subject) {
        m_stno = stno;
        std::strcpy(m_name, name);
        std::strcpy(m_subject, subject);
    }
    Student::Student() {
    }
    Student::Student(int stno, const char* name, const char* subject) {
        set(stno, name, subject);
    }
    std::ostream& Student::display(std::ostream& os)const {
        return os << m_stno << ", " << m_name << ", " << m_subject;
    }
    bool Student::operator==(const Student& S)const {
        return std::strcmp(m_subject, S.m_subject) == 0;
    }
}