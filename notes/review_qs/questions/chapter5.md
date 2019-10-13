Chapter 5 Review
1. The following loop is supposed to print the odd integers from 1 through 5.

count = 1;
while (count != 6)
{
   count++;
   cout << count << ' ';
}
a. What is printed by the loop?
b. Rewrite the loop so that it works correctly.

2. When the following code is inserted in a program and executed, it reads the first price and then the computer "hangs". Find the problem and correct it.

int quantity;
float price, cost;

cout << "Enter item price (or -1 to quit): ";
cin >> price;
while (price > 0);
{
   cout << "Enter quantity for this item: ";
   cin >> quantity;
   cout << endl;
   cost = price * quantity;
   cout << "The cost for " << quantity
        << " items at " << price
        << " each is " << cost
        << endl;
   cout << "Enter item price (or -1 to quit): ";
   cin >> price;
}
3. Write C++ code to read 20 integers and count how many times the integer 100 appears in the input. You must use a loop.

4. Write a loop that sums the integers from 1 through 10.

5. Write a loop that reads a list of integers from the keyboard and counts how many negative integers are input and how many positive integers are input. The loop should stop when zero is input. Then print the count of negative numbers and the count of positive numbers with appropriate labels.

6. Write a switch statement to convert a letter grade to a numeric value based on the following table. Use char variable ltrGrade and int variable numGrade.

letter grade

Numeric value

A

4

B

3

C

2

D

1

F

0

Notes on sentinel-controlled loops:

Your book gives an example of a sentinel loop in Program 5-8. It looks something like the following example. Note that the types for value and sentinel could be any of the integral types: char, short, int, or long.

const int SENTINEL = 0; // or whatever the sentinel value is
int value = 1; // set to any value but sentinel
while ( value != SENTINEL )
{
   cout << "Enter next value: ";
   cin >> value;
   if ( value != sentinel )
   {
      // Process value here
   }
}
Notice that this code has to check for the sentinel value twice. The reason is that normally a sentinel loop should not process the sentinel value.

Most textbooks include an example of a sentinel loop in a format that I generally prefer. It works the same as the above loop but you only have to check for the sentinel value once:

const int SENTINEL = 0; // or whatever the sentinel value is
int value; // variable for input
cout << "Enter next value: ";
cin >> value;
while ( value != SENTINEL )
{
   // Process value here
   cout << "Enter next value: ";
   cin >> value;
}
 

Notes on error checking

Some students get in the habit of doing input validation in "tight" validation loops as in the following example. In a loop like this the user is forced to stay in the validation loop until they enter a valid value. If they get totally confused they have no way to break out of the loop.

// Find the average of a list of grades. 
// Valid grades are in the range 0 - 100. 
// The list ends with a sentinel of -1.
int grade, sum = 0, count = 0;
cout << "Enter next grade (or -1 to stop): ";
cin >> grade;
while ( grade != -1 )
{
   while ( grade < 0 || grade > 100 )
   {
      cout << "Invalid grade - please re-enter" << endl;
      cout << "Valid grades are in the range 0 - 100" << endl;
      cout << "Enter next grade (or -1 to stop): ";
      cin >> grade;
   }
   sum = sum + grade;
   count++;
   cout << "Enter next grade (or -1 to stop): ";
   cin >> grade;
}
cout << "average is" << static_cast<float> (sum) / count << endl;
The following example of error checking gives the user more flexibility.

//Find the average of a list of grades.
// Valid grades are in the range 0 - 100. 
// The list ends with a sentinel of -1.
int grade, sum = 0, count = 0;
cout << "Enter next grade (or -1 to stop): ";
cin >> grade;
while ( grade != -1 )
{
   if ( grade < 0 || grade > 100 )
   {
      cout << "Invalid grade - please re-enter" << endl;
      cout << "Valid grades are in the range 0 - 100" << endl;
   }
   else
   {
      sum = sum + grade;
      count++;
   }
   cout << "Enter next grade (or -1 to stop): ";
   cin >> grade;
}
cout << "average is" << static_cast<float> (sum) / count << endl;
Answers to Other Questions are here.