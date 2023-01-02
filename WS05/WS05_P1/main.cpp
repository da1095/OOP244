/* ------------------------------------------------------
Workshop 5 part 1
Module: N/A
Filename: main.cpp
Version 1.1
Author: Devang Ramubhai Ahir Ahir
Revision History
-----------------------------------------------------------
Date          Reason
17/02/2022
-----------------------------------------------------------*/
#include <iostream>
#include "Flight.h"
using namespace std;
using namespace sdds;

void displayFlights(const Flight* flights, int num) {
    cout << "+------------------------------------------------------------------------------+" << endl;
    for (int i = 0; i < num; i++) {
        flights[i].display() << endl;
    }
    cout << "+------------------------------------------------------------------------------+" << endl;
}

int main() {
    int total;
    Flight flights[] = {
       {200, 300000, "BA 504"},   // invalid
       {100, 65000, "MD 432"},
       {300, 195000, "CAD 453"},
       {150,97500 , "IND 678"},
       {70, 45500, "FRN 435"},
       {-500, 5000, "SA 435"},  // invalid
       {270, 17550, "ZAA 500"}  // invalid
    };

    displayFlights(flights, 7);


    cout << " Total passengers in " << (const char*)(flights[2]) << " and " << (const char*)(flights[4]) << " is:  " << (total = flights[2] + flights[4]) << endl;

    cout << " Total fuel in " << (const char*)(flights[2]) << " and " << (const char*)(flights[4]) << " is:  " << double(flights[2]) + double(flights[4]) << endl;

    cout << "+------------------------------------------------------------------------------+" << endl;

    total = 0;
    total += flights[1];
    total += flights[3];
    cout << " Total passengers in " << (const char*)(flights[1]) << " and " << (const char*)(flights[3]) << " is:  " << total << endl;
    cout << " Total fuel in " << (const char*)(flights[1]) << " and " << (const char*)(flights[3]) << " is:  " << double(flights[1]) + double(flights[3]) << endl;

    cout << "+------------------------------------------------------------------------------+" << endl;

    cout << " Total passengers in " << (const char*)(flights[1]) << " is:  " << int(flights[1]) << endl;
    cout << " Total passengers in " << (const char*)(flights[2]) << " is:  " << int(flights[2]) << endl;
    cout << " Total passengers in " << (const char*)(flights[3]) << " is:  " << int(flights[3]) << endl;
    cout << " Total passengers in " << (const char*)(flights[4]) << " is:  " << int(flights[4]) << endl;

    cout << "+------------------------------------------------------------------------------+" << endl;

    flights[5] = flights[1];

    flights[2] >> flights[3];



    displayFlights(flights, 7);



    flights[6] += 160000.50;
    flights[4] -= 15000.50;

    flights[2] += 200;
    flights[3] -= 300;

    displayFlights(flights, 7);

    flights[0] = 300;

    flights[4] = 200000.50;

    displayFlights(flights, 7);

    return 0;
}