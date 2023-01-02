/* ------------------------------------------------------
Milestone 1
Module: N/A
Filename: main.cpp
Version 1.1
Author: Devang Ramubhai Ahir Ahir
Revision History
-----------------------------------------------------------
Date          Reason
18/03/2022
-----------------------------------------------------------*/
#include <iostream>
#include "Date.h"
#include "Utils.h"
#include "Status.h"
using namespace std;
using namespace sdds;

void statusTester();
void dateTester();

int main() {
    cout << "Status Tester -----------------------------------------------------" << endl;
    statusTester();
    cout << "Date Tester -------------------------------------------------------" << endl;
    dateTester();
}



// Copied from StatusTestr.cpp
const int c_min{ 0 };
const int c_max{ 100 };

class Container {
    int m_val{};
    sdds::Status m_state;
    Container& set(int value) {
        if (value < c_min) {
            m_state = "value too low";
            m_state = -1;
        }
        else if (value > c_max) {
            m_state = "value too high";
            m_state = 1;
        }
        else {
            m_state.clear();
        }
        return *this;
    }
public:
    Container(int value = 0) {
        set(value);
    }
    istream& read(istream& istr = cin) {
        istr >> m_val;
        m_state.clear();
        if (istr) {
            set(m_val);
        }
        else {
            m_state = "Invalid Integer";
            istr.clear();
        }
        istr.ignore(1000, '\n');
        return istr;
    }
    ostream& write(ostream& ostr = cout)const {
        if (m_state) {
            ostr << m_val;
        }
        else {
            ostr << m_state;
        }
        return ostr;
    }
    Container& value(int val) {
        set(val);
        return *this;
    }
    int value()const {
        return m_val;
    }
    operator bool()const {
        return m_state;
    }
    const sdds::Status& state()const {
        return m_state;
    }
};
ostream& operator<<(ostream& ostr, const Container& I) {
    return I.write(ostr);
}
istream& operator>>(istream& istr, Container& I) {
    return I.read(istr);
}

void prnContainer(Container C) {
    cout << "Container: (" << C << ")" << endl;
    if (!C) {
        cout << "Error #: " << int(C.state()) << endl;
        cout << "Problem: " << (const char*)(C.state()) << endl;
    }
}

void statusTester() {
    Container c;
    cout << "Enter following values :\nabc\n123\n-123\n12" << endl;
    for (int i = 0; i < 4; i++) {
        cout << "> ";
        cin >> c;
        prnContainer(c);
    }
}

// Copied from DateTester.cpp
void testDate() {
    Date D;
    cout << "> ";
    cin >> D;
    if (!cin) {
        cin.clear();
        cin.ignore(1000, '\n');
        cout << D.state() << endl;
    }
    else {
        cout << "Date enterd: " << D << endl;
    }
}
void dateTester() {
    cout << "Current Date: " << Date() << endl;
    cout << "Test mode: " << endl;
    ut.testMode();
    Date C;
    Date F(2022, 5, 25);
    cout << "Current Date formatted (C): " << C << endl;
    C.formatted(false);
    cout << "Current Date unformatted (C): " << C << endl;
    cout << "Future Date formatted (F): " << F << endl;
    F.formatted(false);
    cout << "Future Date unformatted (F): " << F << endl;
    cout << "The current date is" << (C != F ? " NOT" : "") << " the same as the future date" << endl;
    cout << "The current date is" << (C == C ? "" : " NOT") << " the same as the current date" << endl;
    cout << "The current date is" << (C <= F ? " Less than or equal to" : " greater than") << " the future date" << endl;;
    cout << "The current date is" << (C <= C ? " Less than or equal to" : " greater than") << " the current date" << endl;;
    cout << "The current date is" << (C < F ? " Less than" : " greater than or equal to") << " the future date" << endl;;
    cout << "The future date is" << (F >= C ? " greater than or equal to" : " Less than") << " the current date" << endl;;
    cout << "The future date is" << (F >= F ? " greater than or equal to" : " Less than") << " the future date" << endl;;
    cout << "The future date is" << (F > C ? " greater than" : " Less than or equal to") << " the current date" << endl;;
    cout << "--------------\nAssigning the Current date to the future date!" << endl;
    C = F;
    if (C == F)
        cout << "Now both of the dates are the same!" << endl;
    else
        cout << "The two dates are different after assignment!!!!!" << endl;
    cout << "Enter the following:\n1- abc\n2- 12\n3- 1212\n4- 121212"
        "\n5- 221312\n6- 220229\n7- 220228" << endl;
    for (int i = 0; i < 7; i++) {
        testDate();
    }
}