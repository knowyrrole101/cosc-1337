//******************************************************************
// Robot Class Implementation File
// Programmer: Mamun Ahmed
//******************************************************************

#include "robot.h" // Include Robot Class Header File

using namespace std;

// Private Constant Member Variable PI
const double Robot::PI = 3.14159;

// Setter Function To Set New RPM Value
void Robot::setRPM(double newRPM) 
{  
    if (newRPM == 74 || newRPM == 190 || newRPM == 265)
    {
        cout << "Setting New RPM" << endl;
        rpm = newRPM;
    }
}

// Setter Function To Set New Diameter Value
void Robot::setDiameter(double newDiameter)
{   
    if (newDiameter >= 1 && newDiameter <=6)
    {
        cout << "Setting New Diameter" << endl;
        diameter = newDiameter;
    }
}

// Getter Function that returns RPM
double Robot::getRPM()
{
    return rpm;
}

// Getter Function that returns Diameter
double Robot::getDiameter()
{
    return diameter;
}

// Getter Function that returns Speed
// Function must calculate and return new value for speed per foot.
double Robot::getSpeed()
{   
    double speedPerInchesPerMinute; // Function variable to store calculation
    speedPerInchesPerMinute = PI * rpm * diameter; // Speed Calculation
    return (PI * rpm * diameter)/12; // Return Speed Calculation by Feet
}