/* ------------------------------------------------------
Workshop 10 part 1 (Only the coding part)
Module: Employee
Filename: Employee.cpp
Version 1.1
Author: Devang Ramubhai Ahir Ahir
Revision History
-----------------------------------------------------------
Date          Reason
13/04/2022
-----------------------------------------------------------*/
#define _CRT_SECURE_NO_WARNINGS
#include <iomanip>
#include <cstring>
#include "Employee.h"
namespace sdds {
    void Employee::set(int stno, const char* name, int officeNo) {
        m_empno = stno;
        std::strcpy(m_name, name);
        m_officeNo = officeNo;
    }
    Employee::Employee() {
    }
    Employee::Employee(int stno, const char* name, int officeNo) {
        set(stno, name, officeNo);
    }
    std::ostream& Employee::display(std::ostream& os)const {
        return os << m_empno << ", " << m_name << ", " << m_officeNo;
    }
    bool Employee::operator==(const Employee& E)const {
        return m_officeNo == E.m_officeNo;
    }
}