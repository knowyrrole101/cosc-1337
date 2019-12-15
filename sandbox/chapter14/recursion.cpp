#include <iostream>
#include <iomanip>
#include <cstring>
#include <cctype> // character testing
#include <cstdio>
#include <memory> // Smart Pointers 
#include <sstream> 
#include <string>

using namespace std;

void message(int howManyTimes);
int frequency(char character, string inputString, int position);
int factorial(int n);
int greatestCommonDivisot(int x, int y);

int main()
{
    message(5);

    char someChar = 'g';
    int freq = frequency(someChar, "glengarry", 0);
    cout << "The letter " << someChar << " appears " << freq << " times!" <<endl;

    int theFactorial = 5;
    int someNum = factorial(theFactorial);
    cout << "Factorial of " << theFactorial << " is " << someNum << endl;

    return 0;
}

void message(int howManyTimes){
    cout << "This is message in recursion #: " << howManyTimes << endl;
    if(howManyTimes > 0){
        message(--howManyTimes);
        // message(howManyTimes-1);
    }
}

int frequency(char character, string inputString, int position)
{
    if(position==inputString.length()){ //base case 
        return 0;
    }
    if(inputString[position] == character){
        return 1+frequency (character, inputString, position+1);
    }
    else{
        return frequency(character, inputString, position+1);
    }
}

int factorial(int n)
{
    if(n==0){ //base case
        return 1;
    } else {
        return n * factorial(n-1);
    }
}

//Euclids Algorithm
int greatestCommonDivisor(int x, int y)
{   
    // Y is divisor
    if(x % y==0){ //BASE CASE
        return y;
    } else {
        greatestCommonDivisor(y, x%y); 
    }
}

int fibonacci(int n)
{
    if(n<=0){
        return 0; // Base case
    } else if (n==1){ //Base case
        return 1;
    } else {
        fib(n-1) + fib(n-2);
    }
} 