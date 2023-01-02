/* ------------------------------------------------------
Workshop 10 part 1 (Only the coding part)
Module: temps
Filename: temps.h
Version 1.1
Author: Devang Ramubhai Ahir Ahir
Revision History
-----------------------------------------------------------
Date          Reason
13/04/2022
-----------------------------------------------------------*/
#include <iostream>
#include "Collection.h"
#include "Car.h"
#include "Employee.h"
#include "Student.h"
#include "Collection.h"


namespace sdds {


    Collection<Employee> select(Employee emp[], int size, Employee& eq) {
        int l = 0, j = 0;

        for (int i = 0; i < size; ++i) if (emp[i] == eq) l++;

        Collection<Employee> newdata(l);

        for (int i = 0; i < size; ++i) if (emp[i] == eq) newdata[j++] = emp[i];

        return newdata;
    }

    Collection<Car> select(Car car[], int size, Car& eq) {

        int l = 0, j = 0;

        for (int i = 0; i < size; ++i) if (car[i] == eq) l++;

        Collection<Car> newdata(l);

        for (int i = 0; i < size; ++i) if (car[i] == eq) newdata[j++] = car[i];

        return newdata;
    }

    Collection<Student> select(Student stu[], int size, Student& eq) {
        int l = 0, j = 0;

        for (int i = 0; i < size; ++i) if (stu[i] == eq) l++;

        Collection<Student> newdata(l);

        for (int i = 0; i < size; ++i) if (stu[i] == eq) newdata[j++] = stu[i];

        return newdata;
    }


    Collection<int> select(int arr[], int size, int& eq) {

        int l = 0, j = 0;

        for (int i = 0; i < size; ++i) if (arr[i] == eq) l++;

        Collection<int> newdata(l);

        for (int i = 0; i < size; ++i) if (arr[i] == eq) newdata[j++] = arr[i];

        return newdata;

    }



    void printCollection(Collection<int>& col, const char* str) {

        std::cout << str << "\n";
        for (unsigned i = 0; i < col.size(); i++) { std::cout << col[i]; std::cout << "\n"; }

    }


    template <typename T>
    void printCollection(Collection<T>& col, const char* str) {

        std::cout << str << "\n";
        for (unsigned i = 0; i < col.size(); i++) { col[i].display(std::cout); std::cout << "\n"; }


    }






};
