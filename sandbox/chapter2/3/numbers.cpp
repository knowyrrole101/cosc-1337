// Needed for cin and cout
#include <iostream>
// Not technically needed. file still compiles.
#include <string>

using namespace std;

int main() {
    // Dont need to include int unless declaring int.
    short int checking;
    unsigned int miles;
    long int diameter;

    checking = -20;
    miles = 4276;
    diameter = 100000;

    // Integer
    int intvar;
    // Double precision f
    double doubleVar = 7.8;
    intvar = doubleVar;

    cout << "We have made a journey of " << miles << " miles. \n";
    cout << "Our checking account balance is $" << checking << " dollars. \n";
    cout << "The milky way galaxy is about " << diameter;
    cout << " lights years in diamter. \n";
    cout << "Floating point now as int: " << intvar << endl;

    // characters - CHAR used to store individual characters
    char letterA = 'A';
    char letterB = 'B';
    cout << letterA << " " << letterB << endl;

    char letterAscii = 66;
    cout << "This is ascii representation of capital letter B: " << letterAscii << endl;

    string bigShotBob;
    bigShotBob = "Moon Ahmed";

    cout << bigShotBob << endl;

    // bool data type. Booleans are shown as 0 or 1.
    bool isGood; 
    isGood = false;

    cout << isGood << endl;

    // sizeof
    cout << "The size of a short integer is " << sizeof(short) << "\n";
    cout << "The size of a short integer is " << sizeof(isGood) << endl;
    cout << "The size of a short integer is " << sizeof(int) << endl;

    // Initialized and assigned Feb value.
    string month = "February";
    // Not initialized
    int year,
    // initialized
    days = 29;
    // now year initialized
    year = 1776;

    // Auto determines data type of variable
    auto moonAhmed = "Moon Ahmed";
    
    // Arithmetic 
    double myDivisionFloat = 5 / 2;
    int total = 4 + 8;
    int leftOver = 26 % 3;

    // cout == console output object
    cout << "Modolus?? " << leftOver << "\n";
    /*
        Multi line comments
        in C++
    */

    // cin == console input object



    return 0;
}