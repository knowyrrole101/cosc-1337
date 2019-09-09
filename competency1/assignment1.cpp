//******************************************************************
// Integer Storage program
// Programmer: Mamun Ahmed
// Completed : 09/07/2019
// Status    : Completed
//
// This program reads in user values and calculates values based off
// them. Including sum, product, integer quotient, integer remainder,
// floating-point quotient, floating-point division
//******************************************************************

#include <iostream>      // input/output declarations
#include <iomanip>       // i/o manupulator declarations
using namespace std;     

int main() {

    // Integer Variables where user input to be stored.
    int firstNum, secondNum;

    // User input to store two integers
    cout << "Please enter first integer: ";
    cin >> firstNum;
    cout << endl;
    cout << "Please enter second integer: ";
    cin >> secondNum;
    cout << endl;

    // Confirmation that user input was stored properly.
    cout << "First number is " << firstNum << endl;
    cout << endl;
    cout << "Second Number is " << secondNum << endl;
    cout << endl;

    // Integer Variables storing all integer calculations
    int sum = firstNum + secondNum,
        product = firstNum * secondNum,
        integer_quotient = (firstNum/secondNum),
        integer_remainder = (firstNum%secondNum);
    
    // Integer Variables storing all floating point calculations
    float floating_point_quotient = (float) firstNum / (float) secondNum,
          average = ((float) firstNum + (float) secondNum) / 2;


    // Output of all variables
    cout << "Sum" << setw(40) << "is " << sum << endl;  
    cout << endl;
    cout << "Product" << setw(36) << "is " << product << endl;  
    cout << endl;
    cout << "Integer Quotient" << setw(27) << "is " << integer_quotient << endl;  
    cout << endl;
    cout << "Integer Remainder" << setw(26) << "is " << integer_quotient << endl;  
    cout << endl;
    cout << "Floating-point quotient" << setw(20) << "is " << floating_point_quotient << endl;  
    cout << endl;
    cout << "Average" << setw(36) << "is " << average << endl;  
    cout << endl;

    // End of program
    return 0;
};
