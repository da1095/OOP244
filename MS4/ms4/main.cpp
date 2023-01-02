/* ------------------------------------------------------
Milestone 4
Module: N/A
Filename: main.cpp
Version 1.1
Author: Devang Ramubhai Ahir Ahir
Revision History
-----------------------------------------------------------
Date          Reason
07/04/2022
-----------------------------------------------------------*/
#include <iostream>
#include <fstream>
#include "iProduct.h"
#include "Perishable.h"
using namespace std;
using namespace sdds;
void resetToOriginal();
void entryAndSave();
void fileAndRuleOf3();
void display(Perishable P);
void displayLinear(Perishable p);
int main() {
    resetToOriginal();
    entryAndSave();
    fileAndRuleOf3();
    return 0;
}
void resetToOriginal() {
    ifstream in("dataOriginal.dat");
    ofstream out("data.dat");
    char ch;
    while (in.get(ch)) out.put(ch);
}
void entryAndSave() {
    ofstream file("data.dat", ios::app);
    iProduct* p = new Perishable;
    cout << "Enter the following values: " << endl
        <<
        "4444\n"
        "44444\n"
        "11111\n"
        "Advil Extra Strength Caplets\n"
        "22\n"
        "2\n"
        "22.22\n"
        "221212\n"
        "<ENTER>\n" << "------------------------" << endl;
    p->readSku(cin);
    cin >> *p;
    cout << "------------------------" << endl;
    cout << *p;
    cout << "------------------------" << endl;
    p->linear(true);
    cout << *p << endl;
    p->save(file) << endl;
    cout << "Enter the following values: " << endl
        <<
        "22222\n"
        "Advil\n"
        "33\n"
        "3\n"
        "33.33\n"
        "221212\n"
        "Keep in room temperature\n" << "------------------------" << endl;
    p->readSku(cin);
    cin >> *p;
    cout << "------------------------" << endl;
    p->linear(false);
    cout << *p << endl;
    cout << "------------------------" << endl;
    p->linear(true);
    cout << *p << endl;
    p->save(file) << endl;
    file.flush();
    file.close();
    delete p;
}
void fileAndRuleOf3() {
    ifstream file("data.dat");
    Perishable p;
    Perishable last;
    cout << "--------------------------------------------------------------------------------" << endl;
    while (p.load(file)) {
        displayLinear(last);
        display(p);
        last = p;
    }
    displayLinear(last);
}
void display(Perishable p) {
    if (p) {
        cout << p
            << "----------------------------------\nJust expiry date: "
            << p.expiry() << endl;
    }
}
void displayLinear(Perishable p) {
    if (p) {
        cout << "linear: ------------------------------------------------------------------------" << endl;
        p.linear(true);
        cout << p << endl;
        cout << "--------------------------------------------------------------------------------" << endl;
    }
}