EXAM REVIEW

CHAPTER 2 

1. How do you output a newline character from your program?

You can print the newline character ('\n') by itself:

cout << '\n';
Or include it in a string:

cout << "Hello\nWorld";
Or use the endl i/o manipulator:

cout << endl;

CHAPTER 3

1. Write a C++ statement that displays the value of floating-point variable rate in a field 8 characters wide with exactly one digit to the right of the decimal.

cout << setprecision(1) << fixed << showpoint
     << setw(8) << rate;
2. How do you enter a newline character from the keyboard?

Pressing the Enter key generates a newline character.

CHAPTER 4
Other Questions

1. A company pays its sales people $200 per week plus 9 percent of their gross sales for the week. Write declarations for variables to hold a salesperson's gross weekly sales and weekly pay. Write a statement to calculate the weekly pay and store it in your variable.

float grossWeeklySales, weeklyPay;

weeklyPay = 200. + .09 * grossWeeklyPay;

2. Given float variables predictedHigh and actualHigh, write a C++ statement or statements that print:

"Bullseye" if the difference between predictedHigh and actualHigh is less than 3,
"Close" if the difference between predictedHigh and actualHigh is from 3 to 6,
and "Oops" if the difference is larger than 6.

float predictedHigh, actualHigh, difference;
difference = fabs(predictedHigh - actualHigh);
if (difference < 3.0 )
   cout << "Bullseye";
else if (difference <= 6)
   cout << "Close";
else
   cout << "Oops";

3. Write a C++ statement that means the same thing as this math expression:

0 < length < 10

0 < length && length < 10

CHAPTER 5 
Other Questions

1. The following loop is supposed to print the odd integers from 1 through 5.

count = 1;
while (count != 6)
{
   count++;
   cout << count << ' ';
}
a. What is printed by the loop?
The loop prints:
2 3 4 5 6

b. Rewrite the loop so that it works correctly.

count = 1;
while (count < 6)
{
   cout << count << ' ';
   count += 2;
}
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
The problem is that there is a semicolon immediately following the condition in the while statement. The compiler expects a statement following the close parenthesis. A semicolon by itself is the null statement - a statement that does nothing. So the loop body is empty. Once the loop is entered, there is no code to make the condition become false and you have an infinite loop. Change the line with the while to:

while (price > 0)
3. Write C++ code to read 20 integers and count how many times the integer 100 appears in the input. You must use a loop.

int count, num, count100;

count100 = 0;
count = 1;
while (count <= 20)
{
   cout << "Enter next number: ";
   cin >> num;
   if (num == 100)
      count100 = count100 + 1;
   count = count + 1;
}
cout << "100 appears " 
     << count100 << " times in the input." << endl;
4. Write a loop that sums the integers from 1 through 10.

int count, sum;

sum = 0;
count = 1;
while (count <= 10)
{
   sum = sum + count;;
   count = count + 1;
}
cout << "The sum of 1 through 10 is " << sum << endl;
5. Write a loop that reads a list of integers from the keyboard and counts how many negative integers are input and how many positive integers are input. The loop should stop when zero is input. Then print the count of negative numbers and the count of positive numbers with appropriate labels.

int num;
int numNeg = 0, numPos = 0;

cout << "Enter a list of integers. Type 0 to quit." << endl;
cout << "Enter first integer: ";
cin >> num;
while (num != 0)
{
   if (num < 0)
      numNeg = numNeg + 1;
   else
      numPos = numPos + 1;
   cout << "Enter next integer: ";
   cin >> num;
}
cout << "You entered " << numNeg << " negative integers" << endl;
     << "        and " << numPos << " positive integers." << endl;
6. Write a switch statement to convert a letter grade to a numeric value based on the following table. Use char variable ltrGrade and int variable numGrade.

letter grade

numeric value
letter grade numeric value
a               4
b               3
c               2
d               1
f               0

The following code does a little extra. It inputs a letter grade, converts it to a numeric value, and then prints the numeric value. The code will accept both uppercase and lowercase letters.

char ltrGrade;
int numGrade;
cout << "Enter the letter grade: ";
cin >> ltrGrade;
switch(ltrGrade)
{
   case 'A':
   case 'a': numGrade = 4;
             break;
   case 'B':
   case 'b': numGrade = 3;
             break;
   case 'C':
   case 'c': numGrade = 2;
             break;
   case 'D':
   case 'd': numGrade = 1;
             break;
   case 'F':
   case 'f': numGrade = 0;
             break;
}
cout << "The grade value is " << numGrade << endl;
