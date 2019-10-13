CHAPTER 6

Other Questions

1. Write a possible prototype for function Func() below.

int main()
{
   double d;
   float f = 6.2;
   int i = 3;
   d = func( i, f );
   cout << "The result is " << d << endl;
   return 0;
}
The call to function func( ) above has an int argument followed by a float argument. The return value is assigned to a double variable. We can use these types to construct a possible prototype:

double func( int i, float f );
2. Write an example call for the following function.

float square( float num)
{
   return num * num;
}
Value-returning functions are called in expressions. For example, in assignment statements:

variable = expression; 
or output statements:

cout << expression; 
or in conditions:

if (boolean expression) 
   true statement 
else 
   false statement 
Some example calls are:

x = square(3.0);
cout << square(4.1) << endl;
if (square(x) < 6)
   cout << "Too small" << endl;
3. True or False: To use a constant variable throughout your program, it should be declared inside your main() function.

False. A variable or constant declared inside a function can only be used inside that function. More generally, anything declared inside a function is local to that function and cannot be accessed outside the function. To use a constant throughout the program, it must be declared outside of any function, and before the first function (usually main()). More generally, anything declared outside any function has global (or external) scope and can be accessed from the point of its declaration to the end of the file containing the program.

4. Write a function that receives a float parameter called num and calculates and returns the fourth power of num (num * num * num * num). Try using a local variable in your function.

float fourth( float num)
{
   float result;
   result = num * num * num * num;
   return result;
}
5. Write a function that prints the sentence:

Your age is ___ years.

In the blank space in the sentence it should print the value of an integer parameter called age.

Typically functions that perform any input or output (or both) should be written as void functions.

void print( int age )
{
   cout << "Your age is " << age << " years." << endl;
}
6. Write a function that prompts the user to enter a number of hours worked and a pay rate. Your function should then input two values into float parameters called hoursWorked and payRate. Your function will need to supply the two input values to the calling function.

Typically functions that perform input should be written as void functions. Any parameter that needs to "return" information to the calling function needs to be a reference parameter.

void GetPayInfo( float &hoursWorked, float &payRate )
{
   cout << "Enter hours worked and pay rate: ";
   cin >> hoursWorked >> payRate;
}
7. The following program will not compile. Find the problem and fix it.

#include <iostream>
using namespace std;

void printCurved( int grade );

int main()
{
   int studentNo, grade;
   cout << "Enter student number and grade:";
   cin >> studentNo >> grade;
   printCurved(grade);
   return 0;
}

void printCurved( int grade )
{
   cout << "The curved grade for student ";
        << studentNo << " is " 
        << grade + 10 << endl;
}
The problem is that function PrintCurved() attempts to print the value of a variable that is local to the main( ) function (studentNo). This value must somehow be communicated to the function, such as by including it as a parameter:

#include <iostream>
using namespace std;

void printCurved( int studentNo, int grade );

int main()
{
   int studentNo, grade;
   cout << "Enter student number and grade:";
   cin >> studentNo >> grade;
   printCurved(studentNo, grade);
   return 0;
}

void printCurved( int studentNo, int grade )
{
   cout << "The curved grade for student "
        << studentNo << " is " 
        << grade + 10 << endl;
}
8. Write a function that receives two float values as parameters and "returns" each value halved. Write an example call for your function. Write declarations for all variables that you use.

A value-returning function can only return a single value. If a function needs to send more that one value back to the calling function, typically a void function is used. Each value that is to be "returned" should be a reference parameter.

void halve( float &num1, float &num2 )
{
   num1 = num1 / 2.0;
   num2 = num2 / 2.0;
}
9. Write an overloaded version of your function in the previous problem that works on int values.

void halve( int &num1, int &num2 )
{
   num1 = num1 / 2;
   num2 = num2 / 2;
}
10. Write a statement that causes all floating point numbers to be printed with exactly 1 place to the right of the decimal point.

Assuming the output will be to the monitor, the following statement will work.

cout << fixed << showpoint
     << setprecision(1);

