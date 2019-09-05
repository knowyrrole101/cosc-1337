#include <iostream>
#include <string>
#include <cmath>

using namespace std;
   int books,
        months;
    double booksPerMonth;

    cout << "How "
int main() {

    int length, width, area;

    cout << "This program calculates the area of a rectanlge" << endl;
    
    //  Have the user input the rectangle's length and width
    cout << "What is length of the rectangle?" << endl;
    cin >> length;
    cout << "What is the width of the rectangle?" << endl;
    cin >> width;
    // Compute and display the area


    cin >> width >> length;
    area = length * width;
    cout << "The area of the rectangle is " << area << endl;

    int whole;
    double fractional;
    char letter;

    cout << "Enter a integer, double and character" << endl;
    cin >> whole >> fractional >> letter;

    cout << "Whole: " << whole << endl;
    cout << "Fractional: " << fractional << endl;
    cout << "Letter: " << letter << endl;

    double numerator, denominator;

    cout << "This program shows the decimal value of a franction. \n" << endl;

    // Have the user enter the user numerator and denominator
    cout << "Enter the numerator: ";
    cin >> numerator;
    cout << "Ente the denominator: ";
    cin >> denominator;

    cout << "The decimal value is: " << (numerator/denominator) << endl;
    
    int x,y;

    // y = x/2*3;
    // cout << y << endl;

    // Pow expect floating point arguments.
    area = pow(4.0, 2);
    cout << area << endl;

    //  Data type casting rank
    // long double
    // double
        // float 
        // unsigned long long int
        // long long int
        // unsigned long int
        // long int
        // unsigned int
        // int


    return 0;
}