#include <iostream>
#include <string>
// For formatting text with width, floating point precision.
#include <iomanip>

using namespace std;
// Function Prototype
void displayMessage(string message);
void acceptNumbers(int someNum);
int returnAValue(int someNum);
double getRadius();

int main() {
    displayMessage("This is the message passed in!");
    acceptNumbers(100);
    int someNum = returnAValue(12);
    cout << someNum << endl;
    double radius = getRadius();
    cout << "Radius: " << radius << endl;
    return 0;
};

void displayMessage(string message) {
    cout << "Hello world from displayMessage function!" << endl;
    cout << message << endl;
};

void acceptNumbers(int someNum){
    cout << "This is the number passed in: " << someNum << endl;
    someNum = someNum + 15;
    cout << "Now we adjusted someNum by 15 it is now " << someNum << endl;
};

int returnAValue(int someNum) {
    cout << "I am now returning your number + 2" << endl;
    return someNum + 2;
};

double getRadius(){
    const double PI = 3.1415;
    double radius = 2.45;
    return PI * radius;
};
