#include <iostream>
#include <string>
#include <cmath>
// For formatting text with width, floating point precision.
#include <iomanip>

using namespace std;

int main() {

    // While loop
    bool bob = true;
    int counter = 0;
    cout << "Starting" << endl;

    // Basic counter while loop
    while (bob)
    {
        if (counter <= 10) {
            cout << "Hello world!" << endl;
            counter += 1;
        }
        else {
            break;
        }
    }
    // Other style while loop
    counter = 0;
    while (counter<=5) {
         cout << "Hello counter" << endl ; 
         cout << counter << endl;
         counter += 1;
    };

    int number;
    // While loop for input validation
    cout << "Enter a number in the range 1-100" << endl;
    cin >> number;

    while ((number<1)||(number>100)){
        cout << "Error enter a value between 1-100 ";
        cin >> number;
    }

    int bigNum = 50;
    while (bigNum>0){
        cout << "Big Num: " << bigNum <<endl;
        // Postfix decrementer
        bigNum -=1;
        // Prefix decrementer
        --bigNum;
    }
    
    int myNum1 = 5;
    // Postfix operator (happens before comparison)
    if (++myNum1 > 5){
        cout << "Greater than 5 "<< endl;
    }
    // Prefix operator (Happens after comparison)
    int myNum2 = 5;
    if (myNum2++ > 5) {
        cout << "Greater than 5" << endl;
    } else {
        cout << "Less than 5" << endl;
    }

    // For loops (and inner for loop)
    for(int snum=1; snum <= 5; snum++){
        cout << "hello world from outer loop!!" << endl;
        int numTests = 4; 
        for(int test=1; test<=numTests; test++){
            cout << "Inner Loop!!" << endl;
        };
    }
        
    //     for (int test=1; test <= numTests; test++) {
      //         int score; // Inititalize score
    //         double total = 0.0; // Initialize accumulator
    //         // Read a score and add to accumulator
    //         cout << "Enter a score " << test << "for " <;
    //         cout << "Student" << snum << ": ";
    //         cin >> score;
    //         total += score;
    //     };
    //     double average = total / numTests;
    //     cout << "The average score for student " << snum;
    //     cout << " is " << average << "\n\n";
    // };

    return 0;
}