#include <iostream>
#include <iomanip>
#include <cstring>
#include <cctype>
#include <cstdio>
#include <memory> // Smart Pointers 

using namespace std;

class someOtherClassName{
    public:
        someOtherClassName();
        int name, lastname;
        void addBudget(int);
};
// Static member variables -> accessible by all class objects 
class StatDemo
{   
    private:
        // Static member varaibles must be declared inside class and defined outside it
        static int x; // Static makes this avaialbe to all objects of the class.
        int y;
    public:
        void setx(int a) const {x = a;} //Cannot be modified
        void sety(int b) const {y = b;}
        int getx() {return x;}
        int gety() {return y;}
        // Static funcs cannot be called through this as its not implict use of an instance of an object
        static double somefunction() {};
        friend void someOtherClassName::addBudget(int); // A friend class
};

some

// Copy constructors



// Friend function from other class
void someOtherClassName::addBudget(){ cout << "some friend function" << endl;}
// Friend functions can access private class objects

int main()
{
    
    return 0;
}