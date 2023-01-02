/* ------------------------------------------------------
Workshop 10 part 1 (Only the coding part)
Module: N/A
Filename: main.cpp
Version 1.1
Author: Devang Ramubhai Ahir Ahir
Revision History
-----------------------------------------------------------
Date          Reason
13/04/2022
-----------------------------------------------------------*/

#include <iostream>
#include "Car.h"
#include "Employee.h"
#include "Student.h"
#include "Collection.h"
#include "temps.h"
using namespace std;
using namespace sdds;

int main() {

    Student S[7] = { { 22345, "Lisa Simpson", "EAC150"}, {12345, "Bart Simpson", "EAC150"},
                      { 24567, "Ralph Wiggum", "IPC144"}, {56789, "Milhouse Van Houten","IPC144"},
                      { 67890, "Todd Flanders", "BTP200"}, {34567, "Nelson Muntz", "BTP200"},{33223, "Magie Simpson", "EAC150"} };
    Employee E[6] = { Employee(213456, "Carl Carlson", 1000), Employee(122345, "Mindy Simmons", 2000),
                      Employee(435678, "Lenny Leonard", 1000), Employee(546789, "Waylon Smithers", 3000),
                      Employee(657890, "Frank Grimes", 3000), Employee(364567, "Homer Simpson", 1000) };
    Car C[7] = { Car("GVBT01", "Tesla","Model S"), Car("BBCDEF", "BMW","320"),
                 Car("CDEFG", "Ford","Festiva"),Car("GVAB24", "Tesla","Cyber Truck"), Car("BCDEFG", "Ford","Explorer"),
                 Car("AFGHIJ", "Nissan","Maxima"),Car("GVDD99", "Tesla","Model 3") };
    int vals[10] = { 4, 6, 4,  67, 4, 6, 7, 5, 4, 6 };


    Collection<Car> teslas = select(C, 7, C[0]);
    Collection<Student> classmates = select(S, 7, S[0]);
    Collection<Employee> colleagues = select(E, 6, E[0]);
    Collection<int> numbers = select(vals, 10, vals[0]);


    printCollection(teslas, "Tesla Cars:");
    printCollection(classmates, "Classmates:");
    printCollection(colleagues, "Colleagues:");
    printCollection(numbers, "Fours:");
    return 0;
}

/*
Tesla Cars:
GVBT01 Tesla Model S
GVAB24 Tesla Cyber Truck
GVDD99 Tesla Model 3
Classmates:
22345, Lisa Simpson, EAC150
12345, Bart Simpson, EAC150
33223, Magie Simpson, EAC150
Colleagues:
213456, Carl Carlson, 1000
435678, Lenny Leonard, 1000
364567, Homer Simpson, 1000
Fours:
4
4
4
4
*/