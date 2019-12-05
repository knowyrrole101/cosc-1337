//******************************************************************
// Robot Speed Estimator - Class Objects - Assignment 4
// Programmer: Mamun Ahmed
// Completed : 09/28/2019
// Status    : Completed
//
// Program that creates a robot class. The class Spec file is 
// stored in robot.h header file and robot.cpp stores the class
// implementation. The main program then creates the class
// and allows the end user to add specific variables to calculate
// speed and store diameter, and rpms.
//******************************************************************

#include <iostream> // Handle input/output 
#include <iomanip>  // I/O manupulator declarations
#include <string>   // string
#include "robot.cpp"

using namespace std;

int main() {
    // Initialize and Create the Robot Class Object
    Robot moonsRobot;
    // Print Default RPM and Diameter values
    cout << "Default RPM: " << moonsRobot.getRPM() << " and the Default Diameter: " 
         << moonsRobot.getDiameter() << endl;   
    // Invalid Value Passed to SetRPM
    moonsRobot.setRPM(65);
    // Getter Function and Output Print
    cout << "Invalid RPM Not Showing (Using Default): " << moonsRobot.getRPM() << endl;  
    // Valid Value Passed to SetRPM
    moonsRobot.setRPM(190); 
    cout << "New Valid RPM: " << moonsRobot.getRPM() << endl;
    // Invalid Value Passed to setDiameter
    moonsRobot.setDiameter(12);
    cout << "Invalid Diameter Not Showing (Using Default): " << moonsRobot.getDiameter() << endl;
    moonsRobot.setDiameter(3);
    cout << "New Valid Diameter: " << moonsRobot.getDiameter() << endl;
    // Set Decimal Precision to 2 for Console Output
    cout << fixed << showpoint << setprecision(2);
    // Calculate speed from valid RPM and Diameter passed in of 190 and 3.
    cout << "The speed in feet calculated is: " << moonsRobot.getSpeed() << endl;
    return 0;
};