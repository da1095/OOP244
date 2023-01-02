/* ------------------------------------------------------
Workshop 9 part 1 (Only the coding part)
Module: N/A
Filename: main.cpp
Version 1.1
Author: Devang Ramubhai Ahir Ahir
Revision History
-----------------------------------------------------------
Date          Reason
1/04/2022
-----------------------------------------------------------*/
#include <iostream>
#include <fstream>
#include "HtmlText.h"
#include "Text.h"
using namespace std;
using namespace sdds;
void show(Text T) {
    cout << "*" << T << "*" << endl;
}
void saveHtml(HtmlText H) {
    ofstream("dcwrLittle.html") << H;
}
void displayFile(const char* filename) {
    cout << "File: " << filename << endl;
    cout << "==================================================" << endl;
    ifstream fin(filename);
    char ch = 0;
    while (fin.get(ch)) {
        cout << ch;
    }
    cout << endl << "==================================================" << endl;
}
int main() {
    Text T;
    Text Y;
    Text Z;
    ifstream test("test.txt");
    ifstream dcwrLittle("dcwrLittle.txt");
    test >> T;
    dcwrLittle >> Y;
    Y = T;
    Z = Y;
    show(Y);
    HtmlText H1("Derived Classes and Resources");
    HtmlText H2;
    HtmlText H3;
    dcwrLittle.seekg(0);
    dcwrLittle >> H1;
    dcwrLittle.seekg(0);
    dcwrLittle >> H2;
    H2 = H1;
    H3 = H2;
    saveHtml(H3);
    displayFile("dcwrLittle.html");
    return 0;
}