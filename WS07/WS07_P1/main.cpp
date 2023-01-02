/* ------------------------------------------------------
Workshop 7 part 1 (Only the coding part)
Module: N/A
Filename: main.cpp
Version 1.1
Author: Devang Ramubhai Ahir Ahir
Revision History
-----------------------------------------------------------
Date          Reason
17/03/2022
-----------------------------------------------------------*/
#include <iostream>
#include "Container.h"
#include "Pack.h"
using namespace std;
using namespace sdds;
void ContainerTest();
void PackTest();

int main() {
	ContainerTest();
	PackTest();
}

void PackTest() {
	Pack P("Pepsi", 24);
	Pack W("Tomato Paste", 10, 150, 12);
	cout << "Pack Tester........................." << endl;
	cout << P << endl;
	cout << "Added " << (P += 14) << " cans of " << P.unit() << " CCs" << endl;
	cout << P << endl;
	cout << "Added " << (P += 14) << " cans of " << P.unit() << " CCs" << endl;
	cout << P << endl;
	cout << "Removed " << (P -= 14) << " cans of " << P.unit() << " CCs" << endl;
	cout << P << endl;
	cout << "Removed " << (P -= 14) << " cans of " << P.unit() << " CCs" << endl;
	cout << endl << "Enter 14" << endl;
	cin >> P;
	cout << P << endl;
	cout << endl << "Enter 14 and then 10" << endl;
	cin >> P;
	cout << P << endl;
	cin >> P;
	cin >> W;
	W.clear(12, 750, "Wine");
	W += 5;
	cout << W << endl;
}
void ContainerTest() {
	Container Bad("Bad one!", 200, 300);
	Container C("Milk", 250);
	cout << "Container Tester........................." << endl;
	cout << C << endl;
	cout << Bad << endl;
	cout << "Adding " << (C += 200) << " CCs" << endl;
	cout << C << endl;
	cout << "Adding another " << (C += 200) << " CCs" << endl;
	cout << C << endl;
	cout << "Removing " << (C -= 200) << " CCs" << endl;
	cout << C << endl;
	cout << "Removing another " << (C -= 200) << " CCs" << endl;
	cout << C << endl;
	cout << endl << "Enter 222" << endl;
	cin >> C;
	cout << C << endl;
	cout << endl << "Enter 222" << endl;
	cin >> C;
	cout << C << endl;
	cin >> Bad;
	Bad.clear(200, "Water");
	Bad += 150;
	cout << Bad << endl;
}