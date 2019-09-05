#include <iostream>
#include <string>
#include <cmath>

using namespace std;

// Overflow is when the bits cannot fitinto specified type
// Doesnt return error but the type now holds incorrect memory.

int main() {
    short intVar = 32767;
    float floatVar = 3.0e-47;



    // Display intvar
    cout << "Original value of intvar " << intVar << endl;
    // Add to make it overflow;
    intVar = intVar + 1;
    cout << "Making it overflow " << intVar << endl;

    return 0;
};