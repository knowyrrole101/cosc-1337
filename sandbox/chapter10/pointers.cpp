#include <iostream>
#include <iomanip>
#include <cstring>
#include <cctype>
#include <cstdio>

using namespace std;

int main()
{
    int myNumber;
    char myLetter;
    string myString;

    myNumber = 20;
    cout << "The value of myNumber before anything is: " << myNumber << endl;

    cout << "Pointers Notes!!" << endl;
    cout << long(&myNumber) << endl;

    // Pointer 
    int *ptr;
    // stores int var in pointer variable.
    ptr = &myNumber;

    int *ptr2;
    ptr2 = &myNumber;

    myString = "Moon Ahmed";
    string *ptr3;
    ptr3 = &myString;

    // To assign new value to pointer
    cout << "The value of myNumber is " << myNumber << endl;
    // This displays memory address of the INT myNumber
    cout << "The value of myNumber is " << ptr << endl;
    *ptr2 = 1000;
    cout << "The memory address is still: " << ptr2 << endl;
    cout << "After reassigning values via pointer myNumber is now: " << myNumber << endl;

    // Pointer Strings
    cout << "Pointer strings before dereference: " << myString << " and memory address: "<< ptr3 << endl;
    *ptr3 = "Big Shot Barry!";
    cout << "Pointer strings after new reference: " << myString << " and memory address: "<< ptr3 << endl;


    // Pointers and Arrays
    short numbersArray[] = {10,20,30,40,50};

    cout << "The first element in the array is " << *numbersArray << endl;

    // pointer notation
    const int SIZE1 = 5;
    int numbers[SIZE1];

    cout << "Enter 5 numbers: ";
    // Pointer notation use here
    // Grab data
    for(int count=0; count < SIZE1; count++)
    {   
        // e.g numbers + count is like index or subscript.
        cin >> *(numbers+count);
    } 
    //Print Array using *pointer notation
    for(int count=0; count < SIZE1; count++)
    {   
        cout << *(numbers+count) << endl;
    }


    //Pointers and subscripts
    const int NUM_COINS = 6;
    double coins[NUM_COINS] = {.01, 05, .10, .25, .50, 1.00};
    double *refCoins; // pointer to a double

    refCoins = coins;

    cout << setprecision(2);
    for(int count=0; count<NUM_COINS; count++)
    {   
        cout << refCoins[count] << " subscript+pointer" << endl;
    }
    // Alternative syntax to print from pointer by storing array subscript into reference pointer.
    for(int count=0; count<NUM_COINS; count++)
    {
        refCoins = &coins[count];
        // Remember the * asterisk otherwise memory location will print instead.
        cout << *refCoins << endl;
    }

    // End Main
    return 0;
}