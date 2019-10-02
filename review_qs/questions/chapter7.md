CHAPTER 7

1. Create a simple class called Item (to represent an inventory item) with private data members:

item number (an integer)
description (a string)
price (a floating-point value)
In the class definition include prototypes for public member functions:

a constructor that sets item number and price to zero and description to the empty string
a set function that checks for valid values for all data members (item number and price should not be negative)
separate get functions that return the values of each data member
After the class definition, write the definitions for the member functions (do not put the function code inside the class definition).

2. Write client code to create an Item object called myItem. Then write code to set it's item number to 10, it's description to "Granny Smith Apples", and it's price to 1.89.

3. Creating an Item object and setting it's data members to values specified by the client programmer takes 2 statements with the Item class code written so far. Add a second constructor to the class so that the client programmer can declare an Item object and specify initial values for it's data members in a single statement.

4. Write a declaration for an Item object that calls your constructor from the previous problem.