/* ------------------------------------------------------
Workshop 6 part 1
Module: N / A
Filename : main.cpp
Version 1.1
Author : Devang Ramubhai Ahir Ahir
Revision History
---------------------------------------------------------- -
Date          Reason
03 / 03 / 2022
---------------------------------------------------------- - */

#include <iostream>
#include <fstream>
#include "HealthCard.h"
using namespace std;
using namespace sdds;

int noOfRecs(const char* filename);
void showFile(const char* filename);
HealthCard ReadCardFromFile(istream& istr);
void dataEntryTest();
void validationTest();


int main() {
    int i;
    int recs = noOfRecs("HealthCardInfo.csv");
    HealthCard C{ "Gandalf The Grey",111,"XL","123234LA" };
    ifstream CardFile("HealthCardInfo.csv");
    ofstream goodCardFile("goodInfo.csv");
    validationTest();
    dataEntryTest();
    for (i = 0; i < recs; i++) {
        C = ReadCardFromFile(CardFile);
        cout << C << endl;
        if (CardFile)
            C.print(goodCardFile, true);
    }
    if (i == recs)
        cout << "\nAll records were read successfully!" << endl;
    else {
        cout << "Read " << i - 1 << " out of " << recs << " Records successfully" << endl;
        cout << "Record number " << i << " is invalid!" << endl;
    }
    showFile("goodInfo.csv");
    return 0;
}

void validationTest() {
    int i;
    HealthCard C[]{
       {"Fred Soley", 1234567890,"AB","WQ1234567"},
       {nullptr, 1234567890,"AB","WQ1234567" },
       {"Fred Soley", 123456789,"B","WQ1234567" },
       {"Fred Soley", 1234567890,"AB","WQ123456" },
       {"Fred Soley", 1234567890,"AB","WQ1234567" },
       {"Fred Soley", 234567890,"AB","Q1234567" },
       {"Fred Soley", 234567890,"B","WQ1234567" },
       {"Fred Soley", 1234567890,"B","Q1234567" },
    };
    cout << "Validation Test" << endl;
    for (i = 0; i < 8; cout << C[i++] << endl);
}

int noOfRecs(const char* filename) {
    int num = 0;
    ifstream file(filename);
    while (file) num += (file.get() == '\n');
    return num;
}

void showFile(const char* filename) {
    ifstream file(filename);
    char ch;
    cout << "Contents of " << filename << endl << "----------------------------------------------------------------" << endl;
    while (file.get(ch)) {
        cout << ch;
    }
}

void dataEntryTest() {
    HealthCard C{ "Fred Soley", 1234567890,"AB","WQ123456" };
    cout << endl << "Data entry test." << endl;
    cout << "Enter the test data using copy and paste to save time:" << endl << endl;

    cout << "Enter the following:" << endl
        << ">Person Name,1231231234-XL,AF1234567" << endl << ">";
    cin >> C;

    cout << "HealthCard Content:" << endl << C << endl;

    cout << "Enter the following:" << endl
        << ">Person Name,1231231234-XL,AF123456" << endl << ">";
    cin >> C;
    cout << "HealthCard Content:" << endl << C << endl;

    cout << "Enter the following:" << endl
        << ">Person Name,1231231234-L,AF1234567" << endl << ">";
    cin >> C;
    cout << "HealthCard Content:" << endl << C << endl;

    cout << "Enter the following:" << endl
        << ">Person Name,1231231234-,AF1234567" << endl << ">";
    cin >> C;
    cout << "HealthCard Content:" << endl << C << endl;

    cout << "Enter the following:" << endl
        << ">Person Name,131231234-XL,AF1234567" << endl << ">";
    cin >> C;
    cout << "HealthCard Content:" << endl << C << endl;

    cout << "Enter the following:" << endl
        << ">Person Name 1231231234-XL,AF1234567" << endl << ">";
    cin >> C;
    cout << "HealthCard Content:" << endl << C << endl;
}


HealthCard ReadCardFromFile(istream& istr) {
    HealthCard C;
    istr >> C;
    return C;
}

