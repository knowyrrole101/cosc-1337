#include <iostream>
#include <cmath>
#include <cstdlib>
#include <ctime>

using namespace std;

int main() {
    double a,b,c;

    // power of
    c = pow(10, 2.0);
    cout << c << endl;

    // #sqrt
    a = sqrt(16.0);
    cout << a << endl;

    // random numbers
    cout << rand() << " \n";
    // To get a stream of new random integers
    // Use srand

    unsigned seed;
    cout << "Get seed" << endl;
    cin >> seed;

    srand(seed);

    cout << rand() << endl;
    cout << rand() << endl;
    cout << rand() << endl;

    // Using time for seed
    unsigned new_seed;
    new_seed = time(0);
    srand(new_seed);
    cout << rand() << endl;
    cout << rand() << endl;
    cout << rand() << endl;

    // Range random number
    int number = rand() % max + 1;
    cout << number << endl;
}