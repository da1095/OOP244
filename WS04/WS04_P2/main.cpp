/* ------------------------------------------------------
Workshop 4 part 2
Module: N/A
Filename: main.cpp
Version 1.1
Author: Devang Ramubhai Ahir Ahir
Revision History
-----------------------------------------------------------
Initials   Date           Reason
F.S.	     13/02/2022     Added covered topics and simplifed.
-----------------------------------------------------------*/
#include <iostream>
#include "Robot.h"

using namespace std;
using namespace sdds;

int main()
{
	const int num_robots = 6;
	int broken_robot = 0;
	char replacmentName[] = "C3PO";
	Robot robot[num_robots] = {
		{},
		{"KC1", "kitchen", 25.33, 4.55, 2, 2.2, false},
		{"BR1", "bedroom", 5.22, 2.54, 1, 2.2, true},
		{"Broken", "Bedroom", 10.12, 2.5,1.55, 0, true},
		{"KC2", "kitchen", 20.56, 5, 2, 3.5, true},
		{"BR2", "bedroom", 25.32, 6.5, 2.5, 3.1, true}
	};

	while ((broken_robot = conrtolRooomReport(robot, num_robots)) >= 0) {
		cout << endl << "Attention: There is a broken robot! Fixing the problem..." << endl;
		robot[broken_robot].set(replacmentName, "Control Room", 10.0, 4, 1, 2.09, false).display();
		replacmentName[0]++;
		cout << "Replacement Provided!" << endl << endl;
	}

	return 0;
}