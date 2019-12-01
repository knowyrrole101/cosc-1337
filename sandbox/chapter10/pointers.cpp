#include <iostream>
#include <iomanip>
#include <cstring>
#include <cctype>
#include <cstdio>

using namespace std;


void doubleValue(int *someNum);
void getSales(int *pointerArray, int arrSize);
int *squares(int n);

int main()
{
    // int myNumber;
    // char myLetter;
    // string myString;

    // myNumber = 20;
    // cout << "The value of myNumber before anything is: " << myNumber << endl;

    // cout << "Pointers Notes!!" << endl;
    // cout << long(&myNumber) << endl;

    // // Pointer 
    // int *ptr;
    // // stores int var in pointer variable.
    // ptr = &myNumber;

    // int *ptr2;
    // ptr2 = &myNumber;

    // myString = "Moon Ahmed";
    // string *ptr3;
    // ptr3 = &myString;

    // // To assign new value to pointer
    // cout << "The value of myNumber is " << myNumber << endl;
    // // This displays memory address of the INT myNumber
    // cout << "The value of myNumber is " << ptr << endl;
    // *ptr2 = 1000;
    // cout << "The memory address is still: " << ptr2 << endl;
    // cout << "After reassigning values via pointer myNumber is now: " << myNumber << endl;

    // // Pointer Strings
    // cout << "Pointer strings before dereference: " << myString << " and memory address: "<< ptr3 << endl;
    // *ptr3 = "Big Shot Barry!";
    // cout << "Pointer strings after new reference: " << myString << " and memory address: "<< ptr3 << endl;


    // // Pointers and Arrays
    // short numbersArray[] = {10,20,30,40,50};

    // cout << "The first element in the array is " << *numbersArray << endl;

    // // pointer notation
    // const int SIZE1 = 5;
    // int numbers[SIZE1];

    // cout << "Enter 5 numbers: ";
    // // Pointer notation use here
    // // Grab data
    // for(int count=0; count < SIZE1; count++)
    // {   
    //     // e.g numbers + count is like index or subscript.
    //     cin >> *(numbers+count);
    // } 
    // //Print Array using *pointer notation
    // for(int count=0; count < SIZE1; count++)
    // {   
    //     cout << *(numbers+count) << endl;
    // }


    //Pointers and subscripts
    const int NUM_COINS = 6;
    double coins[NUM_COINS] = {.01, .05, .10, .25, .50, 1.00};
    double *refCoins; // pointer to a double
    // Pointer reference to coins array
    refCoins = coins;

    cout << setprecision(2);
    for(int count=0; count<NUM_COINS; count++)
    {   
        cout << refCoins[count] << " subscript+pointer" << endl;
    }
    //Alternative syntax to print from pointer by storing array subscript into reference pointer.
    for(int count=0; count<NUM_COINS; count++)
    {
        refCoins = &coins[count];
        // Remember the * asterisk otherwise memory location will print instead.
        cout << *refCoins << endl;
    }

    // //Array names are pointer constants
    // int *arrPointer;
    // int myArrayofNums[] = {1,2,3,5,6,7};
    // // Reference array in pointer
    // arrPointer = myArrayofNums;
    
    int someRandomNum = 3;
    // Pointers as function params. Alternative to reference by param
    int *somePointer;
    *somePointer = someRandomNum;
    
    doubleValue(&someRandomNum);


    int sales[5];
    getSales(sales, 5);

    // Constant POINTERs. The pointer itself is a const
    int value = 100;
    int * const valuePointer = &value;
    cout << "Mem" << valuePointer << " ";
    cout << "Value" << *valuePointer << endl; 

    // Const pointers to constants
    int someBigTimeNumber = 10000;
    const int * const ptr = &someBigTimeNumber;

    // Dynamically allocated memory
    int *iptr = nullptr;
    // hor array of 100 integers dynamically allocated
    iptr = new int[100];
    for (int count=0;count<100;count++)
    {
        iptr[count] = 1;
    }
    // Print hte array
    for (int count=0;count<100;count++)
    {   
        cout << count << endl;
        cout << iptr[count] << endl;
    }

    // Delete the pointer to clean up
    // When you dont delete ptr after use you can create memory leak
    delete iptr;
    // Reassign as null pointer
    iptr = nullptr;

   return 0;
}

int *squares(int n)
{
    int *sqarray = new int[n];
    for (int k=0;k<n;k++)
    {
        sqarray[k] = (k+1) * (k+1);
    }
    return sqarray;
}

void doubleValue(int *someIntPointer)
{   
    cout << "HELLO WORLD!!!!!";
    cout << "Some random nums value: " << *someIntPointer << endl;
    cout << "Some random nums address: " << someIntPointer << endl;
}

void getSales(int *pointerArray, int arrSize)
{
    for(int count=0; count<arrSize; count++)
    {
        pointerArray[count] = count;
        cout << "Pointer array index " << pointerArray[count] << endl;
    }   
}

