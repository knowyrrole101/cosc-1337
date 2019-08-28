#include <iostream>
using namespace std;

int main(){
    double hours, rate, pay;
    
    // Get Hours Worked
    cout << "How many hours did you work?";
    cin >> hours;

    // Get the hourly pay rate
    cout << "How much did you get paid per hour";
    cin >> rate;

    //Calculate the pay
    pay = hours * rate;

    // Display the pay
    cout << "You have earned $" << pay << endl;
    return 0;

}