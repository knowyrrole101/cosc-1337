//******************************************************************
// Robot Class Header File
// Programmer: Mamun Ahmed
//******************************************************************

#ifndef ROBOT_H // Define Robot Class if it does not exist
#define ROBOT_H 

using namespace std;

class Robot
{
    // Private member variables
    private:   
        static const double PI; // Constant Value for PI
        double rpm; // Revolutions per Second
        double diameter; // Diameter of Wheel
    
    // Public Member Variables and Function Prototypes
    public: // Function Prototypes for ROBOT Class.        
        Robot(){  // Object Initializer 
            rpm = 74; // Default RPM set to 74
            diameter = 1;  // Default Diameter set to 1 inch.
            cout << "Initializing ROBOT!" << endl;
        };

        // Class Member Function Prototypes
        void setRPM(double newRPM); // setter function to set RPM
        void setDiameter(double newDiameter); // setter function to set Diameter
        double getRPM(); // getter function to grab rpm variable
        double getDiameter(); // getter function that grabs existing diameter variable
        double getSpeed(); // getter function that returns a calculation of rpm & diameter
};
#endif