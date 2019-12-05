#include <iostream>
#include <string>
#include <cmath>

using namespace std;

// Const must be initialized immediately 
int main () {
    
    const double INTEREST_RATE = 1.56;

    const double PI = 3.14159;
    double area, radius;

    cout << "THis program calculates the area of a circle. \n";

    // Get radius
    cout << "Need radius of circle!!? \n";
    cin >> radius;

    area = PI * pow(radius, 2);
    cout << "The area is " << area << endl;

    // Multipe combined assignment variables
    int a,b,c,d; 
    a = b = c = d = 12;

    int myNumber = 101;
    int newNumber = myNumber + 99;

    int begInv,
        sold,
        store1,
        store2;

    cout << "What was beginning inventory!!";
    cin >> begInv;
    
    store1 = store2 = begInv;
    cout << "how many items sold store 1";
    cin >> sold;

    store1 -= sold;
    
    cout << "how many items sold store 2";
    cin >> sold;

    store2 -= sold;

    cout << "Store 1" << store1 << "and Store 2" << store2 << endl;


    return 0;
}



