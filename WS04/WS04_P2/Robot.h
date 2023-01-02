/* ------------------------------------------------------
Workshop 4 part 2
Module: Robot
Filename: Robot.h
Version 1.1
Author: Devang Ramubhai Ahir Ahir
Revision History
-----------------------------------------------------------
Date          Reason
13/02/2022
-----------------------------------------------------------*/
#ifndef SDDS_ROBOT_H
#define SDDS_ROBOT_H

namespace sdds
{
    class Robot {
        char* Robot_Name;
        char* Robot_Location;
        double Robot_Weight;
        double Robot_Width;
        double Robot_Height;
        double Robot_Speed;
        bool Robot_Deployed;
    public:
        Robot();
        Robot(const char* name, const char* location, double weight,
            double width, double height, double speed, bool deployment);
        ~Robot();

        const Robot& set(const char* name, const char* location, double weight,
            double width, double height, double speed, bool deployment);
        void setLocation(const char* location);
        void setDeployed(bool deployed);

        const char* getName() const;
        const char* getLocation() const;
        bool isDeployed() const;
        bool isValid() const;
        double speed() const;
        void display() const;
    private:
        void resetInfo();
    };
    int conrtolRooomReport(const Robot robot[], int num_robots);
}

#endif