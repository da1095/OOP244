/* ------------------------------------------------------
Milestone 3
Module: N/A
Filename: main.cpp
Version 1.1
Author: Devang Ramubhai Ahir Ahir
Revision History
-----------------------------------------------------------
Date          Reason
03/04/2022
-----------------------------------------------------------*/
#include <iostream>
#include <fstream>
#include "iProduct.h"
#include "Item.h"
using namespace std;
using namespace sdds;
void resetToOriginal();
void entryAndSave();
void descriptive();
void linear();
int main() {
    resetToOriginal();
    entryAndSave();
    cout << "------------------------" << endl;
    descriptive();
    cout << "------------------------" << endl;
    linear();
    cout << "------------------------" << endl;
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
    iProduct* p = new Item;
    cout << "Enter the following values: " << endl
        <<
        "abc\n"
        "1111\n"
        "44444\n"
        "Blanket\n"
        "abc\n"
        "222222\n"
        "22\n"
        "abc\n"
        "222\n"
        "2\n"
        "abc\n"
        "22222222\n"
        "22.22\n" << "------------------------" << endl;
    p->readSku(cin);
    cin >> *p;
    cout << "------------------------" << endl;
    cout << *p;
    cout << "------------------------" << endl;
    p->linear(true);
    cout << *p << endl;
    p->save(file) << endl;
    file.flush();
    file.close();
    delete p;
}
void descriptive() {
    ifstream file("data.dat");
    iProduct* p;
    p = new Item;
    while (p->load(file)) {
        cout << *p << endl;
    }
    delete p;
}
void linear() {
    ifstream file("data.dat");
    iProduct* p;
    p = new Item;
    while (p->load(file)) {
        if (*p == 44444) {
            p->linear(true);
            (*p) += 10;
            cout << "------------------------" << endl;
            cout << *p << endl;
            cout << "Need: " << p->qtyNeeded() << endl;
            cout << "Have: " << p->qty() << endl;
            cout.setf(ios::fixed);
            cout.precision(2);
            cout << "Price: " << double(*p) << endl;
        }
        if (*p == "kets") {
            p->linear(true);
            (*p) -= 5;
            cout << "------------------------" << endl;
            cout << *p << endl;
            cout << "Need: " << p->qtyNeeded() << endl;
            cout << "Have: " << p->qty() << endl;
            cout << "This object is in a " << (bool(*p) ? "good" : "bad") << " state!" << endl;
        }
    }
    delete p;
}
