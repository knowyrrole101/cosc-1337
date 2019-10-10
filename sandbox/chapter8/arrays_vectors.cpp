#include <iostream> // Handle input/output 
#include <iomanip>  // I/O manupulator declarations
#include <string>   // string

using namespace std;

int main() {
    
    // Arrays and Vectors

    // Number is the array size declarator
    int hours[6];
    
    // Shorts use 2bytes so if array size is 6 then total bytes is 12
    short mini[6];

    // letter is 1 byte
    // short is 2 bytes
    // int is 4 bytes
    // float is 4 bytes
    // double is 8 bytes
    
    // subscript of array (or index)
    hours[1] = 16;
    cout << hours[1] << endl;

    int tenNumbers[5];
    // Array values cannot be copied like 
    // newArray = tenNumbers <-- Illegal
    // Array values must be entered one at a time.


    cout << "Enter five numbers!: ";
    cin >> tenNumbers[0];
    cin >> tenNumbers[1];
    cin >> tenNumbers[2];
    cin >> tenNumbers[3];
    cin >> tenNumbers[4];
    
    cout << tenNumbers[0] << endl;
    cout << tenNumbers[1] << endl;
    cout << tenNumbers[2] << endl;
    cout << tenNumbers[3] << endl;
    cout << tenNumbers[4] << endl;

    // USe a CONST to set array size as well.
    // const int BBC = 5;
    // BEST PRACTICE TO USE CONSTANT
    int moonsArray[5];
    int count;

    // DO NOT LOT AND PAST ARRAY BOUNDARIES
    // OTHER MEMORY CAN BE OVERWRITTEN OR CAN CAUSE COMPUTER TO CRASH!!!
    for(count=0;count<5;count++){
        cout << "Enter number to add to Moons Array" << endl;
        cin >> moonsArray[count];

        cout << "You added " << moonsArray[count] << " to the array" << endl;
    }

    // Second way to initialize array
    int const bigNum = 10;
    int myNewArray[bigNum] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

    string stringArray[bigNum] = {"January", "February", "March", "April" , "May", "June", "July", "August", "September", "October"};

    // Skipping index 0 and starting with 1
    string newArray[bigNum+1] = {"", "January", "February", "March", "April" , "May", "June", "July", "August", "September", "October"};

    for(count=1;count<bigNum+1;count++){
        cout << newArray[count] << endl;
    }

    // partial array initialization
    string bigFacts[10] = {"Big", "facts"};

    // Implicit Array Sizing
    string bigBalla[] = {"Big", "balla", "facts", "brodie"};

    //  New WAY TO INITIALIZE VARIABLES
    int bigNumba(15);

    cout << "This is bigNumba " << bigNumba << endl;

    // C++ 11 Only feature
    // Can use auto to autodetect data type
    // for (auto val : bigBalla)
    for (string val : bigBalla){
        cout << "Here is element in an array : " << val << endl;
    }

    // TO modify an existing array with range based loop
    for (string &val : bigBalla){
        cout << "Enter some new words son!!" ;
        cin >> val;
    }
    // Print new values again
    for (string val : bigBalla){
        cout << "Here is element in an array : " << val << endl;
    }

    // increment an arrays values
    int incrementArray[2];
    incrementArray[0] = 1;
    cout << incrementArray[0] << endl;
    incrementArray[0]++;
    cout << incrementArray[0] << endl;

    // Copying arrays. Must be done by using loop
    int someArray1[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int someArrayCopy[10];
    for(int index=0; index<10; index++){
        someArrayCopy[index] = someArray1[index];
        cout << someArrayCopy[index] << endl;
    }

    return 0;
}