#include <iostream>
#include <string>
#include <cmath>
// For formatting text with width, floating point precision.
#include <iomanip>

using namespace std;

int main() {

    int number;

    cout << "Enter an integer and I will tell you if its odd or even" << endl;
    cin >> number;

    if (number%2==0)
    {
        cout << "The number " << number << " is even \n" ;
    } else
    {
        cout << "The number " << number << " is odd \n";
    };
    
    // Comparing floats
    double result = 0.666667 * 6.0;

    // Must be precisely equal so this fails
    cout << "result = " << result << endl;
    if (result == 4.0)
        cout << "Result does equal 4" << endl;
    else
        cout << "Result does not equal 4" << endl;

    if(result - 4.0 < .0001)
        cout << "result does equal with ABSOLUTE VALUE" << endl;
    else
        cout << "result does not equal" << endl;
    
    const int MIN_A_SCORE = 90,
              MIN_B_SCORE = 80,
              MIN_C_SCORE = 70,
              MIN_D_SCORE = 60,
              MIN_POSSIBLE_SCORE = 0;

    int testScore;
    char grade;
    bool goodScore = true;

    cout << "Tell me test score and I will give you grade letter" << endl;
    cin >> testScore;

    if (testScore>=MIN_A_SCORE)
        grade = 'A';
    else if (testScore>=MIN_B_SCORE)
        grade = 'B';
    else if (testScore>=MIN_C_SCORE)
        grade = 'C';
    else if (testScore>=MIN_D_SCORE)
        grade = 'D';
    else if (testScore>=MIN_POSSIBLE_SCORE)
        grade = 'F';
    // This is called a trailing else
    else goodScore = false;

    if (goodScore)
        cout << "You grade is a " << grade << " !!" << endl;
    else
        cout << "The score cannot be below zero" << endl;
    

    return 0;
}