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
    int value;   
    ListNode *next;
    ListNode(int somevalue, ListNode *next1 = nullptr){
        value = somevalue;
        next = next1;
    }
};

int main()
{
    // Traveersing a Linked List
    ListNode *ptr = someLinkedList;;
    while(ptr != nullptr)
    {
        cout << "Value: " << ptr->value << endl;
        ptr = ptr->next; //Mpve to next code
    }


    return 0;
}