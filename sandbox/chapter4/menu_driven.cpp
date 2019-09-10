#include <iostream>
#include <string>
#include <cmath>
// For formatting text with width, floating point precision.
#include <iomanip>
using namespace std;

int main() {

    // Constant RATES
    const double ADULT_RATE = 120.0;
    const double CHILD_RATE = 60.0;
    const double SENIOR_RATE = 100.0;

    int choice; // Menu choice
    int months; // Number of months
    double charges; // Monthly charges

    // Display the menu and get the users choices:
    cout << "    Health Club Membership \n\n";
    cout << "1. Standard Adult Membership \n";
    cout << "2. Child Membership \n";
    cout << "3. Senior Citizen Membership \n";
    cout << "4. Quit Program \n";
    cout << "Enter your choice: ";
    cin >> choice;

    // Set the numeric output formatting
    cout << fixed << showpoint << setprecision(2);

    if (choice == 1)
    {
        cout << "For how many months: ";
        cin >> months;
        charges = months * ADULT_RATE;
        cout << "\nThe total charges are $ " << charges << endl;
    }
    else if (choice==2)
    {
        cout << "For how many months: ";
        cin >> months;
        charges = months * CHILD_RATE;
        cout << "\nTHe total charges are $ " << charges << endl;
    }
    else if (choice==3)
    {
        cout << "For how many months: ";
        cin >> months;
        charges = months * SENIOR_RATE;
        cout << "\nTHe total charges are $ " << charges << endl;
    }
    else if (choice !=4)
    {
        cout << "\n The valid choices are 1 through 4 \n";
        cout << "Run the program again and select one of those\n";
    }
    return 0;
};