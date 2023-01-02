/* ------------------------------------------------------
Workshop 6 part 2
Module: N/A
Filename: main.cpp
Version 1.1
Author: Devang Ramubhai Ahir Ahir
Revision History
-----------------------------------------------------------
Date          Reason
07/03/2022
-----------------------------------------------------------*/
#include <iostream>
#include <fstream>
#include "Name.h"
using namespace sdds;
using namespace std;

void printNames(const Name* n, int size = 1) {
    cout << "Names;" << endl << "First (Middle) Last" << endl;
    for (int i = 0; i < size; i++) {
        cout << n[i] << endl;
    }
}
// get a copy of the Name
void printName(Name N, bool shortOnly = false) {
    if (!shortOnly) {
        N.setShort(false);
        cout << "Name: " << N << endl;
    }
    N.setShort(true);
    if (!shortOnly) cout << "Short: ";
    cout << N << endl;
}

void nameTester(const char* prompt) {
    Name N;
    cout << prompt;
    cin >> N;
    if (N) {
        printName(N);
    }
    else {
        cout << N << " entry!!!" << endl;
        cin.ignore(1000, '\n');
    }
}

int main() {
    Name A[4] = { {"Homer"},{"Homer", "Simpson"}, {"Homer", "Jay", "Simpson"} };
    Name N = "Milhouse";
    printNames(A, 4);
    nameTester("Enter the follwing:\n> Homer Jay Simpson Adams\n> ");
    nameTester("Enter the follwing:\n> Homer Jay Simpson\n> ");
    nameTester("Enter the follwing:\n> Homer Simpson\n> ");
    nameTester("Enter the follwing:\n> Homer\n> ");
    cout << N << "+= \"\": " << (N += "") << endl;
    cout << N << "+= \"    \": " << (N += "   ") << endl;
    cout << N << "+= Van: " << (N += "Van") << endl;
    cout << N << "+= Houten: " << (N += "Houten") << endl;
    cout << N << "+= Adams: " << (N += "Adams") << endl;
    cout << A[3] << "+= Fred: " << (A[3] += "Fred") << endl;

    A[1] = A[2];
    cout << "An assigned name: " << A[1] << endl;
    A[2] = A[2];
    cout << "A self assigned name: " << A[1] << endl;
    ifstream names("names.txt");
    cout << endl << "Names in the file in short form:" << endl
        << "-------------------------------" << endl;
    while (names) {
        // this will call operator>> since ifstream is an istream but for files
        names >> N;
        if (names) {
            if (N) {
                printName(N, true);
            }
            else {
                cout << "--------------Bad record!!!" << endl;
                names.clear();
                names.ignore(1000, '\n');
            }
        }
    }

    return 0;
}