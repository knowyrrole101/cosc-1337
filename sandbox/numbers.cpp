#include <iostream>
using namespace std;

int main() {
    // Dont need to include int unless declaring int.
    short int checking;
    unsigned int miles;
    long int diameter;

    checking = -20;
    miles = 4276;
    diameter = 100000;

    cout << "We have made a journey of " << miles << " miles. \n";
    cout << "Our checking account balance is $" << checking << " dollars. \n";
    cout << "The milky way galaxy is about " << diameter;
    cout << " lights years in diamter. \n";
    
    return 0;
}