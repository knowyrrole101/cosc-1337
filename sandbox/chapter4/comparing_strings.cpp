#include <iostream>
#include <iomanip>
#include <cstring>
#include <cctype>
#include <cstdio>

using namespace std;

int main() {
    const double PRICE_A = 249.0,
                 PRICE_B = 199.0;

    string partNum;

    // Display available items and get the user's selection
    cout << "The headphone item number are \n";

    // Character testing functions
    // Return True if:
    // isalpha() - If letter of the alphabet
    // isalnum() - If letter or digit
    // isdigit() - If argument is a digit 0 -9
    // islower() - lowercase letter 
    // isprint() - retursn true if printable char including a space
    // ispunct() - return true if argument is a printable char other than letter, digit, or space
    // isupper() - if upper
    // isspace() - is a whitespace

    int x,y,z;
    x = 2;

    // Conditional operator
    x < 0 ? y = 10 : z = 20;
    cout << y << endl;
    cout << z << endl;

    const double PAY_RATE = 50.0;
    const int MIN_HOURS = 5;
    double hours, charges;

    cout << "How many hours were worked? ";
    cin >> hours;

    hours = hours < MIN_HOURS ? MIN_HOURS : hours; 

    charges = PAY_RATE * hours;
    
         << "The charges are $" << charges << endl;
    
    char choice; 

    cout << "Enter a choice A, B, or C ";
    cin >> choice;

    choice = toupper(choice);

    // Switch statements
    switch (choice)
    {
        case 'A': cout << "You entered A!\n";
                  break;
        case 'B': cout << "You entered B!\n";
                  break;
        case 'C': cout << "You entered C!\n";
                  break;
        default: cout << "You did not enter A, B, or C!]\n";
    }
      
    return 0;
}