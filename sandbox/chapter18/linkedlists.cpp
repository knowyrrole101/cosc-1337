#include <iostream>
#include <iomanip>
#include <cstring>
#include <cctype> // character testing
#include <cstdio>
#include <memory> // Smart Pointers 
#include <sstream> 
#include <string>

using namespace std;

// Structs must all be upper case
struct ListNode
{
    double value;   
    ListNode *next;
};

// USING CONSTRUCTORS FOR NODES
struct ListNodewithConstructor
{
    int value;
    ListNodewithConstructor *next;
    ListNodewithConstructor(int value1, ListNodewithConstructor *next1=nullptr){
        next = next1;
        value = value1;
    }
};

int main()
{

    // ListNode *head = nullptr;

    // Create first node with 12.5
    ListNode *head = nullptr;
    // Create Head Node
    head = new ListNode;
    head->value = 12.5;
    head->next = nullptr;

    // Create Second Node
    ListNode *secondptr = new ListNode;
    secondptr->value=13.5;
    secondptr->next=nullptr;
    head->next = secondptr;

    // Print the pointers
    cout << "First item in linked list is: " << head->value << endl;
    cout << "The second item in linked list is: " << head->next->value << endl;
    
    // Adds Null PTR 
    ListNodewithConstructor *head2 = new ListNodewithConstructor(101);
    ListNodewithConstructor *node2 = new ListNodewithConstructor(1000);
    head2->next = node2;
    

    cout << "The first value or the head in the linked list " << head2->value << endl;
    cout << "The next node is: " << head2->next << endl; //PRINTS OUT THE MEMORY ADDRESS OF NEXT NODE

    // Create Empty Node
    ListNode *numberList = nullptr;
    double number1;
    
    while(someFile >> number1)
    {
        numberList = new ListNode(number1, numberList)
    }


    return 0;
}