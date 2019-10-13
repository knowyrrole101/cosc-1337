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

Answer:

class Item

{
private:
   int itemNo;
   string desc;
   float price;
public:
   Item();
   void set( int oneItemNo, string oneDesc, float onePrice );
   int getItemNo();
   string getDesc();
   float getPrice();
};
Item::Item()
{
   set( 0, "", 0.0 );
}
void Item::set( int oneItemNo, string oneDesc, float onePrice )
{
   if ( oneItemNo >= 0 )
      itemNo = oneItemNo;
   else
      itemNo = 0;
   desc = oneDesc;
   if ( onePrice >= 0.0)
      price = onePrice;
   else
      price = 0;
}
int Item::getItemNo()
{
   return itemNo;
}
string Item::getDesc()
{
   return desc;
}
float Item::getPrice()
{
   return price;
}
2. Write client code to create an Item object called myItem. Then write code to set it's item number to 10, it's description to "Granny Smith Apples", and it's price to 1.89.

Item myItem;

myItem.set( 10, "Granny Smith Apples", 1.89 );
3. Creating an Item object and setting it's data members to values specified by the client programmer takes 2 statements with the Item class code written so far. Add a second constructor to the class so that the client programmer can declare an Item object and specify initial values for it's data members in a single statement.

Answer (prototype and function definition):

Item( int, string, float );

Item::Item( int anItem, string aDesc, float aPrice )
{
   set(anItem, aDesc, aPrice);
}
4. Write a declaration for an Item object that calls your constructor from the previous problem.

Item myItem( 5, "Fredericksburg Peaches", 3.95 );
