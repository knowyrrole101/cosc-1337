CHAPTER 6 REVIEW QUESTIONS

1. Write a possible prototype for function func( ) below.

int main()
{
   double d;
   float f = 6.2;
   int i = 3;
   d = func( i, f );
   cout << "The result is " << d << endl;
   return 0;
}
2. Write an example call for the following function.

float square( float num)
{
   return num * num;
}
3. True or False: To use a constant variable throughout your program, it should be declared inside your main() function.

4. Write a function that receives a float parameter called num and calculates and returns the fourth power of num (num * num * num * num). Try using a local variable in your function.

5. Write a function that prints the sentence:

Your age is ___ years.

In the blank space in the sentence it should print the value of an integer parameter called age.

6. Write a function that prompts the user to enter a number of hours worked and a pay rate. Your function should then input two values into float parameters called hoursWorked and payRate. Your function will need to supply the two input values to the calling function.

7. The following program will not compile. Find the problem and fix it.

#include <iostream.h>

void PrintCurved( int grade );

int main()
{
   int studentNo, grade;
   cout << "Enter student number and grade:";
   cin >> studentNo >> grade;
   PrintCurved(grade);
   return 0;
}

void PrintCurved( int grade )
{
   cout << "The curved grade for student ";
        << studentNo << " is " 
        << grade + 10 << endl;
}
8. Write a function that receives two float values as parameters and "returns" each value halved. Write an example call for your function. Write declarations for all variables that you use.

9. Write an overloaded version of your function in the previous problem that works on int values.

10. Write a statement that causes all floating point numbers to be printed with exactly 1 place to the right of the decimal point.