/* ------------------------------------------------------
Workshop 4 part 2
Module: Robot
Filename: Robot.cpp
Version 1.1
Author: Devang Ramubhai Ahir Ahir
Revision History
-----------------------------------------------------------
Date          Reason
13/02/2022
-----------------------------------------------------------*/
#define _CRT_SECURE_NO_WARNINGS
#include <string.h>
#include <iomanip>
#include <iostream>

#include "Robot.h"

namespace sdds {
    void Robot::resetInfo() {
        Robot_Name = nullptr;
        Robot_Location = nullptr;
        Robot_Weight = 0.0;
        Robot_Width = 0.0;
        Robot_Height = 0.0;
        Robot_Speed = 0.0;
        Robot_Deployed = false;
    }

    Robot::Robot() {
        resetInfo();
    }

    Robot::Robot(const char* name, const char* location, double weight,
        double width, double height, double speed, bool deployment) {

        Robot_Name = new char[strlen(name) + 1];
        strcpy(Robot_Name, name);
        Robot_Location = new char[strlen(location) + 1];
        strcpy(Robot_Location, location);
        Robot_Weight = weight;
        Robot_Width = width;
        Robot_Height = height;
        Robot_Speed = speed;
        Robot_Deployed = deployment;
    }

    Robot::~Robot() {
        delete[] Robot_Name;
        delete[] Robot_Location;
    }

    const Robot& Robot::set(const char* name, const char* location, double weight,
        double width, double height, double speed, bool deployment) {

        // Free heap memory associated with current state of the object first.
        delete[] Robot_Name;
        Robot_Name = nullptr;
        delete[] Robot_Location;
        Robot_Location = nullptr;

        Robot_Name = new char[strlen(name) + 1];
        strcpy(Robot_Name, name);
        Robot_Location = new char[strlen(location) + 1];
        strcpy(Robot_Location, location);
        Robot_Weight = weight;
        Robot_Width = width;
        Robot_Height = height;
        Robot_Speed = speed;
        Robot_Deployed = deployment;

        return *this;
    }

    void Robot::setLocation(const char* location) {
        delete[] Robot_Location;
        Robot_Location = nullptr;

        Robot_Location = new char[strlen(location) + 1];
        strcpy(Robot_Location, location);
    }

    void Robot::setDeployed(bool deployed) {
        Robot_Deployed = deployed;
    }

    const char* Robot::getName() const {
        return Robot_Name;
    }

    const char* Robot::getLocation() const {
        return Robot_Location;
    }

    bool Robot::isDeployed() const {
        return Robot_Deployed;
    }

    bool Robot::isValid() const {
        return Robot_Name && Robot_Location && Robot_Weight > 0 && Robot_Width > 0
            && Robot_Height > 0 && Robot_Speed > 0;
    }

    double Robot::speed() const {
        return Robot_Speed;
    }

    void Robot::display() const {
        std::cout << "| " << std::left << std::setw(10) << Robot_Name << " | "
            << std::left << std::setw(15) << Robot_Location << " | "
            << std::right << std::setw(6) << std::fixed << std::setprecision(1) << Robot_Weight << " | "
            << std::right << std::setw(6) << std::fixed << std::setprecision(1) << Robot_Width << " | "
            << std::right << std::setw(6) << std::fixed << std::setprecision(1) << Robot_Height << " | "
            << std::right << std::setw(6) << std::fixed << std::setprecision(1) << Robot_Speed << " | "
            << std::left << std::setw(8) << (Robot_Deployed ? "YES" : "NO") << " |" << std::endl;
    }

    int conrtolRooomReport(const Robot robot[], int num_robots) {
        std::cout << "                        ------ Robot Control Room -----\n"
            << "                    ---------------------------------------\n"
            << "| Robot ID   | Location        | Weight |  Width | Height |  Speed | Deployed |\n"
            << "|------------+-----------------+--------+--------+--------+--------+----------|\n";

        int Robot_Deployed = 0;
        double Fastest_Speed = 0;
        int Index_Fasted_Speed = -1;

        for (int i = 0; i < num_robots; i++) {
            if (robot[i].isValid()) {
                robot[i].display();

                if (robot[i].isDeployed()) {
                    Robot_Deployed++;
                }
                if (robot[i].speed() > Fastest_Speed) {
                    Fastest_Speed = robot[i].speed();
                    Index_Fasted_Speed = i;
                }
            }
            else {
                return i;   // Return index of the invalid robot.
            }
        }

        std::cout << "|=============================================================================|\n"
            << "| SUMMARY:                                                                    |\n";
        std::cout << "| " << std::left << std::setw(75) << (std::to_string(Robot_Deployed) + "  robots are deployed.") << " |" << std::endl;
        std::cout << "| " << std::left << std::setw(75) << "The fastest robot is:" << " |" << std::endl;
        std::cout << "| Robot ID   | Location        | Weight |  Width | Height |  Speed | Deployed |\n"
            << "|------------+-----------------+--------+--------+--------+--------+----------|\n";
        robot[Index_Fasted_Speed].display();
        std::cout << "|=============================================================================|" << std::endl;

        return -1;
    }
}