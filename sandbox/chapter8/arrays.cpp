#include <iostream> // Handle input/output 
#include <iomanip>  // I/O manupulator declarations
#include <string>   // string

using namespace std;


typedef int arrayType[];
// Function Prototype
// void showValue(int intArray[], int arraySize);
void showValue(arrayType someArray, int size);

const int NUM_ROWS = 3;
const int NUM_COLS = 2;
void passMultiOver(int [][NUM_COLS], int NUM_ROWS);

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

    // Comparing Arrays
    const int SIZE = 5;
    int arrayA[SIZE] = {3, 2, 1, 5, 4};
    int arrayB[SIZE] = {1, 2, 3, 2, 5};
    bool arraysAreEqual = true;
    int loop = 0; // Flag Variable

    while(arraysAreEqual && loop < SIZE)
    {
        if(arrayA[count] != arrayB[count])
        {
            arraysAreEqual = false;
        }
        count++;
        if (!arraysAreEqual)
        {
            cout << "The arrays dont match!" << endl;
            break;
        }
    }
    if (arraysAreEqual)
    {
        cout << "arrays do match!" << endl;
    }

    int lowest, highest;
    
    // Get Initial highest/lowest value in array
    lowest = arrayA[0];
    highest = arrayA[4];

    for(int count=0; count < SIZE; count++)
    {   
        cout << arrayA[count];
        
        if(lowest > arrayA[count])
        {
            lowest = arrayA[count];
        } 
        if(highest < arrayA[count])
        {
            highest = arrayA[count];
        }
    }
    cout << "Biggest Number in array is " << highest << endl;
    cout << "Lowest Number in array is " << lowest << endl;

    // Strings are stored as arrays
    string myName = "Moon Ahmed";
    cout << myName[0] << endl;

    // Parallel Arrays have same index position. 
    // Usually for related data.
    int days[3] = {1, 2, 3};
    double hoursArray[3] = {1.23, 3.24, 4.55};

    for(int count=0; count<3; count++)
    {
        cout << "The days: " << days[count] << endl;
        cout << "The hours associated: " << hoursArray[count] << endl;
    }

    // Create Typedef - Type Definitions
    typedef int examScore;
    examScore score1,score2;

    // typedef for arrays
    typedef int arrayType[];
    const int BIGSIZE = 5;
    arrayType bigTymeArray = {1,2,3,4,5};

    // Array as function argument
    
    showValue(bigTymeArray, BIGSIZE);
    
    // Can use const int[] to ensure array passed into loop is not modified. 

    // Multidimensional arrays
    const int NUM_BIG_DIV = 5;
    const int NUM_NOT_DIV = 4;
    int sales[NUM_BIG_DIV][NUM_NOT_DIV];

    for(int count=0; count < NUM_BIG_DIV; count++)
    {
        cout << "Hello from outer loop!" << endl;
        for(int second_count=0; second_count < NUM_NOT_DIV; second_count++)
        {
            cout << "Hello from inner loop!" << endl;
        }
        // cout << multiDimensionalArray[count] << endl;
    }
  
    int myMultiDimensionalArray[NUM_ROWS][NUM_COLS] = {{1,2},{1,2},{1,2}};

    passMultiOver(myMultiDimensionalArray, NUM_ROWS);

    return 0;
}

// void showValue(int intArray[], int arraySize)
void showValue(arrayType someArray, int size)
{
    for(int count=0; count < size; count++)
    {
        cout << "This is arrayType printing: " << someArray[count] << endl;
    }
}



void passMultiOver(int array [][NUM_COLS], int NUM_ROWS)
{
    for(int row=0; row < NUM_ROWS; row++)
    {
       for (int col=0; col < NUM_COLS; col++)
       {
           cout << "printing element " << row << "of" << array[row][col] << endl;
       }
    }
}