/* ------------------------------------------------------
Workshop 5 part 1
Module: N/A
Filename: main.cpp
Version 1.1
Author: Devang Ramubhai Ahir Ahir
Revision History
-----------------------------------------------------------
Date          Reason
20/02/2022
-----------------------------------------------------------*/
#include <iostream>
#include "Portfolio.h"
using namespace std;
using namespace sdds;

void displayPortfolios(const Portfolio* Portfolios, int num) {

    cout << "+----------------------------------------------------------------+" << endl;
    for (int i = 0; i < num; i++) {

        Portfolios[i].display() << endl;
    }
    cout << "+----------------------------------------------------------------+" << endl;
}

int main() {
    double total;
    Portfolio Portfolios[] = {
       {300000, "Fitzer", 'F'},   // invalid
       {400000, "Fitzer", 'G'},
       {500000, "Honda", 'I'},
       {140000, "RIM", 'V'},
       {-500000, "Nortel", 'V'},  // invalid
       {95000, "Nvdia", 'G'},
    };

    displayPortfolios(Portfolios, 6);


    cout << " Total Investment in " << (const char*)(Portfolios[2]) << " and " << (const char*)(Portfolios[5]) << " is:  " << (total = Portfolios[2] + Portfolios[5]) << endl;

    cout << " Total Investment in " << (const char*)(Portfolios[1]) << " and " << (const char*)(Portfolios[3]) << " is:  " << double(Portfolios[1]) + double(Portfolios[3]) << endl;

    cout << "+----------------------------------------------------------------+" << endl;

    total = 0;
    total += Portfolios[1];
    total += Portfolios[5];
    cout << " Total Investment in " << (const char*)(Portfolios[1]) << " and " << (const char*)(Portfolios[5]) << " is:  " << total << endl;


    Portfolios[2] >> Portfolios[3];

    Portfolios[1] << Portfolios[5];

    displayPortfolios(Portfolios, 6);



    Portfolios[5] += 250005.50;
    Portfolios[4] -= 150000.50;

    displayPortfolios(Portfolios, 6);

    Portfolios[3] += 60000.50;
    Portfolios[1] -= 95000.00;


    displayPortfolios(Portfolios, 6);

    return 0;
}